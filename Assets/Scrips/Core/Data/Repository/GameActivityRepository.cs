using SQLite4Unity3d;
using System.Linq;
using UnityEngine;

/// <summary>
/// Repositorio de lectura para la tabla game_activity.
/// Sigue el mismo patrón que DegreeRepository.
/// Carpeta: Repository/
/// </summary>
public class GameActivityRepository
{
    private SQLiteConnection ConnectionDb;

    /// <summary>
    /// Constructor con conexión explícita (recomendado).
    /// </summary>
    public GameActivityRepository(SQLiteConnection connection)
    {
        if (connection == null)
        {
            Debug.LogError("GameActivityRepository: la conexión proporcionada es null.");
            throw new System.ArgumentNullException(nameof(connection), "Se requiere una conexión válida.");
        }

        ConnectionDb = connection;
    }

    /// <summary>
    /// Constructor legacy que resuelve la conexión desde DatabaseManager.
    /// </summary>
    public GameActivityRepository()
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("DatabaseManager.Instance es null al crear GameActivityRepository.");
            throw new System.InvalidOperationException("DatabaseManager.Instance es null.");
        }

        ConnectionDb = DatabaseManager.Instance.GetConnection();

        if (ConnectionDb == null)
        {
            Debug.LogError("ConnectionDb es null en GameActivityRepository.");
            throw new System.InvalidOperationException("ConnectionDb es null.");
        }
    }

    /// <summary>
    /// Busca un registro de game_activity por su id_game_activity.
    /// Retorna null si no existe.
    /// </summary>
    public GameActivityData GetById(int idGameActivity)
    {
        return ConnectionDb.Table<GameActivityData>()
            .FirstOrDefault(x => x.id_game_activity == idGameActivity);
    }
}