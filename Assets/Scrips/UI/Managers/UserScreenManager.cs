using UnityEngine;
using System.Collections;
using System.Linq;

/// <summary>
/// Coordinador (Controller) para la pantalla de perfil del usuario.
/// Obtiene datos de servicios, los formatea usando el presenter,
/// y los envía a la vista para mostrar.
/// Sigue arquitectura MVP: es el intermediario entre modelo/servicios y vista.
/// </summary>
public class UserScreenManager : MonoBehaviour
{
    [SerializeField] private UserScreenView userScreenView;

    [Header("Modulos")]
    [SerializeField] private int digestiveModuleId = 1;
    [SerializeField] private int cellModuleId = 2;

    private UserScreenPresenter presenter;
    private DegreeService degreeService;
    private ResultActivityService resultActivityService;
    private ProgressService progressService;
    // Guardará temporalmente el estudiante seleccionado cuando el profesor presione "Ver Progreso"
public static UserModel SelectedUserForView { get; set; }

    // Usuario mostrado actualmente (para refrescarlo cuando llegan datos por la red).
    private UserModel displayedUser;

    private void OnEnable()
    {
        UserSyncService.OnDataSynced += RefreshDisplayedUser;
    }

    private void OnDisable()
    {
        UserSyncService.OnDataSynced -= RefreshDisplayedUser;
    }

    /// <summary>
    /// Vuelve a leer de SQLite el usuario mostrado y actualiza la vista.
    /// </summary>
    private void RefreshDisplayedUser()
    {
        if (displayedUser == null || presenter == null || userScreenView == null)
            return;

        int userId = displayedUser.id_user;
        UserModel updated = DatabaseManager.Instance?.GetConnection()?
            .Table<UserModel>()
            .FirstOrDefault(u => u.id_user == userId);

        UserSessionManager.SelectedUserForView = updated ?? displayedUser;
        LoadAndDisplayUserData();
    }

    private void Start()
    {
        StartCoroutine(InitializeWhenDatabaseReady());
    }

    /// <summary>
    /// Espera a que DatabaseManager esté listo.
    /// </summary>
    private IEnumerator InitializeWhenDatabaseReady()
    {
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        try
        {
            degreeService = new DegreeService();
            resultActivityService = new ResultActivityService();
            progressService = new ProgressService();
            presenter = new UserScreenPresenter();

            Debug.Log("[UserScreenManager] Inicializado correctamente");
            LoadAndDisplayUserData();
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"[UserScreenManager] Error en inicialización: {ex.Message}");
            if (userScreenView != null)
                userScreenView.DisplayError("Error al inicializar pantalla");
        }
    }

    /// <summary>
    /// Obtiene datos del usuario, los formatea y los envía a la vista.
    /// </summary>
    private void LoadAndDisplayUserData()
{
    if (presenter == null || userScreenView == null)
    {
        Debug.LogWarning("[UserScreenManager] Presenter o Vista no inicializados");
        return;
    }

    // 1. Priorizar el estudiante seleccionado desde la lista. Si es null, usar el logueado.
    UserModel targetUser = UserSessionManager.SelectedUserForView ?? UserSessionManager.Instance?.CurrentUser;

    // 2. Limpiar la variable estática para no dejar residuos si regresa al menú
    UserSessionManager.SelectedUserForView = null;

    if (targetUser == null)
    {
        displayedUser = null;
        Debug.LogWarning("[UserScreenManager] No se especificó usuario ni hay sesión activa");
        userScreenView.DisplayError("No hay sesión activa");
        return;
    }

    displayedUser = targetUser;

    try
    {
        int totalStars = GetTotalStarsForUser(targetUser.id_user);

        var formattedData = new UserScreenView.FormattedUserData
        {
            UserName = targetUser.name ?? "Usuario",
            RoleName = presenter.FormatRoleName(GetRoleNameFromId(targetUser.id_role)),
            DegreeName = presenter.FormatDegreeName(GetDegreeNameFromId(targetUser.id_degree)),
            TotalStars = presenter.FormatTotalStars(totalStars),
            DayLastLogin = "",
            DateLastLogin = ""
        };

        var lastLoginInfo = presenter.FormatLastLogin(targetUser.last_login);
        formattedData.DayLastLogin = lastLoginInfo.DayOnly;
        formattedData.DateLastLogin = lastLoginInfo.MonthAndYear;

        formattedData.DigestiveTime = presenter.FormatModuleTime(GetModuleProgress(targetUser.id_user, digestiveModuleId));
        formattedData.CellTime = presenter.FormatModuleTime(GetModuleProgress(targetUser.id_user, cellModuleId));

        userScreenView.DisplayUserData(formattedData);
        Debug.Log($"[UserScreenManager] Datos cargados correctamente para: {targetUser.name}");
    }
    catch (System.Exception ex)
    {
        Debug.LogError($"[UserScreenManager] Error al cargar datos: {ex.Message}");
        userScreenView.DisplayError("Error al cargar datos del usuario");
    }
}

    /// <summary>
    /// Obtiene el nombre del rol desde su ID.
    /// </summary>
    private string GetRoleNameFromId(int roleId)
    {
        return roleId switch
        {
            1 => "Estudiante",
            2 => "Profesor",
            _ => "Usuario"
        };
    }

    /// <summary>
    /// Obtiene el nombre del grado/carrera desde la BD.
    /// </summary>
    private string GetDegreeNameFromId(int degreeId)
    {
        if (degreeService == null)
        {
            Debug.LogWarning("[UserScreenManager] DegreeService no disponible");
            return null;
        }

        try
        {
            var degree = degreeService.GetDegreeById(degreeId);
            return degree?.name;
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"[UserScreenManager] Error al obtener grado: {ex.Message}");
            return null;
        }
    }

    /// <summary>
    /// Obtiene el avance del módulo (estado, % y minutos al completar) desde ProgressService.
    /// </summary>
    private ModuleProgressInfo GetModuleProgress(int userId, int moduleId)
    {
        if (progressService == null)
        {
            Debug.LogWarning("[UserScreenManager] ProgressService no disponible");
            return null;
        }

        try
        {
            return progressService.GetModuleProgress(userId, moduleId);
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"[UserScreenManager] Error al obtener avance del módulo {moduleId}: {ex.Message}");
            return null;
        }
    }

    /// <summary>
    /// Obtiene el total de estrellas del usuario desde ResultActivityService.
    /// </summary>
    private int GetTotalStarsForUser(int userId)
    {
        if (resultActivityService == null)
        {
            Debug.LogWarning("[UserScreenManager] ResultActivityService no disponible");
            return 0;
        }

        try
        {
            return resultActivityService.GetTotalStarsForUser(userId);
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"[UserScreenManager] Error al obtener estrellas: {ex.Message}");
            return 0;
        }
    }
}
