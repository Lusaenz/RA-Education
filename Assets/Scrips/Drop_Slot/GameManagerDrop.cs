using UnityEngine;
using TMPro;

public class GameManagerJuego : MonoBehaviour
{
    public static GameManagerJuego instance;

    public int score = 0;

    public int puntosCorrecto = 10;
    public int puntosIncorrecto = -5;

    public TMP_Text scoreText;

    public int totalItems = 4; 
    private int correctItems = 0;

    void Awake()
    {
        instance = this;
        ActualizarUI();
    }

    public void RespuestaCorrecta()
    {
        score += puntosCorrecto;
        correctItems++;

        ActualizarUI();
        VerificarVictoria();
    }

    public void RespuestaIncorrecta()
    {
        score += puntosIncorrecto;
        ActualizarUI();
    }

    void ActualizarUI()
    {
        if (scoreText != null)
        {
            scoreText.text = ": " + score;
            Debug.Log(score);
        }
    }

    void VerificarVictoria()
    {
        if (correctItems >= totalItems)
        {
           
            GameManager.instance.MostrarVictoria(score, 40);
        }
    }
}