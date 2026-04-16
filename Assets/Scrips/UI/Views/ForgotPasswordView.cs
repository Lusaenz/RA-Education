using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;
using TMPro;
using System.Collections;

/// <summary>
/// Vista para la funcionalidad de recuperación de contraseña.
/// Maneja la UI y orquesta la interacción con el presenter.
/// Sigue arquitectura MVP.
/// </summary>
public class ForgotPasswordView : MonoBehaviour
{
    // ==================== UI Elements ====================
    [SerializeField] private TMP_InputField InputName;
    [SerializeField] private Text TextErrorName;

    [SerializeField] private Text TextSecurityQuestion;
    [SerializeField] private TMP_InputField InputSecurityAnswer;
    [SerializeField] private Text TextErrorAnswer;

    [SerializeField] private TMP_InputField InputNewPassword;
    [SerializeField] private Text TextErrorPassword;

    [SerializeField] private Button ButtonConfirm;

    // ==================== State ====================
    private ForgotPasswordPresenter presenter;
    private UserModel currentUser;
    private bool initialized = false;
    private Coroutine clearErrorCoroutine;

    // ==================== Lifecycle ====================

    void Start()
    {
        StartCoroutine(InitializeWhenDatabaseReady());

        // El botón de Confirmar solo debe presionarse DESPUÉS de haber ingresado el nombre
        if (ButtonConfirm != null)
        {
            ButtonConfirm.onClick.AddListener(ConfirmPasswordReset);
            ButtonConfirm.interactable = false; // Deshabilitado al inicio
        }

        // Permitir buscar usuario presionando Enter en el campo de nombre
        if (InputName != null)
        {
            InputName.onSubmit.AddListener((_) => OnNameEntered());
        }
    }

    System.Collections.IEnumerator InitializeWhenDatabaseReady()
    {
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        var conn = DatabaseManager.Instance.GetConnection();
        var userRepo = new UserRepository(conn);
        var auth = new AuthService(userRepo);

        // Obtener SecurityQuestionsService (necesita también una conexión)
        var sqRepo = new SecurityQuestionsRepository(conn);
        var securityQuestionsService = new SecurityQuestionsService(sqRepo);

        presenter = new ForgotPasswordPresenter(auth, securityQuestionsService);
        initialized = true;

        Debug.Log("[ForgotPasswordView] Inicialización completada");
    }

    void OnDisable()
    {
        if (ButtonConfirm != null)
            ButtonConfirm.onClick.RemoveListener(ConfirmPasswordReset);
        if (InputName != null)
            InputName.onSubmit.RemoveListener((_) => OnNameEntered());
    }

    // ==================== Event Handlers ====================

    /// <summary>
    /// Se ejecuta cuando se completa la entrada del nombre (Enter o Submit).
    /// </summary>
    private void OnNameEntered()
    {
        if (!initialized)
        {
            Debug.LogWarning("[ForgotPasswordView] La vista aún no está inicializada.");
            return;
        }

        string name = InputName?.text ?? string.Empty;

        if (string.IsNullOrWhiteSpace(name))
        {
            ShowError(TextErrorName, "Por favor ingresa tu nombre.");
            return;
        }

        ClearAllErrors();

        // Buscar el usuario
        var lookupResult = presenter.FindStudentByName(name);

        if (!lookupResult.Success)
        {
            ShowError(TextErrorName, lookupResult.ErrorMessage);
            if (ButtonConfirm != null)
                ButtonConfirm.interactable = false;
            return;
        }

        // Usuario encontrado exitosamente
        currentUser = lookupResult.User;
        Debug.Log($"[ForgotPasswordView] Usuario encontrado: {currentUser.name} (ID: {currentUser.id_user}, Rol: {currentUser.id_role})");

        // Mostrar pregunta de seguridad
        DisplaySecurityQuestion(currentUser.id_security_question);

        // Habilitar entrada de respuesta
        EnableSecurityAnswerInput();
        
        // Habilitar botón de confirmación ahora que hay usuario identificado
        if (ButtonConfirm != null)
            ButtonConfirm.interactable = true;
    }

    /// <summary>
    /// Se ejecuta al presionar el botón Confirmar (OnClick del Inspector).
    /// PÚBLICO: Llamable sin parámetros desde OnClick.
    /// </summary>
    public void ConfirmPasswordReset()
    {
        if (!initialized)
        {
            Debug.LogWarning("[ForgotPasswordView] La vista aún no está inicializada.");
            return;
        }

        // Validar que haya usuario identificado
        if (currentUser == null)
        {
            ShowError(TextErrorName, "Por favor completa el formulario desde el principio.");
            Debug.LogWarning("[ForgotPasswordView] Intento de confirmar sin usuario identificado");
            return;
        }

        ProcessPasswordReset();
    }

