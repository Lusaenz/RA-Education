using SQLite4Unity3d;

[Table("modules")]
/// <summary>
/// Modelo que representa la tabla modules de la base de datos.
/// Contiene la información básica de cada unidad educativa o sección del mapa.
/// </summary>
public class ModuleModel
{
    [PrimaryKey, AutoIncrement]
    public int id_module { get; set; }
    
    [NotNull]
    public string name { get; set; }
    
    [NotNull]
    public string description { get; set; }
    
    [NotNull]
    public int period { get; set; }
}
