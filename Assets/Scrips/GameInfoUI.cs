using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class GameInfoUI : MonoBehaviour
{
    public TextMeshProUGUI titleText;
    public TextMeshProUGUI descriptionText;
    public Image previewImage;

    public GameObject panel;

    public GameData[] games;

    public void ShowGame(int gameID)
    {
        // Validación para evitar errores
        if (gameID < 0 || gameID >= games.Length)
        {
            Debug.LogError("GameID fuera de rango");
            return;
        }

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
}

[System.Serializable]
public class GameData
{
    public string title;
    [TextArea(3, 5)] //  escribir descripciones más cómodas en Unity
    public string description;
    public Sprite preview;
}