using SQLite4Unity3d;
using System;

[Table("activity")]
[Serializable]
public class ActivityData
{
    [PrimaryKey]
    public int id_activity { get; set; }

    public string type { get; set; }
    public string description { get; set; }
    public int max_score { get; set; }
    public int max_star { get; set; }
}