using UnityEngine;

/// <summary>
/// Mantiene el usuario autenticado entre escenas mediante un singleton persistente.
/// </summary>
public class UserSessionManager : MonoBehaviour
{
    public static UserSessionManager Instance { get; private set; }

    public UserModel CurrentUser { get; private set; }

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
    /// Elimina la sesion activa.
    /// </summary>
    public void ClearSession()
    {
        CurrentUser = null;
    }
}
