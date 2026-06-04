using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections.Generic;
using System.Linq;

/// <summary>
/// Controla la selección visual de grados y preguntas de seguridad en formularios de registro.
/// Utiliza Services y Repositories para acceder a los datos en lugar de conectarse directamente a la BD.
/// Sincroniza las selecciones con TMP_InputField correspondientes.
/// </summary>
public class DegreeSelector : MonoBehaviour
{
    [Header("Grados")]
    public GameObject degreePanel;
    public TMP_InputField degreeInputField;

    [Header("Preguntas de Seguridad")]
    public GameObject panelQuestionsSecurity;
    public TMP_InputField questionInputField;
    public TMP_InputField answerInputField; // Campo oculto para ingresar respuesta

    private Button[] degreeButtons;
    private Button[] questionButtons;
    
    private int selectedDegreeId = 0;
    private string selectedDegreeName = "";
    private int selectedQuestionId = 0;
    private string selectedQuestion = "";
    private string securityAnswer = "";

    private List<DegreeModel> degrees = new List<DegreeModel>();
    private List<SecurityQuestionsModel> securityQuestions = new List<SecurityQuestionsModel>();
    
    // Services
    private DegreeService degreeService;
    private SecurityQuestionsService securityQuestionsService;
    
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

        // Inicializar los servicios
        degreeService = new DegreeService();
        securityQuestionsService = new SecurityQuestionsService();

