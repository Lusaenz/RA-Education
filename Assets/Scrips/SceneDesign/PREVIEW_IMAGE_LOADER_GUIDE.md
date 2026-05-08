# 🖼️ Guía: Cargar Imágenes de Preview Dinámicamente

## 📋 Resumen

Sistema que carga automáticamente la imagen de preview en **GameInfoUI** según el juego seleccionado en **GameSelector**:
- **Juego ID 1** (Digestivo): `images/digestive`
- **Juego ID 2** (Célula): `images/cell`

---

## 🏗️ Arquitectura

```
GameSelector
    ↓
    (guarda selected_activity_id en PlayerPrefs)
    ↓
GameInfoUI.LoadSelectedActivityInfo()
    ↓
    PreviewImageLoader.LoadPreviewForSelectedGame()
    ↓
    (Lee PlayerPrefs)
    ↓
    Addressables.LoadAssetAsync<Sprite>(key)
    ↓
previewImage (UI Image)
    ↓
✅ Preview mostrada
```

---

## 📝 Scripts Creados/Modificados

### ✨ NUEVO: PreviewImageLoader.cs
```
Assets/Scrips/SceneDesign/PreviewImageLoader.cs
```
- Carga imágenes addressables dinámicamente
- Mapea IDs de juego a rutas addressable
- Gestiona release de assets

### ✏️ MODIFICADO: GameInfoUI.cs
```
Assets/Scrips/SceneDesign/GameInfoUI.cs
```
- Agregado campo `PreviewImageLoader`
- Llamada en `LoadSelectedActivityInfo()` a `LoadPreviewForSelectedGame()`

---

## 🔧 Configuración en Unity

### PASO 1: Crear GameObject PreviewImageLoader

1. **En Hierarchy**, busca o crea un GameObject para PreviewImageLoader:
   ```
   Hierarchy
   └─ PreviewImageLoader (GameObject)
   ```

2. **Agregar componente:**
   - Click derecho → Inspector
   - Add Component → Script → PreviewImageLoader

3. **En Inspector, asignar:**
   ```
   PreviewImageLoader (Script)
   ├─ Preview Image: [Drag el Image del previewImage aquí] ← CRÍTICO
   ├─ Digestive Image Key: "images/digestive"
   └─ Cell Image Key: "images/cell"
   ```

   ✅ **Importante:** El Image debe ser el mismo que tiene GameInfoUI

---

### PASO 2: Asignar PreviewImageLoader a GameInfoUI

1. **Busca GameInfoUI** en Hierarchy
2. **En Inspector**, componente `GameInfoUI (Script)`
3. **Scroll hasta la sección "Preview Image Loader":**
   ```
   [Inspector - GameInfoUI]
   └─ Preview Image Loader: [Drag PreviewImageLoader aquí] ← CRÍTICO
   ```

4. **Verifica todos los campos:**
   ```
   GameInfoUI (Script)
   ├─ Title Text: ✅ (ya estaba)
   ├─ Description Text: ✅ (ya estaba)
   ├─ Preview Image: ✅ (ya estaba)
   ├─ Panel: ✅ (ya estaba)
   ├─ Games: ✅ (ya estaba)
   ├─ Preview Image Loader: ✅ AssignedPreviewImageLoader ← NUEVO
   └─ ...
   ```

---

## ✅ Verificación de Addressables

**Asegúrate de que estas rutas están como Addressable:**

```
Assets/
└─ Resources/ (o donde estén tus imágenes)
   ├─ images/
   │  ├─ digestive        ✅ Addressable (clave: images/digestive)
   │  └─ cell             ✅ Addressable (clave: images/cell)
```

Para marcar como Addressable:
1. Selecciona la imagen en **Project**
2. **Inspector** → busca "Addressables"
3. ✓ Marca el checkbox
4. Verifica que la **Address** es exacta:
   - Digestivo: `images/digestive`
   - Célula: `images/cell`

---

## 🎮 Diagrama de Flujo

