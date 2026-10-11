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
        var progressService = new ProgressService();

        try
        {
            var studentUsers = db.Table<UserModel>().Where(u => u.id_role == 1).ToList();

            foreach (var student in studentUsers)
            {
                string studentName = student.name;
                
                var degreeObj = degreeService.GetDegreeById(student.id_degree);
                string degreeName = degreeObj != null ? degreeObj.name : "N/A";

                // --- CÁLCULO REAL DESDE LA BASE DE DATOS ---
                // Minijuegos distintos completados (tabla progress) sobre el total de game_activity.
                // Antes se contaban filas de result_activity (cada intento sumaba) contra un total fijo de 2.
                int completedCount = progressService.CountCompletedGames(student.id_user, out int totalTopics);
                string completedTopics = $"{completedCount}/{totalTopics}";

                // notstarted: ninguno | inprogress: al menos uno | completed: todos
                string status;
                if (completedCount <= 0)
                    status = "No Iniciado";
                else if (totalTopics > 0 && completedCount >= totalTopics)
                    status = "Completado";
                else
                    status = "En Progreso";

                // Dentro de GetStudentsForCards():
studentsCardsList.Add(new StudentCardData(student, studentName, degreeName, completedTopics, status));
            }
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"StudentService: Error al consultar estudiantes en la BD: {ex.Message}");
        }

        return studentsCardsList;
    }
}