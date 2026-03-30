using SQLite4Unity3d;
using System.Linq;
using UnityEngine;

public class ActivityRepository
{
    private SQLiteConnection _connection;

    public ActivityRepository()
    {
        _connection = DatabaseManager.Instance.GetConnection();
    }

    public ActivityData GetById(int idActivity)
    {
        return _connection.Table<ActivityData>()
            .FirstOrDefault(x => x.id_activity == idActivity);
    }
}