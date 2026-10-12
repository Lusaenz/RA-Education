using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

/// <summary>
/// Instancia un EyeButton por cada subparte del modelo 3D y lo sigue en pantalla.
/// Coloca este script en el GameObject 3DModels de cada ImageTarget.
/// Escucha los eventos OnTargetFound/OnTargetLost del DefaultObserverEventHandler.
///
/// El modelo permanece FIJO al ImageTarget (comportamiento por defecto de
/// Vuforia). Este manager solo gestiona los eye buttons de las partes y el panel
/// de contenido: al encontrar el marcador aparecen los botones, al perderlo se
/// ocultan.
/// </summary>
public class ARPartButtonManager : MonoBehaviour
{
    [Header("UI")]
    [Tooltip("Prefab del boton EyeButton (Image + Button)")]
    public GameObject eyeButtonPrefab;
    [Tooltip("RectTransform raiz del Canvas donde se instanciaran los botones")]
    public RectTransform canvasRect;
    [Tooltip("Panel unico que muestra las content_sections del topic de la parte seleccionada")]
    public TopicContentPanel contentPanel;

    [Header("Mapeo de partes a topics (BD)")]
    [Tooltip("Mapeo explicito nombre de parte (GameObject) -> id_topic. Tiene prioridad sobre defaultTopicId.")]
    public List<PartTopicOverride> partTopicOverrides = new List<PartTopicOverride>();
    [Tooltip("id_topic usado cuando la parte no esta en partTopicOverrides (0 = ninguno). Util cuando todas las partes comparten un mismo topic, como los organulos de una celula.")]
    public int defaultTopicId = 0;
    public int defaultContentId = 0;

    [Header("Zoom al seleccionar una parte")]
    [Tooltip("Punto del viewport de la camara AR (0..1) donde se centra la parte seleccionada. Y=0.68 apunta al centro del area libre superior, ya que el panel de info ocupa la franja inferior de la pantalla.")]
    public Vector2 focusViewportTarget = new Vector2(0.5f, 0.68f);
    [Tooltip("Multiplicador de escala aplicado sobre la escala actual del modelo al enfocar una parte (se recorta entre minScale/maxScale de ARModelControllerPro).")]
    public float focusZoomMultiplier = 2.2f;

    [Header("Tamano / area de toque")]
    [Tooltip("Lado visual del eye button (y del badge) en unidades de canvas. Sobrescribe el tamano del prefab.")]
    public float buttonSize = 80f;
    [Tooltip("Margen invisible (unidades de canvas) que se anade alrededor del boton a la zona tactil, sin cambiar lo que se ve.")]
    public float touchPadding = 25f;
    [Tooltip("Tamano de fuente del contador de los badges de cluster.")]
    public float badgeFontSize = 32f;
    [Tooltip("Rapidez con la que el boton sigue a su parte en pantalla. Mas bajo = mas suave (filtra el jitter del tracking), mas alto = sigue mas pegado.")]
    public float followSharpness = 18f;

    [Header("Escala de los botones con el zoom")]
    [Tooltip("Escala de los eye buttons con el zoom inicial del modelo (1 = buttonSize). Al hacer pinch el boton crece/encoge en la misma proporcion que el modelo.")]
    public float buttonScaleAtBaseZoom = 0.5f;
    [Tooltip("Escala minima de los eye buttons (al alejar el zoom).")]
    public float minButtonScale = 0.4f;
    [Tooltip("Escala maxima de los eye buttons (al acercar el zoom), para que no tapen el modelo.")]
    public float maxButtonScale = 1.1f;

    [Header("Clustering de eye buttons superpuestos")]
    [Tooltip("Distancia en unidades de canvas por debajo de la cual dos botones se consideran superpuestos y se agrupan en un badge con contador. Nunca baja de lo necesario para que dos zonas tactiles no se pisen.")]
    public float clusterRadius = 90f;
    [Tooltip("Radio en unidades de canvas del abanico donde se distribuyen los botones de un cluster al expandirlo. Se agranda solo si hace falta para que los botones no se solapen.")]
    public float clusterExpandRadius = 110f;
    [Tooltip("Color del badge mientras esta colapsado (grupo, toca para expandir).")]
    public Color clusterBadgeColor = new Color(0.15f, 0.40f, 0.65f, 0.9f);
    [Tooltip("Color del badge mientras esta expandido (toca para volver a agrupar).")]
    public Color clusterBadgeExpandedColor = new Color(0.85f, 0.35f, 0.20f, 0.9f);

