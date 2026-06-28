using UnityEngine;
using System.Collections.Generic;

public class TermsRepository : MonoBehaviour
{
    

// Repositorio encargado de realizar la consulta a la base de datos de los temas
// 



public class ConsultaModuloResult
{
    public int id_module { get; set; }
    public string module_name { get; set; }
    public string description { get; set; }
    public string topics { get; set; } 
}

[System.Serializable]
public class SeccionJson
{
    public int section_id;
    public string title;
    public string content;
    public string type;
}

[System.Serializable]
public class TopicJson
{
    public int topic_id;
    public string topic_name;
    public List<SeccionJson> sections;
}
}