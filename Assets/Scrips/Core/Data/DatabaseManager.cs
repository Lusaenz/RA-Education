using SQLite4Unity3d;
using System.IO;
using UnityEngine;
using System;
using System.Collections;
using UnityEngine.Networking;

/// <summary>
/// Punto unico de inicializacion y acceso a SQLite.
/// Copia la base, abre la conexion y reintenta cuando el archivo esta ocupado.
/// </summary>
public class DatabaseManager : MonoBehaviour
{
    private const string DbName = "ciencia_viva.db";
    private const int MaxInitRetries = 30;
    private const float InitRetryDelaySeconds = 0.25f;

    public static DatabaseManager Instance { get; private set; }

    public SQLiteConnection Connection { get; private set; }

    public bool IsReady { get; private set; }

    public event Action OnReady;

    /// <summary>
    /// Inicializa el singleton y lanza la apertura asincronica de la base.
    /// </summary>
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

    /// <summary>
    /// Reintenta la apertura de la conexion para tolerar bloqueos temporales del archivo.
    /// </summary>
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
                if (attempt == MaxInitRetries)
                {
                    break;
                }

                shouldRetry = true;
            }
            catch (Exception ex)
            {
                // Algunos entornos propagan "Busy" como Exception genérica.
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
            {
                yield return new WaitForSecondsRealtime(InitRetryDelaySeconds);
            }
        }

        Debug.LogError("DatabaseManager: Error inicializando DB: Busy (timeout de reintentos agotado).");
        IsReady = false;
    }

    /// <summary>
    /// Garantiza que exista una copia fisica de la base en almacenamiento persistente.
    /// </summary>
    IEnumerator EnsureDatabaseFileExists(string targetPath)
    {
        if (File.Exists(targetPath))
        {
            yield break;
        }

        string sourcePath = Path.Combine(Application.streamingAssetsPath, DbName);

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
        }

        Debug.Log("DatabaseManager: DB copiada a persistentDataPath.");
    }

    /// <summary>
    /// Expone la conexion activa para repositorios y servicios legacy.
    /// </summary>
    public SQLiteConnection GetConnection()
    {
        return Connection;
    }

    /// <summary>
    /// Cierra la conexion al salir de la aplicacion.
    /// </summary>
    void OnApplicationQuit()
    {
        Connection?.Close();
    }
}
