using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Mantiene el usuario autenticado entre escenas mediante un singleton persistente.
/// Orquesta la sesión en memoria y coordina con el servicio de persistencia.
/// </summary>
public class UserSessionManager : MonoBehaviour
{
    public static UserSessionManager Instance { get; private set; }

    public UserModel CurrentUser { get; private set; }

    /// <summary>
    /// Referencia al servicio de persistencia para manejar logout.
    /// Se inicializa cuando está disponible.
    /// </summary>
    private IAutoLoginService autoLoginService;

    /// <summary>
    /// Garantiza una unica instancia viva durante toda la aplicacion.
    /// </summary>
    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    /// <summary>
    /// Actualiza el usuario actual en memoria.
    /// </summary>
    public void SetCurrentUser(UserModel user)
    {
        CurrentUser = user;
    }

    /// <summary>
    /// Realiza logout limpio: limpia sesión en memoria y elimina la sesión guardada.
    /// Luego redirige a la pantalla de login.
    /// </summary>
    public void Logout()
    {
        Debug.Log($"UserSessionManager: Liberando sesión de usuario {CurrentUser?.name ?? "desconocido"}");
        
        // Limpiar usuario en memoria
        CurrentUser = null;

        // Limpiar sesión guardada si está disponible
        if (autoLoginService != null)
        {
            autoLoginService.ClearSavedSession();
        }
        else
        {
            // Si el servicio no está disponible, usar directamente la persistencia
            ISessionPersistence persistence = new SessionPersistence();
            persistence.ClearSession();
        }

        // Redirigir a pantalla de login
        SceneManager.LoadScene("LoginStudentScene"); // Ajusta el nombre según tu escena de login
    }

    /// <summary>
    /// Establece la referencia al servicio de auto-login.
    /// Se llama desde SessionBootstrapper después de que la BD está lista.
    /// </summary>
    public void SetAutoLoginService(IAutoLoginService service)
    {
        autoLoginService = service;
    }

    /// <summary>
    /// Retorna si hay un usuario actualmente autenticado.
    /// </summary>
    public bool IsUserLoggedIn()
    {
        return CurrentUser != null;
    }

    /// <summary>
    /// Elimina la sesion activa sin ir al login (solo limpieza en memoria).
    /// </summary>
    public void ClearSession()
    {
        CurrentUser = null;
    }
}