    [Header("Feedback visual")]
    [Tooltip("Objeto de texto en la escena que se muestra al detectar el target.")]
    public GameObject hintTextObject;
    [Tooltip("Segundos que permanece visible el aviso de 'target encontrado' antes de desvanecerse.")]
    public float hintDuration = 2.5f;

    [Header("Adaptacion a pantallas pequenas")]
    [Tooltip("Punto Y de viewport (0..1) usado en pantallas mas cuadradas/anchas (tablets), donde el panel inferior ocupa proporcionalmente mas espacio y conviene subir mas el modelo.")]
    public float focusViewportTargetYWide = 0.78f;

    private Camera _arCamera;
    private bool _isTracking;

    private DefaultObserverEventHandler _handler;
    private ARModelControllerPro _modelController;

    private Transform _focusedPart;
    private Transform _modelRoot;
    private Dictionary<string, int> _topicByPart;
    private Dictionary<string, int> _contentSectionByPart;
    // Inverso de _contentSectionByPart, resuelto contra las partes reales del
    // modelo instanciado (ver SpawnButtons). Permite, cuando un topic agrupa
    // varias partes (ej. organulos de la celula compartiendo defaultTopicId),
    // saber a que parte del modelo 3D corresponde la content_section que el
    // panel esta mostrando en un momento dado.
    private Dictionary<int, Transform> _partByContentSection;

    private class PartButton
    {
        public RectTransform rect;
        public Transform part;
        public Button button;
        public Image image;
        public Vector2 smoothedPos;
    }

    private class ClusterBadge
    {
        public RectTransform rect;
        public Button button;
        public TextMeshProUGUI label;
        public Image background;
        public Vector2 smoothedPos;
    }

    // Botones/badges con el dedo encima ahora mismo (ver EyeButtonPressTracker).
    // Mientras sea > 0 el layout se congela para que el boton no se escape
    // de debajo del dedo entre el press y el release.
    private int _pressedCount;
    private Canvas _canvas;

    // Escala de 3DModels al arrancar (antes de cualquier pinch): referencia
    // para saber cuanto zoom lleva el usuario. _buttonScale es la escala que
    // se aplica este frame a botones y badges (ver UpdateButtonScale).
    private float _baseModelScale = 1f;
    private float _buttonScale = 1f;
    // Rects reproduciendo el pop de aparicion: mientras dure, la coroutine
    // controla su localScale y PlaceButton no la pisa.
    private readonly HashSet<RectTransform> _popping = new HashSet<RectTransform>();

    private readonly List<PartButton> _buttons = new List<PartButton>();
    private readonly List<ClusterBadge> _badgePool = new List<ClusterBadge>();
    private readonly HashSet<Transform> _expandedClusters = new HashSet<Transform>();

    // Buffers reutilizados cada frame en UpdatePositions/BuildClusters para no generar
    // basura de GC en cada LateUpdate (la app corre en movil).
    private readonly List<int> _visibleIdx = new List<int>();
    private readonly List<Vector3> _screenPos = new List<Vector3>();
    private readonly List<List<int>> _clusters = new List<List<int>>();
    private bool[] _assignedScratch = new bool[0];

    private CanvasGroup _hintCanvasGroup;
    private Coroutine _hintRoutine;

    [System.Serializable]
    public class PartTopicOverride
    {
        public string partName;
        public int idTopic;

        public int idContentSection;
    }

