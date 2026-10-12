using SQLite4Unity3d;
using System;

[Table("result_activity")]
[Serializable]
public class ResultActivityData
{
    [PrimaryKey, AutoIncrement]
    public int id_result { get; set; }

    public int id_user { get; set; }
    public int id_activity { get; set; }
    public int score { get; set; }
    public int stars { get; set; }
    public int attempts { get; set; }
    public string completed_at { get; set; }

    // Minijuego exacto (game_activity). Permite saber a qué módulo pertenece el resultado,
    // porque un mismo id_activity (p. ej. Drag and Drop) se usa en varios módulos.
    public int id_game_activity { get; set; }
}