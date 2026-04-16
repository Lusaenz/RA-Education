using UnityEngine;
using SQLite4Unity3d;
using System.Text.RegularExpressions;
using System;
using System.Collections.Generic;

/// <summary>
/// Resultado del proceso de registro con errores por campo para que la vista
/// pueda mostrar mensajes precisos.
/// </summary>
public class RegisterResult
{
    public bool Success { get; set; }
    public string ErrorMessage { get; set; }
    public Dictionary<string, string> FieldErrors { get; set; }
    public int UserId { get; set; } // ID del usuario registrado (si el registro fue exitoso)

    public RegisterResult()
    {
        FieldErrors = new Dictionary<string, string>();
        UserId = -1;
    }

    public static RegisterResult SuccessResult(int userId = -1) 
    { 
        return new RegisterResult 
        { 
            Success = true, 
            ErrorMessage = string.Empty,
            UserId = userId
        };
    }
    
    public static RegisterResult ErrorResult(string message) 
    { 
        return new RegisterResult 
        { 
            Success = false, 
            ErrorMessage = message 
        };
    }
}

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
        string patronName = @"^[A-Za-zÁÉÍÓÚáéíóúñÑ]+(\s[A-Za-zÁÉÍÓÚáéíóúñÑ]+)+$";
        if (!initialized)
        {
            Debug.LogWarning("Register attempted before DB ready.");
            return RegisterResult.ErrorResult("Error interno: base de datos no disponible.");
        }

        // Validaciones
        var result = new RegisterResult();
        name = name?.Trim() ?? string.Empty;
        pass = pass?.Trim() ?? string.Empty;

        if (string.IsNullOrEmpty(name))
        {
            result.FieldErrors["name"] = "El nombre es obligatorio.";
        }
        else if (!Regex.IsMatch(name, patronName))
        {
            result.FieldErrors["name"] = "Nombre inválido";
        }
        
        if (degreeId <= 0)
        {
            result.FieldErrors["degree"] = "El grado es obligatorio.";
        }
        
        if (string.IsNullOrWhiteSpace(pass))
        {
            result.FieldErrors["password"] = "La contraseña es obligatoria.";
        }
        else if (pass.Length < 6)
        {
            result.FieldErrors["password"] = "La contraseña debe tener al menos 6 caracteres.";
        }
        
        if (!int.TryParse(ageText, out int age))
        {
            result.FieldErrors["age"] = "Edad inválida.";
        }

        // Si hay errores, retornar con el mensaje completo
        if (result.FieldErrors.Count > 0)
        {
            result.Success = false;
            result.ErrorMessage = string.Join(" ", result.FieldErrors.Values);
            return result;
        }

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
        string patronName  = @"^[A-Za-zÁÉÍÓÚáéíóúñÑ]+(\s[A-Za-zÁÉÍÓÚáéíóúñÑ]+)+$";
        string patronEmail = @"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$";

        if (!initialized)
        {
            Debug.LogWarning("Register attempted before DB ready.");
            return RegisterResult.ErrorResult("Error interno: base de datos no disponible.");
        }

        name  = name?.Trim() ?? string.Empty;
        pass  = pass?.Trim() ?? string.Empty;
        email = email?.Trim().ToLowerInvariant() ?? string.Empty;

        var result = new RegisterResult
        {
            FieldErrors = new Dictionary<string, string>()
        };

        // Nombre
        if (string.IsNullOrEmpty(name))
            result.FieldErrors["name"] = "Escribe tu nombre completo";
        else if (!Regex.IsMatch(name, patronName))
            result.FieldErrors["name"] = "El nombre solo puede contener letras y espacios";

        // Email
        if (string.IsNullOrEmpty(email))
            result.FieldErrors["email"] = "El email es obligatorio.";
        else if (!Regex.IsMatch(email, patronEmail))
            result.FieldErrors["email"] = "Escribe un correo válido";

        // Grado
        if (degreeId <= 0)
            result.FieldErrors["degree"] = "Campo obligatorio";

        // Contraseña
        if (string.IsNullOrWhiteSpace(pass))
            result.FieldErrors["password"] = "La contraseña es obligatoria.";
        else if (pass.Length < 6)
            result.FieldErrors["password"] = "La contraseña debe tener al menos 6 caracteres.";

        if (result.FieldErrors.Count > 0)
        {
            result.Success = false;
            result.ErrorMessage = string.Join(" ", result.FieldErrors.Values);
            return result;
        }

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

        var result = new RegisterResult();

        // Validar ID de pregunta
        if (questionId <= 0)
        {
            result.FieldErrors["security"] = "Debe seleccionar una pregunta de seguridad.";
            result.Success = false;
            result.ErrorMessage = "Pregunta de seguridad no seleccionada.";
            return result;
        }

        // Validar respuesta
        answer = answer?.Trim() ?? string.Empty;
        if (string.IsNullOrEmpty(answer))
        {
            result.FieldErrors["answer"] = "Debe ingresar la respuesta de seguridad.";
            result.Success = false;
            result.ErrorMessage = "Respuesta de seguridad vacía.";
            return result;
        }

        if (answer.Length < 2)
        {
            result.FieldErrors["answer"] = "La respuesta debe tener al menos 2 caracteres.";
            result.Success = false;
            result.ErrorMessage = "Respuesta muy corta.";
            return result;
        }

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

