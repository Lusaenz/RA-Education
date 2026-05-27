using NUnit.Framework;

/// <summary>
/// Tests unitarios para PasswordHasher.
/// Verifica hashing SHA-256, detección de hash y verificación legacy.
/// </summary>
public class PasswordHasherTests
{
    // ─────────────────────────────────────────────────────────────
    //  HashPassword
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void HashPassword_RetornaStringDe64Caracteres()
    {
        string hash = PasswordHasher.HashPassword("miContrasena");

        Assert.AreEqual(64, hash.Length, "SHA-256 en hex siempre produce 64 caracteres");
    }

    [Test]
    public void HashPassword_RetornaSoloCaracteresHex()
    {
        string hash = PasswordHasher.HashPassword("miContrasena");

        foreach (char c in hash)
        {
            bool esHex = (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
            Assert.IsTrue(esHex, $"Carácter '{c}' no es hexadecimal válido");
        }
    }

    [Test]
    public void HashPassword_MismaClave_ProduceMismoHash()
    {
        string hash1 = PasswordHasher.HashPassword("clave123");
        string hash2 = PasswordHasher.HashPassword("clave123");

        Assert.AreEqual(hash1, hash2, "La misma contraseña siempre produce el mismo hash");
    }

    [Test]
    public void HashPassword_ClavesDistintas_ProducenHashesDistintos()
    {
        string hash1 = PasswordHasher.HashPassword("clave123");
        string hash2 = PasswordHasher.HashPassword("CLAVE123");

        Assert.AreNotEqual(hash1, hash2, "Contraseñas distintas deben producir hashes distintos");
    }

    [Test]
    public void HashPassword_Null_RetornaCadenaVacia()
    {
        string hash = PasswordHasher.HashPassword(null);

        Assert.AreEqual(string.Empty, hash, "Contraseña null debe retornar cadena vacía");
    }

    [Test]
    public void HashPassword_Vacia_RetornaHashValido()
    {
        string hash = PasswordHasher.HashPassword("");

        Assert.AreEqual(64, hash.Length, "Hash de cadena vacía sigue siendo un hash SHA-256 de 64 chars");
    }

    // ─────────────────────────────────────────────────────────────
    //  IsSha256Hash
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void IsSha256Hash_HashValido_RetornaTrue()
    {
        string hash = PasswordHasher.HashPassword("prueba");

        Assert.IsTrue(PasswordHasher.IsSha256Hash(hash));
    }

    [Test]
    public void IsSha256Hash_TextoPlano_RetornaFalse()
    {
        Assert.IsFalse(PasswordHasher.IsSha256Hash("miContrasena"));
    }

    [Test]
    public void IsSha256Hash_CadenaVacia_RetornaFalse()
    {
        Assert.IsFalse(PasswordHasher.IsSha256Hash(""));
    }

    [Test]
    public void IsSha256Hash_Null_RetornaFalse()
    {
        Assert.IsFalse(PasswordHasher.IsSha256Hash(null));
    }

    [Test]
    public void IsSha256Hash_63Caracteres_RetornaFalse()
    {
        string casiHash = new string('a', 63);

        Assert.IsFalse(PasswordHasher.IsSha256Hash(casiHash), "63 chars no es SHA-256 válido");
    }

    [Test]
    public void IsSha256Hash_65Caracteres_RetornaFalse()
    {
        string casiHash = new string('a', 65);

        Assert.IsFalse(PasswordHasher.IsSha256Hash(casiHash), "65 chars no es SHA-256 válido");
    }

    [Test]
    public void IsSha256Hash_64CaracteresConCaracterInvalido_RetornaFalse()
    {
        // 63 hexadecimales + un carácter no hex
        string hashInvalido = new string('a', 63) + "z";

        Assert.IsFalse(PasswordHasher.IsSha256Hash(hashInvalido));
    }

    // ─────────────────────────────────────────────────────────────
    //  VerifyPassword
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void VerifyPassword_ClaveCorrectaContraHash_RetornaTrue()
    {
        string hash = PasswordHasher.HashPassword("miClave");

        Assert.IsTrue(PasswordHasher.VerifyPassword("miClave", hash));
    }

    [Test]
    public void VerifyPassword_ClaveIncorrectaContraHash_RetornaFalse()
    {
        string hash = PasswordHasher.HashPassword("miClave");

        Assert.IsFalse(PasswordHasher.VerifyPassword("otraClave", hash));
    }

    [Test]
    public void VerifyPassword_LegacyTextoPlano_MismaClave_RetornaTrue()
    {
        // Usuarios legacy: la contraseña está almacenada como texto plano
        Assert.IsTrue(PasswordHasher.VerifyPassword("legacyPass", "legacyPass"));
    }

    [Test]
    public void VerifyPassword_LegacyTextoPlano_ClaveDiferente_RetornaFalse()
    {
        Assert.IsFalse(PasswordHasher.VerifyPassword("otraPass", "legacyPass"));
    }

    [Test]
    public void VerifyPassword_StoredVacio_RetornaFalse()
    {
        Assert.IsFalse(PasswordHasher.VerifyPassword("miClave", ""));
    }

    [Test]
    public void VerifyPassword_StoredNull_RetornaFalse()
    {
        Assert.IsFalse(PasswordHasher.VerifyPassword("miClave", null));
    }

    [Test]
    public void VerifyPassword_HashEsCaseInsensitive()
    {
        string hashMinusculas = PasswordHasher.HashPassword("clave").ToLower();
        string hashMayusculas = PasswordHasher.HashPassword("clave").ToUpper();

        // Ambas variantes del hash deben verificar correctamente
        Assert.IsTrue(PasswordHasher.VerifyPassword("clave", hashMinusculas), "Verificación con hash en minúsculas");
        Assert.IsTrue(PasswordHasher.VerifyPassword("clave", hashMayusculas), "Verificación con hash en mayúsculas");
    }
}
