/// <summary>
/// Presenter de la pantalla de inicio del profesor.
/// Lee la sesion activa y entrega solo datos propios del profesor a la vista.
/// </summary>
public class HomeTeacherPresenter
{
    private readonly IHomeTeacherView view;
    private readonly UserSessionManager userSession;

    public HomeTeacherPresenter(IHomeTeacherView view)
    {
        this.view = view ?? throw new System.ArgumentNullException(nameof(view));
        userSession = UserSessionManager.Instance;
    }

    /// <summary>
    /// Carga los datos del profesor autenticado y los envia a la vista.
    /// </summary>
    public void LoadTeacherData()
    {
        if (userSession == null || userSession.CurrentUser == null)
        {
            view.ShowErrorMessage("No hay usuario en sesion.");
            return;
        }

        string welcomeMessage = $"Bienvenid@ Profe {userSession.CurrentUser.name}";
        view.DisplayTeacherData(welcomeMessage);
    }
}
