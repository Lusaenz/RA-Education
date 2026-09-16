using UnityEngine;

/// <summary>
/// Indicador visual del estado de un modulo sobre su isla en el mapa.
///
/// Dibuja un anillo con relleno radial usando un unico <see cref="SpriteRenderer"/> con el
/// material/shader "Custom/RadialProgressRing":
///   - No iniciado  -> anillo completo en color "no iniciado" (rojo).
///   - Iniciado     -> la porcion [0 .. %] del anillo en verde y el resto en amarillo,
///                     avanzando en sentido horario desde arriba. Con 50% se ve medio
///                     anillo verde y medio amarillo.
///
/// El sprite asignado al SpriteRenderer se usa solo como forma (su canal alfa); los colores
/// los pone el shader.
/// </summary>
[RequireComponent(typeof(SpriteRenderer))]
public class ModuleStatusIndicator : MonoBehaviour
{
    private const string StatusNotStarted = "nostarted";

    private static readonly int FillAmountId = Shader.PropertyToID("_FillAmount");
    private static readonly int StartedId = Shader.PropertyToID("_Started");

    [SerializeField] private SpriteRenderer ring;

    private MaterialPropertyBlock block;

    private void Awake()
    {
        if (ring == null)
        {
            ring = GetComponent<SpriteRenderer>();
        }
        block = new MaterialPropertyBlock();
    }

    /// <summary>
    /// Actualiza el indicador.
    /// </summary>
    /// <param name="status">"nostarted" | "inprogress" | "completed".</param>
    /// <param name="pct01">Avance del modulo en el rango 0..1.</param>
    public void SetProgress(string status, float pct01)
    {
        if (ring == null)
        {
            ring = GetComponent<SpriteRenderer>();
            if (ring == null)
            {
                return;
            }
        }

        block ??= new MaterialPropertyBlock();

        bool started = !string.IsNullOrEmpty(status) && status != StatusNotStarted;

        ring.GetPropertyBlock(block);
        block.SetFloat(FillAmountId, Mathf.Clamp01(pct01));
        block.SetFloat(StartedId, started ? 1f : 0f);
        ring.SetPropertyBlock(block);
    }
}
