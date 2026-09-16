using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;

public class SimpleServer : MonoBehaviour
{
    [Header("UI")]
    public TMP_Text statusText;
    public TMP_Text receivedText;
    public TMP_Text myIPText;
    public TMP_InputField messageInput;

    private TcpListener listener;

    // Lista de clientes conectados
    private readonly List<TcpClient> clients = new List<TcpClient>();

    private UdpClient discoveryServer;
    private bool discoveryRunning;

    private void Start()
    {
        myIPText.text = "IP: " + SimpleNetwork.GetLocalIPAddress();
        statusText.text = "Servidor detenido";

        StartServer();
    }

    public async void StartServer()
    {
        if (listener != null)
        {
            Debug.Log("SimpleServer: el servidor ya está iniciado.");
            return;
        }

        try
        {
            // Iniciar descubrimiento automático
            StartDiscoveryServer();

            listener = new TcpListener(
                IPAddress.Any,
                SimpleNetwork.PORT
            );

            listener.Start();

            statusText.text = "Esperando conexiones...";

            Debug.Log(
                "SimpleServer: servidor TCP iniciado. " +
                "Esperando clientes..."
            );

            // Mantener el servidor aceptando clientes
            while (listener != null)
            {
                TcpClient newClient =
                    await listener.AcceptTcpClientAsync();

                if (newClient == null)
                    continue;

                lock (clients)
                {
                    clients.Add(newClient);
                }

                string clientIP =
                    ((IPEndPoint)newClient.Client.RemoteEndPoint)
                    .Address
                    .ToString();

                Debug.Log(
                    "SimpleServer: nuevo cliente conectado desde " +
                    clientIP
                );

                statusText.text =
                    "Clientes conectados: " +
                    clients.Count;

                // Cada cliente tiene su propio proceso de recepción
                _ = ReceiveMessages(newClient);
            }
        }
        catch (ObjectDisposedException)
        {
            Debug.Log(
                "SimpleServer: listener detenido."
            );
        }
        catch (Exception e)
        {
            statusText.text = "Error";
            Debug.LogError(
                "SimpleServer: error en servidor: " +
                e.Message
            );
        }
    }

    private void StartDiscoveryServer()
    {
        if (discoveryServer != null)
        {
            Debug.Log(
                "SimpleServer: descubrimiento ya iniciado."
            );
            return;
        }

        try
        {
            discoveryServer =
                new UdpClient(SimpleNetwork.DISCOVERY_PORT);

            discoveryRunning = true;

            Debug.Log(
                "Servidor de descubrimiento iniciado en puerto " +
                SimpleNetwork.DISCOVERY_PORT
            );

            _ = ListenForDiscovery();
        }
        catch (Exception e)
        {
            Debug.LogError(
                "Error iniciando servidor de descubrimiento: " +
                e.Message
            );
        }
    }

    private async Task ListenForDiscovery()
    {
        IPEndPoint remoteEndPoint =
            new IPEndPoint(IPAddress.Any, 0);

        while (
            discoveryRunning &&
            discoveryServer != null
        )
        {
            try
            {
                UdpReceiveResult result =
                    await discoveryServer.ReceiveAsync();

                string message =
                    Encoding.UTF8.GetString(
                        result.Buffer
                    );

                if (
                    message ==
                    SimpleNetwork.DISCOVERY_REQUEST
                )
                {
                    byte[] response =
                        Encoding.UTF8.GetBytes(
                            SimpleNetwork.DISCOVERY_RESPONSE
                        );

                    await discoveryServer.SendAsync(
                        response,
                        response.Length,
                        result.RemoteEndPoint
                    );

                    Debug.Log(
                        "Solicitud de descubrimiento recibida de: " +
                        result.RemoteEndPoint.Address
                    );
                }
            }
            catch (ObjectDisposedException)
            {
                break;
            }
            catch (Exception e)
            {
                if (discoveryRunning)
                {
                    Debug.LogError(
                        "Error en descubrimiento: " +
                        e.Message
                    );
                }
            }
        }
    }

