
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using System.Collections;
using System.Collections.Generic;
using System.Linq;

/// <summary>
/// Vista de registro unificada para estudiantes y profesores.
/// Recoge los datos del formulario, delega validaciones al presenter segun el rol y representa errores.
/// Detecta el rol seleccionado y muestra los campos correspondientes:
/// - Estudiante: InputAge activo
/// - Profesor: InputEmail activo
/// </summary>
public class RegisterStudentView : MonoBehaviour
{
    public TMP_InputField InputName;
    public TMP_InputField InputDegree;
    public TMP_InputField InputAge;
    public TMP_InputField InputEmail;
    public TMP_InputField InputPassword;
    public Button RegisterButton;
    public Button LoginButton;
    public Text ErrorTextName;
    public Text ErrorTextDegree;
    public Text ErrorTextAge;
    public Text ErrorTextEmail;
    public Text ErrorTextPassword;
    public Text ErrorTextSecurityQuestion;
    public Text RegisterConfirmationText;

    [Header("Mobile Keyboard")]
    [SerializeField] RectTransform keyboardShiftRoot;
    [SerializeField] ScrollRect formScrollRect;
    [SerializeField] float keyboardPadding = 80f;
    [SerializeField] float keyboardMoveSpeed = 12f;
    [SerializeField] float keyboardFallbackHeightRatio = 0.38f;
    [SerializeField] float maxKeyboardShift = 500f;

    RegisterPresenter presenter;
    DegreeSelector degreeSelector;
    bool isRegistering = false;
    Coroutine clearErrorCoroutine;
    RectTransform cachedShiftRect;
    Canvas rootCanvas;
    Vector2 initialShiftPosition;
    float currentKeyboardShift = 0f;
    readonly List<TMP_InputField> trackedInputs = new List<TMP_InputField>();
    private int selectedRole = 1; // 1 = Estudiante, 2 = Profesor

    /// <summary>
    /// Resuelve dependencias de escena, detecta el rol y enlaza eventos de botones.
    /// </summary>
    void Start()
    {
        // Recuperar rol seleccionado (1 = Estudiante, 2 = Profesor)
        selectedRole = RolePreferences.GetSelectedRole();
        
        // Configurar UI según el rol
        ConfigureUIByRole();

        // Buscar un RegisterPresenter existente en la escena
        presenter = FindFirstObjectByType<RegisterPresenter>();
        if (presenter == null)
        {
            // Si no existe, crear uno para asegurar que la lógica del presenter esté disponible
            var go = new GameObject("RegisterPresenter");
            presenter = go.AddComponent<RegisterPresenter>();
        }

        degreeSelector = FindFirstObjectByType<DegreeSelector>();
        if (degreeSelector == null)
        {
            Debug.LogWarning("RegisterView: DegreeSelector no encontrado en la escena.");
        }

        if (RegisterButton != null)
        {
            RegisterButton.onClick.RemoveAllListeners();
            RegisterButton.onClick.AddListener(Register);
        }

        if (RegisterConfirmationText != null)
        {
            RegisterConfirmationText.gameObject.SetActive(false);
            RegisterConfirmationText.text = string.Empty;
        }

        // Conectar el DegreeSelector al input field de grado
        if (degreeSelector != null && InputDegree != null)
        {
            degreeSelector.degreeInputField = InputDegree;
        }

        CacheKeyboardSupportReferences();
    }

    /// <summary>
    /// Configura la UI (campos visibles) según el rol seleccionado.
    /// </summary>
    private void ConfigureUIByRole()
    {
        if (selectedRole == 2) // Profesor
        {
            if (InputAge != null)
                InputAge.gameObject.SetActive(false);
            if (InputEmail != null)
                InputEmail.gameObject.SetActive(true);
            if (ErrorTextAge != null)
                ErrorTextAge.gameObject.SetActive(false);
            
            Debug.Log("[RegisterView] Configurado para REGISTRO PROFESOR");
        }
        else // Estudiante (rol 1)
        {
            if (InputAge != null)
                InputAge.gameObject.SetActive(true);
            if (InputEmail != null)
                InputEmail.gameObject.SetActive(false);
            if (ErrorTextEmail != null)
                ErrorTextEmail.gameObject.SetActive(false);
            
            Debug.Log("[RegisterView] Configurado para REGISTRO ESTUDIANTE");
        }
    }

