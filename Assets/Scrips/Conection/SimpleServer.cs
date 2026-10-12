using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;

/// <summary>
/// Servidor local (dispositivo del profesor).
///
/// La parte de red (listener, clientes, descubrimiento) es ESTÁTICA: se inicia una sola vez
/// y sigue funcionando aunque se cambie de escena. Cada vez que se carga una escena con un
/// SimpleServer, ese componente solo "toma" los textos de la UI para mostrar el estado.
///
/// La información viaja solo de cliente a servidor: el servidor no reenvía nada.
/// </summary>
public class SimpleServer : MonoBehaviour
{
    [Header("UI")]
    public TMP_Text statusText;
    public TMP_Text receivedText;
    public TMP_Text myIPText;
    public TMP_InputField messageInput;

    // Si un cliente no envía nada (ni datos ni PING) en este tiempo, se da por desconectado.
    private const float ClientTimeoutSeconds = 35f;

    // ---- Estado de red compartido entre escenas ----
    private static TcpListener listener;
    private static UdpClient discoveryServer;
    private static bool running;

    // Clientes conectados y la última vez que se recibió algo de cada uno.
    private static readonly Dictionary<TcpClient, float> clients = new Dictionary<TcpClient, float>();

    // Componente de la escena actual que muestra el estado (puede ser null).
    private static SimpleServer activeView;

    public static int ConnectedCount
    {
        get { lock (clients) { return clients.Count; } }
    }

    // =====================================================================
    // Ciclo de vida del componente (solo UI)
    // =====================================================================

    private void Start()
    {
        activeView = this;

        if (myIPText != null)
            myIPText.text = "IP: " + SimpleNetwork.GetLocalIPAddress();

        StartServer();
        RefreshStatus();
    }

    private void OnDestroy()
    {
        if (activeView == this)
            activeView = null;
    }

    private static void SetStatus(string text)
    {
        if (activeView != null && activeView.statusText != null)
            activeView.statusText.text = text;
    }

    private static void RefreshStatus()
    {
        if (!running)
            SetStatus("Servidor detenido");
        else
            SetStatus("Dispositivos conectados: " + ConnectedCount);
    }

    // =====================================================================
    // Servidor TCP
    // =====================================================================

    public async void StartServer()
    {
        if (running)
        {
            Debug.Log("SimpleServer: el servidor ya está iniciado.");
            RefreshStatus();
            return;
        }

        try
        {
            StartDiscoveryServer();

            listener = new TcpListener(IPAddress.Any, SimpleNetwork.PORT);
            listener.Start();
            running = true;

            RefreshStatus();
            Debug.Log("SimpleServer: servidor TCP iniciado. Esperando clientes...");

            _ = TimeoutLoop();

            while (running && listener != null)
            {
                TcpClient newClient = await listener.AcceptTcpClientAsync();

                if (newClient == null)
                    continue;

                newClient.NoDelay = true;

                lock (clients)
                {
                    clients[newClient] = Time.realtimeSinceStartup;
                }

                string clientIP = ((IPEndPoint)newClient.Client.RemoteEndPoint).Address.ToString();
                Debug.Log("SimpleServer: nuevo cliente conectado desde " + clientIP);

                RefreshStatus();

                // Cada cliente tiene su propio proceso de recepción.
                _ = ReceiveMessages(newClient);
            }
        }
        catch (ObjectDisposedException)
        {
            Debug.Log("SimpleServer: listener detenido.");
        }
        catch (Exception e)
        {
            running = false;
            listener = null;
            SetStatus("Error");
            Debug.LogError("SimpleServer: error en servidor: " + e.Message);
        }
    }

    private static void StartDiscoveryServer()
    {
        if (discoveryServer != null)
            return;

        try
        {
            discoveryServer = new UdpClient(SimpleNetwork.DISCOVERY_PORT);

            Debug.Log("Servidor de descubrimiento iniciado en puerto " + SimpleNetwork.DISCOVERY_PORT);

            _ = ListenForDiscovery();
        }
        catch (Exception e)
        {
            Debug.LogError("Error iniciando servidor de descubrimiento: " + e.Message);
        }
    }

    private static async Task ListenForDiscovery()
    {
        while (discoveryServer != null)
        {
            try
            {
                UdpReceiveResult result = await discoveryServer.ReceiveAsync();

                string message = Encoding.UTF8.GetString(result.Buffer);

                if (message == SimpleNetwork.DISCOVERY_REQUEST)
                {
                    byte[] response = Encoding.UTF8.GetBytes(SimpleNetwork.DISCOVERY_RESPONSE);

                    await discoveryServer.SendAsync(response, response.Length, result.RemoteEndPoint);

                    Debug.Log("Solicitud de descubrimiento recibida de: " + result.RemoteEndPoint.Address);
                }
            }
            catch (ObjectDisposedException)
            {
                break;
            }
            catch (Exception e)
            {
                if (discoveryServer != null)
                    Debug.LogError("Error en descubrimiento: " + e.Message);
            }
        }
    }

