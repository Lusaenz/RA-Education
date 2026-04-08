using UnityEngine;
using UnityEngine.SceneManagement;

public class SceneLoader : MonoBehaviour
{
    public string sceneName;

    public void LoadScene()
    {
        Debug.Log("CLICK FUNCIONA");
        SceneManager.LoadScene(sceneName);
    }
}