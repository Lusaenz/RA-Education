using Newtonsoft.Json;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections.Generic;

public class UIVisualizer : MonoBehaviour
{

    //Opciones del menú
    [Header("Conexiones UI")]
    //public GameObject InfoModules;
    public TextMeshProUGUI txtModulo;
    public TextMeshProUGUI tituloPrincipal;
    //matriz de paneles
    public TextMeshProUGUI[] panelesSeccion; 
    public Image imagenModelo;

    [Header("Otras Referencias")]
    public BookAnimation BookAnimation;
    public ModulesRepository repository;

    void Start()
    {
        repository = new ModulesRepository(); 
        
        MostrarModulo(0);
    }


    public void MostrarIntroduccionModulo(int id_module)
    {
        ModuleModel infoModulo = repository.ObtenerModulo(id_module);

        if (infoModulo != null && txtModulo != null)
        {
            txtModulo.text = $"<b>{infoModulo.name}</b>\n\n{infoModulo.description}";
        }
        else
        {
            Debug.LogWarning("No se encontró información del módulo " + id_module);
        }
    }
    public void MostrarModulo(int id_module)
    {

        List<TopicJson> listaTemas = repository.ObtenerEstructuraCompleta(id_module);
        
        if (BookAnimation == null || panelesSeccion == null || panelesSeccion.Length == 0) 
        {
            Debug.LogWarning("Faltan referencias de UI o del Animador en el UIVisualizer");
            return;
        }
        
        if (listaTemas != null && listaTemas.Count > 0)
        {
            BookAnimation.IniT(listaTemas);
        }

    }


    public void RenderizarUnicoTema(TopicJson tema)
    {
        if (tituloPrincipal != null) 
        {
            tituloPrincipal.text = tema.topic_name;
        }

        bool esPaginaIntro = (tema.topic_id == -1);

        if (esPaginaIntro){

        foreach (var p in panelesSeccion) 
        {
            if (p != null) p.transform.parent.gameObject.SetActive(false);
        }
        
        if (txtModulo != null) 
        {
            txtModulo.gameObject.SetActive(true);
            if (tema.sections != null && tema.sections.Count > 0)
            {
                txtModulo.text = tema.sections[0].content; 
            }
        }

        if (imagenModelo != null) imagenModelo.enabled = false;
    }
    else
    {
        // APAGAR TEXTO DE INTRODUCCIÓN
        if (txtModulo != null) txtModulo.gameObject.SetActive(false);
        
        // ENCENDER LOS BLOQUES DE COLORES COMPLETOS
        foreach (var p in panelesSeccion) 
        {
            if (p != null) 
            {
                p.transform.parent.gameObject.SetActive(true);
                p.text = ""; // Limpiamos el texto viejo
            }
        }

        if (tema.sections != null)
        {
            for (int i = 0; i < tema.sections.Count; i++)
            {
                if (i < panelesSeccion.Length && panelesSeccion[i] != null)
                {
                    var seccion = tema.sections[i];
                    panelesSeccion[i].text = $"<b>{seccion.title}</b>\n{seccion.content}";
                }
            }
        }
    } 
        
        Debug.Log("Buscando en Resources el archivo: '" + tema.image + "'");

        if (imagenModelo != null)
        {
            if (!string.IsNullOrEmpty(tema.image))
            {
                Sprite nuevaImagen = Resources.Load<Sprite>(tema.image);
                
                if (nuevaImagen != null)
                {
                    imagenModelo.sprite = nuevaImagen;
                    imagenModelo.enabled = true;
                }
                else
                {
                    Debug.LogWarning($"[UIVisualizer] No se encontró el archivo Sprite con el nombre '{tema.image}' dentro de la carpeta Resources.");
                    imagenModelo.enabled = false;
                }
            }
            else
            {
                imagenModelo.enabled = false; 
            }
        }
    }
}
