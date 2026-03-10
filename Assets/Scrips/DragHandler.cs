using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

public class DragHandler : MonoBehaviour, IDragHandler, IBeginDragHandler, IEndDragHandler
{
    public static GameObject objBeingDraged;

    private Vector3 startPosition;
    private Transform startParent;
    private CanvasGroup canvasGroup;
    private Transform itemDraggerParent;

    private Animator anim;
    private bool yaSeUso = false;

    private GameObject slotParaDestruir;

    private void Start() 
    {
        
        canvasGroup = GetComponent<CanvasGroup>();
        itemDraggerParent = GameObject.FindGameObjectWithTag("ItemDraggerParent").transform;
        anim = GetComponent<Animator>();

        Debug.Log("Animator encontrado: " + anim);
    }

    #region DragFunctions

    public void OnBeginDrag(PointerEventData eventData)
    {
        Debug.Log("OnBeginDrag");
        objBeingDraged = gameObject;

        startPosition = transform.position;
        startParent = transform.parent;
        transform.SetParent(itemDraggerParent);

        canvasGroup.blocksRaycasts = false;

    }

    public void OnDrag(PointerEventData eventData)
    {
        transform.position = Input.mousePosition;
    }

    public void OnEndDrag(PointerEventData eventData)
{
    Debug.Log("OnEndDrag");
    objBeingDraged = null;

    canvasGroup.blocksRaycasts = true;

    // 🛑 si ya fue colocado correctamente, NO regresar
    if (yaSeUso) return;

    if (transform.parent == itemDraggerParent)
    {
        transform.position = startPosition;
        transform.SetParent(startParent);
    }
}

    public void OnCorrectDrop(GameObject slot)
{
    if (yaSeUso) return;
    yaSeUso = true;

    slotParaDestruir = slot;
    StartCoroutine(PlayAndDisappear());
}

IEnumerator PlayAndDisappear()
{
    Debug.Log("Trigger enviado");

    anim.ResetTrigger("Correct");
    anim.SetTrigger("Correct");

    // esperar a que cambie de estado
    yield return null;
    yield return null;

    // esperar la animación
    float duracion = anim.GetCurrentAnimatorStateInfo(0).length;
    yield return new WaitForSeconds(duracion);

    // 🔥 ahora sí desaparecen ambos
    if (slotParaDestruir != null)
        slotParaDestruir.SetActive(false);

    Destroy(gameObject);
}
    #endregion

    private void Update()
    {

    }
}