using UnityEngine;

/// <summary>
/// Presenter del flujo inicial posterior al login.
/// Lee la sesion activa y transforma datos del usuario a texto listo para la vista.
/// </summary>
public class TestInitialUserFlowPresenter
{
    private ITestInitialUserFlowView view;
    private UserSessionManager userSession;

    public TestInitialUserFlowPresenter(ITestInitialUserFlowView view)
    {
        this.view = view ?? throw new System.ArgumentNullException(nameof(view));
        this.userSession = UserSessionManager.Instance;
    }

    /// <summary>
    /// Carga la informacion del usuario actual y la envia a la vista.
    /// </summary>
    public void LoadUserData()
    {
        if (userSession == null || userSession.CurrentUser == null)
        {
            view.ShowErrorMessage("No hay usuario en sesión.");
            return;
        }

        string userName = userSession.CurrentUser.name;
        string roleName = GetRoleName(userSession.CurrentUser.id_role);
        string degreeName = GetDegreeName(userSession.CurrentUser.id_degree);

        view.DisplayUserData(userName, roleName, degreeName);
    }

    /// <summary>
    /// Traduce el identificador de rol a una etiqueta legible para UI.
    /// </summary>
    private string GetRoleName(int roleId)
    {
        // 1 = Student, 2 = Teacher (ajusta según tu BD)
        return roleId == 1 ? "Estudiante" : roleId == 2 ? "Profesor" : "Desconocido";
    }

    /// <summary>
    /// Resuelve el nombre del grado a partir de su identificador.
    /// </summary>
    private string GetDegreeName(int degreeId)
    {
        // Aquí podrías hacer una consulta a la BD para obtener el nombre del grado
        // Por ahora retornamos el ID, pero idealmente querrías consultar la BD
        
        // Opción 1: Consulta simple (si tienes acceso a la BD)
        var degreeService = new DegreeService();
        var degree = degreeService.GetDegreeById(degreeId);
        
        return degree != null ? degree.name : "Grado desconocido";
    }
}
