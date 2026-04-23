using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    public static UIManager Instance;

    public GameObject panelInfo;
    public Text title;
    public Text description;
    public Text processes;
    public Text diseases;
    public Text care;

    void Awake()
    {
        Instance = this;
    }

   /* public void ShowInfo(string partID)
    {
        panelInfo.SetActive(true);

        PartData data = DatabaseMock.GetData(partID);

        title.text = data.title;
        description.text = data.description;
        processes.text = data.processes;
        diseases.text = data.diseases;
        care.text = data.care;
    }*/

    public void ClosePanel()
    {
        panelInfo.SetActive(false);
    }
}