
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
    /// </summary>
    public bool RegisterStudent(string name, int degreeId, int age, string pass)
    {
        UserModel u = new UserModel
        {
            name = name,
            id_degree = degreeId,
            password = PasswordHasher.HashPassword(pass),
            id_role = 1
        };

        userRepository.InsertUser(u);

        StudentModel s = new StudentModel
        {
            id_user = u.id_user,
            age = age
        };
        userRepository.InserStudent(s);
        return true;
    }

    /// <summary>
    /// Registra un profesor creando el usuario base y luego su informacion adicional.
    /// </summary>
    public bool RegisterTeacher(string name, int degreeId, string pass, string email)
    {
        UserModel u = new UserModel
        {
            name = name,
            password = PasswordHasher.HashPassword(pass),
            id_degree = degreeId,
            id_role = 2
        };

        userRepository.InsertUser(u);

        TeacherModel t = new TeacherModel
        {
            id_user = u.id_user,
            email = email
        };
        userRepository.InsertTeacher(t);
        return true;
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
