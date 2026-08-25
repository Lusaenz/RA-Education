using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Orquestador de inicialización de la aplicación.
/// Se ejecuta en la escena de selección de rol y maneja el auto-login si existe sesión guardada,
/// ocultando la selección de rol mientras se resuelve para que nunca entre en conflicto con ella.
/// Responsable de preparar las dependencias de sesión antes de cualquier flujo de login.
/// </summary>
public class SessionBootstrapper : MonoBehaviour
{
    /// <summary>
    /// Tiempo máximo de espera a que la BD esté lista antes de renunciar al auto-login.
    /// </summary>
    private const float DatabaseReadyTimeoutSeconds = 10f;

    /// <summary>
    /// Raíz de la UI de selección de rol (p.ej. el Canvas de SelectRole).
    /// Se oculta mientras se resuelve un posible auto-login y se reactiva si este no procede.
    /// </summary>
    [SerializeField] private GameObject roleSelectionRoot;

    private ISessionPersistence sessionPersistence;
    private IAutoLoginService autoLoginService;

    /// <summary>
    /// Se ejecuta automáticamente cuando se carga esta escena.
    /// Prepara las dependencias de sesión y, si hay una sesión guardada, oculta de inmediato
    /// la selección de rol para que el usuario no pueda elegir un rol distinto al de la sesión.
    /// </summary>
    private void Awake()
    {
        // Inicializar el contenedor de dependencias para sesión
        InitializeSessionDependencies();

        if (sessionPersistence.HasSavedSession() && roleSelectionRoot != null)
        {
            roleSelectionRoot.SetActive(false);
        }
    }

    /// <summary>
    /// Se ejecuta después de Awake.
    /// Intenta auto-login solo si existe sesión guardada. Si no hay sesión guardada,
    /// no hace nada y la selección de rol se muestra normalmente, sin delay.
    /// </summary>
    private void Start()
    {
        if (sessionPersistence.HasSavedSession())
        {
            StartCoroutine(AttemptAutoLoginWhenDatabaseReady());
        }
    }

    /// <summary>
    /// Crea las instancias de persistencia y servicio de auto-login.
    /// </summary>
    private void InitializeSessionDependencies()
    {
        // Crear implementación de persistencia (PlayerPrefs)
        sessionPersistence = new SessionPersistence();

        // El autoLoginService se crearemos cuando BD esté lista
        // porque necesita acceso al UserRepository
    }

    /// <summary>
    /// Espera a que la BD esté lista e intenta hacer auto-login.
    /// Si el auto-login es exitoso, salta directamente a la escena principal.
    /// Si falla o la BD tarda demasiado, reactiva la selección de rol para el flujo manual.
    /// </summary>
    private System.Collections.IEnumerator AttemptAutoLoginWhenDatabaseReady()
    {
        float elapsed = 0f;

        // Esperar a que DatabaseManager esté disponible y listo, con límite de tiempo
        // para no dejar la selección de rol oculta indefinidamente si la BD nunca inicializa.
        while ((DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady) && elapsed < DatabaseReadyTimeoutSeconds)
        {
            elapsed += Time.deltaTime;
            yield return null;
        }

        if (DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady)
        {
            Debug.LogWarning("SessionBootstrapper: Tiempo de espera agotado esperando la BD. Mostrando selección de rol.");
            ShowRoleSelection();
            yield break;
        }

        // Crear el servicio de auto-login con dependencias inyectadas
        var connection = DatabaseManager.Instance.GetConnection();
        var userRepository = new UserRepository(connection);
        autoLoginService = new AutoLoginService(sessionPersistence, userRepository);

        // Intentar auto-login
        UserModel autoLoginUser = autoLoginService.AttemptAutoLogin();

        if (autoLoginUser != null)
        {
            // Auto-login exitoso: cargar usuario en sesión y navegar
            Debug.Log($"SessionBootstrapper: Auto-login exitoso para {autoLoginUser.name}");

            if (UserSessionManager.Instance != null)
            {
                UserSessionManager.Instance.SetCurrentUser(autoLoginUser);

                // Cargar escena principal según el rol del usuario autenticado
                if (autoLoginUser.id_role == 2) // Profesor
                    SceneManager.LoadScene("HomeTeachers");
                else
                    SceneManager.LoadScene("TestInitialuserFlow");
            }
            else
            {
                Debug.LogError("SessionBootstrapper: UserSessionManager no está disponible.");
                ShowRoleSelection();
            }
        }
        else
        {
            // No hay auto-login (sesión inválida o inexistente): mostrar selección de rol normalmente
            Debug.Log("SessionBootstrapper: No se realizó auto-login. Mostrando selección de rol.");
            ShowRoleSelection();
        }
    }

    /// <summary>
    /// Reactiva la UI de selección de rol si estaba oculta por un intento de auto-login que no procedió.
    /// </summary>
    private void ShowRoleSelection()
    {
        if (roleSelectionRoot != null)
        {
            roleSelectionRoot.SetActive(true);
        }
    }
}
