using UnityEngine;

public class MembraneVisibility : MonoBehaviour
{
    public static MembraneVisibility Instance;

    public MeshRenderer[] renderers;

    void Awake()
    {
        Instance = this;
    }

    public void Hide()
    {
        foreach (MeshRenderer renderer in renderers)
        {
            if (renderer != null)
                renderer.enabled = false;
        }
    }

    public void Show()
    {
        foreach (MeshRenderer renderer in renderers)
        {
            if (renderer != null)
                renderer.enabled = true;
        }
    }
}