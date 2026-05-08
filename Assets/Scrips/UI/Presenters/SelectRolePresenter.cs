using UnityEngine.SceneManagement;

/// <summary>
/// Presenter minimo para navegar a la pantalla de login segun el rol elegido.
/// </summary>
public class SelectRolePresenter
{
    /// <summary>
    /// Navega al login de estudiantes.
    /// </summary>
    public void GoStudentLogin()
    {
        SceneManager.LoadScene("LoginStudent");
    }

    /// <summary>
    /// Navega al login de profesores.
    /// </summary>
    public void GoTeacherLogin()
    {
        SceneManager.LoadScene("LoginTeacher");
    }
}