```
┌──────────────────┐
│  GameSelector    │
│  LoadDigestive() │
└────────┬─────────┘
         │
         └─→ PlayerPrefs.SetInt("selected_activity_id", 1)
             id = 1 (Digestivo) o 2 (Célula)
         
         ↓
         
┌──────────────────────────────┐
│  GameInfoUI                  │
│  LoadSelectedActivityInfo()  │
└────────┬─────────────────────┘
         │
         └─→ previewImageLoader.LoadPreviewForSelectedGame()
         
         ↓
         
┌─────────────────────────────────────┐
│  PreviewImageLoader                 │
│  LoadPreviewForSelectedGame()        │
└────────┬────────────────────────────┘
         │
         ├─→ int id = PlayerPrefs.GetInt("selected_activity_id")
         │
         ├─→ string key = (id == 1) ? "images/digestive" 
         │                         : "images/cell"
         │
         ├─→ Addressables.LoadAssetAsync<Sprite>(key)
         │
         ├─→ previewImage.sprite = loadedSprite
         │
         └─→ ✅ PREVIEW MOSTRADA
```

---

## 📊 Ejemplo de Uso Completo

### Flujo: Usuario selecciona "Digestivo"

**1. En GameSelector:**
```csharp
// GameSelector.LoadDigestive()
PlayerPrefs.SetInt("selected_activity_id", 1);  // ← ID 1 = Digestivo
SceneManager.LoadScene("GameSelection");  // ← Escena que tiene GameInfoUI
```

**2. Se carga escena con GameInfoUI:**
```csharp
// GameInfoUI.Start()
StartCoroutine(LoadSelectedActivityInfo());
```

**3. Se obtiene info de BD:**
```csharp
// Dentro de LoadSelectedActivityInfo()
ActivityData activity = resultado de BD
SetTexts(activity.type, activity.description);  // Muestra textos
```

**4. Se carga imagen de preview:**
```csharp
// Al final de LoadSelectedActivityInfo()
previewImageLoader.LoadPreviewForSelectedGame();
// → Lee ID 1 desde PlayerPrefs
// → Mapea ID 1 → "images/digestive"
// → Carga sprite con Addressables
// → Asigna a previewImage
```

**5. Resultado:**
```
GameInfoUI Panel
├─ Título: (tipo de actividad)
├─ Descripción: (descripción de actividad)
└─ Preview Image: 🥦 (digestive_image) ✅
```

---

## 🔍 Verificación

### Checklist:

- [ ] PreviewImageLoader.cs existe en `Assets/Scrips/SceneDesign/`
- [ ] GameInfoUI.cs actualizado con PreviewImageLoader
- [ ] PreviewImageLoader GameObject creado
- [ ] Preview Image asignado en PreviewImageLoader Inspector
- [ ] PreviewImageLoader asignado en GameInfoUI Inspector
- [ ] `images/digestive` marcado como Addressable
- [ ] `images/cell` marcado como Addressable
- [ ] Las direcciones son exactas (sin espacios)
- [ ] Puedes hacer clic en Preview Image desde el Inspector

---

## 🚀 Testing

### Test 1: Digestivo

```
1. Juego → GameSelector → LoadDigestive()
2. App carga pantalla GameSelection (con GameInfoUI)
3. Verifica Console:
   ℹ️  "PreviewImageLoader: Cargando preview de imagen (ID 1)
        desde addressable: images/digestive"
   ✓ "PreviewImageLoader: Imagen de preview cargada exitosamente"
4. UI debe mostrar imagen digestivo en previewImage
```

### Test 2: Célula

```
1. Juego → GameSelector → LoadCellGame()
2. App carga pantalla GameSelection (con GameInfoUI)
3. Verifica Console:
   ℹ️  "PreviewImageLoader: Cargando preview de imagen (ID 2)
        desde addressable: images/cell"
   ✓ "PreviewImageLoader: Imagen de preview cargada exitosamente"
4. UI debe mostrar imagen cell en previewImage
```

---

## ❌ Troubleshooting

### Problema: Imagen no aparece en previewImage

