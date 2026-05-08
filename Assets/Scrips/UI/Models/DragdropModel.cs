using System;
using System.Collections.Generic;
using SQLite4Unity3d;

// ─────────────────────────────────────────────
//  DragDropModel.cs
//  Clases de datos. No se adjunta a ningún GameObject.
//  Colócalo en la misma carpeta que DragHandler y DropSlot.
// ─────────────────────────────────────────────
[Table ("game_activity")]
[Serializable]
public class GameActivityData
{
    [PrimaryKey]
    public int    id_game_activity { get; set; }
    public int    id_activity { get; set; }
    public string game_type { get; set; }
    public int    max_lives { get; set; }
    public string config_json { get; set; }
}

[Serializable]
public class DragDropConfig
{
    public string         instruction;
    public List<ItemData> items;
    public List<ZoneData> zones;
}

[Serializable]
public class ItemData
{
    public string id;
    public string image_key;
    public string correct_zone;
}

[Serializable]
public class ZoneData
{
    public string id;
    public string label;
}