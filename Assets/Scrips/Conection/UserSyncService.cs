using System;
using System.Text;
using System.Threading.Tasks;
using UnityEngine;
using SQLite4Unity3d;

public class UserSyncService : MonoBehaviour
{
    public static UserSyncService Instance { get; private set; }

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

    /// <summary>
    /// Envía un estudiante al celular conectado.
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
            age = student.age
        };

        string json = JsonUtility.ToJson(data);

        string message = "CREATE_STUDENT|" + json;

        await SimpleClient.Instance.SendRawMessage(message);

        Debug.Log(
            $"UserSyncService: estudiante {user.id_user} enviado correctamente."
        );
    }

    /// <summary>
    /// Procesa un mensaje recibido desde otro celular.
    /// </summary>
   public void ProcessMessage(string message)
{
    Debug.Log(
        $"SYNC TEST 5: UserSyncService recibió: {message}"
    );

    if (string.IsNullOrEmpty(message))
        return;

        if (!message.StartsWith("CREATE_STUDENT|"))
            return;

            Debug.Log(
    "SYNC TEST 6: Detectado mensaje CREATE_STUDENT."
);

        string json = message.Substring("CREATE_STUDENT|".Length);

        try
        {
            UserSyncData data =
                JsonUtility.FromJson<UserSyncData>(json);

                Debug.Log(
    $"SYNC TEST 7: JSON convertido. " +
    $"ID={data.id_user}, Nombre={data.name}"
);

            if (data == null)
            {
                Debug.LogError(
                    "UserSyncService: no se pudo convertir el JSON."
                );
                return;
            }

            SaveStudentLocally(data);
        }
        catch (Exception ex)
        {
            Debug.LogError(
                "UserSyncService: error procesando usuario: " +
                ex.Message
            );
        }
    }

    /// <summary>
    /// Guarda en SQLite el usuario recibido.
    /// </summary>
    private void SaveStudentLocally(UserSyncData data)
    {

        Debug.Log(
    $"SYNC TEST 8: Intentando guardar usuario " +
    $"{data.id_user} en SQLite."
);
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

        UserRepository repository =
            new UserRepository(connection);

        try
        {
            // Comprobar si el usuario ya existe.
            UserModel existing =
                repository.GetUserById(data.id_user);

            if (existing != null)
            {
                Debug.Log(
                    $"UserSyncService: usuario {data.id_user} ya existe. " +
                    "No se insertará nuevamente."
                );

                return;
            }

            UserModel user = new UserModel
            {
                id_user = data.id_user,
                name = data.name,
                id_degree = data.id_degree,
                password = data.password,
                id_role = data.id_role,
                id_security_question = data.id_security_question,
                security_asnwer_hash = data.security_asnwer_hash,
                last_login = data.last_login
            };

            StudentModel student = new StudentModel
            {
                id_user = data.id_user,
                age = data.age
            };

            Debug.Log(
    $"SYNC TEST 9: Insertando usuario en tabla users. " +
    $"ID={user.id_user}"
);

connection.Insert(user);

Debug.Log(
    $"SYNC TEST 10: Usuario insertado. " +
    $"Ahora insertando estudiante."
);

connection.Insert(student);

Debug.Log(
    $"SYNC TEST 11: Estudiante insertado correctamente. " +
    $"ID={student.id_user}"
);

            Debug.Log(
                $"UserSyncService: usuario {data.id_user} " +
                "guardado correctamente en SQLite."
            );
        }
        catch (SQLiteException ex)
        {
            Debug.LogError(
                $"UserSyncService: error SQLite: {ex.Message}"
            );
        }
        catch (Exception ex)
        {
            Debug.LogError(
                $"UserSyncService: error guardando usuario: {ex.Message}"
            );
        }
    }
}