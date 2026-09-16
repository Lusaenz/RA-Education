using System;
using System.Collections.Generic;
using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;
using UnityEngine.SceneManagement;

/// <summary>
/// Escucha el botón/gesto "atrás" de Android (KeyCode.Escape) y navega a la
/// pantalla anterior de cada escena, igual que el botón "volver" que ya existe
/// en la UI. Se autoinstala una única vez al arrancar la app y persiste entre
/// escenas: no requiere colocarlo manualmente en ningún .unity.
/// </summary>
public class BackNavigationManager : MonoBehaviour
{
    private static readonly List<Func<bool>> overrides = new();

    [RuntimeInitializeOnLoadMethod(RuntimeInitializeLoadType.BeforeSceneLoad)]
    private static void Bootstrap()
    {
        GameObject go = new GameObject("~BackNavigationManager");
        go.AddComponent<BackNavigationManager>();
        DontDestroyOnLoad(go);
    }

    /// <summary>
    /// Registra un handler que intercepta el back mientras un panel modal esté
    /// abierto. El handler debe cerrar el panel y devolver true para consumir
    /// el evento (evita que además se navegue de escena).
    /// </summary>
    public static void PushOverride(Func<bool> handler) => overrides.Add(handler);

    public static void PopOverride(Func<bool> handler) => overrides.Remove(handler);

    private void Update()
    {
        if (!Input.GetKeyDown(KeyCode.Escape)) return;
        if (IsTextFieldFocused()) return;
        if (overrides.Count > 0 && overrides[^1].Invoke()) return;

        HandleSceneBack();
    }

    private static bool IsTextFieldFocused()
    {
        GameObject selected = EventSystem.current != null ? EventSystem.current.currentSelectedGameObject : null;
        return selected != null && selected.GetComponent<TMP_InputField>() != null;
    }

    private static void HandleSceneBack()
    {
        string sceneName = SceneManager.GetActiveScene().name;

        switch (sceneName)
        {
            case "SelectRole":
            case "HomeTeachers":
            case "TestInitialuserFlow":
                QuitApp();
                break;

            case "Login":
                SceneManager.LoadScene("SelectRole");
                break;

            case "Register":
            case "ForgotPassword":
                SceneManager.LoadScene("Login");
                break;

            case "UserScreen":
                SceneManager.LoadScene("HomeTeachers");
                break;

            case "GameSelection":
                GoToHomeByRole();
                break;

            case "RAScreen":
            case "DragAndDrop":
            case "PuzzleCells":
            case "PuzzleDigestive":
            case "FoodRiddles":
                SceneManager.LoadScene("GameSelection");
                break;

            case "SampleScene":
                break;

            default:
                Debug.LogWarning($"[BackNavigationManager] Sin acción de 'atrás' definida para la escena '{sceneName}'.");
                break;
        }
    }

    private static void GoToHomeByRole()
    {
        if (UserSessionManager.Instance != null && UserSessionManager.Instance.CurrentUser != null)
        {
            int roleId = UserSessionManager.Instance.CurrentUser.id_role;

            if (roleId == 1) // Estudiante
            {
                SceneManager.LoadScene("TestInitialuserFlow");
                return;
            }

            if (roleId == 2) // Profesor
            {
                SceneManager.LoadScene("HomeTeachers");
                return;
            }
        }

        SceneManager.LoadScene("SelectRole");
    }

    private static void QuitApp()
    {
#if UNITY_EDITOR
        UnityEditor.EditorApplication.isPlaying = false;
#else
        Application.Quit();
#endif
    }
}