    void Start()
    {
        BuildTopicMaps();

        _arCamera = Camera.main;
        _modelController = GetComponent<ARModelControllerPro>();
        if (canvasRect != null) _canvas = canvasRect.GetComponentInParent<Canvas>();
        if (transform.localScale.x > 0f) _baseModelScale = transform.localScale.x;
        _buttonScale = buttonScaleAtBaseZoom;

        if (contentPanel != null)
        {
            contentPanel.OnClosed += ClearFocusAndHighlight;
            contentPanel.OnSectionChanged += OnPanelSectionChanged;
        }

        _handler = GetComponentInParent<DefaultObserverEventHandler>();
        if (_handler != null)
        {
            _handler.OnTargetFound.AddListener(OnTrackingFound);
            _handler.OnTargetLost.AddListener(OnTrackingLost);
        }
        else
        {
            Debug.LogWarning("[ARPartButtonManager] No se encontro DefaultObserverEventHandler en el padre.", this);
        }
    }

    void BuildTopicMaps()
    {
        _topicByPart = new Dictionary<string, int>(System.StringComparer.OrdinalIgnoreCase);
        _contentSectionByPart = new Dictionary<string, int>(System.StringComparer.OrdinalIgnoreCase);

        foreach (var entry in partTopicOverrides)
        {
            if (string.IsNullOrEmpty(entry.partName)) continue;
            _topicByPart[entry.partName] = entry.idTopic;
            _contentSectionByPart[entry.partName] = entry.idContentSection;
        }
    }

    void OnDestroy()
    {
        if (_handler != null)
        {
            _handler.OnTargetFound.RemoveListener(OnTrackingFound);
            _handler.OnTargetLost.RemoveListener(OnTrackingLost);
        }
        if (contentPanel != null)
        {
            contentPanel.OnClosed -= ClearFocusAndHighlight;
            contentPanel.OnSectionChanged -= OnPanelSectionChanged;
        }
        DestroyPooledObjects();
    }

    // Al desactivarse se detienen las coroutines de pop: sin esto sus rects
    // quedarian marcados como "popping" y ya no seguirian el zoom.
    void OnDisable()
    {
        _popping.Clear();
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
        ShowFindHint();
    }

    void OnTrackingLost()
    {
        _isTracking = false;
        HideButtons();
        HideFindHint(true);

        if (_modelController != null)
            _modelController.ClearFocus();

        if (contentPanel != null && contentPanel.IsOpen)
            contentPanel.Close();
    }

    // Los eye buttons se poolean (ver EnsureButtonPool) en vez de destruirse y
    // recrearse en cada ciclo de deteccion/perdida del target: en AR el mismo
    // target suele encontrarse y perderse varias veces por sesion, y
    // Destroy+Instantiate repetido generaba basura de GC evitable en movil.
    void SpawnButtons()
    {
        if (eyeButtonPrefab == null || canvasRect == null) return;
        if (transform.childCount == 0) return;

        // Primer hijo de 3DModels = raiz del modelo (ej. Aparato_Digestivo)
        Transform modelRoot = transform.GetChild(0);
        _modelRoot = modelRoot;

        _partByContentSection = new Dictionary<int, Transform>();

        int count = modelRoot.childCount;
        EnsureButtonPool(count);

        for (int i = 0; i < count; i++)
        {
            Transform part = modelRoot.GetChild(i);
            PartButton pb = _buttons[i];
            pb.part = part;
            pb.rect.gameObject.name = "EyeBtn_" + part.name;

            int idTopic = ResolveTopicId(part.name);
            int idContentSection = ResolveContentSectionId(part.name);

            if (pb.button != null)
            {
                pb.button.onClick.RemoveAllListeners();
                pb.button.onClick.AddListener(() => SelectPart(part, idTopic, idContentSection));
            }

            if (idContentSection > 0)
                _partByContentSection[idContentSection] = part;

            // Se deja inactivo: UpdatePositions() lo activa en el primer
            // LateUpdate y detecta la transicion inactivo->activo para
            // reproducir la animacion de aparicion (ver PlaySpawnPop).
            pb.rect.gameObject.SetActive(false);
        }

        // Si el modelo anterior (pool reutilizado entre targets) tenia mas
        // partes que el actual, los botones sobrantes quedan ocultos y sin
        // referencia a 'part' (si no, UpdatePositions podria reactivarlos
        // usando la posicion de una parte que ya no corresponde a este pool).
        for (int i = count; i < _buttons.Count; i++)
        {
            _buttons[i].part = null;
            _buttons[i].rect.gameObject.SetActive(false);
        }
    }

