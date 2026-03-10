using UnityEngine;

public class BookAnimation : MonoBehaviour
{
    private Animator animator;

    void Start()
    {
        animator = GetComponent<Animator>();
    }

    public void PlayPageTurn()
    {
        animator.SetTrigger("TurnPage");
    }
}