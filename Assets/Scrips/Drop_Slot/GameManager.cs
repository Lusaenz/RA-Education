using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;

/// <summary>
/// GameManager del minijuego DragAndDrop.
/// Usa GameActivityService para obtener los datos de la BD.
/// Los 4 items y 4 zonas YA ESTÁN en la escena —
/// este script solo les asigna los datos del config_json.
/// </summary>
public class GameManager : MonoBehaviour
{
    public static GameManager instance;

    // ── Score ────────────────────────────────────────────────────────────
    public int score            = 0;
    public int puntosCorrecto   = 0;
    public int puntosIncorrecto = 0;
    public int maxScore         = 0;

    public TMP_Text   scoreText;
    public GameObject WinPanel;
    public Image[]    estrellas;
    public Sprite     estrellaLlena;
    public Sprite     estrellaVacia;
    public Transform  estrellasContainer;
    public Vector2    estrellaSize = new Vector2(90f, 90f);
    public float      starArcHeight = 70f;

    // ── Instrucción ──────────────────────────────────────────────────────
    [Header("Instrucción")]
    public TMP_Text instructionText;

    // ── Referencias a objetos en escena ──────────────────────────────────
    [Header("Items en escena (en orden a, b, c, d)")]
    public DragHandler[] items = new DragHandler[4];

    [Header("Zonas en escena (en orden zone_1, zone_2, zone_3, zone_4)")]
    public DropSlot[] zones = new DropSlot[4];

    // ── Internos ─────────────────────────────────────────────────────────
    private int totalItems    = 0;
    private int totalZones    = 0;
    private int correctItems  = 0;
    private int wrongAttempts = 0;
    private GameActivityService _gameActivityService;
    private readonly List<AsyncOperationHandle<Sprite>> _handles = new();
    private readonly List<GameObject> _generatedStarObjects = new();
    private float _pointsPerZone = 0f;
    private float _wrongPenaltyPerMistake = 0f;

    // ── Resultados ────────────────────────────────────────────────────
    private ActivityService _activityService;
    private ResultActivityService _resultService;

    private ActivityData _activityData;

    private int attempts = 0;
    private int idActivity;
    private int idUser = 1; // luego lo sacas de login
    private float _activityStartTime = 0f;


    // ── Ciclo de vida ────────────────────────────────────────────────────

    void Awake()
    {
        instance = this;
        _gameActivityService = new GameActivityService();
        _activityService = new ActivityService();
        _resultService = new ResultActivityService();
    }

    void Start()
    {
        int GameActivityId = PlayerPrefs.GetInt("selected_activity_id", 1);
        StartCoroutine(LoadActivity(GameActivityId));
    }

    // ── Carga desde BD ───────────────────────────────────────────────────

    IEnumerator LoadActivity(int idGameActivity)
{
    GameActivityData data = null;

    yield return StartCoroutine(_gameActivityService.GetGameActivity(idGameActivity, result => {
        data = result;
    }));

    if (data == null)
        yield break;

    idActivity = data.id_activity;

    // 🔥 NUEVO → traer configuración global
    yield return StartCoroutine(_activityService.GetActivity(idActivity, result =>
    {
        _activityData = result;
    }));

    if (_activityData == null)
    {
        Debug.LogError("No se pudo cargar activity");
        yield break;
    }

    DragDropConfig config = JsonConvert.DeserializeObject<DragDropConfig>(data.config_json);

    if (config == null)
    {
        Debug.LogError("[GameManager] config_json invalido o vacio.");
        yield break;
    }

    yield return StartCoroutine(SetupScene(config));
}
    // ── Setup de la escena ───────────────────────────────────────────────

    IEnumerator SetupScene(DragDropConfig config)
    {
        if (config.zones == null || config.zones.Count == 0)
        {
            Debug.LogError("[GameManager] La actividad no tiene zonas configuradas.");
            yield break;
        }

        if (config.items == null || config.items.Count == 0)
        {
            Debug.LogError("[GameManager] La actividad no tiene items configurados.");
            yield break;
        }

        totalZones = config.zones.Count;
        maxScore = Mathf.Max(1, _activityData.max_score);
        ConfigurarPuntaje();
        LimpiarEstrellasGeneradas();

        if (instructionText != null)
            instructionText.text = config.instruction;

        // Zonas
        for (int i = 0; i < config.zones.Count; i++)
        {
            if (i >= zones.Length || zones[i] == null)
            {
                Debug.LogWarning($"[GameManager] No hay DropSlot en el índice {i}");
                continue;
            }
            zones[i].SetupFromData(config.zones[i]);
        }

        // Items + sprites
        totalItems = config.items.Count;

        for (int i = 0; i < config.items.Count; i++)
        {
            if (i >= items.Length || items[i] == null)
            {
                Debug.LogWarning($"[GameManager] No hay DragHandler en el índice {i}");
                continue;
            }

            items[i].SetupFromData(config.items[i]);

            var handle = Addressables.LoadAssetAsync<Sprite>(config.items[i].image_key);
            _handles.Add(handle);
            yield return handle;

            if (handle.Status == AsyncOperationStatus.Succeeded)
                items[i].SetSprite(handle.Result);
            else
                Debug.LogError($"[GameManager] Sprite no encontrado: {config.items[i].image_key}");
        }

        _activityStartTime = Time.time;
        ActualizarUI();
    }

    // ── Score ────────────────────────────────────────────────────────────

    public void RespuestaCorrecta()
    {
        correctItems++;
        RecalcularPuntaje();
        VerificarVictoria();
    }

    public void RespuestaIncorrecta()
    {
        wrongAttempts++;
        RecalcularPuntaje();
    }

