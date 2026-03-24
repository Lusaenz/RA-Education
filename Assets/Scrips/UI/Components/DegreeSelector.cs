using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections.Generic;
using System.Linq;
using SQLite4Unity3d;

/// <summary>
/// Controla la seleccion visual de grados en formularios de registro.
/// Carga opciones desde SQLite y sincroniza la seleccion con un TMP_InputField.
/// </summary>
public class DegreeSelector : MonoBehaviour
{
    public GameObject degreePanel;
    public TMP_InputField degreeInputField;
    
    private Button[] degreeButtons;
    private int selectedDegreeId = -1;
    private string selectedDegreeName = "";
    private List<DegreeModel> degrees = new List<DegreeModel>();
    private SQLiteConnection dbConnection;
    private bool isInitialized = false;

    /// <summary>
    /// Espera la base de datos antes de construir el selector.
    /// </summary>
    void Start()
    {
        // Inicializar cuando la base de datos esté lista
        StartCoroutine(InitializeWhenDatabaseReady());
    }

    /// <summary>
    /// Espera a que DatabaseManager haya abierto la conexion.
    /// </summary>
    System.Collections.IEnumerator InitializeWhenDatabaseReady()
    {
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        dbConnection = DatabaseManager.Instance.GetConnection();
        LoadDegrees();
        SetupUI();
        isInitialized = true;
    }

    /// <summary>
    /// Recupera la lista de grados desde la base de datos.
    /// </summary>
    void LoadDegrees()
    {
        if (dbConnection == null)
        {
            Debug.LogError("DegreeSelector: Conexión a la base de datos no disponible.");
            return;
        }

        try
        {
            degrees = dbConnection.Table<DegreeModel>().ToList();
            Debug.Log($"DegreeSelector: Cargados {degrees.Count} grados de la base de datos.");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"DegreeSelector: Error al cargar grados: {ex.Message}");
        }
    }

    /// <summary>
    /// Resuelve referencias visuales y enlaza botones e input field.
    /// </summary>
    void SetupUI()
    {
        // Auto-buscar degreePanel si no está asignado
        if (degreePanel == null)
        {
            Transform panelTransform = transform.Find("DegreePanel");
            if (panelTransform != null)
            {
                degreePanel = panelTransform.gameObject;
            }
            else
            {
                Debug.LogError("DegreeSelector: degreePanel no está asignado en el inspector.");
                return;
            }
        }

        // Desactivar panel inicialmente
        degreePanel.SetActive(false);

        // Obtener botones directamente del panel (los botones están en el panel, no en un contenedor separado)
        List<Button> buttonList = new List<Button>();
        foreach (Button btn in degreePanel.GetComponentsInChildren<Button>())
        {
            // Excluir botones que sean el botón de cerrar (si existe)
            buttonList.Add(btn);
        }
        degreeButtons = buttonList.ToArray();

        Debug.Log($"DegreeSelector: Se encontraron {degreeButtons.Length} botones de grados.");

        // Asignar listeners a los botones de grados (máximo 5 primeros botones)
        int buttonCount = Mathf.Min(degreeButtons.Length, 5);
        for (int i = 0; i < buttonCount && i < degrees.Count; i++)
        {
            int degreeIndex = i;
            degreeButtons[i].onClick.AddListener(() => SelectDegree(degreeIndex));
            
            // Actualizar texto del botón con el nombre del grado
            TextMeshProUGUI buttonText = degreeButtons[i].GetComponentInChildren<TextMeshProUGUI>();
            if (buttonText != null)
            {
                buttonText.text = degrees[degreeIndex].name;
            }
            else
            {
                Text legacyText = degreeButtons[i].GetComponentInChildren<Text>();
                if (legacyText != null)
                {
                    legacyText.text = degrees[degreeIndex].name;
                }
            }
        }

        // Auto-buscar degreeInputField si no está asignado
        if (degreeInputField == null)
        {
            // Intentar encontrarlo en la escena por nombre similar
            Canvas canvas = FindFirstObjectByType<Canvas>();
            if (canvas != null)
            {
                foreach (TMP_InputField inputField in canvas.GetComponentsInChildren<TMP_InputField>())
                {
                    if (inputField.name.Contains("Degree") || inputField.name.Contains("degree"))
                    {
                        degreeInputField = inputField;
                        break;
                    }
                }
            }

            if (degreeInputField == null)
            {
                Debug.LogWarning("DegreeSelector: degreeInputField no asignado y no encontrado en la escena.");
            }
        }

        // Evento para abrir el panel cuando se hace click en el input field
        if (degreeInputField != null)
        {
            // Usar onSelect para cuando el campo recibe el foco
            degreeInputField.onSelect.AddListener((text) => ShowDegreePanel());
        }
    }

    /// <summary>
    /// Muestra el panel emergente de grados.
    /// </summary>
    public void ShowDegreePanel()
    {
        if (!isInitialized)
        {
            Debug.LogWarning("DegreeSelector: No está inicializado aún.");
            return;
        }

        if (degreePanel != null)
        {
            degreePanel.SetActive(true);
            Debug.Log("DegreeSelector: Panel de grados abierto.");
        }
    }

    /// <summary>
    /// Oculta el panel de seleccion.
    /// </summary>
    public void HideDegreePanel()
    {
        if (degreePanel != null)
        {
            degreePanel.SetActive(false);
            Debug.Log("DegreeSelector: Panel de grados cerrado.");
        }
    }

    /// <summary>
    /// Aplica la seleccion elegida por indice y actualiza el campo visible.
    /// </summary>
    void SelectDegree(int degreeIndex)
    {
        if (degreeIndex < 0 || degreeIndex >= degrees.Count)
        {
            Debug.LogWarning($"DegreeSelector: Índice de grado inválido: {degreeIndex}");
            return;
        }

        DegreeModel selectedDegree = degrees[degreeIndex];
        selectedDegreeId = selectedDegree.id_degree;
        selectedDegreeName = selectedDegree.name;

        // Actualizar el input field con el nombre del grado
        if (degreeInputField != null)
        {
            degreeInputField.text = selectedDegreeName;
            degreeInputField.interactable = false; // Prevenir edición manual
            degreeInputField.interactable = true;  // Permitir volver a interactuar
        }

        Debug.Log($"DegreeSelector: Grado seleccionado - ID: {selectedDegreeId}, Nombre: {selectedDegreeName}");

        // Cerrar el panel automáticamente
        HideDegreePanel();
    }

    /// <summary>
    /// Devuelve el identificador del grado seleccionado.
    /// </summary>
    public int GetSelectedDegreeId()
    {
        return selectedDegreeId;
    }

    /// <summary>
    /// Devuelve el nombre del grado seleccionado.
    /// </summary>
    public string GetSelectedDegreeName()
    {
        return selectedDegreeName;
    }

    /// <summary>
    /// Indica si el usuario ya eligio un grado valido.
    /// </summary>
    public bool IsDegreeSelected()
    {
        return selectedDegreeId > 0;
    }

    /// <summary>
    /// Limpia la seleccion actual y resetea el campo visual.
    /// </summary>
    public void ResetSelection()
    {
        selectedDegreeId = -1;
        selectedDegreeName = "";
        if (degreeInputField != null)
        {
            degreeInputField.text = "";
        }
    }
}
