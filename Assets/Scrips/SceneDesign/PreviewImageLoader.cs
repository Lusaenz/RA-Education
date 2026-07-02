using UnityEngine;
using UnityEngine.UI;
using UnityEngine.AddressableAssets;
using UnityEngine.ResourceManagement.AsyncOperations;

/// <summary>
/// Cargador dinámico de imágenes de preview según el juego seleccionado.
/// Lee el ID del juego desde PlayerPrefs y carga la imagen addressable correspondiente.
/// 
/// Mapeo de juegos:
/// - ID 1 (Digestivo): images/digestive
/// - ID 2 (Célula): images/cell
/// </summary>
public class PreviewImageLoader : MonoBehaviour
{
    // ── Campos públicos ──────────────────────────────────────────────────
    [Header("Referencias en Escena")]
    [SerializeField] private Image previewImage;

    [Header("Addressable Keys")]
    [SerializeField] private string digestiveImageKey = "images/digestive";
    [SerializeField] private string cellImageKey = "images/cell";
    [SerializeField] private string foodRiddlesImageKey = "images/food_riddles";

    // ── Internos ─────────────────────────────────────────────────────────
    private AsyncOperationHandle<Sprite> _currentHandle;

    /// <summary>
    /// Carga la imagen de preview según el juego seleccionado.
    /// Lee el ID desde PlayerPrefs (selected_activity_id).
    /// </summary>
    public void LoadPreviewForSelectedGame()
    {
        int selectedGameId = PlayerPrefs.GetInt("selected_activity_id", 1);
        LoadPreviewByGameId(selectedGameId);
    }

    /// <summary>
    /// Carga la imagen basada en el ID del juego.
    /// ID 1 = Digestivo, ID 2 = Célula
    /// </summary>
    public void LoadPreviewByGameId(int gameId)
    {
        if (previewImage == null)
        {
            Debug.LogError("PreviewImageLoader: No hay Image (previewImage) asignado en Inspector");
            return;
        }

        string addressableKey = GetPreviewKeyForGame(gameId);

        if (string.IsNullOrEmpty(addressableKey))
        {
            Debug.LogWarning($"PreviewImageLoader: Juego ID {gameId} no tiene preview de imagen configurado");
            return;
        }

        LoadPreviewAsset(addressableKey, gameId);
    }

    /// <summary>
    /// Carga la imagen basada en el tipo de juego (nombre).
    /// </summary>
    public void LoadPreviewByGameType(string gameType)
    {
        if (previewImage == null)
        {
            Debug.LogError("PreviewImageLoader: No hay Image (previewImage) asignado en Inspector");
            return;
        }

        string addressableKey = GetPreviewKeyForGameType(gameType);

        if (string.IsNullOrEmpty(addressableKey))
        {
            Debug.LogWarning($"PreviewImageLoader: Tipo de juego '{gameType}' no tiene preview configurado");
            return;
        }

        LoadPreviewAsset(addressableKey, 0);
    }

    /// <summary>
    /// Mapea el ID del juego a la clave addressable correspondiente.
    /// </summary>
    private string GetPreviewKeyForGame(int gameId)
    {
        return gameId switch
        {
            1 => digestiveImageKey,        // Digestivo
            2 => cellImageKey,             // Célula
            3 => foodRiddlesImageKey,      // Food Riddles
            _ => null
        };
    }

    /// <summary>
    /// Mapea el tipo de juego (string) a la clave addressable.
    /// </summary>
    private string GetPreviewKeyForGameType(string gameType)
    {
        if (string.IsNullOrEmpty(gameType))
        {
            return null;
        }

        return gameType.ToLower() switch
        {
            "drag_drop_digestive_system" or "digestive" or "digestivo" => digestiveImageKey,
            "drag_drop_cell" or "cell" or "célula" or "celula" => cellImageKey,
            "food_riddles" or "foodriddle" or "foodriddles" => foodRiddlesImageKey,
            _ => null
        };
    }

    /// <summary>
    /// Carga el asset addressable y lo asigna al Image.
    /// </summary>
    private void LoadPreviewAsset(string addressableKey, int gameId)
    {
        Debug.Log($"PreviewImageLoader: Cargando preview de imagen (ID {gameId}) desde addressable: {addressableKey}");

        // Liberar el handle anterior si existe
        if (_currentHandle.IsValid())
        {
            Addressables.Release(_currentHandle);
        }

        // Cargar nuevo asset
        _currentHandle = Addressables.LoadAssetAsync<Sprite>(addressableKey);
        _currentHandle.Completed += OnPreviewLoaded;
    }

    /// <summary>
    /// Callback cuando la imagen se ha cargado.
    /// </summary>
    private void OnPreviewLoaded(AsyncOperationHandle<Sprite> handle)
    {
        if (handle.Status == AsyncOperationStatus.Succeeded)
        {
            previewImage.sprite = handle.Result;
            Debug.Log($"✓ PreviewImageLoader: Imagen de preview cargada exitosamente");
        }
        else
        {
            Debug.LogError($"✗ PreviewImageLoader: Error al cargar imagen de preview - Status: {handle.Status}");
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
