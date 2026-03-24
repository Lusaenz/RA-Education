# Documentacion Tecnica de `Core` y `UI`

## Objetivo

Este documento resume la responsabilidad de los scripts ubicados en `Assets/Scrips/Core` y `Assets/Scrips/UI`, explica como colaboran entre si y propone mejoras concretas alineadas con principios SOLID y buenas practicas.

## Vista general de la arquitectura actual

La solucion sigue una estructura cercana a MVP, pero con una implementacion hibrida:

- `Core` contiene acceso a datos, sesion, seguridad y servicios de aplicacion.
- `UI/Views` contiene `MonoBehaviour` acoplados a escenas, botones e inputs.
- `UI/Presenters` encapsula parte de la logica de validacion y navegacion.
- `UI/Models` representa entidades persistidas en SQLite.
- `UI/Components` contiene componentes reutilizables para interacciones visuales.

En la practica, la arquitectura todavia mezcla responsabilidades:

- Algunas vistas construyen dependencias por su cuenta.
- Algunos presenters navegan escenas o acceden a servicios concretos.
- Hay acceso directo a SQLite desde componentes de UI.
- Existen dependencias globales via `DatabaseManager.Instance` y `UserSessionManager.Instance`.

## Estructura por carpetas

### `Assets/Scrips/Core`

#### `DegreeService.cs`
- Expone operaciones de consulta de grados.
- Funciona como capa intermedia entre UI y `DegreeRepository`.
- Reduce el acceso directo desde presentacion hacia SQLite.

#### `UserSessionManager.cs`
- Singleton persistente entre escenas.
- Conserva el `CurrentUser` autenticado.
- Es la fuente de verdad temporal para la sesion activa.

### `Assets/Scrips/Core/Data`

#### `DatabaseLoader.cs`
- Componente de compatibilidad para copiar la base SQLite desde `StreamingAssets`.
- Hoy su responsabilidad se solapa parcialmente con `DatabaseManager`.

#### `DatabaseManager.cs`
- Inicializa la base de datos.
- Copia el archivo SQLite a `persistentDataPath` si hace falta.
- Abre la conexion compartida.
- Reintenta cuando SQLite responde con estado `Busy`.
- Publica `IsReady` y `OnReady` para coordinar inicializacion.

### `Assets/Scrips/Core/Data/Repository`

#### `DegreeRepository.cs`
- Repositorio de lectura para la tabla `degrees`.
- Obtiene un grado por id o lista todos los grados.

#### `UserRepository.cs`
- Inserta registros en `users`, `students` y `teachers`.
- Consulta estudiantes por nombre y profesores por correo.
- Actualiza contrasenas ya migradas a hash.
- Protege escrituras con `lock` y reintentos basicos.

### `Assets/Scrips/Core/Security`

#### `PasswordHasher.cs`
- Encapsula hash SHA-256 y verificacion de contrasenas.
- Mantiene compatibilidad temporal con passwords legacy en texto plano.

### `Assets/Scrips/Core/Service`

#### `AuthService.cs`
- Orquesta login y registro.
- Valida credenciales comparando password ingresada contra password persistida.
- Migra automaticamente a hash si detecta un password legacy.
- Registra usuarios base y luego sus detalles por rol.

Importante:
- Este archivo contiene una implementacion interna de `PasswordHasher` duplicada.
- Ya existe otra clase con la misma responsabilidad en `Core/Security/PasswordHasher.cs`.
- Esta duplicacion incrementa riesgo de divergencia funcional.

## Estructura de `UI`

### `Assets/Scrips/UI/Components`

#### `DegreeSelector.cs`
- Carga grados desde SQLite cuando la base esta lista.
- Construye la experiencia visual de seleccion.
- Sincroniza el grado elegido con un `TMP_InputField`.

Observacion:
- Este componente consulta SQLite directamente.
- Esa responsabilidad deberia vivir en un servicio o presenter.

#### `InputFieldHandler.cs`
- Maneja la visibilidad del placeholder al hacer focus y blur.
- Es un componente visual simple y reutilizable.

### `Assets/Scrips/UI/Models`

#### `DegreeModel.cs`
- Entidad mapeada a la tabla `degrees`.

#### `UserModel.cs`
- Entidad base de usuarios.
- Contiene nombre, grado, password y rol.

#### `StudentModel.cs`
- Entidad con informacion adicional del estudiante.

#### `TeacherModel.cs`
- Entidad con informacion adicional del profesor.

Nota de arquitectura:
- Aunque hoy estan dentro de `UI/Models`, realmente son modelos de persistencia/dominio.
- Conceptualmente pertenecen mas a una capa de dominio o datos que a presentacion.

### `Assets/Scrips/UI/Presenters`

#### `LoginPresenter.cs`
- Valida entradas de login.
- Delega autenticacion a `AuthService`.
- Guarda el usuario en sesion.
- Navega a la escena `TestInitialuserFlow`.

