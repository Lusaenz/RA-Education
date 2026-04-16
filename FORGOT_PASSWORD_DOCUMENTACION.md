# ForgotPassword System - Documentación Técnica

## 📋 Descripción General

Sistema completo de recuperación de contraseña usando arquitectura **MVP** (Model-View-Presenter). Permite a usuarios estudiantes recuperar su contraseña verificando una pregunta de seguridad registrada previamente.

---

## 🏗️ Arquitectura

### Patrón MVP
```
ForgotPasswordView (UI)
    ↓
ForgotPasswordPresenter (Lógica de negocio)
    ↓
AuthService + SecurityQuestionsService (Servicios)
    ↓
UserRepository + SecurityQuestionsRepository (Datos)
    ↓
SQLite Database
```

### Responsabilidades

| Componente | Responsabilidad |
|-----------|-----------------|
| **ForgotPasswordView** | Captura entrada del usuario, muestra UI, maneja navegación |
| **ForgotPasswordPresenter** | Valida datos, orquesta búsqueda de usuario, verifica seguridad |
| **AuthService** | Encripta/verifica respuestas, cambia contraseña |
| **UserRepository** | Acceso directo a BD (obtiene usuario, actualiza contraseña) |

---

## 🔐 Seguridad de Respuestas de Seguridad

### Problema Original
- Usuario registra respuesta "Blue" (mayúsculas)
- Usuario intenta reset con "blue" (minúsculas)
- Sistema rechaza porque no coinciden exactamente

### Solución Implementada: Normalización

Todas las respuestas se normalizan **antes de encriptar**:

```csharp
// En AuthService.EncryptAnswer()
answer = answer.ToLower().Trim();  // "BLUE" → "blue"
```

### Flujo Completo

**1. Durante Registro:**
```
Usuario ingresa: "BLUE"
                  ↓
          Normalizar: "blue"
                  ↓
          Encriptar SHA256: "a65d6e98ef1baf9b40c24d00c8a5ba3bfb..."
                  ↓
          Guardar en BD
```

**2. Durante Reset de Contraseña:**
```
Usuario ingresa: "blue"
                  ↓
          Normalizar: "blue"
                  ↓
          Encriptar SHA256: "a65d6e98ef1baf9b40c24d00c8a5ba3bfb..."
                  ↓
          Comparar con hash guardado: ✓ COINCIDEN
```

---

## 📁 Archivos

### Nuevos Archivos Creados

#### 1. `ForgotPasswordPresenter.cs`
Ubicación: `Assets/Scrips/UI/Presenters/`

```csharp
// Resulta de búsqueda de usuario
public UserLookupResult FindStudentByName(string name)
{
    // Valida nombre no vacío
    // Busca usuario en BD
    // Verifica que tenga pregunta de seguridad
    // Retorna resultado con usuario o error
}

// Obtiene información de la pregunta
public SecurityQuestionInfo GetSecurityQuestion(int questionId)
{
    // Recupera pregunta desde BD
    // Retorna ID y texto
}

// Procesa el reset de contraseña
public PasswordResetResult ResetPassword(int userId, string securityAnswer, string newPassword)
{
    // Valida campos no vacíos
    // Valida longitud contraseña (6-50 caracteres)
    // Verifica respuesta de seguridad
    // Si todo OK: cambia contraseña
    // Retorna resultado con errores por campo si aplica
}
```

#### 2. `ForgotPasswordView.cs`
Ubicación: `Assets/Scrips/UI/Views/`

```csharp
// Se ejecuta cuando usuario ingresa nombre (Enter o Submit)
private void OnNameEntered()
{
    // Busca usuario usando presenter
    // Muestra pregunta de seguridad
    // Habilita campos de respuesta y contraseña
}

// Se ejecuta al presionar botón Confirmar
private void OnConfirmClicked()
{
    // Si no hay usuario: busca primero
    // Si hay usuario: procesa reset
}

// Cambia contraseña
private void ProcessPasswordReset()
{
    // Valida con presenter
    // Si OK: guarda en preferencias y redirige
    // Si error: muestra mensajes de error específicos
}
```

