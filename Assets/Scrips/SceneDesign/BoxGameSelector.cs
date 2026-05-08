using UnityEngine;

public class BoxGameSelector : MonoBehaviour
{
    public GameInfoUI gameInfoUI;

    private void OnMouseDown()
    {
        // Obtener el gameID del GameSelector (guardado en PlayerPrefs)
        int gameID = PlayerPrefs.GetInt("selected_activity_id", 0);
        
        Debug.Log("Click en caja ID: " + gameID);
        gameInfoUI.ShowGame(gameID);
    }
}