Observacion:
- Mezcla logica de presentacion con navegacion y manejo de sesion.

#### `RegisterPresenter.cs`
- Espera disponibilidad de base de datos.
- Construye `AuthService`.
- Valida formularios de estudiante y profesor.
- Devuelve `RegisterResult` con errores por campo.

Observacion:
- Tiene buena intencion de separacion, pero sigue dependiendo de Unity (`MonoBehaviour`) y de infraestructura concreta.

#### `SelectRolePresenter.cs`
- Navega a login de estudiante o profesor.
- Es un presenter muy pequeño centrado solo en transicion de escenas.

#### `TestInitialUserFlowPresenter.cs`
- Lee el usuario actual desde `UserSessionManager`.
- Traduce id de rol a texto legible.
- Consulta el nombre del grado para mostrarlo en pantalla.

Observacion:
- Actualmente crea `DegreeService` dentro del presenter.
- Eso dificulta pruebas y rompe inversion de dependencias.

### `Assets/Scrips/UI/Views`

#### `LoginStudentView.cs`
- Recoge nombre y contrasena.
- Inicializa `LoginPresenter` cuando SQLite esta disponible.
- Muestra errores por campo y mensajes generales.
- Tambien vuelve a guardar la sesion y vuelve a cargar escena.

Observacion:
- Duplica responsabilidades que ya existen en `LoginPresenter`.

#### `LoginTeacherView.cs`
- Equivalente al login de estudiante pero para profesores.
- Comparte casi toda la misma estructura.

Observacion:
- Existe duplicacion importante entre ambas vistas.

#### `RegisterStudentView.cs`
- Busca `RegisterPresenter` y `DegreeSelector` en escena.
- Envía datos del formulario para validacion y registro.
- Muestra errores por campo.

#### `RegisterTeacherView.cs`
- Equivalente al registro de estudiante, adaptado a campos de profesor.

Observacion comun:
- Ambas vistas comparten gran parte de la logica de errores, listeners y navegacion.

#### `SelectRoleView.cs`
- Convierte clicks sobre tarjetas visuales en acciones del presenter.
- Registra `EventTrigger` en tiempo de ejecucion.

#### `ITestInitialUserFlowView.cs`
- Contrato entre presenter y vista del flujo inicial.
- Es el punto mas claramente alineado con MVP.

#### `TestInitialUserFlowView.cs`
- Implementa la interfaz de vista.
- Muestra nombre, rol y grado del usuario autenticado.

## Flujo funcional actual

### Login
1. La vista espera a que `DatabaseManager` este listo.
2. La vista crea `UserRepository` y `AuthService`.
3. La vista crea `LoginPresenter`.
4. El presenter valida campos y llama a `AuthService`.
5. `AuthService` consulta `UserRepository`.
6. Si la autenticacion es correcta, se actualiza la sesion y se navega a la siguiente escena.

### Registro
1. La vista toma referencias al `RegisterPresenter` y al `DegreeSelector`.
2. `RegisterPresenter` espera la base y crea `AuthService`.
3. La vista envia datos del formulario.
4. El presenter valida formato, obligatoriedad y reglas basicas.
5. `AuthService` crea `UserModel` y luego `StudentModel` o `TeacherModel`.
6. La vista redirige al login correspondiente.

### Flujo inicial tras autenticacion
1. `TestInitialUserFlowView` crea `TestInitialUserFlowPresenter`.
2. El presenter consulta `UserSessionManager`.
3. Si hay usuario, calcula rol y grado.
4. La vista renderiza la informacion.

## Hallazgos principales

### Fortalezas

- Existe una intencion clara de separar vistas, presenters y servicios.
- `DatabaseManager` centraliza la inicializacion de SQLite.
- `RegisterResult` y `LoginResult` facilitan mostrar errores de forma amigable.
- `UserSessionManager` resuelve bien la persistencia de sesion entre escenas.

### Debilidades tecnicas

- Hay duplicacion de responsabilidades entre vistas y presenters.
- La UI accede a infraestructura concreta demasiado pronto.
- Se usan singletons globales y construccion manual de dependencias.
- Algunas clases estan ubicadas en carpetas que no reflejan su responsabilidad real.
- `AuthService` duplica el hashing en una clase interna.
- `DatabaseLoader` y `DatabaseManager` comparten parcialmente la misma responsabilidad.
- La navegacion por nombre de escena esta hardcodeada en varias clases.
- Hay fuerte duplicacion entre `LoginStudentView` y `LoginTeacherView`, y entre los formularios de registro.

## Evaluacion segun SOLID

### S: Single Responsibility Principle

Se cumple parcialmente.

Problemas detectados:
- `LoginStudentView` y `LoginTeacherView` capturan inputs, crean dependencias, gestionan mensajes, actualizan sesion y navegan.
- `LoginPresenter` ademas de validar y coordinar login, tambien persiste sesion y cambia de escena.
- `DegreeSelector` mezcla comportamiento visual con acceso a datos.
- `DatabaseManager` inicializa, copia archivo, abre conexion y gestiona evento de disponibilidad.

