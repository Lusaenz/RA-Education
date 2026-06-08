using System;
using System.IO;
using NUnit.Framework;
using SQLite4Unity3d;
using UnityEngine;

/// <summary>
/// Tests unitarios para UserRepository.
/// Cubre operaciones de lectura, escritura y actualización de usuarios en la BD.
/// </summary>
public class UserRepositoryTests
{
    [Test]
    public void Constructor_ConexionNull_DebeLanzarArgumentNullException()
    {
        Assert.Throws<ArgumentNullException>(() => new UserRepository(null));
    }

    [Test]
    public void InsertUser_UsuarioValido_DebeInsertarCorrectamente()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Ana Garcia",
            id_degree = 1,
            password = "clave123",
            id_role = 1,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };

        context.Repository.InsertUser(user);
        var retrieved = context.Repository.GetUserById(user.id_user);

        Assert.IsNotNull(retrieved);
        Assert.AreEqual("Ana Garcia", retrieved.name);
    }

    [Test]
    public void LoginStudent_EstudianteExistente_DebeEncontrar()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Juan Perez",
            id_degree = 1,
            password = "clave123",
            id_role = 1,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);

        var result = context.Repository.LoginStudent("Juan Perez");

        Assert.IsNotNull(result);
        Assert.AreEqual("Juan Perez", result.name);
        Assert.AreEqual(1, result.id_role);
    }

    [Test]
    public void LoginStudent_NoExiste_DebeRetornarNull()
    {
        using var context = new RepositoryTestContext();

        var result = context.Repository.LoginStudent("NoExiste");

        Assert.IsNull(result);
    }

    [Test]
    public void LoginStudent_ConProfesor_NoDebeEncontrar()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Carlos Ruiz",
            id_degree = 1,
            password = "clave123",
            id_role = 2, // Profesor
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);

        var result = context.Repository.LoginStudent("Carlos Ruiz");

        Assert.IsNull(result, "LoginStudent no debe encontrar profesores");
    }

    [Test]
    public void LoginStudent_CaseInsensitive_DebeEncontrar()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Maria Lopez",
            id_degree = 1,
            password = "clave123",
            id_role = 1,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);

        var result = context.Repository.LoginStudent("maria lopez");

        Assert.IsNotNull(result);
        Assert.AreEqual("Maria Lopez", result.name);
    }

    [Test]
    public void LoginTeacher_ProfesorExistente_DebeEncontrar()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Sofia Gomez",
            id_degree = 1,
            password = "clave123",
            id_role = 2,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);
        var teacher = new TeacherModel
        {
            id_user = user.id_user,
            email = "sofia@correo.com"
        };
        context.Repository.InsertTeacher(teacher);

        var result = context.Repository.LoginTeacher("sofia@correo.com");

        Assert.IsNotNull(result);
        Assert.AreEqual("Sofia Gomez", result.name);
        Assert.AreEqual(2, result.id_role);
    }

    [Test]
    public void LoginTeacher_NoExiste_DebeRetornarNull()
    {
        using var context = new RepositoryTestContext();

        var result = context.Repository.LoginTeacher("noexiste@correo.com");

        Assert.IsNull(result);
    }

    [Test]
    public void LoginTeacher_ConEstudiante_NoDebeEncontrar()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Pedro Rodriguez",
            id_degree = 1,
            password = "clave123",
            id_role = 1, // Estudiante
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);

        // Intentar buscar como si fuera profesor
        var result = context.Repository.LoginTeacher("pedro@correo.com");

        Assert.IsNull(result, "LoginTeacher no debe encontrar estudiantes");
    }

    [Test]
    public void UpdateUserPassword_DebeActualizarContraseña()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Valentina Torres",
            id_degree = 1,
            password = "claveAntigua",
            id_role = 1,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);
        string newPassword = PasswordHasher.HashPassword("claveNueva");

        context.Repository.UpdateUserPassword(user.id_user, newPassword);
        var updated = context.Repository.GetUserById(user.id_user);

        Assert.AreEqual(newPassword, updated.password);
    }

    [Test]
    public void UpdateLastLogin_DebeActualizarFecha()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Camila Flores",
            id_degree = 1,
            password = "clave123",
            id_role = 1,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);
        string newDate = "15/06/2026";

        context.Repository.UpdateLastLogin(user.id_user, newDate);
        var updated = context.Repository.GetUserById(user.id_user);

        Assert.AreEqual(newDate, updated.last_login);
    }

    [Test]
    public void GetUserById_UsuarioExistente_DebeRetornarUsuario()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Daniela Silva",
            id_degree = 1,
            password = "clave123",
            id_role = 1,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);

        var result = context.Repository.GetUserById(user.id_user);

        Assert.IsNotNull(result);
        Assert.AreEqual("Daniela Silva", result.name);
    }

    [Test]
    public void GetUserById_NoExiste_DebeRetornarNull()
    {
        using var context = new RepositoryTestContext();

        var result = context.Repository.GetUserById(9999);

        Assert.IsNull(result);
    }

    [Test]
    public void InserStudent_EstudianteValido_DebeInsertarCorrectamente()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Elena Morales",
            id_degree = 1,
            password = "clave123",
            id_role = 1,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);
        var student = new StudentModel
        {
            id_user = user.id_user,
            age = 15
        };

        context.Repository.InserStudent(student);

        // Verificar que se insertó consultando la tabla
        var retrievedStudent = context.Connection.Table<StudentModel>()
            .Where(s => s.id_user == user.id_user).FirstOrDefault();
        Assert.IsNotNull(retrievedStudent);
        Assert.AreEqual(15, retrievedStudent.age);
    }

    [Test]
    public void InsertTeacher_ProfesorValido_DebeInsertarCorrectamente()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Francesca Romano",
            id_degree = 1,
            password = "clave123",
            id_role = 2,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);
        var teacher = new TeacherModel
        {
            id_user = user.id_user,
            email = "francesca@correo.com"
        };

        context.Repository.InsertTeacher(teacher);

        var retrievedTeacher = context.Connection.Table<TeacherModel>()
            .Where(t => t.id_user == user.id_user).FirstOrDefault();
        Assert.IsNotNull(retrievedTeacher);
        Assert.AreEqual("francesca@correo.com", retrievedTeacher.email);
    }

    [Test]
    public void UpdateUserSecurityQuestion_DebeActualizarPregunta()
    {
        using var context = new RepositoryTestContext();
        var user = new UserModel
        {
            name = "Gabriela Costa",
            id_degree = 1,
            password = "clave123",
            id_role = 1,
            id_security_question = 0,
            security_asnwer_hash = "",
            last_login = ""
        };
        context.Repository.InsertUser(user);
        string encryptedAnswer = "encriptedValue123";

        context.Repository.UpdateUserSecurityQuestion(user.id_user, 2, encryptedAnswer);
        var updated = context.Repository.GetUserById(user.id_user);

        Assert.AreEqual(2, updated.id_security_question);
        Assert.AreEqual(encryptedAnswer, updated.security_asnwer_hash);
    }

    private sealed class RepositoryTestContext : IDisposable
    {
        private readonly string databasePath;

        public SQLiteConnection Connection { get; }
        public UserRepository Repository { get; }

        public RepositoryTestContext()
        {
            databasePath = Path.Combine(@"C:\tmp", $"repo-tests-{Guid.NewGuid():N}.db");
            Connection = new SQLiteConnection(databasePath);
            Connection.CreateTable<UserModel>();
            Connection.CreateTable<StudentModel>();
            Connection.CreateTable<TeacherModel>();

            Repository = new UserRepository(Connection);
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
