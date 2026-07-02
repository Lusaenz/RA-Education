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

    public IEnumerator GetGameActivityByActivityId(int idActivity, Action<GameActivityData> callback)
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("[GameActivityService] DatabaseManager.Instance es null.");
            callback?.Invoke(null);
            yield break;
        }

        if (!DatabaseManager.Instance.IsReady)
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        GameActivityData result = null;

        try
        {
            EnsureRepository();
            result = repository.GetByActivityId(idActivity);

            if (result == null)
                Debug.LogWarning($"[GameActivityService] No se encontró game_activity con id_activity {idActivity}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[GameActivityService] Error al buscar por id_activity: {ex.Message}");
        }

        callback?.Invoke(result);
    }

    public IEnumerator GetGameActivityByModuleId(int idModule, Action<GameActivityData> callback)
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("[GameActivityService] DatabaseManager.Instance es null.");
            callback?.Invoke(null);
            yield break;
        }

        if (!DatabaseManager.Instance.IsReady)
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        GameActivityData result = null;

        try
        {
            EnsureRepository();
            result = repository.GetByModuleId(idModule);

            if (result == null)
                Debug.LogWarning($"[GameActivityService] No se encontró game_activity con id_module {idModule}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[GameActivityService] Error al buscar por id_module: {ex.Message}");
        }

        callback?.Invoke(result);
    }

    public IEnumerator GetAllGameActivitiesByModuleId(int idModule, System.Action<System.Collections.Generic.List<GameActivityData>> callback)
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("[GameActivityService] DatabaseManager.Instance es null.");
            callback?.Invoke(null);
            yield break;
        }

        if (!DatabaseManager.Instance.IsReady)
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        System.Collections.Generic.List<GameActivityData> result = null;

        try
        {
            EnsureRepository();
            result = repository.GetAllByModuleId(idModule);
        }
        catch (Exception ex)
        {
            Debug.LogError($"[GameActivityService] Error al cargar actividades del módulo {idModule}: {ex.Message}");
        }

        callback?.Invoke(result);
    }

    public IEnumerator GetAllGameActivities(System.Action<System.Collections.Generic.List<GameActivityData>> callback)
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("[GameActivityService] DatabaseManager.Instance es null.");
            callback?.Invoke(null);
            yield break;
        }

        if (!DatabaseManager.Instance.IsReady)
        {
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);
        }

        System.Collections.Generic.List<GameActivityData> result = null;

        try
        {
            EnsureRepository();
            result = repository.GetAll();
        }
        catch (Exception ex)
        {
            Debug.LogError($"[GameActivityService] Error al cargar todas las actividades: {ex.Message}");
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
