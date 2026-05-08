using UnityEngine;

/// <summary>
/// Manager encargado de la lógica relacionada con los módulos.
/// Permite obtener información de los módulos desde la base de datos y manejar su visualización.
/// </summary>
public class ModuleManager : MonoBehaviour
{
    public static ModuleManager Instance { get; private set; }

    private ModulesRepository modulesRepository;

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

    private void Start()
    {
        // Inicializar repositorio cuando el manager esté listo
        // Se asume que DatabaseManager ya tiene la conexión abierta
        try
        {
            modulesRepository = new ModulesRepository();
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"ModuleManager: Error al inicializar repositorio: {ex.Message}");
        }
    }

    /// <summary>
    /// Busca un módulo por ID y muestra su nombre en la consola.
    /// </summary>
    /// <param name="moduleId">ID del módulo a consultar.</param>
    public void GetAndLogModuleName(int moduleId)
    {
        if (modulesRepository == null)
        {
            try {
                modulesRepository = new ModulesRepository();
            } catch {
                Debug.LogError("ModuleManager: El repositorio no está listo.");
                return;
            }
        }

        ModuleModel module = modulesRepository.GetModuleById(moduleId);

        if (module != null)
        {
            Debug.Log($"Módulo detectado: {module.name}");
        }
        else
        {
            Debug.LogWarning($"ModuleManager: No se encontró un módulo con ID {moduleId} en la base de datos.");
        }
    }
}
