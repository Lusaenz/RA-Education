using System.Collections;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.SceneManagement;
using UnityEngine.Serialization;

public class GameInfoUI : MonoBehaviour
{
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
    }

    private void Start()
    {
        StartCoroutine(LoadSelectedActivityInfo());
    }

    private IEnumerator LoadSelectedActivityInfo()
    {
        int selectedGameActivityId = PlayerPrefs.GetInt("selected_activity_id", 1);
        GameActivityData gameActivity = null;

        yield return StartCoroutine(gameActivityService.GetGameActivity(selectedGameActivityId, result =>
        {
            gameActivity = result;
        }));

        if (gameActivity == null)
        {
            SetTexts("Actividad no disponible", "No se pudo cargar la configuracion del juego.");
            yield break;
        }

        ActivityData activity = null;
        yield return StartCoroutine(activityService.GetActivity(gameActivity.id_activity, result =>
        {
            activity = result;
        }));

        if (activity == null)
        {
            SetTexts("Actividad no disponible", "No se pudo cargar la informacion de la actividad.");
            yield break;
        }

        SetTexts(activity.type, activity.description);

        // Cargar imagen de preview dinámicamente desde addressable
        if (previewImageLoader != null)
        {
            previewImageLoader.LoadPreviewForSelectedGame();
        }
        else
        {
            Debug.LogWarning("GameInfoUI: PreviewImageLoader no está asignado. Usando sprite estático del array GameData.");
        }
    }

    public void ShowGame(int gameID)
    {
        currentGameID = gameID;

        if (gameID < 0 || gameID >= games.Length)
        {
            return;
        }

        GameData game = games[gameID];
        SetTexts(game.title, game.description);

        if (previewImage != null)
        {
            previewImage.sprite = game.preview;
        }

        if (panel != null)
        {
            panel.SetActive(true);
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
