using UnityEngine;
using UnityEngine.EventSystems;

public class IslandInteraction : MonoBehaviour
{
    public GameObject bookSystem;
    public GameObject canvasTopHUD;
    public GameObject canvasBottomInfo;
    public UIVisualizer visualizador;

    [Header("Module Configuration")]
    [SerializeField] private int moduleId;
    //LayerMask layerMask;

    void Update()
    {
        //evento nop-click pc
        if (EventSystem.current.IsPointerOverGameObject())
        {
            return; 
        }

        //evento nop-touch cel
        if (Input.touchCount > 0)
        {
            Touch toque = Input.GetTouch(0);
            if (EventSystem.current.IsPointerOverGameObject(toque.fingerId))
            {
                return; 
            }
        }
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);

            if (touch.phase == TouchPhase.Began)
            {
                CheckHit(touch.position);
            }
        }

        if (Input.GetMouseButtonDown(0))
        {
            CheckHit(Input.mousePosition);
        }
    }

    void CheckHit(Vector2 position)
    {
        Ray ray = Camera.main.ScreenPointToRay(position);
        RaycastHit hit;

        if (Physics.Raycast(ray, out hit))
        {
            if (hit.transform == transform || hit.transform.IsChildOf(transform))
{
    OpenBook();
}
        }
    }

    void OpenBook()
    {
        Debug.Log($"Isla tocada (ID Módulo: {moduleId})");
        
        // Consultar el nombre del módulo en la base de datos
        if (EstadoManager.Instance != null)
        {
            EstadoManager.Instance.GetAndLogModuleName(moduleId);
        }
        
        if (visualizador != null)
        {
            visualizador.MostrarModulo(moduleId);
        }
        else 
        {
            visualizador = FindFirstObjectByType<UIVisualizer>();
            if(visualizador != null) visualizador.MostrarModulo(moduleId);
        }

        canvasTopHUD.SetActive(false);
        canvasBottomInfo.SetActive(false);
        bookSystem.SetActive(true);
    }
}
