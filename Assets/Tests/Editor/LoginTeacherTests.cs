using System;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using SQLite4Unity3d;
using UnityEngine;
using UnityEngine.TestTools;

/// <summary>
/// Tests del flujo de login para profesores.
/// Cubre validaciones del presenter, autenticación, migración de contraseñas legacy
/// y actualización de último login usando una BD SQLite temporal.
/// </summary>
public class LoginTeacherTests
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

    [Test]
    public void Constructor_AuthNull_DebeLanzarArgumentNullException()
    {
        Assert.Throws<ArgumentNullException>(() => new LoginPresenter(null));
    }

    [Test]
    public void LoginTeacher_EmailVacio_DebeRetornarErrorDeEmail()
    {
        using var context = new TeacherLoginTestContext();

        var result = context.Presenter.LoginTeacher("", "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu correo electrónico.", result.NameError);
        Assert.IsNull(result.PasswordError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginTeacher_EmailConSoloEspacios_DebeRetornarErrorDeEmail()
    {
        using var context = new TeacherLoginTestContext();

        var result = context.Presenter.LoginTeacher("   ", "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu correo electrónico.", result.NameError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginTeacher_ContrasenaVacia_DebeRetornarErrorDeContrasena()
    {
        using var context = new TeacherLoginTestContext();

        var result = context.Presenter.LoginTeacher("profesor@correo.com", "");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("La contraseña no es correcta. Inténtalo otra vez.", result.PasswordError);
        Assert.IsNull(result.NameError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginTeacher_CamposVacios_DebeRetornarAmbosErrores()
    {
        using var context = new TeacherLoginTestContext();

        var result = context.Presenter.LoginTeacher("", "");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu correo electrónico.", result.NameError);
        Assert.AreEqual("La contraseña no es correcta. Inténtalo otra vez.", result.PasswordError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginTeacher_ProfesorInexistente_DebeRetornarMensajeGeneral()
    {
        using var context = new TeacherLoginTestContext();

        var result = context.Presenter.LoginTeacher("inexistente@correo.com", "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("No encontramos tu cuenta. Revisa tus datos o regístrate", result.GeneralMessage);
        Assert.IsNull(result.User);
    }

    [Test]
    public void LoginTeacher_ContrasenaIncorrecta_DebeRetornarMensajeGeneral()
    {
        using var context = new TeacherLoginTestContext();
        context.SeedTeacher("Carlos Martinez", PasswordHasher.HashPassword("claveCorrecta"), "carlos@correo.com");

        var result = context.Presenter.LoginTeacher("carlos@correo.com", "claveIncorrecta");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("No encontramos tu cuenta. Revisa tus datos o regístrate", result.GeneralMessage);
        Assert.IsNull(result.User);
    }

    [Test]
    public void LoginTeacher_EmailConEspaciosAlrededor_DebeAutenticar()
    {
        using var context = new TeacherLoginTestContext();
        context.SeedTeacher("Sofia Rojas", PasswordHasher.HashPassword("clave123"), "sofia@correo.com");
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginTeacher("  sofia@correo.com  ", "clave123");

        Assert.IsTrue(result.IsSuccess);
        Assert.IsNotNull(result.User);
        Assert.AreEqual("Sofia Rojas", result.User.name);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginTeacher_DatosValidos_DebeRetornarUsuario()
    {
        using var context = new TeacherLoginTestContext();
        var expectedUser = context.SeedTeacher("Juan Mendez", PasswordHasher.HashPassword("miClave99"), "juan@correo.com");
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginTeacher("juan@correo.com", "miClave99");

        Assert.IsTrue(result.IsSuccess);
        Assert.IsNotNull(result.User);
        Assert.AreEqual(expectedUser.id_user, result.User.id_user);
        Assert.AreEqual("Juan Mendez", result.User.name);
        Assert.IsNull(result.NameError);
        Assert.IsNull(result.PasswordError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void AuthService_LoginTeacher_DebeIgnorarMayusculasYMinusculasEnEmail()
    {
        using var context = new TeacherLoginTestContext();
        var expectedUser = context.SeedTeacher("Maria Gonzalez", PasswordHasher.HashPassword("ClaveSegura1"), "maria@correo.com");

        var result = context.AuthService.LoginTeacher("MARIA@CORREO.COM", "ClaveSegura1");

        Assert.IsNotNull(result);
        Assert.AreEqual(expectedUser.id_user, result.id_user);
    }

    [Test]
    public void AuthService_LoginTeacher_NoDebeAutenticarUsuariosQueNoSeanProfesores()
    {
        using var context = new TeacherLoginTestContext();
        context.SeedStudent("Ana Garcia", PasswordHasher.HashPassword("clave123"));

        var result = context.AuthService.LoginTeacher("ana@correo.com", "clave123");

        Assert.IsNull(result, "El login de profesor solo debe autenticar usuarios con rol profesor.");
    }

    [Test]
    public void AuthService_LoginTeacher_ClaveLegacyCorrecta_DebeMigrarAPasswordHasheado()
    {
        using var context = new TeacherLoginTestContext();
        var user = context.SeedTeacher("Laura Sanchez", "textoPlano123", "laura@correo.com");

        var result = context.AuthService.LoginTeacher("laura@correo.com", "textoPlano123");
        string storedPassword = context.GetStoredPassword(user.id_user);

        Assert.IsNotNull(result);
        Assert.AreEqual(user.id_user, result.id_user);
        Assert.AreNotEqual("textoPlano123", storedPassword);
        Assert.IsTrue(PasswordHasher.IsSha256Hash(storedPassword));
        Assert.AreEqual(storedPassword, result.password);
    }

    [Test]
    public void AuthService_LoginTeacher_ClaveLegacyIncorrecta_NoDebeMigrarPassword()
    {
        using var context = new TeacherLoginTestContext();
        var user = context.SeedTeacher("Laura Sanchez", "textoPlano123", "laura@correo.com");

        var result = context.AuthService.LoginTeacher("laura@correo.com", "otraClave");
        string storedPassword = context.GetStoredPassword(user.id_user);

        Assert.IsNull(result);
        Assert.AreEqual("textoPlano123", storedPassword);
    }

    [Test]
    public void AuthService_LoginTeacher_ClaveHasheadaCorrecta_NoDebeCambiarPasswordPersistido()
    {
        using var context = new TeacherLoginTestContext();
        string originalHash = PasswordHasher.HashPassword("miClaveSegura");
        var user = context.SeedTeacher("Pedro Fernandez", originalHash, "pedro@correo.com");

        var result = context.AuthService.LoginTeacher("pedro@correo.com", "miClaveSegura");
        string storedPassword = context.GetStoredPassword(user.id_user);

        Assert.IsNotNull(result);
        Assert.AreEqual(originalHash, storedPassword);
        Assert.AreEqual(originalHash, result.password);
    }

    [Test]
    public void AuthService_UpdateLastLogin_DebePersistirLaFechaActual()
    {
        using var context = new TeacherLoginTestContext();
        var user = context.SeedTeacher("Valentina Torres", PasswordHasher.HashPassword("clave123"), "valentina@correo.com");
        string expectedDate = DateTime.Now.ToString("dd/MM/yyyy");

        context.AuthService.UpdateLastLogin(user.id_user);

        var reloadedUser = context.Repository.GetUserById(user.id_user);
        Assert.AreEqual(expectedDate, reloadedUser.last_login);
    }

    [Test]
    public void LoginTeacher_EmailNulo_DebeRetornarErrorDeEmail()
    {
        using var context = new TeacherLoginTestContext();

        var result = context.Presenter.LoginTeacher(null, "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu correo electrónico.", result.NameError);
    }

    [Test]
    public void LoginTeacher_ContraseinaNula_DebeRetornarErrorDeContrasena()
    {
        using var context = new TeacherLoginTestContext();

        var result = context.Presenter.LoginTeacher("profesor@correo.com", null);

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("La contraseña no es correcta. Inténtalo otra vez.", result.PasswordError);
    }

    private static void ResetSessionManager()
    {
        if (UserSessionManager.Instance != null)
        {
            UnityEngine.Object.DestroyImmediate(UserSessionManager.Instance.gameObject);
        }

        FieldInfo instanceField = typeof(UserSessionManager)
            .GetField("<Instance>k__BackingField", BindingFlags.Static | BindingFlags.NonPublic);

        instanceField?.SetValue(null, null);
    }

    private sealed class TeacherLoginTestContext : IDisposable
    {
        private readonly string databasePath;

        public SQLiteConnection Connection { get; }
        public UserRepository Repository { get; }
        public AuthService AuthService { get; }
        public LoginPresenter Presenter { get; }

        public TeacherLoginTestContext()
        {
            databasePath = Path.Combine(@"C:\tmp", $"teacher-login-tests-{Guid.NewGuid():N}.db");
            Connection = new SQLiteConnection(databasePath);
            Connection.CreateTable<UserModel>();
            Connection.CreateTable<StudentModel>();
            Connection.CreateTable<TeacherModel>();

            Repository = new UserRepository(Connection);
            AuthService = new AuthService(Repository);
            Presenter = new LoginPresenter(AuthService);
        }

        public UserModel SeedStudent(string name, string storedPassword)
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

            return user;
        }

        public UserModel SeedTeacher(string name, string storedPassword, string email)
        {
            UserModel user = new UserModel
            {
                name = name,
                id_degree = 1,
                password = storedPassword,
                id_role = 2,
                id_security_question = 0,
                security_asnwer_hash = string.Empty,
                last_login = string.Empty
            };

            Repository.InsertUser(user);
            Repository.InsertTeacher(new TeacherModel
            {
                id_user = user.id_user,
                email = email
            });

            return user;
        }

        public string GetStoredPassword(int userId)
        {
            return Repository.GetUserById(userId)?.password;
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
