using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Instancia un EyeButton por cada subparte del modelo 3D y lo sigue en pantalla.
/// Coloca este script en el GameObject 3DModels de cada ImageTarget.
/// Escucha los eventos OnTargetFound/OnTargetLost del DefaultObserverEventHandler.
/// </summary>
public class ARPartButtonManager : MonoBehaviour
{
    [Header("UI")]
    [Tooltip("Prefab del botón EyeButton (Image + Button)")]
    public GameObject eyeButtonPrefab;
    [Tooltip("RectTransform raíz del Canvas donde se instanciarán los botones")]
    public RectTransform canvasRect;
    [Tooltip("Panel único que muestra las content_sections del topic de la parte seleccionada")]
    public TopicContentPanel contentPanel;

    [Header("Mapeo de partes a topics (BD)")]
    [Tooltip("Mapeo explícito nombre de parte (GameObject) -> id_topic. Tiene prioridad sobre defaultTopicId.")]
    public List<PartTopicOverride> partTopicOverrides = new List<PartTopicOverride>();
    [Tooltip("id_topic usado cuando la parte no está en partTopicOverrides (0 = ninguno). Útil cuando todas las partes comparten un mismo topic, como los orgánulos de una célula.")]
    public int defaultTopicId = 0;

    [Header("Zoom / Highlight al seleccionar una parte")]
    [Tooltip("Punto del viewport de la camara AR (0..1) donde se centra la parte seleccionada. Y=0.68 apunta al centro del area libre superior, ya que el panel de info ocupa la franja inferior de la pantalla.")]
    public Vector2 focusViewportTarget = new Vector2(0.5f, 0.68f);
    [Tooltip("Multiplicador de escala aplicado sobre la escala actual del modelo al enfocar una parte (se recorta entre minScale/maxScale de ARModelControllerPro).")]
    public float focusZoomMultiplier = 1.6f;
    [Tooltip("Color de emision (glow) aplicado a la parte seleccionada.")]
    public Color highlightEmissionColor = new Color(1f, 0.65f, 0.15f) * 2.2f;

    private Camera _arCamera;
    private bool _isTracking;
    private bool _attachedToCamera;

    private DefaultObserverEventHandler _handler;
    private ARModelControllerPro _modelController;
    private Transform _focusedPart;
    private Dictionary<string, int> _topicByPart;
    private readonly List<(RectTransform btnRect, Transform part)> _buttons =
        new List<(RectTransform, Transform)>();

    [System.Serializable]
    public class PartTopicOverride
    {
        public string partName;
        public int idTopic;
    }

    void Start()
    {
        _topicByPart = new Dictionary<string, int>(System.StringComparer.OrdinalIgnoreCase);
        foreach (var entry in partTopicOverrides)
        {
            if (!string.IsNullOrEmpty(entry.partName))
                _topicByPart[entry.partName] = entry.idTopic;
        }

        _arCamera = Camera.main;
        _modelController = GetComponent<ARModelControllerPro>();

        _handler = GetComponentInParent<DefaultObserverEventHandler>();
        if (_handler != null)
        {
            _handler.OnTargetFound.AddListener(OnTrackingFound);
            _handler.OnTargetLost.AddListener(OnTrackingLost);
        }
        else
        {
            Debug.LogWarning("[ARPartButtonManager] No se encontró DefaultObserverEventHandler en el padre.", this);
        }

        if (contentPanel != null)
            contentPanel.OnClosed += ClearFocusAndHighlight;
    }

    void OnDestroy()
    {
        if (_handler != null)
        {
            _handler.OnTargetFound.RemoveListener(OnTrackingFound);
            _handler.OnTargetLost.RemoveListener(OnTrackingLost);
        }
        if (contentPanel != null)
            contentPanel.OnClosed -= ClearFocusAndHighlight;
        ClearButtons();
    }

    void LateUpdate()
    {
        if (_isTracking)
            UpdatePositions();
    }

void OnTrackingFound()
    {
        _isTracking = true;
        SpawnButtons();
        AttachToCamera();
    }

void OnTrackingLost()
    {
        // Una vez el modelo quedo anclado a la camara ya no depende de
        // seguir viendo el target fisico, asi que se mantiene visible.
        if (_attachedToCamera) return;

        _isTracking = false;
        ClearButtons();
    }

