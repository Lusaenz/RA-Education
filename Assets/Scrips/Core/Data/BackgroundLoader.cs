using UnityEngine;
using UnityEngine.UI;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;

/// <summary>
/// Cargador dinámico de fondos según el juego seleccionado.
/// Lee el ID del juego desde PlayerPrefs y carga la imagen addressable correspondiente.
/// 
/// Mapeo de juegos:
/// - ID 1 (o "Digestive"): background/digestivo
/// - ID 2 (o "Cell"): background/celula
/// </summary>
public class BackgroundLoader : MonoBehaviour
{
    // ── Campos públicos ──────────────────────────────────────────────────
    [Header("Referencias en Escena")]
    [SerializeField] private Image backgroundImage;

    [Header("Addressable Keys")]
    [SerializeField] private string digestiveBackgroundKey = "background/digestivo";
    [SerializeField] private string cellBackgroundKey = "background/celula";

    // ── Internos ─────────────────────────────────────────────────────────
    private AsyncOperationHandle<Sprite> _currentHandle;

    /// <summary>
    /// Carga el fondo según el juego seleccionado en GameSelector.
    /// Lee el ID desde PlayerPrefs (selected_activity_id).
    /// </summary>
    public void LoadBackgroundForSelectedGame()
    {
        int selectedGameId = PlayerPrefs.GetInt("selected_activity_id", 1);
        LoadBackgroundByGameId(selectedGameId);
    }

    /// <summary>
    /// Carga el fondo basado en el ID del juego.
    /// ID 1 = Digestivo, ID 2 = Célula
    /// </summary>
    public void LoadBackgroundByGameId(int gameId)
    {
        if (backgroundImage == null)
        {
            Debug.LogError("BackgroundLoader: No hay Image asignado en Inspector");
            return;
        }

        string addressableKey = GetBackgroundKeyForGame(gameId);

        if (string.IsNullOrEmpty(addressableKey))
        {
            Debug.LogWarning($"BackgroundLoader: Juego ID {gameId} no tiene fondo configurado");
            return;
        }

        LoadBackgroundAsset(addressableKey);
    }

    /// <summary>
    /// Carga el fondo basado en el tipo de juego (nombre).
    /// </summary>
    public void LoadBackgroundByGameType(string gameType)
    {
        if (backgroundImage == null)
        {
            Debug.LogError("BackgroundLoader: No hay Image asignado en Inspector");
            return;
        }

        string addressableKey = GetBackgroundKeyForGameType(gameType);

        if (string.IsNullOrEmpty(addressableKey))
        {
            Debug.LogWarning($"BackgroundLoader: Tipo de juego '{gameType}' no tiene fondo configurado");
            return;
        }

        LoadBackgroundAsset(addressableKey);
    }

    /// <summary>
    /// Mapea el ID del juego a la clave addressable correspondiente.
    /// </summary>
    private string GetBackgroundKeyForGame(int gameId)
    {
        return gameId switch
        {
            1 => digestiveBackgroundKey,      // Digestivo
            2 => cellBackgroundKey,            // Célula
            _ => null
        };
    }

    /// <summary>
    /// Mapea el tipo de juego (string) a la clave addressable.
    /// </summary>
    private string GetBackgroundKeyForGameType(string gameType)
    {
        return gameType.ToLower() switch
        {
            "digestive" or "digestivo" => digestiveBackgroundKey,
            "cell" or "célula" or "celula" => cellBackgroundKey,
            _ => null
        };
    }

    /// <summary>
    /// Carga el asset addressable y lo asigna al Image.
    /// </summary>
    private void LoadBackgroundAsset(string addressableKey)
    {
        Debug.Log($"BackgroundLoader: Cargando fondo desde addressable: {addressableKey}");

        // Liberar el handle anterior si existe
        if (_currentHandle.IsValid())
        {
            Addressables.Release(_currentHandle);
        }

        // Cargar nuevo asset
        _currentHandle = Addressables.LoadAssetAsync<Sprite>(addressableKey);
        _currentHandle.Completed += OnBackgroundLoaded;
    }

    /// <summary>
    /// Callback cuando el fondo se ha cargado.
    /// </summary>
    private void OnBackgroundLoaded(AsyncOperationHandle<Sprite> handle)
    {
        if (handle.Status == AsyncOperationStatus.Succeeded)
        {
            backgroundImage.sprite = handle.Result;
            Debug.Log($"✓ BackgroundLoader: Fondo cargado exitosamente");
        }
        else
        {
            Debug.LogError($"✗ BackgroundLoader: Error al cargar fondo - Status: {handle.Status}");
        }
    }

    /// <summary>
    /// Limpia recursos al destruir el objeto.
    /// </summary>
    private void OnDestroy()
    {
        if (_currentHandle.IsValid())
        {
            Addressables.Release(_currentHandle);
        }
    }
}
