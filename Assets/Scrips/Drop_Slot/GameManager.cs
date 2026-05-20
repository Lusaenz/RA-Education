using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
using UnityEngine;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;
using UnityEngine.Serialization;
using UnityEngine.UI;

/// <summary>
/// GameManager del minijuego DragAndDrop.
/// Obtiene la configuracion desde BD y asigna los datos
/// a los items y zonas que ya existen en escena.
/// </summary>
public class GameManager : MonoBehaviour
{
    public static GameManager instance;
    private const string DatabaseManagerObjectName = "DatabaseManager_Auto";
    private const int DefaultGameActivityId = 1;

    [Header("Score")]
    public int score = 0;
    public int puntosCorrecto = 0;
    public int puntosIncorrecto = 0;
    public int maxScore = 0;

    public TMP_Text scoreText;

    [FormerlySerializedAs("winPanel")]
    public GameObject WinPanel;

    [Header("Estrellas")]
    public Image[] estrellas;
    public Sprite estrellaLlena;
    public Sprite estrellaVacia;
    public Transform estrellasContainer;
    public Vector2 estrellaSize = new Vector2(90f, 90f);
    public float starArcHeight = 70f;

    [Header("Instruccion")]
    public TMP_Text instructionText;

    [Header("Items en escena (en orden a, b, c, d)")]
    public DragHandler[] items = new DragHandler[4];

    [Header("Zonas en escena (en orden zone_1, zone_2, zone_3, zone_4)")]
    public DropSlot[] zones = new DropSlot[4];

    private int totalItems = 0;
    private int totalZones = 0;
    private int correctItems = 0;
    private int wrongAttempts = 0;

    private GameActivityService _gameActivityService;
    private ActivityService _activityService;
    private ResultActivityService _resultService;

    private readonly List<AsyncOperationHandle<Sprite>> _handles = new List<AsyncOperationHandle<Sprite>>();
    private readonly List<GameObject> _generatedStarObjects = new List<GameObject>();

    private float _pointsPerZone = 0f;
    private float _wrongPenaltyPerMistake = 0f;
    private float _activityStartTime = 0f;

    private ActivityData _activityData;

    private int attempts = 0;
    private int idActivity;
    private int idUser;

    private void Awake()
    {
        if (instance != null && instance != this)
        {
            Destroy(gameObject);
            return;
        }

        instance = this;
        _gameActivityService = new GameActivityService();
        _activityService = new ActivityService();
        _resultService = new ResultActivityService();
        EnsureDatabaseManagerExists();
        ResolveSceneReferences();
    }

    private void Start()
    {
        StartCoroutine(BootstrapGame());
    }

    private IEnumerator BootstrapGame()
    {
        if (WinPanel != null)
        {
            WinPanel.SetActive(false);
            WinPanel.transform.localScale = Vector3.one;
        }

        EnsureDatabaseManagerExists();
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);
        ResolveLoggedInUser();