    void EnsureButtonPool(int count)
    {
        while (_buttons.Count < count)
        {
            GameObject btnGO = Instantiate(eyeButtonPrefab, canvasRect);
            btnGO.SetActive(false);
            SetupTouchTarget(btnGO);

            _buttons.Add(new PartButton
            {
                rect = btnGO.GetComponent<RectTransform>(),
                part = null,
                button = btnGO.GetComponent<Button>(),
                image = btnGO.GetComponent<Image>()
            });
        }
    }

    // Aplica el tamano configurado (buttonSize) y agranda la zona tactil con
    // raycastPadding negativo, que en uGUI extiende el area de raycast sin
    // cambiar lo que se dibuja. Tambien engancha el tracker de press para
    // congelar el layout mientras el dedo esta encima.
    void SetupTouchTarget(GameObject go)
    {
        RectTransform rect = go.GetComponent<RectTransform>();
        if (rect != null)
            rect.sizeDelta = new Vector2(buttonSize, buttonSize);

        Image image = go.GetComponent<Image>();
        // El padding esta en unidades locales del boton, que se escalan con
        // _buttonScale: se divide para que mida touchPadding en el canvas.
        if (image != null)
        {
            float pad = -touchPadding / Mathf.Max(_buttonScale, 0.01f);
            image.raycastPadding = new Vector4(pad, pad, pad, pad);
        }

        EyeButtonPressTracker tracker = go.AddComponent<EyeButtonPressTracker>();
        tracker.OnPressChanged += pressed =>
        {
            _pressedCount = Mathf.Max(0, _pressedCount + (pressed ? 1 : -1));
        };
    }

    float CanvasScale => _canvas != null ? _canvas.scaleFactor : 1f;

    // Lleva 'current' hacia 'target' con suavizado exponencial (independiente
    // del framerate). Filtra el jitter del tracking de Vuforia, que antes hacia
    // temblar los botones y les quitaba toques.
    Vector2 Follow(Vector2 current, Vector2 target)
    {
        float k = 1f - Mathf.Exp(-followSharpness * Time.deltaTime);
        return Vector2.Lerp(current, target, k);
    }

    // Abre/actualiza el panel de contenido para 'part' y sincroniza el
    // zoom sobre el modelo 3D con lo que le pase al panel
    // (abrir, cambiar de parte, o cerrar via toggle del mismo eyebutton).
    // idContentSection (opcional, 0 = ninguno) abre el panel directamente en esa
    // content_section en vez de la primera del topic.
    void SelectPart(Transform part, int idTopic, int idContentSection = 0)
    {
        if (contentPanel == null || (idTopic <= 0 && idContentSection <= 0))
        {
            Debug.LogWarning($"[ARPartButtonManager] Sin id_topic ni id_content_section mapeado para la parte '{part.name}'.", this);
            return;
        }

        bool willClose;
        if (idTopic > 0)
        {
            willClose = contentPanel.IsOpen && contentPanel.CurrentTopicId == idTopic
                && (idContentSection <= 0 || contentPanel.CurrentContentSectionId == idContentSection);

            contentPanel.ShowTopic(idTopic, idContentSection);
        }
        else
        {
            willClose = contentPanel.IsOpen && contentPanel.CurrentContentSectionId == idContentSection;

            contentPanel.ShowContentSection(idContentSection);
        }

        if (willClose)
        {
            ClearFocusAndHighlight();
            return;
        }

        HideFindHint(false);

        _focusedPart = part;
        ShowOnlyPart(part);

        if (_modelController != null)
            _modelController.FocusOnPart(part, GetEffectiveFocusViewportTarget(), focusZoomMultiplier);
    }

