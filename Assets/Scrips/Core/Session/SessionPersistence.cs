using UnityEngine;

/// <summary>
/// Implementación de persistencia de sesión usando PlayerPrefs.
/// Encapsula completamente el acceso a PlayerPrefs para permitir cambios futuros sin afectar el resto del código.
/// </summary>
public class SessionPersistence : ISessionPersistence
{
    /// <summary>
    /// Clave base para acceder a PlayerPrefs. Prefijo para evitar colisiones.
    /// </summary>
    private const string SESSION_KEY_PREFIX = "RAEdu_Session_";
    
    /// <summary>
    /// Clave específica para el ID del usuario rememberado.
    /// </summary>
    private const string USER_ID_KEY = SESSION_KEY_PREFIX + "UserId";
    
    /// <summary>
    /// Clave específica para el tipo de usuario rememberado.
    /// </summary>
    private const string USER_TYPE_KEY = SESSION_KEY_PREFIX + "UserType";
    
    /// <summary>
    /// Clave específica para el timestamp de cuándo se guardó.
    /// </summary>
    private const string SAVED_AT_TICKS_KEY = SESSION_KEY_PREFIX + "SavedAtTicks";

    /// <summary>
    /// Guarda los datos de sesión de forma persistente en PlayerPrefs.
    /// </summary>
    public void SaveSession(SessionData sessionData)
    {
        if (sessionData == null)
        {
            Debug.LogWarning("SessionPersistence: No se puede guardar sesión nula.");
            return;
        }

        PlayerPrefs.SetInt(USER_ID_KEY, sessionData.UserId);
        PlayerPrefs.SetString(USER_TYPE_KEY, sessionData.UserType);
        PlayerPrefs.SetString(SAVED_AT_TICKS_KEY, sessionData.SavedAtTicks.ToString());
        PlayerPrefs.Save();

        Debug.Log($"SessionPersistence: Sesión guardada para usuario {sessionData.UserId} (tipo: {sessionData.UserType})");
    }

    /// <summary>
    /// Recupera los datos de sesión desde PlayerPrefs.
    /// Retorna null si no existen datos guardados o si están corruptos.
    /// </summary>
    public SessionData LoadSession()
    {
        if (!HasSavedSession())
        {
            return null;
        }

        try
        {
            int userId = PlayerPrefs.GetInt(USER_ID_KEY, -1);
            string userType = PlayerPrefs.GetString(USER_TYPE_KEY, "");
            string ticksString = PlayerPrefs.GetString(SAVED_AT_TICKS_KEY, "0");

            if (userId <= 0 || string.IsNullOrEmpty(userType) || !long.TryParse(ticksString, out long ticks))
            {
                Debug.LogWarning("SessionPersistence: Datos de sesión guardados están corruptos o inválidos.");
                ClearSession();
                return null;
            }

            SessionData data = new SessionData
            {
                UserId = userId,
                UserType = userType,
                SavedAtTicks = ticks
            };

            Debug.Log($"SessionPersistence: Sesión cargada para usuario {userId} (tipo: {userType})");
            return data;
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"SessionPersistence: Error al cargar sesión: {ex.Message}");
            ClearSession();
            return null;
        }
    }

    /// <summary>
    /// Elimina completamente los datos de sesión guardados.
    /// </summary>
    public void ClearSession()
    {
        if (PlayerPrefs.HasKey(USER_ID_KEY))
            PlayerPrefs.DeleteKey(USER_ID_KEY);
        if (PlayerPrefs.HasKey(USER_TYPE_KEY))
            PlayerPrefs.DeleteKey(USER_TYPE_KEY);
        if (PlayerPrefs.HasKey(SAVED_AT_TICKS_KEY))
            PlayerPrefs.DeleteKey(SAVED_AT_TICKS_KEY);

        PlayerPrefs.Save();
        Debug.Log("SessionPersistence: Sesión eliminada.");
    }

    /// <summary>
    /// Verifica si existe una sesión guardada.
    /// </summary>
    public bool HasSavedSession()
    {
        return PlayerPrefs.HasKey(USER_ID_KEY) && 
               PlayerPrefs.HasKey(USER_TYPE_KEY) && 
               PlayerPrefs.HasKey(SAVED_AT_TICKS_KEY);
    }
}
