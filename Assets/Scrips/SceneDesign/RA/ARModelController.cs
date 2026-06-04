using UnityEngine;
using UnityEngine.EventSystems;

public class ARModelControllerPro : MonoBehaviour
{
    [Header("Rotation")]
    public float rotationSpeed = 0.2f;
    public float smoothSpeed = 12f;

    [Header("Zoom")]
    public float zoomSpeed = 0.3f;
    public float minScale = 0.05f;
    public float maxScale = 0.35f;

    [Header("Vertical Rotation Limits")]
    public float minRotationX = -80f;
    public float maxRotationX = 80f;

    // Rotacion
    private float targetRotationY;
    private float currentRotationY;

    private float targetRotationX;
    private float currentRotationX;
    void Start()
    {
        Vector3 angles = transform.localEulerAngles;

        currentRotationY = angles.y;
        targetRotationY = angles.y;

        currentRotationX = angles.x;
        targetRotationX = angles.x;
    }
    void Update()
    {
        if (IsTouchOverUI()) return;

        HandleRotationInput();
        HandleZoom();
    }

    void LateUpdate()
    {
        SmoothRotation();
    }
    // Rotacion
    void HandleRotationInput()
    {
        // Mouse
        if (Input.GetMouseButton(0))
        {
            // Horizontal = Y
            targetRotationY +=
                Input.GetAxis("Mouse X") *
                rotationSpeed *
                400f;

            // Vertical = X
            targetRotationX -=
                Input.GetAxis("Mouse Y") *
                rotationSpeed *
                250f;
        }
        // Touch
        if (Input.touchCount == 1)
        {
            Touch t = Input.GetTouch(0);

            if (t.phase == TouchPhase.Moved)
            {
                // Horizontal
                targetRotationY +=
                    t.deltaPosition.x *
                    rotationSpeed *
                    1.5f;
                // Vertical
                targetRotationX -=
                    t.deltaPosition.y *
                    rotationSpeed *
                    1.2f;
            }
        }
        targetRotationX = Mathf.Clamp(
            targetRotationX,
            minRotationX,
            maxRotationX
        );

        targetRotationY = NormalizeAngle(targetRotationY);
    }
    void SmoothRotation()
    {
        currentRotationY = Mathf.LerpAngle(
            currentRotationY,
            targetRotationY,
            Time.deltaTime * smoothSpeed
        );

        currentRotationX = Mathf.LerpAngle(
            currentRotationX,
            targetRotationX,
            Time.deltaTime * smoothSpeed
        );

        transform.localRotation =
            Quaternion.Euler(
                currentRotationX,
                currentRotationY,
                0f
            );
    }
    // ZOOM
    void HandleZoom()
    {
        float zoomInput = 0f;

        // Mouse wheel
        float scroll = Input.GetAxis("Mouse ScrollWheel");

        if (scroll != 0)
            zoomInput = scroll;

        // Pinch móvil
        if (Input.touchCount == 2)
        {
            Touch t1 = Input.GetTouch(0);
            Touch t2 = Input.GetTouch(1);

            Vector2 prev1 = t1.position - t1.deltaPosition;
            Vector2 prev2 = t2.position - t2.deltaPosition;

            float prevMag = (prev1 - prev2).magnitude;
            float currentMag = (t1.position - t2.position).magnitude;

            zoomInput = (currentMag - prevMag) * 0.001f;
        }

        if (zoomInput != 0)
        {
            ApplyZoom(zoomInput);
        }
    }

    void ApplyZoom(float increment)
    {
        Vector3 newScale =
            transform.localScale +
            Vector3.one * increment * zoomSpeed;

        float clamped = Mathf.Clamp(
            newScale.x,
            minScale,
            maxScale
        );

        transform.localScale =
            new Vector3(
                clamped,
                clamped,
                clamped
            );
    }

    float NormalizeAngle(float angle)
    {
        angle %= 360f;

        if (angle < 0)
            angle += 360f;

        return angle;
    }

    bool IsTouchOverUI()
    {
        // Mouse
        if (Input.GetMouseButton(0))
        {
            if (EventSystem.current.IsPointerOverGameObject())
                return true;
        }

        // Touch
        if (Input.touchCount > 0)
        {
            Touch t = Input.GetTouch(0);

            if (EventSystem.current.IsPointerOverGameObject(t.fingerId))
                return true;
        }

        return false;
    }
}