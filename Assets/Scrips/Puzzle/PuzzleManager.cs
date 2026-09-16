using System.Collections;
using UnityEngine;
using TMPro;

public class PuzzleManager : MonoBehaviour
{
    public static PuzzleManager instance;

    private const int DefaultGameActivityId = 4;

    [Header("Gameplay")]
    public int correctItems = 0;
    public int totalItems = 7;
    public int score = 0;

    private bool hasWon = false;

    [Header("UI del Minijuego")]
    [Tooltip("Arrastra aquí el Panel o Canvas del minijuego que debe ocultarse al ganar")]
    public GameObject gameInfoUI;

    public TMP_Text scoreText;
    public TMP_Text puntos;

    public int maxScore;
    public int maxStars = 5;

    public TMP_Text nombrePiezaText;
    public TMP_Text targetNameText;

    private GameActivityService _gameActivityService;
    private ActivityService _activityService;
    private ResultActivityService _resultService;
    private ProgressService _progressService;

    private int _idActivity;
    private int _idModule;
    private int _idGameActivity;
    private int _maxStarFromDb;
    private int _attempts;
    private float _startTime;
    private bool _resultSaved;

    void Awake()
    {
        instance = this;
        maxScore = totalItems * 10;

        _gameActivityService = new GameActivityService();
        _activityService = new ActivityService();
        _resultService = new ResultActivityService();
        _progressService = new ProgressService();

        ActualizarScoreUI();

        // REGISTRO INMEDIATO: Registramos el panel info tan pronto despierta el Manager
        RegistrarUI();
    }


    void Start()
    {
        _startTime = Time.time;
        StartCoroutine(LoadActivityData());
    }

    private void RegistrarUI()
    {
        if (VictoryUIManager.Instance != null && gameInfoUI != null)
        {
            VictoryUIManager.Instance.SetInfoUI(gameInfoUI);
        }
    }

    private IEnumerator LoadActivityData()
    {
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        int gameActivityId = PlayerPrefs.GetInt("selected_activity_id", DefaultGameActivityId);
        gameActivityId = gameActivityId > 0 ? gameActivityId : DefaultGameActivityId;

        GameActivityData data = null;
        yield return StartCoroutine(_gameActivityService.GetGameActivity(gameActivityId, r => data = r));

        if (data == null)
        {
            Debug.LogWarning($"[PuzzleManager] No se encontro game_activity con id {gameActivityId}. No se podra registrar el avance del modulo.");
            yield break;
        }

        _idActivity = data.id_activity;
        _idModule = data.id_module;
        _idGameActivity = data.id_game_activity;

        ActivityData activity = null;
        yield return StartCoroutine(_activityService.GetActivity(_idActivity, r => activity = r));
        if (activity != null && activity.max_star > 0)
        {
            _maxStarFromDb = activity.max_star;
        }
    }

    public void ItemCorrecto()
    {
        Debug.Log("ItemCorrecto fue llamado");

        if (hasWon) return;

        correctItems++;
        score += 10;
        puntos.text = "Item Correcto";

        ActualizarScoreUI();
        VerificarVictoria();

        if (SoundManager.instance != null)
        {
            SoundManager.instance.PlayCorrect();
        }
    }

    void VerificarVictoria()
    {
        if (correctItems >= totalItems)
        {
            hasWon = true;

            if (VictoryUIManager.Instance != null)
            {
                // Nos aseguramos nuevamente de que la referencia de la UI esté asignada justo antes de lanzar la victoria
                RegistrarUI();
                
                VictoryUIManager.Instance.ShowVictory(score, maxScore, maxStars);
                Debug.Log("¡Puzzle completo!");
            }
            else
            {
                Debug.LogError("No se asignó el VictoryUIManager en el PuzzleManager.");
            }

            GuardarResultado();
        }
    }

    /// <summary>
    /// Guarda el resultado en result_activity y marca el minijuego como item completado
    /// del modulo (solo si se obtuvo al menos 1 estrella).
    /// </summary>
    private void GuardarResultado()
    {
        if (_resultSaved)
        {
            return;
        }
        _resultSaved = true;

        var user = UserSessionManager.Instance?.CurrentUser;
        if (user == null)
        {
            Debug.LogWarning("[PuzzleManager] No hay usuario en sesion. No se guardara el resultado.");
            return;
        }

        int starMax = _maxStarFromDb > 0 ? _maxStarFromDb : maxStars;
        int stars = maxScore <= 0
            ? 0
            : Mathf.Clamp(Mathf.RoundToInt(Mathf.Clamp01(score / (float)maxScore) * starMax), 0, starMax);

        _attempts++;

        _resultService.SaveResult(user.id_user, _idActivity, score, stars, _attempts, GetElapsedTime());
        _progressService.MarkGameCompleted(user.id_user, _idModule, _idGameActivity, stars);
    }

    private string GetElapsedTime()
    {
        float t = Time.time - _startTime;
        return $"{Mathf.FloorToInt(t / 60):00}:{Mathf.FloorToInt(t % 60):00}";
    }

    public void ItemIncorrecto()
    {
        Debug.Log("ENTRÓ A ItemIncorrecto");

        if (hasWon) return;

        score -= 10;
        puntos.text = "Item incorrecto";
        if (score < 0)
            score = 0;

        ActualizarScoreUI();

        if (SoundManager.instance != null)
        {
            SoundManager.instance.PlayWrong();
        }
    }

    void ActualizarScoreUI()
    {
        if (scoreText != null)
        {
            scoreText.text = "Puntaje: " + score;
        }
    }

    public void MostrarNombre(string nombre)
    {
        if (nombrePiezaText != null)
        {
            nombrePiezaText.text = "Pieza: " + nombre;
        }
    }

    public void OcultarNombre()
    {
        if (nombrePiezaText != null)
        {
            nombrePiezaText.text = "Pieza: ";
        }
    }

    public void MostrarTarget(string nombre)
    {
        if (targetNameText != null)
        {
            targetNameText.text = "Objetivo: " + nombre;
        }
    }

    public void OcultarTarget()
    {
        if (targetNameText != null)
        {
            targetNameText.text = "Objetivo: -";
        }
    }
}