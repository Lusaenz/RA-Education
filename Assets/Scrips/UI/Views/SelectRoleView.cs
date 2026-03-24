using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

/// <summary>
/// Vista de seleccion de rol.
/// Traduce clicks sobre tarjetas visuales a acciones del presenter.
/// </summary>
public class SelectRoleView : MonoBehaviour
{
    SelectRolePresenter selectRolePresenter = new SelectRolePresenter();

    public Image CardStudentPanel;
    public Image CardTeacherPanel;

    /// <summary>
    /// Crea los disparadores de evento para cada tarjeta visible.
    /// </summary>
    private void OnEnable()
    {
        if (CardStudentPanel != null)
        {
            EventTrigger studentTrigger = CardStudentPanel.GetComponent<EventTrigger>();
            if (studentTrigger == null)
                studentTrigger = CardStudentPanel.gameObject.AddComponent<EventTrigger>();
            
            AddEventTrigger(studentTrigger, EventTriggerType.PointerClick, OnStudentPanelClicked);
        }
        
        if (CardTeacherPanel != null)
        {
            EventTrigger teacherTrigger = CardTeacherPanel.GetComponent<EventTrigger>();
            if (teacherTrigger == null)
                teacherTrigger = CardTeacherPanel.gameObject.AddComponent<EventTrigger>();
            
            AddEventTrigger(teacherTrigger, EventTriggerType.PointerClick, OnTeacherPanelClicked);
        }
    }

    /// <summary>
    /// Registra un callback para un evento de Unity UI.
    /// </summary>
    private void AddEventTrigger(EventTrigger trigger, EventTriggerType eventType, UnityEngine.Events.UnityAction<BaseEventData> callback)
    {
        EventTrigger.Entry entry = new EventTrigger.Entry();
        entry.eventID = eventType;
        entry.callback.AddListener(callback);
        trigger.triggers.Add(entry);
    }

    /// <summary>
    /// Handler del click sobre la tarjeta de estudiante.
    /// </summary>
    public void OnStudentPanelClicked(BaseEventData data)
    {
        StudentPressed();
    }

    /// <summary>
    /// Handler del click sobre la tarjeta de profesor.
    /// </summary>
    public void OnTeacherPanelClicked(BaseEventData data)
    {
        TeacherPressed();
    }

    /// <summary>
    /// Navega al login de estudiantes.
    /// </summary>
    public void StudentPressed()
    {
        selectRolePresenter.GoStudentLogin();
    }

    /// <summary>
    /// Navega al login de profesores.
    /// </summary>
    public void TeacherPressed()
    {
        selectRolePresenter.GoTeacherLogin();
    }
}