Mejoras recomendadas:
- Separar navegacion en un `INavigationService`.
- Separar sesion en un `ISessionService`.
- Extraer carga de grados a un `IDegreeService`.
- Mantener vistas enfocadas solo en representar estado y disparar eventos.

### O: Open/Closed Principle

Se cumple poco.

Problemas detectados:
- Los roles estan codificados con enteros y condicionales (`1 = estudiante`, `2 = profesor`).
- Agregar un nuevo rol o nuevo flujo implicaria modificar varios archivos.
- Las escenas se referencian con strings repetidos.

Mejoras recomendadas:
- Introducir constantes o enums para roles y nombres de escena.
- Centralizar navegacion y configuracion de rutas.
- Encapsular estrategias de login por rol si el sistema crece.

### L: Liskov Substitution Principle

No hay una jerarquia compleja, asi que no aparece una violacion fuerte. Aun asi:
- `RegisterPresenter` hereda de `MonoBehaviour`, lo cual dificulta tratarlo como presenter puro.
- Conviene desacoplar la logica de presentacion de tipos Unity cuando no sea necesario.

### I: Interface Segregation Principle

Se cumple mejor en `ITestInitialUserFlowView`, pero falta consistencia.

Mejoras recomendadas:
- Crear interfaces pequenas para servicios: `IAuthService`, `IUserRepository`, `IDegreeRepository`, `INavigationService`, `ISessionService`.
- Evitar que vistas conozcan mas de lo necesario sobre infraestructura.

### D: Dependency Inversion Principle

Es el punto mas debil del estado actual.

Problemas detectados:
- Vistas y presenters crean concretamente `UserRepository`, `AuthService` y `DegreeService`.
- Muchas clases dependen directamente de `DatabaseManager.Instance`.
- `TestInitialUserFlowPresenter` y `DegreeService` no reciben dependencias por constructor en toda la cadena.

Mejoras recomendadas:
- Inyectar dependencias por constructor o mediante un composition root por escena.
- Evitar `new` dentro de presenters y views para servicios de infraestructura.
- Introducir adaptadores para Unity si se quiere mantener compatibilidad con `MonoBehaviour`.

## Buenas practicas a implementar

### Prioridad alta

- Unificar el hashing y dejar una sola implementacion de `PasswordHasher`.
- Eliminar duplicacion entre vistas de login y entre vistas de registro.
- Mover modelos persistentes fuera de `UI/Models` a una carpeta de dominio o datos.
- Extraer navegacion y sesion a servicios dedicados.
- Hacer que `DegreeSelector` dependa de un servicio, no de SQLite directo.
- Centralizar constantes de escenas y roles.

### Prioridad media

- Reemplazar constructores legacy que dependen de singletons por inyeccion explicita.
- Crear interfaces para repositorios y servicios.
- Unificar el patron de inicializacion asincronica de base de datos.
- Eliminar la duplicidad funcional entre `DatabaseLoader` y `DatabaseManager`.
- Registrar errores con contexto tecnico uniforme.

### Prioridad baja

- Renombrar `Assets/Scrips` a `Assets/Scripts` para consistencia.
- Homogeneizar nombres de metodos, propiedades y convenciones de estilo.
- Agregar pruebas unitarias a validaciones y autenticacion.
- Incorporar pruebas de integracion para repositorios SQLite.

## Propuesta de refactor incremental

### Fase 1: orden y seguridad
- Unificar `PasswordHasher`.
- Crear constantes para roles y escenas.
- Mover modelos a una carpeta mas coherente.
- Documentar y reducir duplicaciones evidentes.

### Fase 2: desacoplar UI de infraestructura
- Crear interfaces `IAuthService`, `ISessionService`, `INavigationService`, `IDegreeService`.
- Hacer que presenters dependan de interfaces.
- Dejar que las vistas solo pasen datos y rendericen resultados.

### Fase 3: composition root por escena
- Crear un bootstrapper por escena que construya repositorios, servicios y presenters.
- Evitar `FindFirstObjectByType`, `new` en vistas y dependencias globales innecesarias.

### Fase 4: consolidar formularios
- Crear una base comun para login.
- Crear una base comun para registro.
- Reutilizar validacion, manejo de errores y mensajes temporales.

## Conclusiones

La base actual ya tiene una direccion razonable: separar UI, presenters y servicios. El siguiente salto de calidad no pasa por reescribir todo, sino por consolidar esa separacion:

- menos logica de negocio dentro de vistas,
- menos dependencias globales,
- menos acceso directo a SQLite desde UI,
- mas interfaces y servicios pequenos con responsabilidades claras.

Con esos cambios, el codigo va a ser mas facil de mantener, testear, extender y explicar a nuevos integrantes del equipo.
