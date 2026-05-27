using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.SceneManagement;

/// <summary>
/// Vista de login unificada para estudiantes y profesores.
/// Captura entradas, delega la autenticacion al presenter segun el rol y representa mensajes de error.
/// Orquesta la funcionalidad de "Recordar sesión" mediante persistencia.
/// Detecta el rol seleccionado y muestra los campos correspondientes:
/// - Estudiante: InputName activo
/// - Profesor: InputEmail activo
/// </summary>
public class LoginStudentView : MonoBehaviour
{
    public TMP_InputField InputName;
    public TMP_InputField InputEmail;
    public TMP_InputField InputPassword;
    public Button LoginButton;
    public Toggle RememberSessionToggle;
    public TMP_Text MessageTextWelcome;
    public Text NameErrorText;
    public Text PasswordErrorText;
    public Text MessageErrorLoginText;
    
    private LoginPresenter loginPresenter;
    private ISessionPersistence sessionPersistence;
    private bool initialized = false;
    private int selectedRole = 1; // 1 = Estudiante, 2 = Profesor

    /// <summary>
    /// Ejecuta el proceso de autenticacion segun el rol seleccionado.
    /// Para estudiante: usa InputName y InputPassword.
    /// Para profesor: usa InputEmail y InputPassword.
    /// Si "Recordar sesión" está activado, guarda la sesión para auto-login futuro.
    /// </summary>
    public void Login()
    {
        if (!initialized)
        {
            Debug.LogWarning("Login attempted before DB ready.");
            return;
        }

        ClearFieldErrors();

        LoginPresenter.LoginResult response;

        if (selectedRole == 2) // Profesor
        {
            // Validar campos de profesor
            if (InputEmail == null || string.IsNullOrEmpty(InputEmail.text))
            {
                Debug.LogWarning("InputEmail no está configurado para login de profesor");
                return;
            }

            response = loginPresenter.LoginTeacher(InputEmail.text, InputPassword.text);
            
            if (!string.IsNullOrEmpty(response.NameError))
                ShowFieldError(NameErrorText, response.NameError);
        }
        else // Estudiante
        {
            // Validar campos de estudiante
            if (InputName == null || string.IsNullOrEmpty(InputName.text))
            {
                Debug.LogWarning("InputName no está configurado para login de estudiante");
                return;
            }

            response = loginPresenter.LoginStudent(InputName.text, InputPassword.text);
            
            if (!string.IsNullOrEmpty(response.NameError))
                ShowFieldError(NameErrorText, response.NameError);
        }

        if (!string.IsNullOrEmpty(response.PasswordError))
            ShowFieldError(PasswordErrorText, response.PasswordError);

        if (response.IsSuccess)
        {
            Debug.Log("Login Correcto");
            
            // Guardar usuario en sesión
            if (UserSessionManager.Instance != null)
            {
                UserSessionManager.Instance.SetCurrentUser(response.User);
            }

            // Actualizar última fecha de login
            if (loginPresenter != null && response.User != null)
            {
                loginPresenter.UpdateLastLogin(response.User.id_user);
            }

            // Guardar sesión SI Y SOLO SI el toggle "Recordar sesión" está ACTIVADO
            if (RememberSessionToggle == null)
            {
                Debug.LogWarning("LoginView: RememberSessionToggle NO está asignado en Inspector");
            }
            else
            {
                Debug.Log($"LoginView: RememberSessionToggle estado = {RememberSessionToggle.isOn}");
                
                if (RememberSessionToggle.isOn)
                {
                    Debug.Log("✓ Toggle ACTIVADO -> Guardando sesión");
                    SaveSession(response.User);
                }
                else
                {
                    Debug.Log("✗ Toggle DESACTIVADO -> NO se guarda sesión");
                }
            }
            
            // Cargar escena TestInitialuserFlow
            SceneManager.LoadScene("TestInitialuserFlow");
        }
        else if (!string.IsNullOrEmpty(response.GeneralMessage))
        {
            Debug.Log("Login failed: " + response.GeneralMessage);
            ShowFieldError(MessageErrorLoginText, response.GeneralMessage);
        }
    }

