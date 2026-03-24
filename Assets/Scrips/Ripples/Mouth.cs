using UnityEngine;
using UnityEngine.EventSystems;

public class Mouth : MonoBehaviour, IDropHandler
{
        public GameManagerFood gameManager;
public void OnDrop(PointerEventData eventData)
    {
        GameObject objeto = eventData.pointerDrag;

        if(objeto != null)
        {
            DragHandler item = objeto.GetComponent<DragHandler>();

            if(item != null)
            {
                gameManager.EvaluarItem(item.id);
            }
        }
    }
}

