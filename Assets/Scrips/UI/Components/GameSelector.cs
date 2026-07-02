using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Guarda la actividad elegida y redirige a la escena de detalle del juego.
/// Usa "selected_activity_id" en PlayerPrefs, que IslandInteraction asigna al tocar una isla.
/// </summary>
public class GameSelector : MonoBehaviour
{
    [SerializeField] private string gameSelectionSceneName = "GameSelection";
    [SerializeField] private int defaultGameActivityId = 1;

    /// <summary>
    /// Carga GameSelection usando la actividad guardada por la isla tocada.
    /// Asignar este método al botón "Jugar" dentro del libro.
    /// </summary>
    public void LoadGameForCurrentIsland()
    {
        int gameActivityId = PlayerPrefs.GetInt("selected_activity_id", defaultGameActivityId);
        if (gameActivityId <= 0) gameActivityId = defaultGameActivityId;

        PlayerPrefs.SetInt("selected_activity_id", gameActivityId);
        PlayerPrefs.Save();
        SceneManager.LoadScene(gameSelectionSceneName);
    }

    // Métodos anteriores mantenidos para compatibilidad con botones existentes en la escena
    public void LoadDigestive()
    {
        PlayerPrefs.SetInt("selected_activity_id", 1);
        PlayerPrefs.Save();
        SceneManager.LoadScene(gameSelectionSceneName);
    }

    public void LoadCellGame()
    {
        PlayerPrefs.SetInt("selected_activity_id", 2);
        PlayerPrefs.Save();
        SceneManager.LoadScene(gameSelectionSceneName);
    }
}