    /// <summary>
    /// Registra listeners y espera a que la base quede lista para construir el presenter.
    /// Detecta el rol seleccionado y configura la UI correspondiente.
    /// </summary>
    void Start()
    {
        // Recuperar rol seleccionado (1 = Estudiante, 2 = Profesor)
        selectedRole = RolePreferences.GetSelectedRole();
        
        // Configurar UI según el rol
        ConfigureUIByRole();

        // Esperar hasta que DatabaseManager esté listo antes de crear repositorios/servicios.
        StartCoroutine(InitializeWhenDatabaseReady());

        if (LoginButton != null)
            LoginButton.onClick.AddListener(Login);

        // Inicializar persistencia de sesión
        sessionPersistence = new SessionPersistence();

        // Mostrar mensaje de bienvenida según el rol
        string message = PlayerPrefs.GetString("LoginMessage", "");
        if (string.IsNullOrEmpty(message))
        {
            message = selectedRole == 2 ? "Bienvenido Profesor/a" : "Bienvenido Estudiante";
        }

        if (!string.IsNullOrEmpty(message) && MessageTextWelcome != null)
        {
            MessageTextWelcome.text = message;
            MessageTextWelcome.gameObject.SetActive(true);
        }
    }

    /// <summary>
    /// Configura la UI (campos visibles) según el rol seleccionado.
    /// </summary>
    private void ConfigureUIByRole()
    {
        if (selectedRole == 2) // Profesor
        {
            if (InputName != null)
                InputName.gameObject.SetActive(false);
            if (InputEmail != null)
                InputEmail.gameObject.SetActive(true);
            if (NameErrorText != null)
                NameErrorText.gameObject.SetActive(false);
            
            Debug.Log("[LoginView] Configurado para LOGIN PROFESOR");
        }
        else // Estudiante (rol 1)
        {
            if (InputName != null)
                InputName.gameObject.SetActive(true);
            if (InputEmail != null)
                InputEmail.gameObject.SetActive(false);
            if (NameErrorText != null)
                NameErrorText.gameObject.SetActive(false);
            
            Debug.Log("[LoginView] Configurado para LOGIN ESTUDIANTE");
        }
    }

    /// <summary>
    /// Construye dependencias del flujo de login cuando SQLite ya esta disponible.
    /// </summary>
    System.Collections.IEnumerator InitializeWhenDatabaseReady()
    {
        // Esperar a que exista la instancia
        yield return new WaitUntil(() => DatabaseManager.Instance != null);

        // Esperar a que la DB esté lista
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        var conn = DatabaseManager.Instance.GetConnection();
        var repo = new UserRepository(conn);
        var auth = new AuthService(repo);
        loginPresenter = new LoginPresenter(auth);

        initialized = true;
    }

    /// <summary>
    /// Guarda la sesión localmente para permitir auto-login futuro.
    /// Solo se ejecuta si el usuario selecciona "Recordar sesión".
    /// Guarda el rol correcto segun el usuario autenticado (Estudiante o Profesor).
    /// </summary>
    private void SaveSession(UserModel user)
    {
        if (sessionPersistence == null)
        {
            Debug.LogWarning("LoginView: SessionPersistence no está inicializado.");
            return;
        }

        string roleType = selectedRole == 2 ? "Teacher" : "Student";
        SessionData sessionData = new SessionData(user.id_user, roleType);
        sessionPersistence.SaveSession(sessionData);
        Debug.Log($"✓ LoginView: Sesión guardada para auto-login (Usuario ID: {user.id_user}, Nombre: {user.name}, Rol: {roleType})");
    }

    void OnDisable()
    {
        if (LoginButton != null)
            LoginButton.onClick.RemoveListener(Login);

    }

    void ShowFieldError(Text field, string msg)
    {
        if (field == null) return;
        field.text = msg;
        field.gameObject.SetActive(true);
        StartCoroutine(HideFieldErrorAfter(field, 5f));
    }

    /// <summary>
    /// Oculta el error de un campo despues de unos segundos.
    /// </summary>
    System.Collections.IEnumerator HideFieldErrorAfter(Text field, float seconds)
    {
        yield return new WaitForSeconds(seconds);
        if (field != null)
            field.gameObject.SetActive(false);
    }

    /// <summary>
    /// Limpia todos los mensajes visibles de error o confirmacion.
    /// </summary>
    void ClearFieldErrors()
    {
        if (NameErrorText != null)
            NameErrorText.gameObject.SetActive(false);
        if (PasswordErrorText != null)
            PasswordErrorText.gameObject.SetActive(false);
        if (MessageErrorLoginText != null)
            MessageErrorLoginText.gameObject.SetActive(false);
    }
}
