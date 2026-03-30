using UnityEngine;
using UnityEngine.SceneManagement;

// ─────────────────────────────────────────────
//  GameSelector.cs
//  Adjuntar a un GameObject vacío en la escena
//  del menú. Asignar los dos botones en el
//  Inspector con los métodos correspondientes.
// ─────────────────────────────────────────────

public class GameSelector : MonoBehaviour
{
    // Nombre exacto de la escena del minijuego
    // (debe estar agregada en File → Build Settings)
    [SerializeField] private string dragDropSceneName = "DragAndDrop";

    // ── Botón: La célula ─────────────────────────────────────────────────
    public void LoadDigestive()
    {

        PlayerPrefs.SetInt("selected_activity_id", 1);
        PlayerPrefs.Save();
        SceneManager.LoadScene(dragDropSceneName);
    }

    // ── Botón: Sistema digestivo ─────────────────────────────────────────
    public void LoadCellGame()
    {

        PlayerPrefs.SetInt("selected_activity_id", 2);
        PlayerPrefs.Save();
        SceneManager.LoadScene(dragDropSceneName);
    }
}