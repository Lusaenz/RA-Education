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

    [Header("Victory UI")]
    public VictoryUIManager victoryUI;

    [Header("UI")]
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
    }

    public void ItemCorrecto()
    {
        Debug.Log("ItemCorrecto fue llamado");

        if (hasWon) return;

        correctItems++;
        score += 10;
        puntos.text="Item Correcto";

        ActualizarScoreUI();

        VerificarVictoria();

        SoundManager.instance.PlayCorrect();
    }

    void VerificarVictoria()
    {
        if (correctItems >= totalItems)
        {
            hasWon = true;

            if (victoryUI != null)
            {
                victoryUI.ShowVictory(score, maxScore, maxStars);
                Debug.Log("¡Puzzle completo!");
            }
            else
            {
                Debug.LogError("No se asignó el VictoryUIManager en el PuzzleManager.");
            }
        }
    }

    public void ItemIncorrecto()
    {
        Debug.Log("ENTRÓ A ItemIncorrecto");

        if (hasWon) return;

        score -= 10;
        puntos.text="Item correcto";
        if(score <0)
        score=0;

        ActualizarScoreUI();

        SoundManager.instance.PlayWrong();
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
        nombrePiezaText.text = "Pieza: "+nombre;
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
            targetNameText.text ="Objetivo: "+ nombre;
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