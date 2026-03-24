using System.Security.Cryptography;
using System.Text;

/// <summary>
/// Utilidad de hashing y verificacion de contrasenas.
/// Mantiene compatibilidad temporal con contrasenas legacy en texto plano.
/// </summary>
public static class PasswordHasher
{
    /// <summary>
    /// Genera un hash SHA-256 en formato hexadecimal.
    /// </summary>
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

    /// <summary>
    /// Indica si una cadena parece un hash SHA-256 hexadecimal.
    /// </summary>
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

    /// <summary>
    /// Verifica la contrasena ingresada contra un hash o contra un valor legacy en texto plano.
    /// </summary>
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
