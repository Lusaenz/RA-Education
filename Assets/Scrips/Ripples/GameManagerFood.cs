using UnityEngine;

using TMPro;
using System.Collections;
using System.Collections.Generic;
public class GameManagerFood : MonoBehaviour
{
public static GameManagerFood instance;

    [Header("Puntaje")]
    public int score = 0;
    public int puntosCorrecto = 10;
    public int puntosIncorrecto = -5;

    [Header("UI")]
    public TMP_Text scoreText;
    public GameObject winPanel;

    [Header("Estrellas")]
    public UnityEngine.UI.Image[] estrellas;
    public Sprite estrellaLlena;
    public Sprite estrellaVacia;
    public int maxScore = 40;

    [Header("Sistema Secuencial")]
    public List<string> respuestasCorrectas;
    private int indiceActual = 0;

    [Header("Textos Secuenciales")]
public TMP_Text textoInstruccion;
public List<string> textos;

public RandomizarOrganos randomizador;



    void Awake()
    {
        instance = this;
        ActualizarUI();
        ActualizarTexto();
    }


    public void EvaluarItem(string idItem)
    {
        if (idItem == respuestasCorrectas[indiceActual])
        {
            RespuestaCorrecta();
            indiceActual++;
            randomizador.MezclarHijos();



            if (indiceActual >= respuestasCorrectas.Count)
            {
                StartCoroutine(MostrarVictoria());
            }
            else
            {
                Debug.Log("Siguiente: " + respuestasCorrectas[indiceActual]);
                ActualizarTexto(); 
            }
        }
        else
        {
            RespuestaIncorrecta();
        }
        Debug.Log(indiceActual);
    }

    void ActualizarTexto()
{
    if (textoInstruccion != null && indiceActual < textos.Count)
    {
        textoInstruccion.text = textos[indiceActual];
    }
}

    public void RespuestaCorrecta()
    {
        score += puntosCorrecto;
        ActualizarUI();
        SoundManager.instance.PlayCorrect(); 
    }

    public void RespuestaIncorrecta()
    {
        score += puntosIncorrecto;
        ActualizarUI();
        SoundManager.instance.PlayWrong();
        
    }

    void ActualizarUI()
    {
        if (scoreText != null)
        {
            scoreText.text = ": " + score;
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

        ActualizarEstrellas();
        winPanel.transform.localScale = Vector3.one;
    }

    void ActualizarEstrellas()
    {
        int estrellasGanadas = Mathf.RoundToInt((float)score / maxScore * estrellas.Length);

        for (int i = 0; i < estrellas.Length; i++)
        {
            estrellas[i].sprite = (i < estrellasGanadas) ? estrellaLlena : estrellaVacia;
        }
        Debug.Log(estrellasGanadas); //Variable de la cantidad de estrellas ganadas 

    }
}