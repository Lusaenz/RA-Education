using UnityEngine;

public class SnapPiece : MonoBehaviour
{
    public Transform snapPoint;
    public Transform targetSnapPoint;

    public float snapDistance = 0.05f;

    private bool isSnapped = false;
    private float debugDistance;

    private SnapPiece[] allPieces;

    void Start()
    {
        allPieces = FindObjectsByType<SnapPiece>(FindObjectsSortMode.None);
    }

    void OnGUI()
    {
        GUI.Label(new Rect(10, 10, 400, 40), "Prueba: " + debugDistance);
    }

   
    void Snap(Transform target)
    {
        Vector3 offset = target.position - snapPoint.position;


        // offset.z = 0f;

        transform.position += offset;

        Transform group = CreateOrGetGroup(target.parent);

        transform.SetParent(group);

        if (target.parent.parent != group)
        {
            target.parent.SetParent(group);
        }

        isSnapped = true;

        
DragObject drag = GetComponent<DragObject>();

if (drag != null)
{
    drag.enabled = false;
}

        if (PuzzleManager.instance != null)
        {
            PuzzleManager.instance.ItemCorrecto();
        }
        else
        {
            Debug.LogError("No existe un PuzzleManager en la escena.");
        }
    }

    Transform CreateOrGetGroup(Transform other)
    {
        if (other.parent != null &&
            other.parent.name.StartsWith("Group"))
        {
            return other.parent;
        }

        GameObject group = new GameObject("Group");

        group.transform.position = other.position;

        group.transform.SetParent(transform.parent);

        return group.transform;
    }

   
    bool NearWrongSnap()
    {
        foreach (SnapPiece piece in allPieces)
        {
            if (piece == this)
                continue;

            if (piece.isSnapped)
                continue;

            float distance = Vector3.Distance(
                snapPoint.position,
                piece.targetSnapPoint.position);

            if (distance < snapDistance)
            {
                return true;
            }
        }

        return false;
    }


    public bool TrySnap()
    {
        if (isSnapped)
            return true;

        
        if (targetSnapPoint != null)
        {
            float distance = Vector3.Distance(
                snapPoint.position,
                targetSnapPoint.position);

            if (distance <= snapDistance)
            {
                Snap(targetSnapPoint);
                return true;
            }
            Debug.Log("esteeee");
        }

       
        foreach (SnapPiece piece in allPieces)
        {
            if (piece == this)
                continue;

            if (piece.targetSnapPoint == snapPoint)
            {
                float distance = Vector3.Distance(
                    piece.snapPoint.position,
                    snapPoint.position);

                if (distance <= snapDistance)
                {
                    
                    Snap(piece.snapPoint);
                    return true;
                }
            }
        }

        return false;
    }

    private bool IsNearWrongSnap()
    {
        SnapPiece[] pieces = FindObjectsByType<SnapPiece>(FindObjectsSortMode.None);

        foreach (SnapPiece piece in pieces)
        {
            if (piece == this)
                continue;

            float distance = Vector3.Distance(
                snapPoint.position,
                piece.targetSnapPoint.position);

            if (distance <= snapDistance)
            {
                return true;
            }
        }

        return false;
    }

    public bool IsSnapped()
    {
        return isSnapped;
    }
}