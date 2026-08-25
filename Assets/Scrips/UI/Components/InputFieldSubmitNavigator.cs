using TMPro;
using UnityEngine;
using UnityEngine.EventSystems;

/// <summary>
/// Encadena el envio (Enter/Done del teclado movil) entre TMP_InputField:
/// evita que se inserte un salto de linea, avanza el foco al siguiente
/// campo de la cadena y cierra el teclado al enviar el ultimo campo.
/// </summary>
public static class InputFieldSubmitNavigator
{
    /// <summary>
    /// Devuelve el texto realmente confirmado por el usuario en un TMP_InputField.
    /// TMP_InputField solo copia el texto del teclado nativo (TouchScreenKeyboard) hacia
    /// su propiedad .text dentro de su propio LateUpdate(). Cuando el usuario toca una
    /// sugerencia de autocompletado del teclado y de inmediato pulsa un botón (p. ej. Login),
    /// el click se procesa en Update()/EventSystem, que corre ANTES de ese LateUpdate: .text
    /// queda con el valor previo a la sincronización, aunque en pantalla ya se vea el texto
    /// autocompletado. Por eso hay que leer el teclado nativo directamente cuando está activo.
    /// </summary>
    public static string GetCommittedText(TMP_InputField field)
    {
        if (field == null)
            return string.Empty;

        TouchScreenKeyboard keyboard = field.touchScreenKeyboard;
        if (keyboard != null &&
            (keyboard.status == TouchScreenKeyboard.Status.Visible ||
             keyboard.status == TouchScreenKeyboard.Status.Done))
        {
            return keyboard.text;
        }

        return field.text;
    }

    public static void Chain(params TMP_InputField[] fields)
    {
        for (int i = 0; i < fields.Length; i++)
        {
            TMP_InputField current = fields[i];
            if (current == null)
                continue;

            ForceSingleLine(current);

            TMP_InputField next = null;
            for (int j = i + 1; j < fields.Length; j++)
            {
                if (fields[j] != null)
                {
                    next = fields[j];
                    break;
                }
            }

            TMP_InputField capturedCurrent = current;
            TMP_InputField capturedNext = next;
            current.onSubmit.AddListener((_) => AdvanceOrCloseKeyboard(capturedCurrent, capturedNext));
        }
    }

    public static void ForceSingleLine(TMP_InputField field)
    {
        if (field != null && field.lineType == TMP_InputField.LineType.MultiLineNewline)
            field.lineType = TMP_InputField.LineType.SingleLine;
    }

    public static void AdvanceOrCloseKeyboard(TMP_InputField current, TMP_InputField next)
    {
        if (next != null && next.gameObject.activeInHierarchy && next.interactable)
        {
            next.Select();
            next.ActivateInputField();
        }
        else
        {
            current.DeactivateInputField();
            if (EventSystem.current != null)
                EventSystem.current.SetSelectedGameObject(null);
        }
    }
}
