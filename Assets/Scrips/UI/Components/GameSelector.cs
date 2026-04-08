using UnityEngine;
using UnityEngine.SceneManagement;

/// <summary>
/// Guarda la actividad elegida y redirige a la escena de detalle del juego.
/// </summary>
public class GameSelector : MonoBehaviour
{
    [SerializeField] private string gameSelectionSceneName = "GameSelection";

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