        LoadDegrees();
        LoadSecurityQuestions();
        SetupUI();
        isInitialized = true;
    }

    /// <summary>
    /// Recupera la lista de grados utilizando el servicio.
    /// </summary>
    void LoadDegrees()
    {
        if (degreeService == null)
        {
            Debug.LogError("DegreeSelector: DegreeService no disponible.");
            return;
        }

        try
        {
            degrees = degreeService.GetAllDegrees();
            Debug.Log($"DegreeSelector: Cargados {degrees.Count} grados desde el servicio.");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"DegreeSelector: Error al cargar grados: {ex.Message}");
        }
    }

    /// <summary>
    /// Recupera la lista de preguntas de seguridad utilizando el servicio.
    /// </summary>
    void LoadSecurityQuestions()
    {
        if (securityQuestionsService == null)
        {
            Debug.LogError("DegreeSelector: SecurityQuestionsService no disponible.");
            return;
        }

        try
        {
            securityQuestions = securityQuestionsService.GetAllQuestions();
            Debug.Log($"DegreeSelector: Cargadas {securityQuestions.Count} preguntas de seguridad desde el servicio.");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"DegreeSelector: Error al cargar preguntas de seguridad: {ex.Message}");
        }
    }

    /// <summary>
    /// Resuelve referencias visuales y enlaza botones e input fields.
    /// Configura tanto el panel de grados como el de preguntas de seguridad.
    /// </summary>
    void SetupUI()
    {
        // ============ CONFIGURAR PANEL DE GRADOS ============
        SetupDegreePanel();

        // ============ CONFIGURAR PANEL DE PREGUNTAS DE SEGURIDAD ============
        SetupSecurityQuestionsPanel();

        // Auto-buscar degreeInputField si no está asignado
        if (degreeInputField == null)
        {
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

        // Evento para abrir el panel de grados cuando se hace click en el input field
        if (degreeInputField != null)
        {
            degreeInputField.onSelect.AddListener((text) => ShowDegreePanel());
        }
    }

    /// <summary>
    /// Configura el panel de selección de grados.
    /// </summary>
    void SetupDegreePanel()
    {
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

        degreePanel.SetActive(false);

        List<Button> buttonList = new List<Button>();
        foreach (Button btn in degreePanel.GetComponentsInChildren<Button>())
        {
            buttonList.Add(btn);
        }
        degreeButtons = buttonList.ToArray();

        Debug.Log($"DegreeSelector: Se encontraron {degreeButtons.Length} botones de grados.");

        int buttonCount = Mathf.Min(degreeButtons.Length, degrees.Count);
        for (int i = 0; i < buttonCount; i++)
        {
            int degreeIndex = i;
            degreeButtons[i].onClick.AddListener(() => SelectDegree(degreeIndex));

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
    }

    /// <summary>
    /// Configura el panel de selección de preguntas de seguridad.
    /// </summary>
    void SetupSecurityQuestionsPanel()
    {
        if (panelQuestionsSecurity == null)
        {
            Transform panelTransform = transform.Find("SecurityQuestionsPanel");
            if (panelTransform != null)
            {
                panelQuestionsSecurity = panelTransform.gameObject;
            }
            else
            {
                Debug.LogWarning("DegreeSelector: panelQuestionsSecurity no está asignado en el inspector.");
                return;
            }
        }

        panelQuestionsSecurity.SetActive(false);

        List<Button> buttonList = new List<Button>();
        foreach (Button btn in panelQuestionsSecurity.GetComponentsInChildren<Button>())
        {
            buttonList.Add(btn);
        }
        questionButtons = buttonList.ToArray();

        Debug.Log($"DegreeSelector: Se encontraron {questionButtons.Length} botones de preguntas de seguridad.");

        int buttonCount = Mathf.Min(questionButtons.Length, securityQuestions.Count);
        for (int i = 0; i < buttonCount; i++)
        {
            int questionIndex = i;
            questionButtons[i].onClick.AddListener(() => SelectSecurityQuestion(questionIndex));

            TextMeshProUGUI buttonText = questionButtons[i].GetComponentInChildren<TextMeshProUGUI>();
            if (buttonText != null)
            {
                buttonText.text = securityQuestions[questionIndex].question;
            }
            else
            {
                Text legacyText = questionButtons[i].GetComponentInChildren<Text>();
                if (legacyText != null)
                {
                    legacyText.text = securityQuestions[questionIndex].question;
                }
            }
        }

        // Auto-buscar answerInputField si no está asignado
        if (answerInputField == null)
        {
            Canvas canvas = FindFirstObjectByType<Canvas>();
            if (canvas != null)
            {
                foreach (TMP_InputField inputField in canvas.GetComponentsInChildren<TMP_InputField>())
                {
                    if (inputField.name.Contains("Answer") || inputField.name.Contains("answer") || 
                        inputField.name.Contains("Security") || inputField.name.Contains("security"))
                    {
                        // Asegurarse de que no sea el questionInputField
                        if (inputField != questionInputField)
                        {
                            answerInputField = inputField;
                            break;
                        }
                    }
                }
            }

            if (answerInputField == null)
            {
                Debug.LogWarning("DegreeSelector: answerInputField no asignado y no encontrado en la escena.");
            }
        }

        // Ocultar el input de respuesta inicialmente
        if (answerInputField != null)
        {
            answerInputField.gameObject.SetActive(false);
        }

        // Evento para abrir el panel de preguntas cuando se hace click en el input field
        if (questionInputField != null)
        {
            questionInputField.onSelect.AddListener((text) => ShowSecurityQuestionsPanel());
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
    /// Oculta el panel de grados.
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
    /// Muestra el panel emergente de preguntas de seguridad.
    /// </summary>
    public void ShowSecurityQuestionsPanel()
    {
        if (!isInitialized)
        {
            Debug.LogWarning("DegreeSelector: No está inicializado aún.");
            return;
        }

        if (panelQuestionsSecurity != null)
        {
            panelQuestionsSecurity.SetActive(true);
            Debug.Log("DegreeSelector: Panel de preguntas de seguridad abierto.");
        }
    }

    /// <summary>
    /// Oculta el panel de preguntas de seguridad.
    /// </summary>
    public void HideSecurityQuestionsPanel()
    {
        if (panelQuestionsSecurity != null)
        {
            panelQuestionsSecurity.SetActive(false);
            Debug.Log("DegreeSelector: Panel de preguntas de seguridad cerrado.");
        }
    }

    /// <summary>
    /// Aplica la selección elegida por índice y actualiza el campo visible.
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
            degreeInputField.interactable = false;
            degreeInputField.interactable = true;
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
    /// Indica si el usuario ya eligió un grado válido.
    /// </summary>
    public bool IsDegreeSelected()
    {
        return selectedDegreeId > 0;
    }

    /// <summary>
    /// Devuelve el identificador de la pregunta de seguridad seleccionada.
    /// </summary>
    public int GetSelectedSecurityQuestionId()
    {
        return selectedQuestionId;
    }

    /// <summary>
    /// Devuelve la pregunta de seguridad seleccionada.
    /// </summary>
    public string GetSelectedSecurityQuestion()
    {
        return selectedQuestion;
    }

    /// <summary>
    /// Obtiene la respuesta de seguridad ingresada por el usuario.
    /// </summary>
    public string GetSecurityAnswer()
    {
        if (answerInputField != null)
        {
            securityAnswer = answerInputField.text;
        }
        return securityAnswer;
    }

    /// <summary>
    /// Indica si el usuario ya seleccionó una pregunta de seguridad.
    /// </summary>
    public bool IsSecurityQuestionSelected()
    {
        return selectedQuestionId > 0;
    }

    /// <summary>
    /// Indica si la respuesta de seguridad ha sido ingresada.
    /// </summary>
    public bool IsSecurityAnswerProvided()
    {
        return !string.IsNullOrWhiteSpace(GetSecurityAnswer());
    }

    /// <summary>
    /// Limpia la selección de grado y resetea el campo visual.
    /// </summary>
    public void ResetDegreeSelection()
    {
        selectedDegreeId = 0;
        selectedDegreeName = "";
        if (degreeInputField != null)
        {
            degreeInputField.text = "";
        }
    }

    /// <summary>
    /// Limpia la selección de pregunta de seguridad y resetea los campos visuales.
    /// </summary>
    public void ResetSecurityQuestionSelection()
    {
        selectedQuestionId = 0;
        selectedQuestion = "";
        if (questionInputField != null)
        {
            questionInputField.text = "";
        }
        if (answerInputField != null)
        {
            answerInputField.text = "";
            answerInputField.gameObject.SetActive(false);
        }
    }

    /// <summary>
    /// Aplica la selección de pregunta de seguridad por índice.
    /// Muestra el input field para la respuesta.
    /// </summary>
    void SelectSecurityQuestion(int questionIndex)
    {
        if (questionIndex < 0 || questionIndex >= securityQuestions.Count)
        {
            Debug.LogWarning($"DegreeSelector: Índice de pregunta inválido: {questionIndex}");
            return;
        }

        SecurityQuestionsModel selectedQuestionModel = securityQuestions[questionIndex];
        selectedQuestionId = selectedQuestionModel.id_question;
        selectedQuestion = selectedQuestionModel.question;

        // Actualizar el input field con la pregunta seleccionada
        if (questionInputField != null)
        {
            questionInputField.text = selectedQuestion;
            questionInputField.interactable = false;
        }

        // Mostrar el input field para la respuesta
        if (answerInputField != null)
        {
            answerInputField.gameObject.SetActive(true);
            answerInputField.text = "";
            answerInputField.ActivateInputField(); // Enfocarlo automáticamente
        }

        Debug.Log($"DegreeSelector: Pregunta de seguridad seleccionada - ID: {selectedQuestionId}, Pregunta: {selectedQuestion}");

        // Cerrar el panel de preguntas automáticamente
        HideSecurityQuestionsPanel();
    }

    /// <summary>
    /// Limpia todas las selecciones.
    /// </summary>
    public void ResetAllSelections()
    {
        ResetDegreeSelection();
        ResetSecurityQuestionSelection();
    }
}
