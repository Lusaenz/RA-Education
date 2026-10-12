using UnityEngine;

/// <summary>
/// Marcador que NO corresponde al puzzle de la celula (ej. celula vegetal o
/// aparato digestivo). No tiene contenido AR: cuando se detecta muestra un
/// mensaje con <see cref="RAMarkerFeedback"/> y, mientras siga visible,
/// <see cref="Observer"/> no coloca los modelos del puzzle.
///
/// Colocar en un ImageTarget (sin hijos) junto a su DefaultObserverEventHandler.
/// </summary>
[RequireComponent(typeof(DefaultObserverEventHandler))]
public class PuzzleWrongMarkerGate : MonoBehaviour
{
    [Tooltip("Controlador del mensaje en pantalla. Si se deja vacio se busca en la escena.")]
    [SerializeField] private RAMarkerFeedback feedback;

    [TextArea]
    [SerializeField] private string wrongMarkerMessage =
        "Este marcador no corresponde a este juego. Escanea el marcador de la Célula Animal para armar el puzzle.";

    // Cantidad de marcadores incorrectos detectados en este momento.
    private static int _visibleCount;

    public static bool AnyWrongMarkerVisible => _visibleCount > 0;

    private DefaultObserverEventHandler _handler;
    private bool _visible;

    void Start()
    {
        _handler = GetComponent<DefaultObserverEventHandler>();
        _handler.OnTargetFound.AddListener(HandleTargetFound);
        _handler.OnTargetLost.AddListener(HandleTargetLost);

        if (feedback == null)
            feedback = FindFirstObjectByType<RAMarkerFeedback>(FindObjectsInactive.Include);
    }

    void OnDestroy()
    {
        if (_handler != null)
        {
            _handler.OnTargetFound.RemoveListener(HandleTargetFound);
            _handler.OnTargetLost.RemoveListener(HandleTargetLost);
        }

        SetVisible(false);
    }

    private void HandleTargetFound()
    {
        SetVisible(true);

        if (feedback != null)
            feedback.Show(wrongMarkerMessage);
    }

    private void HandleTargetLost()
    {
        SetVisible(false);

        if (feedback != null && !AnyWrongMarkerVisible)
            feedback.Hide();
    }

    private void SetVisible(bool visible)
    {
        if (_visible == visible) return;

        _visible = visible;
        _visibleCount += visible ? 1 : -1;
    }
}
