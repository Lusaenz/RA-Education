/// <summary>
/// Contrato para persistir y recuperar datos de sesión rememberada.
/// Abstrae el mecanismo subyacente (PlayerPrefs, archivo local, etc).
/// </summary>
public interface ISessionPersistence
{
    /// <summary>
    /// Guarda los datos de sesión de forma persistente.
    /// </summary>
    void SaveSession(SessionData sessionData);

    /// <summary>
    /// Recupera los datos de sesión guardados previamente.
    /// Retorna null si no existen datos guardados.
    /// </summary>
    SessionData LoadSession();

    /// <summary>
    /// Elimina los datos de sesión persistida.
    /// </summary>
    void ClearSession();

    /// <summary>
    /// Verifica si existe una sesión guardada.
    /// </summary>
    bool HasSavedSession();
}
