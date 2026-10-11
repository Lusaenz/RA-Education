using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;

public static class SimpleNetwork
{
    public const int PORT = 7777;

    // Puerto utilizado únicamente para descubrir el servidor.
    public const int DISCOVERY_PORT = 7778;

    // Mensajes utilizados para el descubrimiento.
    public const string DISCOVERY_REQUEST = "CIENCIA_VIVA_DISCOVER";
    public const string DISCOVERY_RESPONSE = "CIENCIA_VIVA_SERVER";

    public static string GetLocalIPAddress()
    {
        var host = Dns.GetHostEntry(Dns.GetHostName());

        foreach (var ip in host.AddressList)
        {
            if (ip.AddressFamily == AddressFamily.InterNetwork)
                return ip.ToString();
        }

        return "No disponible";
    }

    /// <summary>
    /// Separa los mensajes completos (terminados en '\n') acumulados en el buffer.
    /// Lo que quede sin '\n' se conserva para la siguiente lectura.
    /// </summary>
    public static List<string> ExtractMessages(StringBuilder pending)
    {
        List<string> messages = new List<string>();

        string text = pending.ToString();
        int start = 0;
        int newline;

        while ((newline = text.IndexOf('\n', start)) >= 0)
        {
            string msg = text.Substring(start, newline - start).Trim();

            if (msg.Length > 0)
                messages.Add(msg);

            start = newline + 1;
        }

        pending.Remove(0, start);

        return messages;
    }
}