    void LateUpdate()
    {
        UpdateMobileKeyboardOffset();
    }

    void OnDisable()
    {
        RestoreKeyboardPositionImmediately();
    }

    /// <summary>
    /// Ejecuta el registro segun el rol seleccionado (estudiante o profesor).
    /// Usa los valores actuales del formulario y valida según el rol.
    /// </summary>
    public void Register()
    {
        if (isRegistering)
        {
            return;
        }

        if (presenter == null)
        {
            Debug.LogError("Presenter no disponible para registro.");
            ShowError("Error interno: presenter no disponible.");
            return;
        }

        // Limpiar errores previos
        ClearAllErrors();

        // Obtener valores comunes de los campos
        var name = InputName != null ? InputName.text : string.Empty;
        var pass = InputPassword != null ? InputPassword.text : string.Empty;
        var degreeId = degreeSelector != null ? degreeSelector.GetSelectedDegreeId() : 0;

        // Validar pregunta de seguridad ANTES de registrar
        if (degreeSelector == null)
        {
            ShowFieldError(ErrorTextSecurityQuestion, "No se encontró el selector de pregunta de seguridad.");
            return;
        }

        int questionId = degreeSelector.GetSelectedSecurityQuestionId();
        string answer = degreeSelector.GetSecurityAnswer();
        var securityErrors = RegisterValidator.ValidateSecurityQuestion(questionId, answer);
        if (securityErrors.Count > 0)
        {
            DisplayErrorsByField(securityErrors);
            return;
        }

        // Llamar al presenter segun el rol
        RegisterResult result;

        if (selectedRole == 2) // Profesor
        {
            var email = InputEmail != null ? InputEmail.text : string.Empty;
            result = presenter.RegisterTeacher(degreeId, name, email, pass);
        }
        else // Estudiante
        {
            var ageText = InputAge != null ? InputAge.text : string.Empty;
            result = presenter.RegisterStudent(degreeId, name, ageText, pass);
        }

        if (result.Success)
        {
            int userId = result.UserId;

            // Guardar la pregunta de seguridad y su respuesta
            var securityResult = presenter.ValidateAndSaveSecurityQuestion(userId, questionId, answer);
            if (!securityResult.Success)
            {
                Debug.LogWarning($"No se pudo guardar la pregunta de seguridad: {securityResult.ErrorMessage}");
                DisplayErrorsByField(securityResult.FieldErrors);
                return;
            }

            // Mostrar mensaje de éxito
            ShowRegistrationSuccess();
        }
        else
        {
            // Mostrar errores de cada campo desde el resultado del presenter
            DisplayErrorsByField(result.FieldErrors);
        }
    }

    /// <summary>
    /// Distribuye errores por campo segun el resultado del presenter.
    /// </summary>
    void DisplayErrorsByField(Dictionary<string, string> fieldErrors)
    {
        ClearAllErrors();

        if (fieldErrors.ContainsKey("name"))
        {
            ShowFieldError(ErrorTextName, fieldErrors["name"]);
        }

        if (fieldErrors.ContainsKey("degree"))
        {
            ShowFieldError(ErrorTextDegree, fieldErrors["degree"]);
        }

        if (fieldErrors.ContainsKey("age"))
        {
            ShowFieldError(ErrorTextAge, fieldErrors["age"]);
        }

        if (fieldErrors.ContainsKey("email"))
        {
            ShowFieldError(ErrorTextEmail, fieldErrors["email"]);
        }

        if (fieldErrors.ContainsKey("password"))
        {
            ShowFieldError(ErrorTextPassword, fieldErrors["password"]);
        }

        if (fieldErrors.ContainsKey("answer"))
        {
            ShowFieldError(ErrorTextSecurityQuestion, fieldErrors["answer"]);
        }

        if (clearErrorCoroutine != null)
            StopCoroutine(clearErrorCoroutine);

        clearErrorCoroutine = StartCoroutine(ClearErrorAfterSeconds(5f));
    }

    /// <summary>
    /// Muestra un mensaje de error en el control asociado.
    /// </summary>
    void ShowFieldError(Text errorText, string message)
    {
        if (errorText == null)
            return;

        errorText.text = message;
        errorText.gameObject.SetActive(true);
    }

