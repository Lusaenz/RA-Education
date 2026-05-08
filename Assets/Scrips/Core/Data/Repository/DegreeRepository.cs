using SQLite4Unity3d;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

/// <summary>
/// Repositorio de lectura para la tabla degrees.
/// </summary>
public class DegreeRepository
{
    private SQLiteConnection ConnectionDb;

    /// <summary>
    /// Crea el repositorio con una conexion explicita.
    /// </summary>
    public DegreeRepository(SQLiteConnection connection)
    {
        if (connection == null)
        {
            Debug.LogError("DegreeRepository: la conexión proporcionada es null.");
            throw new System.ArgumentNullException(nameof(connection), "Se requiere una conexión válida para crear DegreeRepository.");
        }

        ConnectionDb = connection;
    }

    // Constructor por compatibilidad
    /// <summary>
    /// Constructor legacy que intenta resolver la conexion desde DatabaseManager.
    /// </summary>
    public DegreeRepository()
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("DatabaseManager.Instance es null al crear DegreeRepository.");
            throw new System.InvalidOperationException("DatabaseManager.Instance es null.");
        }

        ConnectionDb = DatabaseManager.Instance.GetConnection();

        if (ConnectionDb == null)
        {
            Debug.LogError("ConnectionDb es null en DegreeRepository.");
            throw new System.InvalidOperationException("ConnectionDb es null.");
        }
    }

    /// <summary>
    /// Busca un grado por su identificador primario.
    /// </summary>
    public DegreeModel GetDegreeById(int degreeId)
    {
        return ConnectionDb.Table<DegreeModel>()
            .FirstOrDefault(x => x.id_degree == degreeId);
    }

    /// <summary>
    /// Retorna todos los grados registrados.
    /// </summary>
    public List<DegreeModel> GetAllDegrees()
    {
        return ConnectionDb.Table<DegreeModel>().ToList();
    }
}
