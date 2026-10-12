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

/// <summary>
/// Fila de la tabla progress enviada por la red.
/// El estudiante se identifica por nombre porque el id_user
/// autoincremental no coincide entre dispositivos.
/// </summary>
[Serializable]
public class ProgressSyncData
{
    public string student_name;
    public int id_module;
    public int punctuation;
    public int percentage_completed;
    public int completad_at; // 0 = null
    public string status;
}

/// <summary>
/// Fila de la tabla result_activity enviada por la red.
/// </summary>
[Serializable]
public class ResultSyncData
{
    public string student_name;
    public int id_activity;
    public int score;
    public int stars;
    public int attempts;
    public string completed_at;
}
