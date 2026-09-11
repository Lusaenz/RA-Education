using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

/// <summary>
/// Gestiona la navegación de la barra superior: Volver (según Rol), Cerrar Sesión y Salir.
/// </summary>
public class SessionButtons : MonoBehaviour
{
    [SerializeField] private Button backButton;   // Botón de Inicio / Casita / Volver
    [SerializeField] private Button logoutButton; // Botón de Cerrar Sesión
    [SerializeField] private Button exitButton;   // Botón de Salir

    private void Start()
    {
        if (backButton != null)
            backButton.onClick.AddListener(OnBackClicked);

        if (logoutButton != null)
            logoutButton.onClick.AddListener(OnLogoutClicked);

        if (exitButton != null)
            exitButton.onClick.AddListener(OnExitClicked);
    }

    /// <summary>
    /// Redirige a la escena correspondiente según el rol del usuario actual
    /// </summary>
    private void OnBackClicked()
    {
        // 1. Limpiamos la selección temporal del perfil si veníamos de ver un estudiante
        UserSessionManager.SelectedUserForView = null;

        // 2. Verificamos la sesión activa
        if (UserSessionManager.Instance != null && UserSessionManager.Instance.CurrentUser != null)
        {
            int roleId = UserSessionManager.Instance.CurrentUser.id_role;

            if (roleId == 1) // Estudiante
            {
                Debug.Log("[SessionButtons] Redirigiendo a TestInitialuserFlow (Estudiante)");
                SceneManager.LoadScene("TestInitialuserFlow");
            }
            else if (roleId == 2) // Profesor
            {
                Debug.Log("[SessionButtons] Redirigiendo a HomeTeachers (Profesor)");
                SceneManager.LoadScene("HomeTeachers");
            }
            else
            {
                Debug.LogWarning($"[SessionButtons] Rol no reconocido ({roleId}). Cargando SelectRole.");
                SceneManager.LoadScene("SelectRole");
            }
        }
        else
        {
            Debug.LogWarning("[SessionButtons] No hay sesión activa. Cargando SelectRole.");
            SceneManager.LoadScene("SelectRole");
        }
    }

    private void OnLogoutClicked()
    {
        Debug.Log("[SessionButtons] Cerrando sesión");
        
        UserSessionManager.SelectedUserForView = null;
        new SessionPersistence().ClearSession();

        if (UserSessionManager.Instance != null)
        {
            UserSessionManager.Instance.ClearSession();
        }

        SceneManager.LoadScene("SelectRole");
    }

    private void OnExitClicked()
    {
        Debug.Log("[SessionButtons] Saliendo de la aplicación");

        #if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
        #else
            Application.Quit();
        #endif
    }

    private void OnDestroy()
    {
        if (backButton != null) backButton.onClick.RemoveListener(OnBackClicked);
        if (logoutButton != null) logoutButton.onClick.RemoveListener(OnLogoutClicked);
        if (exitButton != null) exitButton.onClick.RemoveListener(OnExitClicked);
    }
}