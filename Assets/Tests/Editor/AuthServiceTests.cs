using System;
using System.IO;
using NUnit.Framework;
using SQLite4Unity3d;
using UnityEngine;

/// <summary>
/// Tests unitarios para AuthService.
/// Cubre autenticación, registro, preguntas de seguridad y manejo de sesiones.
/// </summary>
public class AuthServiceTests
{
    [Test]
    public void Constructor_RepositoryNull_DebeLanzarArgumentNullException()
    {
        Assert.Throws<ArgumentNullException>(() => new AuthService(null));
    }

    [Test]
    public void LoginStudent_EstudianteNoExiste_DebeRetornarNull()
    {
        using var context = new AuthServiceTestContext();

        var result = context.AuthService.LoginStudent("NoExiste", "clave123");

        Assert.IsNull(result);
    }

    [Test]
    public void LoginStudent_ConCredencialesCorrectas_DebeRetornarUsuario()
    {
        using var context = new AuthServiceTestContext();
        var expectedUser = context.SeedStudent("Ana Garcia", "clave123");

        var result = context.AuthService.LoginStudent("Ana Garcia", "clave123");

        Assert.IsNotNull(result);
        Assert.AreEqual(expectedUser.id_user, result.id_user);
        Assert.AreEqual("Ana Garcia", result.name);
    }

    [Test]
    public void LoginTeacher_ProfesorNoExiste_DebeRetornarNull()
    {
        using var context = new AuthServiceTestContext();

        var result = context.AuthService.LoginTeacher("noexiste@correo.com", "clave123");

        Assert.IsNull(result);
    }

    [Test]
    public void LoginTeacher_ConCredencialesCorrectas_DebeRetornarUsuario()
    {
        using var context = new AuthServiceTestContext();
        var expectedUser = context.SeedTeacher("Carlos Ruiz", "clave123", "carlos@correo.com");

        var result = context.AuthService.LoginTeacher("carlos@correo.com", "clave123");

        Assert.IsNotNull(result);
        Assert.AreEqual(expectedUser.id_user, result.id_user);
        Assert.AreEqual("Carlos Ruiz", result.name);
    }

    [Test]
    public void RegisterStudent_DatosValidos_DebeCrearUsuarioYEstudiante()
    {
        using var context = new AuthServiceTestContext();

        var result = context.AuthService.RegisterStudent("Juan Perez", 1, 15, "miClave123");

        Assert.IsNotNull(result);
        Assert.Greater(result.id_user, 0, "El ID de usuario debe ser mayor a 0");
        Assert.AreEqual("Juan Perez", result.name);
        Assert.AreEqual(1, result.id_role, "El rol debe ser estudiante (1)");

        // Verificar que puede loguearse
        var loginResult = context.AuthService.LoginStudent("Juan Perez", "miClave123");
        Assert.IsNotNull(loginResult);
    }

    [Test]
    public void RegisterStudent_ContraseñaHasheada_DebeAlmacenarHashSHA256()
    {
        using var context = new AuthServiceTestContext();

        var result = context.AuthService.RegisterStudent("Maria Lopez", 1, 14, "claveSegura99");

        Assert.IsTrue(PasswordHasher.IsSha256Hash(result.password), "La contraseña debe estar hasheada en SHA256");
    }

    [Test]
    public void RegisterTeacher_DatosValidos_DebeCrearUsuarioYProfesor()
    {
        using var context = new AuthServiceTestContext();

        var result = context.AuthService.RegisterTeacher("Sofia Gomez", 1, "contraseña456", "sofia@escuela.com");

        Assert.IsNotNull(result);
        Assert.Greater(result.id_user, 0);
        Assert.AreEqual("Sofia Gomez", result.name);
        Assert.AreEqual(2, result.id_role, "El rol debe ser profesor (2)");

        // Verificar que puede loguearse
        var loginResult = context.AuthService.LoginTeacher("sofia@escuela.com", "contraseña456");
        Assert.IsNotNull(loginResult);
    }

    [Test]
    public void RegisterTeacher_ContraseñaHasheada_DebeAlmacenarHashSHA256()
    {
        using var context = new AuthServiceTestContext();

        var result = context.AuthService.RegisterTeacher("Luis Martinez", 1, "seguridad789", "luis@escuela.com");

        Assert.IsTrue(PasswordHasher.IsSha256Hash(result.password), "La contraseña debe estar hasheada en SHA256");
    }

    [Test]
    public void UpdateLastLogin_UsuarioExistente_DebeActualizarFecha()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Pedro Rodriguez", "clave123");
        string expectedDate = DateTime.Now.ToString("dd/MM/yyyy");

        context.AuthService.UpdateLastLogin(user.id_user);

