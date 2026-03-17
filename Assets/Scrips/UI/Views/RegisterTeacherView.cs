using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;

/// <summary>
/// Vista de registro para profesores.
/// Coordina el formulario, el selector de grado y la representacion de errores.
/// </summary>
public class RegisterTeacherView : MonoBehaviour
{
    RegisterPresenter presenter;
    DegreeSelector degreeSelector;
    bool isRegistering = false;

    public TMP_InputField nameInput;
    public TMP_InputField emailInput;
    public TMP_InputField degreeInput;
    public TMP_InputField passInput;
    public Button registerButton;
    public Button loginButton;
    public Text ErrorTextName;
    public Text ErrorTextEmail;
    public Text ErrorTextDegree;
    public Text ErrorTextPassword;
    public Text registerConfirmationText;
    

    /// <summary>
    /// Resuelve dependencias de escena y enlaza eventos de botones.
    /// </summary>
    void Start()
    {
        presenter = FindFirstObjectByType<RegisterPresenter>();
        if (presenter == null)
        {
            var go = new GameObject("RegisterPresenter");
            presenter = go.AddComponent<RegisterPresenter>();
        }

        degreeSelector = FindFirstObjectByType<DegreeSelector>();
        if (degreeSelector == null)
        {
            Debug.LogWarning("RegisterTeacherView: DegreeSelector no encontrado en la escena.");
        }

        if (registerButton != null)
        {
            registerButton.onClick.RemoveAllListeners();
            registerButton.onClick.AddListener(Register);
        }
        if (loginButton != null)
        {
            loginButton.onClick.RemoveAllListeners();
            loginButton.onClick.AddListener(GoToLogin);
        }

        if (registerConfirmationText != null)
        {
            registerConfirmationText.gameObject.SetActive(false);
            registerConfirmationText.text = string.Empty;
        }

        // Conectar el DegreeSelector al input field de grado
        if (degreeSelector != null && degreeInput != null)
        {
            degreeSelector.degreeInputField = degreeInput;
        }
    }

    /// <summary>
    /// Ejecuta el registro del profesor usando el estado actual del formulario.
    /// </summary>
    public void Register()
    {
        if (isRegistering)
        {
            return;
        }

        if (presenter == null)
        {
            Debug.LogError("Presenter no disponible para registro de profesor.");
            ShowError("Error interno: presenter no disponible.");
            return;
        }

        ClearAllErrors();

        // Obtener valores de los campos
        var name = nameInput != null ? nameInput.text : string.Empty;
        var email = emailInput != null ? emailInput.text : string.Empty;
        var pass = passInput != null ? passInput.text : string.Empty;
        var degreeId = degreeSelector != null ? degreeSelector.GetSelectedDegreeId() : 0;

        // Llamar al presenter que realiza las validaciones
        var result = presenter.RegisterTeacher(degreeId, name, email, pass);
        
        if (result.Success)
        {
            // Guardar mensaje y redirigir a LoginStudent
            PlayerPrefs.SetString("LoginMessage", "Registro exitoso! Por favor inicia sesión.");
            SceneManager.LoadScene("LoginStudent");
        }
        else
        {
            // Mostrar errores de cada campo desde el resultado del presenter
            DisplayErrorsByField(result.FieldErrors);
        }
    }

    Coroutine clearErrorCoroutine;


    /// <summary>
    /// Distribuye mensajes de error por control visual.
    /// </summary>
    void DisplayErrorsByField(Dictionary<string, string> fieldErrors)
    {
        ClearAllErrors();

        if (fieldErrors.ContainsKey("name"))
        {
            ShowFieldError(ErrorTextName, fieldErrors["name"]);
        }
        
        if (fieldErrors.ContainsKey("email"))
        {
            ShowFieldError(ErrorTextEmail, fieldErrors["email"]);
        }
        
        if (fieldErrors.ContainsKey("degree"))
        {
            ShowFieldError(ErrorTextDegree, fieldErrors["degree"]);
        }
        
        if (fieldErrors.ContainsKey("password"))
        {
            ShowFieldError(ErrorTextPassword, fieldErrors["password"]);
        }

        if (clearErrorCoroutine != null)
            StopCoroutine(clearErrorCoroutine);

        clearErrorCoroutine = StartCoroutine(ClearErrorAfterSeconds(5f));
        
    }

    /// <summary>
    /// Muestra un error en el elemento visual indicado.
    /// </summary>
    void ShowFieldError(Text errorText, string message)
    {
        if (errorText == null)
            return;

        errorText.text = message;
        errorText.gameObject.SetActive(true);
    }

    /// <summary>
    /// Limpia el texto y la visibilidad de un error.
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
        ClearFieldError(ErrorTextEmail);
        ClearFieldError(ErrorTextDegree);
        ClearFieldError(ErrorTextPassword);
    }

    /// <summary>
    /// Registra un error generico en consola.
    /// </summary>
    void ShowError(string message, float seconds = 3f)
    {
        Debug.LogWarning(message);

    }

    
    /// <summary>
    /// Limpia los errores visibles despues de un retraso.
    /// </summary>
    IEnumerator ClearErrorAfterSeconds(float seconds)
    {
        yield return new WaitForSeconds(seconds);
        ClearAllErrors();
        clearErrorCoroutine = null;
    }

    /// <summary>
    /// Navega al login de profesores.
    /// </summary>
    private void GoToLogin()
    {
        SceneManager.LoadScene("LoginTeacher");
    }
}
