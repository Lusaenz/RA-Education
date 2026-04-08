using SQLite4Unity3d;
using System.IO;
using UnityEngine;
using System;
using System.Collections;
using UnityEngine.Networking;
using System.Collections.Generic;

public class DatabaseController : MonoBehaviour
{
    private string dbPath;
    public static DatabaseController Instancia;

    void Awake()
    {
        if (Instancia == null)
        {
            Instancia = this;
            DontDestroyOnLoad(gameObject);
            dbPath = Path.Combine(Application.persistentDataPath, "ciencia_local.db");
            StartCoroutine(DataBase());
        }
        else
        {
            Destroy(gameObject);
        }
    }

    IEnumerator DataBase()
    {
        string rutaOrigen = Path.Combine(Application.streamingAssetsPath, "ciencia_local.db");
        string rutaDestino = dbPath;

        if (!File.Exists(rutaDestino))
        {
            UnityWebRequest request = UnityWebRequest.Get(rutaOrigen);
            yield return request.SendWebRequest();
            if (request.result == UnityWebRequest.Result.Success)
            {
                File.WriteAllBytes(rutaDestino, request.downloadHandler.data);
            }
        }
    }

    // Trae un solo dato 
    public string ObtenerDatoUnico(string nombreTabla, string nombreColumna)
    {
        string resultado = "";
        try
        {
            using (var conn = new SQLiteConnection(dbPath))
            {
                // consulta genérica para no tener que crear clases por cada tabla
                var query = $"SELECT {nombreColumna} FROM {nombreTabla} LIMIT 1";
                var comando = conn.CreateCommand(query);
                resultado = comando.ExecuteScalar<string>();
            }
        }
        catch (System.Exception e) { Debug.LogError("Error en ObtenerDatoUnico: " + e.Message); }
        
        return resultado ?? "";
    }

    // Trae todas las columnas de la tabla
    public List<string[]> ObtenerDatos(string nombreTabla)
    {
        List<string[]> listaResultados = new List<string[]>();
        
        using (var conn = new SQLiteConnection(dbPath))
        {

            string sql = $"SELECT * FROM {nombreTabla}";
            var stmt = SQLite3.Prepare2(conn.Handle, sql);
            
            int numColumnas = SQLite3.ColumnCount(stmt);

            while (SQLite3.Step(stmt) == SQLite3.Result.Row)
            {
                string[] fila = new string[numColumnas];

                for (int i = 0; i < numColumnas; i++)
                {
                    fila[i] = SQLite3.ColumnString(stmt, i);
                }

                listaResultados.Add(fila);
            }
            SQLite3.Finalize(stmt);
        }
        
        return listaResultados;
    }
}