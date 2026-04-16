# API Reference - ForgotPassword System

## 📖 Referencia Completa de Métodos Públicos

---

## ForgotPasswordPresenter

### Clases Auxiliares

#### UserLookupResult
```csharp
public class UserLookupResult
{
    public bool Success { get; set; }
    public UserModel User { get; set; }
    public string ErrorMessage { get; set; }
}
```

#### PasswordResetResult
```csharp
public class PasswordResetResult
{
    public bool Success { get; set; }
    public string ErrorMessage { get; set; }
    public Dictionary<string, string> FieldErrors { get; set; }
}
```

#### SecurityQuestionInfo
```csharp
public class SecurityQuestionInfo
{
    public int QuestionId { get; set; }
    public string Question { get; set; }
}
```

### Métodos Públicos

#### Constructor
```csharp
public ForgotPasswordPresenter(AuthService auth, 
                               SecurityQuestionsService securityQuestions)
```
**Descripción**: Crea el presenter con inyección de dependencias.

**Parámetros**:
- `auth`: Servicio de autenticación
- `securityQuestions`: Servicio de preguntas de seguridad

**Excepciones**: Lanza `ArgumentNullException` si algún parámetro es null.

---

#### FindStudentByName
```csharp
public UserLookupResult FindStudentByName(string name)
```

**Descripción**: Busca un estudiante por nombre y valida que tenga pregunta de seguridad.

**Parámetros**:
- `name`: Nombre del estudiante (case-insensitive)

**Retorna**: 
- `UserLookupResult.Success = true` si encontró usuario válido
- `UserLookupResult.User` contiene los datos del usuario
- `UserLookupResult.ErrorMessage` contiene descripción de error si falla

**Validaciones**:
- Nombre no puede estar vacío
- Usuario debe existir en BD con rol de estudiante (id_role = 1)
- Usuario debe tener pregunta de seguridad configurada (id_security_question > 0)
- Usuario debe tener respuesta de seguridad guardada (security_answer_hash no vacío)

**Ejemplo**:
```csharp
var result = presenter.FindStudentByName("Juan");
if (result.Success)
{
    Debug.Log($"Usuario: {result.User.name}");
    Debug.Log($"ID Pregunta: {result.User.id_security_question}");
}
else
{
    Debug.Log($"Error: {result.ErrorMessage}");
}
```

---

#### GetSecurityQuestion
```csharp
public SecurityQuestionInfo GetSecurityQuestion(int questionId)
```

**Descripción**: Obtiene el texto de una pregunta de seguridad por ID.

**Parámetros**:
- `questionId`: ID de la pregunta en la BD

**Retorna**:
- `SecurityQuestionInfo` con ID y texto de la pregunta
- `null` si la pregunta no existe o hay error

**Ejemplo**:
```csharp
var question = presenter.GetSecurityQuestion(1);
if (question != null)
{
    Debug.Log($"Pregunta {question.QuestionId}: {question.Question}");
}
```

---

#### ResetPassword
```csharp
public PasswordResetResult ResetPassword(int userId, 
                                         string securityAnswer, 
                                         string newPassword)
```

**Descripción**: Valida y procesa el cambio de contraseña. Verifica la respuesta de seguridad antes de actualizar.

**Parámetros**:
- `userId`: ID del usuario (obtenido de FindStudentByName)
- `securityAnswer`: Respuesta ingresada por el usuario
- `newPassword`: Nueva contraseña deseada

**Retorna**:
- `PasswordResetResult.Success = true` si cambio fue exitoso
- `PasswordResetResult.FieldErrors` diccionario con errores por campo:
  - `FieldErrors["answer"]` - Error en respuesta de seguridad
  - `FieldErrors["password"]` - Error en contraseña nueva
- `PasswordResetResult.ErrorMessage` - Error general

**Validaciones**:
- Campos no pueden estar vacíos
- Respuesta se normaliza (lowercase + trim) antes de verificar
- Nueva contraseña debe tener 6-50 caracteres
- Respuesta debe coincidir exactamente con la registrada (después de normalización)

**Ejemplo**:
```csharp
var result = presenter.ResetPassword(
    userId: 1,
    securityAnswer: "BLUE",
    newPassword: "MyNewPass123"
);

if (result.Success)
{
    Debug.Log("✓ Contraseña cambiada exitosamente");
}
else
{
    if (result.FieldErrors.ContainsKey("answer"))
    {
        Debug.Log($"Error respuesta: {result.FieldErrors["answer"]}");
    }
    if (result.FieldErrors.ContainsKey("password"))
    {
        Debug.Log($"Error contraseña: {result.FieldErrors["password"]}");
    }
}
```

---

## ForgotPasswordView

### Métodos Públicos

#### OnConfirmClicked
```csharp
public void OnConfirmClicked()
```

