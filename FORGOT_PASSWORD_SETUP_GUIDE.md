# Guía de Configuración Rápida - ForgotPassword Scene

## 📋 Checklist de Configuración

### Paso 1: Crear la Escena
- [ ] File → New Scene
- [ ] Clic derecho en Scene → Rename → "ForgotPassword"
- [ ] Ctrl+S para guardar
- [ ] Seleccionar carpeta: `Assets/Scenes/`

### Paso 2: Crear Canvas y UI
En Hierarchy clic derecho:
- [ ] UI → Text - TextMeshPro
  - Se crea automáticamente Canvas
  - Rename: "Canvas"

### Paso 3: Crear Elementos UI

En Canvas clic derecho crear:
```
Canvas (creado automáticamente)
├── [NEW] Panel - Background (opcional, para organizar)
│   ├── TextTitleForgotPassword (Text - "Recuperar Contraseña")
│   ├── Label_Name (Text - "Nombre Completo:")
│   ├── InputName (TMP InputField)
│   ├── TextErrorName (Text - vacío)
│   │
│   ├── TextSecurityQuestion (Text - vacío, se llena en runtime)
│   ├── Label_Answer (Text - "Respuesta:")
│   ├── InputSecurityAnswer (TMP InputField - DISABLED por defecto)
│   ├── TextErrorAnswer (Text - vacío)
│   │
│   ├── Label_NewPassword (Text - "Nueva Contraseña:")
│   ├── InputNewPassword (TMP InputField - DISABLED por defecto)
│   ├── TextErrorPassword (Text - vacío)
│   │
│   ├── ButtonConfirm (Button - "Confirmar Cambio")
│   └── ButtonBack (Button - "Volver a Login")
```

**Creación de cada elemento:**

#### TextTitleForgotPassword
```
Clic derecho Panel → UI → Text - TextMeshPro
Rename: "TextTitleForgotPassword"
Inspector:
  - Text: "Recuperar Contraseña"
  - Font Size: 60
  - Alignment: Center / Top
  - Color: Azul o color temático
  - Rect Transform: Posición arriba
```

#### InputName
```
Clic derecho Panel → UI → TextMeshPro - Input Field
Rename: "InputName"
Inspector:
  - Placeholder Text: "Escribe tu nombre completamente"
  - Text (TextMeshProUGUI): Color blanco
  - Input Field:
    - Character Limit: 100
    - Line Type: Single Line
    - Content Type: Standard
```

#### TextErrorName
```
Clic derecho Panel → UI → Text - TextMeshPro
Rename: "TextErrorName"
Inspector:
  - Text: "" (vacío)
  - Font Size: 32
  - Color: Rojo (255, 0, 0)
  - Rect Transform: Justo debajo de InputName
  - GameObjeto: Desactivado (✓ Disable en checkbox)
```

#### TextSecurityQuestion
```
Clic derecho Panel → UI → Text - TextMeshPro
Rename: "TextSecurityQuestion"
Inspector:
  - Text: "" (se llena en runtime)
  - Font Size: 40
  - Alignment: Left / Top
  - Color: Blanco
  - Background: Opcionalmente añadir fondo semi-transparente
  - GameObjeto: Desactivado (✓ Disable en checkbox)
```

#### InputSecurityAnswer
```
Clic derecho Panel → UI → TextMeshPro - Input Field
Rename: "InputSecurityAnswer"
Inspector:
  - Placeholder Text: "Tu respuesta de seguridad"
  - Text (TextMeshProUGUI): Color blanco
  - Input Field:
    - Character Limit: 255
    - Content Type: Password ← IMPORTANTE: Oculta entrada
  - GameObjeto: Desactivado (✓ Disable en checkbox)
```

#### TextErrorAnswer
```
Clic derecho Panel → UI → Text - TextMeshPro
Rename: "TextErrorAnswer"
Inspector:
  - Font Size: 32
  - Color: Rojo
  - GameObjeto: Desactivado (✓ Disable en checkbox)
```

#### InputNewPassword
```
Clic derecho Panel → UI → TextMeshPro - Input Field
Rename: "InputNewPassword"
Inspector:
  - Placeholder Text: "Nueva contraseña (mín 6 caracteres)"
  - Input Field:
    - Character Limit: 50
    - Content Type: Password ← IMPORTANTE: Oculta entrada
  - GameObjeto: Desactivado (✓ Disable en checkbox)
```

#### TextErrorPassword
```
Clic derecho Panel → UI → Text - TextMeshPro
Rename: "TextErrorPassword"
Inspector:
  - Font Size: 32
  - Color: Rojo
  - GameObjeto: Desactivado (✓ Disable en checkbox)
```

#### ButtonConfirm
```
Clic derecho Panel → UI → Button - TextMeshPro
Rename: "ButtonConfirm"
Inspector:
  - Button: Text: "Confirmar Cambio"
  - Text (TextMeshProUGUI): Font Size 40
  - Image: Color verde o color temático
  - Rect Transform: Posición inferior izquierda
```

#### ButtonBack
```
Clic derecho Panel → UI → Button - TextMeshPro
Rename: "ButtonBack"
Inspector:
  - Button: Text: "Volver a Login"
  - Text (TextMeshProUGUI): Font Size 40
  - Image: Color gris o secundario
  - Rect Transform: Posición inferior derecha
```

### Paso 4: Agregar ForgotPasswordView Presenter

En Hierarchy clic derecho:
```
Create Empty
Rename: "ForgotPasswordManager"
```

