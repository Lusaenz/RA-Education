using SQLite4Unity3d;

[Table("degrees")]
/// <summary>
/// Entidad persistente que representa un grado o carrera.
/// </summary>
public class DegreeModel
{
    [PrimaryKey, AutoIncrement]
    public int id_degree { get; set; }
    public string name { get; set; }
}
