/// <summary>
/// Contrato minimo que debe implementar la vista de inicio del profesor.
/// </summary>
public interface IHomeTeacherView
{
    void DisplayTeacherData(string welcomeMessage);
    void ShowErrorMessage(string message);
}
