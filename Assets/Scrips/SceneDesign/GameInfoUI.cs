using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEditor;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.Serialization;
using UnityEngine.UI;

public class GameInfoUI : MonoBehaviour
{
    [FormerlySerializedAs("activityTitleText")]
    public TextMeshProUGUI titleText;

    [FormerlySerializedAs("activityDescriptionText")]
    public TextMeshProUGUI descriptionText;

    public Image previewImage;
    public GameObject panel;

    [Header("Preview Image Loader")]
    [SerializeField] private PreviewImageLoader previewImageLoader;

    private ActivityService activityService;
    private GameActivityService gameActivityService;
    private int currentGameID;
    private string currentGameType;

    private readonly Dictionary<int, GameActivityData> gameActivityCache = new();
    private bool cacheLoaded = false;

    private void Awake()
    {
        activityService = new ActivityService();
        gameActivityService = new GameActivityService();
        StartCoroutine(PreloadGameActivities());
    }

    private IEnumerator PreloadGameActivities()
    {
        yield return StartCoroutine(gameActivityService.GetAllGameActivities(results =>
        {
            if (results != null)
            {
                foreach (GameActivityData ga in results)
                {
                    gameActivityCache[ga.id_game_activity] = ga;
                }
                string ids = string.Join(", ", gameActivityCache.Keys);
                Debug.Log($"[GameInfoUI] Caché cargado: {gameActivityCache.Count} game_activities. IDs disponibles: [{ids}]");
            }
            else
            {
                Debug.LogWarning("[GameInfoUI] No se pudieron cargar las game_activities desde la BD.");
            }

            cacheLoaded = true;
        }));
    }

    public void ShowGameForModule(int moduleId)
    {
        if (moduleId <= 0)
        {
            Debug.LogError($"GameInfoUI: moduleId inválido ({moduleId}).");
            return;
        }

        StartCoroutine(ResolveAndShowByModule(moduleId));
    }

    private IEnumerator ResolveAndShowByModule(int moduleId)
    {
        if (!cacheLoaded)
        {
            yield return new WaitUntil(() => cacheLoaded);
        }

        // Buscar en caché por módulo primero
        foreach (GameActivityData ga in gameActivityCache.Values)
        {
            if (ga.id_module == moduleId)
            {
                ShowGame(ga.id_game_activity);
                yield break;
            }
        }

        // No estaba en caché — consultar la BD directamente
        GameActivityData result = null;
        yield return StartCoroutine(gameActivityService.GetGameActivityByModuleId(moduleId, r => result = r));

        if (result == null)
        {
            string availableIds = gameActivityCache.Count > 0
                ? string.Join(", ", gameActivityCache.Keys)
                : "ninguno";
            Debug.LogWarning($"[GameInfoUI] No se encontró game_activity para módulo {moduleId}. " +
                             $"IDs de game_activity disponibles en BD: [{availableIds}]");
            yield break;
        }

        gameActivityCache[result.id_game_activity] = result;
        ShowGame(result.id_game_activity);
    }

    public void ShowGame(int gameID)
    {
        if (gameID <= 0)
        {
            Debug.LogError($"GameInfoUI: gameActivityId inválido ({gameID}).");
            return;
        }

        currentGameID = gameID;
        currentGameType = null;
        PlayerPrefs.SetInt("selected_activity_id", currentGameID);
        PlayerPrefs.Save();

        // El panel se activa solo cuando los datos cargan exitosamente (en LoadGameInfo).
        StartCoroutine(LoadGameInfo(currentGameID));
    }

