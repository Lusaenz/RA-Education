using UnityEngine;

public class DragObject : MonoBehaviour
{
    private Camera arCamera;
    private bool isDragging = false;
    private Vector3 offset;
    private float zDistance;
    private bool isPlaced = false;
    private PuzzlePieceInfo info;
    private SnapPiece snapPiece;
    
    private TagPointInfo[] snapPoints;
private TagPointInfo ultimoSnap;

    

    void Start()
{
    arCamera = Camera.main;
    info = GetComponent<PuzzlePieceInfo>();
    snapPiece = GetComponent<SnapPiece>();
    snapPoints = FindObjectsByType<TagPointInfo>(FindObjectsSortMode.None);
}

    void Update()
    {

        // TOUCH
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);
            HandleInput(touch.position, touch.phase);
            // En el celular Unity tambien simula el mouse con el toque; sin este
            // return la misma entrada se procesaba dos veces por frame.
            return;
        }

        if (Input.GetMouseButtonDown(0))
        {
            HandleInput(Input.mousePosition, TouchPhase.Began);
        }
        else if (Input.GetMouseButton(0))
        {
            HandleInput(Input.mousePosition, TouchPhase.Moved);
        }
        else if (Input.GetMouseButtonUp(0))
        {
            HandleInput(Input.mousePosition, TouchPhase.Ended);
        }
    }

    void HandleInput(Vector2 inputPosition, TouchPhase phase)
    {
        Ray ray = arCamera.ScreenPointToRay(inputPosition);

        if (phase == TouchPhase.Began)
        {
            RaycastHit[] hits = Physics.RaycastAll(ray);

            // Solo se arrastra la pieza mas cercana al rayo; antes se tomaban
            // todas las piezas superpuestas a la vez.
            DragObject closest = null;
            float closestDistance = float.MaxValue;

            foreach (RaycastHit hit in hits)
            {
                DragObject drag = hit.collider.GetComponentInParent<DragObject>();

                if (drag != null && drag.enabled && hit.distance < closestDistance)
                {
                    closestDistance = hit.distance;
                    closest = drag;
                }
            }

            if (closest == this)
            {
                isDragging = true;
                if (info != null && PuzzleManager.instance != null)
{
    PuzzleManager.instance.MostrarNombre(info.nombrePieza);
}

if (MembraneVisibility.Instance != null)
{
    MembraneVisibility.Instance.Hide();
}


                zDistance = arCamera.WorldToScreenPoint(transform.position).z;

                Vector3 inputWorld = arCamera.ScreenToWorldPoint(
                    new Vector3(
                        inputPosition.x,
                        inputPosition.y,
                        zDistance
                    )
                );

                offset = transform.position - inputWorld;
            }
        }

        if (phase == TouchPhase.Moved && isDragging && !isPlaced)
        {
            Vector3 inputWorld = arCamera.ScreenToWorldPoint(
                new Vector3(
                    inputPosition.x,
                    inputPosition.y,
                    zDistance
                )
            );

            
            transform.position = inputWorld + offset;
            DetectarSnapPointCercano();
        }

        if (phase == TouchPhase.Ended)
        {
            if (!isDragging)
                return;

            isDragging = false;

            if (PuzzleManager.instance != null)
{
    PuzzleManager.instance.OcultarNombre();
    ultimoSnap = null;
}

  if (MembraneVisibility.Instance != null)
{
    MembraneVisibility.Instance.Show();
}

            SnapPiece snap = snapPiece;

            if (snap != null)
            {
                snap.TrySnap();
                 if (snap.IsSnapped())
{
    PuzzleManager.instance.OcultarTarget();
    ultimoSnap = null;
}

                if (!snap.IsSnapped())
                {
                    PuzzleManager.instance.ItemIncorrecto();
                   
                }
            }
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        

    
        if (other.CompareTag("Zona"))
        {
            Debug.Log("Objeto colocado correctamente");

            isDragging = false;

            transform.position = other.transform.position;

            isPlaced = true;
        }
    }

    private void OnTriggerExit(Collider other)
{
    TagPointInfo info = other.GetComponent<TagPointInfo>();

    
}

void DetectarSnapPointCercano()
{
    // Se mide igual que SnapPiece.TrySnap (desde el snapPoint de la pieza y con la
    // misma distancia en pantalla) para que el "Objetivo" mostrado sea el que encaja.
    Vector3 origen = snapPiece != null && snapPiece.snapPoint != null
        ? snapPiece.snapPoint.position
        : transform.position;
    float distanciaMinima = snapPiece != null ? snapPiece.snapDistance : 0.07f;
    TagPointInfo masCercano = null;

    foreach (TagPointInfo punto in snapPoints)
    {
        float distancia = SnapPiece.ScreenAlignedDistance(origen, punto.transform.position);

        if (distancia < distanciaMinima)
        {
            distanciaMinima = distancia;
            masCercano = punto;
        }
    }

    if (masCercano != ultimoSnap)
    {
        ultimoSnap = masCercano;

        if (masCercano != null)
            PuzzleManager.instance.MostrarTarget(masCercano.nombre);
            
        else
            PuzzleManager.instance.OcultarTarget();
            
    }
    masCercano = null;
    
}

    
} 