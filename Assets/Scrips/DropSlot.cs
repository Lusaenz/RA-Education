using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class DropSlot : MonoBehaviour, IDropHandler
{
    // 👉 aquí arrastras en el Inspector el ITEM correcto para este slot
    public GameObject item;

   public void OnDrop(PointerEventData eventData)
{
    Debug.Log("Drop");

    GameObject dragged = DragHandler.objBeingDraged;
    if (dragged == null) return;

    if (dragged == item)
    {
        SoundManager.instance.PlayCorrect();
        Debug.Log("Correcto");
        
         // ⭐ SUMAR PUNTOS
            if (GameManager.instance != null)
                GameManager.instance.RespuestaCorrecta();

            dragged.transform.SetParent(transform);
            dragged.transform.position = transform.position;

        dragged.transform.SetParent(transform);
        dragged.transform.position = transform.position;

        var cg = dragged.GetComponent<CanvasGroup>();
        if (cg != null) cg.blocksRaycasts = true;

        // 🔥 avisar al item y pasarle este slot
        DragHandler dragScript = dragged.GetComponent<DragHandler>();
        if (dragScript != null)
        {
            dragScript.OnCorrectDrop(gameObject);
        }
    }
    else
    {
        SoundManager.instance.PlayWrong();
        Debug.Log("Incorrecto");
        
         // ❌ RESTAR PUNTOS
            if (GameManager.instance != null)
                GameManager.instance.RespuestaIncorrecta();
    }
}


}
