using NUnit.Framework;

/// <summary>
/// Tests de validación para el registro de profesores.
/// Cubre todos los campos: nombre, email, grado y contraseña.
/// </summary>
public class RegisterTeacherTests
{
    // ─────────────────────────────────────────────────────────────
    //  NOMBRE
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void Nombre_Vacio_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("", 1, "prof@mail.com", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("Escribe tu nombre completo", errors["name"]);
    }

    [Test]
    public void Nombre_SoloEspacios_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("   ", 1, "prof@mail.com", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("Escribe tu nombre completo", errors["name"]);
    }

    [Test]
    public void Nombre_Null_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher(null, 1, "prof@mail.com", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("Escribe tu nombre completo", errors["name"]);
    }

    [Test]
    public void Nombre_UnaSolaPalabra_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos", 1, "prof@mail.com", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("El nombre solo puede contener letras y espacios", errors["name"]);
    }

    [Test]
    public void Nombre_ConNumeros_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos123 López", 1, "prof@mail.com", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("El nombre solo puede contener letras y espacios", errors["name"]);
    }

    [Test]
    public void Nombre_ConCaracteresEspeciales_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos @López", 1, "prof@mail.com", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("El nombre solo puede contener letras y espacios", errors["name"]);
    }

    [Test]
    public void Nombre_DosPalabrasValidas_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@mail.com", "pass123");

        Assert.IsFalse(errors.ContainsKey("name"), "Nombre válido no debe generar error");
    }

    [Test]
    public void Nombre_ConAcentosYEnye_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Señorita Álvarez", 1, "prof@mail.com", "pass123");

        Assert.IsFalse(errors.ContainsKey("name"));
    }

    // ─────────────────────────────────────────────────────────────
    //  EMAIL
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void Email_Vacio_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "", "pass123");

        Assert.IsTrue(errors.ContainsKey("email"));
        Assert.AreEqual("El email es obligatorio.", errors["email"]);
    }

    [Test]
    public void Email_Null_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, null, "pass123");

        Assert.IsTrue(errors.ContainsKey("email"));
        Assert.AreEqual("El email es obligatorio.", errors["email"]);
    }

    [Test]
    public void Email_SinArroba_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "correosindominio.com", "pass123");

        Assert.IsTrue(errors.ContainsKey("email"));
        Assert.AreEqual("Escribe un correo válido", errors["email"]);
    }

    [Test]
    public void Email_SinDominio_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "correo@", "pass123");

        Assert.IsTrue(errors.ContainsKey("email"));
        Assert.AreEqual("Escribe un correo válido", errors["email"]);
    }

    [Test]
    public void Email_SinExtension_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "correo@dominio", "pass123");

        Assert.IsTrue(errors.ContainsKey("email"));
        Assert.AreEqual("Escribe un correo válido", errors["email"]);
    }

    [Test]
    public void Email_ExtensionMuyCorta_DebeRetornarError()
    {
        // La extensión mínima es de 2 caracteres según el regex
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "correo@dominio.c", "pass123");

        Assert.IsTrue(errors.ContainsKey("email"));
        Assert.AreEqual("Escribe un correo válido", errors["email"]);
    }

    [Test]
    public void Email_FormatoValido_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "correo@dominio.com", "pass123");

        Assert.IsFalse(errors.ContainsKey("email"), "Email válido no debe generar error");
    }

    [Test]
    public void Email_ConMayusculas_SeNormalizaYNoRetornaError()
    {
        // El validator convierte a lowercase antes de validar
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "CORREO@DOMINIO.COM", "pass123");

        Assert.IsFalse(errors.ContainsKey("email"), "Email con mayúsculas se normaliza, no debe ser error");
    }

    [Test]
    public void Email_ConSubdominio_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@universidad.edu.mx", "pass123");

        Assert.IsFalse(errors.ContainsKey("email"));
    }

    [Test]
    public void Email_ConPuntoAntesDeArroba_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "carlos.lopez@uni.edu", "pass123");

        Assert.IsFalse(errors.ContainsKey("email"));
    }

    // ─────────────────────────────────────────────────────────────
    //  GRADO
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void Grado_con_idDegree_0_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 0, "prof@mail.com", "pass123");

        Assert.IsTrue(errors.ContainsKey("degree"));
        Assert.AreEqual("Campo obligatorio", errors["degree"]);
    }


    [Test]
    public void Grado_con_idDegree_1_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@mail.com", "pass123");

        Assert.IsFalse(errors.ContainsKey("degree"), "Grado 1 es válido");
    }


    // ─────────────────────────────────────────────────────────────
    //  CONTRASEÑA
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void Contrasena_Vacia_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@mail.com", "");

        Assert.IsTrue(errors.ContainsKey("password"));
        Assert.AreEqual("La contraseña es obligatoria.", errors["password"]);
    }

    [Test]
    public void Contrasena_SoloEspacios_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@mail.com", "      ");

        Assert.IsTrue(errors.ContainsKey("password"));
        Assert.AreEqual("La contraseña es obligatoria.", errors["password"]);
    }

    [Test]
    public void Contrasena_Null_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@mail.com", null);

        Assert.IsTrue(errors.ContainsKey("password"));
        Assert.AreEqual("La contraseña es obligatoria.", errors["password"]);
    }

    [Test]
    public void Contrasena_CincoCaracteres_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@mail.com", "12345");

        Assert.IsTrue(errors.ContainsKey("password"));
        Assert.AreEqual("La contraseña debe tener al menos 6 caracteres.", errors["password"]);
    }

    [Test]
    public void Contrasena_ExactamenteSeisCar_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@mail.com", "123456");

        Assert.IsFalse(errors.ContainsKey("password"), "Contraseña de 6 caracteres es válida");
    }

    [Test]
    public void Contrasena_Compleja_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateTeacher("Carlos López", 1, "prof@mail.com", "MiPass2024!");

        Assert.IsFalse(errors.ContainsKey("password"));
    }

    // ─────────────────────────────────────────────────────────────
    //  MÚLTIPLES ERRORES
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void TodosLosCamposVacios_DebeRetornarCuatroErrores()
    {
        var errors = RegisterValidator.ValidateTeacher("", 0, "", "");

        Assert.IsTrue(errors.ContainsKey("name"),     "Error en nombre");
        Assert.IsTrue(errors.ContainsKey("email"),    "Error en email");
        Assert.IsTrue(errors.ContainsKey("degree"),   "Error en grado");
        Assert.IsTrue(errors.ContainsKey("password"), "Error en contraseña");
        Assert.AreEqual(4, errors.Count, "Deben ser exactamente 4 errores");
    }

    [Test]
    public void DatosCompletos_NoDebeRetornarNingunError()
    {
        var errors = RegisterValidator.ValidateTeacher("Laura Martínez", 1, "laura@escuela.edu.mx", "claveSecura99");

        Assert.AreEqual(0, errors.Count, "Datos completamente válidos no deben generar errores");
    }
}

