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

    public RegisterResult()
    {
        FieldErrors = new Dictionary<string, string>();
    }

    public static RegisterResult SuccessResult() => new RegisterResult { Success = true, ErrorMessage = string.Empty };
    public static RegisterResult ErrorResult(string message) => new RegisterResult { Success = false, ErrorMessage = message };
}

/// <summary>
/// Presenter de registro para estudiantes y profesores.
/// Espera la disponibilidad de la base y aplica validaciones antes de delegar al servicio.
/// </summary>
public class RegisterPresenter : MonoBehaviour
{
    private AuthService authService;
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

        initialized = true;
    }

    /// <summary>
    /// Valida y registra un estudiante.
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
            result.FieldErrors["name"] = "Nombre invalído";
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

        try
        {
            bool ok = authService.RegisterStudent(name, degreeId, age, pass);
            if (ok)
            {
                return RegisterResult.SuccessResult();
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
    }

    /// <summary>
    /// Valida y registra un profesor.
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
    email = email?.Trim().ToLowerInvariant() ?? string.Empty;  // ✅ normalizar email

    var result = new RegisterResult
    {
        FieldErrors = new Dictionary<string, string>()         // ✅ inicializar diccionario
    };

    // Nombre
    if (string.IsNullOrEmpty(name))
        result.FieldErrors["name"] = "Escribe tu nombre completo";
    else if (!Regex.IsMatch(name, patronName))                 // ✅ validar formato
        result.FieldErrors["name"] = "El nombre solo puede contener letras y espacios";

    // Email
    if (string.IsNullOrEmpty(email))
        result.FieldErrors["email"] = "El email es obligatorio.";
    else if (!Regex.IsMatch(email, patronEmail))               // ✅ regex más estricto
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
        bool ok = authService.RegisterTeacher(name, degreeId, pass, email); // ✅ verificar orden
        return ok
            ? RegisterResult.SuccessResult()
            : RegisterResult.ErrorResult("Error al registrar el usuario. Intente nuevamente.");
    }
    catch (SQLiteException ex) when (ex.Result == SQLite3.Result.Busy)
    {
        Debug.LogWarning("SQLite Busy durante registro.");
        return RegisterResult.ErrorResult("Base de datos ocupada. Intenta nuevamente en unos segundos.");
    }
}
}
