using System.IO;
using System.Xml;
using UnityEditor.Android;

/// <summary>
/// Desactiva el Auto Backup de Android (android:allowBackup="false").
/// Sin esto, al desinstalar y reinstalar la app, Android puede restaurar desde la nube
/// una copia vieja de ciencia_viva.db, y eso pasa solo algunas veces.
/// </summary>
public class DisableAndroidBackup : IPostGenerateGradleAndroidProject
{
    private const string AndroidNs = "http://schemas.android.com/apk/res/android";
    private const string ToolsNs = "http://schemas.android.com/tools";

    public int callbackOrder => 0;

    public void OnPostGenerateGradleAndroidProject(string unityLibraryPath)
    {
        string manifestPath = Path.Combine(unityLibraryPath, "src", "main", "AndroidManifest.xml");
        if (!File.Exists(manifestPath)) return;

        var doc = new XmlDocument();
        doc.Load(manifestPath);

        XmlElement manifest = doc.DocumentElement;
        if (!manifest.HasAttribute("xmlns:tools"))
            manifest.SetAttribute("xmlns:tools", ToolsNs);

        var application = (XmlElement)manifest.SelectSingleNode("application");
        if (application == null) return;

        application.SetAttribute("allowBackup", AndroidNs, "false");
        application.SetAttribute("fullBackupContent", AndroidNs, "false");
        application.SetAttribute("replace", ToolsNs, "android:allowBackup,android:fullBackupContent");

        doc.Save(manifestPath);
    }
}
