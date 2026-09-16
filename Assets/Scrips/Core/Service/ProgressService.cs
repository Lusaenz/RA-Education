using System;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

/// <summary>
/// Resultado del calculo de avance de un modulo para un usuario.
/// </summary>
public class ModuleProgressInfo
{
    public int completedItems;
    public int totalItems;
    public int percentage;   // 0 - 100
    public string status;     // "nostarted" | "inprogress" | "completed"
}

/// <summary>
/// Logica de avance por modulo. Todo se persiste en la tabla "progress" (una fila por
/// id_user + id_module); no se crean tablas ni columnas nuevas.
///
/// Modelo:
///  - Un "item" del modulo = cada tema del libro (topics) + cada minijuego (game_activity).
///  - progress.punctuation se usa como BITMASK de items completados:
///      bits [0 .. T-1]       -> temas, en orden de topics.order_index
///      bits [T .. T+G-1]     -> juegos, en orden de game_activity.id_game_activity
///    Marcar un item es idempotente: punctuation |= (1 &lt;&lt; bit).
///  - progress.percentage_completed = round(popcount(punctuation) * 100 / totalItems).
///  - progress.status = "nostarted" (mask 0) | "completed" (todos los items) | "inprogress".
///  - progress.completad_at = fecha yyyyMMdd la primera vez que el modulo se completa.
///
/// Nota: se asume un maximo de 31 items por modulo (int de 32 bits). Hoy el modulo mayor
/// tiene 12 items. Si algun modulo supera ese limite habria que migrar punctuation a long.
/// </summary>
public class ProgressService
{
    private const string StatusNotStarted = "nostarted";
    private const string StatusInProgress = "inprogress";
    private const string StatusCompleted = "completed";

    private ProgressRepository progressRepository;
    private ModulesRepository modulesRepository;
    private GameActivityRepository gameActivityRepository;

    public ProgressService()
    {
        EnsureRepositories();
    }

    private bool EnsureRepositories()
    {
        if (progressRepository != null && modulesRepository != null && gameActivityRepository != null)
        {
            return true;
        }

        if (DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady)
        {
            return false;
        }

        try
        {
            progressRepository ??= new ProgressRepository();
            modulesRepository ??= new ModulesRepository();
            gameActivityRepository ??= new GameActivityRepository();
            return true;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[ProgressService] No se pudieron inicializar los repositorios: {ex.Message}");
            progressRepository = null;
            modulesRepository = null;
            gameActivityRepository = null;
            return false;
        }
    }

    /// <summary>
    /// Devuelve el avance actual del modulo recalculado desde el bitmask guardado.
    /// </summary>
    public ModuleProgressInfo GetModuleProgress(int userId, int moduleId)
    {
        int total = GetTotalItems(moduleId);

        if (!EnsureRepositories())
        {
            return BuildInfo(0, total);
        }

        ProgressModel row = progressRepository.GetByUserAndModule(userId, moduleId);
        int mask = row?.punctuation ?? 0;
        return BuildInfo(mask, total);
    }

    /// <summary>
    /// Crea la fila del modulo (punctuation 0, status "inprogress") si todavia no existe.
    /// No degrada un modulo ya iniciado ni completado.
    /// </summary>
    public void EnsureModuleStarted(int userId, int moduleId)
    {
        if (!EnsureRepositories() || userId <= 0 || moduleId <= 0)
        {
            return;
        }

        ProgressModel row = progressRepository.GetByUserAndModule(userId, moduleId);
        if (row != null)
        {
            return;
        }

        int total = GetTotalItems(moduleId);
        ModuleProgressInfo info = BuildInfo(0, total);

        progressRepository.Insert(new ProgressModel
        {
            id_user = userId,
            id_module = moduleId,
            punctuation = 0,
            percentage_completed = 0,
            completad_at = null,
            status = info.completedItems > 0 ? info.status : StatusInProgress
        });
    }

    /// <summary>
    /// Marca como visto el tema indicado (idempotente).
    /// </summary>
    public void MarkTopicViewed(int userId, int moduleId, int topicId)
    {
        if (!EnsureRepositories() || userId <= 0 || moduleId <= 0 || topicId <= 0)
        {
            return;
        }

        ModuleItemLayout layout = GetLayout(moduleId);
        int index = layout.topicIds.IndexOf(topicId);
        if (index < 0)
        {
            Debug.LogWarning($"[ProgressService] El tema {topicId} no pertenece al modulo {moduleId}; no se marca.");
            return;
        }

        RecomputeAndPersist(userId, moduleId, index, layout);
    }

