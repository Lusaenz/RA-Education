using UnityEngine;

/// <summary>
/// Restringe cada ImageTarget de la escena de RA al modulo en el que esta
/// trabajando el usuario. Si el marcador detectado pertenece al modulo activo
/// (guardado en PlayerPrefs por IslandInteraction), el contenido AR se muestra
/// con normalidad. Si pertenece a otro modulo, el modelo 3D queda oculto y se
/// muestra un mensaje de feedback mediante <see cref="RAMarkerFeedback"/>.
///
/// Colocar en el mismo GameObject que el DefaultObserverEventHandler del
/// ImageTarget. Ejemplo de configuracion:
///   - ImageTargetDigestive     -> allowedModuleIds = [1]
///   - ImageTargetAnimalCell    -> allowedModuleIds = [2]
///   - ImageTargetVegetalCell   -> allowedModuleIds = [2]
/// </summary>
[RequireComponent(typeof(DefaultObserverEventHandler))]
public class RAMarkerModuleGate : MonoBehaviour
{
    [Header("Configuracion del modulo")]
    [Tooltip("IDs de modulo que pueden usar este marcador. Aparato Digestivo = 1, Celula = 2.")]
    [SerializeField] private int[] allowedModuleIds = new int[0];

    [Tooltip("Raiz del contenido AR (modelo 3D y sus managers) que se oculta cuando el marcador no corresponde al modulo activo. Si se deja vacio se usa el hijo llamado '3DModels'.")]
    [SerializeField] private GameObject arContentRoot;

    [Tooltip("Clave de PlayerPrefs donde IslandInteraction guarda el modulo seleccionado.")]
    [SerializeField] private string moduleIdPrefKey = "selected_module_id";

    [Header("Feedback")]
    [Tooltip("Controlador del mensaje en pantalla. Si se deja vacio se busca en la escena.")]
    [SerializeField] private RAMarkerFeedback feedback;

    [TextArea]
    [SerializeField] private string wrongMarkerMessage =
        "Este marcador pertenece a otro modulo. Escanea el marcador correspondiente al modulo que estas estudiando.";

    private DefaultObserverEventHandler _handler;

    // Se decide en Awake y no cambia durante la vida de la escena: la escena de
    // RA siempre se abre desde un modulo concreto, asi que el modulo activo ya
    // esta fijado antes de que corra este componente.
    private bool _blocked;

    void Awake()
    {
        if (arContentRoot == null)
        {
            Transform found = transform.Find("3DModels");
            if (found != null) arContentRoot = found.gameObject;
        }

        _blocked = !IsMarkerAllowedForCurrentModule();

        // Se desactiva en Awake (antes de cualquier Start) para que ni el
        // DefaultObserverEventHandler ni el ARPartButtonManager del hijo lleguen
        // a inicializar/instanciar nada para un marcador que no corresponde.
        if (_blocked && arContentRoot != null)
            arContentRoot.SetActive(false);
    }

    void Start()
    {
        _handler = GetComponent<DefaultObserverEventHandler>();
        if (_handler != null)
        {
            _handler.OnTargetFound.AddListener(HandleTargetFound);
            _handler.OnTargetLost.AddListener(HandleTargetLost);
        }

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
    }

    private bool IsMarkerAllowedForCurrentModule()
    {
        int currentModule = PlayerPrefs.GetInt(moduleIdPrefKey, 0);

        // Sin modulo seleccionado (ej. abrir la escena directamente en el editor):
        // no se restringe nada para no romper las pruebas.
        if (currentModule <= 0) return true;

        // Marcador sin modulos configurados: se permite (fail-open).
        if (allowedModuleIds == null || allowedModuleIds.Length == 0) return true;

        foreach (int id in allowedModuleIds)
            if (id == currentModule) return true;

        return false;
    }

    private void HandleTargetFound()
    {
        if (!_blocked) return;

        // Salvaguarda por si algo volvio a activar el contenido.
        if (arContentRoot != null && arContentRoot.activeSelf)
            arContentRoot.SetActive(false);

        if (feedback != null)
            feedback.Show(wrongMarkerMessage);
    }

    private void HandleTargetLost()
    {
        if (!_blocked) return;

        if (feedback != null)
            feedback.Hide();
    }
}
