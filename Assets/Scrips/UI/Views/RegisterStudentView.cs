
using UnityEngine;
using UnityEngine.UI;
using TMPro;

using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// Vista de registro para estudiantes.
/// Recoge los datos del formulario, delega validaciones al presenter y representa errores.
/// </summary>
public class RegisterStudentView : MonoBehaviour
{
    public TMP_InputField InputName;
    public TMP_InputField InputDegree;
    public TMP_InputField InputAge;
    public TMP_InputField InputPassword;
    public Button RegisterButton;
    public Button LoginButton;
    public Text ErrorTextName;
    public Text ErrorTextDegree;
    public Text ErrorTextAge;
    public Text ErrorTextPassword;
    public Text RegisterConfirmationText;

    RegisterPresenter presenter;
    DegreeSelector degreeSelector;
    bool isRegistering = false;
    Coroutine clearErrorCoroutine;

    /// <summary>
    /// Resuelve dependencias de escena y enlaza eventos de botones.
    /// </summary>
    void Start()
    {
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
            Debug.LogWarning("RegisterStudentView: DegreeSelector no encontrado en la escena.");
        }

        if (RegisterButton != null)
        {
            RegisterButton.onClick.RemoveAllListeners();
            RegisterButton.onClick.AddListener(Register);
        }
        if (LoginButton != null)
        {
            LoginButton.onClick.RemoveAllListeners();
            LoginButton.onClick.AddListener(GoToLogin);
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
    }

    /// <summary>
    /// Ejecuta el registro de estudiante usando los valores actuales del formulario.
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

        // Obtener valores de los campos
        var name = InputName != null ? InputName.text : string.Empty;
        var ageText = InputAge != null ? InputAge.text : string.Empty;
        var pass = InputPassword != null ? InputPassword.text : string.Empty;
        var degreeId = degreeSelector != null ? degreeSelector.GetSelectedDegreeId() : 0;

        // Llamar al presenter que realiza las validaciones
        var result = presenter.RegisterStudent(degreeId, name, ageText, pass);
        
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
        
        if (fieldErrors.ContainsKey("password"))
        {
            ShowFieldError(ErrorTextPassword, fieldErrors["password"]);
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
        ClearFieldError(ErrorTextPassword);
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

    /// <summary>
    /// Navega al login de estudiantes.
    /// </summary>
    public void GoToLogin()
    {
        SceneManager.LoadScene("LoginStudent");
    }
}
