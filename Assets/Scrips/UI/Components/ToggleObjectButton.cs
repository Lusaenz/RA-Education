using UnityEngine;
using UnityEngine.UI;

public class ToggleObjectButton : MonoBehaviour
{
    [SerializeField] private Button toggleButton;
    [SerializeField] private GameObject targetObject;
    [SerializeField] private bool startActive = false;

    private bool isObjectActive;

    private void Start()
    {
        // Validar referencias
        if (toggleButton == null)
        {
            Debug.LogError("ToggleObjectButton: Falta la referencia al botón");
            return;
        }

        if (targetObject == null)
        {
            Debug.LogError("ToggleObjectButton: Falta la referencia al objeto a controlar");
            return;
        }

        // Establecer estado inicial
        isObjectActive = startActive;
        targetObject.SetActive(isObjectActive);

        // Registrar listener del botón
        toggleButton.onClick.AddListener(ToggleObject);

        Debug.Log($"ToggleObjectButton inicializado. Objeto inicial: {(isObjectActive ? "Abierto" : "Cerrado")}");
    }

    /// <summary>
    /// Alterna la visibilidad del objeto
    /// </summary>
    public void ToggleObject()
    {
        isObjectActive = !isObjectActive;
        targetObject.SetActive(isObjectActive);

        Debug.Log($"Objeto {targetObject.name}: {(isObjectActive ? "Abierto" : "Cerrado")}");
    }

    /// <summary>
    /// Abre el objeto
    /// </summary>
    public void OpenObject()
    {
        if (!isObjectActive)
        {
            isObjectActive = true;
            targetObject.SetActive(true);
            Debug.Log($"Objeto {targetObject.name} abierto");
        }
    }

    /// <summary>
    /// Cierra el objeto
    /// </summary>
    public void CloseObject()
    {
        if (isObjectActive)
        {
            isObjectActive = false;
            targetObject.SetActive(false);
            Debug.Log($"Objeto {targetObject.name} cerrado");
        }
    }

    /// <summary>
    /// Obtiene el estado actual del objeto
    /// </summary>
    public bool IsObjectActive => isObjectActive;

    private void OnDestroy()
    {
        // Limpiar listener
        if (toggleButton != null)
            toggleButton.onClick.RemoveListener(ToggleObject);
    }
}
