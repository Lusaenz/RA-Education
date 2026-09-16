using System;

[Serializable]
public class UserSyncData
{
    // Datos de users
    public int id_user;
    public string name;
    public int id_degree;
    public string password;
    public int id_role;
    public int id_security_question;
    public string security_asnwer_hash;
    public string last_login;

    // Datos de students
    public int age;
}