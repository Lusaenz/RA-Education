using UnityEngine;
using SQLite4Unity3d;
using System.Collections.Generic;

/// <summary>
/// Presenter de registro para estudiantes y profesores.
/// Espera la disponibilidad de la base y aplica validaciones antes de delegar al servicio.
/// Integra la lógica de preguntas de seguridad y último login.
/// </summary>
public class RegisterPresenter : MonoBehaviour
{
    private AuthService authService;
    private DegreeSelector degreeSelector;
    private bool initialized = false;

    /// <summary>
    /// Inicializa el servicio cuando SQLite ya se encuentra disponible.
    /// </summary>
    void Start()
    {
        StartCoroutine(InitializeWhenDatabaseReady());
    }

    /// <summary>
    /// Construye dependencias de registro una vez la base queda operativa.
    /// </summary>
    System.Collections.IEnumerator InitializeWhenDatabaseReady()
    {
        yield return new WaitUntil(() => DatabaseManager.Instance != null);
        yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);

        var conn = DatabaseManager.Instance.GetConnection();
        var repo = new UserRepository(conn);
        authService = new AuthService(repo);

        // Obtener referencia al DegreeSelector para acceder a preguntas de seguridad
        degreeSelector = FindFirstObjectByType<DegreeSelector>();
        if (degreeSelector == null)
        {
            Debug.LogWarning("RegisterPresenter: DegreeSelector no encontrado en la escena.");
        }

