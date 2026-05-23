using UnityEngine;

public class ResultActivityService
{
    private ResultActivityRepository repository;

    public void SaveResult(int idUser, int idActivity, int score, int star, int attempts, string completedAt)
    {
        if (!EnsureRepository())
        {
            Debug.LogWarning("[ResultActivityService] No se pudo guardar el resultado porque la base de datos no esta disponible.");
            return;
        }

        ResultActivityData result = new ResultActivityData
        {
            id_user = idUser,
            id_activity = idActivity,
            score = score,
            stars = star,
            attempts = attempts,
            completed_at = completedAt
        };

        repository.Insert(result);
    }

    public int GetTotalStarsForUser(int userId)
    {
        if (!EnsureRepository())
        {
            return 0;
        }

        return repository.GetTotalStarsByUser(userId);
    }

    private bool EnsureRepository()
    {
        if (repository != null)
        {
            return true;
        }

        if (DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady)
        {
            return false;
        }

        repository = new ResultActivityRepository();
        return true;
    }
}