    /// <summary>
    /// Limpia el contenido y visibilidad de un error concreto.
    /// </summary>
    void ClearFieldError(Text errorText)
    {
        if (errorText == null)
            return;

        errorText.text = string.Empty;
        errorText.gameObject.SetActive(false);
    }

    /// <summary>
    /// Limpia todos los errores visibles del formulario.
    /// </summary>
    void ClearAllErrors()
    {
        ClearFieldError(ErrorTextName);
        ClearFieldError(ErrorTextDegree);
        ClearFieldError(ErrorTextAge);
        ClearFieldError(ErrorTextEmail);
        ClearFieldError(ErrorTextPassword);
        ClearFieldError(ErrorTextSecurityQuestion);
    }

    /// <summary>
    /// Registra un error generico en consola.
    /// </summary>
    void ShowError(string message, float seconds = 3f)
    {
        // Mostrar error genérico en consola
        Debug.LogWarning(message);
    }

    /// <summary>
    /// Elimina los mensajes de error despues de unos segundos.
    /// </summary>
    IEnumerator ClearErrorAfterSeconds(float seconds)
    {
        yield return new WaitForSeconds(seconds);
        ClearAllErrors();
        clearErrorCoroutine = null;
    }

    void CacheKeyboardSupportReferences()
    {
        trackedInputs.Clear();
        RegisterTrackedInput(InputName);
        RegisterTrackedInput(InputDegree);
        RegisterTrackedInput(InputAge);
        RegisterTrackedInput(InputEmail);
        RegisterTrackedInput(InputPassword);

        if (degreeSelector != null)
        {
            RegisterTrackedInput(degreeSelector.questionInputField);
            RegisterTrackedInput(degreeSelector.answerInputField);
        }

        if (formScrollRect == null)
        {
            formScrollRect = FindFirstObjectByType<ScrollRect>();
        }

        rootCanvas = ResolveRootCanvas();

        if (keyboardShiftRoot == null && formScrollRect != null && formScrollRect.content != null)
        {
            keyboardShiftRoot = formScrollRect.content;
        }

        if (keyboardShiftRoot == null)
        {
            keyboardShiftRoot = FindBestKeyboardShiftRoot();
        }

        cachedShiftRect = keyboardShiftRoot;

        if (cachedShiftRect != null)
        {
            initialShiftPosition = cachedShiftRect.anchoredPosition;
        }
    }

    void UpdateMobileKeyboardOffset()
    {
        if (!Application.isMobilePlatform || cachedShiftRect == null)
        {
            return;
        }

        TMP_InputField selectedInput = GetSelectedInputField();
        if (selectedInput == null || !selectedInput.isFocused)
        {
            MoveKeyboardShiftTowards(0f);
            return;
        }

        float keyboardHeight = GetKeyboardHeight();
        if (keyboardHeight <= 0f)
        {
            MoveKeyboardShiftTowards(0f);
            return;
        }

        float overlap = CalculateInputOverlapWithKeyboard(selectedInput, keyboardHeight);
        float targetShift = Mathf.Clamp(overlap, 0f, maxKeyboardShift);
        MoveKeyboardShiftTowards(targetShift);
    }

    TMP_InputField GetSelectedInputField()
    {
        if (EventSystem.current == null)
        {
            return null;
        }

        GameObject selectedObject = EventSystem.current.currentSelectedGameObject;
        if (selectedObject == null)
        {
            return null;
        }

        TMP_InputField selectedInput = selectedObject.GetComponent<TMP_InputField>();
        if (selectedInput == null)
        {
            return null;
        }

        return trackedInputs.Contains(selectedInput) ? selectedInput : null;
    }

    float GetKeyboardHeight()
    {
        Rect keyboardArea = TouchScreenKeyboard.area;
        if (keyboardArea.height > 0f)
        {
            return keyboardArea.height;
        }

        if (TouchScreenKeyboard.visible)
        {
            return Screen.height * keyboardFallbackHeightRatio;
        }

        return 0f;
    }

