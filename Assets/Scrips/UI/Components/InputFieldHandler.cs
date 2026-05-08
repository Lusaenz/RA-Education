using UnityEngine;
using TMPro;
using UnityEngine.EventSystems;

[RequireComponent(typeof(TMP_InputField))]
/// <summary>
/// Encapsula el comportamiento visual del placeholder al ganar o perder foco.
/// </summary>
public class InputFieldHandler : MonoBehaviour, ISelectHandler, IDeselectHandler
{
    private TMP_InputField inputField;

    void Awake()
    {
        inputField = GetComponent<TMP_InputField>();
    }

    // Implementación de ISelectHandler - se llama automáticamente al hacer focus
    /// <summary>
    /// Evento de foco recibido desde el sistema de UI.
    /// </summary>
    public void OnSelect(BaseEventData eventData)
    {
        HandleSelect();
    }

    // Implementación de IDeselectHandler - se llama automáticamente al perder focus
    /// <summary>
    /// Evento de perdida de foco recibido desde el sistema de UI.
    /// </summary>
    public void OnDeselect(BaseEventData eventData)
    {
        HandleDeselect();
    }

    // Método público para enlazar desde el Inspector (On Select event)
    /// <summary>
    /// Oculta el placeholder mientras el usuario edita el campo.
    /// </summary>
    public void HandleSelect()
    {
        if (inputField == null)
            inputField = GetComponent<TMP_InputField>();

        // Ocultar el placeholder cuando se selecciona el campo
        if (inputField != null && inputField.placeholder != null)
        {
            inputField.placeholder.gameObject.SetActive(false);
        }
    }

    // Método público para enlazar desde el Inspector (On Deselect event)
    /// <summary>
    /// Restaura el placeholder cuando el campo pierde foco.
    /// </summary>
    public void HandleDeselect()
    {
        if (inputField == null)
            inputField = GetComponent<TMP_InputField>();

        // Mostrar el placeholder cuando se deselecciona el campo
        if (inputField != null && inputField.placeholder != null)
        {
            inputField.placeholder.gameObject.SetActive(true);
        }
    }
}

