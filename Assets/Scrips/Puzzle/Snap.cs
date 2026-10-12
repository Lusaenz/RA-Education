using UnityEngine;

public class SnapPiece : MonoBehaviour
{
    public Transform snapPoint;
    public Transform targetSnapPoint;

    public float snapDistance = 0.05f;

    private bool isSnapped = false;

    private SnapPiece[] allPieces;

    void Start()
    {
        allPieces = FindObjectsByType<SnapPiece>(FindObjectsSortMode.None);
    }

    /// <summary>
    /// Distancia entre dos puntos tal como se ven en pantalla, expresada en metros
    /// a la profundidad de <paramref name="b"/>. La pieza se arrastra a profundidad
    /// constante y el modelo fijo esta mas lejos (e inclinado), asi que la distancia
    /// 3D nunca coincide con lo que el usuario ve alineado; se ignora la profundidad.
    /// </summary>
    public static float ScreenAlignedDistance(Vector3 a, Vector3 b)
    {
        Camera cam = Camera.main;
        if (cam == null)
            return Vector3.Distance(a, b);

        Vector3 la = cam.transform.InverseTransformPoint(a);
        Vector3 lb = cam.transform.InverseTransformPoint(b);

        if (la.z <= 0f || lb.z <= 0f)
            return float.PositiveInfinity;

        Vector2 pa = new Vector2(la.x, la.y) * (lb.z / la.z);
        return Vector2.Distance(pa, new Vector2(lb.x, lb.y));
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
            float distance = ScreenAlignedDistance(
                snapPoint.position,
                targetSnapPoint.position);

            if (distance <= snapDistance)
            {
                Snap(targetSnapPoint);
                return true;
            }
        }

       
        foreach (SnapPiece piece in allPieces)
        {
            if (piece == this)
                continue;

            if (piece.targetSnapPoint == snapPoint)
            {
                float distance = ScreenAlignedDistance(
                    snapPoint.position,
                    piece.snapPoint.position);

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