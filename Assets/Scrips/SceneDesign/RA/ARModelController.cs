using System.Collections;
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

    [Header("Rotacion/Zoom de la parte aislada (foco)")]
    [Tooltip("Sensibilidad de rotacion aplicada a la parte mientras esta enfocada/aislada.")]
    public float partRotationSpeed = 0.2f;
    [Tooltip("Sensibilidad de zoom aplicada a la parte mientras esta enfocada/aislada.")]
    public float partZoomSpeed = 0.5f;
    public float partMinScaleMultiplier = 0.6f;
    public float partMaxScaleMultiplier = 2.5f;
    public float partMinRotationX = -80f;
    public float partMaxRotationX = 80f;

    // Rotacion
    private float targetRotationY;
    private float currentRotationY;

    private float targetRotationX;
    private float currentRotationX;

    // Rotacion/zoom de la parte aislada: independientes de las de arriba
    // para que, una vez que solo queda visible la parte seleccionada, el
    // usuario pueda inspeccionarla girandola sobre si misma en vez de sobre
    // el pivote del modelo completo (que la sacaria de cuadro).
    private Transform _focusedPart;
    private Quaternion _partBaseLocalRotation;
    private Vector3 _partBaseLocalScale;
    private float _partTargetRotY, _partCurrentRotY;
    private float _partTargetRotX, _partCurrentRotX;
    private float _partScaleMultiplier = 1f;

    // Solo se acepta input de rotacion/zoom una vez que ESTE target especifico
    // fue encontrado. Sin esto, Update() corria igual para los 3 ImageTargets
    // de la escena aunque solo uno estuviera en camara: cualquier scroll o
    // pinch accidental (ruido de touchpad, por ejemplo) reescalaba tambien los
    // modelos de los otros dos targets que ni siquiera estaban a la vista,
    // dejandolos con un tamaño incorrecto la proxima vez que se encontraban.
    private bool _canInteract;

    // Foco sobre una parte (ver FocusOnPart/ClearFocus): mientras esta activo
    // se ignoran los gestos de rotacion/zoom manuales para no pelear con la
    // animacion, y se recuerda la pose previa para poder restaurarla.
    private bool _isFocused;
    private Vector3 _prevLocalPosition;
    private Vector3 _prevLocalScale;
    private Coroutine _focusRoutine;
    private Camera _arCamera;

