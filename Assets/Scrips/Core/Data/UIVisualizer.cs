using UnityEngine;
using TMPro;
using System.Collections.Generic;

public class UIVisualizer : MonoBehaviour
{
    
    //Opciones del menú
    public enum ModoCarga {CargarTabla, CargarDatoUnico}
    
    [Header("Configuración de Carga")]
    public ModoCarga modoSeleccionado;
    public  ModulesRepository ModulesRepository;
    public string NombreTabla;

    [Header("Referencias UI")]
    public TextMeshProUGUI textoMesh;

    void Start()

    {
        ModulesRepository = new ModulesRepository();
        ConfiguracionFuncion();
    }

    //Selección de la función
    void ConfiguracionFuncion()
    {
        if (modoSeleccionado == ModoCarga.CargarTabla)
        {
            CargarTabla();
        }
        else
        {
            CargarDatoUnico();
        }
    }

    // Carga de datos completa
    public void CargarTabla()
    {
        List<string[]> filas = ModulesRepository.ObtenerDatos(NombreTabla);

        if (filas != null && filas.Count > 0)
        {
            string[] fila = filas[0]; 

            string textoTabla = ""; 

            // Recorremos cada columna de la fila
            for (int i = 0; i < fila.Length; i++)
            {
                // Salta la columna 0 que es el ID
                if (i == 0) continue; 

                // Unimos el texto: \n crea un salto de línea entre columnas
                textoTabla += fila[i] + "\n\n"; 
            }

            // Asignamos el resultado final al componente TextMeshPro
            textoMesh.text = textoTabla;
        }
        else
        {
            Debug.LogWarning("No se encontraron datos para la tabla: " + NombreTabla);
        }
    }
    
    //Selección columna Unica
    public void CargarDatoUnico()
    {
        //solo para la descripción
        string soloTexto = ModulesRepository.ObtenerDatoUnico(NombreTabla, "procesos");
    
        textoMesh.text = soloTexto;
    }
}