    /// <summary>
    /// Recibe los mensajes de un cliente. Todo corre en el hilo principal de Unity,
    /// así que los mensajes de todos los clientes se procesan y guardan uno por uno.
    /// </summary>
    private static async Task ReceiveMessages(TcpClient currentClient)
    {
        NetworkStream currentStream = currentClient.GetStream();

        byte[] buffer = new byte[4096];
        char[] chars = new char[Encoding.UTF8.GetMaxCharCount(buffer.Length)];
        Decoder decoder = Encoding.UTF8.GetDecoder();
        StringBuilder pending = new StringBuilder();

        string clientIP = ((IPEndPoint)currentClient.Client.RemoteEndPoint).Address.ToString();

        try
        {
            while (currentClient.Connected)
            {
                int bytes = await currentStream.ReadAsync(buffer, 0, buffer.Length);

                if (bytes <= 0)
                    break;

                lock (clients)
                {
                    if (clients.ContainsKey(currentClient))
                        clients[currentClient] = Time.realtimeSinceStartup;
                }

                int charCount = decoder.GetChars(buffer, 0, bytes, chars, 0);
                pending.Append(chars, 0, charCount);

                // Cada mensaje termina en '\n'. Un mismo Read puede traer
                // varios mensajes o solo una parte de uno.
                foreach (string msg in SimpleNetwork.ExtractMessages(pending))
                {
                    // Latido del cliente: solo sirve para saber que sigue conectado.
                    if (msg == SimpleNetwork.PING)
                        continue;

                    if (activeView != null && activeView.receivedText != null)
                        activeView.receivedText.text = msg;

                    Debug.Log($"SYNC TEST 3: Mensaje recibido de {clientIP}: {msg}");

                    if (UserSyncService.Instance != null)
                    {
                        UserSyncService.Instance.ProcessMessage(msg);
                    }
                    else
                    {
                        Debug.LogError("SYNC ERROR: UserSyncService.Instance es NULL.");
                    }
                }
            }
        }
        catch (Exception e)
        {
            if (running)
                Debug.LogWarning("SimpleServer: cliente " + clientIP + " desconectado: " + e.Message);
        }
        finally
        {
            RemoveClient(currentClient);
        }
    }

    private static void RemoveClient(TcpClient clientToRemove)
    {
        if (clientToRemove == null)
            return;

        bool removed;
        lock (clients)
        {
            removed = clients.Remove(clientToRemove);
        }

        try { clientToRemove.Close(); } catch { }

        if (removed)
        {
            Debug.Log("SimpleServer: cliente desconectado. Clientes restantes: " + ConnectedCount);
            RefreshStatus();
        }
    }

    private static async Task TimeoutLoop()
    {
        while (running)
        {
            await Task.Delay(5000);
            RemoveTimedOutClients();
        }
    }

    /// <summary>
    /// Cierra los clientes que llevan demasiado tiempo sin enviar nada
    /// (p. ej. un celular que perdió el Wi-Fi sin cerrar la conexión).
    /// </summary>
    private static void RemoveTimedOutClients()
    {
        float now = Time.realtimeSinceStartup;
        List<TcpClient> expired = new List<TcpClient>();

        lock (clients)
        {
            foreach (KeyValuePair<TcpClient, float> pair in clients)
            {
                if (now - pair.Value > ClientTimeoutSeconds)
                    expired.Add(pair.Key);
            }
        }

        foreach (TcpClient c in expired)
        {
            Debug.Log("SimpleServer: cliente sin actividad, se cierra la conexión.");
            RemoveClient(c);
        }
    }

    /// <summary>
    /// Conservado para no romper botones existentes en la escena.
    /// La información solo viaja de cliente a servidor, así que no envía nada.
    /// </summary>
    public void SendMessage()
    {
        Debug.Log("SimpleServer: el servidor no envía datos a los clientes.");
    }

    private void OnApplicationQuit()
    {
        running = false;

        try { discoveryServer?.Close(); } catch { }
        discoveryServer = null;

        lock (clients)
        {
            foreach (TcpClient c in clients.Keys)
            {
                try { c.Close(); } catch { }
            }

            clients.Clear();
        }

        try { listener?.Stop(); } catch { }
        listener = null;
    }
}
