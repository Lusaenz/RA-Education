using SQLite4Unity3d;
using System;

[Table("progress")]
public class ProgressModel
{
    [PrimaryKey, AutoIncrement]
    public int id_progress { get; set; }
    public int id_user { get; set; }
    public int id_module { get; set; }
    public int? punctuation { get; set; }
    public int? percentage_completed { get; set; }
    public int? completad_at { get; set; }
    public string status { get; set; }
}