    // Sincroniza que parte del modelo 3D esta visible/enfocada con la
    // content_section que el panel acaba de renderizar (disparado por
    // ShowTopic/ShowContentSection y por Next()/Prev()). Solo actua cuando esa
    // seccion tiene una parte mapeada (caso celula, donde varias partes
    // comparten un mismo topic): en el sistema digestivo cada parte usa
    // idContentSection = 0, asi que _partByContentSection queda vacio y este
    // metodo no hace nada, dejando el comportamiento actual intacto.
    void OnPanelSectionChanged(int idContentSection)
    {
        if (!_isTracking || idContentSection <= 0) return;
        if (_partByContentSection == null) return;
        if (!_partByContentSection.TryGetValue(idContentSection, out Transform part)) return;
        if (part == _focusedPart) return;

        _focusedPart = part;
        ShowOnlyPart(part);

        if (_modelController != null)
            _modelController.FocusOnPart(part, GetEffectiveFocusViewportTarget(), focusZoomMultiplier);
    }

    // Ajusta el punto de foco segun la proporcion de pantalla: en telefonos
    // angostos y altos hay bastante espacio libre por encima del panel
    // inferior (se puede usar el focusViewportTarget.y configurado en el
    // inspector), pero en pantallas mas cuadradas/anchas (tablets, phones en
    // landscape) el panel ocupa proporcionalmente mas alto y el modelo debe
    // subir mas para no quedar tapado.
    Vector2 GetEffectiveFocusViewportTarget()
    {
        if (Screen.width <= 0 || Screen.height <= 0) return focusViewportTarget;

        float heightOverWidth = (float)Screen.height / Screen.width;
        float t = Mathf.InverseLerp(1.3f, 2.1f, heightOverWidth);
        float y = Mathf.Lerp(focusViewportTargetYWide, focusViewportTarget.y, t);

        return new Vector2(focusViewportTarget.x, y);
    }

    // Aviso "toca una parte para explorar" mostrado al detectar el target por
    // primera vez, para que el usuario sepa que el modelo es interactuable.
    void ShowFindHint()
    {
        if (hintTextObject == null) return;
        if (_hintCanvasGroup == null) _hintCanvasGroup = hintTextObject.GetComponent<CanvasGroup>();
        if (_hintCanvasGroup == null) return;

        if (_hintRoutine != null) StopCoroutine(_hintRoutine);
        _hintRoutine = StartCoroutine(FindHintRoutine());
    }

    void HideFindHint(bool immediate)
    {
        if (hintTextObject == null || _hintCanvasGroup == null) return;

        if (_hintRoutine != null)
        {
            StopCoroutine(_hintRoutine);
            _hintRoutine = null;
        }

        if (immediate)
        {
            _hintCanvasGroup.alpha = 0f;
            hintTextObject.SetActive(false);
        }
        else
        {
            _hintRoutine = StartCoroutine(FadeHintOut());
        }
    }

    IEnumerator FindHintRoutine()
    {
        hintTextObject.SetActive(true);
        yield return FadeCanvasGroup(_hintCanvasGroup, 0f, 1f, 0.25f);
        yield return new WaitForSeconds(hintDuration);
        yield return FadeCanvasGroup(_hintCanvasGroup, 1f, 0f, 0.35f);
        hintTextObject.SetActive(false);
        _hintRoutine = null;
    }

    IEnumerator FadeHintOut()
    {
        yield return FadeCanvasGroup(_hintCanvasGroup, _hintCanvasGroup.alpha, 0f, 0.2f);
        hintTextObject.SetActive(false);
        _hintRoutine = null;
    }

    IEnumerator FadeCanvasGroup(CanvasGroup cg, float from, float to, float duration)
    {
        float t = 0f;
        while (t < duration)
        {
            t += Time.deltaTime;
            cg.alpha = Mathf.Lerp(from, to, Mathf.Clamp01(t / duration));
            yield return null;
        }
        cg.alpha = to;
    }

    void ClearFocusAndHighlight()
    {
        _focusedPart = null;
        ShowAllParts();

        if (_modelController != null)
            _modelController.ClearFocus();
    }

    // Oculta el resto de partes del modelo para que en pantalla solo quede
    // visible la parte seleccionada (junto con el panel de informacion).
    void ShowOnlyPart(Transform part)
    {
        if (_modelRoot == null) return;

        for (int i = 0; i < _modelRoot.childCount; i++)
        {
            Transform child = _modelRoot.GetChild(i);
            child.gameObject.SetActive(child == part);
        }
    }

