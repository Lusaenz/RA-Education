using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

/// <summary>
/// Componente que gestiona los botones de sesión: Logout y Exit.
/// Logout: cierra la sesión y redirige a SelectRole
/// Exit: cierra la aplicación sin cerrar sesión
/// </summary>
public class SessionButtons : MonoBehaviour
{
    [SerializeField] private Button logoutButton;
    [SerializeField] private Button exitButton;

    private void Start()
    {
        if (logoutButton != null)
            logoutButton.onClick.AddListener(OnLogoutClicked);

        if (exitButton != null)
            exitButton.onClick.AddListener(OnExitClicked);
    }

    /// <summary>
    /// Cierra la sesión y redirige a la escena SelectRole
    /// </summary>
    private void OnLogoutClicked()
    {
        Debug.Log("[SessionButtons] Cerrando sesión");

        // Limpiar sesión guardada (recuérdame) para evitar auto-login al volver
        new SessionPersistence().ClearSession();

        if (UserSessionManager.Instance != null)
        {
            UserSessionManager.Instance.ClearSession();
        }
        else
        {
            Debug.LogWarning("[SessionButtons] UserSessionManager no encontrado");
        }

        SceneManager.LoadScene("SelectRole");
    }

    /// <summary>
    /// Sale de la aplicación sin cerrar sesión
    /// </summary>
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
        if (logoutButton != null)
            logoutButton.onClick.RemoveListener(OnLogoutClicked);

        if (exitButton != null)
            exitButton.onClick.RemoveListener(OnExitClicked);
    }
}
