using UnityEngine;
using TMPro;
using UnityEngine.UI;

public class StudentCardUI : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI nameText;
    [SerializeField] private TextMeshProUGUI degreeText;
    [SerializeField] private TextMeshProUGUI completedTopicsText;
    [SerializeField] private TextMeshProUGUI statusText;
    [SerializeField] private Button viewProgressButton;

    /// <summary>
    /// Recibe los datos del estudiante y los asigna a la interfaz de la card.
    /// </summary>
    public void Setup(StudentCardData data)
    {
        if (nameText != null) 
            nameText.text = data.Name;
            
        if (degreeText != null) 
            degreeText.text = "Grado: " + data.Degree;

        if (completedTopicsText != null) 
            completedTopicsText.text = "Temas Completados: " + data.CompletedTopicsText;

        if (statusText != null) 
            statusText.text = data.Status;

        if (viewProgressButton != null)
        {
            viewProgressButton.onClick.RemoveAllListeners();
            viewProgressButton.onClick.AddListener(() => OnClickViewProgress(data.Name));
        }
    }

    private void OnClickViewProgress(string studentName)
    {
        Debug.Log("Viendo progreso de: " + studentName);
    }
}