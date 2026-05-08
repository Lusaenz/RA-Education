using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Orquestador de inicialización de la aplicación.
/// Se ejecuta en la escena de login y maneja el auto-login si existe sesión guardada.
/// Responsable de preparar las dependencias de sesión antes de cualquier flujo de login.
/// </summary>
public class SessionBootstrapper : MonoBehaviour
{
    private ISessionPersistence sessionPersistence;
    private IAutoLoginService autoLoginService;

    /// <summary>
    /// Se ejecuta automáticamente cuando se carga esta escena.
    /// Prepara las dependencias de sesión.
    /// </summary>
    private void Awake()
    {
        // Inicializar el contenedor de dependencias para sesión
        InitializeSessionDependencies();
    }

    /// <summary>
    /// Se ejecuta después de Awake.
    /// Intenta auto-login si existe sesión guardada y la BD está lista.
    /// </summary>
    private void Start()
    {
        // Esperar a que DatabaseManager esté listo para intentar auto-login
        StartCoroutine(AttemptAutoLoginWhenDatabaseReady());
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
    /// </summary>
    private System.Collections.IEnumerator AttemptAutoLoginWhenDatabaseReady()
    {
        // Esperar a que DatabaseManager esté disponible
        yield return new WaitUntil(() => DatabaseManager.Instance != null);

        // Esperar a que la BD esté lista
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

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
                // Cargar escena principal
                SceneManager.LoadScene("TestInitialuserFlow");
            }
            else
            {
                Debug.LogError("SessionBootstrapper: UserSessionManager no está disponible.");
            }
        }
        else
        {
            // No hay auto-login: mostrar pantalla de login normalmente
            Debug.Log("SessionBootstrapper: No se realizó auto-login. Mostrando pantalla de login.");
        }
    }
}
