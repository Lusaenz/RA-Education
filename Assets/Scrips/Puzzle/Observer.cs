using UnityEngine;
using Vuforia;
using System.Collections.Generic;

public class Observer : MonoBehaviour
{
    public Transform arCamera;
    public Transform fixedModel;

    [Header("Ajustes de Vista en Pantalla")]
    [Tooltip("Distancia hacia adelante desde la cámara donde flotarán los objetos (en metros)")]
    public float distanceFromCamera = 0.8f;

    [Tooltip("Distancia extra hacia ATRÁS para el modelo fijo (valores positivos lo alejan más)")]
    public float fixedModelDepthOffset = 0.3f; // <--- NUEVA VARIABLE

    [Tooltip("Radio del círculo alrededor del modelo central")]
    public float radiusOffset = 0.25f;

    [Tooltip("Escala fija de los modelos frente a la cámara")]
    public float modelsScale = 0.08f;

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

        if (arCamera == null && Camera.main != null)
        {
            arCamera = Camera.main.transform;
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
            if (arCamera == null) return;

            alreadyPlaced = true;

            foreach (Transform model in models)
            {
                model.SetParent(arCamera, true);

                if (model.GetComponent<Collider>() == null)
                {
                    BoxCollider bc = model.gameObject.AddComponent<BoxCollider>();
                    bc.isTrigger = true;
                }

                if (model != fixedModel && model.GetComponent<DragObject>() == null)
                {
                    model.gameObject.AddComponent<DragObject>();
                }

                model.gameObject.SetActive(true);
            }

            PositionInFrontOfCamera();
        }
    }

    void PositionInFrontOfCamera()
    {
        Quaternion defaultRotation = Quaternion.Euler(rotationOffset);

        // 1. Posicionar el modelo fijo MÁS ATRÁS en el eje Z
        if (fixedModel != null)
        {
            // Sumamos fixedModelDepthOffset para alejarlo más de la cámara
            Vector3 fixedPosition = new Vector3(0f, 0f, distanceFromCamera + fixedModelDepthOffset);
            
            fixedModel.localPosition = fixedPosition;
            fixedModel.localRotation = defaultRotation;
            fixedModel.localScale = Vector3.one * modelsScale;
        }

        // 2. Filtrar modelos secundarios
        List<Transform> movableModels = new List<Transform>();
        foreach (Transform model in models)
        {
            if (model != fixedModel)
            {
                movableModels.Add(model);
            }
        }

        if (movableModels.Count == 0) return;

        // 3. Posicionar los modelos movibles en su distancia estándar (más al frente)
        for (int i = 0; i < movableModels.Count; i++)
        {
            float angle = (360f / movableModels.Count) * i;
            float rad = angle * Mathf.Deg2Rad;

            Vector3 localOffset = new Vector3(
                Mathf.Cos(rad) * radiusOffset,
                Mathf.Sin(rad) * radiusOffset,
                distanceFromCamera // Se quedan a la distancia estándar
            );

            movableModels[i].localPosition = localOffset;
            movableModels[i].localRotation = defaultRotation;
            movableModels[i].localScale = Vector3.one * modelsScale;
        }
    }
}