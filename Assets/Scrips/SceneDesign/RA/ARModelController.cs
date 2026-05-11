using UnityEngine;
using UnityEngine.EventSystems;

public class ARModelControllerPro : MonoBehaviour
{
    [Header("Rotation")]
    public float rotationSpeed = 0.2f;
    public float smoothSpeed = 10f;

    [Header("Zoom")]
    public float zoomSpeed = 0.5f;
    public float minScale = 0.8f;
    public float maxScale = 4f;

    [Header("Look At Camera (suave)")]
    [Range(0f, 1f)]
    public float lookWeight = 0.3f;      // cuánto “mira” a la cámara (0–1)
    public float lookSmooth = 6f;        // suavizado de esa mirada
    public float maxPitch = 25f;         // límite de inclinación vertical (grados)

    private float targetRotationY;
    private float currentRotationY;

    private Vector3 initialLocalPos;
    private float currentPitch;          // inclinación actual (X)

    void Start()
    {
        initialLocalPos = transform.localPosition;
        currentRotationY = transform.localEulerAngles.y;
        targetRotationY = currentRotationY;
    }

    void Update()
    {
        if (IsTouchOverUI()) return;

        HandleRotationInput();
        HandleZoom();
    }

    void LateUpdate()
    {
        SmoothTransform();
    }

    // ---------------- ROTACIÓN ----------------

    void HandleRotationInput()
    {
        // Mouse
        if (Input.GetMouseButton(0))
        {
            targetRotationY += Input.GetAxis("Mouse X") * rotationSpeed * 200f;
        }

        // Touch
        if (Input.touchCount == 1)
        {
            Touch t = Input.GetTouch(0);
            if (t.phase == TouchPhase.Moved)
            {
                targetRotationY += t.deltaPosition.x * rotationSpeed;
            }
        }

        targetRotationY = NormalizeAngle(targetRotationY);
    }

    void SmoothTransform()
    {
        // 1) Rotación base en Y (360°)
        currentRotationY = Mathf.LerpAngle(currentRotationY, targetRotationY, Time.deltaTime * smoothSpeed);

        // 2) Cálculo de inclinación hacia cámara (solo pitch)
        float targetPitch = 0f;

        if (Camera.main != null)
        {
            Vector3 toCam = Camera.main.transform.position - transform.position;

            // Proyectamos para obtener ángulo vertical (pitch)
            float verticalAngle = Vector3.SignedAngle(
                Vector3.ProjectOnPlane(toCam, transform.right), // referencia
                toCam,
                transform.right
            );

            // Limitamos y ponderamos
            targetPitch = Mathf.Clamp(verticalAngle, -maxPitch, maxPitch) * lookWeight;
        }

        // Suavizamos la inclinación
        currentPitch = Mathf.Lerp(currentPitch, targetPitch, Time.deltaTime * lookSmooth);

        // 3) Aplicamos rotación final (solo X + Y)
        transform.localRotation = Quaternion.Euler(currentPitch, currentRotationY, 0f);

        // 4) Posición fija (no deriva)
        transform.localPosition = initialLocalPos;
    }

    // ---------------- ZOOM ----------------

    void HandleZoom()
    {
        float zoomInput = 0f;

        float scroll = Input.GetAxis("Mouse ScrollWheel");
        if (scroll != 0) zoomInput = scroll;

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
        Vector3 newScale = transform.localScale + Vector3.one * increment * zoomSpeed;
        float clamped = Mathf.Clamp(newScale.x, minScale, maxScale);

        transform.localScale = new Vector3(clamped, clamped, clamped);

        // asegurar estabilidad
        transform.localPosition = initialLocalPos;
    }

    // ---------------- UTILS ----------------

    float NormalizeAngle(float angle)
    {
        angle %= 360f;
        if (angle < 0) angle += 360f;
        return angle;
    }

    bool IsTouchOverUI()
    {
        if (Input.GetMouseButton(0))
        {
            if (EventSystem.current.IsPointerOverGameObject())
                return true;
        }

        if (Input.touchCount > 0)
        {
            Touch t = Input.GetTouch(0);
            if (EventSystem.current.IsPointerOverGameObject(t.fingerId))
                return true;
        }

        return false;
    }
}