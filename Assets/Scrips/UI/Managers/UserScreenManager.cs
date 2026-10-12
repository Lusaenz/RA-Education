using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using SQLite4Unity3d;

/// <summary>
/// Coordinador (Controller) para la pantalla de perfil del usuario.
/// Obtiene datos de servicios, los formatea usando el presenter,
/// y los envía a la vista para mostrar.
/// Sigue arquitectura MVP: es el intermediario entre modelo/servicios y vista.
/// </summary>
public class UserScreenManager : MonoBehaviour
{
    [SerializeField] private UserScreenView userScreenView;

    [Header("Módulos usados para los tiempos de finalización")]
    [SerializeField] private int cellModuleId = 2;       // "La célula y los seres vivos"
    [SerializeField] private int digestiveModuleId = 1;  // "Aparato Digestivo"

    private UserScreenPresenter presenter;
    private DegreeService degreeService;
    private ResultActivityService resultActivityService;
    // Guardará temporalmente el estudiante seleccionado cuando el profesor presione "Ver Progreso"
public static UserModel SelectedUserForView { get; set; }

    // Usuario mostrado actualmente (para refrescarlo cuando llegan datos por la red).
    private UserModel displayedUser;

    private void OnEnable()
    {
        UserSyncService.OnDataSynced += ActualizarPantalla;
    }

    private void OnDisable()
    {
        UserSyncService.OnDataSynced -= ActualizarPantalla;
    }

    /// <summary>
    /// Vuelve a leer de SQLite el usuario mostrado y actualiza todos los componentes
    /// de la escena (perfil, ranking, tiempos y última conexión).
    /// Se llama sola cuando llegan datos por la red; también se puede asignar a un botón.
    /// </summary>
    public void ActualizarPantalla()
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

        FillRanking(targetUser, formattedData);
        FillCompletionTimes(targetUser, formattedData);

        var lastLoginInfo = presenter.FormatLastLogin(targetUser.last_login);
        formattedData.DayLastLogin = lastLoginInfo.DayOnly;
        formattedData.DateLastLogin = lastLoginInfo.MonthAndYear;

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

    // =====================================================================
    // Ranking
    // =====================================================================

    /// <summary>
    /// Calcula el puesto del estudiante entre los estudiantes de su mismo grado.
    /// Orden: más estrellas primero; si empatan, más minijuegos completados; luego por nombre.
    /// Podio: escalón central = puesto del estudiante, izquierdo = puesto anterior,
    /// derecho = puesto siguiente (se ocultan si no existen).
    /// </summary>
    private void FillRanking(UserModel user, UserScreenView.FormattedUserData data)
    {
        data.StudentName = user.name ?? "Estudiante";

        if (user.id_role != 1)
        {
            data.CenterPosition = "-";
            data.LeftPosition = null;
            data.RightPosition = null;
            data.AcquiredPosition = "Sin ranking";
            return;
        }

        try
        {
            SQLiteConnection db = DatabaseManager.Instance.GetConnection();
            int degreeId = user.id_degree;

            List<UserModel> classmates = db.Table<UserModel>()
                .Where(u => u.id_role == 1 && u.id_degree == degreeId)
                .ToList();

            ProgressService progressService = new ProgressService();

            var ranked = classmates
                .Select(u => new
                {
                    u.id_user,
                    name = u.name ?? string.Empty,
                    stars = GetTotalStarsForUser(u.id_user),
                    games = progressService.CountCompletedGames(u.id_user, out _)
                })
                .OrderByDescending(x => x.stars)
                .ThenByDescending(x => x.games)
                .ThenBy(x => x.name)
                .ToList();

            int index = ranked.FindIndex(x => x.id_user == user.id_user);
            if (index < 0)
            {
                data.CenterPosition = "-";
                data.AcquiredPosition = "Sin ranking";
                return;
            }

            int position = index + 1;

            data.CenterPosition = position.ToString();
            data.LeftPosition = position > 1 ? (position - 1).ToString() : null;
            data.RightPosition = position < ranked.Count ? (position + 1).ToString() : null;
            data.AcquiredPosition = $"Puesto adquirido: {position} de {ranked.Count}";
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"[UserScreenManager] Error al calcular ranking: {ex.Message}");
            data.CenterPosition = "-";
            data.AcquiredPosition = "Sin ranking";
        }
    }

    // =====================================================================
    // Tiempos de finalización por módulo
    // =====================================================================

    private void FillCompletionTimes(UserModel user, UserScreenView.FormattedUserData data)
    {
        try
        {
            SQLiteConnection db = DatabaseManager.Instance.GetConnection();
            data.CellTime = GetModuleTimeText(db, user.id_user, cellModuleId);
            data.DigestiveTime = GetModuleTimeText(db, user.id_user, digestiveModuleId);
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"[UserScreenManager] Error al calcular tiempos: {ex.Message}");
            data.CellTime = "-";
            data.DigestiveTime = "-";
        }
    }

    /// <summary>
    /// Tiempo que tardó el estudiante en terminar los minijuegos del módulo:
    /// suma del tiempo de la PRIMERA vez que completó cada minijuego (al menos 1 estrella).
    /// Si falta algún minijuego por completar devuelve "Sin terminar".
    /// </summary>
    private string GetModuleTimeText(SQLiteConnection db, int userId, int moduleId)
    {
        List<GameActivityData> allGames = db.Table<GameActivityData>().ToList();
        List<GameActivityData> moduleGames = allGames.Where(g => g.id_module == moduleId).ToList();

        if (moduleGames.Count == 0)
            return "-";

        List<ResultActivityData> results = db.Table<ResultActivityData>()
            .Where(r => r.id_user == userId)
            .ToList();

        int totalSeconds = 0;

        foreach (GameActivityData game in moduleGames)
        {
            ResultActivityData first = results
                .Where(r => r.stars >= 1 && ResolveGameActivityId(r, allGames) == game.id_game_activity)
                .OrderBy(r => r.id_result)
                .FirstOrDefault();

            if (first == null)
                return "Sin terminar";

            totalSeconds += ParseSeconds(first.completed_at);
        }

        return FormatDuration(totalSeconds);
    }

    /// <summary>
    /// Resultados nuevos guardan id_game_activity. En resultados antiguos (0) se deduce
    /// desde id_activity solo si ese tipo de actividad pertenece a un único minijuego.
    /// </summary>
    private static int ResolveGameActivityId(ResultActivityData r, List<GameActivityData> allGames)
    {
        if (r.id_game_activity > 0)
            return r.id_game_activity;

        List<GameActivityData> matches = allGames.Where(g => g.id_activity == r.id_activity).ToList();
        return matches.Count == 1 ? matches[0].id_game_activity : 0;
    }

    /// <summary>
    /// Convierte "mm:ss" a segundos.
    /// </summary>
    private static int ParseSeconds(string time)
    {
        if (string.IsNullOrEmpty(time))
            return 0;

        string[] parts = time.Split(':');
        if (parts.Length == 2 &&
            int.TryParse(parts[0], out int minutes) &&
            int.TryParse(parts[1], out int seconds))
        {
            return minutes * 60 + seconds;
        }

        return int.TryParse(time, out int onlySeconds) ? onlySeconds : 0;
    }

    private static string FormatDuration(int totalSeconds)
    {
        int minutes = totalSeconds / 60;
        int seconds = totalSeconds % 60;

        if (minutes == 0)
            return $"{seconds} s";

        return seconds == 0 ? $"{minutes} min" : $"{minutes} min {seconds} s";
    }
}
