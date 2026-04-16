# Guía de Integración - Sistema de Preguntas de Seguridad y Login

## Descripción General

Se ha implementado un sistema completo de autenticación con:
- ✅ Selección de grados a través de Service/Repository
- ✅ Selección de preguntas de seguridad
- ✅ Respuestas de seguridad cifradas con SHA256
- ✅ Registro de último login (`last_login`)
- ✅ Arquitectura limpia: Service → Repository → Database

---

## Arquitectura Implementada

### Componentes Creados

1. **SecurityQuestionsRepository.cs** - Acceso a BD para preguntas de seguridad
2. **SecurityQuestionsService.cs** - Servicio de dominio para preguntas
3. **DegreeSelector.cs (refactorizado)** - Selector con Services en lugar de conexión directa
4. **UserRepository (actualizado)** - Nuevos métodos para seguridad y último login
5. **AuthService (actualizado)** - Métodos para cifrar respuestas y actualizar login
6. **RegisterPresenter (actualizado)** - Integración de preguntas de seguridad

---

## Flujo de Registro Completo

### Paso 1: Seleccionar Grado
```csharp
DegreeSelector selector = GetComponent<DegreeSelector>();

// El usuario selecciona un grado desde el panel
// El selector automáticamente guarda:
// - selectedDegreeId
// - selectedDegreeName

// Validar si se seleccionó
if (!selector.IsDegreeSelected())
{
    Debug.LogError("Grado no seleccionado");
    return;
}

int degreeId = selector.GetSelectedDegreeId();
```

### Paso 2: Seleccionar Pregunta de Seguridad
```csharp
// El usuario selecciona una pregunta de seguridad desde el panel
// El selector automáticamente:
// - Muestra el input oculto para la respuesta
// - Guarda el ID de la pregunta

// Validar si se seleccionó
if (!selector.IsSecurityQuestionSelected())
{
    Debug.LogError("Pregunta de seguridad no seleccionada");
    return;
}

int questionId = selector.GetSelectedSecurityQuestionId();
string answer = selector.GetSecurityAnswer();

if (!selector.IsSecurityAnswerProvided())
{
    Debug.LogError("Respuesta de seguridad no proporcionada");
    return;
}
```

### Paso 3: Registrar Estudiante
```csharp
RegisterPresenter registerPresenter = GetComponent<RegisterPresenter>();

// Registrar al estudiante
RegisterResult result = registerPresenter.RegisterStudent(
    degreeId: degreeId,
    name: "Juan Pérez",
    ageText: "20",
    pass: "MiContraseña123"
);

if (!result.Success)
{
    Debug.LogError($"Error en registro: {result.ErrorMessage}");
    return;
}

// Obtener el ID del usuario registrado (necesario para siguiente paso)
// Nota: Asegúrate de que RegisterStudent retorne el ID del usuario
```

### Paso 4: Guardar Pregunta de Seguridad
```csharp
// Después del registro exitoso, guardar la pregunta de seguridad
RegisterResult securityResult = registerPresenter.ValidateAndSaveSecurityQuestion(
    userId: userIdRecienRegistrado,
    questionId: questionId,
    answer: answer
);

if (!securityResult.Success)
{
    Debug.LogError($"Error al guardar pregunta de seguridad: {securityResult.ErrorMessage}");
    return;
}

Debug.Log("Pregunta de seguridad guardada correctamente");
```

### Paso 5: Actualizar Último Login
```csharp
// Finalmente, actualizar el último login
registerPresenter.UpdateLastLoginForUser(userIdRecienRegistrado);

Debug.Log("Registro completado exitosamente");
```

---

## Ejemplo Completo de Presentador

```csharp
using UnityEngine;

/// <summary>
/// Ejemplo de presentador que integra todo el flujo de registro con seguridad.
/// </summary>
public class MiPresentadorRegistro : MonoBehaviour
{
    [SerializeField] private TMP_InputField nombreInput;
    [SerializeField] private TMP_InputField edadInput;
    [SerializeField] private TMP_InputField passwordInput;
    [SerializeField] private Text mensajeError;
    
    private RegisterPresenter registerPresenter;
    private DegreeSelector degreeSelector;

    void Start()
    {
        registerPresenter = GetComponent<RegisterPresenter>();
        degreeSelector = GetComponent<DegreeSelector>();
    }

    public void RegistrarEstudiante()
    {
        // Paso 1: Validar selecciones
        if (!degreeSelector.IsDegreeSelected())
        {
            MostrarError("Selecciona un grado");
            return;
        }

        if (!degreeSelector.IsSecurityQuestionSelected())
        {
            MostrarError("Selecciona una pregunta de seguridad");
            return;
        }

        if (!degreeSelector.IsSecurityAnswerProvided())
        {
            MostrarError("Proporciona una respuesta de seguridad");
            return;
        }

        // Paso 2: Realizar registro
        RegisterResult result = registerPresenter.RegisterStudent(
            degreeId: degreeSelector.GetSelectedDegreeId(),
            name: nombreInput.text,
            ageText: edadInput.text,
            pass: passwordInput.text
        );

        if (!result.Success)
        {
            MostrarError(result.ErrorMessage);
            return;
        }

        // Paso 3: Guardar pregunta de seguridad
        // ⚠️ NOTA: Necesitas obtener el userId del usuario registrado
        // Esto requiere modificar AuthService.RegisterStudent para retornar el ID
        
        int userId = ObtenerIdDelUsuarioRegistrado(); // Implementar este método
        
        RegisterResult securityResult = registerPresenter.ValidateAndSaveSecurityQuestion(
            userId: userId,
            questionId: degreeSelector.GetSelectedSecurityQuestionId(),
            answer: degreeSelector.GetSecurityAnswer()
        );

        if (!securityResult.Success)
        {
            MostrarError(securityResult.ErrorMessage);
            return;
        }

        // Paso 4: Actualizar último login
        registerPresenter.UpdateLastLoginForUser(userId);

        // Éxito
        LimpiarFormulario();
        MostrarMensaje("¡Registro exitoso!");
    }

    private void MostrarError(string mensaje)
    {
        mensajeError.text = mensaje;
        mensajeError.color = Color.red;
    }

    private void MostrarMensaje(string mensaje)
    {
        mensajeError.text = mensaje;
        mensajeError.color = Color.green;
    }

    private void LimpiarFormulario()
    {
        nombreInput.text = "";
        edadInput.text = "";
        passwordInput.text = "";
        degreeSelector.ResetAllSelections();
    }

    private int ObtenerIdDelUsuarioRegistrado()
    {
        // ⚠️ TODO: Necesitas implementar una forma de obtener esto
        // Opción 1: Modificar AuthService para retornar el UserModel
        // Opción 2: Crear un método en RegisterPresenter que retorne el último usuario
        return -1;
    }
}
```

