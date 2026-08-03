using Newtonsoft.Json;
using UnityEngine;
using UnityEngine.UI;
using TMPro;
using System.Collections.Generic;
using System.Collections;

public class UIVisualizer : MonoBehaviour
{
    [Header("Solución de Layout")]
    public RectTransform contenedorPrincipal; 

    [Header("Conexiones UI")]
    public TextMeshProUGUI txtModulo;
    public TextMeshProUGUI tituloPrincipal;
    public Image imagenModelo;

    [Header("Secciones Fijas / Paneles (Opcional)")]
    public TextMeshProUGUI[] panelesSeccion;

    [Header("Generación Dinámica")]
    public GameObject prefabBloqueSeccion;
    public Color[] paletaColores;

    [Header("Otras Referencias")]
    public BookAnimation BookAnimation;
    public ModulesRepository repository;

    private List<GameObject> bloquesInstanciados = new List<GameObject>();

    void Start()
    {
        repository = new ModulesRepository(); 
        MostrarModulo(0);
    }

    public void MostrarIntroduccion(int id_module)
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
        
        if (BookAnimation == null) 
        {
            Debug.LogWarning("Falta la referencia de BookAnimation en el UIVisualizer");
            return;
        }
        
        if (listaTemas != null && listaTemas.Count > 0)
        {
            BookAnimation.IniT(listaTemas);
        }
    }

    public void RenderizarUnicoTema(TopicJson tema)
    {
        OcultarContenedor();
        LimpiarBloques();

        if (tituloPrincipal != null) 
        {
            ActivarObjeto(tituloPrincipal.gameObject);

            string textoTitulo = string.IsNullOrEmpty(tema.topic_name) ? "TÍTULO VACÍO EN JSON" : tema.topic_name;
            tituloPrincipal.text = textoTitulo;
        }
        else
        {
            Debug.LogError("[UIVisualizer] La variable 'tituloPrincipal' no está asignada en el Inspector.");
        }

        bool esPaginaIntro = (tema.topic_id == -1);

        if (esPaginaIntro)
        {
            // ==========================================
            // --- MODO INTRODUCCIÓN ---
            // ==========================================
            
            if (txtModulo != null) 
            {
                ActivarObjeto(txtModulo.gameObject);
                if (tema.sections != null && tema.sections.Count > 0)
                {
                    txtModulo.text = tema.sections[0].content; 
                }
            }

            if (imagenModelo != null) 
            {
                imagenModelo.enabled = false;
                imagenModelo.gameObject.SetActive(false);
            }
        }
        else
        {
            // ==========================================
            // --- TEMAS ---
            // ==========================================

            if (txtModulo != null) 
            {
                txtModulo.gameObject.SetActive(false);
            }

            if (tema.sections != null)
            {
                int panelesEstaticosCount = (panelesSeccion != null) ? panelesSeccion.Length : 0;

                for (int i = 0; i < tema.sections.Count; i++)
                {
                    var seccion = tema.sections[i];

                    // Si hay un panel fijo configurado (Text1, Text2), lo usamos
                    if (i < panelesEstaticosCount && panelesSeccion[i] != null)
                    {
                        GameObject obj = ObtenerContenedor(panelesSeccion[i]);
                        obj.SetActive(true);
                        panelesSeccion[i].gameObject.SetActive(true);
                        panelesSeccion[i].text = $"<b>{seccion.title}</b>\n{seccion.content}";
                    }
                    // Si el tema tiene más secciones, instanciamos dinámicamente
                    else if (prefabBloqueSeccion != null)
                    {
                        GameObject nuevoBloque = Instantiate(prefabBloqueSeccion, contenedorPrincipal);
                        bloquesInstanciados.Add(nuevoBloque);

                        TextMeshProUGUI textoBloque = nuevoBloque.GetComponentInChildren<TextMeshProUGUI>();
                        if (textoBloque != null)
                        {
                            textoBloque.text = $"<b>{seccion.title}</b>\n{seccion.content}";
                        }

                        Image fondo = nuevoBloque.GetComponent<Image>();
                        if (fondo != null && paletaColores != null && paletaColores.Length > 0)
                        {
                            fondo.color = paletaColores[i % paletaColores.Length];
                        }
                    }
                }
            }

            // Manejo de la imagen 3D
            if (imagenModelo != null)
            {
                if (!string.IsNullOrEmpty(tema.image))
                {
                    Sprite nuevaImagen = Resources.Load<Sprite>(tema.image);
                    if (nuevaImagen != null)
                    {
                        imagenModelo.sprite = nuevaImagen;
                        imagenModelo.enabled = true;
                        imagenModelo.gameObject.SetActive(true);
                    }
                    else
                    {
                        Debug.LogWarning($"[UIVisualizer] No se encontró la imagen '{tema.image}' en Resources.");
                        imagenModelo.enabled = false;
                        imagenModelo.gameObject.SetActive(false);
                    }
                }
                else
                {
                    imagenModelo.enabled = false;
                    imagenModelo.gameObject.SetActive(false);
                }
            }
        }

        // 3. Forzar refresco de Layout
        if (gameObject.activeInHierarchy)
        {
            StartCoroutine(ActualizacionUI());
        }
    }

    private void ActivarObjeto(GameObject obj)
    {
        if (obj == null) return;
        Transform actual = obj.transform;
        while (actual != null)
        {
            actual.gameObject.SetActive(true);
            actual = actual.parent;
        }
    }

    private void OcultarContenedor()
    {
        if (contenedorPrincipal == null) return;

        foreach (Transform hijo in contenedorPrincipal)
        {
            // PROTECCIÓN: Si el título o la info son este hijo O están dentro de él, no apagarlo
            if (tituloPrincipal != null && (hijo == tituloPrincipal.transform || tituloPrincipal.transform.IsChildOf(hijo))) 
                continue;
                
            if (txtModulo != null && (hijo == txtModulo.transform || txtModulo.transform.IsChildOf(hijo))) 
                continue;

            hijo.gameObject.SetActive(false);
        }
    }

    private void LimpiarBloques()
    {
        foreach (GameObject bloque in bloquesInstanciados)
        {
            if (bloque != null) Destroy(bloque);
        }
        bloquesInstanciados.Clear();
    }

    private GameObject ObtenerContenedor(TextMeshProUGUI texto)
    {
        if (texto.transform.parent != null && texto.transform.parent != contenedorPrincipal)
        {
            return texto.transform.parent.gameObject;
        }
        return texto.gameObject;
    }

    IEnumerator ActualizacionUI()
    {
        yield return new WaitForEndOfFrame();
        
        if (contenedorPrincipal != null)
        {
            LayoutRebuilder.ForceRebuildLayoutImmediate(contenedorPrincipal);
        }
    }
}