using System.Net;
using System.Net.Sockets;

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
}