**Descripción**: Controlador de evento para botón Confirmar. Orquesta la búsqueda de usuario (si no existe) o el cambio de contraseña.

**Comportamiento**:
1. Si `currentUser` es null: Ejecuta búsqueda (OnNameEntered)
2. Si `currentUser` existe: Procesa cambio de contraseña

**Uso**: Vinculado automáticamente a ButtonConfirm.onClick en OnSubmit

---

#### OnBackClicked
```csharp
public void OnBackClicked()
```

**Descripción**: Redirije a la escena de login del estudiante.

**Comportamiento**: Ejecuta `SceneManager.LoadScene("LoginStudent")`

**Uso**: Vinculado automáticamente a ButtonBack.onClick

---

## AuthService (Métodos Nuevos)

### FindUserByNameAndRole
```csharp
public UserModel FindUserByNameAndRole(string name, int roleId)
```

**Descripción**: Busca un usuario por nombre y rol específico.

**Parámetros**:
- `name`: Nombre del usuario (case-insensitive)
- `roleId`: ID del rol (1 = estudiante, 2 = profesor)

**Retorna**:
- `UserModel` si encuentra usuario
- `null` si no existe

**Ejemplo**:
```csharp
var user = authService.FindUserByNameAndRole("Juan", 1);
if (user != null)
{
    Debug.Log($"Encontrado: {user.name}");
}
```

---

### ChangePasswordAfterSecurityVerification
```csharp
public void ChangePasswordAfterSecurityVerification(int userId, 
                                                     string newPassword)
```

**Descripción**: Cambia la contraseña de un usuario. Precondición: la respuesta de seguridad debe haber sido verificada antes.

**Parámetros**:
- `userId`: ID del usuario
- `newPassword`: Nueva contraseña (debe estar validada previamente)

**Comportamiento**:
1. Valida que contraseña no sea vacía
2. Encripta con SHA256
3. Actualiza en la BD
4. Escribe log de éxito

**Excepciones**: Lanza `ArgumentException` si contraseña es vacía

**Ejemplo**:
```csharp
try
{
    authService.ChangePasswordAfterSecurityVerification(1, "MyNewPass123");
    Debug.Log("✓ Contraseña actualizada");
}
catch (ArgumentException ex)
{
    Debug.LogError($"Error: {ex.Message}");
}
```

---

## AuthService (Métodos Existentes - Útiles)

### VerifySecurityAnswer
```csharp
public bool VerifySecurityAnswer(int userId, string providedAnswer)
```

**Descripción**: Verifica si la respuesta de seguridad es correcta.

**Parámetros**:
- `userId`: ID del usuario
- `providedAnswer`: Respuesta ingresada por el usuario

**Retorna**:
- `true` si coincide (después de normalización)
- `false` si no coincide o hay error

**Normalización**: Automáticamente convierte a minúsculas y elimina espacios.

---

### UpdateLastLogin
```csharp
public void UpdateLastLogin(int userId)
```

**Descripción**: Actualiza el registro de último login del usuario (formato dd/MM/yyyy).

**Parámetros**:
- `userId`: ID del usuario

---

## UserRepository (Métodos Útiles)

### GetUserById
```csharp
public UserModel GetUserById(int userId)
```

**Descripción**: Obtiene un usuario por su ID.

**Retorna**: `UserModel` o `null` si no existe.

---

### UpdateUserPassword
```csharp
public void UpdateUserPassword(int userId, string hashedPassword)
```

**Descripción**: Actualiza la contraseña en la BD (debe estar hasheada).

---

### LoginStudent
```csharp
public UserModel LoginStudent(string name)
```

**Descripción**: Busca un estudiante por nombre (role = 1).

**Retorna**: `UserModel` con todos los datos incluyendo security_answer_hash.

---

## SecurityQuestionsService

### Constructor (Nuevo)
```csharp
public SecurityQuestionsService(SecurityQuestionsRepository repository)
```

**Descripción**: Crea el servicio con inyección de dependencias.

---

### GetQuestionById
```csharp
public SecurityQuestionsModel GetQuestionById(int questionId)
```

**Descripción**: Obtiene una pregunta de seguridad por ID.

**Retorna**: 
- `SecurityQuestionsModel` con `id_question` y `question`
- `null` si no existe

---

### GetAllQuestions
```csharp
public List<SecurityQuestionsModel> GetAllQuestions()
```

**Descripción**: Obtiene todas las preguntas disponibles.

---

## Modelos de Datos

### UserModel
```csharp
public class UserModel : SQLiteTableBase
{
    [PrimaryKey]
    public int id_user { get; set; }
    
    public string name { get; set; }
    public int id_degree { get; set; }          // FK
    public string password { get; set; }        // SHA256 hash
    public int id_role { get; set; }            // 1=student, 2=teacher
    public int id_security_question { get; set; }
    public string security_answer_hash { get; set; }
    public string last_login { get; set; }      // dd/MM/yyyy format
}
```