En Inspector de ForgotPasswordManager:
```
Add Component → ForgotPasswordView
  - Input Name: Arrastra InputName field aquí
  - Text Error Name: Arrastra TextErrorName field aquí
  - Text Security Question: Arrastra TextSecurityQuestion field aquí
  - Input Security Answer: Arrastra InputSecurityAnswer field aquí
  - Text Error Answer: Arrastra TextErrorAnswer field aquí
  - Input New Password: Arrastra InputNewPassword field aquí
  - Text Error Password: Arrastra TextErrorPassword field aquí
  - Button Confirm: Arrastra ButtonConfirm field aquí
  - Button Back: Arrastra ButtonBack field aquí
```

### Paso 5: Asegurarse que DatabaseManager existe

En Hierarchy, busca "DatabaseManager":
- Si NO existe: Crear un GameObject →
  ```
  Create Empty
  Rename: "DatabaseManager"
  Add Component → DatabaseManager
  ```
- Si EXISTS: Dejar igual

### Paso 6: Conectar LoginStudentView a ForgotPassword Scene

En LoginStudentView.cs verificar que existe:
```csharp
public void GoToForgotPassword()
{
    SceneManager.LoadScene("ForgotPassword");
}
```

En LoginStudentView Inspector:
- ButtonForgotPassword → OnClick → ForgotPasswordView → GoToForgotPassword()
- ✓ Ya está asignado en el código

### Paso 7: Verificar Build Settings

File → Build Settings:
```
Scenes In Build:
  0. LoginStudent
  1. LoginTeacher
  2. RegisterStuden
  3. RegisterTeacher
  4. TestInitialuserFlow
  5. ForgotPassword ← AGREGAR AQUÍ
```

### Paso 8: Test en el Editor

1. Play (tecla Space)
2. En LoginStudent: Click "¿Olvidaste contraseña?"
3. Debe cargar ForgotPassword scene
4. Ingresar nombre de estudiante (ej: "Juan")
5. Presionar Enter
6. Debe aparecer pregunta de seguridad
7. Ingresar respuesta
8. Ingresar nueva contraseña (mín 6 caracteres)
9. Click "Confirmar Cambio"
10. Debe redirigir a LoginStudent con mensaje ✓

---

## 🎨 Diseño Recomendado

### Estructura Visual
```
┌─────────────────────────────────────┐
│    Recuperar Contraseña             │  ← Title
├─────────────────────────────────────┤
│                                     │
│  Nombre Completo:                   │
│  [____________] ← InputName         │
│  ❌ Error mensaje   ← TextErrorName │
│                                     │
│  ¿Cuál es tu color favorito?        │  ← TextSecurityQuestion
│  [____________] ← InputSecurityAnswer
│  ❌ Error mensaje   ← TextErrorAnswer
│                                     │
│  Nueva Contraseña:                  │
│  [____________] ← InputNewPassword  │
│  ❌ Error mensaje   ← TextErrorPassword
│                                     │
│  [Confirmar Cambio] [Volver a Login]│
│                                     │
└─────────────────────────────────────┘
```

### Colores Sugeridos
- **Fondo**: Azul oscuro (#1a1a2e) o gris (#2c2c2c)
- **Texto**: Blanco (#ffffff)
- **Labels**: Gris claro (#b0b0b0)
- **Errores**: Rojo (#ff4444)
- **Botón Confirmar**: Verde (#44aa44)
- **Botón Volver**: Gris (#666666)

---

## 🔗 Conexión de Botones

### ButtonConfirm
```
Inspector → Button → OnClick
  - Objeto(s): ForgotPasswordManager
  - Función: ForgotPasswordView.OnConfirmClicked()
  
✓ Ya está conectado automáticamente en código
```

### ButtonBack
```
Inspector → Button → OnClick
  - Objeto(s): ForgotPasswordManager
  - Función: ForgotPasswordView.OnBackClicked()
  
✓ Ya está conectado automáticamente en código
```

---

## ✅ Verificación Final

```
☑ Escena "ForgotPassword" creada
☑ Canvas con todos los elementos UI
☑ ForgotPasswordManager con script ForgotPasswordView
☑ Todas las referencias asignadas en Inspector
☑ DatabaseManager existe en escena
☑ ForgotPassword agregada a Build Settings
☑ ButtonForgotPassword en Login conectado
☑ Input Fields con tipo correcto (Password si aplica)
☑ Botones conectados a eventos onClick
☑ Teste en editor sin errores
```

---

## 🐛 Si hay problemas

### Compilación falla
```
Verificar:
❌ ForgotPasswordPresenter.cs está en Scrips/UI/Presenters/
❌ ForgotPasswordView.cs está en Scrips/UI/Views/
❌ No hay typos en nombres de clases
```

### "NullReferenceException" en Console
```
Verificar en Inspector:
❌ Todos los Input/Text fields están asignados
❌ DatabaseManager existe en escena
❌ ForgotPasswordManager tiene script ForgotPasswordView
```

### Usuario no encontrado
```
Verificar:
❌ Nombre exacto coincide con BD
❌ Usuario tiene rol = 1 (estudiante)
☑ Usar SQL: SELECT name FROM users WHERE id_role = 1;
```

### Respuesta de seguridad rechazada
```
Verificar:
❌ Usuario tiene pregunta configurada
☑ Usar SQL: SELECT id_security_question FROM users WHERE id_user = X;
❌ Respuesta original no tenía caracteres especiales raros
```

---

**Documentación versión**: 1.0  
**Última actualización**: 14/04/2026
