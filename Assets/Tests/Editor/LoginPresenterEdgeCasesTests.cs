using System;
using System.IO;
using NUnit.Framework;
using SQLite4Unity3d;
using UnityEngine;
using UnityEngine.TestTools;

/// <summary>
/// Tests avanzados para LoginPresenter con validaciones de edge cases.
/// Cubre casos límite de entrada, comportamiento de sesión y mensajes de error.
/// </summary>
public class LoginPresenterEdgeCasesTests
{
    [SetUp]
    public void SetUp()
    {
        ResetSessionManager();
    }

    [TearDown]
    public void TearDown()
    {
        ResetSessionManager();
    }

    // ─────────────────────────────────────────────────────────────
    //  Validaciones de longitud y caracteres especiales
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void LoginStudent_NombreMuyLargo_DebeAutenticarSiExiste()
    {
        using var context = new EdgeCaseTestContext();
        string longName = new string('A', 100) + " Garcia";
        context.SeedStudent(longName, PasswordHasher.HashPassword("clave123"));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent(longName, "clave123");

        Assert.IsTrue(result.IsSuccess);
    }

    [Test]
    public void LoginStudent_ContraseñaConEspacios_NoDebeValidar()
    {
        using var context = new EdgeCaseTestContext();
        context.SeedStudent("Ana Garcia", PasswordHasher.HashPassword("clave con espacios"));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent("Ana Garcia", "clave con espacios");

        Assert.IsFalse(result.IsSuccess);
    }

    [Test]
    public void LoginStudent_ContraseñaConCaracteresEspeciales_DebeValidar()
    {
        using var context = new EdgeCaseTestContext();
        string specialPassword = "clave!@#$%^&*()";
        context.SeedStudent("Juan Perez", PasswordHasher.HashPassword(specialPassword));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent("Juan Perez", specialPassword);

        Assert.IsTrue(result.IsSuccess);
    }

    [Test]
    public void LoginStudent_NombreConNumeros_NoDebeAutenticar()
    {
        using var context = new EdgeCaseTestContext();
        context.SeedStudent("Ana123 Garcia456", PasswordHasher.HashPassword("clave123"));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent("Ana123 Garcia456", "clave123");

        Assert.IsFalse(result.IsSuccess);
    }

    [Test]
    public void LoginStudent_NombreConAcentos_DebeAutenticar()
    {
        using var context = new EdgeCaseTestContext();
        context.SeedStudent("José María", PasswordHasher.HashPassword("clave123"));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent("José María", "clave123");

        Assert.IsTrue(result.IsSuccess);
    }

    // ─────────────────────────────────────────────────────────────
    //  Casos de whitespace
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void LoginStudent_NombreConTabsYEspacios_DebeNormalizar()
    {
        using var context = new EdgeCaseTestContext();
        context.SeedStudent("Ana Garcia", PasswordHasher.HashPassword("clave123"));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        // Nombre con tabs y espacios múltiples
        var result = context.Presenter.LoginStudent("\t\tAna Garcia\t\t", "clave123");

        Assert.IsTrue(result.IsSuccess);
    }

    [Test]
    public void LoginStudent_ContrasenaConEspaciosAlRededor_NoDebeNormalizarse()
    {
        using var context = new EdgeCaseTestContext();
        context.SeedStudent("Ana Garcia", PasswordHasher.HashPassword("clave123"));

        var result = context.Presenter.LoginStudent("Ana Garcia", " clave123 ");

        Assert.IsFalse(result.IsSuccess, "La contraseña no debe normalizarse (no hace trim)");
    }

    // ─────────────────────────────────────────────────────────────
    //  Validaciones de null y vacío
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void LoginStudent_NombreNulo_DebeRetornarError()
    {
        using var context = new EdgeCaseTestContext();

        var result = context.Presenter.LoginStudent(null, "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu nombre completo.", result.NameError);
    }

    [Test]
    public void LoginStudent_ContrasenaNull_DebeRetornarError()
    {
        using var context = new EdgeCaseTestContext();

        var result = context.Presenter.LoginStudent("Ana Garcia", null);

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu contraseña.", result.PasswordError);
    }

    [Test]
    public void LoginTeacher_EmailNulo_DebeRetornarError()
    {
        using var context = new EdgeCaseTestContext();

        var result = context.Presenter.LoginTeacher(null, "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu correo electrónico.", result.NameError);
    }

    [Test]
    public void LoginTeacher_ContrasenaNull_DebeRetornarError()
    {
        using var context = new EdgeCaseTestContext();

        var result = context.Presenter.LoginTeacher("profesor@correo.com", null);

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("La contraseña no es correcta. Inténtalo otra vez.", result.PasswordError);
    }

