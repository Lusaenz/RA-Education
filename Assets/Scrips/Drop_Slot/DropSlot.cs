using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;

public class DropSlot : MonoBehaviour, IDropHandler
{
    [HideInInspector] public string zoneId;

    [SerializeField] private TMP_Text labelText;

    public void SetupFromData(ZoneData data)
    {
        zoneId = data.id;

        if (labelText != null)
        {
            labelText.text = data.label;
        }
    }

    public void OnDrop(PointerEventData eventData)
    {
        GameObject dragged = DragHandler.objBeingDraged;
        if (dragged == null)
        {
            return;
        }

        DragHandler dragScript = dragged.GetComponent<DragHandler>();
        if (dragScript == null)
        {
            return;
        }

        if (dragScript.correctZone == zoneId)
        {
            if (SoundManager.instance != null)
            {
                SoundManager.instance.PlayCorrect();
            }

            if (GameManager.instance != null)
            {
                GameManager.instance.RespuestaCorrecta();
            }

            dragged.transform.SetParent(transform);
            dragged.transform.position = transform.position;

            CanvasGroup cg = dragged.GetComponent<CanvasGroup>();
            if (cg != null)
            {
                cg.blocksRaycasts = true;
            }

            dragScript.OnCorrectDrop(gameObject);
        }
        else
        {
            if (SoundManager.instance != null)
            {
                SoundManager.instance.PlayWrong();
            }

            if (GameManager.instance != null)
            {
                GameManager.instance.RespuestaIncorrecta();
            }
        }
    }
}
