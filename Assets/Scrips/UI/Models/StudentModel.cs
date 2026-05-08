using SQLite4Unity3d;

[Table("students")]
/// <summary>
/// Entidad persistente con datos especificos del estudiante.
/// </summary>
public class StudentModel
{
    public int id_user { get; set; }
    public int age { get; set; }
}


