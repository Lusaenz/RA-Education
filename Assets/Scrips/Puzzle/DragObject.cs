using UnityEngine;

public class DragObject : MonoBehaviour
{
    private Camera arCamera;
    private bool isDragging = false;
    private Vector3 offset;
    private float zDistance;
    private bool isPlaced = false;

    void Start()
    {
        arCamera = Camera.main;
    }

    void Update()
    {
        // TOUCH
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);
            HandleInput(touch.position, touch.phase);
        }

        // MOUSE
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
        RaycastHit hit;

        if (phase == TouchPhase.Began)
        {
            if (Physics.Raycast(ray, out hit))
            {
                if (hit.transform == transform)
                {
                    isDragging = true;

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

            // OBJETO A MOVER
            Transform objectToMove = transform;

            // SI PERTENECE A UN GRUPO, MOVER EL GRUPO
            if (transform.parent != null &&
                transform.parent.name.StartsWith("Group"))
            {
                objectToMove = transform.parent;
            }

            objectToMove.position = inputWorld + offset;
        }

        if (phase == TouchPhase.Ended)
        {
            isDragging = false;
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
}