using UnityEngine;
using UnityEngine.UI;
using UnityEngine.EventSystems;

[RequireComponent(typeof(Image))]
public class DuckCanvasWalker : MonoBehaviour, IPointerClickHandler
{
    [Header("Animacion caminando")]
    [SerializeField] private Sprite[] walkFrames;
    [SerializeField] private float framesPerSecond = 10f;

    [Header("Pose al tocar")]
    [SerializeField] private Sprite[] tapFrames;
    [SerializeField] private float tapPoseDuration = 1.2f;

    [Header("Movimiento")]
    [SerializeField] private RectTransform leftPoint;
    [SerializeField] private RectTransform rightPoint;
    [SerializeField] private float speed = 180f;

    private RectTransform rectTransform;
    private Image image;

    private Vector2 target;
    private bool goingRight = true;

    private int frameIndex;
    private float frameTimer;

    private bool doingTapPose;
    private float tapTimer;

    private void Awake()
    {
        rectTransform = GetComponent<RectTransform>();
        image = GetComponent<Image>();

        image.raycastTarget = true;

        if (walkFrames.Length > 0)
            image.sprite = walkFrames[0];

        if (rightPoint != null)
            target = rightPoint.anchoredPosition;
    }

    private void Update()
    {
        if (doingTapPose)
        {
            PlayFrames(tapFrames);

            tapTimer -= Time.unscaledDeltaTime;
            if (tapTimer <= 0f)
            {
                doingTapPose = false;
                frameIndex = 0;
            }

            return;
        }

        PlayFrames(walkFrames);
        MoveDuck();
    }

    public void OnPointerClick(PointerEventData eventData)
    {
        if (tapFrames == null || tapFrames.Length == 0)
            return;

        doingTapPose = true;
        tapTimer = tapPoseDuration;
        frameIndex = 0;
        frameTimer = 0f;
    }

    private void PlayFrames(Sprite[] frames)
    {
        if (frames == null || frames.Length == 0)
            return;

        frameTimer += Time.unscaledDeltaTime;

        if (frameTimer >= 1f / framesPerSecond)
        {
            frameTimer = 0f;
            frameIndex = (frameIndex + 1) % frames.Length;
            image.sprite = frames[frameIndex];
        }
    }

    private void MoveDuck()
    {
        if (leftPoint == null || rightPoint == null)
            return;

        rectTransform.anchoredPosition = Vector2.MoveTowards(
            rectTransform.anchoredPosition,
            target,
            speed * Time.unscaledDeltaTime
        );

        if (Vector2.Distance(rectTransform.anchoredPosition, target) < 2f)
        {
            goingRight = !goingRight;
            target = goingRight ? rightPoint.anchoredPosition : leftPoint.anchoredPosition;

            Vector3 scale = rectTransform.localScale;
            scale.x = Mathf.Abs(scale.x) * (goingRight ? -1f : 1f);
            rectTransform.localScale = scale;
        }
    }
}