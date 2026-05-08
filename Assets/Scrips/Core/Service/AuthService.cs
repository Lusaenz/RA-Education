
using System.Security.Cryptography;
using System.Text;

/// <summary>
/// Servicio de aplicacion para autenticacion y registro.
/// Orquesta repositorios y reglas basicas de seguridad para estudiantes y profesores.
/// </summary>
public class AuthService 
{
    private readonly UserRepository userRepository;

    /// <summary>
    /// Crea el servicio con el repositorio de usuarios a utilizar.
    /// </summary>
    public AuthService(UserRepository repository)
    {
        userRepository = repository ?? throw new System.ArgumentNullException(nameof(repository));
    }

    /// <summary>
    /// Autentica un estudiante por nombre y contrasena.
    /// </summary>
    public UserModel LoginStudent(string name, string pass)
    {
        UserModel user = userRepository.LoginStudent(name);
        if (user == null)
        {
            return null;
        }

        bool isValid = PasswordHasher.VerifyPassword(pass, user.password);
        if (!isValid)
        {
            return null;
        }

        // Si estaba en texto plano, migramos al hash SHA256 al primer login exitoso.
        if (!PasswordHasher.IsSha256Hash(user.password))
        {
            string newHash = PasswordHasher.HashPassword(pass);
            userRepository.UpdateUserPassword(user.id_user, newHash);
            user.password = newHash;
        }

        return user;
    }

    /// <summary>
    /// Autentica un profesor por correo y contrasena.
    /// </summary>
    public UserModel LoginTeacher(string email, string pass)
    {
        UserModel user = userRepository.LoginTeacher(email);
        if (user == null)
        {
            return null;
        }

        bool isValid = PasswordHasher.VerifyPassword(pass, user.password);
        if (!isValid)
        {
            return null;
        }

        // Si estaba en texto plano, migramos al hash SHA256 al primer login exitoso.
        if (!PasswordHasher.IsSha256Hash(user.password))
        {
            string newHash = PasswordHasher.HashPassword(pass);
            userRepository.UpdateUserPassword(user.id_user, newHash);
            user.password = newHash;
        }

        return user;
    }

    /// <summary>
    /// Registra un estudiante creando el usuario base y luego su detalle academico.
    /// Retorna el UserModel con el ID generado.
    /// </summary>
    public UserModel RegisterStudent(string name, int degreeId, int age, string pass)
    {
        try
        {
            UserModel u = new UserModel
            {
                name = name,
                id_degree = degreeId,
                password = PasswordHasher.HashPassword(pass),
                id_role = 1,
                id_security_question = 0,
                security_asnwer_hash = "",
                last_login = ""
            };

            userRepository.InsertUser(u);

            StudentModel s = new StudentModel
            {
                id_user = u.id_user,
                age = age
            };
            userRepository.InserStudent(s);
            
            // Retornar el modelo con el ID generado
            return u;
        }
        catch (System.Exception ex)
        {
            UnityEngine.Debug.LogError($"AuthService.RegisterStudent Error: {ex.Message}\nStackTrace: {ex.StackTrace}");
            throw;
        }
    }

    /// <summary>
    /// Registra un profesor creando el usuario base y luego su informacion adicional.
    /// Retorna el UserModel con el ID generado.
    /// </summary>
    public UserModel RegisterTeacher(string name, int degreeId, string pass, string email)
    {
        UserModel u = new UserModel
        {
            name = name,
            password = PasswordHasher.HashPassword(pass),
            id_degree = degreeId,
            id_role = 2,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };

        userRepository.InsertUser(u);

        TeacherModel t = new TeacherModel
        {
            id_user = u.id_user,
            email = email
        };
        userRepository.InsertTeacher(t);
        
        // Retornar el modelo con el ID generado
        return u;
    }

    /// <summary>
    /// Guarda la pregunta de seguridad y su respuesta cifrada para un usuario.
    /// </summary>
    public void SaveSecurityQuestion(int userId, int questionId, string answer)
    {
        if (string.IsNullOrWhiteSpace(answer))
        {
            throw new System.ArgumentException("La respuesta de seguridad no puede estar vacía.", nameof(answer));
        }

        // Cifrar la respuesta de seguridad
        string encryptedAnswer = EncryptAnswer(answer);
        
        // Guardar en la BD
        userRepository.UpdateUserSecurityQuestion(userId, questionId, encryptedAnswer);
    }

    /// <summary>
    /// Verifica si la respuesta de seguridad es correcta.
    /// </summary>
    public bool VerifySecurityAnswer(int userId, string providedAnswer)
    {
        if (string.IsNullOrWhiteSpace(providedAnswer))
        {
            return false;
        }

        UserModel user = userRepository.GetUserById(userId);
        if (user == null || user.id_security_question <= 0 || string.IsNullOrEmpty(user.security_asnwer_hash))
        {
            return false;
        }

        // Cifrar la respuesta proporcionada y compararla con la almacenada
        string encryptedProvided = EncryptAnswer(providedAnswer);
        return string.Equals(encryptedProvided, user.security_asnwer_hash, System.StringComparison.Ordinal);
    }

