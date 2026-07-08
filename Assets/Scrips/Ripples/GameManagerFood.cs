using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
using UnityEngine;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;
using UnityEngine.UI;

public class GameManagerFood : MonoBehaviour
{
    public static GameManagerFood instance;

    private const string DatabaseManagerObjectName = "DatabaseManager_Auto";
    private const int DefaultGameActivityId = 3;

    [Header("Puntaje")]
    public int score = 0;
    public int maxScore = 0;

    [Header("UI")]
    public TMP_Text scoreText;
    public GameObject winPanel;
    public TMP_Text textoInstruccion;
    public TMP_Text textoAcertijo;

    [Header("Estrellas")]
    public Image[] estrellas;
    public Sprite estrellaLlena;
    public Sprite estrellaVacia;

    [Header("Items en escena (mismo orden que config_json)")]
    public DragHandler[] items;

    [Header("Slot de destino")]
    public Mouth dropSlot;

    [Header("Randomizador")]
    public RandomizarOrganos randomizador;

    private List<FoodRiddleLevel> _levels;
    private int _indiceActual = 0;

    private GameActivityService _gameActivityService;
    private ActivityService _activityService;
    private ResultActivityService _resultService;
    private ActivityData _activityData;

    private readonly List<AsyncOperationHandle<Sprite>> _handles = new();
    private static readonly WaitForSeconds WaitOneSecond = new(1f);

    private float _activityStartTime = 0f;
    private int _idActivity;
    private int _idUser;
    private int _attempts = 0;

    private void Awake()
    {
        if (instance != null && instance != this) { Destroy(gameObject); return; }
        instance = this;
        _gameActivityService = new GameActivityService();
        _activityService = new ActivityService();
        _resultService = new ResultActivityService();
        EnsureDatabaseManagerExists();
    }

    private void Start()
    {
        StartCoroutine(BootstrapGame());
    }

    private IEnumerator BootstrapGame()
    {
        if (winPanel != null)
        {
            winPanel.SetActive(false);
            winPanel.transform.localScale = Vector3.one;
        }

        EnsureDatabaseManagerExists();
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);
        ResolveLoggedInUser();

        int gameActivityId = PlayerPrefs.GetInt("selected_activity_id", DefaultGameActivityId);
        gameActivityId = gameActivityId > 0 ? gameActivityId : DefaultGameActivityId;
        PlayerPrefs.SetInt("selected_activity_id", gameActivityId);
        PlayerPrefs.Save();

