using UnityEngine;

public class SnapPiece : MonoBehaviour
{
    public PuzzleManager puzzleManager;
    public Transform snapPoint;
    public Transform targetSnapPoint;

    public float snapDistance = 0.08f;

    private bool isSnapped = false;
    private float debugDistance;


    void Update()
{
    if (snapPoint == null || targetSnapPoint == null) return;

    float distance = Vector3.Distance(snapPoint.position, targetSnapPoint.position);
    debugDistance = distance;

    if (distance < snapDistance)
    {
        Snap();
    }
}

void OnGUI()
{
    GUI.Label(new Rect(10, 10, 400, 40), "Prueba: " + debugDistance);
}
    void Snap()
    {
       
        Vector3 offset = targetSnapPoint.position - snapPoint.position;
        transform.position += offset;
        transform.rotation = targetSnapPoint.rotation;

        Transform group = CreateOrGetGroup(targetSnapPoint.parent);

        
        transform.SetParent(group);
        targetSnapPoint.parent.SetParent(group);

        isSnapped = true;

        Debug.Log("Piezas unidas");
        
    }

    Transform CreateOrGetGroup(Transform other)
    {
       
        if (other.parent != null && other.parent.name.StartsWith("Group"))
        {
            return other.parent;
        }

        
        GameObject group = new GameObject("Group");
        group.transform.position = other.position;

        return group.transform;
    }
}