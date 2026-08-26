using System.Collections.Generic;
using UnityEngine;

[System.Serializable]
public class StudentCardData
{
    public string Name;
    public string Degree;
    public string CompletedTopicsText;
    public string Status;

    public StudentCardData(string name, string degree, string completedTopicsText, string status)
    {
        Name = name;
        Degree = degree;
        CompletedTopicsText = completedTopicsText;
        Status = status;
    }
}

public class StudentListController : MonoBehaviour
{
    [SerializeField] private GameObject studentCardPrefab;
    [SerializeField] private Transform cardsContainer;

    private StudentService studentService;

    private void Awake()
    {
        studentService = new StudentService();
    }

    private void Start()
    {
        // Si la base de datos ya esta lista, cargar inmediatamente
        if (DatabaseManager.Instance != null && DatabaseManager.Instance.IsReady)
        {
            LoadStudentsFromDatabase();
        }
        else if (DatabaseManager.Instance != null)
        {
            // Esperar a que la BD termine de inicializarse
            DatabaseManager.Instance.OnReady += LoadStudentsFromDatabase;
        }
    }

    private void OnDestroy()
    {
        if (DatabaseManager.Instance != null)
        {
            DatabaseManager.Instance.OnReady -= LoadStudentsFromDatabase;
        }
    }

    /// <summary>
    /// Consulta los datos reales de SQLite y genera las cards en la UI.
    /// </summary>
    public void LoadStudentsFromDatabase()
    {
        List<StudentCardData> realStudents = studentService.GetStudentsForCards();
        GenerateStudentCards(realStudents);
    }

    public void GenerateStudentCards(List<StudentCardData> studentsList)
    {
        // Limpiar cards anteriores
        foreach (Transform child in cardsContainer)
        {
            Destroy(child.gameObject);
        }

        // Generar cards dinamicas
        foreach (var student in studentsList)
        {
            GameObject newCard = Instantiate(studentCardPrefab, cardsContainer);
            StudentCardUI cardUI = newCard.GetComponent<StudentCardUI>();

            if (cardUI != null)
            {
                cardUI.Setup(student);
            }
        }
    }
}