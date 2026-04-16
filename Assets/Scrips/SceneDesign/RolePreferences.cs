using UnityEngine;

/// <summary>
/// Gestiona la persistencia del rol seleccionado en SelectRole.
/// Responsabilidad única: Guardar y recuperar preferencias de rol.
/// </summary>
public class RolePreferences
{
    private const string SELECTED_ROLE_KEY = "SelectedRoleId";
    private const int DEFAULT_ROLE = 1; // Estudiante

    /// <summary>
    /// Guarda el rol seleccionado en PlayerPrefs.
    /// </summary>
    public static void SaveSelectedRole(int roleId)
    {
        PlayerPrefs.SetInt(SELECTED_ROLE_KEY, roleId);
        PlayerPrefs.Save();
        Debug.Log($"[RolePreferences] Rol guardado: {roleId}");
    }

    /// <summary>
    /// Obtiene el rol guardado o retorna el rol por defecto.
    /// </summary>
    public static int GetSelectedRole()
    {
        int roleId = PlayerPrefs.GetInt(SELECTED_ROLE_KEY, DEFAULT_ROLE);
        Debug.Log($"[RolePreferences] Rol recuperado: {roleId}");
        return roleId;
    }

    /// <summary>
    /// Limpia el rol guardado (útil para logout).
    /// </summary>
    public static void ClearSelectedRole()
    {
        PlayerPrefs.DeleteKey(SELECTED_ROLE_KEY);
        PlayerPrefs.Save();
        Debug.Log("[RolePreferences] Rol limpiado");
    }
}
