using System.Collections;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.UI;

/// <summary>
/// Maneja TODO lo visual de victoria:
/// - Panel
/// - Animación
/// - Estrellas
/// </summary>
public class VictoryUIManager : MonoBehaviour
{
    [Header("Panel")]
    public GameObject winPanel;

    [Header("Estrellas")]
    public Image[] estrellas;
    public Sprite estrellaLlena;
    public Sprite estrellaVacia;
    public Transform container;

    public Vector2 size = new(90, 90);
    public float arcHeight = 70f;

    private readonly List<GameObject> generated = new();

    public int lastStars;

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
        winPanel.SetActive(true);
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

        if (count <= 0) return;

        estrellas = new Image[count];

        for (int i = 0; i < count; i++)
        {
            GameObject go = new GameObject($"Star_{i}", typeof(RectTransform), typeof(CanvasRenderer), typeof(Image));
            go.transform.SetParent(container, false);

            RectTransform rt = go.GetComponent<RectTransform>();

rt.anchorMin = new Vector2(0.5f, 0.5f);
rt.anchorMax = new Vector2(0.5f, 0.5f);
rt.pivot = new Vector2(0.5f, 0.5f);

rt.sizeDelta = size;
rt.localScale = Vector3.one;
rt.anchoredPosition = GetPos(i, count);

            Image img = go.GetComponent<Image>();
            img.sprite = estrellaLlena;
            img.color = Color.white;
img.preserveAspect = true;
img.raycastTarget = false;
            img.preserveAspect = true;

            estrellas[i] = img;
            generated.Add(go);
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
        foreach (var g in generated)
            Destroy(g);

        generated.Clear();
    }
}