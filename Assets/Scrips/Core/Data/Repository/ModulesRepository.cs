using System.Collections.Generic;
using System.Linq;
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

    /// <summary>
    /// Obtiene un módulo por su ID de manera limpia usando el ORM.
    /// </summary>
    /// <param name="id_module">ID del módulo a buscar.</param>
    /// <returns>El modelo del módulo o null si no se encuentra.</returns>
    public ModuleModel GetModuleById(int id_module)
    {
        try
        {
            return ConnectionDb.Table<ModuleModel>()
                .FirstOrDefault(m => m.id_module == id_module);
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"ModulesRepository: Error al obtener módulo {id_module}: {ex.Message}");
            return null;
        }
    }

    public List<TopicJson> ObtenerEstructuraCompleta(int id_module)
    {
        List<TopicJson> resultadoFinal = new List<TopicJson>();
        
        ModuleModel infoModulo = ObtenerModulo(id_module);
        
        if (infoModulo != null) {
            resultadoFinal.Add(new TopicJson {
                topic_id = -1,
                topic_name = infoModulo.name,
                sections = new List<SeccionJson> {
                    new SeccionJson { title = "Introducción", content = infoModulo.description }
                }
            });
        }

        var topics = ConnectionDb.Table<TopicModel>().Where(t => t.id_module == id_module).ToList();
        foreach (var t in topics) {
            resultadoFinal.Add(new TopicJson {
                topic_id = t.id_topic,
                topic_name = t.name,
                image = t.image,
                sections = ConnectionDb.Table<SeccionJson>().Where(m => m.id_topic == t.id_topic).OrderBy(m => m.order_index).ToList()
            });
        }
        return resultadoFinal;
    }

    public ModuleModel ObtenerModulo(int id_module)
    {
        try 
        {
            var modulo = ConnectionDb.Table<ModuleModel>()
                                .Where(m => m.id_module == id_module)
                                .FirstOrDefault();
            return modulo;
        } 
        catch (System.Exception ex) 
        {
            UnityEngine.Debug.LogError("Error al obtener la información del módulo: " + ex.Message);
            return null;
        }
    }

}


[Table("topics")] // Carga de Tabla "topics"
public class TopicModel 
{
    [PrimaryKey]
    public int id_topic { get; set; }
    public string name { get; set; }
    public string image { get; set; }
    public int id_module { get; set; }
}

[Table("content_sections")] // Carga de Tabla "content_sections"
[System.Serializable]
public class SeccionJson
{
    [PrimaryKey]
    public int id_section { get; set; }
    public int id_topic { get; set; }
    public string title { get; set; }
    public string content { get; set; }
    public string section_type { get; set; }
    public int order_index { get; set; }
}

// Clase para agrupar los datos en C#
public class TopicJson
{
    public int topic_id;
    public string topic_name;
    public string image;
    public List<SeccionJson> sections;
}
