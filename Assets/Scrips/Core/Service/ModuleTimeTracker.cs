using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Acumula el tiempo activo que un usuario pasa dentro del contenido de un modulo
/// (libro de temas y minijuegos). Se agrega en runtime al GameObject que muestra el
/// contenido mediante <see cref="Track"/>; mientras ese objeto esta activo cuenta tiempo.
///
/// El acumulado en curso se guarda en PlayerPrefs (module_time_{userId}_{moduleId}, segundos).
/// Al completarse el modulo, ProgressService lo convierte a minutos y lo persiste en
/// progress.completad_at.
/// </summary>
public class ModuleTimeTracker : MonoBehaviour
{
    private const string PrefsKeyFormat = "module_time_{0}_{1}";

    private static readonly List<ModuleTimeTracker> ActiveTrackers = new List<ModuleTimeTracker>();

    private int userId;
    private int moduleId;
    private float segmentStart = -1f;

    /// <summary>
    /// Empieza (o continua) a contar el tiempo del modulo en el GameObject indicado.
    /// </summary>
    public static ModuleTimeTracker Track(GameObject host, int userId, int moduleId)
    {
        if (host == null || userId <= 0 || moduleId <= 0)
        {
            return null;
        }

        ModuleTimeTracker tracker = host.GetComponent<ModuleTimeTracker>();
        if (tracker == null)
        {
            tracker = host.AddComponent<ModuleTimeTracker>();
        }

        tracker.Begin(userId, moduleId);
        return tracker;
    }

    /// <summary>
    /// Segundos acumulados del modulo, incluyendo el tramo en curso de los trackers activos.
    /// </summary>
    public static float GetTotalSeconds(int userId, int moduleId)
    {
        float total = PlayerPrefs.GetFloat(GetKey(userId, moduleId), 0f);

        foreach (ModuleTimeTracker tracker in ActiveTrackers)
        {
            if (tracker.userId == userId && tracker.moduleId == moduleId)
            {
                total += tracker.GetRunningSeconds();
            }
        }

        return total;
    }

    public void Begin(int newUserId, int newModuleId)
    {
        if (newUserId != userId || newModuleId != moduleId)
        {
            Flush();
            userId = newUserId;
            moduleId = newModuleId;
        }

        Resume();
    }

    /// <summary>
    /// Detiene el conteo y guarda lo acumulado.
    /// </summary>
    public void Stop()
    {
        Flush();
        segmentStart = -1f;
        ActiveTrackers.Remove(this);
    }

    private void OnEnable()
    {
        if (userId > 0 && moduleId > 0)
        {
            Resume();
        }
    }

    private void OnDisable()
    {
        Stop();
    }

    private void OnDestroy()
    {
        Stop();
    }

    private void OnApplicationPause(bool paused)
    {
        if (paused)
        {
            Flush();
            segmentStart = -1f;
        }
        else if (isActiveAndEnabled && userId > 0 && moduleId > 0)
        {
            Resume();
        }
    }

    private void Resume()
    {
        if (segmentStart < 0f)
        {
            segmentStart = Time.realtimeSinceStartup;
        }

        if (!ActiveTrackers.Contains(this))
        {
            ActiveTrackers.Add(this);
        }
    }

    private float GetRunningSeconds()
    {
        return segmentStart < 0f ? 0f : Mathf.Max(0f, Time.realtimeSinceStartup - segmentStart);
    }

    /// <summary>
    /// Pasa el tramo en curso a PlayerPrefs y reinicia el tramo si sigue contando.
    /// </summary>
    private void Flush()
    {
        float running = GetRunningSeconds();
        if (running <= 0f || userId <= 0 || moduleId <= 0)
        {
            return;
        }

        string key = GetKey(userId, moduleId);
        PlayerPrefs.SetFloat(key, PlayerPrefs.GetFloat(key, 0f) + running);
        PlayerPrefs.Save();

        segmentStart = Time.realtimeSinceStartup;
    }

    private static string GetKey(int userId, int moduleId)
    {
        return string.Format(PrefsKeyFormat, userId, moduleId);
    }
}
