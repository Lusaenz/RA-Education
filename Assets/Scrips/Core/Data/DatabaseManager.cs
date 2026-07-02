using SQLite4Unity3d;
using System.IO;
using UnityEngine;
using System;
using System.Collections;
using UnityEngine.Networking;
using System.Security.Cryptography;

public class DatabaseManager : MonoBehaviour
{
    private const string DbName = "ciencia_viva.db";
    private const string DbHashFile = "ciencia_viva.db.hash";
    private const int MaxInitRetries = 30;
    private const float InitRetryDelaySeconds = 0.25f;

    // Tablas gestionadas por el desarrollador — se reemplazan al actualizar la BD original.
    // Las tablas de usuario (users, students, teachers, result_activity, progress) se preservan siempre.
    private static readonly string[] ContentTables = { "degrees", "modules", "activity", "game_activity", "security_questions" };

    public static DatabaseManager Instance { get; private set; }

    public SQLiteConnection Connection { get; private set; }

    public bool IsReady { get; private set; }

    public event Action OnReady;

    void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
            StartCoroutine(InicializarDBConReintentos());
        }
        else
        {
            Destroy(gameObject);
        }
    }

    IEnumerator InicializarDBConReintentos()
    {
        IsReady = false;
        string dbPath = Path.Combine(Application.persistentDataPath, DbName);

        yield return StartCoroutine(EnsureDatabaseFileExists(dbPath));

        for (int attempt = 1; attempt <= MaxInitRetries; attempt++)
        {
            bool shouldRetry = false;

            try
            {
                Connection?.Close();

                Connection = new SQLiteConnection(
                    dbPath,
                    SQLiteOpenFlags.ReadWrite | SQLiteOpenFlags.Create | SQLiteOpenFlags.FullMutex);
                Connection.BusyTimeout = TimeSpan.FromSeconds(15);
                Connection.ExecuteScalar<string>("PRAGMA journal_mode=WAL;");
                Connection.Execute("PRAGMA synchronous=NORMAL;");

                IsReady = true;
                Debug.Log("DatabaseManager: Conectado a DB");
                OnReady?.Invoke();
                yield break;
            }
            catch (SQLiteException ex) when (ex.Result == SQLite3.Result.Busy)
            {
                if (attempt == MaxInitRetries) break;
                shouldRetry = true;
            }
            catch (Exception ex)
            {
                if (ex.Message.IndexOf("busy", StringComparison.OrdinalIgnoreCase) >= 0 && attempt < MaxInitRetries)
                {
                    shouldRetry = true;
                }
                else
                {
                    Debug.LogError($"DatabaseManager: Error inicializando DB: {ex.Message}");
                    IsReady = false;
                    yield break;
                }
            }

            if (shouldRetry)
                yield return new WaitForSecondsRealtime(InitRetryDelaySeconds);
        }

        Debug.LogError("DatabaseManager: Error inicializando DB: Busy (timeout de reintentos agotado).");
        IsReady = false;
    }

    IEnumerator EnsureDatabaseFileExists(string targetPath)
    {
        string sourcePath = Path.Combine(Application.streamingAssetsPath, DbName);

        if (File.Exists(targetPath))
        {
            yield return StartCoroutine(CheckAndUpdateIfModified(sourcePath, targetPath));
            yield break;
        }

        byte[] sourceBytes = null;

        if (sourcePath.Contains("://"))
        {
            using (UnityWebRequest www = UnityWebRequest.Get(sourcePath))
            {
                yield return www.SendWebRequest();

                if (www.result != UnityWebRequest.Result.Success)
                {
                    Debug.LogError($"DatabaseManager: No se pudo copiar DB desde StreamingAssets: {www.error}");
                    yield break;
                }

                sourceBytes = www.downloadHandler.data;
                File.WriteAllBytes(targetPath, sourceBytes);
            }
        }
        else
        {
            if (!File.Exists(sourcePath))
            {
                Debug.LogWarning($"DatabaseManager: DB base no encontrada en StreamingAssets: {sourcePath}");
                yield break;
            }

            sourceBytes = File.ReadAllBytes(sourcePath);
            File.Copy(sourcePath, targetPath, true);
        }

        // Guardar hash tras la copia inicial para evitar una migración innecesaria en el próximo arranque.
        if (sourceBytes != null)
        {
            try
            {
                string hashFilePath = Path.Combine(Application.persistentDataPath, DbHashFile);
                File.WriteAllText(hashFilePath, CalculateHash(sourceBytes));
            }
            catch (Exception ex)
            {
                Debug.LogWarning($"DatabaseManager: No se pudo guardar hash inicial: {ex.Message}");
            }
        }

        Debug.Log("DatabaseManager: DB copiada a persistentDataPath.");
    }

    private IEnumerator CheckAndUpdateIfModified(string sourcePath, string targetPath)
    {
        string hashFilePath = Path.Combine(Application.persistentDataPath, DbHashFile);
        string currentHash = "";
        byte[] newDbBytes = null;

        if (sourcePath.Contains("://"))
        {
            using (UnityWebRequest www = UnityWebRequest.Get(sourcePath))
            {
                yield return www.SendWebRequest();

                if (www.result == UnityWebRequest.Result.Success)
                {
                    newDbBytes = www.downloadHandler.data;
                    currentHash = CalculateHash(newDbBytes);
                }
            }
        }
        else if (File.Exists(sourcePath))
        {
            newDbBytes = File.ReadAllBytes(sourcePath);
            currentHash = CalculateHash(newDbBytes);
        }

        string storedHash = File.Exists(hashFilePath) ? File.ReadAllText(hashFilePath).Trim() : "";

        if (string.IsNullOrEmpty(currentHash) || currentHash == storedHash)
            yield break;

        Debug.Log("DatabaseManager: BD original modificada. Iniciando migración selectiva...");

        bool migrated = newDbBytes != null && MigrateContentTables(targetPath, newDbBytes);

        if (!migrated)
        {
            // Fallback: reemplazar la BD completa. Los datos de usuario se perderán.
            Debug.LogWarning("DatabaseManager: Migración selectiva fallida. Reemplazando BD completa.");
            try
            {
                if (File.Exists(targetPath))
                    File.Delete(targetPath);
            }
            catch (Exception ex)
            {
                Debug.LogError($"DatabaseManager: Error al eliminar BD antigua: {ex.Message}");
            }

            yield return StartCoroutine(CopyDatabaseFile(sourcePath, targetPath));
        }

        try
        {
            File.WriteAllText(hashFilePath, currentHash);
        }
        catch (Exception ex)
        {
            Debug.LogError($"DatabaseManager: Error al guardar hash: {ex.Message}");
        }
    }

    /// <summary>
    /// Actualiza las tablas de contenido en la BD local usando ATTACH, preservando los datos de usuario.
    /// Devuelve true si la migración fue exitosa.
    /// </summary>
    private bool MigrateContentTables(string localDbPath, byte[] newDbBytes)
    {
        string tempPath = localDbPath + ".update";

        try
        {
            File.WriteAllBytes(tempPath, newDbBytes);

            string escapedTemp = tempPath.Replace("'", "''");

            using (var conn = new SQLiteConnection(localDbPath, SQLiteOpenFlags.ReadWrite | SQLiteOpenFlags.FullMutex))
            {
                conn.BusyTimeout = TimeSpan.FromSeconds(15);
                conn.Execute($"ATTACH DATABASE '{escapedTemp}' AS newdb;");
                conn.Execute("BEGIN TRANSACTION;");

                foreach (string table in ContentTables)
                {
                    try
                    {
                        // Obtener el DDL original de la BD fuente para recrear la tabla con el esquema correcto.
                        string ddl = conn.ExecuteScalar<string>(
                            $"SELECT sql FROM newdb.sqlite_master WHERE type='table' AND name='{table}';");

                        conn.Execute($"DROP TABLE IF EXISTS \"{table}\";");

                        if (!string.IsNullOrEmpty(ddl))
                        {
                            conn.Execute(ddl);
                        }

                        conn.Execute($"INSERT INTO \"{table}\" SELECT * FROM newdb.\"{table}\";");
                        Debug.Log($"DatabaseManager: Tabla '{table}' actualizada.");
                    }
                    catch (Exception ex)
                    {
                        Debug.LogWarning($"DatabaseManager: No se pudo migrar tabla '{table}': {ex.Message}");
                    }
                }

                conn.Execute("COMMIT;");
                conn.Execute("DETACH DATABASE newdb;");
            }

            Debug.Log("DatabaseManager: Migración selectiva completada. Datos de usuario preservados.");
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"DatabaseManager: Error en migración selectiva: {ex.Message}");
            return false;
        }
        finally
        {
            try { if (File.Exists(tempPath)) File.Delete(tempPath); } catch { }
        }
    }

    private IEnumerator CopyDatabaseFile(string sourcePath, string targetPath)
    {
        if (sourcePath.Contains("://"))
        {
            using (UnityWebRequest www = UnityWebRequest.Get(sourcePath))
            {
                yield return www.SendWebRequest();

                if (www.result != UnityWebRequest.Result.Success)
                {
                    Debug.LogError($"DatabaseManager: No se pudo copiar DB desde StreamingAssets: {www.error}");
                    yield break;
                }

                File.WriteAllBytes(targetPath, www.downloadHandler.data);
                Debug.Log("DatabaseManager: DB actualizada desde StreamingAssets.");
            }
        }
        else
        {
            if (!File.Exists(sourcePath))
            {
                Debug.LogWarning($"DatabaseManager: DB base no encontrada en StreamingAssets: {sourcePath}");
                yield break;
            }

            File.Copy(sourcePath, targetPath, true);
            Debug.Log("DatabaseManager: DB actualizada a persistentDataPath.");
        }
    }

    private string CalculateHash(byte[] data)
    {
        using (MD5 md5 = MD5.Create())
        {
            byte[] hash = md5.ComputeHash(data);
            return Convert.ToBase64String(hash);
        }
    }

    public SQLiteConnection GetConnection()
    {
        return Connection;
    }

    void OnApplicationQuit()
    {
        Connection?.Close();
    }
}
