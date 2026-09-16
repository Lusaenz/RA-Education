using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;
using TMPro;
using UnityEngine.SceneManagement; // <-- Agrega esta línea arriba del todo

public class StudentCardUI : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI nameText;
    [SerializeField] private TextMeshProUGUI degreeText;
    [SerializeField] private TextMeshProUGUI completedTopicsText;
    [SerializeField] private TextMeshProUGUI statusText;
    [SerializeField] private Image statusCircleImage;
    [SerializeField] private Button btnViewProgress; // <-- Asigna el botón "Ver Progreso" en el Inspector

    [Header("Sprites de Estado")]
    [SerializeField] private Sprite completedSprite;
    [SerializeField] private Sprite inProgressSprite;
    [SerializeField] private Sprite notStartedSprite;

    private UserModel currentUserData;

    public void Setup(StudentCardData studentData)
    {
        currentUserData = studentData.User; // Guardamos el usuario

        nameText.text = studentData.Name;
        
        string degreeFormatted = studentData.Degree.StartsWith("Grado") 
            ? studentData.Degree 
            : $"{studentData.Degree}";
        degreeText.text = degreeFormatted;

        completedTopicsText.text = $"Temas Completados: {studentData.CompletedTopicsText}";
        statusText.text = studentData.Status;

        UpdateStatusSprite(studentData.Status);

        // Configurar evento de clic en el botón
        if (btnViewProgress != null)
        {
            btnViewProgress.onClick.RemoveAllListeners();
            btnViewProgress.onClick.AddListener(OnViewProgressClicked);
        }
    }

    private void OnViewProgressClicked()
    {
        if (currentUserData != null)
        {
            // Asignamos el estudiante seleccionado para que la siguiente escena lo lea
            UserSessionManager.SelectedUserForView = currentUserData;

            // Reemplaza "UserScreenScene" por el nombre exacto de tu escena de detalle de perfil
           // Guardas la escena actual antes de cambiar
UserSessionManager.PreviousSceneName = SceneManager.GetActiveScene().name;

// Abres la pantalla de usuario

            SceneManager.LoadScene("UserScreen"); 
        }
    }

    private void UpdateStatusSprite(string status)
    {
        if (statusCircleImage == null) return;
        statusCircleImage.color = Color.white;

        switch (status)
        {
            case "Completado":
                if (completedSprite != null) statusCircleImage.sprite = completedSprite;
                break;
            case "En Progreso":
                if (inProgressSprite != null) statusCircleImage.sprite = inProgressSprite;
                break;
            case "No Iniciado":
            default:
                if (notStartedSprite != null) statusCircleImage.sprite = notStartedSprite;
                break;
        }
    }
}