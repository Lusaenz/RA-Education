using System;
using UnityEngine;
using UnityEngine.EventSystems;

/// <summary>
/// Avisa cuando un eye button (o badge de cluster) se presiona / suelta.
/// ARPartButtonManager lo usa para congelar el layout de los botones mientras
/// el dedo esta encima: si el boton se moviera por el jitter del tracking entre
/// el press y el release, uGUI no dispararia el onClick.
/// Se anade en runtime desde ARPartButtonManager (no hace falta ponerlo en el prefab).
/// </summary>
public class EyeButtonPressTracker : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    public event Action<bool> OnPressChanged;

    public bool IsPressed { get; private set; }

    public void OnPointerDown(PointerEventData eventData)
    {
        SetPressed(true);
    }

    public void OnPointerUp(PointerEventData eventData)
    {
        SetPressed(false);
    }

    // Si el boton se desactiva con el dedo encima (perdida de tracking, panel
    // abierto) no llega el OnPointerUp: se libera aqui para no dejar el
    // contador del manager colgado.
    void OnDisable()
    {
        SetPressed(false);
    }

    void SetPressed(bool pressed)
    {
        if (IsPressed == pressed) return;
        IsPressed = pressed;
        OnPressChanged?.Invoke(pressed);
    }
}
