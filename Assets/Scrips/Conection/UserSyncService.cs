using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using UnityEngine;
using SQLite4Unity3d;

public class UserSyncService : MonoBehaviour
{
    public static UserSyncService Instance { get; private set; }

    // Prefijos de los mensajes de sincronización.
    public const string MsgStudent = "CREATE_STUDENT|";
    public const string MsgProgress = "PROGRESS|";
    public const string MsgResult = "RESULT|";

    /// <summary>
    /// Se dispara (en el hilo principal) cada vez que se guardan
    /// en SQLite datos recibidos desde otro dispositivo.
    /// Las pantallas del profesor lo usan para refrescarse en tiempo real.
    /// </summary>
    public static event Action OnDataSynced;

    // Evita reenviar cambios mientras se guardan datos que llegaron por la red.
    private static bool applyingRemoteData;

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
            DontDestroyOnLoad(gameObject);
        }
        else
        {
            Destroy(gameObject);
        }
    }

    // =====================================================================
    // ENVÍO (dispositivo cliente)
    // =====================================================================

    /// <summary>
    /// Envía un estudiante al servidor conectado.
    /// </summary>
    public async Task SendStudent(UserModel user, StudentModel student)
    {
        if (user == null || student == null)
        {
            Debug.LogWarning("UserSyncService: datos de usuario incompletos.");
            return;
        }

        if (SimpleClient.Instance == null)
        {
            Debug.LogWarning("UserSyncService: SimpleClient no disponible.");
            return;
        }

        await SimpleClient.Instance.SendRawMessage(BuildStudentMessage(user, student));

        Debug.Log(
            $"UserSyncService: estudiante {user.id_user} enviado correctamente."
        );
    }

    private static bool CanSend()
    {
        return !applyingRemoteData &&
               SimpleClient.Instance != null &&
               SimpleClient.Instance.IsConnected &&
               DatabaseManager.Instance != null &&
               DatabaseManager.Instance.IsReady;
    }

    private static string BuildStudentMessage(UserModel user, StudentModel student)
    {
        UserSyncData data = new UserSyncData
        {
            id_user = user.id_user,
            name = user.name,
            id_degree = user.id_degree,
            password = user.password,
            id_role = user.id_role,
            id_security_question = user.id_security_question,
            security_asnwer_hash = user.security_asnwer_hash,
            last_login = user.last_login,
            age = student != null ? student.age : 0
        };

        return MsgStudent + JsonUtility.ToJson(data);
    }

    private static string BuildProgressMessage(string studentName, ProgressModel p)
    {
        ProgressSyncData data = new ProgressSyncData
        {
            student_name = studentName,
            id_module = p.id_module,
            punctuation = p.punctuation ?? 0,
            percentage_completed = p.percentage_completed ?? 0,
            completad_at = p.completad_at ?? 0,
            status = p.status
        };

        return MsgProgress + JsonUtility.ToJson(data);
    }

    private static string BuildResultMessage(string studentName, ResultActivityData r)
    {
        ResultSyncData data = new ResultSyncData
        {
            student_name = studentName,
            id_activity = r.id_activity,
            score = r.score,
            stars = r.stars,
            attempts = r.attempts,
            completed_at = r.completed_at
        };

        return MsgResult + JsonUtility.ToJson(data);
    }

    private static UserModel GetLocalStudent(SQLiteConnection db, int userId)
    {
        UserModel user = db.Table<UserModel>().FirstOrDefault(u => u.id_user == userId);
        return (user != null && user.id_role == 1) ? user : null;
    }

    /// <summary>
    /// Llamar cuando se crea o modifica un usuario en este dispositivo.
    /// Solo se sincronizan estudiantes.
    /// </summary>
    public static void NotifyUserChanged(int userId)
    {
        if (!CanSend() || userId <= 0)
            return;

        try
        {
            SQLiteConnection db = DatabaseManager.Instance.GetConnection();
            UserModel user = GetLocalStudent(db, userId);
            if (user == null)
                return;

            StudentModel student = db.Table<StudentModel>().FirstOrDefault(s => s.id_user == userId);
            if (student == null)
                return; // Todavía no se ha insertado la fila de students.

            _ = SimpleClient.Instance.SendRawMessage(BuildStudentMessage(user, student));
        }
        catch (Exception ex)
        {
            Debug.LogError("UserSyncService: error enviando usuario: " + ex.Message);
        }
    }

    /// <summary>
    /// Llamar cuando se inserta o actualiza una fila de progress en este dispositivo.
    /// </summary>
    public static void NotifyProgressChanged(ProgressModel progress)
    {
        if (!CanSend() || progress == null)
            return;

        try
        {
            SQLiteConnection db = DatabaseManager.Instance.GetConnection();
            UserModel user = GetLocalStudent(db, progress.id_user);
            if (user == null)
                return;

            _ = SimpleClient.Instance.SendRawMessage(BuildProgressMessage(user.name, progress));
        }
        catch (Exception ex)
        {
            Debug.LogError("UserSyncService: error enviando progreso: " + ex.Message);
        }
    }

    /// <summary>
    /// Llamar cuando se guarda un resultado de actividad en este dispositivo.
    /// </summary>
    public static void NotifyResultSaved(ResultActivityData result)
    {
        if (!CanSend() || result == null)
            return;

        try
        {
            SQLiteConnection db = DatabaseManager.Instance.GetConnection();
            UserModel user = GetLocalStudent(db, result.id_user);
            if (user == null)
                return;

            _ = SimpleClient.Instance.SendRawMessage(BuildResultMessage(user.name, result));
        }
        catch (Exception ex)
        {
            Debug.LogError("UserSyncService: error enviando resultado: " + ex.Message);
        }
    }

    /// <summary>
    /// Envía todos los estudiantes locales con su progreso y resultados.
    /// Se llama al conectar, para que el servidor reciba también los cambios
    /// hechos mientras no había conexión.
    /// </summary>
    public static async Task SendFullSync()
    {
        // Esperar (máx. ~10 s) a que la base de datos esté lista.
        for (int i = 0; i < 40 &&
             (DatabaseManager.Instance == null || !DatabaseManager.Instance.IsReady); i++)
        {
            await Task.Delay(250);
        }

        if (!CanSend())
            return;

        try
        {
            SQLiteConnection db = DatabaseManager.Instance.GetConnection();
            List<UserModel> students = db.Table<UserModel>().Where(u => u.id_role == 1).ToList();

            foreach (UserModel user in students)
            {
                int id = user.id_user;
                StudentModel student = db.Table<StudentModel>().FirstOrDefault(s => s.id_user == id);
                if (student == null)
                    continue;

                await SimpleClient.Instance.SendRawMessage(BuildStudentMessage(user, student));

                foreach (ProgressModel p in db.Table<ProgressModel>().Where(x => x.id_user == id).ToList())
                    await SimpleClient.Instance.SendRawMessage(BuildProgressMessage(user.name, p));

                foreach (ResultActivityData r in db.Table<ResultActivityData>().Where(x => x.id_user == id).ToList())
                    await SimpleClient.Instance.SendRawMessage(BuildResultMessage(user.name, r));
            }

            Debug.Log($"UserSyncService: sincronización completa enviada ({students.Count} estudiantes).");
        }
        catch (Exception ex)
        {
            Debug.LogError("UserSyncService: error en sincronización completa: " + ex.Message);
        }
    }

    // =====================================================================
    // RECEPCIÓN (dispositivo servidor / otros dispositivos)
    // =====================================================================

    /// <summary>
    /// Procesa un mensaje recibido desde otro dispositivo.
    /// </summary>
    public void ProcessMessage(string message)
    {
        if (string.IsNullOrEmpty(message))
            return;

        message = message.Trim();

        if (DatabaseManager.Instance == null ||
            !DatabaseManager.Instance.IsReady)
        {
            Debug.LogError(
                "UserSyncService: base de datos no disponible."
            );
            return;
        }

        SQLiteConnection connection =
            DatabaseManager.Instance.GetConnection();

        if (connection == null)
        {
            Debug.LogError(
                "UserSyncService: conexión SQLite es null."
            );
            return;
        }

        bool changed = false;
        applyingRemoteData = true;

        try
        {
            if (message.StartsWith(MsgStudent))
            {
                UserSyncData data = JsonUtility.FromJson<UserSyncData>(message.Substring(MsgStudent.Length));
                if (data != null)
                    changed = SaveStudentLocally(connection, data);
            }
            else if (message.StartsWith(MsgProgress))
            {
                ProgressSyncData data = JsonUtility.FromJson<ProgressSyncData>(message.Substring(MsgProgress.Length));
                if (data != null)
                    changed = SaveProgressLocally(connection, data);
            }
            else if (message.StartsWith(MsgResult))
            {
                ResultSyncData data = JsonUtility.FromJson<ResultSyncData>(message.Substring(MsgResult.Length));
                if (data != null)
                    changed = SaveResultLocally(connection, data);
            }
        }
        catch (SQLiteException ex)
        {
            Debug.LogError($"UserSyncService: error SQLite: {ex.Message}");
        }
        catch (Exception ex)
        {
            Debug.LogError("UserSyncService: error procesando mensaje: " + ex.Message);
        }
        finally
        {
            applyingRemoteData = false;
        }

        if (changed)
        {
            try
            {
                OnDataSynced?.Invoke();
            }
            catch (Exception ex)
            {
                Debug.LogError("UserSyncService: error refrescando UI: " + ex.Message);
            }
        }
    }

    /// <summary>
    /// Busca el estudiante local por nombre (el id_user no coincide entre dispositivos).
    /// </summary>
    private static UserModel FindLocalStudentByName(SQLiteConnection connection, string name)
    {
        if (string.IsNullOrWhiteSpace(name))
            return null;

        return connection.Query<UserModel>(
            "SELECT * FROM users WHERE name = ? COLLATE NOCASE AND id_role = 1",
            name).FirstOrDefault();
    }

    /// <summary>
    /// Inserta o actualiza en SQLite el estudiante recibido.
    /// </summary>
    private bool SaveStudentLocally(SQLiteConnection connection, UserSyncData data)
    {
        if (data.id_role != 1)
            return false;

        UserModel existing = FindLocalStudentByName(connection, data.name);

        if (existing != null)
        {
            existing.id_degree = data.id_degree;
            existing.password = data.password;
            existing.id_security_question = data.id_security_question;
            existing.security_asnwer_hash = data.security_asnwer_hash;
            existing.last_login = data.last_login;
            connection.Update(existing);

            int existingId = existing.id_user;
            StudentModel existingStudent =
                connection.Table<StudentModel>().FirstOrDefault(s => s.id_user == existingId);

            if (existingStudent == null)
            {
                connection.Insert(new StudentModel { id_user = existingId, age = data.age });
            }
            else if (existingStudent.age != data.age)
            {
                connection.Execute("UPDATE students SET age = ? WHERE id_user = ?", data.age, existingId);
            }

            Debug.Log($"UserSyncService: estudiante '{data.name}' actualizado.");
            return true;
        }

        UserModel user = new UserModel
        {
            name = data.name,
            id_degree = data.id_degree,
            password = data.password,
            id_role = data.id_role,
            id_security_question = data.id_security_question,
            security_asnwer_hash = data.security_asnwer_hash,
            last_login = data.last_login
        };

        // id_user es AutoIncrement: SQLite asigna el id local.
        connection.Insert(user);

        connection.Insert(new StudentModel
        {
            id_user = user.id_user,
            age = data.age
        });

        Debug.Log($"UserSyncService: estudiante '{data.name}' guardado con id local {user.id_user}.");
        return true;
    }

    /// <summary>
    /// Inserta o actualiza la fila de progress (id_user + id_module) recibida.
    /// </summary>
    private bool SaveProgressLocally(SQLiteConnection connection, ProgressSyncData data)
    {
        UserModel user = FindLocalStudentByName(connection, data.student_name);
        if (user == null)
        {
            Debug.LogWarning($"UserSyncService: progreso recibido de '{data.student_name}', pero el estudiante no existe aquí.");
            return false;
        }

        int userId = user.id_user;
        int moduleId = data.id_module;

        ProgressModel row = connection.Table<ProgressModel>()
            .FirstOrDefault(x => x.id_user == userId && x.id_module == moduleId);

        bool isNew = row == null;
        if (isNew)
        {
            row = new ProgressModel { id_user = userId, id_module = moduleId };
        }

        row.punctuation = data.punctuation;
        row.percentage_completed = data.percentage_completed;
        row.completad_at = data.completad_at > 0 ? data.completad_at : (int?)null;
        row.status = data.status;

        if (isNew)
            connection.Insert(row);
        else
            connection.Update(row);

        Debug.Log($"UserSyncService: progreso de '{data.student_name}' en módulo {moduleId} = {data.percentage_completed}%.");
        return true;
    }

    /// <summary>
    /// Inserta el resultado recibido si no existe ya (evita duplicados al resincronizar).
    /// </summary>
    private bool SaveResultLocally(SQLiteConnection connection, ResultSyncData data)
    {
        UserModel user = FindLocalStudentByName(connection, data.student_name);
        if (user == null)
        {
            Debug.LogWarning($"UserSyncService: resultado recibido de '{data.student_name}', pero el estudiante no existe aquí.");
            return false;
        }

        int userId = user.id_user;
        int activityId = data.id_activity;

        bool exists = connection.Table<ResultActivityData>()
            .Where(r => r.id_user == userId && r.id_activity == activityId)
            .ToList()
            .Any(r => r.score == data.score &&
                      r.stars == data.stars &&
                      r.attempts == data.attempts &&
                      r.completed_at == data.completed_at);

        if (exists)
            return false;

        connection.Insert(new ResultActivityData
        {
            id_user = userId,
            id_activity = data.id_activity,
            score = data.score,
            stars = data.stars,
            attempts = data.attempts,
            completed_at = data.completed_at
        });

        Debug.Log($"UserSyncService: resultado de '{data.student_name}' en actividad {data.id_activity} guardado.");
        return true;
    }
}