**Checklist:**
```
☐ PreviewImageLoader está asignado en GameInfoUI?
☐ previewImage está asignado en PreviewImageLoader?
☐ Las rutas addressable existen?
  - Project → busca "digestive"
  - Project → busca "cell"
☐ Imágenes están marcadas como Addressable? ✓
☐ Las direcciones son exactas?
  - "images/digestive" (NO "images/Digestive")
  - "images/cell" (NO "images/Cell")
```

### Problema: "Addressable asset not found"

```
Solución:
1. Selecciona la imagen "digestive" en Project
2. Inspector → busca "Addressable" checkbox
3. ¿Está marcado? ✓
4. En "Address" debe decir exactamente: "images/digestive"
5. Repite para "cell"
```

### Problema: "PreviewImageLoader no está asignado"

```
Solución:
1. En Hierarchy, crea nuevo GameObject: PreviewImageLoader
2. Add Component → PreviewImageLoader.cs
3. Arrastra a la propiedad en GameInfoUI
4. En PreviewImageLoader, asigna el Image (previewImage)
```

### Problema: Mensaje "Usando sprite estático del array GameData"

```
Significado: PreviewImageLoader no está asignado
Solución: Asigna PreviewImageLoader en el Inspector de GameInfoUI
```

---

## 🎨 Personalización

### Agregar Más Juegos

Si agregas más juegos:

**1. En GameSelector.cs:**
```csharp
public void LoadNewGame()
{
    PlayerPrefs.SetInt("selected_activity_id", 3);  // ID 3
    SceneManager.LoadScene("GameSelection");
}
```

**2. En PreviewImageLoader.cs:**
```csharp
private string GetPreviewKeyForGame(int gameId)
{
    return gameId switch
    {
        1 => digestiveImageKey,
        2 => cellImageKey,
        3 => "images/newgame",  // ← NUEVO
        _ => null
    };
}

[SerializeField] private string newGameImageKey = "images/newgame";
```

**3. Marcar imagen como Addressable:**
- En Project → selecciona imagen para "newgame"
- Inspector → Addressable ✓
- Address: `images/newgame`

---

## 📚 API de PreviewImageLoader

```csharp
// Cargar automáticamente desde PlayerPrefs (RECOMENDADO)
previewImageLoader.LoadPreviewForSelectedGame();

// Cargar por ID
previewImageLoader.LoadPreviewByGameId(1);  // 1 = Digestivo

// Cargar por ID (para testing)
previewImageLoader.LoadPreviewByGameId(2);  // 2 = Célula
```

---

## ✨ Diferencias con BackgroundLoader

| Aspecto | BackgroundLoader | PreviewImageLoader |
|---------|-----------------|-------------------|
| **Propósito** | Fondo escena | Preview en UI |
| **Canvas** | Fondo de juego | Panel de selección |
| **Rutas** | `background/*` | `images/*` |
| **Integración** | GameManager | GameInfoUI |
| **Timing** | Al iniciar juego | Al mostrar panel |

---

## 🎯 Resumen

**Sistema creado:**
- ✅ PreviewImageLoader.cs para cargar imágenes dinámicamente
- ✅ Integración en GameInfoUI
- ✅ Mapeo automático ID juego → imagen addressable
- ✅ Gestión automática de assets

**Ventajas:**
- 🎯 Preview automática según juego
- 🔄 Fácil agregar más juegos
- 📦 Usa Addressables (eficiente)
- 🧹 Limpieza automática de memoria

**Tiempo de setup:** ~5 minutos

---

## ✅ Checklist de Setup

```
- [ ] PreviewImageLoader.cs existe
- [ ] GameInfoUI.cs actualizado
- [ ] PreviewImageLoader GameObject creado
- [ ] previewImage asignado en PreviewImageLoader
- [ ] PreviewImageLoader asignado en GameInfoUI  
- [ ] images/digestive es Addressable
- [ ] images/cell es Addressable
- [ ] Rutas coinciden exactamente
- [ ] Console sin errores
```

🚀 **¡Listo para usar!**
