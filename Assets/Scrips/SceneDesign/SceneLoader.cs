using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Gestor de carga de escenas.
/// Responsabilidad única: Cargar escenas de forma segura.
/// No gestiona persistencia de datos - usa RolePreferences para eso.
/// </summary>
public class SceneLoader : MonoBehaviour
{
    public string sceneName;

    /// <summary>
    /// Carga una escena por nombre específico.
    /// Uso: Botones que necesitan cargar una escena fija (ej: "MainMenu").
    /// Se configura el nombre en el Inspector: sceneName
    /// </summary>
    public void LoadScene()
    {
        if (string.IsNullOrEmpty(sceneName))
        {
            Debug.LogError("[SceneLoader] sceneName no está configurado en el Inspector");
            return;
        }

        Debug.Log($"[SceneLoader] Cargando escena: {sceneName}");
        SceneManager.LoadScene(sceneName);
    }

    /// <summary>
    /// Carga la escena de login correspondiente según el rol pasado.
    /// Estudiante (1) → LoginStudent
    /// Profesor (2) → LoginTeacher
    /// Uso: Desde ForgotPasswordView con currentUser.id_role
    /// </summary>
    public void LoadLoginByRole(int roleId)
    {
        string targetScene = GetLoginSceneForRole(roleId);
        Debug.Log($"[SceneLoader] Rol ID: {roleId} → Cargando escena: {targetScene}");
        SceneManager.LoadScene(targetScene);
    }

    /// <summary>
    /// Botón de regresar: Carga login según el rol guardado en SelectRole.
    /// NO depende de datos en sesión.
    /// Uso: OnClick del botón de regresar en ForgotPassword, etc.
    /// </summary>
    public void LoadLoginForBackButton()
    {
        int roleId = RolePreferences.GetSelectedRole();
        string targetScene = GetLoginSceneForRole(roleId);
        Debug.Log($"[SceneLoader] Back Button - Rol ID: {roleId} → Cargando escena: {targetScene}");
        SceneManager.LoadScene(targetScene);
    }

    /// <summary>
    /// Mapea un ID de rol a su escena de login correspondiente.
    /// Centraliza la lógica de mapeo para evitar duplicación.
    /// </summary>
    private string GetLoginSceneForRole(int roleId)
    {
        return roleId switch
        {
            1 => "LoginStudent",      // Estudiante
            2 => "LoginTeacher",      // Profesor
            _ => "LoginStudent"       // Default: Estudiante
        };
    }
}