    // ─────────────────────────────────────────────────────────────
    //  Validaciones de precedencia (qué error se reporta primero)
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void LoginStudent_AmbosNulosYVacios_DebeReportarAmbosErrores()
    {
        using var context = new EdgeCaseTestContext();

        var result = context.Presenter.LoginStudent(null, null);

        Assert.IsFalse(result.IsSuccess);
        Assert.IsNotNull(result.NameError);
        Assert.IsNotNull(result.PasswordError);
    }

    [Test]
    public void LoginStudent_NombreEspaciosYContraseñaVacia_DebeReportarAmbos()
    {
        using var context = new EdgeCaseTestContext();

        var result = context.Presenter.LoginStudent("   ", "");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu nombre completo.", result.NameError);
        Assert.AreEqual("Escribe tu contraseña.", result.PasswordError);
    }

    // ─────────────────────────────────────────────────────────────
    //  Validaciones de múltiples usuarios con nombres similares
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void LoginStudent_MultiplesUsuariosNombresSimilares_DebeEncontrarExacto()
    {
        using var context = new EdgeCaseTestContext();
        context.SeedStudent("Ana Garcia", PasswordHasher.HashPassword("pass1"));
        context.SeedStudent("Ana", PasswordHasher.HashPassword("pass2"));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent("Ana", "pass2");

        Assert.IsTrue(result.IsSuccess);
        Assert.AreEqual("Ana", result.User.name);
    }

    // ─────────────────────────────────────────────────────────────
    //  Validaciones de estructura de resultado
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void LoginStudent_FalloValidacion_DebeDejarNullGeneralMessage()
    {
        using var context = new EdgeCaseTestContext();

        var result = context.Presenter.LoginStudent("", "");

        Assert.IsNull(result.GeneralMessage, "GeneralMessage debe ser null en fallos de validación");
    }

    [Test]
    public void LoginStudent_UsuarioNoEncontrado_NoDebeRetornarErroresDeCampo()
    {
        using var context = new EdgeCaseTestContext();

        var result = context.Presenter.LoginStudent("NoExiste", "clave123");

        Assert.IsNull(result.NameError, "No debe haber error de campo cuando falla autenticación");
        Assert.IsNull(result.PasswordError, "No debe haber error de campo cuando falla autenticación");
        Assert.IsNotNull(result.GeneralMessage);
    }

    // ─────────────────────────────────────────────────────────────
    //  Validaciones de persistencia
    // ─────────────────────────────────────────────────────────────

    [Test]
    public void LoginStudent_ExitosoCamposBasicosPresentes()
    {
        using var context = new EdgeCaseTestContext();
        context.SeedStudent("Pedro Rodriguez", PasswordHasher.HashPassword("clave123"));
        var expectedUser = context.Repository.LoginStudent("Pedro Rodriguez");
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent("Pedro Rodriguez", "clave123");

        Assert.IsTrue(result.IsSuccess);
        Assert.IsNotNull(result.User);
        Assert.AreEqual(expectedUser.id_user, result.User.id_user);
        Assert.AreEqual(expectedUser.name, result.User.name);
        Assert.IsNull(result.NameError);
        Assert.IsNull(result.PasswordError);
        Assert.IsNull(result.GeneralMessage);
    }

    private static void ResetSessionManager()
    {
        if (UserSessionManager.Instance != null)
        {
            UnityEngine.Object.DestroyImmediate(UserSessionManager.Instance.gameObject);
        }

        System.Reflection.FieldInfo instanceField = typeof(UserSessionManager)
            .GetField("<Instance>k__BackingField", System.Reflection.BindingFlags.Static | System.Reflection.BindingFlags.NonPublic);

        instanceField?.SetValue(null, null);
    }

    private sealed class EdgeCaseTestContext : IDisposable
    {
        private readonly string databasePath;

        public SQLiteConnection Connection { get; }
        public UserRepository Repository { get; }
        public AuthService AuthService { get; }
        public LoginPresenter Presenter { get; }

        public EdgeCaseTestContext()
        {
            databasePath = Path.Combine(@"C:\tmp", $"edge-case-tests-{Guid.NewGuid():N}.db");
            Connection = new SQLiteConnection(databasePath);
            Connection.CreateTable<UserModel>();
            Connection.CreateTable<StudentModel>();
            Connection.CreateTable<TeacherModel>();

            Repository = new UserRepository(Connection);
            AuthService = new AuthService(Repository);
            Presenter = new LoginPresenter(AuthService);
        }

        public void SeedStudent(string name, string storedPassword)
        {
            UserModel user = new UserModel
            {
                name = name,
                id_degree = 1,
                password = storedPassword,
                id_role = 1,
                id_security_question = 0,
                security_asnwer_hash = string.Empty,
                last_login = string.Empty
            };

            Repository.InsertUser(user);
            Repository.InserStudent(new StudentModel
            {
                id_user = user.id_user,
                age = 12
            });
        }

        public void Dispose()
        {
            Connection?.Dispose();

            if (File.Exists(databasePath))
            {
                File.Delete(databasePath);
            }
        }
    }
}
