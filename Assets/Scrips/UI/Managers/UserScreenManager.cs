using UnityEngine;
using System.Collections;

/// <summary>
/// Coordinador (Controller) para la pantalla de perfil del usuario.
/// Obtiene datos de servicios, los formatea usando el presenter,
/// y los envía a la vista para mostrar.
/// Sigue arquitectura MVP: es el intermediario entre modelo/servicios y vista.
/// </summary>
public class UserScreenManager : MonoBehaviour
{
    [SerializeField] private UserScreenView userScreenView;

    private UserScreenPresenter presenter;
    private DegreeService degreeService;
    private ResultActivityService resultActivityService;

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

        if (UserSessionManager.Instance == null || UserSessionManager.Instance.CurrentUser == null)
        {
            Debug.LogWarning("[UserScreenManager] No hay usuario autenticado");
            userScreenView.DisplayError("No hay sesión activa");
            return;
        }

        try
        {
            UserModel currentUser = UserSessionManager.Instance.CurrentUser;

            int totalStars = GetTotalStarsForUser(currentUser.id_user);

            var formattedData = new UserScreenView.FormattedUserData
            {
                UserName = currentUser.name ?? "Usuario",
                RoleName = presenter.FormatRoleName(GetRoleNameFromId(currentUser.id_role)),
                DegreeName = presenter.FormatDegreeName(GetDegreeNameFromId(currentUser.id_degree)),
                TotalStars = presenter.FormatTotalStars(totalStars),
                DayLastLogin = "",
                DateLastLogin = ""
            };

            var lastLoginInfo = presenter.FormatLastLogin(currentUser.last_login);
            formattedData.DayLastLogin = lastLoginInfo.DayOnly;
            formattedData.DateLastLogin = lastLoginInfo.MonthAndYear;

            userScreenView.DisplayUserData(formattedData);
            Debug.Log($"[UserScreenManager] Datos cargados para usuario: {currentUser.name}");
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
