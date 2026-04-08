using UnityEngine;
using UnityEngine.SceneManagement;

public class RestartLevel : MonoBehaviour

{
    

    public void RestartGame()
    
    {
        GameObject winPanel = GameObject.Find("WinPanel"); 
       
        if (winPanel != null)
        {
            winPanel.SetActive(false);
        }

        // Recargar la escena actual
        SceneManager.LoadScene(SceneManager.GetActiveScene().buildIndex);
    
    }
}