using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Servicio de dominio para consultar y gestionar preguntas de seguridad.
/// Centraliza el acceso al repositorio de preguntas de seguridad.
/// </summary>
public class SecurityQuestionsService
{
    private SecurityQuestionsRepository securityQuestionsRepository;

    /// <summary>
    /// Crea el servicio con una conexión explícita.
    /// </summary>
    public SecurityQuestionsService(SecurityQuestionsRepository repository)
    {
        securityQuestionsRepository = repository ?? throw new ArgumentNullException(nameof(repository));
    }

    /// <summary>
    /// Crea el servicio utilizando el repositorio asociado al DatabaseManager actual.
    /// Constructor legacy para compatibilidad.
    /// </summary>
    public SecurityQuestionsService()
    {
        try
        {
            securityQuestionsRepository = new SecurityQuestionsRepository();
        }
        catch (InvalidOperationException ex)
        {
            Debug.LogError($"Error inicializando SecurityQuestionsService: {ex.Message}");
        }
    }

    /// <summary>
    /// Obtiene una pregunta de seguridad por su identificador.
    /// </summary>
    public SecurityQuestionsModel GetQuestionById(int questionId)
    {
        if (securityQuestionsRepository == null)
        {
            Debug.LogError("SecurityQuestionsRepository no está inicializado.");
            return null;
        }

        return securityQuestionsRepository.GetQuestionById(questionId);
    }

    /// <summary>
    /// Obtiene todas las preguntas de seguridad disponibles.
    /// </summary>
    public List<SecurityQuestionsModel> GetAllQuestions()
    {
        if (securityQuestionsRepository == null)
        {
            Debug.LogError("SecurityQuestionsRepository no está inicializado.");
            return new List<SecurityQuestionsModel>();
        }

        return securityQuestionsRepository.GetAllQuestions();
    }
}