---

## Pendiente: Obtener ID de Usuario Registrado

**Problema**: Después de llamar `RegisterStudent()`, necesitamos el ID del usuario registrado.

**Soluciones sugeridas**:

### Opción 1: Modificar AuthService (Recomendado)
```csharp
// En AuthService.cs, cambiar RegisterStudent para retornar UserModel
public UserModel RegisterStudent(string name, int degreeId, int age, string pass)
{
    UserModel u = new UserModel
    {
        name = name,
        id_degree = degreeId,
        password = PasswordHasher.HashPassword(pass),
        id_role = 1
    };

    userRepository.InsertUser(u); // Esto popula u.id_user
    
    StudentModel s = new StudentModel
    {
        id_user = u.id_user,
        age = age
    };
    userRepository.InserStudent(s);
    
    return u; // ← Retornar el modelo completo con ID generado
}
```

### Opción 2: Agregar método en RegisterPresenter
```csharp
public int GetLastRegisteredUserId()
{
    // Mantener track del último usuario registrado
}
```

---

## Panel de Preguntas de Seguridad - Configuración en Unity

En tu escena, necesitas:

1. **Panel de Grados** (ya existente):
   - GameObject: `DegreePanel`
   - Botones para cada grado
   - Input Field: `degreeInputField`

2. **Panel de Preguntas de Seguridad** (nuevo):
   - GameObject: `SecurityQuestionsPanel`
   - Botones para cada pregunta (el texto se llena automáticamente)
   - Input Field: `questionInputField` (mostrar la pregunta seleccionada)
   - Input Field: `answerInputField` (respuesta oculta - se muestra al seleccionar pregunta)

3. **Asignaciones en Inspector**:
   ```
   DegreeSelector (Script):
   - Degree Panel: [SecurityQuestionsPanel]
   - Degree Input Field: [Tu TMP_InputField de grado]
   - Panel Questions Security: [Tu SecurityQuestionsPanel]
   - Question Input Field: [Tu TMP_InputField de pregunta]
   - Answer Input Field: [Tu TMP_InputField de respuesta]
   ```

---

## Base de Datos - Campos Requeridos

### Tabla `users`
```sql
CREATE TABLE users (
    id_user INTEGER PRIMARY KEY AUTOINCREMENT,
    name TEXT,
    id_degree INTEGER,
    password TEXT,
    id_role INTEGER,
    id_security_question INTEGER,  -- ← Campo para pregunta de seguridad
    security_answer TEXT,           -- ← Respuesta cifrada
    last_login TEXT                 -- ← Último login (formato: "yyyy-MM-dd HH:mm:ss")
);
```

### Tabla `security_questions`
```sql
CREATE TABLE security_questions (
    id_question INTEGER PRIMARY KEY AUTOINCREMENT,
    question TEXT
);
```

---

## Confirmación de Funcionalidades

- ✅ **Security**: Respuestas cifradas con SHA256
- ✅ **Architecture**: Service → Repository → Database
- ✅ **UI**: Input oculto aparece al seleccionar pregunta
- ✅ **Last Login**: Se actualiza automáticamente al registrar
- ✅ **Validations**: Todas las entradas validadas

---

## Pruebas Sugeridas

1. Registrar un estudiante completo
2. Verificar que la pregunta de seguridad se guardó
3. Verificar que la respuesta está cifrada en la BD
4. Verificar que last_login tiene timestamp correcto
5. Intentar ingresar respuesta de seguridad incorrecta → debe fallar
6. Intentar ingresar respuesta correcta → debe pasar

---

## Notas Adicionales

- Las respuestas de seguridad se normalizan (lowercase, trim) antes de cifrar
- Asegúrate de tener datos en la tabla `security_questions`
- El `DegreeSelector` ahora usa Services, sin conexión directa a BD
- Todos los métodos están documentados con comentarios XML
