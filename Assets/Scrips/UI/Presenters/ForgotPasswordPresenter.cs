using System;
using System.Collections.Generic;
using UnityEngine;

/// <summary>
/// Presenter para la funcionalidad de recuperación de contraseña.
/// Valida entradas, recupera información de usuario y orquesta el cambio de contraseña.
/// Sigue arquitectura MVP.
/// </summary>
public class ForgotPasswordPresenter
{
    private readonly AuthService authService;
    private readonly SecurityQuestionsService securityQuestionsService;

    /// <summary>
    /// Resultado del intento de búsqueda de usuario.
    /// </summary>
    public class UserLookupResult
    {
        public bool Success { get; set; }
        public UserModel User { get; set; }
        public string ErrorMessage { get; set; }
    }

    /// <summary>
    /// Resultado del cambio de contraseña.
    /// </summary>
    public class PasswordResetResult
    {
        public bool Success { get; set; }
        public string ErrorMessage { get; set; }
        public Dictionary<string, string> FieldErrors { get; set; }

        public PasswordResetResult()
        {
            FieldErrors = new Dictionary<string, string>();
        }
    }

    /// <summary>
    /// Información sobre la pregunta de seguridad del usuario.
    /// </summary>
    public class SecurityQuestionInfo
    {
        public int QuestionId { get; set; }
        public string Question { get; set; }
    }

    public ForgotPasswordPresenter(AuthService auth, SecurityQuestionsService securityQuestions)
    {
        authService = auth ?? throw new ArgumentNullException(nameof(auth));
        securityQuestionsService = securityQuestions ?? throw new ArgumentNullException(nameof(securityQuestions));
    }

    /// <summary>
    /// Busca un usuario estudiante por nombre.
    /// </summary>
    public UserLookupResult FindStudentByName(string name)
    {
        var result = new UserLookupResult();

        if (string.IsNullOrWhiteSpace(name))
        {
            result.ErrorMessage = "Por favor ingresa tu nombre completo.";
            return result;
        }

        try
        {
            UserModel user = authService.FindUserByNameAndRole(name, 1);

            if (user == null)
            {
                result.ErrorMessage = "No encontramos un estudiante con ese nombre. Verifica e intenta nuevamente.";
                return result;
            }

            // Validar que el usuario tenga pregunta de seguridad configurada
            if (user.id_security_question <= 0 || string.IsNullOrEmpty(user.security_answer_hash))
            {
                result.ErrorMessage = "Tu cuenta no tiene una pregunta de seguridad configurada. Contacta soporte.";
                return result;
            }

            result.Success = true;
            result.User = user;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[ForgotPasswordPresenter] Error al buscar usuario: {ex.Message}");
            result.ErrorMessage = "Error al buscar tu cuenta. Intenta más tarde.";
        }

        return result;
    }

    /// <summary>
    /// Obtiene la pregunta de seguridad del usuario.
    /// </summary>
    public SecurityQuestionInfo GetSecurityQuestion(int questionId)
    {
        try
        {
            var question = securityQuestionsService.GetQuestionById(questionId);
            if (question == null)
            {
                Debug.LogWarning($"[ForgotPasswordPresenter] Pregunta de seguridad no encontrada: {questionId}");
                return null;
            }

            return new SecurityQuestionInfo
            {
                QuestionId = question.id_question,
                Question = question.question
            };
        }
        catch (Exception ex)
        {
            Debug.LogError($"[ForgotPasswordPresenter] Error al obtener pregunta de seguridad: {ex.Message}");
            return null;
        }
    }

    /// <summary>
    /// Valida y procesa el cambio de contraseña.
    /// Verifica la respuesta de seguridad antes de permitir el cambio.
    /// </summary>
    public PasswordResetResult ResetPassword(int userId, string securityAnswer, string newPassword)
    {
        var result = new PasswordResetResult();

        // Validar campos no vacío
        if (string.IsNullOrWhiteSpace(securityAnswer))
        {
            result.FieldErrors["answer"] = "Por favor ingresa tu respuesta de seguridad.";
        }

        if (string.IsNullOrWhiteSpace(newPassword))
        {
            result.FieldErrors["password"] = "Por favor ingresa una nueva contraseña.";
        }

        if (result.FieldErrors.Count > 0)
        {
            return result;
        }

        // Validar longitud de contraseña
        if (newPassword.Length < 6)
        {
            result.FieldErrors["password"] = "La contraseña debe tener al menos 6 caracteres.";
            return result;
        }

        if (newPassword.Length > 50)
        {
            result.FieldErrors["password"] = "La contraseña no puede exceder 50 caracteres.";
            return result;
        }

        try
        {
            // Verificar respuesta de seguridad
            if (!authService.VerifySecurityAnswer(userId, securityAnswer))
            {
                result.FieldErrors["answer"] = "Tu respuesta de seguridad es incorrecta. Intenta nuevamente.";
                Debug.Log($"[ForgotPasswordPresenter] Respuesta de seguridad incorrecta para usuario {userId}");
                return result;
            }

            // Cambiar contraseña
            authService.ChangePasswordAfterSecurityVerification(userId, newPassword);

            result.Success = true;
            Debug.Log($"[ForgotPasswordPresenter] Contraseña cambiada exitosamente para usuario {userId}");
        }
        catch (Exception ex)
        {
            Debug.LogError($"[ForgotPasswordPresenter] Error al cambiar contraseña: {ex.Message}\nStackTrace: {ex.StackTrace}");
            result.ErrorMessage = "Ocurrió un error al cambiar tu contraseña. Intenta más tarde.";
        }

        return result;
    }
}