        initialized = true;
    }

    /// <summary>
    /// Valida y registra un estudiante.
    /// Retorna el UserId si el registro fue exitoso.
    /// </summary>
    public RegisterResult RegisterStudent(int degreeId, string name, string ageText, string pass)
    {
        if (!initialized)
        {
            Debug.LogWarning("Register attempted before DB ready.");
            return RegisterResult.ErrorResult("Error interno: base de datos no disponible.");
        }

        var fieldErrors = RegisterValidator.ValidateStudent(name, degreeId, ageText, pass);
        if (fieldErrors.Count > 0)
        {
            return new RegisterResult
            {
                Success      = false,
                FieldErrors  = fieldErrors,
                ErrorMessage = string.Join(" ", fieldErrors.Values)
            };
        }

        name = name?.Trim() ?? string.Empty;
        int.TryParse(ageText, out int age);

        Debug.Log($"[RegisterStudent] Intentando registrar - Name: {name}, DegreeId: {degreeId}, Age: {age}");

        try
        {
            UserModel registeredUser = authService.RegisterStudent(name, degreeId, age, pass);
            if (registeredUser != null && registeredUser.id_user > 0)
            {
                Debug.Log($"RegisterPresenter: Estudiante registrado exitosamente - ID: {registeredUser.id_user}");
                return RegisterResult.SuccessResult(registeredUser.id_user);
            }
            else
            {
                return RegisterResult.ErrorResult("Error al registrar el usuario. Intente nuevamente.");
            }
        }
        catch (SQLiteException ex) when (ex.Result == SQLite3.Result.Busy)
        {
            Debug.LogWarning("SQLite Busy durante registro. Intente nuevamente.");
            return RegisterResult.ErrorResult("Base de datos ocupada. Intenta nuevamente en unos segundos.");
        }
        catch (SQLiteException ex) when (ex.Result == SQLite3.Result.Constraint)
        {
            Debug.LogError($"SQLite Constraint Error: {ex.Message}");
            Debug.LogError($"Esto puede indicar: 1) El grado (ID: {degreeId}) no existe en la tabla degrees, 2) Restricción UNIQUE violada, 3) Campo NOT NULL sin valor");
            return RegisterResult.ErrorResult("Error: Datos inválidos o duplicados. Verifica que el grado sea válido y que el nombre sea único.");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"Error general durante registro: {ex.Message}");
            return RegisterResult.ErrorResult($"Error al registrar: {ex.Message}");
        }
    }

    /// <summary>
    /// Valida y registra un profesor.
    /// Retorna el UserId si el registro fue exitoso.
    /// </summary>
    public RegisterResult RegisterTeacher(int degreeId, string name, string email, string pass)
    {
        if (!initialized)
        {
            Debug.LogWarning("Register attempted before DB ready.");
            return RegisterResult.ErrorResult("Error interno: base de datos no disponible.");
        }

        var fieldErrors = RegisterValidator.ValidateTeacher(name, degreeId, email, pass);
        if (fieldErrors.Count > 0)
        {
            return new RegisterResult
            {
                Success      = false,
                FieldErrors  = fieldErrors,
                ErrorMessage = string.Join(" ", fieldErrors.Values)
            };
        }

        name  = name?.Trim() ?? string.Empty;
        email = email?.Trim().ToLowerInvariant() ?? string.Empty;

        try
        {
            UserModel registeredUser = authService.RegisterTeacher(name, degreeId, pass, email);
            if (registeredUser != null && registeredUser.id_user > 0)
            {
                Debug.Log($"RegisterPresenter: Profesor registrado exitosamente - ID: {registeredUser.id_user}");
                return RegisterResult.SuccessResult(registeredUser.id_user);
            }
            else
            {
                return RegisterResult.ErrorResult("Error al registrar el usuario. Intente nuevamente.");
            }
        }
        catch (SQLiteException ex) when (ex.Result == SQLite3.Result.Busy)
        {
            Debug.LogWarning("SQLite Busy durante registro.");
            return RegisterResult.ErrorResult("Base de datos ocupada. Intenta nuevamente en unos segundos.");
        }
        catch (SQLiteException ex) when (ex.Result == SQLite3.Result.Constraint)
        {
            Debug.LogError($"SQLite Constraint Error: {ex.Message}");
            return RegisterResult.ErrorResult("Error: Datos inválidos o duplicados. Verifica que el grado sea válido y que el email sea único.");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"Error general durante registro: {ex.Message}");
            return RegisterResult.ErrorResult($"Error al registrar: {ex.Message}");
        }
    }

    /// <summary>
    /// Valida y guarda la pregunta de seguridad y su respuesta cifrada.
    /// </summary>
    public RegisterResult ValidateAndSaveSecurityQuestion(int userId, int questionId, string answer)
    {
        if (!initialized)
        {
            Debug.LogWarning("ValidateAndSaveSecurityQuestion attempted before DB ready.");
            return RegisterResult.ErrorResult("Error interno: base de datos no disponible.");
        }

        var fieldErrors = RegisterValidator.ValidateSecurityQuestion(questionId, answer);
        if (fieldErrors.Count > 0)
        {
            return new RegisterResult
            {
                Success      = false,
                FieldErrors  = fieldErrors,
                ErrorMessage = string.Join(" ", fieldErrors.Values)
            };
        }

        answer = answer?.Trim() ?? string.Empty;

        try
        {
            authService.SaveSecurityQuestion(userId, questionId, answer);
            Debug.Log($"RegisterPresenter: Pregunta de seguridad guardada para usuario {userId}");
            return RegisterResult.SuccessResult();
        }
        catch (SQLiteException ex) when (ex.Result == SQLite3.Result.Busy)
        {
            Debug.LogWarning("SQLite Busy al guardar pregunta de seguridad.");
            return RegisterResult.ErrorResult("Base de datos ocupada. Intenta nuevamente en unos segundos.");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"Error al guardar pregunta de seguridad: {ex.Message}");
            return RegisterResult.ErrorResult($"Error al guardar pregunta de seguridad: {ex.Message}");
        }
    }

    /// <summary>
    /// Actualiza el último login del usuario registrado.
    /// Debe llamarse después de completar el registro exitosamente.
    /// </summary>
    public void UpdateLastLoginForUser(int userId)
    {
        if (!initialized)
        {
            Debug.LogWarning("UpdateLastLoginForUser attempted before DB ready.");
            return;
        }

        try
        {
            authService.UpdateLastLogin(userId);
            Debug.Log($"RegisterPresenter: último login actualizado para usuario {userId} a {System.DateTime.Now:yyyy-MM-dd HH:mm:ss}");
        }
        catch (System.Exception ex)
        {
            Debug.LogError($"Error al actualizar último login: {ex.Message}");
        }
    }

    /// <summary>
    /// Obtiene el DegreeSelector para acceder a las selecciones del usuario.
    /// </summary>
    public DegreeSelector GetDegreeSelector()
    {
        return degreeSelector;
    }
}

