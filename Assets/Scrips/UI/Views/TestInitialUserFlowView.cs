using UnityEngine;
using TMPro;
using UnityEngine.SceneManagement;

/// <summary>
/// Vista del flujo inicial tras autenticacion.
/// Muestra datos basicos del usuario almacenado en sesion.
/// </summary>
public class TestInitialUserFlowView : MonoBehaviour, ITestInitialUserFlowView
{
    [SerializeField] private TextMeshProUGUI userNameText;
    [SerializeField] private TextMeshProUGUI roleTypeText;
    [SerializeField] private TextMeshProUGUI degreeText;
    [SerializeField] private TextMeshProUGUI totalStarsText;

    [Header("BookSystem")]
    [SerializeField] private GameObject bookSystem;
    [SerializeField] private GameObject canvasTopHUD;
    [SerializeField] private GameObject canvasBottomInfo;

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
    public void DisplayUserData(string userName, string roleName, string degreeName, int totalStars)
    {
        if (userNameText != null)
            userNameText.text = userName;

        if (roleTypeText != null)
            roleTypeText.text = roleName;

        if (degreeText != null)
            degreeText.text = degreeName;

        if (totalStarsText != null)
            totalStarsText.text = totalStars.ToString();
    }

    /// <summary>
    /// Reporta errores de carga del flujo inicial.
    /// </summary>
    public void ShowErrorMessage(string message)
    {
        Debug.LogError("Error en TestInitialUserFlow: " + message);
    }

    public void CloseBook()
    {
        if (bookSystem != null) bookSystem.SetActive(false);
        if (canvasTopHUD != null) canvasTopHUD.SetActive(true);
        if (canvasBottomInfo != null) canvasBottomInfo.SetActive(true);
    }

    public void IrAEscenaPrueba()
    {
        SceneManager.LoadScene("SelectGameExample");
    }
}
