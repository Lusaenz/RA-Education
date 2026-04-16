using SQLite4Unity3d;

[Table("security_questions")]
/// <summary>
/// Entidad persistente que representa una pregunta de seguridad.
/// </summary>
public class SecurityQuestionsModel
{
    [PrimaryKey, AutoIncrement]
    public int id_question { get; set; }
    public string question { get; set; }
}