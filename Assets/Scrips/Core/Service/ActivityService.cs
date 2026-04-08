using System;
using System.Collections;
using UnityEngine;

public class ActivityService
{
    private readonly ActivityRepository _repository;

    public ActivityService()
    {
        _repository = new ActivityRepository();
    }

    public IEnumerator GetActivity(int idActivity, Action<ActivityData> callback)
    {
        if (!DatabaseManager.Instance.IsReady)
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        ActivityData result = null;

        try
        {
            result = _repository.GetById(idActivity);
        }
        catch (Exception ex)
        {
            Debug.LogError("[ActivityService] Error: " + ex.Message);
        }

        callback?.Invoke(result);
    }
}