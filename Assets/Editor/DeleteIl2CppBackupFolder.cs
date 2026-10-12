using System.IO;
using UnityEditor;
using UnityEditor.Build;
using UnityEditor.Build.Reporting;
using UnityEngine;

/// <summary>
/// Borra la carpeta "&lt;build&gt;_BackUpThisFolder_ButDontShipItWithYourGame" que IL2CPP deja
/// junto al APK en cada build. Solo sirve para simbolizar crashes y pesa ~800 MB.
/// No toca el APK ni nada que vaya dentro de él; es un script solo de editor.
/// </summary>
public class DeleteIl2CppBackupFolder : IPostprocessBuildWithReport
{
    private const string BackupSuffix = "_BackUpThisFolder_ButDontShipItWithYourGame";

    public int callbackOrder => int.MaxValue;

    public void OnPostprocessBuild(BuildReport report)
    {
        string outputPath = report.summary.outputPath;
        if (string.IsNullOrEmpty(outputPath)) return;

        string parentDir = Path.GetDirectoryName(Path.GetFullPath(outputPath));
        string buildName = Path.GetFileNameWithoutExtension(outputPath.TrimEnd('/', '\\'));
        string backupPath = Path.Combine(parentDir, buildName + BackupSuffix);

        TryDelete(backupPath);
        // Unity puede mover la carpeta al final del build, después de este callback.
        EditorApplication.delayCall += () => TryDelete(backupPath);
    }

    private static void TryDelete(string path)
    {
        if (!Directory.Exists(path)) return;
        try
        {
            Directory.Delete(path, true);
            Debug.Log($"[Build] Carpeta de backup IL2CPP eliminada: {path}");
        }
        catch (IOException e)
        {
            Debug.LogWarning($"[Build] No se pudo eliminar {path}: {e.Message}");
        }
        catch (System.UnauthorizedAccessException e)
        {
            Debug.LogWarning($"[Build] No se pudo eliminar {path}: {e.Message}");
        }
    }
}