    void ShowAllParts()
    {
        if (_modelRoot == null) return;

        for (int i = 0; i < _modelRoot.childCount; i++)
            _modelRoot.GetChild(i).gameObject.SetActive(true);
    }

    int ResolveTopicId(string partName)
    {
        if (_topicByPart != null && _topicByPart.TryGetValue(partName, out int idTopic))
            return idTopic;

        return defaultTopicId;
    }

    int ResolveContentSectionId(string partName)
    {
        if (_contentSectionByPart != null && _contentSectionByPart.TryGetValue(partName, out int idContentSection) && idContentSection > 0)
            return idContentSection;

        return defaultContentId;
    }

    // Oculta todos los botones/badges sin destruirlos (ver EnsureButtonPool):
    // se usa al perder tracking, ya que es habitual recuperar el mismo target
    // mas adelante en la misma sesion.
    void HideButtons()
    {
        foreach (var pb in _buttons)
        {
            if (pb.rect != null)
                pb.rect.gameObject.SetActive(false);
        }

        DeactivateBadgesFrom(0);
        _expandedClusters.Clear();
    }

    // Destruye definitivamente el pool. Solo se llama al destruir este
    // componente (ver OnDestroy), no al perder tracking.
    void DestroyPooledObjects()
    {
        foreach (var pb in _buttons)
        {
            if (pb.rect != null)
                Destroy(pb.rect.gameObject);
        }
        _buttons.Clear();

        foreach (var badge in _badgePool)
        {
            if (badge.rect != null)
                Destroy(badge.rect.gameObject);
        }
        _badgePool.Clear();

        _expandedClusters.Clear();
    }

    // Recalcula cada frame la posicion en pantalla de las partes y agrupa en un
    // "badge" con contador a las que caen a menos de clusterRadius pixeles entre
    // si (ej. organulos concentricos dentro de una celula), evitando que sus
    // eye buttons se vean amontonados/superpuestos. Tocar el badge expande sus
    // miembros en un pequeno abanico alrededor del centroide del grupo.
    void UpdatePositions()
    {
        if (_arCamera == null) return;

        bool panelOpen = contentPanel != null && contentPanel.IsOpen;
        if (panelOpen)
        {
            foreach (var pb in _buttons)
                if (pb.rect != null) pb.rect.gameObject.SetActive(false);
            DeactivateBadgesFrom(0);
            return;
        }

        // Dedo encima de un boton: se congela todo (posiciones y clusters)
        // hasta que lo suelte, para que el release caiga sobre el mismo boton.
        if (_pressedCount > 0) return;

        UpdateButtonScale();

        _visibleIdx.Clear();
        _screenPos.Clear();

        for (int i = 0; i < _buttons.Count; i++)
        {
            var pb = _buttons[i];
            if (pb.rect == null || pb.part == null) continue;

            Vector3 screenPos = _arCamera.WorldToScreenPoint(pb.part.position);
            bool inFront = screenPos.z > 0f;

            if (!inFront)
            {
                pb.rect.gameObject.SetActive(false);
                continue;
            }

            _visibleIdx.Add(i);
            _screenPos.Add(screenPos);
        }

        BuildClusters();

        int badgesUsed = 0;

        foreach (var cluster in _clusters)
        {
            if (cluster.Count == 1)
            {
                var pb = _buttons[_visibleIdx[cluster[0]]];
                PlaceButton(pb, _screenPos[cluster[0]]);
                continue;
            }

            Vector2 centroid = Vector2.zero;
            foreach (int i in cluster)
                centroid += (Vector2)_screenPos[i];
            centroid /= cluster.Count;

            Transform anchor = _buttons[_visibleIdx[cluster[0]]].part;
            bool expanded = _expandedClusters.Contains(anchor);

            ClusterBadge badge = GetBadge(badgesUsed++);
            bool badgeWasActive = badge.rect.gameObject.activeSelf;
            badge.rect.gameObject.SetActive(true);
            badge.smoothedPos = badgeWasActive ? Follow(badge.smoothedPos, centroid) : centroid;
            badge.rect.position = badge.smoothedPos;
            // "x" = toca para volver a agrupar (expandido); numero = cuantas
            // partes agrupa (colapsado). El color refuerza el mismo estado
            // para que no dependa solo de leer el texto.
            badge.label.text = expanded ? "x" : cluster.Count.ToString();
            badge.background.color = expanded ? clusterBadgeExpandedColor : clusterBadgeColor;
            badge.button.onClick.RemoveAllListeners();
            badge.button.onClick.AddListener(() => ToggleCluster(anchor));
            if (!badgeWasActive) StartCoroutine(PlaySpawnPop(badge.rect));
            else if (!_popping.Contains(badge.rect)) badge.rect.localScale = Vector3.one * _buttonScale;

            // Radio del abanico: el configurado, o el minimo para que los n
            // botones repartidos en circulo no se solapen (cuerda entre
            // vecinos = 2·r·sin(pi/n) >= tamano del boton + separacion).
            float minExpandRadius = (ScaledButtonSize + 16f) / (2f * Mathf.Sin(Mathf.PI / cluster.Count));
            float expandRadius = Mathf.Max(clusterExpandRadius, minExpandRadius) * CanvasScale;

            for (int k = 0; k < cluster.Count; k++)
            {
                var pb = _buttons[_visibleIdx[cluster[k]]];

                if (!expanded)
                {
                    pb.rect.gameObject.SetActive(false);
                    continue;
                }

                float angle = (k * Mathf.PI * 2f / cluster.Count) - Mathf.PI / 2f;
                Vector2 offset = new Vector2(Mathf.Cos(angle), Mathf.Sin(angle)) * expandRadius;

                PlaceButton(pb, centroid + offset);
            }
        }

        DeactivateBadgesFrom(badgesUsed);
    }

