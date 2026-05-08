using System.Linq;
using SQLite4Unity3d;
using UnityEngine;

public class ResultActivityRepository
{
    private SQLiteConnection _connection;

    public ResultActivityRepository()
    {
        _connection = DatabaseManager.Instance.GetConnection();
    }

    public void Insert(ResultActivityData result)
    {
        _connection.Insert(result);
        Debug.Log("[ResultActivityRepository] Resultado guardado correctamente.");
    }

    public int GetTotalStarsByUser(int userId)
    {
        if (userId <= 0)
        {
            return 0;
        }

        return _connection.Table<ResultActivityData>()
            .Where(x => x.id_user == userId)
            .ToList()
            .Sum(x => x.stars);
    }
}