    // ==================== Business Logic ====================

    /// <summary>
    /// Muestra la pregunta de seguridad del usuario.
    /// </summary>
    private void DisplaySecurityQuestion(int questionId)
    {
        var questionInfo = presenter.GetSecurityQuestion(questionId);

        if (questionInfo == null)
        {
            ShowError(TextErrorName, "No se pudo cargar la pregunta de seguridad. Intenta más tarde.");
            return;
        }

        if (TextSecurityQuestion != null)
        {
            TextSecurityQuestion.text = $"{questionInfo.Question}";
            TextSecurityQuestion.gameObject.SetActive(true);
        }

        Debug.Log($"[ForgotPasswordView] Pregunta mostrada: {questionInfo.Question}");
    }

    /// <summary>
    /// Habilita los campos de respuesta y nueva contraseña.
    /// </summary>
    private void EnableSecurityAnswerInput()
    {
        if (InputSecurityAnswer != null)
        {
            InputSecurityAnswer.interactable = true;
            InputSecurityAnswer.Select();
        }

        if (InputNewPassword != null)
        {
            InputNewPassword.interactable = true;
        }
    }

    /// <summary>
    /// Procesa el cambio de contraseña internamente.
    /// </summary>
    private void ProcessPasswordReset()
    {
        ClearAllErrors();

        string securityAnswer = InputSecurityAnswer?.text ?? string.Empty;
        string newPassword = InputNewPassword?.text ?? string.Empty;

        // Validar y procesar
        var resetResult = presenter.ResetPassword(currentUser.id_user, securityAnswer, newPassword);

        if (!resetResult.Success)
        {
            // Mostrar errores de validación
            if (resetResult.FieldErrors.ContainsKey("answer"))
            {
                ShowError(TextErrorAnswer, resetResult.FieldErrors["answer"]);
            }

            if (resetResult.FieldErrors.ContainsKey("password"))
            {
                ShowError(TextErrorPassword, resetResult.FieldErrors["password"]);
            }

            if (!string.IsNullOrEmpty(resetResult.ErrorMessage))
            {
                ShowError(TextErrorPassword, resetResult.ErrorMessage);
            }

            Debug.Log("[ForgotPasswordView] Cambio de contraseña fallido");
            return;
        }

        // Éxito - mostrar mensaje y redirigir al login correspondiente según rol
        Debug.Log($"[ForgotPasswordView] Contraseña cambiada exitosamente. Usuario: {currentUser.name}, Rol ID: {currentUser.id_role}");
        PlayerPrefs.SetString("LoginMessage", "✓ Tu contraseña ha sido cambiada correctamente. Por favor inicia sesión.");
        
        // Cargar login según el rol del usuario recuperado
        SceneLoader sceneLoader = FindFirstObjectByType<SceneLoader>();
        if (sceneLoader != null)
        {
            sceneLoader.LoadLoginByRole(currentUser.id_role);
        }
        else
        {
            Debug.LogError("[ForgotPasswordView] SceneLoader no encontrado en la escena");
        }
    }

    // ==================== UI Helpers ====================

    /// <summary>
    /// Muestra un mensaje de error en un elemento Text específico.
    /// </summary>
    private void ShowError(Text errorText, string message)
    {
        if (errorText == null)
            return;

        errorText.text = message;
        errorText.gameObject.SetActive(true);

        if (clearErrorCoroutine != null)
            StopCoroutine(clearErrorCoroutine);

        clearErrorCoroutine = StartCoroutine(ClearErrorAfterSeconds(errorText, 6f));
    }

    /// <summary>
    /// Limpia un error de pantalla después de algunos segundos.
    /// </summary>
    private IEnumerator ClearErrorAfterSeconds(Text errorText, float seconds)
    {
        yield return new WaitForSeconds(seconds);

        if (errorText != null)
        {
            errorText.text = string.Empty;
            errorText.gameObject.SetActive(false);
        }
    }

    /// <summary>
    /// Limpia todos los errores visibles.
    /// </summary>
    private void ClearAllErrors()
    {
        if (TextErrorName != null)
        {
            TextErrorName.text = string.Empty;
            TextErrorName.gameObject.SetActive(false);
        }

        if (TextErrorAnswer != null)
        {
            TextErrorAnswer.text = string.Empty;
            TextErrorAnswer.gameObject.SetActive(false);
        }

        if (TextErrorPassword != null)
        {
            TextErrorPassword.text = string.Empty;
            TextErrorPassword.gameObject.SetActive(false);
        }
    }
}
