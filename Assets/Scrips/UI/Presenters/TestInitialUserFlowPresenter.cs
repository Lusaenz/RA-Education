using UnityEngine;

/// <summary>
/// Presenter del flujo inicial posterior al login.
/// Lee la sesion activa y transforma datos del usuario a texto listo para la vista.
/// </summary>
public class TestInitialUserFlowPresenter
{
    private readonly ITestInitialUserFlowView view;
    private readonly UserSessionManager userSession;
    private readonly ResultActivityService resultActivityService;

    public TestInitialUserFlowPresenter(ITestInitialUserFlowView view)
    {
        this.view = view ?? throw new System.ArgumentNullException(nameof(view));
        userSession = UserSessionManager.Instance;
        resultActivityService = new ResultActivityService();
    }

    /// <summary>
    /// Carga la informacion del usuario actual y la envia a la vista.
    /// </summary>
    public void LoadUserData()
    {
        if (userSession == null || userSession.CurrentUser == null)
        {
            view.ShowErrorMessage("No hay usuario en sesion.");
            return;
        }

        string userName = userSession.CurrentUser.name;
        string roleName = GetRoleName(userSession.CurrentUser.id_role);
        string degreeName = GetDegreeName(userSession.CurrentUser.id_degree);
        int totalStars = GetTotalStars(userSession.CurrentUser.id_user);

        view.DisplayUserData(userName, roleName, degreeName, totalStars);
    }

    /// <summary>
    /// Traduce el identificador de rol a una etiqueta legible para UI.
    /// </summary>
    private string GetRoleName(int roleId)
    {
        return roleId == 1 ? "Estudiante" : roleId == 2 ? "Profesor" : "Desconocido";
    }

    /// <summary>
    /// Resuelve el nombre del grado a partir de su identificador.
    /// </summary>
    private string GetDegreeName(int degreeId)
    {
        var degreeService = new DegreeService();
        var degree = degreeService.GetDegreeById(degreeId);
        return degree != null ? degree.name : "Grado desconocido";
    }

    /// <summary>
    /// Obtiene el acumulado de estrellas del usuario autenticado.
    /// </summary>
    private int GetTotalStars(int userId)
    {
        try
        {
            return resultActivityService.GetTotalStarsForUser(userId);
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"Error obteniendo estrellas del usuario: {ex.Message}");
            return 0;
        }
    }
}
