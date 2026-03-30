using SQLite4Unity3d;
using System;
using System.Collections;
using UnityEngine;

/// <summary>
/// Servicio para operaciones de game_activity.
/// Actúa de intermediario entre GameManager y GameActivityRepository.
/// Espera a que DatabaseManager esté listo antes de consultar.
/// Carpeta: Service/
/// </summary>
public class GameActivityService
{
    private readonly GameActivityRepository _repository;

    /// <summary>
    /// Constructor con conexión explícita.
    /// </summary>
    public GameActivityService(SQLiteConnection connection)
    {
        _repository = new GameActivityRepository(connection);
    }

    /// <summary>
    /// Constructor legacy — resuelve la conexión desde DatabaseManager.
    /// </summary>
    public GameActivityService()
    {
        _repository = new GameActivityRepository();
    }

    /// <summary>
    /// Obtiene un GameActivityData por id y lo entrega por callback.
    /// Si DatabaseManager no está listo, espera usando la corrutina del caller.
    /// Uso desde GameManager:
    ///   yield return StartCoroutine(_service.GetGameActivity(id, result => data = result));
    /// </summary>
    public IEnumerator GetGameActivity(int idGameActivity, Action<GameActivityData> callback)
    {
        // Esperar a que la BD esté lista si aún no lo está
        if (!DatabaseManager.Instance.IsReady)
        {
            Debug.Log("[GameActivityService] Esperando a que DatabaseManager esté listo...");
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);
        }

        GameActivityData result = null;

        try
        {
            result = _repository.GetById(idGameActivity);

            if (result == null)
                Debug.LogWarning($"[GameActivityService] No se encontró game_activity con id {idGameActivity}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[GameActivityService] Error al consultar game_activity: {ex.Message}");
        }

        callback?.Invoke(result);
    }
}