using UnityEngine;
using System.Linq;

/// <summary>
/// Servicio que implementa la lógica de auto-login.
/// Valida que la sesión guardada sea válida y que el usuario aún exista en BD.
/// Sigue el patrón de inyección de dependencias para máxima testabilidad.
/// </summary>
public class AutoLoginService : IAutoLoginService
{
    private readonly ISessionPersistence sessionPersistence;
    private readonly UserRepository userRepository;

    /// <summary>
    /// Inyecta las dependencias necesarias para auto-login.
    /// </summary>
    public AutoLoginService(ISessionPersistence persistence, UserRepository repository)
    {
        sessionPersistence = persistence ?? throw new System.ArgumentNullException(nameof(persistence));
        userRepository = repository ?? throw new System.ArgumentNullException(nameof(repository));
    }

    /// <summary>
    /// Intenta hacer auto-login desde una sesión guardada.
    /// Valida que el usuario aún exista en la BD antes de recuperarlo.
    /// </summary>
    public UserModel AttemptAutoLogin()
    {
        if (!HasSavedSession())
        {
            Debug.Log("AutoLoginService: No hay sesión guardada disponible.");
            return null;
        }

        SessionData savedSession = sessionPersistence.LoadSession();
        if (savedSession == null)
        {
            Debug.LogWarning("AutoLoginService: No se pudo cargar la sesión guardada.");
            return null;
        }

        // Validar que el usuario aún exista en la BD
        UserModel user = GetUserById(savedSession.UserId);
        if (user == null)
        {
            Debug.LogWarning($"AutoLoginService: Usuario {savedSession.UserId} no existe en BD. Limpiando sesión guardada.");
            ClearSavedSession();
            return null;
        }

        Debug.Log($"AutoLoginService: Auto-login exitoso para usuario {user.name} (ID: {user.id_user})");
        return user;
    }

    /// <summary>
    /// Verifica si existe una sesión guardada para recuperar.
    /// </summary>
    public bool HasSavedSession()
    {
        return sessionPersistence.HasSavedSession();
    }

    /// <summary>
    /// Elimina la sesión guardada (logout).
    /// </summary>
    public void ClearSavedSession()
    {
        sessionPersistence.ClearSession();
        Debug.Log("AutoLoginService: Sesión guardada eliminada (logout).");
    }

    /// <summary>
    /// Recupera un usuario por su ID desde la BD.
    /// Es responsabilidad del UserRepository validar que el usuario exista.
    /// </summary>
    private UserModel GetUserById(int userId)
    {
        try
        {
            // Utilizamos SQL genérico para traer cualquier usuario por ID
            var connection = DatabaseManager.Instance?.GetConnection();
            if (connection == null)
            {
                Debug.LogError("AutoLoginService: No se pudo obtener la conexión a la BD.");
                return null;
            }

            var result = connection.Table<UserModel>()
                .FirstOrDefault(u => u.id_user == userId);

            return result;
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"AutoLoginService: Error al recuperar usuario {userId}: {ex.Message}");
            return null;
        }
    }
}
