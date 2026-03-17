using System.Collections;
using System.IO;
using UnityEngine;
using UnityEngine.Networking;

/// <summary>
/// Componente de compatibilidad que copia la base de datos desde StreamingAssets
/// a persistentDataPath cuando todavia no existe una copia local.
/// </summary>
public class DatabaseLoader : MonoBehaviour
{
    string dbName = "ciencia_viva.db";

    /// <summary>
    /// Solo ejecuta la copia si no existe un DatabaseManager centralizado.
    /// </summary>
    void Start()
    {
        if (DatabaseManager.Instance != null)
        {
            // DatabaseManager ya centraliza la copia/apertura de la DB.
            return;
        }

        StartCoroutine(CopyDatabase());
    }

    /// <summary>
    /// Copia la base local segun la plataforma de ejecucion.
    /// </summary>
    IEnumerator CopyDatabase()
    {
        string sourcePath = Path.Combine(Application.streamingAssetsPath, dbName);
        string targetPath = Path.Combine(Application.persistentDataPath, dbName);

        if (!File.Exists(targetPath))
        {
            if (sourcePath.Contains("://"))
            {
                UnityWebRequest www = UnityWebRequest.Get(sourcePath);
                yield return www.SendWebRequest();

                File.WriteAllBytes(targetPath, www.downloadHandler.data);
            }
            else
            {
                File.Copy(sourcePath, targetPath, true);
            }

            Debug.Log("DB copiada a: " + targetPath);
        }
        else
        {
            Debug.Log("DB ya existe en: " + targetPath);
        }
    }
}

