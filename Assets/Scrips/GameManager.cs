using UnityEngine;
using TMPro;
using System;
using System.Collections;


public class GameManager : MonoBehaviour
{
    public static GameManager instance;

    public int score = 0;

    
    public int puntosCorrecto = 10;
    public int puntosIncorrecto = -5;

    
    public TMP_Text scoreText;

    public GameObject winPanel;

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
           StartCoroutine(MostrarVictoria());

        }
    }

    IEnumerator MostrarVictoria()
    {
      
        yield return new WaitForSeconds(1f);

        winPanel.SetActive(true);

        
        winPanel.transform.localScale = Vector3.zero;

        float tiempo = 0f;
        float duracion = 0.4f;

        while (tiempo < duracion)
        {
            tiempo += Time.deltaTime;
            float escala = Mathf.Lerp(0, 1, tiempo / duracion);
            winPanel.transform.localScale = new Vector3(escala, escala, escala);
            yield return null;
        }

        winPanel.transform.localScale = Vector3.one;
    }

}
