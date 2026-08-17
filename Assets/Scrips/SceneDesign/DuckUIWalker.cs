using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class DuckUIWalker : MonoBehaviour
{
    [Header("UI")]
    [SerializeField] private RectTransform duck;
    [SerializeField] private Animator animator;

    [Header("Campos TMP")]
    [SerializeField] private TMP_InputField[] tmpInputs;

    [Header("Campos UI normales")]
    [SerializeField] private InputField[] legacyInputs;

    [Header("Movimiento")]
    [SerializeField] private Vector2 leftPoint = new Vector2(-260f, -420f);
    [SerializeField] private Vector2 rightPoint = new Vector2(260f, -420f);
    [SerializeField] private float speed = 180f;

    private Vector2 target;
    private bool movingRight = true;

    private void Awake()
    {
        if (duck == null)
            duck = GetComponent<RectTransform>();

        target = rightPoint;
    }

    private void Update()
    {
        bool studentIsTyping = IsAnyInputFocused();

        if (animator != null)
            animator.SetBool("IsWalking", studentIsTyping);
            animator.SetBool("facingRight", studentIsTyping);

        if (!studentIsTyping)
            return;

        MoveDuck();
    }

    private bool IsAnyInputFocused()
    {
        foreach (TMP_InputField input in tmpInputs)
        {
            if (input != null && input.isFocused)
                return true;
        }

        foreach (InputField input in legacyInputs)
        {
            if (input != null && input.isFocused)
                return true;
        }

        return false;
    }

    private void MoveDuck()
    {
        duck.anchoredPosition = Vector2.MoveTowards(
            duck.anchoredPosition,
            target,
            speed * Time.deltaTime
        );

        if (Vector2.Distance(duck.anchoredPosition, target) < 2f)
        {
            movingRight = !movingRight;
            target = movingRight ? rightPoint : leftPoint;

            Vector3 scale = duck.localScale;
            scale.x = Mathf.Abs(scale.x) * (movingRight ? 1f : -1f);
            duck.localScale = scale;
        }
    }
}