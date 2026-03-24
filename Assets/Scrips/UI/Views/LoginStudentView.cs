using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.SceneManagement;

/// <summary>
/// Vista de login para estudiantes.
/// Captura entradas, delega la autenticacion al presenter y representa mensajes de error.
/// </summary>
public class LoginStudentView : MonoBehaviour
{
    public TMP_InputField InputName;
    public TMP_InputField InputPassword;
    public Button LoginButton;
    public Button RegisterButton;
    public Text MessageText; // Campo para mostrar mensajes como "Registro exitoso"
    public Text NameErrorText; // Campo para mostrar error específico del nombre
    public Text PasswordErrorText; // Campo para mostrar error específico de la contraseña
    public Text MessageErrorLoginText;
    private LoginPresenter loginPresenter;
    private bool initialized = false;

    /// <summary>
    /// Ejecuta el proceso de autenticacion del estudiante desde la UI.
    /// </summary>
    public void Login()
    {
        if (!initialized)
        {
            Debug.LogWarning("Login attempted before DB ready.");
            return;
        }

        ClearFieldErrors();

        // solicitar al presenter que procese las credenciales y devuelva resultados
        var response = loginPresenter.LoginStudent(InputName.text, InputPassword.text);

        if (!string.IsNullOrEmpty(response.NameError))
            ShowFieldError(NameErrorText, response.NameError);
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
            
            if (MessageText != null)
            {
                MessageText.gameObject.SetActive(true);
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
    /// Navega a la pantalla de registro de estudiantes.
    /// </summary>
    public void GoToRegister()
    {
        SceneManager.LoadScene("RegisterStuden");
    }

    /// <summary>
    /// Registra listeners y espera a que la base quede lista para construir el presenter.
    /// </summary>
    void Start()
    {
        // Esperar hasta que DatabaseManager esté listo antes de crear repositorios/servicios.
        StartCoroutine(InitializeWhenDatabaseReady());

        if (LoginButton != null)
            LoginButton.onClick.AddListener(Login);
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

    void OnDisable()
    {
        if (LoginButton != null)
            LoginButton.onClick.RemoveListener(Login);

        if (RegisterButton != null)
            RegisterButton.onClick.RemoveListener(GoToRegister);

        // solo limpiar el listener del botón de login
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
    /// Muestra un error temporal asociado a un campo.
    /// </summary>
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
        if (MessageText != null)
            MessageText.gameObject.SetActive(false);
        if (MessageErrorLoginText != null)
            MessageErrorLoginText.gameObject.SetActive(false);
    }

}
