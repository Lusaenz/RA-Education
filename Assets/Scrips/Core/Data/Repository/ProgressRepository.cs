using System;
using System.Linq;
using SQLite4Unity3d;
using UnityEngine;

/// <summary>
/// Repositorio de acceso a la tabla "progress" (estado y avance del usuario por modulo).
/// Antes vivia embebido dentro de EstadoManager; se extrajo para poder reutilizarlo
/// desde ProgressService (marcado de items) y desde EstadoManager (lectura para el mapa).
/// </summary>
public class ProgressRepository
{
    private readonly SQLiteConnection connectionDb;

    public ProgressRepository()
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("ProgressRepository: DatabaseManager.Instance es null.");
            throw new InvalidOperationException("DatabaseManager.Instance es null.");
        }

        connectionDb = DatabaseManager.Instance.GetConnection();

        if (connectionDb == null)
        {
            Debug.LogError("ProgressRepository: la conexion de base de datos es null.");
            throw new InvalidOperationException("La conexion de base de datos es null.");
        }
    }

    public ProgressModel GetByUserAndModule(int userId, int moduleId)
    {
        return connectionDb.Table<ProgressModel>()
            .FirstOrDefault(x => x.id_user == userId && x.id_module == moduleId);
    }

    public void Insert(ProgressModel progress)
    {
        connectionDb.Insert(progress);
    }

    public void Update(ProgressModel progress)
    {
        connectionDb.Update(progress);
    }

    /// <summary>
    /// Inserta la fila si no tiene id_progress asignado; en caso contrario la actualiza.
    /// </summary>
    public void Upsert(ProgressModel progress)
    {
        if (progress == null)
        {
            return;
        }

        if (progress.id_progress > 0)
        {
            connectionDb.Update(progress);
        }
        else
        {
            connectionDb.Insert(progress);
        }
    }
}
