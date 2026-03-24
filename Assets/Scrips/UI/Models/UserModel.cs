using SQLite4Unity3d;

[Table("users")]
/// <summary>
/// Entidad base de autenticacion y perfil comun para cualquier usuario.
/// </summary>
public class UserModel
{
    [PrimaryKey, AutoIncrement]
    public int id_user { get; set; }
    public string name { get; set; }
    public int id_degree { get; set; }
    public string password { get; set; }
    public int id_role { get; set; }
}


