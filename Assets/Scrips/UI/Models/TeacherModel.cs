using SQLite4Unity3d;

[Table("teachers")]
/// <summary>
/// Entidad persistente con datos especificos del profesor.
/// </summary>
public class TeacherModel
{
    public int id_user { get; set; }
    public string email { get; set; }
}

