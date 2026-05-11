using UnityEngine;
using UnityEngine.SceneManagement;


public class BtnGame : MonoBehaviour
{
     public string sceneName = "GameSelection";

    public void OpenGameScene()
    {
        Debug.Log("Intentando abrir escena");
        SceneManager.LoadScene(sceneName);
    }
    
}
