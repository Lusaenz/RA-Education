using System.Collections.Generic;

/// <summary>
/// Servicio de dominio ligero para consultar grados/carreras desde la capa de datos.
/// Centraliza el acceso al repositorio para evitar que la UI dependa directamente de SQLite.
/// </summary>
public class DegreeService
{
    private DegreeRepository degreeRepository;

    /// <summary>
    /// Crea el servicio utilizando el repositorio asociado al DatabaseManager actual.
    /// </summary>
    public DegreeService()
    {
        try
        {
            degreeRepository = new DegreeRepository();
        }
        catch (System.InvalidOperationException ex)
        {
            UnityEngine.Debug.LogError($"Error inicializando DegreeService: {ex.Message}");
        }
    }

    /// <summary>
    /// Obtiene un grado por identificador.
    /// </summary>
    public DegreeModel GetDegreeById(int degreeId)
    {
        if (degreeRepository == null)
        {
            UnityEngine.Debug.LogError("DegreeRepository no está inicializado.");
            return null;
        }

        return degreeRepository.GetDegreeById(degreeId);
    }

    /// <summary>
    /// Obtiene todos los grados disponibles.
    /// </summary>
    public List<DegreeModel> GetAllDegrees()
    {
        if (degreeRepository == null)
        {
            UnityEngine.Debug.LogError("DegreeRepository no está inicializado.");
            return new List<DegreeModel>();
        }

        return degreeRepository.GetAllDegrees();
    }
}
