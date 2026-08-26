using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class StudentService
{
    private readonly DegreeService degreeService;

    public StudentService()
    {
        degreeService = new DegreeService();
    }

    public List<StudentCardData> GetStudentsForCards()
    {
        List<StudentCardData> studentsCardsList = new List<StudentCardData>();

        if (DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady)
        {
            Debug.LogWarning("StudentService: La base de datos aun no esta lista.");
            return studentsCardsList;
        }

        var db = DatabaseManager.Instance.GetConnection();

        try
        {
            var studentUsers = db.Table<UserModel>().Where(u => u.id_role == 1).ToList();

            foreach (var student in studentUsers)
            {
                string studentName = student.name;
                
                var degreeObj = degreeService.GetDegreeById(student.id_degree);
                string degreeName = degreeObj != null ? degreeObj.name : "N/A";

                // --- CÁLCULO REAL DESDE LA BASE DE DATOS ---
                // Cuenta cuantas actividades o temas ha completado el estudiante en la tabla result_activity
                int completedCount = db.Table<ResultActivityData>()
                                       .Where(r => r.id_user == student.id_user)
                                       .Count();

                int totalTopics = 2; // O el total de temas/módulos que tenga tu curso
                string completedTopics = $"{completedCount}/{totalTopics}";

                // Determinar el estado automáticamente
                string status = completedCount == 0 ? "No Iniciado" : 
                               (completedCount >= totalTopics ? "Completado" : "En Progreso");

                studentsCardsList.Add(new StudentCardData(studentName, degreeName, completedTopics, status));
            }
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"StudentService: Error al consultar estudiantes en la BD: {ex.Message}");
        }

        return studentsCardsList;
    }
}