    /// <summary>
    /// Marca como completado el minijuego indicado, solo si se obtuvo al menos 1 estrella.
    /// </summary>
    public void MarkGameCompleted(int userId, int moduleId, int gameActivityId, int stars)
    {
        if (stars < 1)
        {
            return;
        }

        if (!EnsureRepositories() || userId <= 0 || moduleId <= 0 || gameActivityId <= 0)
        {
            return;
        }

        ModuleItemLayout layout = GetLayout(moduleId);
        int gameIndex = layout.gameActivityIds.IndexOf(gameActivityId);
        if (gameIndex < 0)
        {
            Debug.LogWarning($"[ProgressService] La game_activity {gameActivityId} no pertenece al modulo {moduleId}; no se marca.");
            return;
        }

        RecomputeAndPersist(userId, moduleId, layout.topicIds.Count + gameIndex, layout);
    }

    // ---------------------------------------------------------------------

    private void RecomputeAndPersist(int userId, int moduleId, int bitIndex, ModuleItemLayout layout)
    {
        if (bitIndex < 0 || bitIndex >= 31)
        {
            Debug.LogWarning($"[ProgressService] Indice de item fuera de rango ({bitIndex}) para el modulo {moduleId}.");
            return;
        }

        int total = layout.TotalItems;
        ProgressModel row = progressRepository.GetByUserAndModule(userId, moduleId);

        int previousMask = row?.punctuation ?? 0;
        int newMask = previousMask | (1 << bitIndex);

        ModuleProgressInfo info = BuildInfo(newMask, total);

        if (row == null)
        {
            row = new ProgressModel
            {
                id_user = userId,
                id_module = moduleId
            };
        }

        row.punctuation = newMask;
        row.percentage_completed = info.percentage;
        row.status = info.status;

        bool justCompleted = info.status == StatusCompleted && (row.completad_at == null || row.completad_at == 0);
        if (justCompleted)
        {
            row.completad_at = int.Parse(DateTime.Now.ToString("yyyyMMdd"));
        }

        progressRepository.Upsert(row);
    }

    private ModuleProgressInfo BuildInfo(int mask, int totalItems)
    {
        int validBits = totalItems >= 31 ? 31 : Mathf.Max(totalItems, 0);
        int validMask = validBits >= 31 ? int.MaxValue : (1 << validBits) - 1;
        int completed = PopCount(mask & validMask);

        int percentage;
        string status;

        if (completed <= 0 || totalItems <= 0)
        {
            percentage = 0;
            status = completed <= 0 ? StatusNotStarted : StatusInProgress;
        }
        else if (completed >= totalItems)
        {
            percentage = 100;
            status = StatusCompleted;
        }
        else
        {
            percentage = Mathf.Clamp(Mathf.RoundToInt(completed * 100f / totalItems), 1, 99);
            status = StatusInProgress;
        }

        return new ModuleProgressInfo
        {
            completedItems = completed,
            totalItems = totalItems,
            percentage = percentage,
            status = status
        };
    }

    private int GetTotalItems(int moduleId)
    {
        return GetLayout(moduleId).TotalItems;
    }

    private ModuleItemLayout GetLayout(int moduleId)
    {
        var layout = new ModuleItemLayout
        {
            topicIds = new List<int>(),
            gameActivityIds = new List<int>()
        };

        if (!EnsureRepositories())
        {
            return layout;
        }

        try
        {
            layout.topicIds = modulesRepository.GetTopicIdsByModule(moduleId) ?? new List<int>();
        }
        catch (Exception ex)
        {
            Debug.LogError($"[ProgressService] Error al leer los temas del modulo {moduleId}: {ex.Message}");
        }

        try
        {
            List<GameActivityData> games = gameActivityRepository.GetAllByModuleId(moduleId) ?? new List<GameActivityData>();
            layout.gameActivityIds = games
                .OrderBy(g => g.id_game_activity)
                .Select(g => g.id_game_activity)
                .ToList();
        }
        catch (Exception ex)
        {
            Debug.LogError($"[ProgressService] Error al leer los juegos del modulo {moduleId}: {ex.Message}");
        }

        return layout;
    }

    private static int PopCount(int value)
    {
        int count = 0;
        uint v = unchecked((uint)value);
        while (v != 0)
        {
            v &= v - 1;
            count++;
        }
        return count;
    }

    private class ModuleItemLayout
    {
        public List<int> topicIds;
        public List<int> gameActivityIds;
        public int TotalItems => topicIds.Count + gameActivityIds.Count;
    }
}
