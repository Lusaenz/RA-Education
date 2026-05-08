
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;

/// <summary>
/// Vista para mostrar el perfil/datos del usuario autenticado.
/// Obtiene datos de UserSessionManager y los formatea usando UserScreenPresenter.
/// Sigue arquitectura MVP.
/// </summary>
public class UserScreenView : MonoBehaviour
{
    // ==================== UI Elements ====================
    [SerializeField] private TextMeshProUGUI userNameText;
    [SerializeField] private TextMeshProUGUI roleTypeText;
    [SerializeField] private TextMeshProUGUI degreeText;
    [SerializeField] private TextMeshProUGUI totalStarsText;
    [SerializeField] private TextMeshProUGUI dayLastLoginText;
    [SerializeField] private TextMeshProUGUI dateLastLoginText;

    // ==================== Dependencies ====================
    private UserScreenPresenter presenter;
    private bool initialized = false;

    // ==================== Lifecycle ====================

    void Start()
    {
        StartCoroutine(InitializeWhenDatabaseReady());
    }

    // ==================== Initialization ====================

    /// <summary>
    /// Espera a que DatabaseManager esté listo y luego inicializa el presenter.
    /// </summary>
    private System.Collections.IEnumerator InitializeWhenDatabaseReady()
    {
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        try
        {
            var degreeService = new DegreeService();

            // Crear presenter con DegreeService
            presenter = new UserScreenPresenter(degreeService);
            initialized = true;

            Debug.Log("[UserScreenView] Presenter inicializado con DegreeService");

            // Cargar datos del usuario
            LoadAndDisplayUserData();
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"[UserScreenView] Error en inicialización: {ex.Message}");
            ShowErrorMessage("Error al inicializar pantalla");
        }
    }

    /// <summary>
    /// Carga y muestra los datos del usuario autenticado.
    /// </summary>
    private void LoadAndDisplayUserData()
    {
        if (!initialized)
        {
            Debug.LogWarning("[UserScreenView] Vista no está inicializada aún");
            return;
        }

        // Validar que haya usuario autenticado
        if (UserSessionManager.Instance == null || UserSessionManager.Instance.CurrentUser == null)
        {
            Debug.LogWarning("[UserScreenView] No hay usuario autenticado. Redirigiendo a login.");
            ShowNoUserError();
            return;
        }

        UserModel currentUser = UserSessionManager.Instance.CurrentUser;

        try
        {
            // Mostrar nombre de usuario
            DisplayUserName(currentUser.name);

            // Mostrar tipo de rol
            DisplayRoleType(currentUser.id_role);

            // Mostrar grado/carrera (ahora con nombre desde BD)
            DisplayDegree(currentUser.id_degree);

            // Mostrar estrellas (si existen)
            DisplayTotalStars(0); // TODO: Obtener valor de la BD o modelo

            // Mostrar fecha del último login
            DisplayLastLogin(currentUser.last_login);

            Debug.Log($"[UserScreenView] Datos cargados para usuario: {currentUser.name}");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"[UserScreenView] Error al cargar datos: {ex.Message}");
            ShowErrorMessage("Error al cargar datos del usuario");
        }
    }

    // ==================== Display Methods ====================

    /// <summary>
    /// Muestra el nombre del usuario en el campo designado.
    /// </summary>
    private void DisplayUserName(string name)
    {
        if (userNameText == null)
        {
            Debug.LogWarning("[UserScreenView] userNameText no está asignado");
            return;
        }

        userNameText.text = name;
    }

    /// <summary>
    /// Muestra el tipo de rol en formato legible.
    /// </summary>
    private void DisplayRoleType(int roleId)
    {
        if (roleTypeText == null)
        {
            Debug.LogWarning("[UserScreenView] roleTypeText no está asignado");
            return;
        }

        if (presenter == null)
        {
            Debug.LogWarning("[UserScreenView] Presenter no está inicializado");
            roleTypeText.text = $"Rol: {roleId}";
            return;
        }

        string roleName = presenter.GetRoleName(roleId);
        roleTypeText.text = roleName;
    }

    /// <summary>
    /// Muestra el nombre del grado/carrera obtenido desde la BD.
    /// </summary>
    private void DisplayDegree(int degreeId)
    {
        if (degreeText == null)
        {
            Debug.LogWarning("[UserScreenView] degreeText no está asignado");
            return;
        }

        if (presenter == null)
        {
            Debug.LogWarning("[UserScreenView] Presenter no está inicializado");
            degreeText.text = $"Grado: {degreeId}";
            return;
        }

        string degreeName = presenter.GetDegreeName(degreeId);
        degreeText.text = degreeName;
    }

    /// <summary>
    /// Muestra el total de estrellas/puntos del usuario.
    /// </summary>
    private void DisplayTotalStars(int stars)
    {
        if (totalStarsText == null)
        {
            Debug.LogWarning("[UserScreenView] totalStarsText no está asignado");
            return;
        }

        totalStarsText.text = stars.ToString();
    }

    /// <summary>
    /// Muestra la información del último login formateada.
    /// - Day: Solo el número del día (ej: "14")
    /// - MonthYear: Mes en palabras + año (ej: "Abril 2026")
    /// </summary>
    private void DisplayLastLogin(string lastLoginDate)
    {
        if (dayLastLoginText == null || dateLastLoginText == null)
        {
            Debug.LogWarning("[UserScreenView] dayLastLoginText o dateLastLoginText no están asignados");
            return;
        }

        if (presenter == null)
        {
            Debug.LogWarning("[UserScreenView] Presenter no está inicializado");
            dayLastLoginText.text = "--";
            dateLastLoginText.text = "--";
            return;
        }

        // Formatear la fecha usando el presenter
        var lastLoginInfo = presenter.FormatLastLogin(lastLoginDate);

        // Mostrar día
        dayLastLoginText.text = lastLoginInfo.DayOnly;

        // Mostrar mes y año
        dateLastLoginText.text = lastLoginInfo.MonthAndYear;

        Debug.Log($"[UserScreenView] Último login: {lastLoginInfo.DayOnly}, {lastLoginInfo.MonthAndYear}");
    }

    // ==================== Error Handlers ====================

    /// <summary>
    /// Muestra un mensaje de error cuando no hay usuario autenticado.
    /// </summary>
    private void ShowNoUserError()
    {
        ShowErrorMessage("No hay sesión activa");
        // Opcional: Redirigir a login después de un delay
    }

    /// <summary>
    /// Muestra un mensaje de error genérico en los campos.
    /// </summary>
    private void ShowErrorMessage(string message)
    {
        if (userNameText != null)
            userNameText.text = message;

        Debug.LogError($"[UserScreenView] Error: {message}");
    }
}