    // Desancla el modelo 3D del ImageTarget y lo mueve bajo la camara AR,
    // conservando su pose actual, para que a partir de ahora se mueva junto
    // con la camara en vez de quedarse fijo sobre el marcador.
    void AttachToCamera()
    {
        if (_attachedToCamera || _arCamera == null) return;

        // Se conserva la distancia a la que estaba el modelo respecto a la
        // camara, pero se coloca sobre su eje local +Z (adelante), en vez de
        // preservar el offset mundial tal cual: con worldPositionStays=true
        // la rotacion local resultante suele tener componente Z, y
        // ARModelControllerPro solo reconstruye rotacion en X/Y cada frame
        // (ver SmoothRotation), lo que dejaba el modelo mal orientado o
        // fuera del frustum apenas la camara giraba.
        float distance = Vector3.Distance(transform.position, _arCamera.transform.position);
        if (distance < 0.5f) distance = 0.5f;

        transform.SetParent(_arCamera.transform, false);
        transform.localPosition = new Vector3(0f, 0f, distance);
        transform.localRotation = Quaternion.identity;

        _attachedToCamera = true;

        if (_modelController != null)
            _modelController.SyncRotationFromTransform();
    }


    void SpawnButtons()
    {
        ClearButtons();
        if (eyeButtonPrefab == null || canvasRect == null) return;
        if (transform.childCount == 0) return;

        // Primer hijo de 3DModels = raíz del modelo (ej. Aparato_Digestivo)
        Transform modelRoot = transform.GetChild(0);

        for (int i = 0; i < modelRoot.childCount; i++)
        {
            Transform part = modelRoot.GetChild(i);

            GameObject btnGO = Instantiate(eyeButtonPrefab, canvasRect);
            btnGO.name = "EyeBtn_" + part.name;
            btnGO.SetActive(true);

            Button btn = btnGO.GetComponent<Button>();
            if (btn != null)
            {
                int idTopic = ResolveTopicId(part.name);
                btn.onClick.AddListener(() => SelectPart(part, idTopic));
            }

            _buttons.Add((btnGO.GetComponent<RectTransform>(), part));
        }
    }

    // Abre/actualiza el panel de contenido para 'part' y sincroniza el
    // zoom+highlight sobre el modelo 3D con lo que le pase al panel
    // (abrir, cambiar de parte, o cerrar via toggle del mismo eyebutton).
    void SelectPart(Transform part, int idTopic)
    {
        if (contentPanel == null || idTopic <= 0)
        {
            Debug.LogWarning($"[ARPartButtonManager] Sin id_topic mapeado para la parte '{part.name}'.", this);
            return;
        }

        bool willClose = contentPanel.IsOpen && contentPanel.CurrentTopicId == idTopic;

        contentPanel.ShowTopic(idTopic);

        if (willClose)
        {
            ClearFocusAndHighlight();
            return;
        }

        if (_focusedPart != null && _focusedPart != part)
            SetHighlight(_focusedPart, false);

        _focusedPart = part;
        SetHighlight(part, true);

        if (_modelController != null)
            _modelController.FocusOnPart(part, focusViewportTarget, focusZoomMultiplier);
    }

    void ClearFocusAndHighlight()
    {
        if (_focusedPart != null)
            SetHighlight(_focusedPart, false);
        _focusedPart = null;

        if (_modelController != null)
            _modelController.ClearFocus();
    }

    static readonly int EmissionColorId = Shader.PropertyToID("_EmissionColor");

    void SetHighlight(Transform part, bool on)
    {
        Renderer renderer = part.GetComponent<Renderer>();
        if (renderer == null) return;

        Material mat = renderer.material;
        if (on)
        {
            mat.EnableKeyword("_EMISSION");
            mat.SetColor(EmissionColorId, highlightEmissionColor);
        }
        else
        {
            mat.DisableKeyword("_EMISSION");
            mat.SetColor(EmissionColorId, Color.black);
        }
    }

    int ResolveTopicId(string partName)
    {
        if (_topicByPart != null && _topicByPart.TryGetValue(partName, out int idTopic))
            return idTopic;

        return defaultTopicId;
    }

    void ClearButtons()
    {
        foreach (var (btnRect, _) in _buttons)
        {
            if (btnRect != null)
                Destroy(btnRect.gameObject);
        }
        _buttons.Clear();
    }

void UpdatePositions()
    {
        if (_arCamera == null) return;

        bool panelOpen = contentPanel != null && contentPanel.IsOpen;

        foreach (var (btnRect, part) in _buttons)
        {
            if (btnRect == null || part == null) continue;

            if (panelOpen)
            {
                btnRect.gameObject.SetActive(false);
                continue;
            }

            Vector3 screenPos = _arCamera.WorldToScreenPoint(part.position);
            bool inFront = screenPos.z > 0f;
            btnRect.gameObject.SetActive(inFront);

            if (inFront)
                btnRect.position = screenPos;
        }
    }
}
