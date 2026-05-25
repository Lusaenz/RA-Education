using UnityEngine;

public class InfoPanelManager : MonoBehaviour
{
    [Header("Todos los paneles informativos")]
    public GameObject[] panels;

    private int currentPanel = -1;

    void Start()
    {
        HideAllPanels();
    }

    public void TogglePanel(int panelIndex)
    {
        Debug.Log("Botón presionado: " + panelIndex);

        if (currentPanel == panelIndex)
        {
            panels[panelIndex].SetActive(false);

            currentPanel = -1;

            return;
        }

        HideAllPanels();

        panels[panelIndex].SetActive(true);

        currentPanel = panelIndex;
    }

    void HideAllPanels()
    {
        foreach (GameObject panel in panels)
        {
            panel.SetActive(false);
        }
    }
}