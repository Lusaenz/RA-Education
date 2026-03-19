using System;
using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Presenter que valida entradas de login, delega la autenticacion y coordina
/// la persistencia de sesion y la navegacion posterior.
/// </summary>
public class LoginPresenter
{
    AuthService authService;
    private const string TestInitialUserFlowScene = "TestInitialuserFlow";

    public LoginPresenter(AuthService auth)
    {
        authService = auth ?? throw new System.ArgumentNullException(nameof(auth));
    }

    // Se usa internamente tanto para estudiante como profesor; el campo NameError servirá para nombre o correo
    /// <summary>
    /// Resultado de validacion y autenticacion consumido por las vistas de login.
    /// </summary>
    public class LoginResult
    {
        public UserModel User { get; set; }
        public string GeneralMessage { get; set; }
        public string NameError { get; set; }
        public string PasswordError { get; set; }
        public bool IsSuccess => User != null;
    }

    /// <summary>
    /// Procesa el login del estudiante.
    /// </summary>
    public LoginResult LoginStudent(string name, string pass)
    {
        var result = new LoginResult();
        
        if (string.IsNullOrEmpty(name))
            result.NameError = "Escribe tu nombre completo.";
        if (string.IsNullOrEmpty(pass))
            result.PasswordError = "Escribe tu contraseña.";

        if (!string.IsNullOrEmpty(result.NameError) || !string.IsNullOrEmpty(result.PasswordError))
            return result;

        result.User = authService.LoginStudent(name, pass);
        if (result.User == null)
            result.GeneralMessage = "No encontramos tu cuenta. Revisa tus datos o regístrate";
        else
        {
            // Guardar usuario en sesión y cargar escena
            SaveUserAndLoadScene(result.User);
        }

        return result;
    }

    /// <summary>
    /// Procesa el login del profesor.
    /// </summary>
    public LoginResult LoginTeacher(string email, string pass)
    {
        var result = new LoginResult();

        if (string.IsNullOrEmpty(email))
            result.NameError = "Escribe tu correo electrónico.";
        if (string.IsNullOrEmpty(pass))
            result.PasswordError = "La contraseña no es correcta. Inténtalo otra vez.";

        if (!string.IsNullOrEmpty(result.NameError) || !string.IsNullOrEmpty(result.PasswordError))
            return result;

        result.User = authService.LoginTeacher(email, pass);
        if (result.User == null)
            result.GeneralMessage = "No encontramos tu cuenta. Revisa tus datos o regístrate";
        else
        {
            // Guardar usuario en sesión y cargar escena
            SaveUserAndLoadScene(result.User);
        }

        return result;
    }

    /// <summary>
    /// Persiste el usuario autenticado y redirige al flujo inicial.
    /// </summary>
    private void SaveUserAndLoadScene(UserModel user)
    {
        // Guardar el usuario en la sesión
        if (UserSessionManager.Instance != null)
        {
            UserSessionManager.Instance.SetCurrentUser(user);
        }
        else
        {
            Debug.LogError("UserSessionManager no está disponible.");
            return;
        }

        // Cargar la escena
        LoadScene(TestInitialUserFlowScene);
    }

    /// <summary>
    /// Carga una escena controlando errores de Unity.
    /// </summary>
    private void LoadScene(string sceneName)
    {
        try
        {
            SceneManager.LoadScene(sceneName);
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"Error al cargar la escena {sceneName}: {ex.Message}");
        }
    }
}