    float CalculateInputOverlapWithKeyboard(TMP_InputField inputField, float keyboardHeight)
    {
        RectTransform inputRect = inputField.transform as RectTransform;
        if (inputRect == null)
        {
            return 0f;
        }

        Vector3[] corners = new Vector3[4];
        inputRect.GetWorldCorners(corners);

        Camera uiCamera = null;
        if (rootCanvas != null && rootCanvas.renderMode != RenderMode.ScreenSpaceOverlay)
        {
            uiCamera = rootCanvas.worldCamera;
        }

        float inputBottomY = RectTransformUtility.WorldToScreenPoint(uiCamera, corners[0]).y;
        float keyboardTopY = keyboardHeight + keyboardPadding;
        return keyboardTopY - inputBottomY;
    }

    void MoveKeyboardShiftTowards(float targetShift)
    {
        currentKeyboardShift = Mathf.Lerp(currentKeyboardShift, targetShift, Time.unscaledDeltaTime * keyboardMoveSpeed);

        if (Mathf.Abs(currentKeyboardShift - targetShift) < 0.5f)
        {
            currentKeyboardShift = targetShift;
        }

        cachedShiftRect.anchoredPosition = initialShiftPosition + new Vector2(0f, currentKeyboardShift);
    }

    void RestoreKeyboardPositionImmediately()
    {
        currentKeyboardShift = 0f;

        if (cachedShiftRect != null)
        {
            cachedShiftRect.anchoredPosition = initialShiftPosition;
        }
    }

    void RegisterTrackedInput(TMP_InputField inputField)
    {
        if (inputField != null && !trackedInputs.Contains(inputField))
        {
            trackedInputs.Add(inputField);
        }
    }

    RectTransform FindBestKeyboardShiftRoot()
    {
        List<RectTransform> inputRects = trackedInputs
            .Where(input => input != null)
            .Select(input => input.transform as RectTransform)
            .Where(rect => rect != null)
            .ToList();

        if (inputRects.Count == 0)
        {
            return rootCanvas != null ? rootCanvas.transform as RectTransform : null;
        }

        Transform commonAncestor = inputRects[0];
        for (int i = 1; i < inputRects.Count; i++)
        {
            commonAncestor = FindCommonAncestor(commonAncestor, inputRects[i]);
            if (commonAncestor == null)
            {
                break;
            }
        }

        RectTransform candidate = commonAncestor as RectTransform;
        RectTransform canvasRect = rootCanvas != null ? rootCanvas.transform as RectTransform : null;

        if (candidate == canvasRect)
        {
            candidate = inputRects[0].parent as RectTransform;
        }

        if (candidate != null)
        {
            return candidate;
        }

        return inputRects[0].parent as RectTransform;
    }

    Transform FindCommonAncestor(Transform a, Transform b)
    {
        if (a == null || b == null)
        {
            return null;
        }

        HashSet<Transform> ancestors = new HashSet<Transform>();
        Transform current = a;
        while (current != null)
        {
            ancestors.Add(current);
            current = current.parent;
        }

        current = b;
        while (current != null)
        {
            if (ancestors.Contains(current))
            {
                return current;
            }

            current = current.parent;
        }

        return null;
    }

    Canvas ResolveRootCanvas()
    {
        foreach (TMP_InputField inputField in trackedInputs)
        {
            if (inputField == null)
            {
                continue;
            }

            Canvas canvas = inputField.GetComponentInParent<Canvas>();
            if (canvas != null)
            {
                return canvas.rootCanvas;
            }
        }

        Canvas fallbackCanvas = FindFirstObjectByType<Canvas>();
        return fallbackCanvas != null ? fallbackCanvas.rootCanvas : null;
    }

    /// <summary>
    /// Muestra el mensaje de éxito del registro y ajusta el estado de los botones.
    /// </summary>
    void ShowRegistrationSuccess()
    {
        if (RegisterConfirmationText != null)
        {
            RegisterConfirmationText.text = "¡Listo! Tu cuenta ya está creada. Ahora puedes iniciar sesión.";
            RegisterConfirmationText.gameObject.SetActive(true);
        }

        if (RegisterButton != null)
        {
            RegisterButton.interactable = false;
        }

        if (LoginButton != null)
        {
            LoginButton.gameObject.SetActive(true);
            LoginButton.interactable = true;
        }
    }
}
