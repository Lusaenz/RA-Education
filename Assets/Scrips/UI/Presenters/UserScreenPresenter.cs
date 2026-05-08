using System;
using UnityEngine;

/// <summary>
/// Presenter para la pantalla de perfil del usuario.
/// Formatea datos del usuario para presentación en UI.
/// Sigue arquitectura MVP.
/// </summary>
public class UserScreenPresenter
{
    private readonly DegreeService degreeService;

    /// <summary>
    /// Información formateada del último login.
    /// </summary>
    public class LastLoginInfo
    {
        public string DayOnly { get; set; }          // "14"
        public string MonthAndYear { get; set; }     // "Abril 2026"
    }

    public UserScreenPresenter(DegreeService degreeService = null)
    {
        this.degreeService = degreeService;
    }

    /// <summary>
    /// Obtiene el nombre del grado/carrera desde la BD.
    /// </summary>
    public string GetDegreeName(int degreeId)
    {
        if (degreeService == null)
        {
            Debug.LogWarning("[UserScreenPresenter] DegreeService no está disponible");
            return $"Grado: {degreeId}";
        }

        try
        {
            var degree = degreeService.GetDegreeById(degreeId);
            if (degree == null)
            {
                Debug.LogWarning($"[UserScreenPresenter] Grado no encontrado: {degreeId}");
                return $"Grado: {degreeId}";
            }

            return degree.name;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UserScreenPresenter] Error al obtener nombre de grado: {ex.Message}");
            return $"Grado ID: {degreeId}";
        }
    }

    /// <summary>
    /// Obtiene el nombre del rol en formato legible.
    /// </summary>
    public string GetRoleName(int roleId)
    {
        return roleId switch
        {
            1 => "Estudiante",
            2 => "Profesor",
            _ => "Usuario"
        };
    }

    /// <summary>
    /// Formatea la información de último login.
    /// Convierte formato "dd/MM/yyyy" a día y "Mes Año".
    /// </summary>
    public LastLoginInfo FormatLastLogin(string lastLoginDate)
    {
        var info = new LastLoginInfo();

        if (string.IsNullOrEmpty(lastLoginDate))
        {
            info.DayOnly = "—";
            info.MonthAndYear = "Sin registros";
            return info;
        }

        try
        {
            // Esperado: "dd/MM/yyyy" ej: "14/04/2026"
            string[] parts = lastLoginDate.Split('/');

            if (parts.Length != 3)
            {
                Debug.LogWarning($"[UserScreenPresenter] Formato de fecha inesperado: {lastLoginDate}");
                info.DayOnly = "—";
                info.MonthAndYear = "Fecha inválida";
                return info;
            }

            // Extraer componentes
            string dayStr = parts[0];              // "14"
            string monthStr = parts[1];            // "04"
            string yearStr = parts[2];             // "2026"

            // El día tal cual
            info.DayOnly = dayStr;

            // Convertir mes a nombre en español
            int monthNum = int.Parse(monthStr);
            string monthName = GetMonthNameInSpanish(monthNum);

            // Formato: "Abril 2026"
            info.MonthAndYear = $"{monthName} {yearStr}";

            return info;
        }
        catch (Exception ex)
        {
            Debug.LogError($"[UserScreenPresenter] Error al formatear fecha '{lastLoginDate}': {ex.Message}");
            info.DayOnly = "—";
            info.MonthAndYear = "Error al procesar";
            return info;
        }
    }

    /// <summary>
    /// Convierte número de mes a nombre en español.
    /// </summary>
    private string GetMonthNameInSpanish(int month)
    {
        return month switch
        {
            1 => "Enero",
            2 => "Febrero",
            3 => "Marzo",
            4 => "Abril",
            5 => "Mayo",
            6 => "Junio",
            7 => "Julio",
            8 => "Agosto",
            9 => "Septiembre",
            10 => "Octubre",
            11 => "Noviembre",
            12 => "Diciembre",
            _ => "Mes inválido"
        };
    }
}
