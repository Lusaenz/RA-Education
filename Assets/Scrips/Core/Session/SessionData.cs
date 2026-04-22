using System;

/// <summary>
/// Modelo de datos para persistir información mínima de sesión y permitir auto-login.
/// Solo contiene el ID del usuario y timestamp para validación.
/// </summary>
[System.Serializable]
public class SessionData
{
    /// <summary>
    /// ID único del usuario autenticado.
    /// </summary>
    public int UserId { get; set; }

    /// <summary>
    /// Tipo de usuario: "Student" o "Teacher"
    /// </summary>
    public string UserType { get; set; }

    /// <summary>
    /// Timestamp de cuándo se guardó la sesión (para futuros usos como expiración).
    /// </summary>
    public long SavedAtTicks { get; set; }

    public SessionData()
    {
    }

    public SessionData(int userId, string userType)
    {
        UserId = userId;
        UserType = userType;
        SavedAtTicks = DateTime.UtcNow.Ticks;
    }

    /// <summary>
    /// Calcula cuánto tiempo ha pasado desde que se guardó la sesión.
    /// </summary>
    public TimeSpan GetElapsedTime()
    {
        return DateTime.UtcNow - new DateTime(SavedAtTicks);
    }
}
