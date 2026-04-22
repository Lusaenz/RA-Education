/// <summary>
/// Servicio que orquesta el proceso de auto-login usando una sesión guardada.
/// Define el contrato para validar y recuperar usuarios automáticamente.
/// </summary>
public interface IAutoLoginService
{
    /// <summary>
    /// Intenta realizar auto-login usando los datos guardados en SessionData.
    /// Valida que el usuario aún exista en la base de datos.
    /// </summary>
    /// <returns>El UserModel si el auto-login fue exitoso, null en caso contrario.</returns>
    UserModel AttemptAutoLogin();

    /// <summary>
    /// Verifica si existe una sesión guardada que pueda ser recuperada.
    /// </summary>
    bool HasSavedSession();

    /// <summary>
    /// Elimina la sesión guardada (para logout).
    /// </summary>
    void ClearSavedSession();
}
