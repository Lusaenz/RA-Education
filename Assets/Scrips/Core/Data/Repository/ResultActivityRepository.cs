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
}