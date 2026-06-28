using UnityEngine;
#if ENABLE_INPUT_SYSTEM
using UnityEngine.InputSystem;
#endif

public class BoxGameSelector : MonoBehaviour
{
    public GameInfoUI gameInfoUI;
    [SerializeField] private bool showAndroidTouchMessages = true;
    [SerializeField] private int fallbackGameActivityId = 1;

    private Camera cachedCamera;
    private int lastSelectionFrame = -1;

    private void Awake()
    {
        RefreshCamera();
    }

    private void OnEnable()
    {
        RefreshCamera();
        if (gameInfoUI == null)
        {
            ResolveGameInfoUI();
        }
    }

    private void Start()
    {
    }

    private void Update()
    {
        if (TryHandleInputSystemTap())
        {
            return;
        }

        TryHandleLegacyTouch();
        TryHandleMouseClick();
    }

    private bool TryHandleInputSystemTap()
    {
#if ENABLE_INPUT_SYSTEM
        if (Touchscreen.current != null && Touchscreen.current.primaryTouch.press.wasPressedThisFrame)
        {
            CheckHit(Touchscreen.current.primaryTouch.position.ReadValue());
            return true;
        }

        if (Mouse.current != null && Mouse.current.leftButton.wasPressedThisFrame)
        {
            CheckHit(Mouse.current.position.ReadValue());
            return true;
        }
#endif
        return false;
    }

    private void TryHandleLegacyTouch()
    {
#if ENABLE_LEGACY_INPUT_MANAGER
        if (!Application.isMobilePlatform || UnityEngine.Input.touchCount <= 0)
        {
            return;
        }

        UnityEngine.Touch touch = UnityEngine.Input.GetTouch(0);
        if (touch.phase == UnityEngine.TouchPhase.Began || touch.phase == UnityEngine.TouchPhase.Ended)
        {
            CheckHit(touch.position);
        }
#endif
    }

    private void TryHandleMouseClick()
    {
#if ENABLE_LEGACY_INPUT_MANAGER
        if (Application.isMobilePlatform)
        {
            return;
        }

        if (UnityEngine.Input.GetMouseButtonDown(0))
        {
            CheckHit(UnityEngine.Input.mousePosition);
        }
#endif
    }

    private void OnMouseUpAsButton()
    {
        SelectGame("OnMouseUpAsButton");
    }

    private void CheckHit(Vector2 screenPosition)
    {
        RefreshCamera();
        if (cachedCamera == null)
        {
            Debug.LogWarning("BoxGameSelector: no se encontro una camara principal para detectar el toque.");
            return;
        }

        Ray ray = cachedCamera.ScreenPointToRay(screenPosition);

        RaycastHit[] hits3D = Physics.RaycastAll(ray, Mathf.Infinity);
        foreach (RaycastHit hit in hits3D)
        {
            if (IsHitThisSelector(hit.transform))
            {
                SelectGame("Physics.RaycastAll");
                return;
            }
        }

        RaycastHit2D[] hits2D = Physics2D.GetRayIntersectionAll(ray, Mathf.Infinity);
        foreach (RaycastHit2D hit2D in hits2D)
        {
            if (hit2D.collider != null && IsHitThisSelector(hit2D.transform))
            {
                SelectGame("Physics2D.GetRayIntersectionAll");
                return;
            }
        }
    }

    private bool IsHitThisSelector(Transform hitTransform)
    {
        return hitTransform == transform || hitTransform.IsChildOf(transform);
    }

    private void RefreshCamera()
    {
        if (cachedCamera == null)
        {
            cachedCamera = Camera.main;
        }
    }

    private void ResolveGameInfoUI()
    {
        if (gameInfoUI != null && gameInfoUI.isActiveAndEnabled)
        {
            return;
        }

        GameInfoUI[] candidates = FindObjectsByType<GameInfoUI>(FindObjectsInactive.Include, FindObjectsSortMode.None);
        GameInfoUI fallback = null;

        foreach (GameInfoUI candidate in candidates)
        {
            if (candidate == null)
            {
                continue;
            }

            if (fallback == null)
            {
                fallback = candidate;
            }

            if (candidate.isActiveAndEnabled)
            {
                gameInfoUI = candidate;
                Debug.Log("BoxGameSelector: se reasigno automaticamente al GameInfoUI activo.");
                return;
            }
        }

        gameInfoUI = fallback;
    }

    private void SelectGame(string source)
    {
        if (lastSelectionFrame == Time.frameCount)
        {
            return;
        }

        lastSelectionFrame = Time.frameCount;

        int gameID = ResolveGameActivityId();
        Debug.Log($"BoxGameSelector: seleccion detectada desde {source}. ID: {gameID}");
        ResolveGameInfoUI();

        if (gameInfoUI == null)
        {
            Debug.LogWarning("BoxGameSelector: gameInfoUI no esta asignado.");
            return;
        }

        gameInfoUI.ShowGame(gameID);
    }

    private int ResolveGameActivityId()
    {
        int gameID = PlayerPrefs.GetInt("selected_activity_id", fallbackGameActivityId);
        return gameID > 0 ? gameID : fallbackGameActivityId;
    }

}
