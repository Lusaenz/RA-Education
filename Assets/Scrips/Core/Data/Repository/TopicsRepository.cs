using System;
using System.Collections.Generic;
using System.Linq;
using SQLite4Unity3d;
using UnityEngine;

/// <summary>
/// Repositorio de consulta para "topics" y "content_sections".
/// Usa los modelos TopicModel y SeccionJson definidos en ModulesRepository.cs.
/// </summary>
public class TopicsRepository
{
    private readonly SQLiteConnection _connection;

    public TopicsRepository(SQLiteConnection connection)
    {
        if (connection == null)
        {
            Debug.LogError("TopicsRepository: la conexión proporcionada es null.");
            throw new ArgumentNullException(nameof(connection), "Se requiere una conexión válida.");
        }

        _connection = connection;
    }

    public TopicsRepository()
    {
        if (DatabaseManager.Instance == null || DatabaseManager.Instance.GetConnection() == null)
        {
            Debug.LogError("TopicsRepository: DatabaseManager.Instance no está listo.");
            throw new InvalidOperationException("DatabaseManager.Instance no está listo.");
        }

        _connection = DatabaseManager.Instance.GetConnection();
    }

    public TopicModel GetTopicById(int idTopic)
    {
        try
        {
            return _connection.Table<TopicModel>().FirstOrDefault(t => t.id_topic == idTopic);
        }
        catch (Exception ex)
        {
            Debug.LogError($"TopicsRepository: Error al obtener topic {idTopic}: {ex.Message}");
            return null;
        }
    }

    public List<SeccionJson> GetSections(int idTopic)
    {
        try
        {
            return _connection.Table<SeccionJson>()
                .Where(s => s.id_topic == idTopic)
                .OrderBy(s => s.order_index)
                .ToList();
        }
        catch (Exception ex)
        {
            Debug.LogError($"TopicsRepository: Error al obtener content_sections del topic {idTopic}: {ex.Message}");
            return new List<SeccionJson>();
        }
    }
}
