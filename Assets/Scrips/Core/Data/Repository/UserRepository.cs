using SQLite4Unity3d;
using System;
using System.Linq;
using System.Threading;
using UnityEngine;

/// <summary>
/// Repositorio encargado de persistir y consultar usuarios, estudiantes y profesores.
/// Incluye una politica minima de reintentos para escrituras cuando SQLite informa bloqueo.
/// </summary>
public class UserRepository
{
    private static readonly object DbWriteLock = new object();
    private const int MaxBusyRetries = 5;
    private const int BusyRetryDelayMs = 80;

    SQLiteConnection ConnectionDb;

    /// <summary>
    /// Crea el repositorio con una conexion explicita.
    /// </summary>
    public UserRepository(SQLiteConnection connection)
    {
        if (connection == null)
        {
            Debug.LogError("UserRepository: la conexión proporcionada es null.");
            throw new System.ArgumentNullException(nameof(connection), "Se requiere una conexión válida para crear UserRepository.");
        }

        ConnectionDb = connection;
    }

    // Mantener un constructor por compatibilidad mínima, pero marcarlo para evitar usos accidentales.
    /// <summary>
    /// Constructor legacy que resuelve la conexion desde DatabaseManager.
    /// </summary>
    public UserRepository()
    {
        if (DatabaseManager.Instance == null)
        {
            Debug.LogError("DatabaseManager.Instance es null al crear UserRepository. Asegúrate de tener un GameObject con DatabaseManager en la escena y que su Awake() haya corrido.");
            throw new System.InvalidOperationException("DatabaseManager.Instance es null. Use el constructor que recibe una conexión.");
        }

        ConnectionDb = DatabaseManager.Instance.GetConnection();

        if (ConnectionDb == null)
        {
            Debug.LogError("ConnectionDb es null en UserRepository. Verifica la inicialización de la base de datos y flags de apertura.");
            throw new System.InvalidOperationException("ConnectionDb es null.");
        }
    }

    /// <summary>
    /// Inserta un registro base en la tabla de usuarios.
    /// </summary>
    public void InsertUser(UserModel users)
    {
        ExecuteWriteWithRetry(() => ConnectionDb.Insert(users));
    }

    /// <summary>
    /// Inserta el detalle especifico del estudiante.
    /// </summary>
    public void InserStudent(StudentModel student)
    {
        ExecuteWriteWithRetry(() => ConnectionDb.Insert(student));
    }

    /// <summary>
    /// Inserta el detalle especifico del profesor.
    /// </summary>
    public void InsertTeacher(TeacherModel teacher)
    {
        ExecuteWriteWithRetry(() => ConnectionDb.Insert(teacher));
    }

    /// <summary>
    /// Busca un estudiante por nombre filtrando por rol.
    /// </summary>
    public UserModel LoginStudent(string name)
    {
        if (string.IsNullOrEmpty(name))
        {
            Debug.LogWarning("LoginStudent: Nombre no puede estar vacío.");
            return null;
        }

        return ConnectionDb.Table<UserModel>()
            .FirstOrDefault(x => string.Equals(x.name, name, System.StringComparison.OrdinalIgnoreCase)
                              && x.id_role == 1);
    }

    /// <summary>
    /// Busca un profesor mediante el correo almacenado en la tabla teachers.
    /// </summary>
    public UserModel LoginTeacher(string email)
    {
        var result = ConnectionDb.Query<UserModel>(
            @"SELECT u.* FROM users u
                JOIN teachers t ON u.id_user = t.id_user
                WHERE t.email=?",
            email);

        return result.FirstOrDefault();
    }

    /// <summary>
    /// Actualiza la contrasena persistida, usado durante la migracion a hash.
    /// </summary>
    public void UpdateUserPassword(int userId, string hashedPassword)
    {
        ExecuteWriteWithRetry(() =>
            ConnectionDb.Execute(
                @"UPDATE users
                  SET password = ?
                  WHERE id_user = ?",
                hashedPassword, userId));
    }

    /// <summary>
    /// Ejecuta escrituras serializadas para reducir conflictos concurrentes sobre SQLite.
    /// </summary>
    private void ExecuteWriteWithRetry(Action writeAction)
    {
        if (writeAction == null)
        {
            throw new ArgumentNullException(nameof(writeAction));
        }

        lock (DbWriteLock)
        {
            int attempt = 0;
            while (true)
            {
                try
                {
                    writeAction();
                    return;
                }
                catch (SQLiteException ex) when (ex.Result == SQLite3.Result.Busy && attempt < MaxBusyRetries)
                {
                    attempt++;
                    Thread.Sleep(BusyRetryDelayMs * attempt);
                }
            }
        }
    }
}
