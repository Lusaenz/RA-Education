using UnityEngine;

public class ResultActivityService
{
    private readonly ResultActivityRepository _repository;

    public ResultActivityService()
    {
        _repository = new ResultActivityRepository();
    }

    public void SaveResult(int idUser, int idActivity, int score, int star, int attempts, string completedAt)
    {
        ResultActivityData result = new ResultActivityData
        {
            id_user = idUser,
            id_activity = idActivity,
            score = score,
            stars = star,
            attempts = attempts,
            completed_at = completedAt
        };

        _repository.Insert(result);
    }
}
