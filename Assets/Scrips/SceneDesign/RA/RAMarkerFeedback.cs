using System.Collections;
using TMPro;
using UnityEngine;

/// <summary>
/// Mensaje de feedback en pantalla para la escena de RA. Lo usa
/// <see cref="RAMarkerModuleGate"/> para avisar al usuario cuando el marcador
/// detectado no corresponde al modulo en el que esta trabajando.
/// Colocar este componente en un GameObject de UI con un CanvasGroup.
/// </summary>
public class RAMarkerFeedback : MonoBehaviour
{
    [Header("Referencias")]
    [Tooltip("CanvasGroup usado para el fade. Si se deja vacio se busca en este GameObject.")]
    [SerializeField] private CanvasGroup canvasGroup;
    [Tooltip("Texto donde se muestra el mensaje.")]
    [SerializeField] private TextMeshProUGUI messageText;

    [Header("Animacion")]
    [SerializeField] private float fadeDuration = 0.25f;
    [Tooltip("Segundos que el mensaje permanece visible antes de ocultarse solo. 0 = permanece hasta que se pierda el marcador.")]
    [SerializeField] private float autoHideAfter = 0f;

    private Coroutine _routine;

    void Awake()
    {
        if (canvasGroup == null) canvasGroup = GetComponent<CanvasGroup>();

        if (canvasGroup != null)
        {
            canvasGroup.alpha = 0f;
            canvasGroup.blocksRaycasts = false;
            canvasGroup.interactable = false;
        }

        gameObject.SetActive(false);
    }

    /// <summary>Muestra el mensaje indicado con un fade in.</summary>
    public void Show(string message)
    {
        if (messageText != null) messageText.text = message;

        gameObject.SetActive(true);

        if (_routine != null) StopCoroutine(_routine);
        _routine = StartCoroutine(ShowRoutine());
    }

    /// <summary>Oculta el mensaje con un fade out.</summary>
    public void Hide()
    {
        if (!gameObject.activeSelf) return;

        if (_routine != null) StopCoroutine(_routine);
        _routine = StartCoroutine(HideRoutine());
    }

    IEnumerator ShowRoutine()
    {
        yield return Fade(1f);

        if (autoHideAfter > 0f)
        {
            yield return new WaitForSeconds(autoHideAfter);
            yield return Fade(0f);
            gameObject.SetActive(false);
        }

        _routine = null;
    }

    IEnumerator HideRoutine()
    {
        yield return Fade(0f);
        gameObject.SetActive(false);
        _routine = null;
    }

    IEnumerator Fade(float target)
    {
        if (canvasGroup == null) yield break;

        float start = canvasGroup.alpha;
        float t = 0f;

        while (t < fadeDuration)
        {
            t += Time.deltaTime;
            canvasGroup.alpha = Mathf.Lerp(start, target, t / fadeDuration);
            yield return null;
        }

        canvasGroup.alpha = target;
    }
}
