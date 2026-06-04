using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class PasswordToggle : MonoBehaviour
{
    [SerializeField] private TMP_InputField passwordInput;
    [SerializeField] private Button showPasswordButton;
    [SerializeField] private Button hidePasswordButton;
    
    private bool isPasswordVisible = false;

    private void Start()
    {
        // Validar referencias
        if (passwordInput == null || showPasswordButton == null || hidePasswordButton == null)
        {
            Debug.LogError("PasswordToggle: Faltan referencias en los campos SerializeField");
            return;
        }

        // Configurar el InputField como TextArea multilinea
        passwordInput.lineType = TMP_InputField.LineType.MultiLineNewline;

        // Registrar los listeners de los botones
        showPasswordButton.onClick.AddListener(ShowPassword);
        hidePasswordButton.onClick.AddListener(HidePassword);

        // Inicialmente mostrar el botón de ver y ocultar el botón de ocultar
        showPasswordButton.gameObject.SetActive(true);
        hidePasswordButton.gameObject.SetActive(false);
        
        // Ocultar la contraseña por defecto
        HidePassword();
    }

    /// <summary>
    /// Muestra la contraseña en el input
    /// </summary>
    public void ShowPassword()
    {
        passwordInput.inputType = TMP_InputField.InputType.Standard;
        passwordInput.ForceLabelUpdate();
        isPasswordVisible = true;

        // Cambiar visibilidad de botones
        showPasswordButton.gameObject.SetActive(false);
        hidePasswordButton.gameObject.SetActive(true);

        Debug.Log("Contraseña visible");
    }

    /// <summary>
    /// Oculta la contraseña en el input
    /// </summary>
    public void HidePassword()
    {
        passwordInput.inputType = TMP_InputField.InputType.Password;
        passwordInput.ForceLabelUpdate();
        isPasswordVisible = false;

        // Cambiar visibilidad de botones
        showPasswordButton.gameObject.SetActive(true);
        hidePasswordButton.gameObject.SetActive(false);

        Debug.Log("Contraseña oculta");
    }

    /// <summary>
    /// Alterna la visibilidad de la contraseña
    /// </summary>
    public void TogglePassword()
    {
        if (isPasswordVisible)
        {
            HidePassword();
        }
        else
        {
            ShowPassword();
        }
    }

    /// <summary>
    /// Obtiene el estado actual de visibilidad
    /// </summary>
    public bool IsPasswordVisible => isPasswordVisible;

    private void OnDestroy()
    {
        // Limpiar listeners
        if (showPasswordButton != null)
            showPasswordButton.onClick.RemoveListener(ShowPassword);
        if (hidePasswordButton != null)
            hidePasswordButton.onClick.RemoveListener(HidePassword);
    }
}
