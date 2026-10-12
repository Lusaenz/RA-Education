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

    // Si estos campos se dejan vacíos en el Inspector, se buscan automáticamente
    // en la escena por el nombre del GameObject (ver AutoAssignReferences).
    [Header("Ranking")]
    [SerializeField] private TextMeshProUGUI studentNameText;      // "StudentName"
    [SerializeField] private TextMeshProUGUI acquiredPositionText; // "AcquiredPosition"
    [SerializeField] private TextMeshProUGUI centerPositionText;   // "Position1" (escalón central, el estudiante)
    [SerializeField] private TextMeshProUGUI leftPositionText;     // "Position2" (escalón izquierdo, puesto anterior)
    [SerializeField] private TextMeshProUGUI rightPositionText;    // "Position3" (escalón derecho, puesto siguiente)
    [SerializeField] private GameObject leftStair;                 // "Stair2"
    [SerializeField] private GameObject rightStair;                // "Stair3"

    [Header("Tiempo de finalización")]
    [SerializeField] private TextMeshProUGUI cellTimeText;         // "CellTime/Minutes (1)"
    [SerializeField] private TextMeshProUGUI digestiveTimeText;    // "DigestiveSystemTime/Minutes"

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

        // Ranking (null o vacío = ocultar ese escalón)
        public string StudentName { get; set; }
        public string AcquiredPosition { get; set; }
        public string CenterPosition { get; set; }
        public string LeftPosition { get; set; }
        public string RightPosition { get; set; }

        // Tiempos
        public string CellTime { get; set; }
        public string DigestiveTime { get; set; }
    }

    private void Awake()
    {
        AutoAssignReferences();
    }

    /// <summary>
    /// Muestra los datos formateados del usuario en la UI.
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

        DisplayText(studentNameText, data.StudentName, "studentNameText");
        DisplayText(acquiredPositionText, data.AcquiredPosition, "acquiredPositionText");
        DisplayText(centerPositionText, data.CenterPosition, "centerPositionText");
        DisplayStair(leftStair, leftPositionText, data.LeftPosition);
        DisplayStair(rightStair, rightPositionText, data.RightPosition);

        DisplayText(cellTimeText, data.CellTime, "cellTimeText");
        DisplayText(digestiveTimeText, data.DigestiveTime, "digestiveTimeText");

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

        textField.text = text ?? string.Empty;
    }

    /// <summary>
    /// Muestra un escalón lateral del podio solo si hay un puesto para mostrar.
    /// </summary>
    private void DisplayStair(GameObject stair, TextMeshProUGUI positionText, string value)
    {
        bool visible = !string.IsNullOrEmpty(value);

        if (stair != null)
            stair.SetActive(visible);

        if (positionText != null)
        {
            positionText.gameObject.SetActive(visible);
            positionText.text = value ?? string.Empty;
        }
    }

    // ---------------------------------------------------------------------
    // Asignación automática por nombre (solo para los campos vacíos)
    // ---------------------------------------------------------------------

    private void AutoAssignReferences()
    {
        studentNameText      = studentNameText      != null ? studentNameText      : FindText("StudentName");
        acquiredPositionText = acquiredPositionText != null ? acquiredPositionText : FindText("AcquiredPosition");
        centerPositionText   = centerPositionText   != null ? centerPositionText   : FindText("Position1");
        leftPositionText     = leftPositionText     != null ? leftPositionText     : FindText("Position2");
        rightPositionText    = rightPositionText    != null ? rightPositionText    : FindText("Position3");
        leftStair            = leftStair            != null ? leftStair            : FindObject("Stair2");
        rightStair           = rightStair           != null ? rightStair           : FindObject("Stair3");
        cellTimeText         = cellTimeText         != null ? cellTimeText         : FindText("Minutes (1)", "CellTime");
        digestiveTimeText    = digestiveTimeText    != null ? digestiveTimeText    : FindText("Minutes", "DigestiveSystemTime");
    }

    /// <summary>
    /// Busca un TextMeshProUGUI por nombre (ignorando espacios al inicio/final).
    /// Si se indica parentName, el padre directo también debe coincidir.
    /// </summary>
    private static TextMeshProUGUI FindText(string objectName, string parentName = null)
    {
        TextMeshProUGUI[] all = FindObjectsByType<TextMeshProUGUI>(FindObjectsInactive.Include, FindObjectsSortMode.None);

        foreach (TextMeshProUGUI t in all)
        {
            if (t.gameObject.name.Trim() != objectName)
                continue;

            if (parentName != null &&
                (t.transform.parent == null || t.transform.parent.name.Trim() != parentName))
                continue;

            return t;
        }

        Debug.LogWarning($"[UserScreenView] No se encontró el texto '{objectName}' en la escena.");
        return null;
    }

    private static GameObject FindObject(string objectName)
    {
        RectTransform[] all = FindObjectsByType<RectTransform>(FindObjectsInactive.Include, FindObjectsSortMode.None);

        foreach (RectTransform rt in all)
        {
            if (rt.gameObject.name.Trim() == objectName)
                return rt.gameObject;
        }

        Debug.LogWarning($"[UserScreenView] No se encontró el objeto '{objectName}' en la escena.");
        return null;
    }
}
