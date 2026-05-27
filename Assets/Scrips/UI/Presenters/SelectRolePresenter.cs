using UnityEngine.SceneManagement;

/// <summary>
/// Presenter minimo para navegar a la pantalla de login unificada segun el rol elegido.
/// Ambos roles redireccionan a la misma escena "Login" que se configura dinamicamente.
/// </summary>
public class SelectRolePresenter
{
    private const string LOGIN_SCENE = "Login";

    /// <summary>
    /// Navega al login unificado para estudiantes.
    /// </summary>
    public void GoStudentLogin()
    {
        SceneManager.LoadScene(LOGIN_SCENE);
    }

    /// <summary>
    /// Navega al login unificado para profesores.
    /// </summary>
    public void GoTeacherLogin()
    {
        SceneManager.LoadScene(LOGIN_SCENE);
    }
}