    // Activa el boton y lo lleva suavizado a 'target'. Si acaba de aparecer
    // se coloca directamente (sin deslizarse desde su posicion anterior) y se
    // reproduce el pop de aparicion.
    void PlaceButton(PartButton pb, Vector2 target)
    {
        bool wasActive = pb.rect.gameObject.activeSelf;
        pb.rect.gameObject.SetActive(true);
        pb.smoothedPos = wasActive ? Follow(pb.smoothedPos, target) : target;
        pb.rect.position = pb.smoothedPos;
        if (!wasActive) StartCoroutine(PlaySpawnPop(pb.rect));
        else if (!_popping.Contains(pb.rect)) pb.rect.localScale = Vector3.one * _buttonScale;
    }

    float ScaledButtonSize => buttonSize * _buttonScale;

    // Hace que los eye buttons sigan el zoom del modelo: si el pinch duplica
    // la escala de 3DModels, el boton tambien se duplica (recortado entre
    // minButtonScale/maxButtonScale). El padding tactil se compensa para que
    // la zona tactil extra siga midiendo touchPadding en unidades de canvas
    // y los botones pequenos sigan siendo faciles de tocar.
    void UpdateButtonScale()
    {
        float zoom = transform.localScale.x / _baseModelScale;
        float scale = Mathf.Clamp(buttonScaleAtBaseZoom * zoom, minButtonScale, maxButtonScale);
        if (Mathf.Approximately(scale, _buttonScale)) return;

        _buttonScale = scale;

        float pad = -touchPadding / Mathf.Max(scale, 0.01f);
        Vector4 padding = new Vector4(pad, pad, pad, pad);
        foreach (var pb in _buttons)
            if (pb.image != null) pb.image.raycastPadding = padding;
        foreach (var badge in _badgePool)
            if (badge.background != null) badge.background.raycastPadding = padding;
    }

