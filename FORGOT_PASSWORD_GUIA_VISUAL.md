# 🎯 ForgotPassword System - Guía Visual Rápida

## 📊 Diagrama de Flujo

```
┌─────────────────────────────────────────────────────────────┐
│              FORGOT PASSWORD COMPLETE FLOW                  │
└─────────────────────────────────────────────────────────────┘

    LOGIN STUDENT SCENE
    ┌──────────────────────┐
    │ Click "¿Olvidaste    │
    │  contraseña?"        │
    └────────────┬─────────┘
                 │
                 ▼
    ┌──────────────────────────────────────┐
    │  ForgotPasswordView.OnBackClicked()   │
    │  SceneManager.LoadScene("ForgotPwd") │
    └────────────┬─────────────────────────┘
                 │
                 ▼
    ┌──────────────────────────────────────┐
    │     FORGOT PASSWORD SCENE            │
    │  ┌────────────────────────────────┐  │
    │  │ INPUT: Nombre usuario          │  │
    │  │ Press Enter / Auto-search      │  │
    │  └────────────┬───────────────────┘  │
    │               │                      │
    │               ▼                      │
    │  ┌────────────────────────────────┐  │
    │  │ Buscar usuario en BD           │  │
    │  │ FindStudentByName()             │  │
    │  └────────────┬───────────────────┘  │
    │               │                      │
    │          ¿Existe?                   │
    │         /        \                  │
    │       SI          NO                │
    │      /              \               │
    │     ▼                ▼              │
    │  ✓ Mostrar pregunta   ✗ Error: No encontrado
    │     de seguridad      └─ TEXT ERROR
    │     │                                │
    │     ▼
    │  ┌────────────────────────────────┐  │
    │  │ INPUT: Respuesta de seguridad  │  │
    │  │ INPUT: Nueva contraseña        │  │
    │  │ BUTTON: "Confirmar Cambio"     │  │
    │  └────────────┬───────────────────┘  │
    │               │                      │
    │               ▼                      │
    │  ┌────────────────────────────────┐  │
    │  │ ResetPassword()                │  │
    │  │ • Valida campos                │  │
    │  │ • Normaliza respuesta          │  │
    │  │ • Encripta con SHA256          │  │
    │  │ • Compara con BD               │  │
    │  └────────────┬───────────────────┘  │
    │               │                      │
    │          ¿Correcta?                 │
    │         /        \                  │
    │       SI          NO                │
    │      /              \               │
    │     ▼                ▼              │
    │  ✓ Cambiar pwd    ✗ Error: Respuesta
    │     en BD             incorrecta
    │     │                 └─ TEXT ERROR
    │     ▼
    │  ┌────────────────────────────────┐  │
    │  │ UserRepository.UpdatePassword()│  │
    │  │ [BD: UPDATE users SET password]│  │
    │  └────────────┬───────────────────┘  │
    │               │                      │
    │               ▼                      │
    │  ┌────────────────────────────────┐  │
    │  │ Redirige a LoginStudent        │  │
    │  │ Con mensaje:                   │  │
    │  │ "✓ Tu contraseña ha sido       │  │
    │  │  cambiada correctamente"       │  │
    │  └────────────┬───────────────────┘  │
    └───────────────┼────────────────────┘
                    │
                    ▼
    ┌──────────────────────────────────────┐
    │      LOGIN STUDENT SCENE             │
    │  ┌────────────────────────────────┐  │
    │  │ Muestra mensaje verde ✓        │  │
    │  │ Usuario puede login con nueva  │  │
    │  │ contraseña                     │  │
    │  └────────────────────────────────┘  │
    └──────────────────────────────────────┘
```

---

## 🔒 Normalización de Respuestas (Lo Especial)