    /// <summary>
    /// Actualiza el último login del usuario con la fecha actual en formato día/mes/año.
    /// </summary>
    public void UpdateLastLogin(int userId)
    {
        string now = System.DateTime.Now.ToString("dd/MM/yyyy");
        userRepository.UpdateLastLogin(userId, now);
    }

    /// <summary>
    /// Busca un usuario por nombre y rol específico.
    /// Utilizado para recuperación de contraseña y otros flujos.
    /// </summary>
    public UserModel FindUserByNameAndRole(string name, int roleId)
    {
        if (string.IsNullOrWhiteSpace(name))
        {
            UnityEngine.Debug.LogWarning("FindUserByNameAndRole: Nombre no puede estar vacío.");
            return null;
        }

        try
        {
            // Para estudiantes (roleId = 1)
            if (roleId == 1)
            {
                return userRepository.LoginStudent(name);
            }
            // Para profesores (roleId = 2), buscar por nombre en tabla de usuarios
            else if (roleId == 2)
            {
                return userRepository.LoginTeacher(name);
            }

            UnityEngine.Debug.LogWarning($"FindUserByNameAndRole: Rol desconocido {roleId}");
            return null;
        }
        catch (System.Exception ex)
        {
            UnityEngine.Debug.LogError($"AuthService.FindUserByNameAndRole Error: {ex.Message}");
            return null;
        }
    }

    /// <summary>
    /// Cambia la contraseña de un usuario después de haber verificado su respuesta de seguridad.
    /// Precondición: La respuesta de seguridad ya ha sido verificada en presenter.
    /// </summary>
    public void ChangePasswordAfterSecurityVerification(int userId, string newPassword)
    {
        if (string.IsNullOrWhiteSpace(newPassword))
        {
            throw new System.ArgumentException("La contraseña no puede estar vacía.", nameof(newPassword));
        }

        try
        {
            // Hashear la nueva contraseña
            string hashedPassword = PasswordHasher.HashPassword(newPassword);

            // Actualizar en la BD
            userRepository.UpdateUserPassword(userId, hashedPassword);

            UnityEngine.Debug.Log($"[AuthService] Contraseña actualizada exitosamente para usuario {userId}");
        }
        catch (System.Exception ex)
        {
            UnityEngine.Debug.LogError($"AuthService.ChangePasswordAfterSecurityVerification Error: {ex.Message}\nStackTrace: {ex.StackTrace}");
            throw;
        }
    }

    /// <summary>
    /// Cifra una respuesta de seguridad usando SHA256.
    /// </summary>
    private string EncryptAnswer(string answer)
    {
        if (string.IsNullOrEmpty(answer))
        {
            return string.Empty;
        }

        // Normalizar la respuesta (lowercase, trim) para hacer comparaciones más lenientes
        answer = answer.ToLower().Trim();

        using (SHA256 sha256 = SHA256.Create())
        {
            byte[] inputBytes = Encoding.UTF8.GetBytes(answer);
            byte[] hashBytes = sha256.ComputeHash(inputBytes);

            StringBuilder sb = new StringBuilder(hashBytes.Length * 2);
            for (int i = 0; i < hashBytes.Length; i++)
            {
                sb.Append(hashBytes[i].ToString("x2"));
            }

            return sb.ToString();
        }
    }

    /// <summary>
    /// Implementacion interna legacy de hashing usada por este servicio.
    /// Existe otra version equivalente en Core/Security y conviene unificarlas.
    /// </summary>
    private static class PasswordHasher
    {
        public static string HashPassword(string password)
        {
            if (password == null)
            {
                return string.Empty;
            }

            using (SHA256 sha256 = SHA256.Create())
            {
                byte[] inputBytes = Encoding.UTF8.GetBytes(password);
                byte[] hashBytes = sha256.ComputeHash(inputBytes);

                StringBuilder sb = new StringBuilder(hashBytes.Length * 2);
                for (int i = 0; i < hashBytes.Length; i++)
                {
                    sb.Append(hashBytes[i].ToString("x2"));
                }

                return sb.ToString();
            }
        }

        public static bool IsSha256Hash(string value)
        {
            if (string.IsNullOrEmpty(value) || value.Length != 64)
            {
                return false;
            }

            for (int i = 0; i < value.Length; i++)
            {
                char c = value[i];
                bool isHex =
                    (c >= '0' && c <= '9') ||
                    (c >= 'a' && c <= 'f') ||
                    (c >= 'A' && c <= 'F');

                if (!isHex)
                {
                    return false;
                }
            }

            return true;
        }

        public static bool VerifyPassword(string inputPassword, string storedPassword)
        {
            if (string.IsNullOrEmpty(storedPassword))
            {
                return false;
            }

            if (IsSha256Hash(storedPassword))
            {
                string inputHash = HashPassword(inputPassword);
                return string.Equals(inputHash, storedPassword, System.StringComparison.OrdinalIgnoreCase);
            }

            // Compatibilidad temporal con usuarios antiguos en texto plano.
            return string.Equals(inputPassword, storedPassword, System.StringComparison.Ordinal);
        }
    }
}
