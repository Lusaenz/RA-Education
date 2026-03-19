using UnityEngine;
using TMPro;

/// <summary>
/// Vista del flujo inicial tras autenticacion.
/// Muestra datos basicos del usuario almacenado en sesion.
/// </summary>
public class TestInitialUserFlowView : MonoBehaviour, ITestInitialUserFlowView
{
    [SerializeField] private TextMeshProUGUI userNameText;
    [SerializeField] private TextMeshProUGUI roleTypeText;
    [SerializeField] private TextMeshProUGUI degreeText;

    private TestInitialUserFlowPresenter presenter;

    /// <summary>
    /// Inicializa el presenter y solicita la carga de datos de sesion.
    /// </summary>
    private void Start()
    {
        InitializePresenter();
        presenter.LoadUserData();
    }

    /// <summary>
    /// Crea el presenter asociado a esta vista.
    /// </summary>
    private void InitializePresenter()
    {
        presenter = new TestInitialUserFlowPresenter(this);
    }

    /// <summary>
    /// Refresca los textos principales de la vista.
    /// </summary>
    public void DisplayUserData(string userName, string roleName, string degreeName)
    {
        if (userNameText != null)
            userNameText.text = userName;

        if (roleTypeText != null)
            roleTypeText.text = roleName;

        if (degreeText != null)
            degreeText.text = degreeName;
    }

    /// <summary>
    /// Reporta errores de carga del flujo inicial.
    /// </summary>
    public void ShowErrorMessage(string message)
    {
        Debug.LogError("Error en TestInitialUserFlow: " + message);
    }
}
