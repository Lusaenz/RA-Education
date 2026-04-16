using System.Collections.Generic;
using SQLite4Unity3d;
using UnityEngine;

public class ModulesRepository
{
    private SQLiteConnection ConnectionDb;

    /// <summary>
    /// Constructor con conexión explícita (recomendado).
    /// </summary>
    public ModulesRepository(SQLiteConnection connection)
    {
        if (connection == null)
        {
            Debug.LogError("ModulesRepository : la conexión proporcionada es null.");
            throw new System.ArgumentNullException(nameof(connection), "Se requiere una conexión válida.");
        }

        ConnectionDb = connection;


    }

    public ModulesRepository()
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("DatabaseManager.Instance es null al crear ModulesRepository.");
            throw new System.InvalidOperationException("DatabaseManager.Instance es null.");
        }

        ConnectionDb = DatabaseManager.Instance.GetConnection();

        if (ConnectionDb == null)
        {
            Debug.LogError("ConnectionDb es null en ModulesRepository.");
            throw new System.InvalidOperationException("ConnectionDb es null.");
        }
    }

    public string ObtenerDatoUnico(string nombreTabla, string nombreColumna)
    {
        string sql = $"SELECT {nombreColumna} FROM {nombreTabla} LIMIT 1";
        var stmt = SQLite3.Prepare2(ConnectionDb.Handle, sql);

        string resultado = string.Empty;

        if (SQLite3.Step(stmt) == SQLite3.Result.Row)
        {
            resultado = SQLite3.ColumnString(stmt, 0);
        }
        else
        {
            Debug.LogWarning($"ModulesRepository: No se encontraron datos en {nombreTabla} para columna {nombreColumna}.");
        }

        SQLite3.Finalize(stmt);

        return resultado;
    }

    // Trae todas las columnas de la tabla
    public List<string[]> ObtenerDatos(string nombreTabla)
    {
        List<string[]> listaResultados = new List<string[]>();
        
        {

            string sql = $"SELECT * FROM {nombreTabla}";
            var stmt = SQLite3.Prepare2(ConnectionDb.Handle, sql);
            
            int numColumnas = SQLite3.ColumnCount(stmt);

            while (SQLite3.Step(stmt) == SQLite3.Result.Row)
            {
                string[] fila = new string[numColumnas];

                for (int i = 0; i < numColumnas; i++)
                {
                    fila[i] = SQLite3.ColumnString(stmt, i);
                }

                listaResultados.Add(fila);
            }
            SQLite3.Finalize(stmt);
        }
        
        return listaResultados;
    }
}