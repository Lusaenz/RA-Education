using TMPro;
using UnityEngine;

/// <summary>
/// Puente temporal para escenas que aun conservan este componente.
/// Transfiere referencias utiles al nuevo GameManager y luego se desactiva.
/// </summary>
public class GameManagerJuego : MonoBehaviour
{
    public static GameManagerJuego instance;

    public TMP_Text scoreText;

    private void Awake()
    {
        instance = this;
    }

    private void Start()
    {
        if (GameManager.instance != null && GameManager.instance.scoreText == null && scoreText != null)
        {
            GameManager.instance.scoreText = scoreText;
        }

        enabled = false;
    }
}
