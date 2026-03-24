using UnityEngine;
using UnityEngine.UI;
using TMPro;
using UnityEngine.SceneManagement;

public class GameInfoUI : MonoBehaviour
{
    public TextMeshProUGUI titleText;
    public TextMeshProUGUI descriptionText;
    public Image previewImage;

    public GameObject panel;

    public GameData[] games;
    private int currentGameID;

    public void ShowGame(int gameID)
    {
        // Validación para evitar errores
        if (gameID < 0 || gameID >= games.Length)
        {
            Debug.LogError("GameID fuera de rango");
            return;
        }
        currentGameID = gameID;
        GameData game = games[gameID];

        titleText.text = game.title;
        descriptionText.text = game.description;
        previewImage.sprite = game.preview;

        panel.SetActive(true);
    }

    public void ClosePanel()
    {
        panel.SetActive(false);
    }
    // Botón jugar
    public void PlayGame()
    {
        string sceneToLoad = games[currentGameID].sceneName;

        SceneManager.LoadScene(sceneToLoad);
    }
}

[System.Serializable]
public class GameData
{
    public string title;
    [TextArea(3, 5)] //  escribir descripciones más cómodas en Unity
    public string description;
    public Sprite preview;
    public string sceneName;
}