void Start()
    {
        SyncRotationFromTransform();

        var handler = GetComponentInParent<DefaultObserverEventHandler>();
        if (handler != null)
            handler.OnTargetFound.AddListener(() => _canInteract = true);
    }

    // Recalcula los angulos base a partir del transform actual.
    // Debe llamarse tras reparentar el modelo (ver ARPartButtonManager),
    // ya que localEulerAngles cambia de significado con el nuevo padre.
    public void SyncRotationFromTransform()
    {
        Vector3 angles = transform.localEulerAngles;

        currentRotationY = angles.y;
        targetRotationY = angles.y;

        currentRotationX = angles.x;
        targetRotationX = angles.x;
    }
    void Update()
    {
        if (!_canInteract) return;
        if (IsTouchOverUI()) return;

        if (_isFocused)
        {
            if (_focusedPart != null)
            {
                HandlePartRotationInput();
                HandlePartZoom();
            }
            return;
        }

        HandleRotationInput();
        HandleZoom();
    }

    void LateUpdate()
    {
        SmoothRotation();
        if (_isFocused && _focusedPart != null)
            SmoothPartRotation();
    }

    // Centra y escala el modelo para que 'part' quede en viewportTarget
    // (0..1, en espacio de viewport de la camara AR) sin tocar la rotacion
    // actual. Se puede llamar varias veces seguidas (cambiar de parte con el
    // panel abierto) sin perder la pose original: solo se guarda como "previa"
    // la primera vez, antes de que arranque el primer foco.
    public void FocusOnPart(Transform part, Vector2 viewportTarget, float zoomMultiplier)
    {
        if (part == null) return;

        if (_arCamera == null && transform.parent != null)
            _arCamera = transform.parent.GetComponent<Camera>();
        if (_arCamera == null) return;

        if (!_isFocused)
        {
            _prevLocalPosition = transform.localPosition;
            _prevLocalScale = transform.localScale;
        }
        _isFocused = true;

        // Si se cambia de parte sin cerrar el panel, se restaura primero la
        // rotacion/escala manual que el usuario le haya aplicado a la parte
        // anterior antes de soltarla.
        if (_focusedPart != null && _focusedPart != part)
        {
            _focusedPart.localRotation = _partBaseLocalRotation;
            _focusedPart.localScale = _partBaseLocalScale;
        }

        if (_focusedPart != part)
        {
            _focusedPart = part;
            _partBaseLocalRotation = part.localRotation;
            _partBaseLocalScale = part.localScale;
            _partTargetRotX = _partCurrentRotX = 0f;
            _partTargetRotY = _partCurrentRotY = 0f;
            _partScaleMultiplier = 1f;
        }

        Transform camTransform = _arCamera.transform;

        float viewDistance = Vector3.Dot(part.position - camTransform.position, camTransform.forward);
        viewDistance = Mathf.Max(viewDistance, _arCamera.nearClipPlane + 0.01f);

        Vector3 targetWorldPoint = _arCamera.ViewportToWorldPoint(
            new Vector3(viewportTarget.x, viewportTarget.y, viewDistance)
        );

        Vector3 worldShift = targetWorldPoint - part.position;
        Vector3 localShift = camTransform.InverseTransformVector(worldShift);

        Vector3 targetLocalPosition = transform.localPosition + localShift;

        float targetScaleValue = Mathf.Clamp(
            transform.localScale.x * zoomMultiplier,
            minScale,
            maxScale
        );
        Vector3 targetScale = Vector3.one * targetScaleValue;

        if (_focusRoutine != null) StopCoroutine(_focusRoutine);
        _focusRoutine = StartCoroutine(AnimateTransform(targetLocalPosition, targetScale, 0.4f));
    }

    // Devuelve el modelo a la pose que tenia antes del primer FocusOnPart.
    public void ClearFocus()
    {
        if (!_isFocused) return;
        _isFocused = false;

        if (_focusRoutine != null) StopCoroutine(_focusRoutine);
        _focusRoutine = StartCoroutine(AnimateTransform(_prevLocalPosition, _prevLocalScale, 0.35f));

        if (_focusedPart != null)
        {
            _focusedPart.localRotation = _partBaseLocalRotation;
            _focusedPart.localScale = _partBaseLocalScale;
            _focusedPart = null;
        }
    }

    IEnumerator AnimateTransform(Vector3 targetLocalPosition, Vector3 targetScale, float duration)
    {
        Vector3 startPosition = transform.localPosition;
        Vector3 startScale = transform.localScale;
        float t = 0f;

        while (t < duration)
        {
            t += Time.deltaTime;
            float k = Mathf.SmoothStep(0f, 1f, Mathf.Clamp01(t / duration));

            transform.localPosition = Vector3.Lerp(startPosition, targetLocalPosition, k);
            transform.localScale = Vector3.Lerp(startScale, targetScale, k);

            yield return null;
        }

        transform.localPosition = targetLocalPosition;
        transform.localScale = targetScale;
    }
    // Rotacion
    void HandleRotationInput()
    {
        // Mouse
        if (Input.GetMouseButton(0))
        {
            // Horizontal = Y
            // Input.GetAxis ya aplica la sensibilidad de mouse de Unity (~0.1),
            // por eso el multiplicador es bajo: iguala la sensibilidad al touch (1.5f/1.2f)
            targetRotationY +=
                Input.GetAxis("Mouse X") *
                rotationSpeed *
                15f;

            // Vertical = X
            targetRotationX -=
                Input.GetAxis("Mouse Y") *
                rotationSpeed *
                12f;
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

    // Rotacion/zoom de la parte aislada (mientras esta enfocada)
    void HandlePartRotationInput()
    {
        if (Input.GetMouseButton(0))
        {
            _partTargetRotY +=
                Input.GetAxis("Mouse X") *
                partRotationSpeed *
                15f;

            _partTargetRotX -=
                Input.GetAxis("Mouse Y") *
                partRotationSpeed *
                12f;
        }
        if (Input.touchCount == 1)
        {
            Touch t = Input.GetTouch(0);

            if (t.phase == TouchPhase.Moved)
            {
                _partTargetRotY +=
                    t.deltaPosition.x *
                    partRotationSpeed *
                    1.5f;
                _partTargetRotX -=
                    t.deltaPosition.y *
                    partRotationSpeed *
                    1.2f;
            }
        }
        _partTargetRotX = Mathf.Clamp(
            _partTargetRotX,
            partMinRotationX,
            partMaxRotationX
        );

        _partTargetRotY = NormalizeAngle(_partTargetRotY);
    }

    void SmoothPartRotation()
    {
        _partCurrentRotY = Mathf.LerpAngle(
            _partCurrentRotY,
            _partTargetRotY,
            Time.deltaTime * smoothSpeed
        );

        _partCurrentRotX = Mathf.LerpAngle(
            _partCurrentRotX,
            _partTargetRotX,
            Time.deltaTime * smoothSpeed
        );

        _focusedPart.localRotation =
            _partBaseLocalRotation *
            Quaternion.Euler(_partCurrentRotX, _partCurrentRotY, 0f);
    }

    void HandlePartZoom()
    {
        float zoomInput = 0f;

        float scroll = Input.GetAxis("Mouse ScrollWheel");
        if (scroll != 0)
            zoomInput = scroll;

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
            ApplyPartZoom(zoomInput);
    }

    void ApplyPartZoom(float increment)
    {
        _partScaleMultiplier = Mathf.Clamp(
            _partScaleMultiplier + increment * partZoomSpeed,
            partMinScaleMultiplier,
            partMaxScaleMultiplier
        );

        _focusedPart.localScale = _partBaseLocalScale * _partScaleMultiplier;
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