### Archivos Modificados

#### 1. `AuthService.cs`
**Nuevos Métodos:**

```csharp
// Busca usuario por nombre y rol
public UserModel FindUserByNameAndRole(string name, int roleId)

// Cambia contraseña después de verificación
public void ChangePasswordAfterSecurityVerification(int userId, string newPassword)
```

#### 2. `SecurityQuestionsService.cs`
**Constructor Nuevo:**

```csharp
// Ahora acepta inyección de dependencia
public SecurityQuestionsService(SecurityQuestionsRepository repository)
```

---

## 🎮 Configuración en Unity

### 1. Crear escena "ForgotPassword"
- File → New Scene
- Asignar nombre: "ForgotPassword"
- Guardar

### 2. Agregar ForgotPasswordView
- Click derecho en Hierarchy → Create Empty
- Nombre: "ForgotPasswordManager"
- Add Component → ForgotPasswordView

### 3. Crear UI (Canvas if not exists)
```
Canvas
  ├── InputName (TMP InputField)
  ├── TextErrorName (Text)
  ├── TextSecurityQuestion (Text)
  ├── InputSecurityAnswer (TMP InputField)
  ├── TextErrorAnswer (Text)
  ├── InputNewPassword (TMP InputField)
  ├── TextErrorPassword (Text)
  ├── ButtonConfirm (Button)
  └── ButtonBack (Button)
```

### 4. Asignar referencias en Inspector
Seleccionar "ForgotPasswordManager" y asignar:
- InputName → InputName (InputField)
- TextErrorName → TextErrorName (Text)
- TextSecurityQuestion → TextSecurityQuestion (Text)
- InputSecurityAnswer → InputSecurityAnswer (InputField)
- TextErrorAnswer → TextErrorAnswer (Text)
- InputNewPassword → InputNewPassword (InputField)
- TextErrorPassword → TextErrorPassword (Text)
- ButtonConfirm → ButtonConfirm (Button)
- ButtonBack → ButtonBack (Button)

### 5. Agregar escena a Build
- File → Build Settings
- Arrastrar escena "ForgotPassword" a la lista

---

## 📊 Flujo de Ejecución

```
    Usuario en Login
          ↓
    Click "¿Olvidaste contraseña?"
          ↓
    Carga escena ForgotPassword
          ↓
    Ingresa nombre completo
          ↓
    Press Enter / Click buscar
          ↓
    [ForgotPasswordView.OnNameEntered()]
          ↓
    [ForgotPasswordPresenter.FindStudentByName()]
          ↓
    Busca en BD → Valida pregunta de seguridad
          ↓
    SI existe → Muestra pregunta
    NO existe → Muestra error
          ↓
    Usuario ingresa respuesta + nueva contraseña
          ↓
    Click Confirmar
          ↓
    [ForgotPasswordView.OnConfirmClicked()]
          ↓
    [ForgotPasswordView.ProcessPasswordReset()]
          ↓
    [ForgotPasswordPresenter.ResetPassword()]
          ↓
    Valida campos
          ↓
    Normaliza y encripta respuesta
          ↓
    [AuthService.VerifySecurityAnswer()] ← Aquí se comparan hashes
          ↓
    ¿Respuesta correcta?
          ↓
    SI → [AuthService.ChangePasswordAfterSecurityVerification()]
         → Encripta nueva contraseña
         → Actualiza BD
         → Redirige a Login con mensaje ✓
    NO → Muestra error "Respuesta incorrecta"
```

---

## 🧪 Casos de Prueba

### Test 1: Respuesta Case-Insensitive
```
1. Registrar estudiante con respuesta de seguridad: "Mi Gato"
2. Ir a ForgotPassword
3. Ingresar respuesta: "mi gato" (todo minúsculas)
4. Resultado esperado: ✓ Aceptado
```

