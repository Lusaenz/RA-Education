using UnityEngine;

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
        // TOUCH (movil)
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);

            if (touch.phase == TouchPhase.Began)
            {
                CheckHit(touch.position);
            }
        }

        // MOUSE (editor Unity)
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

        PlayerPrefs.SetInt("selected_module_id", moduleId);
        PlayerPrefs.SetInt("selected_activity_id", moduleId);
        PlayerPrefs.Save();
        
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
