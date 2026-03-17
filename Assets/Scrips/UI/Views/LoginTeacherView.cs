using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// Vista de login para profesores.
/// Orquesta los controles visuales y delega la autenticacion al presenter.
/// </summary>
public class LoginTeacherView : MonoBehaviour
{
    public TMP_InputField emailInput;
    public TMP_InputField passInput;
    public Button loginButton;
    public Button RegisterButton;
    public Text MessageText; // Campo para mostrar mensajes como "Registro exitoso"
    public Text EmailErrorText; // Campo para error del email
    public Text PasswordErrorText; // Campo para error de la contraseña
    public Text MessageErrorLoginText;

    private LoginPresenter presenter;
    private bool initialized = false;

    /// <summary>
    /// Registra listeners y espera el acceso a base de datos antes de habilitar login.
    /// </summary>
    void Start()
    {
        StartCoroutine(InitializeWhenDatabaseReady());
        if (loginButton != null)
            loginButton.onClick.AddListener(Login);
        if (RegisterButton != null)
            RegisterButton.onClick.AddListener(GoToRegister);

        // Mostrar mensaje si existe (ej. después de registro exitoso)
        string message = PlayerPrefs.GetString("LoginMessage", "");
        if (!string.IsNullOrEmpty(message) && MessageText != null)
        {
            MessageText.text = message;
            MessageText.gameObject.SetActive(true);
            PlayerPrefs.DeleteKey("LoginMessage");
        }
    }

    /// <summary>
    /// Construye dependencias cuando DatabaseManager queda listo.
    /// </summary>
    System.Collections.IEnumerator InitializeWhenDatabaseReady()
    {
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        var conn = DatabaseManager.Instance.GetConnection();
        var repo = new UserRepository(conn);
        var auth = new AuthService(repo);
        presenter = new LoginPresenter(auth);

        initialized = true;
    }

    /// <summary>
    /// Navega a la pantalla de registro de profesores.
    /// </summary>
    public void GoToRegister()
    {
        SceneManager.LoadScene("RegisterTeacher");
    }

    /// <summary>
    /// Ejecuta el login del profesor y refleja el resultado en pantalla.
    /// </summary>
    public void Login()
    {
        if (!initialized)
        {
            Debug.LogWarning("Login attempted before DB ready.");
            return;
        }

        ClearFieldErrors();

        var response = presenter.LoginTeacher(emailInput.text, passInput.text);

        if (!string.IsNullOrEmpty(response.NameError))
            ShowFieldError(EmailErrorText, response.NameError);
        if (!string.IsNullOrEmpty(response.PasswordError))
            ShowFieldError(PasswordErrorText, response.PasswordError);

        if (response.IsSuccess)
        {
            Debug.Log("Login correcto");
            
            // Guardar usuario en sesión
            if (UserSessionManager.Instance != null)
            {
                UserSessionManager.Instance.SetCurrentUser(response.User);
            }
            
            if (MessageText != null)
            {
                MessageText.text = "Login correcto";
                MessageText.gameObject.SetActive(true);
            }
            
            // Cargar escena TestInitialuserFlow
            SceneManager.LoadScene("TestInitialuserFlow");
        }
        else if (!string.IsNullOrEmpty(response.GeneralMessage))
        {
            Debug.Log("Login incorrecto: " + response.GeneralMessage);
            ShowFieldError(MessageErrorLoginText, response.GeneralMessage);
        }
    }

    /// <summary>
    /// Muestra un mensaje general temporal.
    /// </summary>
    void ShowMessage(string msg)
    {
        if (MessageText == null) return;
        MessageText.text = msg;
        MessageText.gameObject.SetActive(true);
        StartCoroutine(HideMessageAfter(5f));
    }

    /// <summary>
    /// Oculta el mensaje general despues de un tiempo.
    /// </summary>
    System.Collections.IEnumerator HideMessageAfter(float seconds)
    {
        yield return new WaitForSeconds(seconds);
        if (MessageText != null)
            MessageText.gameObject.SetActive(false);
    }

    /// <summary>
    /// Muestra un error temporal asociado a un campo concreto.
    /// </summary>
    void ShowFieldError(Text field, string msg)
    {
        if (field == null) return;
        field.text = msg;
        field.gameObject.SetActive(true);
        StartCoroutine(HideFieldErrorAfter(field, 5f));
    }

    /// <summary>
    /// Oculta un error de campo tras un retraso.
    /// </summary>
    System.Collections.IEnumerator HideFieldErrorAfter(Text field, float seconds)
    {
        yield return new WaitForSeconds(seconds);
        if (field != null)
            field.gameObject.SetActive(false);
    }

    /// <summary>
    /// Limpia todos los mensajes de la pantalla.
    /// </summary>
    void ClearFieldErrors()
    {
        if (EmailErrorText != null)
            EmailErrorText.gameObject.SetActive(false);
        if (PasswordErrorText != null)
            PasswordErrorText.gameObject.SetActive(false);
        if (MessageText != null)
            MessageText.gameObject.SetActive(false);
        if (MessageErrorLoginText != null)
            MessageErrorLoginText.gameObject.SetActive(false);
    }
}
