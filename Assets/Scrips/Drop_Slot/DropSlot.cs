using UnityEngine;
using UnityEngine.EventSystems;
using TMPro;

// ─────────────────────────────────────────────
//  DropSlot.cs
//  Adjuntar a cada uno de los 4 Canvas de zonas
//  que ya están en la escena.
//
//  Cambios respecto al original:
//  - Se agrega zoneId y SetupFromData()
//    llamados por el GameManager al iniciar
//  - La validación compara dragScript.correctZone == zoneId
//    en lugar de dragged == item
//  - SoundManager y GameManager se llaman IGUAL
// ─────────────────────────────────────────────

public class DropSlot : MonoBehaviour, IDropHandler
{
    // Asignado por GameManager.SetupFromData()
    // No se asigna en el Inspector
    [HideInInspector] public string zoneId;

    // Asignar en el Inspector: el TMP_Text que muestra la descripción
    [SerializeField] private TMP_Text labelText;

    // ── Llamado por GameManager al iniciar ───────────────────────────────

    public void SetupFromData(ZoneData data)
    {
        zoneId = data.id;

        if (labelText != null)
            labelText.text = data.label;
    }

    // ── Drop (lógica igual que antes, solo cambia la validación) ─────────

    public void OnDrop(PointerEventData eventData)
    {
        GameObject dragged = DragHandler.objBeingDraged;
        if (dragged == null) return;

        DragHandler dragScript = dragged.GetComponent<DragHandler>();
        if (dragScript == null) return;

        if (dragScript.correctZone == zoneId)
        {
            SoundManager.instance.PlayCorrect();

            if (GameManager.instance != null)
                GameManager.instance.RespuestaCorrecta();

            dragged.transform.SetParent(transform);
            dragged.transform.position = transform.position;

            var cg = dragged.GetComponent<CanvasGroup>();
            if (cg != null) cg.blocksRaycasts = true;

            dragScript.OnCorrectDrop(gameObject);
        }
        else
        {
            SoundManager.instance.PlayWrong();

            if (GameManager.instance != null)
                GameManager.instance.RespuestaIncorrecta();
        }
    }
}