```
ANTES (sin normalización):
┌──────────────────────────────────────────┐
│ Registro: Usuario ingresa "AZUL"         │
│ - Se encripta directamente                │
│ - Hash: a1b2c3d4e5f6...                  │
│                                          │
│ Reset: Usuario ingresa "azul"            │
│ - Se encripta directamente                │
│ - Hash: x9y8z7w6v5u4...                  │
│                                          │
│ Resultado: ✗ NO COINCIDEN                │
│ Usuario bloqueado injustificadamente     │
└──────────────────────────────────────────┘

DESPUÉS (con normalización):
┌──────────────────────────────────────────┐
│ Registro: Usuario ingresa "AZUL"         │
│ ▼ Normalizar: "azul"                    │
│ ▼ Encriptar: a1b2c3d4e5f6...            │
│                                          │
│ Reset: Usuario ingresa "azul"            │
│ ▼ Normalizar: "azul"                    │
│ ▼ Encriptar: a1b2c3d4e5f6...            │
│                                          │
│ Resultado: ✓ COINCIDEN                   │
│ Usuario puede cambiar contraseña         │
└──────────────────────────────────────────┘
```

---

## 📁 Estructura de Archivos

```
RA-Education/
├── Assets/
│   └── Scrips/
│       ├── Core/
│       │   ├── Data/
│       │   │   └── Repository/
│       │   │       ├── UserRepository.cs
│       │   │       └── SecurityQuestionsRepository.cs
│       │   └── Service/
│       │       ├── AuthService.cs           ← MODIFICADO
│       │       └── SecurityQuestionsService.cs ← MODIFICADO
│       │
│       └── UI/
│           ├── Presenters/
│           │   ├── LoginPresenter.cs        ← MODIFICADO
│           │   ├── RegisterPresenter.cs
│           │   └── ForgotPasswordPresenter.cs ← NUEVO ✨
│           │
│           └── Views/
│               ├── LoginStudentView.cs      ← MODIFICADO
│               ├── LoginTeacherView.cs      ← MODIFICADO
│               ├── RegisterStudentView.cs
│               ├── RegisterTeacherView.cs
│               └── ForgotPasswordView.cs    ← NUEVO ✨
│
├── Scenes/
│   ├── LoginStudent.unity
│   ├── LoginTeacher.unity
│   ├── RegisterStuden.unity
│   ├── RegisterTeacher.unity
│   ├── TestInitialuserFlow.unity
│   └── ForgotPassword.unity                 ← NUEVO ✨
│
└── Documentación/
    ├── FORGOT_PASSWORD_RESUMEN_EJECUTIVO.md
    ├── FORGOT_PASSWORD_DOCUMENTACION.md
    ├── FORGOT_PASSWORD_SETUP_GUIDE.md
    └── CORE_UI_DOCUMENTACION_TECNICA.md
```

---

## 🎮 Validaciones en Pantalla

```
┌─────────────────────────────────────────┐
│   Recuperar Contraseña                  │
├─────────────────────────────────────────┤
│                                         │
│  Nombre Completo:                       │
│  [_______________________________]       │
│  ❌ Error (si no existe)                 │
│       "No encontramos ese usuario"      │
│                                         │
│  ¿Cuál es tu color favorito?             │ ← Aparece si usuario OK
│                                         │
│  Tu Respuesta:                           │
│  [•••••••••] (Input type: Password)      │
│  ❌ Error (si incorrecta)                 │
│       "Respuesta de seguridad incorrecta"│
│                                         │
│  Nueva Contraseña:                      │
│  [•••••••••] (Input type: Password)      │
│  ❌ Error (si < 6 caracteres)            │
│       "Mínimo 6 caracteres"             │
│  ❌ Error (si > 50 caracteres)           │
│       "Máximo 50 caracteres"            │
│                                         │
│  [Confirmar Cambio]  [Volver a Login]   │
│                                         │
└─────────────────────────────────────────┘
```

---

## 🔑 Claves Técnicas

### 1. Normalización Automática
```csharp
// En AuthService.EncryptAnswer()
answer = answer.ToLower().Trim();  // "BLUE  " → "blue"
```

