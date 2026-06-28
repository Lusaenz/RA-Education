
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// Vista para mostrar el perfil/datos del usuario autenticado.
/// SOLO es responsable de mostrar datos en la UI. No obtiene ni procesa datos.
/// El coordinador (UserScreenManager) se encarga de obtener y formatear datos.
/// Sigue arquitectura MVP correcta.
/// </summary>
public class UserScreenView : MonoBehaviour
{
    [SerializeField] private TextMeshProUGUI userNameText;
    [SerializeField] private TextMeshProUGUI roleTypeText;
    [SerializeField] private TextMeshProUGUI degreeText;
    [SerializeField] private TextMeshProUGUI totalStarsText;
    [SerializeField] private TextMeshProUGUI dayLastLoginText;
    [SerializeField] private TextMeshProUGUI dateLastLoginText;

    /// <summary>
    /// Datos formateados listos para mostrar en UI.
    /// </summary>
    public class FormattedUserData
    {
        public string UserName { get; set; }
        public string RoleName { get; set; }
        public string DegreeName { get; set; }
        public string TotalStars { get; set; }
        public string DayLastLogin { get; set; }
        public string DateLastLogin { get; set; }
    }

    /// <summary>
    /// Muestra los datos formateados del usuario en la UI.
    /// Este es el ÚNICO método público que la vista expone.
    /// </summary>
    public void DisplayUserData(FormattedUserData data)
    {
        if (data == null)
        {
            Debug.LogError("[UserScreenView] FormattedUserData es nulo");
            return;
        }

        DisplayText(userNameText, data.UserName, "userNameText");
        DisplayText(roleTypeText, data.RoleName, "roleTypeText");
        DisplayText(degreeText, data.DegreeName, "degreeText");
        DisplayText(totalStarsText, data.TotalStars, "totalStarsText");
        DisplayText(dayLastLoginText, data.DayLastLogin, "dayLastLoginText");
        DisplayText(dateLastLoginText, data.DateLastLogin, "dateLastLoginText");

        Debug.Log($"[UserScreenView] Datos mostrados para usuario: {data.UserName}");
    }

    /// <summary>
    /// Muestra un mensaje de error en la pantalla.
    /// </summary>
    public void DisplayError(string errorMessage)
    {
        DisplayText(userNameText, errorMessage, "userNameText");
        Debug.LogError($"[UserScreenView] Error: {errorMessage}");
    }

    private void DisplayText(TextMeshProUGUI textField, string text, string fieldName)
    {
        if (textField == null)
        {
            Debug.LogWarning($"[UserScreenView] {fieldName} no está asignado");
            return;
        }

        textField.text = text;
    }
}