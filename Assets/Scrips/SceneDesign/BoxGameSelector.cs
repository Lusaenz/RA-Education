using UnityEngine;

public class BoxGameSelector : MonoBehaviour
{
    public int gameID;
    public GameInfoUI gameInfoUI;

    private void OnMouseDown()
    {
        Debug.Log("Click en caja ID: " + gameID);
        gameInfoUI.ShowGame(gameID);
    }
}