using UnityEngine;
using System.Collections;

public class BookAnimation : MonoBehaviour
{
    public GameObject book;
    public GameObject bookPage;

    public void TurnPage()
    {
        StartCoroutine(PageEffect());
    }

    IEnumerator PageEffect()
    {
        // ocultar libro normal
        book.SetActive(false);

        // mostrar hoja levantándose
        bookPage.SetActive(true);

        // pequeño tiempo para que se vea la animación
        yield return new WaitForSeconds(0.4f);

        // volver al libro normal
        bookPage.SetActive(false);
        book.SetActive(true);
    }
}