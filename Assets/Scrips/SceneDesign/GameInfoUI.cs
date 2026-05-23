using System.Collections;
using TMPro;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.Serialization;
using UnityEngine.UI;

public class GameInfoUI : MonoBehaviour
{
    private const int DefaultGameActivityId = 1;

    [FormerlySerializedAs("activityTitleText")]
    public TextMeshProUGUI titleText;

    [FormerlySerializedAs("activityDescriptionText")]
    public TextMeshProUGUI descriptionText;

    public Image previewImage;
    public GameObject panel;
    public GameData[] games;

    [Header("Preview Image Loader")]
    [SerializeField] private PreviewImageLoader previewImageLoader;

    [SerializeField] private string dragAndDropSceneName = "DragAndDrop";

    private ActivityService activityService;
    private GameActivityService gameActivityService;
    private int currentGameID;

    private void Awake()
    {
        activityService = new ActivityService();
        gameActivityService = new GameActivityService();
        ResolveFallbackGameDefinitions();
    }

    private void Start()
    {
        StartCoroutine(LoadSelectedActivityInfo());
    }

    private IEnumerator LoadSelectedActivityInfo()
    {
        int selectedGameActivityId = NormalizeGameActivityId(PlayerPrefs.GetInt("selected_activity_id", DefaultGameActivityId));
        yield return StartCoroutine(LoadGameInfo(selectedGameActivityId, true));
    }

    public void ShowGame(int gameID)
    {
        currentGameID = NormalizeGameActivityId(gameID);
        PlayerPrefs.SetInt("selected_activity_id", currentGameID);
        PlayerPrefs.Save();

        if (panel != null)
        {
            panel.SetActive(true);
        }

        StartCoroutine(LoadGameInfo(currentGameID, false));
    }

    private IEnumerator LoadGameInfo(int gameActivityId, bool keepPanelClosedOnFailure)
    {
        ResolveFallbackGameDefinitions();

        GameActivityData gameActivity = null;
        yield return StartCoroutine(gameActivityService.GetGameActivity(gameActivityId, result =>
        {
            gameActivity = result;
        }));

        if (gameActivity == null)
        {
            if (!TryApplyFallbackGameData(gameActivityId))
            {
                SetTexts("Actividad no disponible", "No se pudo cargar la configuracion del juego.");
                if (keepPanelClosedOnFailure && panel != null)
                {
                    panel.SetActive(false);
                }
            }

            yield break;
        }

        ActivityData activity = null;
        yield return StartCoroutine(activityService.GetActivity(gameActivity.id_activity, result =>
        {
            activity = result;
        }));

        if (activity == null)
        {
            if (!TryApplyFallbackGameData(gameActivityId))
            {
                SetTexts("Actividad no disponible", "No se pudo cargar la informacion de la actividad.");
                if (keepPanelClosedOnFailure && panel != null)
                {
                    panel.SetActive(false);
                }
            }

            yield break;
        }

        SetTexts(activity.type, activity.description);
        ApplyPreviewForGame(gameActivityId);

        if (panel != null && !panel.activeSelf)
        {
            panel.SetActive(true);
        }
    }

    private void ResolveFallbackGameDefinitions()
    {
        if (games != null && games.Length > 0)
        {
            return;
        }

        GameInfoUI[] candidates = FindObjectsByType<GameInfoUI>(FindObjectsInactive.Include, FindObjectsSortMode.None);
        foreach (GameInfoUI candidate in candidates)
        {
            if (candidate == null || candidate == this)
            {
                continue;
            }

            if (candidate.games != null && candidate.games.Length > 0)
            {
                games = candidate.games;
                return;
            }
        }
    }

    private bool TryApplyFallbackGameData(int gameActivityId)
    {
        ResolveFallbackGameDefinitions();
        GameData fallbackData = GetFallbackGameData(gameActivityId);
        if (fallbackData == null)
        {
            return false;
        }

        SetTexts(fallbackData.title, fallbackData.description);

        if (previewImageLoader != null)
        {
            previewImageLoader.LoadPreviewByGameId(gameActivityId);
        }
        else if (previewImage != null && fallbackData.preview != null)
        {
            previewImage.sprite = fallbackData.preview;
        }

        if (panel != null && !panel.activeSelf)
        {
            panel.SetActive(true);
        }

        return true;
    }

    private GameData GetFallbackGameData(int gameActivityId)
    {
        if (games == null || games.Length == 0)
        {
            return null;
        }

        int zeroBasedIndex = gameActivityId - 1;
        if (zeroBasedIndex >= 0 && zeroBasedIndex < games.Length && games[zeroBasedIndex] != null)
        {
            return games[zeroBasedIndex];
        }

        if (gameActivityId >= 0 && gameActivityId < games.Length && games[gameActivityId] != null)
        {
            return games[gameActivityId];
        }

        return games[0];
    }

    private void ApplyPreviewForGame(int gameActivityId)
    {
        if (previewImageLoader != null)
        {
            previewImageLoader.LoadPreviewByGameId(gameActivityId);
            return;
        }

        GameData fallbackData = GetFallbackGameData(gameActivityId);
        if (previewImage != null && fallbackData != null && fallbackData.preview != null)
        {
            previewImage.sprite = fallbackData.preview;
        }
    }

    public void ClosePanel()
    {
        if (panel != null)
        {
            panel.SetActive(false);
        }
    }

    public void PlayGame()
    {
        currentGameID = NormalizeGameActivityId(currentGameID);
        PlayerPrefs.SetInt("selected_activity_id", currentGameID);
        PlayerPrefs.Save();
        GoToDragAndDrop();
    }

    public void GoToDragAndDrop()
    {
        SceneManager.LoadScene(dragAndDropSceneName);
    }

    private void SetTexts(string title, string description)
    {
        if (titleText != null)
        {
            titleText.text = title;
        }

        if (descriptionText != null)
        {
            descriptionText.text = description;
        }
    }

    private int NormalizeGameActivityId(int gameActivityId)
    {
        int normalizedId = gameActivityId > 0 ? gameActivityId : DefaultGameActivityId;

        if (normalizedId != gameActivityId)
        {
            Debug.LogWarning($"GameInfoUI: gameActivityId inválido ({gameActivityId}). Se usará {normalizedId}.");
        }

        return normalizedId;
    }
}

[System.Serializable]
public class GameData
{
    public string title;

    [TextArea(3, 5)]
    public string description;

    public Sprite preview;
    public string sceneName;
}
