using UnityEngine;
using Vuforia;
using System.Collections.Generic;

public class Observer : MonoBehaviour
{
    public Transform arCamera;
    public Transform fixedModel;

    public Vector3 rotationOffset = new Vector3(0f, 180f, 0f);

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

                
                if (model != fixedModel)
                {
                    if (model.GetComponent<DragObject>() == null)
                    {
                        model.gameObject.AddComponent<DragObject>();
                    }
                }

                model.SetParent(null);
            }

            MoveAllToCenter();
        }
    }

    void MoveAllToCenter()
    {
        float distance = 1.0f;
        Vector3 center = arCamera.position + arCamera.forward * distance;

        Camera cam = arCamera.GetComponent<Camera>();
        float fov = cam.fieldOfView * Mathf.Deg2Rad;

        float visibleHeight = 2f * distance * Mathf.Tan(fov / 2f);
        float visibleWidth = visibleHeight * cam.aspect;

        float scale = Mathf.Min(visibleWidth, visibleHeight) * 0.18f;

        Quaternion rotation =
            Quaternion.LookRotation(arCamera.forward) *
            Quaternion.Euler(rotationOffset);

    
        if (fixedModel != null)
        {
            fixedModel.position = center;
            fixedModel.rotation = rotation;
            fixedModel.localScale = Vector3.one * scale;
        }

        
        List<Transform> movableModels = new List<Transform>();

        foreach (Transform model in models)
        {
            if (model != fixedModel)
            {
                movableModels.Add(model);
            }
        }

        
        float radius = Mathf.Min(visibleWidth, visibleHeight) * 0.45f;

        for (int i = 0; i < movableModels.Count; i++)
        {
            float angle = (360f / movableModels.Count) * i;

            float rad = angle * Mathf.Deg2Rad;

            Vector3 offset =
                arCamera.right * Mathf.Cos(rad) * radius +
                arCamera.up * Mathf.Sin(rad) * radius;

            movableModels[i].position = center + offset;
            movableModels[i].rotation = rotation;
            movableModels[i].localScale = Vector3.one * scale;
        }
    }
}