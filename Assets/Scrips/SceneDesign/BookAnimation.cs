using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class BookAnimation : MonoBehaviour
{
    public GameObject book;
    public GameObject bookPage;
    public UIVisualizer visualizador;

    private int idAct = 0;
    private List<TopicJson> temasCargados;

    public void IniT(List<TopicJson> temas)
    {
        temasCargados = temas;
        idAct = 0;
        Debug.Log($"Libro inicializado con {temasCargados.Count} temas.");
        ActualizarT();
    }

    public void Sigpag()
    {
        if (temasCargados != null && idAct < temasCargados.Count - 1)
        {
            idAct++;
            Debug.Log($"Cambiando a página: {idAct}");
            StartCoroutine(PageEffect());
        }
        else
        {
            Debug.Log("Ya estás en la última página o no hay temas cargados.");
        }
    }

    public void Antpag()
    {
        if (temasCargados != null && idAct > 0)
        {
            idAct--;
            StartCoroutine(PageEffect());
        }
    }

    void ActualizarT()
    {
        if (temasCargados != null && temasCargados.Count > idAct)
        {
            visualizador.RenderizarUnicoTema(temasCargados[idAct]);
        }
    }

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
        yield return new WaitForSeconds(0.2f);

        // actualizar pagina
        ActualizarT();

        yield return new WaitForSeconds(0.2f);

        // volver al libro normal
        bookPage.SetActive(false);
        book.SetActive(true);
    }

}