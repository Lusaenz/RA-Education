using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public static GameManager instance;

    [Header("UI Global")]
    public GameObject winPanel;

    [Header("Estrellas")]
    public Image[] estrellas;
    public Sprite estrellaLlena;
    public Sprite estrellaVacia;

    void Awake()
{
    if (instance == null)
    {
        instance = this;
        DontDestroyOnLoad(gameObject); 
    }
    else
    {
        Destroy(gameObject);
    }
}

    public void MostrarVictoria(int score, int maxScore)
    {
        StartCoroutine(Mostrar(score, maxScore));
    }

    IEnumerator Mostrar(int score, int maxScore)
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

        ActualizarEstrellas(score, maxScore);
        winPanel.transform.localScale = Vector3.one;
    }

    void ActualizarEstrellas(int score, int maxScore)
    {
        int estrellasGanadas = Mathf.RoundToInt((float)score / maxScore * estrellas.Length);

        for (int i = 0; i < estrellas.Length; i++)
        {
            estrellas[i].sprite = (i < estrellasGanadas) ? estrellaLlena : estrellaVacia;
        }
    }
}