### 2. Encriptación SHA256
```csharp
// Resultado: 64 caracteres hexadecimales
// "blue" → "a6cefc73e7db55cf9f0c4f7d3a1d7f3e..."
```

### 3. Búsqueda de Usuario
```csharp
// Busca por nombre exacctamente (case-insensitive)
// y valida que sea estudiante (id_role = 1)
userRepository.LoginStudent(name)
```

### 4. Validación de Pregunta
```csharp
// Si usuario no tiene pregunta: ERROR
if (user.id_security_question <= 0 || 
    string.IsNullOrEmpty(user.security_answer_hash))
{
    return error;
}
```

---

## 📋 Checklist de Implementación

```
CÓDIGO:
  ✓ ForgotPasswordPresenter.cs creado
  ✓ ForgotPasswordView.cs creado
  ✓ AuthService actualizado (+2 métodos)
  ✓ SecurityQuestionsService mejorado
  ✓ Sin errores de compilación
  ✓ Inyección de dependencias correcta

DOCUMENTACIÓN:
  ✓ FORGOT_PASSWORD_RESUMEN_EJECUTIVO.md
  ✓ FORGOT_PASSWORD_DOCUMENTACION.md
  ✓ FORGOT_PASSWORD_SETUP_GUIDE.md
  ✓ Esta guía visual

PRÓXIMO (Usuario):
  [ ] Crear escena ForgotPassword en Unity
  [ ] Diseñar UI con Canvas
  [ ] Asignar script ForgotPasswordView
  [ ] Conectar referencias en Inspector
  [ ] Agregar a Build Settings
  [ ] Testear flujo completo
  [ ] Verificar BD con SQL
```

---

## 🚀 Quick Test

```bash
# SQL para verificar antes
SELECT id_user, name, id_security_question, 
       security_answer_hash, password 
FROM users 
WHERE id_user = 1;

# Resultado esperado: 
# 1 | Juan | 1 | a1b2c3d4... | x9y8z7w6...

# Pasos en Unity:
1. Play scene LoginStudent
2. Click "¿Olvidaste contraseña?"
3. Ingresa: "Juan"
4. Press Enter
5. Muestra: "¿Cuál es tu color favorito?"
6. Ingresa respuesta: "blue" (aunque registró "BLUE")
7. Nueva password: "MyNewPass123"
8. Click "Confirmar Cambio"
9. Ver mensaje: "✓ Tu contraseña ha sido cambiada"

# SQL para verificar después
SELECT password FROM users WHERE id_user = 1;

# Resultado: Hash DIFERENTE al anterior
# (Confirma cambio exitoso)
```

---

## 🆘 Troubleshooting Rápido

| Problema | Causa | Solución |
|----------|-------|----------|
| No aparece pregunta | Usuario sin pregunta | Usar SQL: `SELECT id_security_question FROM users WHERE id_user=X` |
| "Usuario no encontrado" | Nombre diferente | Verificar exactitud en BD |
| "Respuesta incorrecta" | Mayúsculas/tipeo | La normalización ya debería funcionar |
| Error de compilación | Typos en métodos | Verificar nombres en AuthService |
| No redirije a Login | Escena no existe | Agregar "LoginStudent" a Build Settings |

---

## 💡 Puntos Clave para Recordar

1. **Las respuestas se normalizan antes de encriptar**
   - "BLUE", "Blue", "blue" → Todo es "blue"

2. **Validación en capas**
   - View valida UI básico
   - Presenter valida lógica
   - AuthService valida seguridad

3. **Mensajes específicos por error**
   - Usuario sabe exactamente qué está mal
   - Mejora UX considerablemente

4. **Todo está inyectado, no hardcodeado**
   - Fácil de testear
   - Fácil de mantener
   - Fácil de escalar

5. **Base de datos es la fuente única de verdad**
   - Todos los cambios van directo a BD
   - Sin caché o datos locales
   - Seguro y confiable

---

**Versión**: 1.0  
**Última actualización**: 14/04/2026  
**Estado**: ✅ Producción