        var updatedUser = context.Repository.GetUserById(user.id_user);
        Assert.AreEqual(expectedDate, updatedUser.last_login);
    }

    [Test]
    public void UpdateLastLogin_MultiplesVeces_DebePersistirUltimaFecha()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Valentina Torres", "clave123");

        // Primera actualización
        context.AuthService.UpdateLastLogin(user.id_user);
        var date1 = context.Repository.GetUserById(user.id_user).last_login;

        // Pequeña espera para verificar que se persiste correctamente
        System.Threading.Thread.Sleep(100);

        // Segunda actualización
        context.AuthService.UpdateLastLogin(user.id_user);
        var date2 = context.Repository.GetUserById(user.id_user).last_login;

        // Ambas fechas deben ser hoy (a menos que se ejecute justo antes de cambio de día)
        string today = DateTime.Now.ToString("dd/MM/yyyy");
        Assert.AreEqual(today, date1);
        Assert.AreEqual(today, date2);
    }

    [Test]
    public void FindUserByNameAndRole_EstudianteExistente_DebeEncontrar()
    {
        using var context = new AuthServiceTestContext();
        var expectedUser = context.SeedStudent("Monica Ramos", "clave123");

        var result = context.AuthService.FindUserByNameAndRole("Monica Ramos", 1);

        Assert.IsNotNull(result);
        Assert.AreEqual(expectedUser.id_user, result.id_user);
    }

    [Test]
    public void FindUserByNameAndRole_ProfesorExistente_DebeEncontrar()
    {
        using var context = new AuthServiceTestContext();
        var expectedUser = context.SeedTeacher("Roberto Hernandez", "clave123", "roberto@correo.com");

        var result = context.AuthService.FindUserByNameAndRole("Roberto Hernandez", 2);

        Assert.IsNotNull(result);
        Assert.AreEqual(expectedUser.id_user, result.id_user);
    }

    [Test]
    public void FindUserByNameAndRole_NoExiste_DebeRetornarNull()
    {
        using var context = new AuthServiceTestContext();

        var result = context.AuthService.FindUserByNameAndRole("NoExiste", 1);

        Assert.IsNull(result);
    }

    [Test]
    public void FindUserByNameAndRole_NombreIncorrecto_DebeRetornarNull()
    {
        using var context = new AuthServiceTestContext();
        context.SeedStudent("Isabel Diaz", "clave123");

        var result = context.AuthService.FindUserByNameAndRole("Isabel", 1);

        Assert.IsNull(result, "Debe hacer búsqueda exacta, no parcial");
    }

    [Test]
    public void SaveSecurityQuestion_UsuarioExistente_DebePersistirPregunta()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Camila Flores", "clave123");
        int questionId = 1;
        string answer = "MiRespuesta";

        context.AuthService.SaveSecurityQuestion(user.id_user, questionId, answer);

        var updatedUser = context.Repository.GetUserById(user.id_user);
        Assert.AreEqual(questionId, updatedUser.id_security_question);
        Assert.IsNotEmpty(updatedUser.security_asnwer_hash, "La respuesta debe estar cifrada");
    }

    [Test]
    public void SaveSecurityQuestion_RespuestaVacia_DebeLanzarExcepcion()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Daniela Silva", "clave123");

        Assert.Throws<ArgumentException>(() =>
            context.AuthService.SaveSecurityQuestion(user.id_user, 1, ""));
    }

    [Test]
    public void SaveSecurityQuestion_RespuestaNula_DebeLanzarExcepcion()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Elena Morales", "clave123");

        Assert.Throws<ArgumentException>(() =>
            context.AuthService.SaveSecurityQuestion(user.id_user, 1, null));
    }

    [Test]
    public void VerifySecurityAnswer_RespuestaCorrecta_DebeRetornarTrue()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Francesca Romano", "clave123");
        string answer = "MiMascota";
        context.AuthService.SaveSecurityQuestion(user.id_user, 1, answer);

        bool result = context.AuthService.VerifySecurityAnswer(user.id_user, answer);

        Assert.IsTrue(result);
    }

    [Test]
    public void VerifySecurityAnswer_RespuestaIncorrecta_DebeRetornarFalse()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Gabriela Costa", "clave123");
        context.AuthService.SaveSecurityQuestion(user.id_user, 1, "RespuestaCorrecta");

        bool result = context.AuthService.VerifySecurityAnswer(user.id_user, "RespuestaIncorrecta");

        Assert.IsFalse(result);
    }

    [Test]
    public void VerifySecurityAnswer_UsuarioSinPregunta_DebeRetornarFalse()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Hilary Nelson", "clave123");

        bool result = context.AuthService.VerifySecurityAnswer(user.id_user, "Cualquier");

        Assert.IsFalse(result);
    }

    [Test]
    public void VerifySecurityAnswer_RespuestaNula_DebeRetornarFalse()
    {
        using var context = new AuthServiceTestContext();
        var user = context.SeedStudent("Iris Moreno", "clave123");
        context.AuthService.SaveSecurityQuestion(user.id_user, 1, "Respuesta");

        bool result = context.AuthService.VerifySecurityAnswer(user.id_user, null);

        Assert.IsFalse(result);
    }

    [Test]
    public void LoginStudent_ContraseñaVacia_DebeRetornarNull()
    {
        using var context = new AuthServiceTestContext();
        context.SeedStudent("Jasmine Brown", "clave123");

        var result = context.AuthService.LoginStudent("Jasmine Brown", "");

        Assert.IsNull(result);
    }

    [Test]
    public void LoginTeacher_ContraseñaVacia_DebeRetornarNull()
    {
        using var context = new AuthServiceTestContext();
        context.SeedTeacher("Kevin White", "clave123", "kevin@correo.com");

        var result = context.AuthService.LoginTeacher("kevin@correo.com", "");

        Assert.IsNull(result);
    }

    private sealed class AuthServiceTestContext : IDisposable
    {
        private readonly string databasePath;

        public SQLiteConnection Connection { get; }
        public UserRepository Repository { get; }
        public AuthService AuthService { get; }

        public AuthServiceTestContext()
        {
            databasePath = Path.Combine(@"C:\tmp", $"auth-service-tests-{Guid.NewGuid():N}.db");
            Connection = new SQLiteConnection(databasePath);
            Connection.CreateTable<UserModel>();
            Connection.CreateTable<StudentModel>();
            Connection.CreateTable<TeacherModel>();

            Repository = new UserRepository(Connection);
            AuthService = new AuthService(Repository);
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
