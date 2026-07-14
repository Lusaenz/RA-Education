using UnityEngine;

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

    
    public int maxScore;


    public int maxStars = 5;

    void Awake()
    {
        instance = this;

    
        maxScore = totalItems * 10;
    }

    public void ItemCorrecto()
    {
        Debug.Log("ItemCorrecto fue llamado");

        if (hasWon) return;

        correctItems++;
        score += 10;

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

    score -=10;


    SoundManager.instance.PlayWrong();
}
}