    void ActualizarUI()
    {
        if (scoreText != null)
            scoreText.text = ": " + score;
    }

    void ConfigurarPuntaje()
    {
        _pointsPerZone = maxScore / (float)totalZones;

        // Penalizacion fuerte: un error descuenta el valor de una zona correcta.
        _wrongPenaltyPerMistake = _pointsPerZone;

        puntosCorrecto = Mathf.Max(1, Mathf.RoundToInt(_pointsPerZone));
        puntosIncorrecto = -Mathf.Max(1, Mathf.RoundToInt(_wrongPenaltyPerMistake));

        RecalcularPuntaje();
    }

    void RecalcularPuntaje()
    {
        float rawScore = (correctItems * _pointsPerZone) - (wrongAttempts * _wrongPenaltyPerMistake);
        score = Mathf.Clamp(Mathf.RoundToInt(rawScore), 0, maxScore);
        ActualizarUI();
    }

    void VerificarVictoria()
    {
        if (correctItems >= totalItems)
            StartCoroutine(MostrarVictoria());
    }

    IEnumerator MostrarVictoria()
{
    yield return new WaitForSeconds(1f);

    WinPanel.SetActive(true);

    ActualizarEstrellas();

    int estrellasGanadas = CalcularEstrellasGanadas();

    attempts++;

    // 🔥 GUARDAR RESULTADO
    _resultService.SaveResult(
        idUser,
        idActivity,
        score,
        estrellasGanadas,
        attempts,
        ObtenerTiempoCompletado()
    );
}

    void ActualizarEstrellas()
    {
        int estrellasGanadas = CalcularEstrellasGanadas();
        PrepararPanelDeEstrellas(estrellasGanadas);
    }

    int CalcularEstrellasGanadas()
    {
        int maxStars = Mathf.Max(0, _activityData.max_star);

        if (maxStars == 0 || maxScore <= 0)
        {
            return 0;
        }

        float progreso = Mathf.Clamp01(score / (float)maxScore);
        return Mathf.Clamp(Mathf.RoundToInt(progreso * maxStars), 0, maxStars);
    }

    void PrepararPanelDeEstrellas(int estrellasGanadas)
    {
        LimpiarEstrellasGeneradas();

        if (estrellas != null)
        {
            foreach (Image estrella in estrellas)
            {
                if (estrella != null)
                {
                    estrella.gameObject.SetActive(false);
                }
            }
        }

        if (estrellasContainer == null && estrellas != null && estrellas.Length > 0 && estrellas[0] != null)
        {
            estrellasContainer = estrellas[0].transform.parent;
        }

        if (estrellasContainer == null)
        {
            estrellasContainer = WinPanel != null ? WinPanel.transform : null;
        }

        if (estrellasContainer == null)
        {
            Debug.LogWarning("[GameManager] No hay contenedor asignado para generar las estrellas.");
            estrellas = new Image[0];
            return;
        }

        if (estrellasGanadas <= 0)
        {
            estrellas = new Image[0];
            return;
        }

        estrellas = new Image[estrellasGanadas];

        for (int i = 0; i < estrellasGanadas; i++)
        {
            GameObject starObject = new GameObject($"Star_{i + 1}", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
            starObject.transform.SetParent(estrellasContainer, false);

            RectTransform rectTransform = starObject.GetComponent<RectTransform>();
            rectTransform.anchorMin = new Vector2(0.5f, 0.5f);
            rectTransform.anchorMax = new Vector2(0.5f, 0.5f);
            rectTransform.pivot = new Vector2(0.5f, 0.5f);
            rectTransform.sizeDelta = estrellaSize;
            rectTransform.anchoredPosition = ObtenerPosicionEstrella(i, estrellasGanadas);

            Image starImage = starObject.GetComponent<Image>();
            starImage.preserveAspect = true;
            starImage.sprite = estrellaLlena;

            estrellas[i] = starImage;
            _generatedStarObjects.Add(starObject);
        }
    }

    void LimpiarEstrellasGeneradas()
    {
        foreach (GameObject starObject in _generatedStarObjects)
        {
            if (starObject != null)
            {
                Destroy(starObject);
            }
        }

        _generatedStarObjects.Clear();
    }

    Vector2 ObtenerPosicionEstrella(int index, int totalStars)
    {
        RectTransform containerRect = estrellasContainer as RectTransform;
        float containerWidth = containerRect != null ? Mathf.Max(estrellaSize.x * totalStars, containerRect.rect.width) : estrellaSize.x * totalStars;
        float spacing = Mathf.Max(estrellaSize.x * 0.9f, Mathf.Min(180f, containerWidth / (totalStars + 1)));

        if (totalStars <= 1)
        {
            return Vector2.zero;
        }

        float centeredIndex = index - (totalStars - 1) * 0.5f;
        float x = centeredIndex * spacing;
        float normalizedDistance = totalStars <= 2 ? 1f : Mathf.Abs(centeredIndex) / ((totalStars - 1) * 0.5f);
        float y = (1f - normalizedDistance) * starArcHeight;

        return new Vector2(x, y);
    }

    // ── Limpieza ─────────────────────────────────────────────────────────

    string ObtenerTiempoCompletado()
    {
        float elapsedSeconds = Mathf.Max(0f, Time.time - _activityStartTime);
        int totalMinutes = Mathf.FloorToInt(elapsedSeconds / 60f);
        int seconds = Mathf.FloorToInt(elapsedSeconds % 60f);
        return $"{totalMinutes:00}:{seconds:00}";
    }

    void OnDestroy()
    {
        LimpiarEstrellasGeneradas();

        foreach (var handle in _handles)
            Addressables.Release(handle);
    }
}
