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
    
}