### Test 2: Respuesta con espacios extra
```
1. Registrar: "Python"
2. Reset con: "  Python  " (espacios antes/después)
3. Resultado esperado: ✓ Aceptado (trim hace efecto)
```

### Test 3: Respuesta incorrecta
```
1. Registrar: "Blue"
2. Reset con: "Red"
3. Resultado esperado: ✗ Error "Tu respuesta de seguridad es incorrecta"
```

### Test 4: Nueva contraseña validación
```
1. Ingresar contraseña: "123" (menos de 6 caracteres)
2. Click Confirmar
3. Resultado esperado: ✗ Error "La contraseña debe tener al menos 6 caracteres"
```

### Test 5: Verificar cambio en BD
```sql
-- Antes
SELECT password FROM users WHERE id_user = 1;
-- Resultado: "a65d6e98ef1baf9b40c24d00c8a5ba3b..." (hash anterior)

-- Después de reset
SELECT password FROM users WHERE id_user = 1;
-- Resultado: "c78d2f9a1b3e4c5d6f7g8h9i0j1k2l3m..." (hash nuevo)
```

---

## 🐛 Troubleshooting

### Error: "No encontramos un estudiante con ese nombre"
- **Causa**: Nombre escrito diferente (espacios, mayúsculas/minúsculas)
- **Solución**: Verificar exactitud del nombre en BD
- **SQL**: `SELECT name FROM users WHERE id_role = 1;`

### Error: "Tu cuenta no tiene una pregunta de seguridad"
- **Causa**: Usuario registrado antes de implementar preguntas de seguridad
- **Solución**: Contactar soporte para actualizar perfil

### Error: "Tu respuesta de seguridad es incorrecta"
- **Causa**: Respuesta no coincide (después de normalización)
- **Solución**: Revisar si respuesta original contenía caracteres especiales

### No redirije a Login después de cambiar contraseña
- **Causa**: Escena "LoginStudent" no existe o nombre incorrecto
- **Solución**: Verificar nombre exacto de escena en Build Settings

---

## 📝 Validaciones Implementadas

| Campo | Validación |
|-------|-----------|
| **Nombre** | No vacío, búsqueda en BD |
| **Respuesta** | No vacía, normalización (trim + lowercase), encriptación |
| **New Password** | No vacía, mínimo 6 caracteres, máximo 50 caracteres |

---

## 🔄 Ciclo de Vida

### Vista (ForgotPasswordView)
1. `Awake` → Espera DatabaseManager
2. `Start` → Registra listeners
3. `OnNameEntered` → Usuario completa nombre
4. `OnConfirmClicked` → Usuario confirma cambio
5. `OnDisable` → Limpia listeners

### Presenter (ForgotPasswordPresenter)
1. `FindStudentByName()` → Búsqueda inicial
2. `GetSecurityQuestion()` → Recupera pregunta
3. `ResetPassword()` → Valida y procesa cambio

---

## 🎯 Mejoras Futuras (Opcionales)

- [ ] Agregar captcha para evitar fuerza bruta
- [ ] Limitar intentos de respuesta de seguridad (ej: máximo 3)
- [ ] Enviar email de confirmación después de cambio
- [ ] Agregar 2FA (autenticación de dos factores)
- [ ] Log de intentos fallidos
- [ ] Soporte para recuperación por email (profesores)

---

## 📚 Referencias

- [OWASP Password Reset](https://cheatsheetseries.owasp.org/cheatsheets/Forgotten_Password_Cheat_Sheet.html)
- [Unity MVP Pattern](https://docs.unity3d.com/Manual/UIToolkitArchitecture.html)
- SQLite4Unity3d Documentation

---

**Versión**: 1.0  
**Fecha**: 14/04/2026  
**Estado**: ✅ Producción