    private IEnumerator LoadGameInfo(int gameActivityId)
    {
        if (!cacheLoaded)
        {
            yield return new WaitUntil(() => cacheLoaded);
        }

        GameActivityData gameActivity = null;

        if (gameActivityCache.TryGetValue(gameActivityId, out GameActivityData cached))
        {
            gameActivity = cached;
        }
        else
        {
            yield return StartCoroutine(gameActivityService.GetGameActivity(gameActivityId, result =>
            {
                gameActivity = result;
                if (result != null)
                {
                    gameActivityCache[gameActivityId] = result;
                }
            }));
        }

        if (gameActivity == null)
        {
            string availableIds = gameActivityCache.Count > 0
                ? string.Join(", ", gameActivityCache.Keys)
                : "ninguno";
            Debug.LogWarning($"[GameInfoUI] No se encontró game_activity con id {gameActivityId}. " +
                             $"IDs disponibles en BD: [{availableIds}]. " +
                             "Verifica el campo 'Fallback Game Activity Id' en el Inspector de BoxGameSelector.");
            yield break;
        }

        currentGameType = gameActivity.game_type;
        Debug.Log($"[GameInfoUI] LoadGameInfo → id={gameActivityId} game_type='{currentGameType}'");
        PlayerPrefs.SetString("selected_game_type", currentGameType);
        PlayerPrefs.Save();

        ActivityData activity = null;
        yield return StartCoroutine(activityService.GetActivity(gameActivity.id_activity, result =>
        {
            activity = result;
        }));

        if (activity != null)
        {
            SetTexts(activity.type, activity.description);
        }

        if (previewImageLoader != null)
        {
            previewImageLoader.LoadPreviewByGameType(currentGameType);
        }

        // Abrir el panel solo cuando los datos ya están listos para evitar el parpadeo.
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
        StartCoroutine(PlayGameCoroutine());
    }

    private IEnumerator PlayGameCoroutine()
    {
        Debug.Log($"[GameInfoUI] PlayGame → currentGameID={currentGameID}, currentGameType='{currentGameType}'");

        if (currentGameID <= 0)
        {
            int moduleId = PlayerPrefs.GetInt("selected_module_id", 0);

            if (moduleId > 0)
            {
                // Buscar en caché primero
                foreach (GameActivityData ga in gameActivityCache.Values)
                {
                    if (ga.id_module == moduleId)
                    {
                        currentGameID = ga.id_game_activity;
                        currentGameType = ga.game_type;
                        break;
                    }
                }

                // Si no estaba en caché, consultar la BD
                if (currentGameID <= 0)
                {
                    yield return StartCoroutine(gameActivityService.GetGameActivityByModuleId(moduleId, result =>
                    {
                        if (result != null)
                        {
                            currentGameID = result.id_game_activity;
                            currentGameType = result.game_type;
                            gameActivityCache[currentGameID] = result;
                        }
                    }));
                }
            }
        }

        if (currentGameID <= 0)
        {
            Debug.LogWarning("[GameInfoUI] PlayGame() sin actividad seleccionada.");
            yield break;
        }

        if (string.IsNullOrEmpty(currentGameType) &&
            gameActivityCache.TryGetValue(currentGameID, out GameActivityData cached) &&
            !string.IsNullOrEmpty(cached.game_type))
        {
            currentGameType = cached.game_type;
        }

        if (string.IsNullOrEmpty(currentGameType))
        {
            Debug.LogError($"[GameInfoUI] game_type es nulo o vacío para la actividad {currentGameID}. " +
                           "Verifica que el campo game_type esté correctamente registrado en la base de datos.");
            yield break;
        }

        string sceneName = GetSceneNameForGameType(currentGameType);
        Debug.Log($"[GameInfoUI] Cargando escena → game_type='{currentGameType}' → escena='{sceneName}'");
        PlayerPrefs.SetInt("selected_activity_id", currentGameID);
        PlayerPrefs.Save();
        SceneManager.LoadScene(sceneName);
    }

    private string GetSceneNameForGameType(string gameType)
    {
        if (string.IsNullOrEmpty(gameType)) return "DragAndDrop";

        return gameType.ToLower() switch
        {
            "drag_drop_digestive_system" or "drag_drop_cell" => "DragAndDrop",
            "food_riddles" or "foodriddles" => "FoodRiddles",
            _ => "DragAndDrop"
        };
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
