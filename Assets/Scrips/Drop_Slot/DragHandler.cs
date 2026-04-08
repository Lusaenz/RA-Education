using System.Collections;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.UI;

// ─────────────────────────────────────────────
//  DragHandler.cs
//  Adjuntar a cada uno de los 4 items que ya
//  están en la escena.
//
//  Cambios respecto al original:
//  - Se agrega itemId y correctZone (el DropSlot
//    compara correctZone en lugar de referencia)
//  - Se agrega SetupFromData() y SetSprite()
//    llamados por el GameManager al iniciar
//  - El drag, animación y OnCorrectDrop
//    funcionan IGUAL que antes
// ─────────────────────────────────────────────

public class DragHandler : MonoBehaviour, IDragHandler, IBeginDragHandler, IEndDragHandler
{
    public static GameObject objBeingDraged;

    // Asignados por GameManager.SetupFromData()
    // No se asignan en el Inspector
    [HideInInspector] public string itemId;
    [HideInInspector] public string correctZone;

    // Asignar en el Inspector: el Image del mismo GameObject
    [SerializeField] private Image itemImage;

    private Vector3    startPosition;
    private Transform  startParent;
    private CanvasGroup canvasGroup;
    private Transform  itemDraggerParent;
    private Animator   anim;
    private bool       yaSeUso = false;
    private GameObject slotParaDestruir;

    // ── Llamados por GameManager al iniciar ──────────────────────────────

    public void SetupFromData(ItemData data)
    {
        itemId      = data.id;
        correctZone = data.correct_zone;
    }

    public void SetSprite(Sprite sprite)
    {
        if (itemImage != null)
            itemImage.sprite = sprite;
    }

    // ── Inicialización ───────────────────────────────────────────────────

    private void Start()
    {
        canvasGroup       = GetComponent<CanvasGroup>();
        itemDraggerParent = GameObject.FindGameObjectWithTag("ItemDraggerParent").transform;
        anim              = GetComponent<Animator>();
    }

    // ── Drag (igual que antes) ───────────────────────────────────────────

    public void OnBeginDrag(PointerEventData eventData)
    {
        objBeingDraged = gameObject;
        startPosition  = transform.position;
        startParent    = transform.parent;
        transform.SetParent(itemDraggerParent);
        transform.SetAsLastSibling();
        canvasGroup.blocksRaycasts = false;
    }

    public void OnDrag(PointerEventData eventData)
    {
        transform.position = Input.mousePosition;
    }

    public void OnEndDrag(PointerEventData eventData)
    {
        objBeingDraged             = null;
        canvasGroup.blocksRaycasts = true;

        if (yaSeUso) return;

        if (transform.parent == itemDraggerParent)
        {
            transform.position = startPosition;
            transform.SetParent(startParent);
        }
    }

    // ── Animación de acierto (igual que antes) ───────────────────────────

    public void OnCorrectDrop(GameObject slot)
    {
        if (yaSeUso) return;
        yaSeUso          = true;
        slotParaDestruir = slot;
        StartCoroutine(PlayAndDisappear());
    }

    IEnumerator PlayAndDisappear()
    {
        anim.ResetTrigger("Correct");
        anim.SetTrigger("Correct");

        yield return null;
        yield return null;

        float duracion = anim.GetCurrentAnimatorStateInfo(0).length;
        yield return new WaitForSeconds(duracion);

        if (slotParaDestruir != null)
            slotParaDestruir.SetActive(false);

        Destroy(gameObject);
    }
}