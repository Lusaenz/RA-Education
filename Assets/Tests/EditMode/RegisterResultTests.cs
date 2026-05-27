using NUnit.Framework;

/// <summary>
/// Tests unitarios para la clase RegisterResult.
/// Verifica los factory methods y el estado por defecto.
/// </summary>
public class RegisterResultTests
{
    [Test]
    public void Constructor_EstadoPorDefecto_EsError()
    {
        var result = new RegisterResult();

        Assert.IsFalse(result.Success, "Por defecto, Success debe ser false");
        Assert.AreEqual(-1, result.UserId, "UserId por defecto debe ser -1");
        Assert.IsNotNull(result.FieldErrors, "FieldErrors no debe ser null");
        Assert.AreEqual(0, result.FieldErrors.Count, "FieldErrors debe estar vacío");
    }

    [Test]
    public void SuccessResult_SinId_CreaResultadoExitoso()
    {
        var result = RegisterResult.SuccessResult();

        Assert.IsTrue(result.Success);
        Assert.AreEqual(-1, result.UserId, "UserId por defecto en success es -1");
        Assert.AreEqual(string.Empty, result.ErrorMessage);
    }

    [Test]
    public void SuccessResult_ConId_AsignaIdCorrectamente()
    {
        var result = RegisterResult.SuccessResult(42);

        Assert.IsTrue(result.Success);
        Assert.AreEqual(42, result.UserId);
    }

    [Test]
    public void ErrorResult_CreaResultadoFallido()
    {
        var result = RegisterResult.ErrorResult("Algo salió mal");

        Assert.IsFalse(result.Success);
        Assert.AreEqual("Algo salió mal", result.ErrorMessage);
        Assert.AreEqual(-1, result.UserId, "UserId en error debe ser -1");
    }

    [Test]
    public void FieldErrors_SeAgregaCorrectamente()
    {
        var result = new RegisterResult();
        result.FieldErrors["name"] = "El nombre es obligatorio.";
        result.FieldErrors["email"] = "El email es obligatorio.";

        Assert.AreEqual(2, result.FieldErrors.Count);
        Assert.AreEqual("El nombre es obligatorio.", result.FieldErrors["name"]);
        Assert.AreEqual("El email es obligatorio.", result.FieldErrors["email"]);
    }
}
