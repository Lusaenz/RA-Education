using UnityEngine;

public class PuzzleManager : MonoBehaviour
{
    public static PuzzleManager instance;

    public int correctItems = 0;
    public int totalItems = 8; // ajusta según tu puzzle
    public int score = 0;

    bool hasWon = false;

    void Awake()
    {
        instance = this;
    }

    public void ItemCorrecto()
    {
        if (hasWon) return;

        correctItems++;
        score += 10;

        VerificarVictoria();
    }

    void VerificarVictoria()
    {
        if (correctItems >= totalItems)
        {
            hasWon = true;

            Debug.Log("¡Puzzle completo!");

            GameManager.instance.MostrarVictoria(score, 40);
        }
    }
}