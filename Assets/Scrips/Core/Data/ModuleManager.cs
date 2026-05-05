using System;
using System.Collections.Generic;
using System.Linq;
using SQLite4Unity3d;
using UnityEngine;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;

/// <summary>
/// Manager encargado de la logica relacionada con los modulos.
/// Permite obtener informacion de los modulos desde la base de datos y manejar su visualizacion.
/// </summary>
public class ModuleManager : MonoBehaviour
{
    private const string StatusNotStarted = "nostarted";
    private const string StatusInProgress = "inprogress";
    private const string StatusCompleted = "completed";

    [Header("Status Sprites")]
    [SerializeField] private SpriteRenderer statusCell;
    [SerializeField] private SpriteRenderer statusDigestive;

    [Header("Module IDs")]
    [SerializeField] private int digestiveModuleId = 1;
    [SerializeField] private int cellModuleId = 2;

    [Header("Status Addressables")]
    [SerializeField] private string notStartedStatusKey = "estados/notstarted";
    [SerializeField] private string completedStatusKey = "estados/completed";
    [SerializeField] private string inProgressStatusKey = "estados/inprogress";

    public static ModuleManager Instance { get; private set; }

    private ModulesRepository modulesRepository;
    private ProgressRepository progressRepository;
    private readonly Dictionary<string, AsyncOperationHandle<Sprite>> spriteHandles = new Dictionary<string, AsyncOperationHandle<Sprite>>();
    private readonly Dictionary<string, Sprite> spriteCache = new Dictionary<string, Sprite>();
    private readonly Dictionary<string, List<SpriteRenderer>> pendingSpriteTargets = new Dictionary<string, List<SpriteRenderer>>();

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
    }

    private void Start()
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("ModuleManager: DatabaseManager no esta disponible.");
            return;
        }

        if (DatabaseManager.Instance.IsReady)
        {
            InitializeRepositories();
            LoadUserModuleStatuses();
            return;
        }

        DatabaseManager.Instance.OnReady += OnDatabaseReady;
    }

    public void GetAndLogModuleName(int moduleId)
    {
        if (!EnsureRepositoriesReady())
        {
            return;
        }

        ModuleModel module = modulesRepository.GetModuleById(moduleId);

        if (module == null)
        {
            Debug.LogWarning($"ModuleManager: No se encontro un modulo con ID {moduleId} en la base de datos.");
            return;
        }

        Debug.Log($"Modulo detectado: {module.name}");
        MarkModuleAsInProgress(moduleId);
    }

    private void OnDestroy()
    {
        if (Instance == this)
        {
            Instance = null;
        }

        if (DatabaseManager.Instance != null)
        {
            DatabaseManager.Instance.OnReady -= OnDatabaseReady;
        }

        foreach (AsyncOperationHandle<Sprite> handle in spriteHandles.Values)
        {
            if (handle.IsValid())
            {
                Addressables.Release(handle);
            }
        }

        spriteHandles.Clear();
        spriteCache.Clear();
        pendingSpriteTargets.Clear();
    }

    private void OnDatabaseReady()
    {
        if (DatabaseManager.Instance != null)
        {
            DatabaseManager.Instance.OnReady -= OnDatabaseReady;
        }

        InitializeRepositories();
        LoadUserModuleStatuses();
    }

    private void InitializeRepositories()
    {
        try
        {
            modulesRepository = new ModulesRepository();
            progressRepository = new ProgressRepository();
        }
        catch (Exception ex)
        {
            modulesRepository = null;
            progressRepository = null;
            Debug.LogError($"ModuleManager: Error al inicializar repositorios: {ex.Message}");
        }
    }

    private bool EnsureRepositoriesReady()
    {
        if (modulesRepository != null && progressRepository != null)
        {
            return true;
        }

        if (DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady)
        {
            Debug.LogWarning("ModuleManager: La base de datos todavia no esta lista.");
            return false;
        }

        InitializeRepositories();
        return modulesRepository != null && progressRepository != null;
    }

    private void LoadUserModuleStatuses()
    {
        ApplySavedStatusToModule(digestiveModuleId);
        ApplySavedStatusToModule(cellModuleId);
    }

    private void ApplySavedStatusToModule(int moduleId)
    {
        string status = GetModuleStatusForCurrentUser(moduleId);
        UpdateModuleStatusImage(moduleId, status);
    }

    private string GetModuleStatusForCurrentUser(int moduleId)
    {
        if (progressRepository == null)
        {
            return StatusNotStarted;
        }

        UserModel currentUser = UserSessionManager.Instance?.CurrentUser;
        if (currentUser == null)
        {
            return StatusNotStarted;
        }

        ProgressModel progress = progressRepository.GetByUserAndModule(currentUser.id_user, moduleId);
        return progress == null ? StatusNotStarted : NormalizeStatus(progress.status);
    }

    private void MarkModuleAsInProgress(int moduleId)
    {
        if (progressRepository == null)
        {
            Debug.LogWarning("ModuleManager: ProgressRepository no esta disponible.");
            return;
        }

        UserModel currentUser = UserSessionManager.Instance?.CurrentUser;
        if (currentUser == null)
        {
            Debug.LogWarning("ModuleManager: No hay un usuario en sesion para guardar el progreso.");
            return;
        }

        ProgressModel progress = progressRepository.GetByUserAndModule(currentUser.id_user, moduleId);

        if (progress == null)
        {
            progress = new ProgressModel
            {
                id_user = currentUser.id_user,
                id_module = moduleId,
                punctuation = null,
                percentage_completed = null,
                completad_at = null,
                status = StatusInProgress
            };

            progressRepository.Insert(progress);
            UpdateModuleStatusImage(moduleId, StatusInProgress);
            return;
        }

        string normalizedStatus = NormalizeStatus(progress.status);
        if (normalizedStatus == StatusCompleted)
        {
            UpdateModuleStatusImage(moduleId, StatusCompleted);
            return;
        }

        progress.status = StatusInProgress;
        progressRepository.Update(progress);
        UpdateModuleStatusImage(moduleId, StatusInProgress);
    }

    private void UpdateModuleStatusImage(int moduleId, string status)
    {
        SpriteRenderer targetRenderer = GetRendererForModule(moduleId);
        if (targetRenderer == null)
        {
            Debug.LogWarning($"ModuleManager: No hay SpriteRenderer asignado para el modulo {moduleId}.");
            return;
        }

        string addressableKey = GetAddressableKeyForStatus(status);
        LoadStatusSprite(targetRenderer, addressableKey);
    }

    private SpriteRenderer GetRendererForModule(int moduleId)
    {
        if (moduleId == digestiveModuleId)
        {
            return statusDigestive;
        }

        if (moduleId == cellModuleId)
        {
            return statusCell;
        }

        return null;
    }

    private string GetAddressableKeyForStatus(string status)
    {
        return NormalizeStatus(status) switch
        {
            StatusCompleted => completedStatusKey,
            StatusInProgress => inProgressStatusKey,
            _ => notStartedStatusKey
        };
    }

    private string NormalizeStatus(string status)
    {
        if (string.IsNullOrWhiteSpace(status))
        {
            return StatusNotStarted;
        }

        string normalized = status.Trim().ToLowerInvariant();

        return normalized switch
        {
            "iniciado" => StatusInProgress,
            "enprogreso" => StatusInProgress,
            "en_progreso" => StatusInProgress,
            "started" => StatusInProgress,
            "completado" => StatusCompleted,
            _ => normalized
        };
    }

    private void LoadStatusSprite(SpriteRenderer targetRenderer, string addressableKey)
    {
        if (targetRenderer == null || string.IsNullOrWhiteSpace(addressableKey))
        {
            return;
        }

        if (spriteCache.TryGetValue(addressableKey, out Sprite cachedSprite))
        {
            targetRenderer.sprite = cachedSprite;
            return;
        }

        if (pendingSpriteTargets.TryGetValue(addressableKey, out List<SpriteRenderer> waitingTargets))
        {
            waitingTargets.Add(targetRenderer);
            return;
        }

        pendingSpriteTargets[addressableKey] = new List<SpriteRenderer> { targetRenderer };

        AsyncOperationHandle<Sprite> loadHandle = Addressables.LoadAssetAsync<Sprite>(addressableKey);
        loadHandle.Completed += handle =>
        {
            if (!pendingSpriteTargets.TryGetValue(addressableKey, out List<SpriteRenderer> targets))
            {
                if (handle.IsValid())
                {
                    Addressables.Release(handle);
                }

                return;
            }

            pendingSpriteTargets.Remove(addressableKey);

            if (handle.Status != AsyncOperationStatus.Succeeded)
            {
                Debug.LogError($"ModuleManager: No se pudo cargar el sprite de estado '{addressableKey}'.");
                if (handle.IsValid())
                {
                    Addressables.Release(handle);
                }
                return;
            }

            spriteHandles[addressableKey] = handle;
            spriteCache[addressableKey] = handle.Result;

            foreach (SpriteRenderer renderer in targets)
            {
                if (renderer != null)
                {
                    renderer.sprite = handle.Result;
                }
            }
        };
    }
}

internal class ProgressRepository
{
    private readonly SQLiteConnection connectionDb;

    public ProgressRepository()
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("ProgressRepository: DatabaseManager.Instance es null.");
            throw new InvalidOperationException("DatabaseManager.Instance es null.");
        }

        connectionDb = DatabaseManager.Instance.GetConnection();

        if (connectionDb == null)
        {
            Debug.LogError("ProgressRepository: la conexion de base de datos es null.");
            throw new InvalidOperationException("La conexion de base de datos es null.");
        }
    }

    public ProgressModel GetByUserAndModule(int userId, int moduleId)
    {
        return connectionDb.Table<ProgressModel>()
            .FirstOrDefault(x => x.id_user == userId && x.id_module == moduleId);
    }

    public void Insert(ProgressModel progress)
    {
        connectionDb.Insert(progress);
    }

    public void Update(ProgressModel progress)
    {
        connectionDb.Update(progress);
    }
}
