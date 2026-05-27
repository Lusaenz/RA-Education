using NUnit.Framework;
using System.Collections.Generic; 

/// <summary>
/// Tests de validación para el registro de estudiantes.
/// Cubre todos los campos: nombre, grado, edad y contraseña.
/// </summary>
public class RegisterStudentTests
{
    // ─────────────────────────────────────────────────────────────
    //  NOMBRE
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void Nombre_Vacio_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("", 1, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"), "Debe haber error en el campo 'name'");
        Assert.AreEqual("El nombre es obligatorio.", errors["name"]);
    }

    [Test]
    public void Nombre_SoloEspacios_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("   ", 1, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("El nombre es obligatorio.", errors["name"]);
    }

    [Test]
    public void Nombre_Null_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent(null, 1, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("El nombre es obligatorio.", errors["name"]);
    }

    [Test]
    public void Nombre_UnaSolaPalabra_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan", 1, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("Nombre inválido", errors["name"]);
    }

    [Test]
    public void Nombre_ConNumeros_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan123 Perez", 1, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("Nombre inválido", errors["name"]);
    }

    [Test]
    public void Nombre_ConCaracteresEspeciales_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan @Perez", 1, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"));
        Assert.AreEqual("Nombre inválido", errors["name"]);
    }

    [Test]
    public void Nombre_DosPalabrasValidas_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", "pass123");

        Assert.IsFalse(errors.ContainsKey("name"), "Nombre válido no debe generar error");
    }

    [Test]
    public void Nombre_TresPalabras_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Carlos Perez", 1, "10", "pass123");

        Assert.IsFalse(errors.ContainsKey("name"));
    }

    [Test]
    public void Nombre_ConAcentos_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("María José", 1, "10", "pass123");

        Assert.IsFalse(errors.ContainsKey("name"));
    }

    [Test]
    public void Nombre_ConEnye_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Niño López", 1, "10", "pass123");

        Assert.IsFalse(errors.ContainsKey("name"));
    }

    [Test]
    public void Nombre_MenorDeSeisCar_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Ana Pe", 1, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"), "Nombre con menos de 6 caracteres debe generar error");
        Assert.AreEqual("El nombre debe tener entre 6 y 20 caracteres.", errors["name"]);
    }

    [Test]
    public void Nombre_ExactamenteSeisCar_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Ana Per", 1, "10", "pass123");

        Assert.IsFalse(errors.ContainsKey("name"), "Nombre con exactamente 6 caracteres es válido");
    }

    [Test]
    public void Nombre_VeintiCar_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Carlos López Pérez", 1, "10", "pass123");

        Assert.IsFalse(errors.ContainsKey("name"), "Nombre con exactamente 20 caracteres es válido");
    }

    [Test]
    public void Nombre_MasDVeintiCar_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Carlos López Pérez García", 1, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("name"), "Nombre con más de 20 caracteres debe generar error");
        Assert.AreEqual("El nombre debe tener entre 6 y 20 caracteres.", errors["name"]);
    }

    // ─────────────────────────────────────────────────────────────
    //  GRADO
    // ─────────────────────────────────────────────────────────────



    [Test]
    public void Grado_con_idDegree_1_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", "pass123");

        Assert.IsFalse(errors.ContainsKey("degree"), "Grado 1 es válido");
    }

    [Test]
    public void Grado_con_idDegree_0_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 0, "10", "pass123");

        Assert.IsTrue(errors.ContainsKey("degree"), "Grado 0 debe generar error");
    }

    // ─────────────────────────────────────────────────────────────
    //  EDAD
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void Edad_Texto_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "abc", "pass123");

        Assert.IsTrue(errors.ContainsKey("age"));
        Assert.AreEqual("Edad inválida.", errors["age"]);
    }

    [Test]
    public void Edad_Vacia_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "", "pass123");

        Assert.IsTrue(errors.ContainsKey("age"));
        Assert.AreEqual("Edad inválida.", errors["age"]);
    }

    [Test]
    public void Edad_Null_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, null, "pass123");

        Assert.IsTrue(errors.ContainsKey("age"));
        Assert.AreEqual("Edad inválida.", errors["age"]);
    }

    [Test]
    public void Edad_Decimal_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "5.5", "pass123");

        Assert.IsTrue(errors.ContainsKey("age"));
        Assert.AreEqual("Edad inválida.", errors["age"]);
    }

    [Test]
    public void Edad_Cero_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "0", "pass123");

        Assert.IsTrue(errors.ContainsKey("age"), "Edad 0 es Invalida");
    }

    [Test]
    public void Edad_Negativa_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "-1", "pass123");

        Assert.IsTrue(errors.ContainsKey("age"));
        Assert.AreEqual("La edad debe estar entre 10 y 15 años.", errors["age"]);
    }

    [Test]
    public void Edad_EnRango_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", "pass123");

        Assert.IsFalse(errors.ContainsKey("age"), "Edad numérica válida en rango no debe generar error");
    }

    [Test]
    public void Edad_LimiteSuperior_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "15", "pass123");

        Assert.IsFalse(errors.ContainsKey("age"), "Edad 15 (límite superior) es válida");
    }

    [Test]
    public void Edad_FueraDeLimite_MayorA15_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "16", "pass123");

        Assert.IsTrue(errors.ContainsKey("age"));
        Assert.AreEqual("La edad debe estar entre 10 y 15 años.", errors["age"]);
    }

    [Test]
    public void Edad_MuchoMayorQue15_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "100", "pass123");

        Assert.IsTrue(errors.ContainsKey("age"));
        Assert.AreEqual("La edad debe estar entre 10 y 15 años.", errors["age"]);
    }

    // ─────────────────────────────────────────────────────────────
    //  CONTRASEÑA
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void Contrasena_Vacia_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", "");

        Assert.IsTrue(errors.ContainsKey("password"));
        Assert.AreEqual("La contraseña es obligatoria.", errors["password"]);
    }

    [Test]
    public void Contrasena_SoloEspacios_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", "      ");

        Assert.IsTrue(errors.ContainsKey("password"));
        Assert.AreEqual("La contraseña es obligatoria.", errors["password"]);
    }

    [Test]
    public void Contrasena_Null_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", null);

        Assert.IsTrue(errors.ContainsKey("password"));
        Assert.AreEqual("La contraseña es obligatoria.", errors["password"]);
    }

    [Test]
    public void Contrasena_MenosDeSeisCar_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", "12345");

        Assert.IsTrue(errors.ContainsKey("password"));
        Assert.AreEqual("La contraseña debe tener al menos 6 caracteres.", errors["password"]);
    }

    [Test]
    public void Contrasena_ExactamenteSeisCar_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", "123456");

        Assert.IsFalse(errors.ContainsKey("password"), "Contraseña de 6 caracteres es válida");
    }

    [Test]
    public void Contrasena_MasDeSeisCar_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateStudent("Juan Perez", 1, "10", "MiPass2024!");

        Assert.IsFalse(errors.ContainsKey("password"));
    }

    // ─────────────────────────────────────────────────────────────
    //  MÚLTIPLES ERRORES
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void TodosLosCamposVacios_DebeRetornarCuatroErrores()
    {
        var errors = RegisterValidator.ValidateStudent("", 0, "", "");

        Assert.IsTrue(errors.ContainsKey("name"),     "Error en nombre");
        Assert.IsTrue(errors.ContainsKey("degree"),   "Error en grado");
        Assert.IsTrue(errors.ContainsKey("age"),      "Error en edad");
        Assert.IsTrue(errors.ContainsKey("password"), "Error en contraseña");
        Assert.AreEqual(4, errors.Count, "Deben ser exactamente 4 errores");
    }

    [Test]
    public void DatosValidos_NoDebeRetornarNingunError()
    {
        var errors = RegisterValidator.ValidateStudent("Ana García", 1, "12", "miClave99");

        Assert.AreEqual(0, errors.Count, "Datos completamente válidos no deben generar errores");
    }
}
