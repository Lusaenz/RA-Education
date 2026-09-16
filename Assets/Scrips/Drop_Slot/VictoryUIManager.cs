using System.Collections;
using System.Collections.Generic;
using TMPro;
using Unity.VisualScripting;
using UnityEngine;
using UnityEngine.UI;

/// 
/// Maneja TODO lo visual de victoria:
/// - Panel
/// - Animación
/// - Estrellas
/// Persistente entre escenas (Singleton)
/// 
public class VictoryUIManager : MonoBehaviour
{
    public static VictoryUIManager Instance { get; private set; }

    [Header("Panel")]
    public GameObject winPanel;

    [Header("Efectos Visuales")]
    public ParticleSystem confettiFX; // <--- Asigna aquí tu Particle System
    public GameObject info; // Se asigna dinámicamente desde el minijuego activo

    [Header("Estrellas")]
    public Image[] estrellas;
    public Sprite estrellaLlena;
    public Sprite estrellaVacia;
    public Transform container;

    public Vector2 size = new Vector2(90f, 90f);
    public float arcHeight = 70f;

    private GameObject[] generated = new GameObject[0];

    public int lastStars;

    private void Awake()
    {
        if (Instance != null && Instance != this)
        {
            Destroy(gameObject);
            return;
        }

        Instance = this;
        DontDestroyOnLoad(gameObject);
    }

    /// 
    /// Asigna la UI de información del minijuego actual
    /// 
    public void SetInfoUI(GameObject gameInfoUI)
    {
        info = gameInfoUI;
    }

    /// 
    /// Oculta el panel de victoria y se asegura de habilitar el panel HUD si existe
    /// 
    public void ResetUI()
    {
        if (winPanel != null) winPanel.SetActive(false);
        if (info != null) info.SetActive(true);
        Clear();

        BackNavigationManager.PopOverride(HandleBackOverride);
    }

    private bool HandleBackOverride()
    {
        ResetUI();
        return true;
    }

    public int ShowVictory(int score, int maxScore, int maxStars)
    {
        StartCoroutine(VictoryRoutine(score, maxScore, maxStars));
        return lastStars;
    }

    private IEnumerator VictoryRoutine(int score, int maxScore, int maxStars)
    {
        yield return new WaitForSeconds(1f);

        yield return StartCoroutine(AnimatePanel());

        lastStars = CalculateStars(score, maxScore, maxStars);

        BuildStars(lastStars);
    }

    private IEnumerator AnimatePanel()
    {
        // 1. Activar panel de victoria
        if (winPanel != null)
        {
            winPanel.SetActive(true);
            BackNavigationManager.PopOverride(HandleBackOverride);
            BackNavigationManager.PushOverride(HandleBackOverride);
        }

        if (confettiFX != null)
        {
            confettiFX.Play();
        }

        // 2. Ocultar OBLIGATORIAMENTE el panel info registrado
        if (info != null)
        {
            info.SetActive(false);
        }
        else
        {
            Debug.LogWarning("VictoryUIManager: No hay un GameObject 'info' registrado para ocultar.");
        }

        if (winPanel != null)
        {
            winPanel.transform.localScale = Vector3.zero;

            float t = 0;
            const float duration = 0.4f;

            while (t < duration)
            {
                t += Time.deltaTime;
                float s = Mathf.Lerp(0, 1, t / duration);
                winPanel.transform.localScale = Vector3.one * s;
                yield return null;
            }

            winPanel.transform.localScale = Vector3.one;
        }
    }

    private int CalculateStars(int score, int maxScore, int maxStars)
    {
        if (maxScore <= 0) return 0;

        float p = Mathf.Clamp01(score / (float)maxScore);
        return Mathf.RoundToInt(p * maxStars);
    }

    private void BuildStars(int count)
    {
        if (container == null)
        {
            Debug.LogError("VictoryUIManager: Container no está asignado.");
            return;
        }

        Clear();

        if (count <= 0) count = 1;

        estrellas = new Image[count];
        generated = new GameObject[count];

        for (int i = 0; i < count; i++)
        {
            GameObject go = new GameObject($"Star_{i}", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
            go.transform.SetParent(container, false);

            RectTransform rt = (RectTransform)go.GetComponent(typeof(RectTransform));

            rt.anchorMin = new Vector2(0.5f, 0.5f);
            rt.anchorMax = new Vector2(0.5f, 0.5f);
            rt.pivot = new Vector2(0.5f, 0.5f);

            rt.sizeDelta = size;
            rt.localScale = Vector3.one;
            rt.anchoredPosition = GetPos(i, count);

            Image img = (Image)go.GetComponent(typeof(Image));
            img.sprite = estrellaLlena;
            img.color = Color.white;
            img.preserveAspect = true;
            img.raycastTarget = false;

            estrellas[i] = img;
            generated[i] = go;
        }
    }

    private Vector2 GetPos(int index, int totalStars)
    {
        if (totalStars <= 1)
            return Vector2.zero;

        float spacing = Mathf.Max(size.x * 0.9f, 120f);

        float centeredIndex = index - (totalStars - 1) * 0.5f;

        float x = centeredIndex * spacing;

        float normalizedDistance =
            totalStars <= 2
                ? 1f
                : Mathf.Abs(centeredIndex) / ((totalStars - 1) * 0.5f);

        float y = (1f - normalizedDistance) * arcHeight;

        return new Vector2(x, y);
    }

    private void Clear()
    {
        if (generated == null) return;

        foreach (var g in generated)
        {
            if (g != null) Destroy(g);
        }

        generated = new GameObject[0];
    }
}