using System.Collections;
using UnityEngine;

/// <summary>
/// Manager encargado de mostrar el estado/avance de los modulos en el mapa.
/// Lee el avance calculado por <see cref="ProgressService"/> (basado en la tabla "progress")
/// y lo refleja en el indicador de anillo de cada isla, ademas del color del rotulo.
/// </summary>
public class EstadoManager : MonoBehaviour
{
    private const string StatusNotStarted = "nostarted";
    private const string StatusInProgress = "inprogress";
    private const string StatusCompleted = "completed";

    [Header("Indicadores de estado (anillo por isla)")]
    [SerializeField] private ModuleStatusIndicator digestiveIndicator;
    [SerializeField] private ModuleStatusIndicator cellIndicator;

    [Header("Status Text Sprites")]
    [SerializeField] private SpriteRenderer textCell;
    [SerializeField] private SpriteRenderer textDigestive;

    [Header("Status Text Colors")]
    [SerializeField] private Color notStartedTextColor = Color.white;
    [SerializeField] private Color inProgressTextColor = new Color(0.15f, 0.15f, 0.15f);
    [SerializeField] private Color completedTextColor = Color.white;

    [Header("Module IDs")]
    [SerializeField] private int digestiveModuleId = 1;
    [SerializeField] private int cellModuleId = 2;

    public static EstadoManager Instance { get; private set; }

    private ModulesRepository modulesRepository;
    private ProgressService progressService;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
    }

    private void OnEnable()
    {
        // Al volver a esta escena (p.ej. tras salir de un minijuego) refrescamos el avance.
        if (progressService != null && modulesRepository != null)
        {
            LoadUserModuleStatuses();
        }
    }

    private void Start()
    {
        StartCoroutine(InitializeWhenReady());
    }

    /// <summary>
    /// Espera a que la BD y la sesion de usuario esten disponibles y aplica el estado guardado.
    /// Evita carreras de inicializacion entre DatabaseManager, UserSessionManager y esta escena.
    /// </summary>
    private IEnumerator InitializeWhenReady()
    {
        float elapsed = 0f;
        const float userWaitTimeout = 5f;

        while (DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady)
        {
            yield return null;
        }

        InitializeServices();

        // Damos un margen para que el auto-login / login termine de poblar la sesion.
        while (GetCurrentUserId() <= 0 && elapsed < userWaitTimeout)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        LoadUserModuleStatuses();
    }

    private void OnDestroy()
    {
        if (Instance == this)
        {
            Instance = null;
        }
    }

    private void InitializeServices()
    {
        try
        {
            modulesRepository = new ModulesRepository();
            progressService = new ProgressService();
        }
        catch (System.Exception ex)
        {
            modulesRepository = null;
            progressService = null;
            Debug.LogError($"EstadoManager: Error al inicializar servicios: {ex.Message}");
        }
    }

    private bool EnsureServicesReady()
    {
        if (progressService != null && modulesRepository != null)
        {
            return true;
        }

        if (DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady)
        {
            Debug.LogWarning("EstadoManager: La base de datos todavia no esta lista.");
            return false;
        }

        InitializeServices();
        return progressService != null && modulesRepository != null;
    }

    /// <summary>
    /// Llamado por IslandInteraction al tocar una isla: registra el modulo como iniciado
    /// (sin degradar avance existente) y refresca su indicador.
    /// </summary>
    public void GetAndLogModuleName(int moduleId)
    {
        if (!EnsureServicesReady())
        {
            return;
        }

        ModuleModel module = modulesRepository.GetModuleById(moduleId);
        if (module == null)
        {
            Debug.LogWarning($"EstadoManager: No se encontro un modulo con ID {moduleId} en la base de datos.");
        }
        else
        {
            Debug.Log($"Modulo detectado: {module.name}");
        }

        int userId = GetCurrentUserId();
        if (userId > 0)
        {
            progressService.EnsureModuleStarted(userId, moduleId);
        }

        ApplySavedStatusToModule(moduleId);
    }

    /// <summary>
    /// Vuelve a leer el avance del modulo y actualiza su indicador. Pensado para llamarse
    /// en vivo desde el libro cuando el usuario avanza de tema.
    /// </summary>
    public void RefreshModule(int moduleId)
    {
        if (moduleId != digestiveModuleId && moduleId != cellModuleId)
        {
            return;
        }

        if (!EnsureServicesReady())
        {
            return;
        }

        ApplySavedStatusToModule(moduleId);
    }

    private void LoadUserModuleStatuses()
    {
        ApplySavedStatusToModule(digestiveModuleId);
        ApplySavedStatusToModule(cellModuleId);
    }

    private void ApplySavedStatusToModule(int moduleId)
    {
        ModuleStatusIndicator indicator = GetIndicatorForModule(moduleId);

        string status = StatusNotStarted;
        int percentage = 0;

        int userId = GetCurrentUserId();
        if (userId > 0 && progressService != null)
        {
            ModuleProgressInfo info = progressService.GetModuleProgress(userId, moduleId);
            if (info != null)
            {
                status = info.status;
                percentage = info.percentage;
            }
        }

        if (indicator != null)
        {
            indicator.SetProgress(status, percentage / 100f);
        }
        else
        {
            Debug.LogWarning($"EstadoManager: No hay ModuleStatusIndicator asignado para el modulo {moduleId}.");
        }

        ApplyTextColor(moduleId, status);
    }

    private ModuleStatusIndicator GetIndicatorForModule(int moduleId)
    {
        if (moduleId == digestiveModuleId)
        {
            return digestiveIndicator;
        }

        if (moduleId == cellModuleId)
        {
            return cellIndicator;
        }

        return null;
    }

    private SpriteRenderer GetTextRendererForModule(int moduleId)
    {
        if (moduleId == digestiveModuleId)
        {
            return textDigestive;
        }

        if (moduleId == cellModuleId)
        {
            return textCell;
        }

        return null;
    }

    private void ApplyTextColor(int moduleId, string status)
    {
        SpriteRenderer textRenderer = GetTextRendererForModule(moduleId);
        if (textRenderer == null)
        {
            return;
        }

        textRenderer.color = GetTextColorForStatus(status);
    }

    private Color GetTextColorForStatus(string status)
    {
        return NormalizeStatus(status) switch
        {
            StatusCompleted => completedTextColor,
            StatusInProgress => inProgressTextColor,
            _ => notStartedTextColor
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

    private int GetCurrentUserId()
    {
        UserModel currentUser = UserSessionManager.Instance?.CurrentUser;
        return currentUser?.id_user ?? 0;
    }
}
