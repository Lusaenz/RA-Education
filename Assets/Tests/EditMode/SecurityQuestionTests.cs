using NUnit.Framework;
using System.Collections.Generic;

/// <summary>
/// Tests de validación para la pregunta de seguridad requerida en el registro.
/// </summary>
public class SecurityQuestionTests
{
    // ─────────────────────────────────────────────────────────────
    //  ID DE PREGUNTA
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void PreguntaId_Cero_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(0, "miRespuesta");

        Assert.IsTrue(errors.ContainsKey("security"));
        Assert.AreEqual("Debe seleccionar una pregunta de seguridad.", errors["security"]);
    }

    [Test]
    public void PreguntaId_Negativo_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(-1, "miRespuesta");

        Assert.IsTrue(errors.ContainsKey("security"));
        Assert.AreEqual("Debe seleccionar una pregunta de seguridad.", errors["security"]);
    }

    [Test]
    public void PreguntaId_Valido_NoDebeRetornarErrorDePregunta()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(1, "miRespuesta");

        Assert.IsFalse(errors.ContainsKey("security"), "ID de pregunta válido no debe generar error");
    }

    // ─────────────────────────────────────────────────────────────
    //  RESPUESTA
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void Respuesta_Vacia_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(1, "");

        Assert.IsTrue(errors.ContainsKey("answer"));
        Assert.AreEqual("Debe ingresar la respuesta de seguridad.", errors["answer"]);
    }

    [Test]
    public void Respuesta_Null_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(1, null);

        Assert.IsTrue(errors.ContainsKey("answer"));
        Assert.AreEqual("Debe ingresar la respuesta de seguridad.", errors["answer"]);
    }

    [Test]
    public void Respuesta_SoloEspacios_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(1, "   ");

        Assert.IsTrue(errors.ContainsKey("answer"));
        Assert.AreEqual("Debe ingresar la respuesta de seguridad.", errors["answer"]);
    }

    [Test]
    public void Respuesta_UnCaracter_DebeRetornarError()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(1, "a");

        Assert.IsTrue(errors.ContainsKey("answer"));
        Assert.AreEqual("La respuesta debe tener al menos 2 caracteres.", errors["answer"]);
    }

    [Test]
    public void Respuesta_DosCaracteres_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(1, "ab");

        Assert.IsFalse(errors.ContainsKey("answer"), "Respuesta de 2 caracteres es válida");
    }

    [Test]
    public void Respuesta_Normal_NoDebeRetornarError()
    {
        var errors = RegisterValidator.ValidateSecurityQuestion(1, "Mascota");

        Assert.AreEqual(0, errors.Count, "Pregunta y respuesta válidas no deben generar errores");
    }

    // ─────────────────────────────────────────────────────────────
    //  CASO: ID inválido no verifica respuesta
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void PreguntaId_Invalido_RetornaAntesDe_ValidarRespuesta()
    {
        // Cuando el ID es inválido, debe retornar de inmediato sin validar la respuesta
        var errors = RegisterValidator.ValidateSecurityQuestion(0, "");

        Assert.IsTrue(errors.ContainsKey("security"), "Debe haber error de pregunta");
        Assert.IsFalse(errors.ContainsKey("answer"),  "No debe evaluar la respuesta si la pregunta es inválida");
        Assert.AreEqual(1, errors.Count, "Solo debe haber un error");
    }
}
