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
            TopicJson tema = temasCargados[idAct];
            visualizador.RenderizarUnicoTema(tema);
            RegistrarTemaVisto(tema);
        }
    }

    /// <summary>
    /// Marca el tema actual como visto para el avance del modulo. La pagina de introduccion
    /// (topic_id == -1) no cuenta como item.
    /// </summary>
    private void RegistrarTemaVisto(TopicJson tema)
    {
        if (tema == null || tema.topic_id <= 0)
        {
            return;
        }

        int moduleId = PlayerPrefs.GetInt("selected_module_id", 0);
        int userId = UserSessionManager.Instance?.CurrentUser?.id_user ?? 0;

        if (moduleId <= 0 || userId <= 0)
        {
            return;
        }

        new ProgressService().MarkTopicViewed(userId, moduleId, tema.topic_id);
        EstadoManager.Instance?.RefreshModule(moduleId);
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