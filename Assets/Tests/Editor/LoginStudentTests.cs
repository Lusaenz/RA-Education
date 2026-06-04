using System;
using System.IO;
using System.Reflection;
using NUnit.Framework;
using SQLite4Unity3d;
using UnityEngine;
using UnityEngine.TestTools;

/// <summary>
/// Tests del flujo de login para estudiantes.
/// Cubre validaciones del presenter, autenticación, migración de contraseñas legacy
/// y actualización de último login usando una BD SQLite temporal.
/// </summary>
public class LoginStudentTests
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
    public void LoginStudent_NombreVacio_DebeRetornarErrorDeNombre()
    {
        using var context = new StudentLoginTestContext();

        var result = context.Presenter.LoginStudent("", "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu nombre completo.", result.NameError);
        Assert.IsNull(result.PasswordError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginStudent_NombreConSoloEspacios_DebeRetornarErrorDeNombre()
    {
        using var context = new StudentLoginTestContext();

        var result = context.Presenter.LoginStudent("   ", "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu nombre completo.", result.NameError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginStudent_ContrasenaVacia_DebeRetornarErrorDeContrasena()
    {
        using var context = new StudentLoginTestContext();

        var result = context.Presenter.LoginStudent("Ana Garcia", "");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu contraseña.", result.PasswordError);
        Assert.IsNull(result.NameError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginStudent_CamposVacios_DebeRetornarAmbosErrores()
    {
        using var context = new StudentLoginTestContext();

        var result = context.Presenter.LoginStudent("", "");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("Escribe tu nombre completo.", result.NameError);
        Assert.AreEqual("Escribe tu contraseña.", result.PasswordError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginStudent_EstudianteInexistente_DebeRetornarMensajeGeneral()
    {
        using var context = new StudentLoginTestContext();

        var result = context.Presenter.LoginStudent("Nadie Existe", "clave123");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("No encontramos tu cuenta. Revisa tus datos o regístrate", result.GeneralMessage);
        Assert.IsNull(result.User);
    }

    [Test]
    public void LoginStudent_ContrasenaIncorrecta_DebeRetornarMensajeGeneral()
    {
        using var context = new StudentLoginTestContext();
        context.SeedStudent("Ana Garcia", PasswordHasher.HashPassword("claveCorrecta"));

        var result = context.Presenter.LoginStudent("Ana Garcia", "claveIncorrecta");

        Assert.IsFalse(result.IsSuccess);
        Assert.AreEqual("No encontramos tu cuenta. Revisa tus datos o regístrate", result.GeneralMessage);
        Assert.IsNull(result.User);
    }

    [Test]
    public void LoginStudent_NombreConEspaciosAlrededor_DebeAutenticar()
    {
        using var context = new StudentLoginTestContext();
        context.SeedStudent("Ana Garcia", PasswordHasher.HashPassword("clave123"));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent("  Ana Garcia  ", "clave123");

        Assert.IsTrue(result.IsSuccess);
        Assert.IsNotNull(result.User);
        Assert.AreEqual("Ana Garcia", result.User.name);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void LoginStudent_DatosValidos_DebeRetornarUsuario()
    {
        using var context = new StudentLoginTestContext();
        var expectedUser = context.SeedStudent("Juan Perez", PasswordHasher.HashPassword("miClave99"));
        LogAssert.Expect(LogType.Error, "UserSessionManager no está disponible.");

        var result = context.Presenter.LoginStudent("Juan Perez", "miClave99");

        Assert.IsTrue(result.IsSuccess);
        Assert.IsNotNull(result.User);
        Assert.AreEqual(expectedUser.id_user, result.User.id_user);
        Assert.AreEqual("Juan Perez", result.User.name);
        Assert.IsNull(result.NameError);
        Assert.IsNull(result.PasswordError);
        Assert.IsNull(result.GeneralMessage);
    }

    [Test]
    public void AuthService_LoginStudent_DebeIgnorarMayusculasYMinusculasEnNombre()
    {
        using var context = new StudentLoginTestContext();
        var expectedUser = context.SeedStudent("Maria Lopez", PasswordHasher.HashPassword("ClaveSegura1"));

        var result = context.AuthService.LoginStudent("mArIa lOpEz", "ClaveSegura1");

        Assert.IsNotNull(result);
        Assert.AreEqual(expectedUser.id_user, result.id_user);
    }

    [Test]
    public void AuthService_LoginStudent_NoDebeAutenticarUsuariosQueNoSeanEstudiantes()
    {
        using var context = new StudentLoginTestContext();
        context.SeedTeacher("Carlos Ruiz", PasswordHasher.HashPassword("clave123"), "carlos@correo.com");

        var result = context.AuthService.LoginStudent("Carlos Ruiz", "clave123");

        Assert.IsNull(result, "El login de estudiante solo debe autenticar usuarios con rol estudiante.");
    }

    [Test]
    public void AuthService_LoginStudent_ClaveLegacyCorrecta_DebeMigrarAPasswordHasheado()
    {
        using var context = new StudentLoginTestContext();
        var user = context.SeedStudent("Laura Diaz", "textoPlano123");

        var result = context.AuthService.LoginStudent("Laura Diaz", "textoPlano123");
        string storedPassword = context.GetStoredPassword(user.id_user);

        Assert.IsNotNull(result);
        Assert.AreEqual(user.id_user, result.id_user);
        Assert.AreNotEqual("textoPlano123", storedPassword);
        Assert.IsTrue(PasswordHasher.IsSha256Hash(storedPassword));
        Assert.AreEqual(storedPassword, result.password);
    }

    [Test]
    public void AuthService_LoginStudent_ClaveLegacyIncorrecta_NoDebeMigrarPassword()
    {
        using var context = new StudentLoginTestContext();
        var user = context.SeedStudent("Laura Diaz", "textoPlano123");

        var result = context.AuthService.LoginStudent("Laura Diaz", "otraClave");
        string storedPassword = context.GetStoredPassword(user.id_user);

        Assert.IsNull(result);
        Assert.AreEqual("textoPlano123", storedPassword);
    }

    [Test]
    public void AuthService_LoginStudent_ClaveHasheadaCorrecta_NoDebeCambiarPasswordPersistido()
    {
        using var context = new StudentLoginTestContext();
        string originalHash = PasswordHasher.HashPassword("miClaveSegura");
        var user = context.SeedStudent("Pedro Gomez", originalHash);

        var result = context.AuthService.LoginStudent("Pedro Gomez", "miClaveSegura");
        string storedPassword = context.GetStoredPassword(user.id_user);

        Assert.IsNotNull(result);
        Assert.AreEqual(originalHash, storedPassword);
        Assert.AreEqual(originalHash, result.password);
    }

    [Test]
    public void AuthService_UpdateLastLogin_DebePersistirLaFechaActual()
    {
        using var context = new StudentLoginTestContext();
        var user = context.SeedStudent("Sofia Rojas", PasswordHasher.HashPassword("clave123"));
        string expectedDate = DateTime.Now.ToString("dd/MM/yyyy");

        context.AuthService.UpdateLastLogin(user.id_user);

        var reloadedUser = context.Repository.GetUserById(user.id_user);
        Assert.AreEqual(expectedDate, reloadedUser.last_login);
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

    private sealed class StudentLoginTestContext : IDisposable
    {
        private readonly string databasePath;

        public SQLiteConnection Connection { get; }
        public UserRepository Repository { get; }
        public AuthService AuthService { get; }
        public LoginPresenter Presenter { get; }

        public StudentLoginTestContext()
        {
            databasePath = Path.Combine(@"C:\tmp", $"student-login-tests-{Guid.NewGuid():N}.db");
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