    // Agrupa por cercania en pantalla (single-linkage simple): cada cluster crece
    // mientras encuentre botones sin asignar dentro de clusterRadius de su centroide.
    void BuildClusters()
    {
        _clusters.Clear();

        int n = _visibleIdx.Count;
        if (_assignedScratch.Length < n) _assignedScratch = new bool[n];
        System.Array.Clear(_assignedScratch, 0, n);

        // _screenPos esta en pixeles de pantalla: se pasa el radio (unidades
        // de canvas) a pixeles con el scaleFactor. Nunca menor que lo necesario
        // para que las zonas tactiles de dos botones no se pisen.
        float radius = Mathf.Max(clusterRadius, ScaledButtonSize + touchPadding * 0.5f) * CanvasScale;

        for (int i = 0; i < n; i++)
        {
            if (_assignedScratch[i]) continue;

            var cluster = new List<int> { i };
            _assignedScratch[i] = true;
            Vector2 centroid = _screenPos[i];

            for (int j = i + 1; j < n; j++)
            {
                if (_assignedScratch[j]) continue;
                if (Vector2.Distance(centroid, _screenPos[j]) > radius) continue;

                cluster.Add(j);
                _assignedScratch[j] = true;

                centroid = Vector2.zero;
                foreach (int m in cluster) centroid += (Vector2)_screenPos[m];
                centroid /= cluster.Count;
            }

            _clusters.Add(cluster);
        }
    }

    void ToggleCluster(Transform anchor)
    {
        if (!_expandedClusters.Remove(anchor))
            _expandedClusters.Add(anchor);
    }

    ClusterBadge GetBadge(int index)
    {
        while (_badgePool.Count <= index)
            _badgePool.Add(CreateBadge());

        return _badgePool[index];
    }

    ClusterBadge CreateBadge()
    {
        GameObject badgeGO = Instantiate(eyeButtonPrefab, canvasRect);
        badgeGO.name = "EyeBtn_ClusterBadge";
        SetupTouchTarget(badgeGO);

        // Fondo con color propio (ver clusterBadgeColor/clusterBadgeExpandedColor)
        // para que un badge de grupo se distinga a simple vista de un eye
        // button normal, en vez de compartir el mismo blanco.
        Image background = badgeGO.GetComponent<Image>();
        if (background != null)
            background.color = clusterBadgeColor;

        GameObject labelGO = new GameObject("Count", typeof(RectTransform));
        labelGO.transform.SetParent(badgeGO.transform, false);
        RectTransform labelRect = (RectTransform)labelGO.transform;
        labelRect.anchorMin = Vector2.zero;
        labelRect.anchorMax = Vector2.one;
        labelRect.offsetMin = Vector2.zero;
        labelRect.offsetMax = Vector2.zero;

        TextMeshProUGUI label = labelGO.AddComponent<TextMeshProUGUI>();
        label.alignment = TextAlignmentOptions.Center;
        label.fontSize = badgeFontSize;
        label.fontStyle = FontStyles.Bold;
        label.color = Color.white;
        label.raycastTarget = false;

        badgeGO.SetActive(false);

        return new ClusterBadge
        {
            rect = badgeGO.GetComponent<RectTransform>(),
            button = badgeGO.GetComponent<Button>(),
            label = label,
            background = background
        };
    }

    // Animacion de aparicion (pop con overshoot) para eye buttons y badges
    // que acaban de activarse, dando feedback claro de que algo nuevo es
    // interactuable en pantalla.
    IEnumerator PlaySpawnPop(RectTransform rect)
    {
        if (rect == null) yield break;

        const float duration = 0.25f;
        float t = 0f;
        _popping.Add(rect);
        rect.localScale = Vector3.zero;

        // Se multiplica por _buttonScale en cada frame para que el pop
        // termine en el tamano que corresponde al zoom actual.
        while (t < duration && rect != null)
        {
            t += Time.deltaTime;
            float k = EaseOutBack(Mathf.Clamp01(t / duration));
            rect.localScale = Vector3.one * (k * _buttonScale);
            yield return null;
        }

        _popping.Remove(rect);
        if (rect != null) rect.localScale = Vector3.one * _buttonScale;
    }

    static float EaseOutBack(float x)
    {
        const float c1 = 1.70158f;
        const float c3 = c1 + 1f;
        return 1f + c3 * Mathf.Pow(x - 1f, 3f) + c1 * Mathf.Pow(x - 1f, 2f);
    }

    void DeactivateBadgesFrom(int startIndex)
    {
        for (int i = startIndex; i < _badgePool.Count; i++)
        {
            if (_badgePool[i].rect != null)
                _badgePool[i].rect.gameObject.SetActive(false);
        }
    }
}
