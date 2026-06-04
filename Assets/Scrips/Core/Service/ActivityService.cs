using System;
using System.Collections;
using UnityEngine;

public class ActivityService
{
    private ActivityRepository repository;

    public IEnumerator GetActivity(int idActivity, Action<ActivityData> callback)
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("[ActivityService] DatabaseManager.Instance es null.");
            callback?.Invoke(null);
            yield break;
        }

        if (!DatabaseManager.Instance.IsReady)
        {
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);
        }

        ActivityData result = null;

        try
        {
            EnsureRepository();
            result = repository.GetById(idActivity);
        }
        catch (Exception ex)
        {
            Debug.LogError("[ActivityService] Error: " + ex.Message);
        }

        callback?.Invoke(result);
    }

    private void EnsureRepository()
    {
        if (repository == null)
        {
            repository = new ActivityRepository();
        }
    }
}
