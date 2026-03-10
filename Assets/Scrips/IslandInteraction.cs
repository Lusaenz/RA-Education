using UnityEngine;

public class IslandInteraction : MonoBehaviour
{
    public GameObject bookSystem;
    public GameObject canvasTopHUD;
    public GameObject canvasBottomInfo;

    void Update()
    {
        // TOUCH (movil)
        if (Input.touchCount > 0)
        {
            Touch touch = Input.GetTouch(0);

            if (touch.phase == TouchPhase.Began)
            {
                CheckHit(touch.position);
            }
        }

        // MOUSE (editor Unity)
        if (Input.GetMouseButtonDown(0))
        {
            CheckHit(Input.mousePosition);
        }
    }

    void CheckHit(Vector2 position)
    {
        Ray ray = Camera.main.ScreenPointToRay(position);
        RaycastHit hit;

        if (Physics.Raycast(ray, out hit))
        {
            if (hit.transform == transform)
            {
                OpenBook();
            }
        }
    }

    void OpenBook()
    {
        Debug.Log("Isla tocada");
        canvasTopHUD.SetActive(false);
        canvasBottomInfo.SetActive(false);
        bookSystem.SetActive(true);
    }
}