    private async Task ReceiveMessages(TcpClient currentClient)
    {
        NetworkStream currentStream =
            currentClient.GetStream();

        byte[] buffer = new byte[1024];

        try
        {
            while (
                currentClient != null &&
                currentClient.Connected
            )
            {
                int bytes = await currentStream.ReadAsync(
                    buffer,
                    0,
                    buffer.Length
                );

                if (bytes <= 0)
                    break;

                string msg =
                    Encoding.UTF8.GetString(
                        buffer,
                        0,
                        bytes
                    );

                receivedText.text = msg;

                string clientIP =
                    ((IPEndPoint)currentClient.Client.RemoteEndPoint)
                    .Address
                    .ToString();

                Debug.Log(
                    $"SYNC TEST 3: Mensaje recibido de {clientIP}: {msg}"
                );

                if (UserSyncService.Instance != null)
                {
                    Debug.Log(
                        "SYNC TEST 4: Enviando mensaje a UserSyncService."
                    );

                    UserSyncService.Instance.ProcessMessage(msg);
                }
                else
                {
                    Debug.LogError(
                        "SYNC ERROR: UserSyncService.Instance es NULL."
                    );
                }
                await BroadcastMessage(msg, currentClient);
            }
        }
        catch (Exception e)
        {
            Debug.LogError(
                "SimpleServer: error recibiendo mensaje: " +
                e.Message
            );
        }
        finally
        {
            RemoveClient(currentClient);
        }
    }
private async Task BroadcastMessage(
    string msg,
    TcpClient sender
)
{
    byte[] data = Encoding.UTF8.GetBytes(msg);

    List<TcpClient> clientsCopy;

    lock (clients)
    {
        clientsCopy = new List<TcpClient>(clients);
    }

    foreach (TcpClient currentClient in clientsCopy)
    {
        // No reenviar el mensaje al cliente que lo envió
        if (currentClient == sender)
            continue;

        try
        {
            NetworkStream currentStream =
                currentClient.GetStream();

            await currentStream.WriteAsync(
                data,
                0,
                data.Length
            );

            Debug.Log(
                "SimpleServer: mensaje reenviado a otro cliente."
            );
        }
        catch (Exception e)
        {
            Debug.LogError(
                "SimpleServer: error reenviando mensaje: " +
                e.Message
            );

            RemoveClient(currentClient);
        }
    }
}
    private void RemoveClient(TcpClient clientToRemove)
    {
        if (clientToRemove == null)
            return;

        lock (clients)
        {
            clients.Remove(clientToRemove);
        }

        try
        {
            clientToRemove.GetStream()?.Close();
        }
        catch
        {
        }

        try
        {
            clientToRemove.Close();
        }
        catch
        {
        }

        Debug.Log(
            "SimpleServer: cliente desconectado. " +
            "Clientes restantes: " +
            clients.Count
        );

        statusText.text =
            "Clientes conectados: " +
            clients.Count;
    }

    public async void SendMessage()
    {
        string msg = messageInput.text;

        if (string.IsNullOrWhiteSpace(msg))
            return;

        byte[] data =
            Encoding.UTF8.GetBytes(msg);

        List<TcpClient> clientsCopy;

        lock (clients)
        {
            clientsCopy =
                new List<TcpClient>(clients);
        }

        foreach (TcpClient currentClient in clientsCopy)
        {
            try
            {
                NetworkStream currentStream =
                    currentClient.GetStream();

                await currentStream.WriteAsync(
                    data,
                    0,
                    data.Length
                );
            }
            catch (Exception e)
            {
                Debug.LogError(
                    "Error enviando mensaje a cliente: " +
                    e.Message
                );

                RemoveClient(currentClient);
            }
        }
    }

    private void OnApplicationQuit()
    {
        discoveryRunning = false;

        discoveryServer?.Close();

        lock (clients)
        {
            foreach (TcpClient currentClient in clients)
            {
                try
                {
                    currentClient.GetStream()?.Close();
                    currentClient.Close();
                }
                catch
                {
                }
            }

            clients.Clear();
        }

        listener?.Stop();
    }
}