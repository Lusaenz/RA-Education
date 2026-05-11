using UnityEngine;
using UnityEngine.SceneManagement;

public class BtnRA : MonoBehaviour
{
    public string sceneName = "RAScreen";

    public void OpenRAScene()
    {
        Debug.Log("Intentando abrir escena");
        SceneManager.LoadScene(sceneName);
    }
}