### SecurityQuestionsModel
```csharp
public class SecurityQuestionsModel : SQLiteTableBase
{
    [PrimaryKey]
    public int id_question { get; set; }
    
    public string question { get; set; }
}
```

---

## Flujos de Ejecución Típicos

### Flujo 1: Login Correcto
```csharp
// 1. Usuario ingresa nombre
string userName = "Juan";

// 2. Presenter busca usuario
var lookupResult = presenter.FindStudentByName(userName);

if (lookupResult.Success)
{
    // 3. Mostrar pregunta
    var question = presenter.GetSecurityQuestion(
        lookupResult.User.id_security_question
    );
    Debug.Log($"Pregunta: {question.Question}");
    
    // 4. Usuario ingresa respuesta y contraseña
    string answer = "blue";
    string newPass = "MyNewPass123";
    
    // 5. Procesar reset
    var resetResult = presenter.ResetPassword(
        lookupResult.User.id_user,
        answer,
        newPass
    );
    
    if (resetResult.Success)
    {
        Debug.Log("✓ Cambio exitoso");
        SceneManager.LoadScene("LoginStudent");
    }
    else
    {
        foreach (var error in resetResult.FieldErrors)
        {
            Debug.Log($"{error.Key}: {error.Value}");
        }
    }
}
else
{
    Debug.Log($"Error: {lookupResult.ErrorMessage}");
}
```

### Flujo 2: Respuesta Incorrecta
```csharp
var resetResult = presenter.ResetPassword(userId, "wrongAnswer", "newPass");

if (!resetResult.Success)
{
    if (resetResult.FieldErrors.ContainsKey("answer"))
    {
        // Mostrar: "Tu respuesta de seguridad es incorrecta"
        ShowError(resetResult.FieldErrors["answer"]);
    }
}
```

### Flujo 3: Contraseña Débil
```csharp
var resetResult = presenter.ResetPassword(userId, "correctAnswer", "123");

if (!resetResult.Success)
{
    if (resetResult.FieldErrors.ContainsKey("password"))
    {
        // Mostrar: "La contraseña debe tener al menos 6 caracteres"
        ShowError(resetResult.FieldErrors["password"]);
    }
}
```

---

## Constantes y Límites

| Concepto | Límite | Notas |
|----------|--------|-------|
| Longitud mín contraseña | 6 caracteres | Validado en Presenter |
| Longitud máx contraseña | 50 caracteres | Validado en Presenter |
| Longitud máx nombre | 100 caracteres | Input field |
| Longitud máx respuesta | 255 caracteres | Input field type password |
| Formato fecha | dd/MM/yyyy | Ej: "14/04/2026" |
| Modo password | Password/Asterisks | Respuesta y contraseña ocultas |

---

## Códigos de Error Comunes

| Error | Causa | Mensaje Mostrado |
|-------|-------|------------------|
| NOMBRE_VACIO | Input vacío | "Por favor ingresa tu nombre completo" |
| USUARIO_NO_EXISTE | No encontrado en BD | "No encontramos un estudiante con ese nombre..." |
| SIN_PREGUNTA | user.id_security_question <= 0 | "Tu cuenta no tiene una pregunta de seguridad..." |
| RESPUESTA_VACIA | Input vacío | "Por favor ingresa tu respuesta de seguridad" |
| PASSWORD_VACIA | Input vacío | "Por favor ingresa una nueva contraseña" |
| PASSWORD_CORTA | < 6 caracteres | "La contraseña debe tener al menos 6 caracteres" |
| PASSWORD_LARGA | > 50 caracteres | "La contraseña no puede exceder 50 caracteres" |
| RESPUESTA_INCORRECTA | Hash no coincide | "Tu respuesta de seguridad es incorrecta. Intenta nuevamente." |
| DB_ERROR | Exception en BD | "Ocurrió un error al cambiar tu contraseña. Intenta más tarde" |

---

## Logs de Debug

El sistema genera logs informativos en Debug.Log():

```csharp
// Éxito
"[ForgotPasswordPresenter] Usuario encontrado: Juan (ID: 1)"
"[ForgotPasswordPresenter] Contraseña cambiada exitosamente para usuario 1"
"[ForgotPasswordView] Inicialización completada"
"[LoginPresenter] Último login actualizado para usuario 1"

// Errores
"[ForgotPasswordPresenter] Error al buscar usuario: ..."
"[ForgotPasswordPresenter] Respuesta de seguridad incorrecta para usuario 1"
```

---

**Versión API**: 1.0  
**Última actualización**: 14/04/2026  
**Mantenedor**: GitHub Copilot
