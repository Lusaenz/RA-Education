# Diagnóstico: Error "SQLiteException: Constraint" en Registro

## Problema
El registro falla con error "SQLiteException: Constraint" cuando se intenta insertar un nuevo usuario.

## Posibles Causas

### 1. **ID de Grado NO EXISTE en la tabla `degrees` (CAUSA MÁS PROBABLE)**
```
Error: FOREIGN KEY constraint violado
```
**Verificar:**
- ¿Tiene tu BD datos en la tabla `degrees`?
- ¿El grado que selecciona el usuario existe realmente?
- ¿El `id_degree` que se envía es válido?

**Solución:**
```sql
-- Verificar si hay grados en la BD
SELECT * FROM degrees;

-- Debería retornar al menos un registro como:
-- id_degree=1, name="Primero"
-- id_degree=2, name="Segundo"
-- etc.
```

### 2. **Campo NOT NULL sin valor**
Si la tabla `users` en la BD tiene más campos que en el modelo C#.

**Solución:**
Verificar la definición de la tabla:
```sql
PRAGMA table_info(users);
```

### 3. **Restricción UNIQUE en campo `name`**
Si hay UNIQUE constraint en el campo `name` y se intenta registrar un nombre duplicado.

**Solución:**
Usar nombres únicos o remover la restricción UNIQUE.

---

## Cómo Debuggear

### Paso 1: Ver los logs en Unity Console
La aplicación ahora muestra:
- `[RegisterStudent] Intentando registrar - Name: ..., DegreeId: ...`
- `SQLite Constraint Error: ...`
- `Esto puede indicar: 1) El grado (ID: ...) no existe...`

**Busca en los logs exactamente qué `DegreeId` está siendo enviado.**

### Paso 2: Verificar la BD
```sql
-- Ver si existen grados
SELECT id_degree, name FROM degrees;

-- Si el query anterior está vacío, inserta datos:
INSERT INTO degrees (name) VALUES ('1º Primaria');
INSERT INTO degrees (name) VALUES ('2º Primaria');
INSERT INTO degrees (name) VALUES ('3º Primaria');
```

### Paso 3: Verificar la estructura de users
```sql
-- Ver la definición de la tabla
PRAGMA table_info(users);

-- Debería retornar algo como:
-- id_user | INTEGER | NOT NULL | PRIMARY KEY
-- name | TEXT | NOT NULL
-- id_degree | INTEGER | NOT NULL | FOREIGN KEY
-- password | TEXT | NOT NULL
-- id_role | INTEGER | NOT NULL
-- id_security_question | INTEGER
-- security_answer_hash | TEXT
-- last_login | TEXT
```

---

## Solución Definitiva

Si el problema es que no hay datos en la tabla `degrees`:

1. **En la BD, ejecuta:**
```sql
-- Verificar si hay grados
SELECT COUNT(*) as count FROM degrees;

-- Si el resultado es 0, inserta:
INSERT INTO degrees (id_degree, name) VALUES (1, '1º Primaria');
INSERT INTO degrees (id_degree, name) VALUES (2, '2º Primaria');
INSERT INTO degrees (id_degree, name) VALUES (3, '3º Primaria');
INSERT INTO degrees (id_degree, name) VALUES (4, '4º Primaria');
INSERT INTO degrees (id_degree, name) VALUES (5, '5º Primaria');
INSERT INTO degrees (id_degree, name) VALUES (6, '6º Primaria');
```

2. **Intenta registrar nuevamente**

---

## Si aún falla

1. **Verifica en los logs exactamente qué valor de `DegreeId` se envía**
2. **Ejecuta en la BD:** `SELECT * FROM degrees WHERE id_degree = <el_id_que_envias>;`
3. **Si el resultado está vacío, ESE es tu problema**: El grado no existe
4. **Si existe, sube el mensaje exacto del error a los logs**

---

## Campos del UserModel en C#

Asegúrate de que todos estos campos coincidan con la BD:

```csharp
public class UserModel
{
    [PrimaryKey, AutoIncrement]
    public int id_user { get; set; }           // INTEGER PRIMARY KEY AUTOINCREMENT
    public string name { get; set; }            // TEXT (debe existir)
    public int id_degree { get; set; }          // INTEGER (debe ser FOREIGN KEY a degrees.id_degree)
    public string password { get; set; }        // TEXT
    public int id_role { get; set; }            // INTEGER
    public int id_security_question { get; set; }    // INTEGER (OK si NULL por ahora)
    public string security_answer_hash { get; set; } // TEXT (OK si vacía por ahora)
    public string last_login { get; set; }     // TEXT (OK si vacía por ahora)
}
```

---

## Próximos Pasos si esto no resuelve

1. Comparte el mensaje exacto del error de los logs
2. Ejecuta `PRAGMA foreign_keys;` en la BD y comparte el resultado
3. Ejecuta `SELECT sql FROM sqlite_master WHERE type='table' AND name='users';` y comparte la definición exacta de la tabla
