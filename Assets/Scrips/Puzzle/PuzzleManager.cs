using UnityEngine;
using TMPro;

public class PuzzleManager : MonoBehaviour
{
    public static PuzzleManager instance;

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

    void Awake()
    {
        instance = this;
        maxScore = totalItems * 10;
        ActualizarScoreUI();

        // REGISTRO INMEDIATO: Registramos el panel info tan pronto despierta el Manager
        RegistrarUI();
    }

    void Start()
    {
        if (VictoryUIManager.Instance != null)
        {
            VictoryUIManager.Instance.ResetUI();
        }
    }

    private void RegistrarUI()
    {
        if (VictoryUIManager.Instance != null && gameInfoUI != null)
        {
            VictoryUIManager.Instance.SetInfoUI(gameInfoUI);
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
                Debug.LogError("No se encontró la instancia de VictoryUIManager en la escena.");
            }
        }
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