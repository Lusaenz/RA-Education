using System;
using UnityEngine;

/// <summary>
/// Presenter para la pantalla de perfil del usuario.
/// SOLO formatea datos para presentación en UI, sin obtener datos de servicios.
/// Sigue arquitectura MVP correcta: solo contiene lógica de formateo.
/// </summary>
public class UserScreenPresenter
{
    public class LastLoginInfo
    {
        public string DayOnly { get; set; }
        public string MonthAndYear { get; set; }
    }

    public UserScreenPresenter()
    {
    }

    /// <summary>
    /// Formatea el nombre del rol recibido como parámetro.
    /// </summary>
    public string FormatRoleName(string roleName)
    {
        return string.IsNullOrEmpty(roleName) ? "Usuario" : roleName;
    }

    /// <summary>
    /// Formatea el nombre del grado/carrera recibido como parámetro.
    /// </summary>
    public string FormatDegreeName(string degreeName)
    {
        return string.IsNullOrEmpty(degreeName) ? "Grado desconocido" : degreeName;
    }

    /// <summary>
    /// Formatea el total de estrellas como string.
    /// </summary>
    public string FormatTotalStars(int stars)
    {
        return stars.ToString();
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
            string[] parts = lastLoginDate.Split('/');

            if (parts.Length != 3)
            {
                Debug.LogWarning($"[UserScreenPresenter] Formato de fecha inesperado: {lastLoginDate}");
                info.DayOnly = "—";
                info.MonthAndYear = "Fecha inválida";
                return info;
            }

            string dayStr = parts[0];
            string monthStr = parts[1];
            string yearStr = parts[2];

            info.DayOnly = dayStr;

            int monthNum = int.Parse(monthStr);
            string monthName = GetMonthNameInSpanish(monthNum);

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
