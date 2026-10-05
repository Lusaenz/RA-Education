using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using UnityEngine;
using System.Linq;
using SQLite4Unity3d;

public class OfflineSyncManager : MonoBehaviour
{
    public static OfflineSyncManager Instance { get; private set; }

    private bool isSyncing = false;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    private void Start()
    {
        if (DatabaseManager.Instance != null)
        {
            if (DatabaseManager.Instance.IsReady)
                InitQueueTable();
            else
                DatabaseManager.Instance.OnReady += InitQueueTable;
        }
    }

    private void InitQueueTable()
    {
        try
        {
            var conn = DatabaseManager.Instance.GetConnection();
            conn?.CreateTable<PendingSyncItem>();
            Debug.Log("OfflineSyncManager: Tabla 'pending_sync_queue' lista.");
        }
        catch (Exception ex)
        {
            Debug.LogError($"OfflineSyncManager: Error creando tabla de sincronización: {ex.Message}");
        }
    }

    /// <summary>
    /// Guarda el cambio localmente en SQLite y lo encola para sincronizar.
    /// </summary>
    public void RecordChangeAndSync<T>(string tableName, string actionType, string entityId, T entityObj)
    {
        var conn = DatabaseManager.Instance?.GetConnection();
        if (conn == null) return;

        conn.RunInTransaction(() =>
        {
            // 1. Guardar/Actualizar la entidad local en SQLite
            if (actionType == "INSERT" || actionType == "UPDATE")
                conn.InsertOrReplace(entityObj);
            else if (actionType == "DELETE")
                conn.Delete(entityObj);

            // 2. Registrar el evento en la cola de sincronización
            string json = JsonUtility.ToJson(entityObj);
            var syncItem = new PendingSyncItem
            {
                TableName = tableName,
                ActionType = actionType,
                EntityId = entityId,
                JsonPayload = json
            };

            conn.Insert(syncItem);
        });

        // 3. Intentar enviar inmediatamente si hay red
        _ = ProcessPendingQueueAsync();
    }

    /// <summary>
    /// Recorre la cola local y envía todos los cambios pendientes al servidor.
    /// </summary>
    public async Task ProcessPendingQueueAsync()
    {
        if (isSyncing) return;
        if (SimpleClient.Instance == null || !SimpleClient.Instance.IsConnected) return;

        isSyncing = true;

        try
        {
            var conn = DatabaseManager.Instance?.GetConnection();
            if (conn == null) return;

            List<PendingSyncItem> pendingItems = conn.Table<PendingSyncItem>()
                                                     .OrderBy(x => x.Id)
                                                     .ToList();

            if (pendingItems.Count == 0)
            {
                isSyncing = false;
                return;
            }

            Debug.Log($"OfflineSyncManager: Procesando {pendingItems.Count} cambios pendientes...");

            foreach (var item in pendingItems)
            {
                // Formato de paquete JSON que viajará por TCP
                string syncMessage = JsonUtility.ToJson(new SyncPacket
                {
                    Type = "SYNC_CHANGE",
                    SyncGuid = item.SyncGuid,
                    TableName = item.TableName,
                    ActionType = item.ActionType,
                    EntityId = item.EntityId,
                    Payload = item.JsonPayload,
                    Timestamp = item.CreatedAt
                });

                // Enviar mensaje TCP
                await SimpleClient.Instance.SendRawMessage(syncMessage);

                // Remover el cambio enviado de la cola local
                conn.Delete<PendingSyncItem>(item.Id);
            }

            Debug.Log("OfflineSyncManager: Cola de sincronización procesada exitosamente.");
        }
        catch (Exception ex)
        {
            Debug.LogWarning($"OfflineSyncManager: Error procesando la cola: {ex.Message}");
        }
        finally
        {
            isSyncing = false;
        }
    }
}

[Serializable]
public class SyncPacket
{
    public string Type;
    public string SyncGuid;
    public string TableName;
    public string ActionType;
    public string EntityId;
    public string Payload;
    public string Timestamp;
}