        int gameActivityId = NormalizeGameActivityId(PlayerPrefs.GetInt("selected_activity_id", DefaultGameActivityId));
        PlayerPrefs.SetInt("selected_activity_id", gameActivityId);
        PlayerPrefs.Save();
        yield return StartCoroutine(LoadActivity(gameActivityId));
    }

    private IEnumerator LoadActivity(int idGameActivity)
    {
        idGameActivity = NormalizeGameActivityId(idGameActivity);

        GameActivityData data = null;

        yield return StartCoroutine(_gameActivityService.GetGameActivity(idGameActivity, result =>
        {
            data = result;
        }));

        if (data == null)
        {
            Debug.LogError($"[GameManager] No se encontro game_activity con id {idGameActivity}.");
            yield break;
        }

        idActivity = data.id_activity;

        yield return StartCoroutine(_activityService.GetActivity(idActivity, result =>
        {
            _activityData = result;
        }));

        if (_activityData == null)
        {
            Debug.LogError("[GameManager] No se pudo cargar activity.");
            yield break;
        }

        if (string.IsNullOrWhiteSpace(data.config_json))
        {
            Debug.LogError("[GameManager] config_json vacio.");
            yield break;
        }

        DragDropConfig config = null;

        try
        {
            config = JsonConvert.DeserializeObject<DragDropConfig>(data.config_json);
        }
        catch (System.Exception ex)
        {
            Debug.LogError("[GameManager] Error al leer config_json: " + ex.Message);
            yield break;
        }

        if (config == null)
        {
            Debug.LogError("[GameManager] config_json invalido.");
            yield break;
        }

        yield return StartCoroutine(SetupScene(config));
    }

    private IEnumerator SetupScene(DragDropConfig config)
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

        ResetGameState();

        if (instructionText != null)
        {
            instructionText.text = config.instruction;
        }

        totalZones = 0;
        for (int i = 0; i < config.zones.Count; i++)
        {
            if (i >= zones.Length || zones[i] == null)
            {
                Debug.LogWarning($"[GameManager] No hay DropSlot asignado en el indice {i}.");
                continue;
            }

            zones[i].SetupFromData(config.zones[i]);
            totalZones++;
        }

        totalItems = 0;
        for (int i = 0; i < config.items.Count; i++)
        {
            if (i >= items.Length || items[i] == null)
            {
                Debug.LogWarning($"[GameManager] No hay DragHandler asignado en el indice {i}.");
                continue;
            }

            items[i].SetupFromData(config.items[i]);
            totalItems++;

            if (string.IsNullOrWhiteSpace(config.items[i].image_key))
            {
                Debug.LogWarning($"[GameManager] image_key vacio para item {config.items[i].id}.");
                continue;
            }

            AsyncOperationHandle<Sprite> handle = Addressables.LoadAssetAsync<Sprite>(config.items[i].image_key);
            _handles.Add(handle);
            yield return handle;

            if (handle.Status == AsyncOperationStatus.Succeeded)
            {
                items[i].SetSprite(handle.Result);
            }
            else
            {
                Debug.LogError($"[GameManager] Sprite no encontrado: {config.items[i].image_key}");
            }
        }

        if (totalZones <= 0 || totalItems <= 0)
        {
            Debug.LogError("[GameManager] No hay suficientes referencias validas para iniciar el juego.");
            yield break;
        }

        maxScore = Mathf.Max(1, _activityData.max_score);
        ConfigurarPuntaje();
        _activityStartTime = Time.time;
        ActualizarUI();
    }

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

    private void ActualizarUI()
    {
        if (scoreText != null)
        {
            scoreText.text = ": " + score;
        }
    }

    private void ConfigurarPuntaje()
    {
        _pointsPerZone = maxScore / (float)Mathf.Max(1, totalZones);
        _wrongPenaltyPerMistake = _pointsPerZone;

        puntosCorrecto = Mathf.Max(1, Mathf.RoundToInt(_pointsPerZone));
        puntosIncorrecto = -Mathf.Max(1, Mathf.RoundToInt(_wrongPenaltyPerMistake));

        RecalcularPuntaje();
    }

    private void RecalcularPuntaje()
    {
        float rawScore = (correctItems * _pointsPerZone) - (wrongAttempts * _wrongPenaltyPerMistake);
        score = Mathf.Clamp(Mathf.RoundToInt(rawScore), 0, maxScore);
        ActualizarUI();
    }

    private void VerificarVictoria()
    {
        if (correctItems >= totalItems)
        {
            StartCoroutine(MostrarVictoria());
        }
    }

    public void MostrarVictoria(int scoreValue, int maxScoreValue)
    {
        StartCoroutine(MostrarVictoriaLegacy(scoreValue, maxScoreValue));
    }

    private IEnumerator MostrarVictoria()
    {
        yield return new WaitForSeconds(1f);

        yield return StartCoroutine(AnimarPanelVictoria());

        ActualizarEstrellas();

        int estrellasGanadas = CalcularEstrellasGanadas();
        attempts++;

        ResolveLoggedInUser();
        if (idUser <= 0)
        {
            Debug.LogWarning("[GameManager] No hay un usuario logeado valido. No se guardara result_activity.");
            yield break;
        }

        _resultService.SaveResult(
            idUser,
            idActivity,
            score,
            estrellasGanadas,
            attempts,
            ObtenerTiempoCompletado());
    }

    private IEnumerator MostrarVictoriaLegacy(int scoreValue, int maxScoreValue)
    {
        yield return new WaitForSeconds(1f);
        yield return StartCoroutine(AnimarPanelVictoria());

        int totalEstrellas = estrellas != null ? estrellas.Length : 0;
        if (totalEstrellas <= 0 || maxScoreValue <= 0)
        {
            yield break;
        }

        int estrellasGanadas = Mathf.Clamp(
            Mathf.RoundToInt(scoreValue / (float)maxScoreValue * totalEstrellas),
            0,
            totalEstrellas);

        for (int i = 0; i < totalEstrellas; i++)
        {
            if (estrellas[i] == null)
            {
                continue;
            }

            estrellas[i].gameObject.SetActive(true);
            estrellas[i].sprite = i < estrellasGanadas ? estrellaLlena : estrellaVacia;
        }
    }

    private void ActualizarEstrellas()
    {
        int estrellasGanadas = CalcularEstrellasGanadas();
        PrepararPanelDeEstrellas(estrellasGanadas);
    }

    private int CalcularEstrellasGanadas()
    {
        int maxStars = _activityData != null ? Mathf.Max(0, _activityData.max_star) : 0;

        if (maxStars == 0 || maxScore <= 0)
        {
            return 0;
        }

        float progreso = Mathf.Clamp01(score / (float)maxScore);
        return Mathf.Clamp(Mathf.RoundToInt(progreso * maxStars), 0, maxStars);
    }

    private void PrepararPanelDeEstrellas(int estrellasGanadas)
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

    private void LimpiarEstrellasGeneradas()
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

    private Vector2 ObtenerPosicionEstrella(int index, int totalStars)
    {
        RectTransform containerRect = estrellasContainer as RectTransform;
        float minWidth = estrellaSize.x * totalStars;
        float containerWidth = containerRect != null ? Mathf.Max(minWidth, containerRect.rect.width) : minWidth;
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

    private string ObtenerTiempoCompletado()
    {
        float elapsedSeconds = Mathf.Max(0f, Time.time - _activityStartTime);
        int totalMinutes = Mathf.FloorToInt(elapsedSeconds / 60f);
        int seconds = Mathf.FloorToInt(elapsedSeconds % 60f);
        return $"{totalMinutes:00}:{seconds:00}";
    }

    private IEnumerator AnimarPanelVictoria()
    {
        if (WinPanel == null)
        {
            yield break;
        }

        WinPanel.SetActive(true);
        WinPanel.transform.localScale = Vector3.zero;

        float tiempo = 0f;
        const float duracion = 0.4f;

        while (tiempo < duracion)
        {
            tiempo += Time.deltaTime;
            float escala = Mathf.Lerp(0f, 1f, tiempo / duracion);
            WinPanel.transform.localScale = new Vector3(escala, escala, escala);
            yield return null;
        }

        WinPanel.transform.localScale = Vector3.one;
    }

    private void ResetGameState()
    {
        score = 0;
        totalItems = 0;
        totalZones = 0;
        correctItems = 0;
        wrongAttempts = 0;
        attempts = 0;
        puntosCorrecto = 0;
        puntosIncorrecto = 0;
        maxScore = 0;

        if (WinPanel != null)
        {
            WinPanel.SetActive(false);
            WinPanel.transform.localScale = Vector3.one;
        }

        LimpiarEstrellasGeneradas();
    }

    private void OnDestroy()
    {
        if (instance == this)
        {
            instance = null;
        }

        LimpiarEstrellasGeneradas();

        foreach (AsyncOperationHandle<Sprite> handle in _handles)
        {
            if (handle.IsValid())
            {
                Addressables.Release(handle);
            }
        }
    }

    private void EnsureDatabaseManagerExists()
    {
        if (DatabaseManager.Instance != null)
        {
            return;
        }

        GameObject databaseManagerObject = new GameObject(DatabaseManagerObjectName);
        databaseManagerObject.AddComponent<DatabaseManager>();
    }

    private void ResolveSceneReferences()
    {
        if (scoreText == null)
        {
            if (GameManagerJuego.instance != null && GameManagerJuego.instance.scoreText != null)
            {
                scoreText = GameManagerJuego.instance.scoreText;
            }
            else
            {
                scoreText = FindTextByNameHint("score");
            }
        }

        if (instructionText == null)
        {
            instructionText = FindTextByNameHint("instruction", "instru", "indicacion");
        }
    }

    private TMP_Text FindTextByNameHint(params string[] hints)
    {
        TMP_Text[] texts = FindObjectsByType<TMP_Text>(FindObjectsInactive.Include, FindObjectsSortMode.None);
        foreach (TMP_Text text in texts)
        {
            if (text == null)
            {
                continue;
            }

            string textName = text.gameObject.name.ToLowerInvariant();
            foreach (string hint in hints)
            {
                if (textName.Contains(hint))
                {
                    return text;
                }
            }
        }

        return null;
    }

    private int NormalizeGameActivityId(int gameActivityId)
    {
        int normalizedId = gameActivityId > 0 ? gameActivityId : DefaultGameActivityId;

        if (normalizedId != gameActivityId)
        {
            Debug.LogWarning($"[GameManager] game_activity inválido ({gameActivityId}). Se usará {normalizedId}.");
        }

        return normalizedId;
    }

    private void ResolveLoggedInUser()
    {
        UserModel currentUser = UserSessionManager.Instance?.CurrentUser;
        if (currentUser == null)
        {
            return;
        }

        idUser = currentUser.id_user;
    }
}
