using System.Collections;
using System.Collections.Generic;
using Newtonsoft.Json;
using TMPro;
using UnityEngine;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;

/// <summary>
/// Lógica principal del Drag & Drop:
/// - Carga BD
/// - Configura escena
/// - Maneja score
/// - Detecta victoria
/// </summary>
public class GameManager : MonoBehaviour
{
    public static GameManager instance;

    [Header("Score")]
    public int score = 0;
    public int maxScore = 0;
    public int puntosCorrecto = 0;
    public int puntosIncorrecto = 0;

    [Header("UI Referencias")]
    public TMP_Text scoreText;
    public TMP_Text instructionText;

    [Header("Victory UI (DEPENDENCIA)")]
    public VictoryUIManager victoryUI;

    [Header("Gameplay")]
    public DragHandler[] items = new DragHandler[4];
    public DropSlot[] zones = new DropSlot[4];

    private int totalItems;
    private int totalZones;
    private int correctItems;
    private int wrongAttempts;

    private float pointsPerZone;
    private float wrongPenalty;

    private float startTime;

    private ActivityData activityData;
    private int idActivity;
    private int idUser;
    private int attempts;

    private GameActivityService gameActivityService;
    private ActivityService activityService;
    private ResultActivityService resultService;

    private readonly List<AsyncOperationHandle<Sprite>> handles = new();

    private const int DefaultGameActivityId = 1;

    private void Awake()
    {
        if (instance != null && instance != this)
        {
            Destroy(gameObject);
            return;
        }
        instance = this;

        gameActivityService = new GameActivityService();
        activityService = new ActivityService();
        resultService = new ResultActivityService();
    }

    private void Start()
    {
        StartCoroutine(BootstrapGame());
    }

    private IEnumerator BootstrapGame()
    {
        int gameActivityId = PlayerPrefs.GetInt("selected_activity_id", DefaultGameActivityId);

        yield return StartCoroutine(LoadActivity(gameActivityId));
    }

    private IEnumerator LoadActivity(int idGameActivity)
    {
        GameActivityData data = null;

        yield return StartCoroutine(gameActivityService.GetGameActivity(idGameActivity, r => data = r));

        if (data == null) yield break;

        idActivity = data.id_activity;

        yield return StartCoroutine(activityService.GetActivity(idActivity, r => activityData = r));

        DragDropConfig config = JsonConvert.DeserializeObject<DragDropConfig>(data.config_json);

        yield return StartCoroutine(Setup(config));
    }

    private IEnumerator Setup(DragDropConfig config)
    {
          Reset();
        if (instructionText != null)
{
    instructionText.text = config.instruction;
}
      


        maxScore = Mathf.Max(1, activityData.max_score);

        

        totalItems = config.items.Count;
        totalZones = config.zones.Count;
        ConfigureScore();

        for (int i = 0; i < config.items.Count; i++)
        {
            items[i].SetupFromData(config.items[i]);

            var handle = Addressables.LoadAssetAsync<Sprite>(config.items[i].image_key);
            handles.Add(handle);
            yield return handle;

            if (handle.Status == AsyncOperationStatus.Succeeded)
                items[i].SetSprite(handle.Result);
        }

        for (int i = 0; i < config.zones.Count; i++)
        {
            zones[i].SetupFromData(config.zones[i]);
        }

        startTime = Time.time;
        UpdateUI();
    }

    public void RespuestaCorrecta()
    {
        correctItems++;
        RecalculateScore();
        CheckWin();
    }

    public void RespuestaIncorrecta()
    {
        wrongAttempts++;
        RecalculateScore();
    }

    private void ConfigureScore()
    {
        pointsPerZone = maxScore / (float)Mathf.Max(1, totalZones);

        wrongPenalty = pointsPerZone;

        puntosCorrecto = Mathf.Max(1, Mathf.RoundToInt(pointsPerZone));
    puntosIncorrecto = -Mathf.Max(1, Mathf.RoundToInt(wrongPenalty));
;
    }

    private void RecalculateScore()
    {
        float raw = (correctItems * pointsPerZone) - (wrongAttempts * wrongPenalty);
        score = Mathf.Clamp(Mathf.RoundToInt(raw), 0, maxScore);
        UpdateUI();
    }

    private void UpdateUI()
    {
        if (scoreText != null)
            scoreText.text = ": " + score;
    }

    private void CheckWin()
    {
        if (correctItems >= totalItems)
            StartCoroutine(WinRoutine());
    }

    private IEnumerator WinRoutine()
    {
        yield return new WaitForSeconds(1f);

        int stars = CalculateStars();

    // Solo muestra la UI
    victoryUI.ShowVictory(score, maxScore, stars);

        SaveResult(stars);
    }

    private void SaveResult(int stars)
    {
        attempts++;

        var user = UserSessionManager.Instance?.CurrentUser;
        if (user == null) return;

        resultService.SaveResult(
            user.id_user,
            idActivity,
            score,
            stars,
            attempts,
            GetTime()
        );
    }

    private string GetTime()
    {
        float t = Time.time - startTime;
        return $"{Mathf.FloorToInt(t / 60):00}:{Mathf.FloorToInt(t % 60):00}";
    }

    private void Reset()
    {
        score = 0;
        correctItems = 0;
        wrongAttempts = 0;
        attempts = 0;
    }

    private int CalculateStars()
{
    if (activityData == null || activityData.max_star <= 0 || maxScore <= 0)
        return 0;

    float progreso = Mathf.Clamp01(score / (float)maxScore);

    return Mathf.Clamp(
        Mathf.RoundToInt(progreso * activityData.max_star),
        0,
        activityData.max_star
    );
}

    private void OnDestroy()
    {
        foreach (var h in handles)
            if (h.IsValid()) Addressables.Release(h);
    }
}