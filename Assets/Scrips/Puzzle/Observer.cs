using UnityEngine;
using Vuforia;
using System.Collections.Generic;

public class Observer : MonoBehaviour
{
    public Transform arCamera;

    private ObserverBehaviour observer;
    private List<Transform> models = new List<Transform>();
    private bool alreadyPlaced = false;

    void Start()
    {
        observer = GetComponent<ObserverBehaviour>();

        if (observer != null)
            observer.OnTargetStatusChanged += OnTargetStatusChanged;

        models.Clear();

        foreach (Transform t in transform)
        {
            models.Add(t);
        }
    }

    void OnDestroy()
    {
        if (observer != null)
            observer.OnTargetStatusChanged -= OnTargetStatusChanged;
    }

    private void OnTargetStatusChanged(ObserverBehaviour behaviour, TargetStatus status)
    {
        if ((status.Status == Status.TRACKED || status.Status == Status.EXTENDED_TRACKED) && !alreadyPlaced)
        {
            alreadyPlaced = true;

            foreach (Transform model in models)
            {
                if (model.GetComponent<Collider>() == null)
                {
                    model.gameObject.AddComponent<BoxCollider>();
                }

                if (model.GetComponent<DragObject>() == null)
                {
                    model.gameObject.AddComponent<DragObject>();
                }

                model.SetParent(null);

                if (model.GetComponent<DragObject>() == null)
                {
                    model.gameObject.AddComponent<DragObject>();
                }
            }

            MoveAllToCenter();
        }
    }

    void MoveAllToCenter()
    {
        int total = models.Count;

        int columns = Mathf.CeilToInt(Mathf.Sqrt(total));
        int rows = Mathf.CeilToInt((float)total / columns);

        float distance = 1.0f;
        Vector3 center = arCamera.position + arCamera.forward * distance;

        Camera cam = arCamera.GetComponent<Camera>();
        float fov = cam.fieldOfView * Mathf.Deg2Rad;

        float visibleHeight = 2f * distance * Mathf.Tan(fov / 2f);
        float visibleWidth = visibleHeight * cam.aspect;

        float cellWidth = visibleWidth / columns;
        float cellHeight = visibleHeight / rows;

        float spacingFactor = 0.8f;
        float spacingX = cellWidth * spacingFactor;
        float spacingY = cellHeight * spacingFactor;

        float scale = Mathf.Min(cellWidth, cellHeight) * 0.5f;

        for (int i = 0; i < total; i++)
        {
            int row = i / columns;
            int col = i % columns;

            float xOffset = (col - (columns - 1) / 2.0f) * spacingX;
            float yOffset = ((rows - 1) / 2.0f - row) * spacingY;

            Vector3 offset = (arCamera.right * xOffset) + (arCamera.up * yOffset);

            models[i].position = center + offset;

            models[i].rotation =
                Quaternion.LookRotation(arCamera.forward)
                * Quaternion.Euler(0f, 180f, 0f);

            models[i].localScale = Vector3.one * scale;
        }
    }
}