        yield return StartCoroutine(LoadActivity(gameActivityId));
    }

    private IEnumerator LoadActivity(int idGameActivity)
    {
        GameActivityData data = null;
        yield return StartCoroutine(_gameActivityService.GetGameActivity(idGameActivity, result => data = result));

        if (data == null)
        {
            Debug.LogError($"[GameManagerFood] No se encontró game_activity con id {idGameActivity}.");
            yield break;
        }

        _idActivity = data.id_activity;

        yield return StartCoroutine(_activityService.GetActivity(_idActivity, result => _activityData = result));

        if (_activityData == null)
        {
            Debug.LogError("[GameManagerFood] No se pudo cargar activity.");
            yield break;
        }

        if (string.IsNullOrWhiteSpace(data.config_json))
        {
            Debug.LogError("[GameManagerFood] config_json vacío.");
            yield break;
        }

        FoodRiddlesConfig config = null;
        try
        {
            config = JsonConvert.DeserializeObject<FoodRiddlesConfig>(data.config_json);
        }
        catch (System.Exception ex)
        {
            Debug.LogError("[GameManagerFood] Error al leer config_json: " + ex.Message);
            yield break;
        }

        if (config?.levels == null || config.levels.Count == 0)
        {
            Debug.LogError("[GameManagerFood] La actividad no tiene niveles configurados.");
            yield break;
        }

        yield return StartCoroutine(SetupScene(config));
    }

    private IEnumerator SetupScene(FoodRiddlesConfig config)
    {
        _levels = config.levels;
        _levels.Sort((a, b) => a.order.CompareTo(b.order));
        _indiceActual = 0;

        maxScore = _activityData != null ? Mathf.Max(1, _activityData.max_score) : 100;
        score = 0;

        if (config.items != null)
        {
            for (int i = 0; i < config.items.Count; i++)
            {
                if (i >= items.Length || items[i] == null)
                {
                    Debug.LogWarning($"[GameManagerFood] No hay DragHandler asignado en el índice {i}.");
                    continue;
                }

                FoodRiddleItem foodItem = config.items[i];
                items[i].itemId = foodItem.id;

                if (string.IsNullOrWhiteSpace(foodItem.addressableKey)) continue;

                AsyncOperationHandle<Sprite> handle = Addressables.LoadAssetAsync<Sprite>(foodItem.addressableKey);
                _handles.Add(handle);
                yield return handle;

                if (handle.Status == AsyncOperationStatus.Succeeded)
                    items[i].SetSprite(handle.Result);
                else
                    Debug.LogWarning($"[GameManagerFood] Sprite no encontrado: {foodItem.addressableKey}");
            }
        }

        if (randomizador != null) randomizador.MezclarHijos();
        ActualizarUI();
        ActualizarTexto();
        _activityStartTime = Time.time;
    }

    public bool EvaluarItem(string idItem)
    {
        if (_levels == null || _indiceActual >= _levels.Count) return false;

        if (idItem == _levels[_indiceActual].correctItemId)
        {
            RespuestaCorrecta();
            _indiceActual++;
            if (randomizador != null) randomizador.MezclarHijos();

            if (_indiceActual >= _levels.Count)
                StartCoroutine(MostrarVictoria());
            else
                ActualizarTexto();

            return true;
        }
        else
        {
            RespuestaIncorrecta();
            return false;
        }
    }

    public void RespuestaCorrecta()
    {
        int puntosCorrecto = Mathf.Max(1, maxScore / Mathf.Max(1, _levels != null ? _levels.Count : 1));
        score = Mathf.Min(score + puntosCorrecto, maxScore);
        ActualizarUI();
        if (SoundManager.instance != null) SoundManager.instance.PlayCorrect();
    }

    public void RespuestaIncorrecta()
    {
        int puntosIncorrecto = Mathf.Max(1, maxScore / Mathf.Max(1, _levels != null ? _levels.Count : 1));
        score = Mathf.Max(score - puntosIncorrecto, 0);
        ActualizarUI();
        if (SoundManager.instance != null) SoundManager.instance.PlayWrong();
    }

    private void ActualizarUI()
    {
        if (scoreText != null) scoreText.text = ": " + score;
    }

    private void ActualizarTexto()
    {
        if (_levels == null || _indiceActual >= _levels.Count) return;
        string riddle = _levels[_indiceActual].riddle;
        if (textoInstruccion != null) textoInstruccion.text = riddle;
        if (textoAcertijo != null) textoAcertijo.text = riddle;
    }

    private IEnumerator MostrarVictoria()
    {
        yield return WaitOneSecond;
        yield return StartCoroutine(AnimarPanelVictoria());
        ActualizarEstrellas();

        _attempts++;
        ResolveLoggedInUser();
        if (_idUser <= 0)
        {
            Debug.LogWarning("[GameManagerFood] No hay usuario logeado. No se guardará result_activity.");
            yield break;
        }

        _resultService.SaveResult(
            _idUser,
            _idActivity,
            score,
            CalcularEstrellasGanadas(),
            _attempts,
            ObtenerTiempoCompletado());
    }

    private IEnumerator AnimarPanelVictoria()
    {
        if (winPanel == null) yield break;

        winPanel.SetActive(true);
        winPanel.transform.localScale = Vector3.zero;

        float t = 0f;
        const float dur = 0.4f;
        while (t < dur)
        {
            t += Time.deltaTime;
            float s = Mathf.Lerp(0f, 1f, t / dur);
            winPanel.transform.localScale = new Vector3(s, s, s);
            yield return null;
        }

        winPanel.transform.localScale = Vector3.one;
    }

    private void ActualizarEstrellas()
    {
        if (indiceActual == textos.Count)
        {
           
            //GameManager.instance.MostrarVictoria(score, 40);
        }
    }
}
