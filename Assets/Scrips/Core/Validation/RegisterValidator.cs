using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

/// <summary>
/// Lógica de validación de registro separada de MonoBehaviour para poder testearse de forma aislada.
/// </summary>
///

public static class RegisterValidator
{
    public const string PatronName  = @"^[A-Za-zÁÉÍÓÚáéíóúñÑ]+(\s[A-Za-zÁÉÍÓÚáéíóúñÑ]+)+$";
    public const string PatronEmail = @"^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$";

    public static Dictionary<string, string> ValidateStudent(string name, int degreeId, string ageText, string pass)
    {
        var errors = new Dictionary<string, string>();

        name = name?.Trim() ?? string.Empty;
        pass = pass?.Trim() ?? string.Empty;

        if (string.IsNullOrEmpty(name))
            errors["name"] = "El nombre es obligatorio.";
        else if (!Regex.IsMatch(name, PatronName))
            errors["name"] = "Nombre inválido";

        if (degreeId <= 0)
            errors["degree"] = "El grado es obligatorio.";

        if (string.IsNullOrWhiteSpace(pass))
            errors["password"] = "La contraseña es obligatoria.";
        else if (pass.Length < 6)
            errors["password"] = "La contraseña debe tener al menos 6 caracteres.";

        if (!int.TryParse(ageText, out int age))
            errors["age"] = "Edad inválida.";
        else if (age < 10 || age > 15)
            errors["age"] = "La edad debe estar entre 10 y 15 años.";

        return errors;
    }

    public static Dictionary<string, string> ValidateTeacher(string name, int degreeId, string email, string pass)
    {
        var errors = new Dictionary<string, string>();

        name  = name?.Trim()  ?? string.Empty;
        pass  = pass?.Trim()  ?? string.Empty;
        email = email?.Trim().ToLowerInvariant() ?? string.Empty;

        if (string.IsNullOrEmpty(name))
            errors["name"] = "Escribe tu nombre completo";
        else if (!Regex.IsMatch(name, PatronName))
            errors["name"] = "El nombre solo puede contener letras y espacios";

        if (string.IsNullOrEmpty(email))
            errors["email"] = "El email es obligatorio.";
        else if (!Regex.IsMatch(email, PatronEmail))
            errors["email"] = "Escribe un correo válido";

        if (degreeId <= 0)
            errors["degree"] = "Campo obligatorio";

        if (string.IsNullOrWhiteSpace(pass))
            errors["password"] = "La contraseña es obligatoria.";
        else if (pass.Length < 6)
            errors["password"] = "La contraseña debe tener al menos 6 caracteres.";

        return errors;
    }

    public static Dictionary<string, string> ValidateSecurityQuestion(int questionId, string answer)
    {
        var errors = new Dictionary<string, string>();

        if (questionId <= 0)
        {
            errors["security"] = "Debe seleccionar una pregunta de seguridad.";
            return errors;
        }

        answer = answer?.Trim() ?? string.Empty;

        if (string.IsNullOrEmpty(answer))
        {
            errors["answer"] = "Debe ingresar la respuesta de seguridad.";
            return errors;
        }

        if (answer.Length < 2)
            errors["answer"] = "La respuesta debe tener al menos 2 caracteres.";

        return errors;
    }
}
