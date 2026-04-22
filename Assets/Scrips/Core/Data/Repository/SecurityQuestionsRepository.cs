using SQLite4Unity3d;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

/// <summary>
/// Repositorio para consultar preguntas de seguridad desde la tabla security_questions.
/// </summary>
public class SecurityQuestionsRepository
{
    private SQLiteConnection ConnectionDb;

    /// <summary>
    /// Crea el repositorio con una conexión explícita.
    /// </summary>
    public SecurityQuestionsRepository(SQLiteConnection connection)
    {
        if (connection == null)
        {
            Debug.LogError("SecurityQuestionsRepository: la conexión proporcionada es null.");
            throw new System.ArgumentNullException(nameof(connection), "Se requiere una conexión válida para crear SecurityQuestionsRepository.");
        }

        ConnectionDb = connection;
    }

    /// <summary>
    /// Constructor legacy que intenta resolver la conexión desde DatabaseManager.
    /// </summary>
    public SecurityQuestionsRepository()
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("DatabaseManager.Instance es null al crear SecurityQuestionsRepository.");
            throw new System.InvalidOperationException("DatabaseManager.Instance es null.");
        }

        ConnectionDb = DatabaseManager.Instance.GetConnection();

        if (ConnectionDb == null)
        {
            Debug.LogError("ConnectionDb es null en SecurityQuestionsRepository.");
            throw new System.InvalidOperationException("ConnectionDb es null.");
        }
    }

    /// <summary>
    /// Obtiene una pregunta de seguridad por su identificador.
    /// </summary>
    public SecurityQuestionsModel GetQuestionById(int questionId)
    {
        return ConnectionDb.Table<SecurityQuestionsModel>()
            .FirstOrDefault(x => x.id_question == questionId);
    }

    /// <summary>
    /// Obtiene todas las preguntas de seguridad disponibles.
    /// </summary>
    public List<SecurityQuestionsModel> GetAllQuestions()
    {
        return ConnectionDb.Table<SecurityQuestionsModel>().ToList();
    }
}
