# Reporte de Bugs y Errores del Proyecto RA-Education

**Fecha:** 2026-06-23  
**Rama analizada:** `developer-leal`  
**Total de scripts analizados:** 80 archivos `.cs`

---

## Resumen Ejecutivo

| Severidad | Cantidad |
|-----------|----------|
| 🔴 Crítico  | 5  |
| 🟠 Alto     | 9  |
| 🟡 Medio    | 11 |
| 🔵 Bajo     | 8  |

---

## 🔴 CRÍTICOS — Pueden causar crash o build roto

---

### BUG-01 · `GameInfoUI.cs:4` — `using UnityEditor` en script de runtime

**Archivo:** [Assets/Scrips/SceneDesign/GameInfoUI.cs](Assets/Scrips/SceneDesign/GameInfoUI.cs#L4)

```csharp
using UnityEditor; // ← LÍNEA 4
```

**Problema:** El namespace `UnityEditor` solo está disponible dentro del Editor de Unity. Al hacer un **build de producción (Android/iOS/PC)**, el compilador no encontrará este namespace y el build **fallará con error de compilación**. Este es el bug más crítico del proyecto.

**Solución:** Eliminar la línea `using UnityEditor;` del script. Si era necesaria para algo específico, envolver con `#if UNITY_EDITOR`.

---

### BUG-02 · `DragHandler.cs:59` — NullReferenceException si no existe el tag `ItemDraggerParent`

**Archivo:** [Assets/Scrips/Drop_Slot/DragHandler.cs](Assets/Scrips/Drop_Slot/DragHandler.cs#L59)

```csharp
itemDraggerParent = GameObject.FindGameObjectWithTag("ItemDraggerParent").transform;
```

**Problema:** Si no existe ningún `GameObject` con el tag `"ItemDraggerParent"` en la escena (por olvido en el Inspector o error de nombre del tag), `FindGameObjectWithTag` retorna `null` y llamar `.transform` sobre él lanza `NullReferenceException`, crasheando el juego al inicio. Además, el error de drag completo falla silenciosamente después.

**Solución:**
```csharp
var parent = GameObject.FindGameObjectWithTag("ItemDraggerParent");
if (parent == null) { Debug.LogError("DragHandler: No se encontró 'ItemDraggerParent'."); return; }
itemDraggerParent = parent.transform;
```

---

### BUG-03 · `IslandInteraction.cs:55` — `selected_activity_id` se sobreescribe con el `moduleId`

**Archivo:** [Assets/Scrips/SceneDesign/IslandInteraction.cs](Assets/Scrips/SceneDesign/IslandInteraction.cs#L54-L56)

```csharp
PlayerPrefs.SetInt("selected_module_id", moduleId);
PlayerPrefs.SetInt("selected_activity_id", moduleId); // ← BUG: guarda moduleId como activity_id
PlayerPrefs.Save();
```

**Problema:** La llave `selected_activity_id` debería contener un `id_game_activity` (de la tabla `game_activity`), pero aquí se le asigna el `moduleId`. Luego, `GameManager.cs` y `GameManagerFood.cs` leen esta llave esperando un `id_game_activity`. Si los IDs de módulo no coinciden con ningún `id_game_activity`, los juegos cargarán la actividad equivocada o el ID por defecto (1).

**Solución:** Eliminar la segunda línea. La key `selected_activity_id` debe ser asignada solo por `GameInfoUI.ShowGame()` cuando el usuario hace clic en "Jugar".

---

### BUG-04 · `Mouth.cs:6` — `gameManager` public sin protección contra null

**Archivo:** [Assets/Scrips/Ripples/Mouth.cs](Assets/Scrips/Ripples/Mouth.cs#L6-L17)

```csharp
public GameManagerFood gameManager; // debe asignarse manualmente en Inspector

public void OnDrop(PointerEventData eventData)
{
    // ...
    bool correcto = gameManager.EvaluarItem(item.itemId); // ← crash si gameManager es null
```

**Problema:** `gameManager` es un campo público sin comprobación de null. Si se olvida asignar la referencia en el Inspector, al soltar cualquier alimento en la boca se producirá un `NullReferenceException`.

**Solución:**
```csharp
if (gameManager == null) { Debug.LogError("Mouth: gameManager no asignado."); return; }
bool correcto = gameManager.EvaluarItem(item.itemId);
```

---

### BUG-05 · `AuthService.cs:287-351` — Clase interna `PasswordHasher` duplicada y oculta la global

**Archivo:** [Assets/Scrips/Core/Service/AuthService.cs](Assets/Scrips/Core/Service/AuthService.cs#L287)

**Problema:** Dentro de `AuthService` existe una **clase privada estática interna** llamada `PasswordHasher` (líneas 287–351) con los mismos métodos que la clase pública global en `Core/Security/PasswordHasher.cs`. La clase interna shadea el nombre dentro del contexto de `AuthService`.

- Las llamadas en `LoginStudent`/`LoginTeacher` (líneas 32, 42, 60, 70) llaman al `PasswordHasher` **global** (correcto).
- Sin embargo, existe el riesgo real de que un desarrollador futuro modifique solo una de las dos implementaciones, generando comportamiento divergente: un usuario podría autenticarse con la lógica "A" y registrarse con la lógica "B", volviendo las contraseñas incompatibles.

**Solución:** Eliminar la clase `PasswordHasher` privada dentro de `AuthService` y usar exclusivamente `global::PasswordHasher` (el de `Core/Security`).

---

## 🟠 ALTO — Funcionalidad rota o pérdida de datos

---

### BUG-06 · `SoundManager.cs` — Singleton sin `DontDestroyOnLoad` y sin null-checks

**Archivo:** [Assets/Scrips/Drop_Slot/SoundManager.cs](Assets/Scrips/Drop_Slot/SoundManager.cs)

```csharp
private void Awake() { instance = this; } // Sin DontDestroyOnLoad ni check de duplicados

public void PlayCorrect()
{
    audioSource.PlayOneShot(correctSound); // crash si audioSource o correctSound son null
}
```

**Problemas:**
1. Sin `DontDestroyOnLoad`, al cambiar de escena se destruye la instancia y `instance` queda apuntando a un objeto destruido. El primer acceso lanza `MissingReferenceException`.
2. Sin guard de duplicados en `Awake`, múltiples instancias sobreescriben `instance`.
3. Sin null-check en `PlayCorrect`/`PlayWrong`: si `audioSource` no está asignado en el Inspector → crash.

**Solución:**
```csharp
private void Awake()
{
    if (instance != null && instance != this) { Destroy(gameObject); return; }
    instance = this;
    DontDestroyOnLoad(gameObject);
}
public void PlayCorrect()
{
    if (audioSource != null && correctSound != null) audioSource.PlayOneShot(correctSound);
}
```

---

### BUG-07 · `ResultActivityRepository.cs:10-12` — Constructor sin verificación de null

**Archivo:** [Assets/Scrips/Core/Data/Repository/ResultActivityRepository.cs](Assets/Scrips/Core/Data/Repository/ResultActivityRepository.cs#L9-L12)

```csharp
public ResultActivityRepository()
{
    _connection = DatabaseManager.Instance.GetConnection(); // NullRefException si Instance es null
}
```

**Problema:** A diferencia de otros repositorios del proyecto (como `GameActivityRepository` y `UserRepository`) que tienen guards de null, este constructor accede directamente al singleton sin verificar. Si se construye antes de que la DB esté lista, lanzará `NullReferenceException`.

**Solución:** Añadir las mismas comprobaciones que tiene `UserRepository`:
```csharp
if (DatabaseManager.Instance == null) throw new InvalidOperationException("DatabaseManager no disponible.");
_connection = DatabaseManager.Instance.GetConnection();
if (_connection == null) throw new InvalidOperationException("Conexión es null.");
```

---

### BUG-08 · `ActivityRepository.cs:11` — Constructor sin verificación de null

**Archivo:** [Assets/Scrips/Core/Data/Repository/ActivityRepository.cs](Assets/Scrips/Core/Data/Repository/ActivityRepository.cs#L11)

```csharp
public ActivityRepository()
{
    _connection = DatabaseManager.Instance.GetConnection(); // sin null-check
}
```

**Problema:** Idéntico al BUG-07. No hay ninguna verificación de que `DatabaseManager.Instance` existe antes de usarlo.

---

### BUG-09 · `LoginPresenter.cs` + `LoginStudentView.cs` — Lógica de sesión y navegación duplicada

**Archivos:**
- [Assets/Scrips/UI/Presenters/LoginPresenter.cs](Assets/Scrips/UI/Presenters/LoginPresenter.cs#L53-L55)
- [Assets/Scrips/UI/Views/LoginView.cs](Assets/Scrips/UI/Views/LoginView.cs#L86-L117)

**Problema:** Cuando el login es exitoso, ocurre lo siguiente:
1. `LoginPresenter.LoginStudent()` llama internamente a `SaveUserAndLoadScene()` → establece usuario en `UserSessionManager` y carga la escena.
2. `LoginStudentView.Login()` recibe el resultado y vuelve a llamar `UserSessionManager.Instance.SetCurrentUser(response.User)` y luego `SceneManager.LoadScene("TestInitialuserFlow")`.

Hay **doble carga de escena**: una dentro del presenter y otra en la vista. En Unity, `LoadScene` no es instantáneo pero la segunda llamada puede generar un estado inconsistente y logs de error.

**Solución:** El Presenter no debe llamar a `SceneManager.LoadScene` — ese es trabajo de la Vista. El presenter debe solo retornar el resultado y dejar que la vista decida la navegación.

---

### BUG-10 · `AuthService.FindUserByNameAndRole` — Profesor buscado por nombre en lugar de email

**Archivo:** [Assets/Scrips/Core/Service/AuthService.cs](Assets/Scrips/Core/Service/AuthService.cs#L213)

```csharp
else if (roleId == 2)
{
    return userRepository.LoginTeacher(name); // LoginTeacher hace JOIN por t.email = ?, no por nombre
}
```

**Problema:** `UserRepository.LoginTeacher()` ejecuta `WHERE t.email = ?`, pero aquí se pasa `name` (nombre del usuario). Esto nunca encontrará a un profesor por su nombre, retornará siempre `null`. Afecta el flujo de recuperación de contraseña para profesores.

---

### BUG-11 · `DragHandler.cs:106-108` — Referencia `anim` sin null-check en corrutina

**Archivo:** [Assets/Scrips/Drop_Slot/DragHandler.cs](Assets/Scrips/Drop_Slot/DragHandler.cs#L104-L113)

```csharp
IEnumerator PlayAndDisappear()
{
    anim.ResetTrigger("Correct"); // ← crash si no hay Animator en el GameObject
    anim.SetTrigger("Correct");
    yield return null;
    yield return null;
    float duracion = anim.GetCurrentAnimatorStateInfo(0).length; // ← crash
```

**Problema:** `anim` se obtiene con `GetComponent<Animator>()` en `Start()`. Si el GameObject no tiene `Animator`, `anim` será null y las tres llamadas lanzarán `NullReferenceException`.

**Solución:** Añadir `if (anim == null) { Destroy(gameObject); yield break; }` al inicio de `PlayAndDisappear`.

---

### BUG-12 · `IslandInteraction.cs:73-75` — Referencias sin null-check en `OpenBook()`

**Archivo:** [Assets/Scrips/SceneDesign/IslandInteraction.cs](Assets/Scrips/SceneDesign/IslandInteraction.cs#L73-L75)

```csharp
canvasTopHUD.SetActive(false);    // crash si no asignado
canvasBottomInfo.SetActive(false); // crash si no asignado
bookSystem.SetActive(true);        // crash si no asignado
```

**Problema:** Los tres campos son públicos sin comprobación de null. Si cualquiera no está asignado en el Inspector, se produce `NullReferenceException` al tocar una isla.

---

### BUG-13 · `IslandInteraction.cs:37` — `Camera.main` sin null-check

**Archivo:** [Assets/Scrips/SceneDesign/IslandInteraction.cs](Assets/Scrips/SceneDesign/IslandInteraction.cs#L37)

```csharp
Ray ray = Camera.main.ScreenPointToRay(position); // crash si Camera.main es null
```

**Problema:** `Camera.main` retorna `null` si no existe una cámara con el tag `MainCamera`. Si esto ocurre, la línea lanza `NullReferenceException` en cada frame que haya input.

---

### BUG-14 · `RegisterStudentView.cs` — Variable `isRegistering` nunca se pone en `true`

**Archivo:** [Assets/Scrips/UI/Views/RegisterView.cs](Assets/Scrips/UI/Views/RegisterView.cs#L45-L148)

```csharp
bool isRegistering = false; // se declara aquí

public void Register()
{
    if (isRegistering) return; // se comprueba...
    // ... pero nunca se hace: isRegistering = true;
```

**Problema:** La bandera de "registro en progreso" nunca se activa, por lo que el guard anti-doble-clic no tiene efecto. Un usuario puede presionar el botón múltiples veces mientras la BD procesa, intentando insertar el mismo usuario más de una vez y generando errores de restricción SQLite.

---

## 🟡 MEDIO — Comportamiento incorrecto o experiencia degradada

---

### BUG-15 · `AutoLoginService.cs` — `userRepository` inyectado nunca se usa

**Archivo:** [Assets/Scrips/Core/Session/AutoLoginService.cs](Assets/Scrips/Core/Session/AutoLoginService.cs#L11-L17)

```csharp
private readonly UserRepository userRepository; // inyectado en constructor...

private UserModel GetUserById(int userId)
{
    var connection = DatabaseManager.Instance?.GetConnection(); // ...pero se accede directo a la BD
    var result = connection.Table<UserModel>()...
}
```

**Problema:** El `UserRepository` se inyecta en el constructor (buena práctica para testabilidad), pero `GetUserById` ignora el repositorio y accede directamente al `DatabaseManager`. Rompe el propósito de la inyección de dependencias y hace el código no testeable.

---

### BUG-16 · `RestartLevel.cs` — `GameObject.Find` frágil y costoso

**Archivo:** [Assets/Scrips/Drop_Slot/RestartLevel.cs](Assets/Scrips/Drop_Slot/RestartLevel.cs#L12)

```csharp
GameObject winPanel = GameObject.Find("WinPanel");
```

**Problema:** `GameObject.Find` es lento (busca en toda la jerarquía activa) y frágil (depende del nombre exacto). Si el panel se renombra o está desactivado, no se encontrará y la pantalla de victoria permanecerá visible. Sería más correcto tener una referencia directa `[SerializeField]`.

---

### BUG-17 · `GameInfoUI.cs` — `selected_activity_id` almacena `id_game_activity`, pero el nombre sugiere `id_activity`

**Archivo:** [Assets/Scrips/SceneDesign/GameInfoUI.cs](Assets/Scrips/SceneDesign/GameInfoUI.cs#L117)

```csharp
PlayerPrefs.SetInt("selected_activity_id", currentGameID); // currentGameID es un id_game_activity
```

**Problema:** La clave `"selected_activity_id"` almacena un `id_game_activity` (tabla `game_activity`), no un `id_activity` (tabla `activity`). Los managers de juego lo leen correctamente como `id_game_activity`, pero el nombre de la clave es engañoso. Más grave: `IslandInteraction.cs` (BUG-03) escribe el `moduleId` en esa clave, lo que confirma que hay confusión entre estos IDs.

---

### BUG-18 · `ItemPool.cs` — Reparentar sin actualizar posición visual

**Archivo:** [Assets/Scrips/Drop_Slot/ItemPool.cs](Assets/Scrips/Drop_Slot/ItemPool.cs#L12-L13)

```csharp
DragHandler.objBeingDraged.transform.SetParent(transform);
// falta: DragHandler.objBeingDraged.transform.localPosition = Vector2.zero;
```

**Problema:** Al soltar un ítem sobre el pool, se reparenta pero no se reposiciona. El ítem queda visualmente en la posición donde fue soltado, en lugar de "volver al pool".

---

### BUG-19 · `BackgroundLoader.cs` y `PreviewImageLoader.cs` — Callback de Addressables tras destrucción del objeto

**Archivos:**
- [Assets/Scrips/Core/Data/BackgroundLoader.cs](Assets/Scrips/Core/Data/BackgroundLoader.cs#L131-L132)
- [Assets/Scrips/SceneDesign/PreviewImageLoader.cs](Assets/Scrips/SceneDesign/PreviewImageLoader.cs#L130-L131)

```csharp
_currentHandle = Addressables.LoadAssetAsync<Sprite>(addressableKey);
_currentHandle.Completed += OnBackgroundLoaded; // ← el objeto podría estar destruido al ejecutarse
```

**Problema:** Si el `GameObject` se destruye (cambio de escena, cierre del panel) antes de que termine la carga async, el callback `OnBackgroundLoaded` se ejecutará e intentará asignar un sprite a `backgroundImage` (o `previewImage`) que ya es null o apunta a un objeto destruido, generando `MissingReferenceException`.

**Solución:** Verificar `this != null` al inicio del callback, o usar `CancellationToken`.

---

### BUG-20 · `UserSessionManager.cs:67` — Nombre de escena hardcodeado en `Logout()`

**Archivo:** [Assets/Scrips/Core/Data/UserSessionManager.cs](Assets/Scrips/Core/Data/UserSessionManager.cs#L67)

```csharp
SceneManager.LoadScene("LoginStudentScene"); // nombre hardcodeado
```

**Problema:** Si la escena de login tiene otro nombre (por ejemplo en `BuildSettings` se llama diferente, o se renombra), el logout crasheará con `Scene not found`.

---

### BUG-21 · `TestInitialUserFlowPresenter.cs` — `DegreeService` instanciado sincrónicamente sin esperar BD

**Archivo:** [Assets/Scrips/UI/Presenters/TestInitialUserFlowPresenter.cs](Assets/Scrips/UI/Presenters/TestInitialUserFlowPresenter.cs#L52-L54)

```csharp
private string GetDegreeName(int degreeId)
{
    var degreeService = new DegreeService(); // nueva instancia en cada llamada
    var degree = degreeService.GetDegreeById(degreeId); // operación síncrona a BD
```

**Problema:** Se crea una nueva instancia de `DegreeService` en cada llamada a `LoadUserData()`. Si la base de datos no está lista en ese momento, puede fallar silenciosamente. Además, es ineficiente crear el servicio en cada llamada.

---

### BUG-22 · `IslandInteraction.cs` — Doble procesamiento de input en dispositivos táctiles con mouse

**Archivo:** [Assets/Scrips/SceneDesign/IslandInteraction.cs](Assets/Scrips/SceneDesign/IslandInteraction.cs#L15-L31)

```csharp
void Update()
{
    if (Input.touchCount > 0) { ... CheckHit(touch.position); } // procesa touch
    if (Input.GetMouseButtonDown(0)) { CheckHit(Input.mousePosition); } // Y también el mouse
}
```

**Problema:** En muchos dispositivos Android/iOS, un toque genera **tanto** un evento de touch **como** un evento de mouse. `CheckHit` (y por ende `OpenBook`) se llamará **dos veces** por el mismo toque, duplicando la acción.

**Solución:** Usar `else if` o el `#if ENABLE_LEGACY_INPUT_MANAGER` que `BoxGameSelector.cs` ya implementa correctamente.

---

### BUG-23 · `RegisterStudentView.cs` — `ShowError()` no muestra nada en UI

**Archivo:** [Assets/Scrips/UI/Views/RegisterView.cs](Assets/Scrips/UI/Views/RegisterView.cs#L333-L337)

```csharp
void ShowError(string message, float seconds = 3f)
{
    Debug.LogWarning(message); // ← solo log, nada en pantalla
}
```

**Problema:** Este método se llama cuando el Presenter no está disponible. El usuario no verá ningún mensaje de error en pantalla, solo en la consola (invisible en producción).

---

### BUG-24 · `LoginStudentView.cs` — Mezcla de sistemas de UI legacy y TMP

**Archivo:** [Assets/Scrips/UI/Views/LoginView.cs](Assets/Scrips/UI/Views/LoginView.cs)

**Problema:** El script usa `TMP_InputField` para las entradas pero `UnityEngine.UI.Text` (legacy) para los textos de error (`NameErrorText`, `PasswordErrorText`, `MessageErrorLoginText`). Si en la escena estos están configurados como `TextMeshProUGUI`, la referencia no se asignará desde el Inspector y los mensajes de error nunca se mostrarán (aunque no crasheará, por el null-check en `ShowFieldError`).

---

### BUG-25 · `GameManager.cs:294` — Método público `MostrarVictoria` legacy no documentado

**Archivo:** [Assets/Scrips/Drop_Slot/GameManager.cs](Assets/Scrips/Drop_Slot/GameManager.cs#L294-L297)

```csharp
public void MostrarVictoria(int scoreValue, int maxScoreValue) // método público legado
{
    StartCoroutine(MostrarVictoriaLegacy(scoreValue, maxScoreValue));
}
```

**Problema:** Existe un método público con firma diferente del privado (mismo nombre, parámetros distintos) que llama a un flujo legado diferente (`MostrarVictoriaLegacy`) con lógica de estrellas diferente. Si algún botón o script externo lo llama accidentalmente, el resultado del juego usará la lógica incorrecta.

---

## 🔵 BAJO — Calidad de código y advertencias

---

### BUG-26 · `GameManager.cs` y `GameManagerFood.cs` — Texto de puntaje incompleto

**Archivos:**
- [Assets/Scrips/Drop_Slot/GameManager.cs](Assets/Scrips/Drop_Slot/GameManager.cs#L263)
- [Assets/Scrips/Ripples/GameManagerFood.cs](Assets/Scrips/Ripples/GameManagerFood.cs#L223)

```csharp
scoreText.text = ": " + score; // falta el label (ej: "Puntos: 50")
```

**Problema:** El texto empieza con `": "` lo que sugiere que falta un prefijo como `"Puntos"` o `"Puntaje"`. El jugador verá `: 50` en lugar de `Puntos: 50`.

---

### BUG-27 · `GameSelector.cs` — IDs de actividad hardcodeados

**Archivo:** [Assets/Scrips/UI/Components/GameSelector.cs](Assets/Scrips/UI/Components/GameSelector.cs#L29-L37)

```csharp
public void LoadDigestive() { PlayerPrefs.SetInt("selected_activity_id", 1); ... }
public void LoadCellGame()  { PlayerPrefs.SetInt("selected_activity_id", 2); ... }
```

**Problema:** Los IDs 1 y 2 están hardcodeados. Si los registros en la BD tienen IDs diferentes, estos métodos no funcionarán. Estas funciones se marcan como "mantenidos para compatibilidad" pero representan deuda técnica.

---

### BUG-28 · `DatabaseManager.cs` — Hash MD5 usado para integridad (no criptografía, pero es deprecado)

**Archivo:** [Assets/Scrips/Core/Data/DatabaseManager.cs](Assets/Scrips/Core/Data/DatabaseManager.cs#L308-L313)

```csharp
using (MD5 md5 = MD5.Create())
```

**Problema:** MD5 está marcado como obsoleto para uso criptográfico. Para detección de cambios en archivos es aceptable, pero en algunas plataformas (iOS con modo de cumplimiento FIPS) `MD5.Create()` puede lanzar una excepción en tiempo de ejecución. Considerar usar SHA-256 o CRC32.

---

### BUG-29 · `MigrateContentTables` — Transacción puede quedar abierta si `COMMIT` falla

**Archivo:** [Assets/Scrips/Core/Data/DatabaseManager.cs](Assets/Scrips/Core/Data/DatabaseManager.cs#L232-L259)

```csharp
conn.Execute("BEGIN TRANSACTION;");
foreach (string table in ContentTables) { ... } // errores por tabla son capturados
conn.Execute("COMMIT;");   // ← si llega aquí pero COMMIT falla, la transacción queda abierta
conn.Execute("DETACH DATABASE newdb;");
```

**Problema:** El `COMMIT` y `DETACH` están fuera del bloque try-catch de cada tabla individual. Si `COMMIT` lanza una excepción no esperada, la transacción de SQLite queda abierta y la BD queda bloqueada para escrituras hasta que se cierre la conexión.

---

### BUG-30 · `BoxGameSelector.cs` — `OnMouseUpAsButton` puede duplicar `SelectGame`

**Archivo:** [Assets/Scrips/SceneDesign/BoxGameSelector.cs](Assets/Scrips/SceneDesign/BoxGameSelector.cs#L117-L119)

```csharp
private void OnMouseUpAsButton() { SelectGame("OnMouseUpAsButton"); }
```

**Problema:** `OnMouseUpAsButton` es un método de Unity que se llama cuando el mouse termina sobre el mismo collider donde empezó. `TryHandleMouseClick` detecta `MouseButtonDown` en `Update`, mientras que `OnMouseUpAsButton` se llama en `MouseButtonUp`. Son frames diferentes, por lo que el guard de `lastSelectionFrame` no los filtra como duplicados, pudiendo disparar dos selecciones consecutivas.

---

### BUG-31 · `IslandInteraction.cs` — Indentación rota (código no formateado)

**Archivo:** [Assets/Scrips/SceneDesign/IslandInteraction.cs](Assets/Scrips/SceneDesign/IslandInteraction.cs#L42-L46)

```csharp
        if (Physics.Raycast(ray, out hit))
        {
            if (hit.transform == transform || hit.transform.IsChildOf(transform))
{            // ← la llave de apertura está en columna 0 (sin indentación)
    OpenBook();
}
```

**Problema:** La indentación incorrecta no causa un error de compilación, pero complica la lectura y mantenimiento del código.

---

### BUG-32 · `GameActivityService.cs` — Constructor vacío crea dependencia oculta

**Archivo:** [Assets/Scrips/Core/Service/GameActivityService.cs](Assets/Scrips/Core/Service/GameActivityService.cs#L21-L23)

```csharp
public GameActivityService() { } // el repository es null aquí
```

**Problema:** El constructor sin parámetros deja `repository` en null. Aunque `EnsureRepository()` lo inicializa lazy, si se llama `GetGameActivity` antes de que `DatabaseManager` esté listo, `EnsureRepository` fallará internamente en `GameActivityRepository()` que también puede lanzar. Es una cadena de dependencias ocultas.

---

## Tabla de Archivos por Severidad

| Archivo | Bugs Críticos | Bugs Altos | Bugs Medios | Bugs Bajos |
|---------|:---:|:---:|:---:|:---:|
| `GameInfoUI.cs` | BUG-01 | — | BUG-17 | — |
| `DragHandler.cs` | BUG-02 | BUG-11 | — | — |
| `IslandInteraction.cs` | BUG-03 | BUG-12, BUG-13 | BUG-22 | BUG-31 |
| `Mouth.cs` | BUG-04 | — | — | — |
| `AuthService.cs` | BUG-05 | BUG-10 | — | — |
| `SoundManager.cs` | — | BUG-06 | — | — |
| `ResultActivityRepository.cs` | — | BUG-07 | — | — |
| `ActivityRepository.cs` | — | BUG-08 | — | — |
| `LoginPresenter.cs` / `LoginView.cs` | — | BUG-09 | — | — |
| `RegisterStudentView.cs` | — | BUG-14 | BUG-23 | — |
| `AutoLoginService.cs` | — | — | BUG-15 | — |
| `RestartLevel.cs` | — | — | BUG-16 | — |
| `BackgroundLoader.cs` | — | — | BUG-19 | — |
| `PreviewImageLoader.cs` | — | — | BUG-19 | — |
| `UserSessionManager.cs` | — | — | BUG-20 | — |
| `TestInitialUserFlowPresenter.cs` | — | — | BUG-21 | — |
| `LoginStudentView.cs` | — | — | BUG-24 | — |
| `GameManager.cs` | — | — | BUG-25 | BUG-26, BUG-30 |
| `GameManagerFood.cs` | — | — | — | BUG-26 |
| `GameSelector.cs` | — | — | — | BUG-27 |
| `DatabaseManager.cs` | — | — | — | BUG-28, BUG-29 |
| `BoxGameSelector.cs` | — | — | — | BUG-30 |
| `ItemPool.cs` | — | — | BUG-18 | — |
| `GameActivityService.cs` | — | — | — | BUG-32 |

---

## Prioridades de Corrección Recomendadas

1. **Inmediata (antes del próximo build):** BUG-01 (`using UnityEditor`)
2. **Esta semana:** BUG-03 (PlayerPrefs con moduleId), BUG-02 (DragHandler null), BUG-04 (Mouth null), BUG-09 (doble navegación login)
3. **Próximo sprint:** BUG-06 (SoundManager singleton), BUG-07/08 (repositorios sin null-check), BUG-11 (Animator null), BUG-12/13 (IslandInteraction nulls), BUG-14 (isRegistering)
4. **Backlog:** Resto de bugs medios y bajos
