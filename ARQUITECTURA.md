# Informe de Arquitectura — RA-Education
**Fecha:** 2026-06-23  
**Revisado por:** Ingeniero de Software Senior / Arquitecto  
**Versión del análisis:** 1.0

---

## Tabla de Contenidos

1. [Resumen Ejecutivo](#1-resumen-ejecutivo)
2. [Estado Actual de la Arquitectura](#2-estado-actual-de-la-arquitectura)
3. [Problemas Identificados y Violaciones SOLID](#3-problemas-identificados-y-violaciones-solid)
4. [Arquitectura Propuesta](#4-arquitectura-propuesta)
5. [Estructura de Carpetas Propuesta](#5-estructura-de-carpetas-propuesta)
6. [Contratos de Interfaces (Abstracciones Clave)](#6-contratos-de-interfaces-abstracciones-clave)
7. [Hoja de Ruta de Migración](#7-hoja-de-ruta-de-migración)
8. [Patrones de Código Recomendados](#8-patrones-de-código-recomendados)
9. [Reglas de Estilo y Convenciones](#9-reglas-de-estilo-y-convenciones)
10. [Métricas Actuales del Proyecto](#10-métricas-actuales-del-proyecto)

---

## 1. Resumen Ejecutivo

El proyecto **RA-Education** es una aplicación educativa de Realidad Aumentada en Unity/C# con ~85 scripts (~15 000 líneas de código). Tiene una base arquitectónica sólida (patrón MVP, capa de repositorios, servicios de dominio, gestión de sesión), pero acumula inconsistencias que dificultan el mantenimiento, las pruebas y la adición de nuevos juegos o módulos.

**Lo que ya funciona bien y se debe conservar:**
- Separación MVP (Presenters / Views / Models)
- Capa de repositorios para acceso a datos
- Sistema de sesión con auto-login y persistencia
- Carga de assets con Addressables
- Migración selectiva de base de datos SQLite

**Lo que se debe corregir:**
- Ausencia de interfaces en repositorios y servicios (rompe DIP y dificulta pruebas)
- Acoplamiento directo a `DatabaseManager.Instance` dentro de servicios
- Abuso de `PlayerPrefs` como bus de estado de runtime
- Duplicación de lógica entre `GameManager` y `GameManagerFood`
- `MonoBehaviour` donde debería haber Plain C# (Presenters)
- Singletons sin abstracción (no testeables)
- Nombres de escenas hardcodeados como strings dispersos
- Código legado sin eliminar (`DatabaseController`, `GameManagerDrop`, `TermsRepository` incompleto)

---

## 2. Estado Actual de la Arquitectura

### 2.1 Mapa de capas actuales

```
┌─────────────────────────────────────────────────┐
│              PRESENTACIÓN (Unity Scenes)         │
│  Views · Presenters · Components · SceneDesign   │
├─────────────────────────────────────────────────┤
│              SERVICIOS DE DOMINIO                │
│  AuthService · GameActivityService · ...         │
├─────────────────────────────────────────────────┤
│              ACCESO A DATOS                      │
│  Repositories · DatabaseManager                  │
├─────────────────────────────────────────────────┤
│              INFRAESTRUCTURA                     │
│  SQLite · Addressables · PlayerPrefs             │
└─────────────────────────────────────────────────┘
```

### 2.2 Inventario de scripts (85 archivos)

| Carpeta actual | Cantidad | Responsabilidad |
|---|---|---|
| `Core/Data/` | 5 | DB Manager, Estado, Visualizador |
| `Core/Data/Repository/` | 8 | CRUD sobre SQLite |
| `Core/Service/` | 6 | Lógica de dominio |
| `Core/Session/` | 6 | Sesión, Auto-login, Persistencia |
| `Core/Validation/` | 2 | Validación de formularios |
| `Core/Security/` | 1 | Hashing de contraseñas |
| `UI/Models/` | 10 | DTOs y modelos de datos |
| `UI/Views/` | 8 | Componentes visuales |
| `UI/Presenters/` | 6 | Lógica de presentación |
| `UI/Components/` | 6 | Widgets reutilizables |
| `UI/Managers/` | 1 | Orquestador pantalla usuario |
| `SceneDesign/` | 10 | Navegación, interacción 3D, UI de juego |
| `Drop_Slot/` | 8 | Minijuego Drag & Drop |
| `Ripples/` | 2 | Minijuego Food Riddles |

---

## 3. Problemas Identificados y Violaciones SOLID

### 3.1 Single Responsibility Principle (SRP) — Violaciones

#### UIVisualizer.cs — Clase Dios
Combina en un solo MonoBehaviour: consulta BD, parsea datos, crea GameObjects dinámicamente, gestiona animaciones de libro, y mantiene estado de paginación. Cualquier cambio en el diseño del libro o en el esquema de módulos requiere editar la misma clase.

#### GameInfoUI.cs — Responsabilidades múltiples
Carga datos de `game_activity` desde BD, gestiona imágenes Addressables, actualiza UI del panel, y orquesta la navegación a la escena del juego. Debería dividirse en un Presenter + una View.

#### BookAnimation.cs — Animación + Paginación + Datos
Mezcla lógica de paginación con efectos de animación y carga de datos de módulos.

#### EstadoManager.cs — Estado + BD + Assets
Instancia directamente `ProgressRepository`, consulta BD, carga sprites Addressables y mantiene estado de módulos. Viola SRP al mezclar persistencia con gestión de assets y estado de UI.

---

### 3.2 Open/Closed Principle (OCP) — Violaciones

#### Añadir un nuevo tipo de juego requiere modificar clases existentes
Para agregar un tercer tipo de minijuego (ej. `WordSearch`), actualmente se necesita:
- Agregar un `case` en `GameInfoUI` para el nuevo `game_type`
- Agregar una nueva entrada en `BackgroundLoader`
- Agregar una nueva entrada en `PreviewImageLoader`
- Crear un nuevo GameManager sin una plantilla base

**Solución:** Definir una interfaz `IGameBootstrapper` con una factory que resuelva el tipo de juego en tiempo de ejecución.

---

### 3.3 Liskov Substitution Principle (LSP) — Violaciones

#### GameManagerDrop.cs — Alias sin sentido
Es un wrapper/alias de `GameManager` que existe por razones históricas pero no agrega comportamiento. Confunde el modelo de herencia.

#### Falta base común para GameManagers
`GameManager` (Drag & Drop) y `GameManagerFood` (Riddles) son dos clases paralelas con código casi idéntico: bootstrap, carga de `game_activity`, cálculo de estrellas, animación del panel de victoria, guardado de resultados. No comparten ninguna clase base, lo que impide sustituirlos polimórficamente.

---

### 3.4 Interface Segregation Principle (ISP) — Violaciones

#### Ausencia de interfaces en repositorios
Ningún repositorio implementa una interfaz (`IUserRepository`, `IActivityRepository`, etc.). Esto impide:
- Inyección de dependencias real
- Pruebas unitarias con mocks
- Múltiples implementaciones (ej. caché en memoria vs. SQLite)

Solo `ITestInitialUserFlowView` existe como interfaz de vista. `LoginView`, `RegisterView`, `ForgotPasswordView` no tienen interfaces, lo que los acopla directamente a sus Presenters.

---

### 3.5 Dependency Inversion Principle (DIP) — Violaciones

#### Servicios dependen de `DatabaseManager.Instance` directamente
```csharp
// Código actual en GameActivityService.cs (línea 27)
if (DatabaseManager.Instance == null) { ... }
if (!DatabaseManager.Instance.IsReady)
    yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);
```
Este patrón se **repite en todos los servicios**, acoplando la capa de servicio a la implementación concreta de la infraestructura. Deberían depender de una abstracción.

#### `EnsureDatabaseManagerExists()` en GameManagers
```csharp
// Código actual en GameManagerFood.cs (línea 303)
private void EnsureDatabaseManagerExists()
{
    if (DatabaseManager.Instance != null) return;
    new GameObject(DatabaseManagerObjectName).AddComponent<DatabaseManager>();
}
```
Un GameManager no debería ser responsable de crear infraestructura. Esto es violación directa del DIP y del SRP.

#### PlayerPrefs como bus de estado entre escenas
```csharp
// Disperso en BoxGameSelector, GameSelector, GameManager, GameManagerFood
PlayerPrefs.SetInt("selected_module_id", moduleId);
PlayerPrefs.GetInt("selected_activity_id", DefaultGameActivityId);
```
PlayerPrefs es persistencia de disco, no un canal de comunicación entre escenas. Se usa en 6+ scripts sin contrato tipado, lo que genera errores silenciosos cuando se cambia el nombre de la clave.

---

### 3.6 Otros Problemas de Calidad

| Problema | Ubicación | Impacto |
|---|---|---|
| Typo en nombre de carpeta `Scrips` vs `Scripts` | Raíz del proyecto | Confusión en toda la base de código |
| Strings de nombres de escena hardcodeados | SceneLoader, SessionBootstrapper, múltiples Presenters | Crash silencioso si se renombra una escena |
| `MonoBehaviour` en Presenters | `RegisterPresenter`, `ForgotPasswordPresenter` | Ciclo de vida Unity atado a lógica de negocio |
| Código legado sin eliminar | `DatabaseController`, `GameManagerDrop`, `TermsRepository` incompleto | Dead code que confunde |
| Duplicación de `PasswordHasher` | `AuthService` (privado) + `Core/Security/PasswordHasher.cs` | Dos fuentes de verdad |
| Repositorios con constructor dual (con/sin conexión) | Todos los repositories | Inicialización implícita peligrosa |
| `Debug.Log` en producción | Generalizado | Performance en dispositivos móviles |
| `SoundManager` como Singleton estático | `Drop_Slot/SoundManager.cs` | Irremplazable, no testeable |

---

## 4. Arquitectura Propuesta

### 4.1 Principio guía

> **Cada capa conoce solo la capa inmediatamente inferior mediante abstracciones (interfaces). Nunca mediante implementaciones concretas.**

### 4.2 Diagrama de la arquitectura objetivo

```
┌──────────────────────────────────────────────────────────────────┐
│                    CAPA DE PRESENTACIÓN                          │
│                                                                  │
│  ┌─────────────┐  ┌────────────┐  ┌──────────────────────────┐  │
│  │   Views     │  │ Presenters │  │   UI Components          │  │
│  │ (ILoginView)│  │ (Plain C#) │  │   Widgets reutilizables  │  │
│  └──────┬──────┘  └──────┬─────┘  └──────────────────────────┘  │
│         │ implementa      │ usa abstracción                       │
└─────────┼─────────────────┼────────────────────────────────────  ┘
          │                 │
┌─────────▼─────────────────▼────────────────────────────────────  ┐
│                    CAPA DE APLICACIÓN                            │
│                                                                  │
│  ┌──────────────────────────────────────────────────────────┐    │
│  │   GameBootstrappers (IGameBootstrapper)                  │    │
│  │   SceneNavigator (ISceneNavigator)                       │    │
│  │   SceneContext — reemplaza PlayerPrefs como bus de       │    │
│  │   estado entre escenas (tipado, en memoria)              │    │
│  └──────────────────────────────────────────────────────────┘    │
└────────────────────────────────────────────────────────────────  ┘
          │
┌─────────▼──────────────────────────────────────────────────────  ┐
│                    CAPA DE DOMINIO/SERVICIO                      │
│                                                                  │
│  ┌─────────────┐  ┌──────────────────┐  ┌───────────────────┐   │
│  │ IAuthService│  │IGameActivitySvc  │  │IResultActivitySvc │   │
│  │ AuthService │  │GameActivitySvc   │  │ResultActivitySvc  │   │
│  └──────┬──────┘  └────────┬─────────┘  └────────┬──────────┘   │
│         └─────────────────┬┘────────────────────┘               │
│  ┌──────────────────────────────────────────────────────────┐    │
│  │   IDatabaseReadinessProvider — abstracción sobre         │    │
│  │   "esperar a que la BD esté lista"                       │    │
│  └──────────────────────────────────────────────────────────┘    │
└────────────────────────────────────────────────────────────────  ┘
          │
┌─────────▼──────────────────────────────────────────────────────  ┐
│                    CAPA DE DATOS                                 │
│                                                                  │
│  ┌──────────────────┐  ┌──────────────────────────────────────┐  │
│  │  IUserRepository │  │  IGameActivityRepository             │  │
│  │  UserRepository  │  │  GameActivityRepository              │  │
│  │  ...             │  │  ...                                 │  │
│  └──────────────────┘  └──────────────────────────────────────┘  │
│  ┌──────────────────────────────────────────────────────────┐    │
│  │   DatabaseManager (único punto de entrada a SQLite)      │    │
│  └──────────────────────────────────────────────────────────┘    │
└────────────────────────────────────────────────────────────────  ┘
          │
┌─────────▼──────────────────────────────────────────────────────  ┐
│                    INFRAESTRUCTURA                               │
│   SQLite4Unity3d · Unity Addressables · PlayerPrefs (solo       │
│   persistencia real: sesión, preferencias) · UnityWebRequest    │
└────────────────────────────────────────────────────────────────  ┘
```

### 4.3 Flujo de dependencias correcto

```
View → implementa → IView
Presenter → depende de → IView + IService
Service → depende de → IRepository + IDatabaseReadinessProvider
Repository → depende de → SQLiteConnection (concreta, vía constructor)
DatabaseManager → implementa → IDatabaseReadinessProvider
```

Ninguna clase de nivel superior crea instancias `new` de clases de nivel inferior **excepto** el `ServiceLocator` o los GameObjects de Unity que actúan como raíz de composición.

---

## 5. Estructura de Carpetas Propuesta

```
Assets/
└── Scripts/                          ← (renombrar desde Scrips/)
    │
    ├── Core/
    │   ├── Database/
    │   │   ├── IDatabaseProvider.cs          ← NUEVA: abstracción de conexión + IsReady
    │   │   ├── DatabaseManager.cs            ← implementa IDatabaseProvider
    │   │   └── DatabaseMigrationService.cs   ← EXTRAÍDO de DatabaseManager
    │   │
    │   ├── Repositories/                     ← MOVER desde Core/Data/Repository/
    │   │   ├── Interfaces/
    │   │   │   ├── IUserRepository.cs        ← NUEVA
    │   │   │   ├── IActivityRepository.cs    ← NUEVA
    │   │   │   ├── IGameActivityRepository.cs← NUEVA
    │   │   │   ├── IResultActivityRepository.cs ← NUEVA
    │   │   │   ├── IModulesRepository.cs     ← NUEVA
    │   │   │   ├── IDegreeRepository.cs      ← NUEVA
    │   │   │   └── ISecurityQuestionsRepository.cs ← NUEVA
    │   │   ├── UserRepository.cs             ← implementa IUserRepository
    │   │   ├── ActivityRepository.cs
    │   │   ├── GameActivityRepository.cs
    │   │   ├── ResultActivityRepository.cs
    │   │   ├── ModulesRepository.cs
    │   │   ├── DegreeRepository.cs
    │   │   └── SecurityQuestionsRepository.cs
    │   │
    │   ├── Services/                         ← MOVER desde Core/Service/
    │   │   ├── Interfaces/
    │   │   │   ├── IAuthService.cs           ← NUEVA
    │   │   │   ├── IGameActivityService.cs   ← NUEVA
    │   │   │   ├── IActivityService.cs       ← NUEVA
    │   │   │   ├── IResultActivityService.cs ← NUEVA
    │   │   │   ├── IDegreeService.cs         ← NUEVA
    │   │   │   └── ISecurityQuestionsService.cs ← NUEVA
    │   │   ├── AuthService.cs
    │   │   ├── GameActivityService.cs
    │   │   ├── ActivityService.cs
    │   │   ├── ResultActivityService.cs
    │   │   ├── DegreeService.cs
    │   │   └── SecurityQuestionsService.cs
    │   │
    │   ├── Session/                          ← MANTENER estructura actual
    │   │   ├── ISessionPersistence.cs
    │   │   ├── IAutoLoginService.cs
    │   │   ├── SessionData.cs
    │   │   ├── SessionPersistence.cs
    │   │   ├── AutoLoginService.cs
    │   │   ├── SessionBootstrapper.cs
    │   │   └── UserSessionManager.cs
    │   │
    │   ├── Security/
    │   │   └── PasswordHasher.cs             ← ÚNICO, eliminar duplicado en AuthService
    │   │
    │   └── Validation/
    │       ├── RegisterValidator.cs
    │       └── RegisterResult.cs
    │
    ├── Domain/                               ← NUEVA CARPETA
    │   └── Models/                           ← MOVER desde UI/Models/ los modelos de dominio
    │       ├── UserModel.cs
    │       ├── StudentModel.cs
    │       ├── TeacherModel.cs
    │       ├── DegreeModel.cs
    │       ├── ModuleModel.cs
    │       ├── ActivityData.cs
    │       ├── GameActivityData.cs           ← renombrado desde GameActivityModel
    │       ├── ResultActivityData.cs
    │       ├── ProgressModel.cs
    │       ├── SecurityQuestionsModel.cs
    │       └── Configs/                      ← configuraciones JSON de juegos
    │           ├── DragDropConfig.cs
    │           └── FoodRiddlesConfig.cs
    │
    ├── Application/                          ← NUEVA CAPA
    │   ├── Navigation/
    │   │   ├── ISceneNavigator.cs            ← NUEVA: abstracción de navegación
    │   │   ├── SceneNavigator.cs             ← implementa ISceneNavigator
    │   │   └── SceneNames.cs                 ← NUEVA: constantes de nombres de escena
    │   │
    │   ├── Context/
    │   │   └── SceneContext.cs               ← NUEVA: bus de estado tipado entre escenas
    │   │
    │   └── Games/
    │       ├── IGameBootstrapper.cs          ← NUEVA: contrato para cada minijuego
    │       ├── GameBootstrapperFactory.cs    ← NUEVA: resuelve IGameBootstrapper por game_type
    │       ├── BaseGameManager.cs            ← NUEVA: clase base con lógica compartida
    │       ├── ScoreCalculator.cs            ← NUEVA: extraído de GameManagers
    │       └── StarCalculator.cs             ← NUEVA: extraído de GameManagers
    │
    ├── UI/
    │   ├── Views/
    │   │   ├── Interfaces/
    │   │   │   ├── ILoginView.cs             ← NUEVA
    │   │   │   ├── IRegisterView.cs          ← NUEVA
    │   │   │   ├── IForgotPasswordView.cs    ← NUEVA
    │   │   │   ├── ISelectRoleView.cs        ← NUEVA
    │   │   │   └── IUserScreenView.cs        ← NUEVA
    │   │   ├── LoginView.cs
    │   │   ├── RegisterView.cs
    │   │   ├── ForgotPasswordView.cs
    │   │   ├── SelectRoleView.cs
    │   │   ├── UserScreenView.cs
    │   │   └── TestInitialUserFlowView.cs
    │   │
    │   ├── Presenters/
    │   │   ├── LoginPresenter.cs             ← convertir a Plain C#
    │   │   ├── RegisterPresenter.cs          ← convertir a Plain C#
    │   │   ├── ForgotPasswordPresenter.cs    ← convertir a Plain C#
    │   │   ├── SelectRolePresenter.cs
    │   │   ├── UserScreenPresenter.cs
    │   │   └── TestInitialUserFlowPresenter.cs
    │   │
    │   ├── Components/
    │   │   ├── InputFieldHandler.cs
    │   │   ├── PasswordToggle.cs
    │   │   ├── Selector.cs
    │   │   ├── DegreeSelector.cs
    │   │   ├── SessionButtons.cs
    │   │   ├── ToggleObjectButton.cs
    │   │   └── GameSelector.cs
    │   │
    │   └── Screens/                          ← NUEVA: orquestadores de pantalla (eran Managers)
    │       └── UserScreenController.cs       ← renombrado desde UserScreenManager
    │
    ├── Gameplay/
    │   ├── DragAndDrop/                      ← MOVER desde Drop_Slot/
    │   │   ├── DragDropGameManager.cs        ← renombrado desde GameManager.cs
    │   │   ├── DragHandler.cs
    │   │   ├── DropSlot.cs
    │   │   ├── ItemPool.cs
    │   │   ├── RandomizarOrganos.cs
    │   │   └── RestartLevel.cs
    │   │
    │   ├── FoodRiddles/                      ← MOVER desde Ripples/
    │   │   ├── FoodRiddlesGameManager.cs     ← renombrado desde GameManagerFood.cs
    │   │   └── Mouth.cs
    │   │
    │   └── Shared/
    │       └── SoundManager.cs               ← MOVER, extraer ISoundManager
    │
    ├── SceneDesign/                          ← MANTENER pero reorganizar
    │   ├── Navigation/
    │   │   ├── SceneLoader.cs                ← DEPRECAR, usar ISceneNavigator
    │   │   ├── RolePreferences.cs
    │   │   └── IslandInteraction.cs
    │   ├── UI/
    │   │   ├── GameInfoUI.cs                 ← dividir en Presenter + View
    │   │   ├── BoxGameSelector.cs
    │   │   ├── BookAnimation.cs
    │   │   ├── UIVisualizer.cs               ← dividir en DataLoader + View
    │   │   └── PreviewImageLoader.cs
    │   ├── Background/
    │   │   └── BackgroundLoader.cs
    │   ├── State/
    │   │   └── EstadoManager.cs              ← refactorizar para inyectar dependencias
    │   └── RA/
    │       ├── ARModelController.cs
    │       └── InfoPanelManager.cs
    │
    └── _ToDelete/                            ← NUEVA: código legado a eliminar
        ├── DatabaseController.cs
        ├── GameManagerDrop.cs
        └── TermsRepository.cs
```

---

## 6. Contratos de Interfaces (Abstracciones Clave)

### 6.1 IDatabaseProvider

```csharp
// Core/Database/IDatabaseProvider.cs
public interface IDatabaseProvider
{
    bool IsReady { get; }
    SQLiteConnection Connection { get; }
    event Action OnReady;
}
```

**Por qué:** Permite que los servicios esperen la BD sin depender de `DatabaseManager.Instance`. En tests se puede inyectar un `FakeDatabaseProvider` que devuelve `IsReady = true` inmediatamente.

---

### 6.2 IRepository<T> + interfaces específicas

```csharp
// Core/Repositories/Interfaces/IRepository.cs
public interface IRepository<T> where T : class
{
    T GetById(int id);
    List<T> GetAll();
}

// Core/Repositories/Interfaces/IUserRepository.cs
public interface IUserRepository : IRepository<UserModel>
{
    UserModel GetByName(string name);
    int InsertUser(UserModel user);
    bool UpdatePassword(int userId, string newPasswordHash);
    UserModel LoginStudent(string name, string password);
    UserModel LoginTeacher(string email, string password);
}

// Core/Repositories/Interfaces/IGameActivityRepository.cs
public interface IGameActivityRepository
{
    GameActivityData GetById(int id);
    GameActivityData GetByModuleId(int moduleId);
    GameActivityData GetByActivityId(int activityId);
    List<GameActivityData> GetAllByModuleId(int moduleId);
    List<GameActivityData> GetAll();
}
```

---

### 6.3 Interfaces de Servicios

```csharp
// Core/Services/Interfaces/IAuthService.cs
public interface IAuthService
{
    IEnumerator LoginStudent(string name, string password, Action<UserModel> callback);
    IEnumerator LoginTeacher(string email, string password, Action<UserModel> callback);
    IEnumerator RegisterStudent(string name, string password, int degreeId, Action<bool, string> callback);
    IEnumerator RegisterTeacher(string name, string email, string password, int degreeId, Action<bool, string> callback);
    IEnumerator SaveSecurityQuestion(int userId, int questionId, string answer, Action<bool> callback);
    IEnumerator VerifySecurityAnswer(int userId, string answer, Action<bool> callback);
    IEnumerator ChangePassword(int userId, string newPassword, Action<bool> callback);
}

// Core/Services/Interfaces/IGameActivityService.cs
public interface IGameActivityService
{
    IEnumerator GetGameActivity(int id, Action<GameActivityData> callback);
    IEnumerator GetGameActivityByModuleId(int moduleId, Action<GameActivityData> callback);
    IEnumerator GetAllGameActivitiesByModuleId(int moduleId, Action<List<GameActivityData>> callback);
}
```

---

### 6.4 Interfaces de Vistas (MVP)

```csharp
// UI/Views/Interfaces/ILoginView.cs
public interface ILoginView
{
    string NameOrEmail { get; }
    string Password { get; }
    bool RememberSession { get; }
    void ShowError(string message);
    void ShowSuccess(string message);
    void SetLoading(bool isLoading);
}

// UI/Views/Interfaces/IRegisterView.cs
public interface IRegisterView
{
    string Name { get; }
    string Email { get; }
    string Password { get; }
    string ConfirmPassword { get; }
    int SelectedDegreeId { get; }
    int SelectedSecurityQuestionId { get; }
    string SecurityAnswer { get; }
    void ShowError(string message);
    void ShowSuccess(string message);
    void SetRegistrationComplete(bool complete);
}
```

---

### 6.5 IGameBootstrapper (OCP para nuevos juegos)

```csharp
// Application/Games/IGameBootstrapper.cs
public interface IGameBootstrapper
{
    string GameType { get; }
    IEnumerator Bootstrap(GameActivityData data, Action onReady);
}

// Application/Games/GameBootstrapperFactory.cs
public class GameBootstrapperFactory
{
    private readonly Dictionary<string, IGameBootstrapper> _bootstrappers;

    public GameBootstrapperFactory(IEnumerable<IGameBootstrapper> bootstrappers)
    {
        _bootstrappers = bootstrappers.ToDictionary(b => b.GameType);
    }

    public IGameBootstrapper GetBootstrapper(string gameType)
    {
        return _bootstrappers.TryGetValue(gameType, out var b) ? b : null;
    }
}
```

**Beneficio:** Agregar `WordSearchGameManager : IGameBootstrapper` no requiere modificar `GameBootstrapperFactory`. Solo se registra en la colección inicial. Principio Open/Closed cumplido.

---

### 6.6 SceneContext — Reemplazo de PlayerPrefs como bus de estado

```csharp
// Application/Context/SceneContext.cs
public static class SceneContext
{
    public static int SelectedModuleId { get; private set; }
    public static int SelectedGameActivityId { get; private set; }
    public static string SelectedGameType { get; private set; }

    public static void SetSelectedGame(int moduleId, int gameActivityId, string gameType)
    {
        SelectedModuleId = moduleId;
        SelectedGameActivityId = gameActivityId;
        SelectedGameType = gameType;
    }

    public static void Clear() 
    {
        SelectedModuleId = 0;
        SelectedGameActivityId = 0;
        SelectedGameType = null;
    }
}
```

**Beneficio:** Tipado, rastreable, sin strings mágicos, no persiste en disco entre sesiones.

---

### 6.7 SceneNames — Eliminar strings hardcodeados

```csharp
// Application/Navigation/SceneNames.cs
public static class SceneNames
{
    public const string Login          = "Login";
    public const string SelectRole     = "SelectRole";
    public const string Home           = "TestInitialuserFlow";
    public const string GameSelection  = "GameSelection";
    public const string DragAndDrop    = "DragAndDrop";
    public const string FoodRiddles    = "FoodRiddles";
    public const string RAScreen       = "RAScreen";
}
```

---

### 6.8 BaseGameManager — Eliminar duplicación entre minijuegos

```csharp
// Application/Games/BaseGameManager.cs
public abstract class BaseGameManager : MonoBehaviour
{
    protected IGameActivityService GameActivityService;
    protected IActivityService ActivityService;
    protected IResultActivityService ResultService;

    protected ActivityData ActivityData;
    protected int IdActivity;
    protected int IdUser;
    protected int Score;
    protected int MaxScore;
    protected int Attempts;
    protected float StartTime;

    protected virtual void Awake()
    {
        // Los hijos inyectan sus dependencias aquí o mediante Unity Inspector
        StartTime = Time.time;
        ResolveLoggedInUser();
    }

    protected IEnumerator Bootstrap(int gameActivityId)
    {
        yield return new WaitUntil(() => DatabaseManager.Instance?.IsReady == true);
        GameActivityData data = null;
        yield return StartCoroutine(GameActivityService.GetGameActivity(gameActivityId, r => data = r));
        if (data == null) yield break;
        IdActivity = data.id_activity;
        yield return StartCoroutine(ActivityService.GetActivity(IdActivity, r => ActivityData = r));
        if (ActivityData == null) yield break;
        MaxScore = Mathf.Max(1, ActivityData.max_score);
        yield return StartCoroutine(SetupGame(data));
    }

    protected abstract IEnumerator SetupGame(GameActivityData data);

    protected int CalculateStars()
    {
        int maxStars = ActivityData != null ? Mathf.Max(0, ActivityData.max_star) : 0;
        if (maxStars == 0 || MaxScore <= 0) return 0;
        return Mathf.Clamp(Mathf.RoundToInt(Score / (float)MaxScore * maxStars), 0, maxStars);
    }

    protected string GetCompletionTime()
    {
        float elapsed = Mathf.Max(0f, Time.time - StartTime);
        return $"{Mathf.FloorToInt(elapsed / 60f):00}:{Mathf.FloorToInt(elapsed % 60f):00}";
    }

    protected void SaveResult()
    {
        if (IdUser <= 0) return;
        ResultService.SaveResult(IdUser, IdActivity, Score, CalculateStars(), Attempts, GetCompletionTime());
    }

    private void ResolveLoggedInUser()
    {
        if (UserSessionManager.Instance?.CurrentUser != null)
            IdUser = UserSessionManager.Instance.CurrentUser.id_user;
    }
}
```

**Con esto, `DragDropGameManager` y `FoodRiddlesGameManager` solo implementan `SetupGame()` y la lógica específica de su juego.**

---

## 7. Hoja de Ruta de Migración

Esta hoja de ruta está ordenada para minimizar regresiones: primero se establece la infraestructura (sin cambios en comportamiento), luego se refactorizan las capas de arriba hacia abajo.

### Fase 1 — Fundamentos (Sin impacto en comportamiento) ✅

| Tarea | Archivos | Esfuerzo |
|---|---|---|
| Renombrar carpeta `Scrips` → `Scripts` | Todos los `.cs`, `.meta` | Alto (rename global en Unity) |
| Crear `SceneNames.cs` y reemplazar todos los strings de escena | `SceneLoader`, `SessionBootstrapper`, Presenters | Bajo |
| Crear `SceneContext.cs` y migrar `PlayerPrefs` de estado de runtime | `BoxGameSelector`, `GameSelector`, `GameManager`, `GameManagerFood` | Medio |
| Eliminar código legado (`DatabaseController`, `GameManagerDrop`, `TermsRepository`) | 3 archivos | Bajo |
| Crear `_ToDelete/` y mover código legado antes de eliminar | 3 archivos | Bajo |

### Fase 2 — Interfaces de Infraestructura

| Tarea | Archivos | Esfuerzo |
|---|---|---|
| Crear `IDatabaseProvider` e implementarlo en `DatabaseManager` | 1 nueva, 1 modificada | Bajo |
| Crear interfaces para todos los repositorios | 7 nuevas interfaces | Medio |
| Hacer que cada Repository implemente su interfaz | 7 archivos modificados | Bajo |
| Centralizar `PasswordHasher` (eliminar la privada en AuthService) | `AuthService` + `PasswordHasher` | Bajo |

### Fase 3 — Interfaces de Servicios

| Tarea | Archivos | Esfuerzo |
|---|---|---|
| Crear interfaces para todos los servicios | 6 nuevas interfaces | Medio |
| Eliminar dependencia directa a `DatabaseManager.Instance` en servicios | 6 servicios (inyectar `IDatabaseProvider`) | Medio |
| Eliminar el patrón `EnsureRepository()` y `EnsureDatabaseManagerExists()` | `GameActivityService`, `GameManagerFood` | Bajo |

### Fase 4 — Capa de Presentación

| Tarea | Archivos | Esfuerzo |
|---|---|---|
| Crear interfaces para todas las Views | 5 nuevas interfaces | Bajo |
| Hacer que `LoginView`, `RegisterView`, etc. implementen sus interfaces | 5 archivos modificados | Bajo |
| Convertir `RegisterPresenter` y `ForgotPasswordPresenter` de `MonoBehaviour` a Plain C# | 2 archivos | Medio |
| Actualizar Views para instanciar Presenters correctamente | 2 archivos | Bajo |

### Fase 5 — Capa de Aplicación y Juegos

| Tarea | Archivos | Esfuerzo |
|---|---|---|
| Crear `BaseGameManager` | 1 nuevo archivo | Alto |
| Refactorizar `GameManager` → `DragDropGameManager : BaseGameManager` | 1 archivo | Alto |
| Refactorizar `GameManagerFood` → `FoodRiddlesGameManager : BaseGameManager` | 1 archivo | Alto |
| Crear `IGameBootstrapper` y `GameBootstrapperFactory` | 2 nuevos archivos | Medio |
| Refactorizar `EstadoManager` para inyectar `IProgressRepository` | 1 archivo | Medio |
| Dividir `GameInfoUI` en Presenter + View | 2 archivos | Alto |
| Mover modelos de dominio a `Domain/Models/` | 10 archivos | Bajo |

### Fase 6 — Limpieza Final

| Tarea | Archivos | Esfuerzo |
|---|---|---|
| Eliminar `_ToDelete/` | 3 archivos | Bajo |
| Eliminar `SceneLoader` reemplazado por `ISceneNavigator` | 1 archivo | Bajo |
| Revisar todos los `Debug.Log` y convertirlos a condicional `#if UNITY_EDITOR` | Global | Medio |
| Añadir `ISoundManager` y hacer `SoundManager` reemplazable | 1 interfaz + 1 modificada | Bajo |

---

## 8. Patrones de Código Recomendados

### 8.1 Patrón de servicio con inyección de IDatabaseProvider

```csharp
// ANTES (acoplado a DatabaseManager.Instance)
public class GameActivityService
{
    private GameActivityRepository repository;

    public IEnumerator GetGameActivity(int id, Action<GameActivityData> callback)
    {
        if (DatabaseManager.Instance == null) { callback?.Invoke(null); yield break; }
        if (!DatabaseManager.Instance.IsReady)
            yield return new WaitUntil(() => DatabaseManager.Instance.IsReady);
        // ...
    }
}

// DESPUÉS (desacoplado, testeable)
public class GameActivityService : IGameActivityService
{
    private readonly IGameActivityRepository _repository;
    private readonly IDatabaseProvider _dbProvider;

    public GameActivityService(IGameActivityRepository repository, IDatabaseProvider dbProvider)
    {
        _repository = repository;
        _dbProvider = dbProvider;
    }

    public IEnumerator GetGameActivity(int id, Action<GameActivityData> callback)
    {
        if (!_dbProvider.IsReady)
            yield return new WaitUntil(() => _dbProvider.IsReady);

        GameActivityData result = null;
        try { result = _repository.GetById(id); }
        catch (Exception ex) { Debug.LogError($"[GameActivityService] {ex.Message}"); }
        callback?.Invoke(result);
    }
}
```

### 8.2 Presenter como Plain C# (no MonoBehaviour)

```csharp
// ANTES
public class RegisterPresenter : MonoBehaviour
{
    [SerializeField] private RegisterStudentView _view;
    // Unity lifecycle acoplado a lógica de negocio
}

// DESPUÉS
public class RegisterPresenter
{
    private readonly IRegisterView _view;
    private readonly IAuthService _authService;
    private readonly IRegisterValidator _validator;

    public RegisterPresenter(IRegisterView view, IAuthService authService, IRegisterValidator validator)
    {
        _view = view;
        _authService = authService;
        _validator = validator;
    }

    public IEnumerator OnRegisterPressed()
    {
        var result = _validator.ValidateStudent(_view.Name, _view.Password, _view.SelectedDegreeId);
        if (!result.IsValid) { _view.ShowError(result.ErrorMessage); yield break; }
        // ...
    }
}

// La View sigue siendo MonoBehaviour y crea el Presenter en Start()
public class RegisterView : MonoBehaviour, IRegisterView
{
    private RegisterPresenter _presenter;

    void Start()
    {
        var authService = ServiceLocator.Get<IAuthService>();
        var validator = new RegisterValidator();
        _presenter = new RegisterPresenter(this, authService, validator);
    }
}
```

### 8.3 DragDropGameManager heredando BaseGameManager

```csharp
public class DragDropGameManager : BaseGameManager
{
    [Header("Drag & Drop")]
    public DragHandler[] items;
    public DropSlot[] zones;

    private DragDropConfig _config;

    protected override IEnumerator SetupGame(GameActivityData data)
    {
        _config = JsonConvert.DeserializeObject<DragDropConfig>(data.config_json);
        // Solo lógica específica del juego Drag & Drop
        yield return StartCoroutine(LoadSprites());
        AssignItemsAndZones();
    }

    public void OnItemDropped(string itemId, string zoneId)
    {
        bool correct = _config.IsCorrectZone(itemId, zoneId);
        if (correct) { Score += PointsPerZone; Attempts++; }
        else { Score = Mathf.Max(0, Score - PointsPerZone); Attempts++; }
        if (AllItemsPlaced()) StartCoroutine(ShowVictory());
    }

    private IEnumerator ShowVictory()
    {
        yield return StartCoroutine(AnimateVictoryPanel());
        SaveResult();
    }
}
```

---

## 9. Reglas de Estilo y Convenciones

### 9.1 Naming

| Tipo | Convención | Ejemplo |
|---|---|---|
| Interfaces | `I` + PascalCase | `IAuthService`, `IUserRepository` |
| Clases abstractas | `Base` + PascalCase | `BaseGameManager` |
| Clases concretas | PascalCase | `AuthService`, `UserRepository` |
| Constantes de escenas | `SceneNames.NombreEscena` | `SceneNames.Home` |
| Campos privados | `_camelCase` | `_authService`, `_repository` |
| Propiedades públicas | PascalCase | `IsReady`, `CurrentUser` |

### 9.2 Reglas de arquitectura

1. **Las clases de datos (Models) no conocen servicios ni repositorios.**
2. **Los repositorios no conocen servicios ni la capa de presentación.**
3. **Los servicios no dependen de `MonoBehaviour` ni de Unity directamente** (excepto `IEnumerator`/`Coroutine` que son necesarios).
4. **Los Presenters son Plain C#**; si necesitan Unity, se lo piden a la View.
5. **Las Views son `MonoBehaviour`**; crean o reciben sus Presenters y exponen propiedades de UI.
6. **Nunca `PlayerPrefs` para estado de runtime entre escenas**; usar `SceneContext`.
7. **`PlayerPrefs` solo para: sesión persistida en disco, preferencias de usuario (rol guardado).**
8. **Nunca `new` en código de alto nivel para instanciar servicios o repositorios**; delegarlo al punto de composición (ServiceLocator o el GameObject inicial).

### 9.3 Comentarios

Solo comentar el **por qué**, nunca el qué:
```csharp
// WAL mode mejora concurrencia en escrituras paralelas desde coroutines.
conn.ExecuteScalar<string>("PRAGMA journal_mode=WAL;");

// No eliminar: iOS requiere FullMutex para acceso multi-thread a SQLite.
SQLiteOpenFlags.FullMutex
```

### 9.4 Debug en producción

```csharp
// Solo en editor, cero overhead en builds
#if UNITY_EDITOR
    Debug.Log($"[GameActivityService] Cargando activity {id}");
#endif

// Errores reales siempre visibles
Debug.LogError($"[GameActivityService] Error crítico: {ex.Message}");
```

---

## 10. Métricas Actuales del Proyecto

| Métrica | Valor actual | Objetivo |
|---|---|---|
| Total de scripts | 85 | ~85 (reorganizados, no más) |
| Scripts con interfaces | ~5 (6%) | ~35 (40%+) |
| Presenters como Plain C# | 4 de 6 (67%) | 6 de 6 (100%) |
| Views con interfaz | 1 de 6 (17%) | 6 de 6 (100%) |
| Repositorios con interfaz | 0 de 8 (0%) | 8 de 8 (100%) |
| Servicios con interfaz | 0 de 6 (0%) | 6 de 6 (100%) |
| Strings de escena hardcodeados | ~15 lugares | 0 (todos en SceneNames) |
| Usos de PlayerPrefs como bus de estado | ~8 lugares | 0 (SceneContext) |
| Clases legado sin uso | 3 | 0 |
| GameManagers con código duplicado | 2 (100% duplicado) | 0 (heredan BaseGameManager) |

---

## Apéndice A — Decisiones de Diseño Justificadas

### ¿Por qué no usar un DI Container completo (Zenject/VContainer)?

El proyecto está en etapa media de desarrollo con 85 scripts. Introducir un DI Container en este punto requeriría refactorizar todos los scripts y añadiría una curva de aprendizaje. La propuesta usa **ServiceLocator + constructor injection** que es más liviana, igualmente desacoplada, y puede migrarse a Zenject en una fase futura si el proyecto crece.

### ¿Por qué mantener `IEnumerator` en los servicios?

Unity SQLite4Unity3d es síncrono, pero esperar a `DatabaseManager.IsReady` requiere `WaitUntil` que solo funciona en Coroutines. La alternativa (async/await con UniTask) es válida pero requeriría una dependencia adicional. Se mantiene `IEnumerator` para preservar la compatibilidad con el código existente.

### ¿Por qué `SceneContext` estático en vez de un ScriptableObject?

`ScriptableObject` persistiría en disco entre sesiones y requeriría lógica de limpieza. `SceneContext` estático vive en memoria y se limpia automáticamente al reiniciar la app, que es el comportamiento correcto para estado de navegación.

### ¿Por qué `BaseGameManager` y no una interfaz pura?

`DragDropGameManager` y `FoodRiddlesGameManager` comparten ~60% de código (bootstrap, cálculo de estrellas, guardado de resultado, animación de victoria). Una interfaz solo definiría el contrato pero no eliminaría la duplicación. La clase base abstracta elimina el código duplicado y deja el contrato abierto para extensión.

---

*Fin del informe. Para cualquier decisión de implementación concreta, revisar primero el código actual con `git blame` para preservar el contexto de cambios recientes.*
