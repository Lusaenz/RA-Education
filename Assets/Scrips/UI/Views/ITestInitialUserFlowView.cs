/// <summary>
/// Contrato minimo que debe implementar la vista del flujo inicial del usuario.
/// </summary>
public interface ITestInitialUserFlowView
{
    void DisplayUserData(string userName, string roleName, string degreeName);
    void ShowErrorMessage(string message);
}
