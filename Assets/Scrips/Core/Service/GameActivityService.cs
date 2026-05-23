using SQLite4Unity3d;
using System;
using System.Collections;
using UnityEngine;

/// <summary>
/// Servicio para operaciones de game_activity.
/// Actua de intermediario entre GameManager y GameActivityRepository.
/// Espera a que DatabaseManager este listo antes de consultar.
/// </summary>
public class GameActivityService
{
    private GameActivityRepository repository;

    public GameActivityService(SQLiteConnection connection)
    {
        repository = new GameActivityRepository(connection);
    }

    public GameActivityService()
    {
    }

    public IEnumerator GetGameActivity(int idGameActivity, Action<GameActivityData> callback)
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("[GameActivityService] DatabaseManager.Instance es null.");
            callback?.Invoke(null);
            yield break;
        }

        if (!DatabaseManager.Instance.IsReady)
        {
            Debug.Log("[GameActivityService] Esperando a que DatabaseManager este listo...");
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);
        }

        GameActivityData result = null;

        try
        {
            EnsureRepository();
            result = repository.GetById(idGameActivity);

            if (result == null)
            {
                Debug.LogWarning($"[GameActivityService] No se encontro game_activity con id {idGameActivity}");
            }
        }
        catch (Exception ex)
        {
            Debug.LogError($"[GameActivityService] Error al consultar game_activity: {ex.Message}");
        }

        callback?.Invoke(result);
    }

    private void EnsureRepository()
    {
        if (repository == null)
        {
            repository = new GameActivityRepository();
        }
    }
}
