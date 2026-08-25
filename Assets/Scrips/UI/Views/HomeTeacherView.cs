using UnityEngine;
using TMPro;

/// <summary>
/// Vista de inicio del profesor.
/// Muestra el saludo de bienvenida con el nombre del profesor en sesion.
/// </summary>
public class HomeTeacherView : MonoBehaviour, IHomeTeacherView
{
    [SerializeField] private TextMeshProUGUI welcomeText;

    private HomeTeacherPresenter presenter;

    /// <summary>
    /// Inicializa el presenter y solicita la carga de datos del profesor en sesion.
    /// </summary>
    private void Start()
    {
        presenter = new HomeTeacherPresenter(this);
        presenter.LoadTeacherData();
    }

    /// <summary>
    /// Refresca el texto de bienvenida.
    /// </summary>
    public void DisplayTeacherData(string welcomeMessage)
    {
        if (welcomeText != null)
            welcomeText.text = welcomeMessage;
    }

    /// <summary>
    /// Reporta errores de carga de la pantalla de inicio del profesor.
    /// </summary>
    public void ShowErrorMessage(string message)
    {
        Debug.LogError("Error en HomeTeacher: " + message);
    }
}
