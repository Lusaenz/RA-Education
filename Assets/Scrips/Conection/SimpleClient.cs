using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;

public class SimpleClient : MonoBehaviour
{
    public static SimpleClient Instance { get; private set; }

    // Segundos de espera antes de volver a buscar el servidor.
    private const float ReconnectDelaySeconds = 5f;

    private void Awake()
{
    if (Instance == null)
    {
        Instance = this;
        DontDestroyOnLoad(gameObject);
    }
    else
    {
        Destroy(gameObject);
    }
}
private void Start()
{
    Debug.Log("SimpleClient: iniciando búsqueda automática de servidor...");
    Connect();
}

    [Header("UI")]
    public TMP_InputField serverIPInput;
    public TMP_InputField messageInput;

    public TMP_Text statusText;
    public TMP_Text receivedText;

    private TcpClient client;
    private NetworkStream stream;

    // Evita escrituras simultáneas en el stream (los mensajes se mezclarían).
    private readonly SemaphoreSlim writeLock = new SemaphoreSlim(1, 1);

    private bool isConnecting;
    private bool isQuitting;

    public bool IsConnected =>
        client != null && client.Connected && stream != null;

    // Los textos pueden destruirse al cambiar de escena (este objeto es DontDestroyOnLoad).
    private void SetStatus(string text)
    {
        if (statusText != null)
            statusText.text = text;
    }

    public async void Connect()
    {
        if (isConnecting || IsConnected || isQuitting)
            return;

        isConnecting = true;

        try
        {
            SetStatus("Buscando servidor...");

            string serverIP = await FindServer();

            if (string.IsNullOrEmpty(serverIP))
            {
                SetStatus("Servidor no encontrado");
                Debug.LogWarning("No se encontró ningún servidor.");
                ScheduleReconnect();
                return;
            }

            Debug.Log("Servidor encontrado en: " + serverIP);

            // Conservamos este campo para mostrar la IP encontrada.
            if (serverIPInput != null)
                serverIPInput.text = serverIP;

            SetStatus("Servidor encontrado. Conectando...");

            client = new TcpClient();
            client.NoDelay = true;

            await client.ConnectAsync(
                serverIP,
                SimpleNetwork.PORT
            );

            stream = client.GetStream();

            SetStatus("Conectado");
            Debug.Log("Cliente conectado correctamente");

            _ = ReceiveMessages(client, stream);
            _ = HeartbeatLoop(client);

            // Enviar todo lo que haya cambiado mientras no había conexión.
            await UserSyncService.SendFullSync();
        }
        catch (Exception e)
        {
            SetStatus("Error de conexión");
            Debug.LogError(e);
            CloseConnection();
            ScheduleReconnect();
        }
        finally
        {
            isConnecting = false;
        }
    }

    private void ScheduleReconnect()
    {
        if (isQuitting || this == null)
            return;

        CancelInvoke(nameof(Connect));
        Invoke(nameof(Connect), ReconnectDelaySeconds);
    }

    private void CloseConnection()
    {
        try { stream?.Close(); } catch { }
        try { client?.Close(); } catch { }

        stream = null;
        client = null;
    }

    private async Task<string> FindServer()
    {
        using (UdpClient udp = new UdpClient())
        {
            udp.EnableBroadcast = true;

            byte[] request = Encoding.UTF8.GetBytes(
                SimpleNetwork.DISCOVERY_REQUEST
            );

            IPEndPoint broadcastEndPoint =
                new IPEndPoint(
                    IPAddress.Broadcast,
                    SimpleNetwork.DISCOVERY_PORT
                );

            await udp.SendAsync(
                request,
                request.Length,
                broadcastEndPoint
            );

            Debug.Log("Buscando servidor en la red...");

            Task<UdpReceiveResult> receiveTask =
                udp.ReceiveAsync();

            Task timeoutTask =
                Task.Delay(3000);

            Task completedTask =
                await Task.WhenAny(
                    receiveTask,
                    timeoutTask
                );

            if (completedTask == receiveTask)
            {
                UdpReceiveResult result =
                    await receiveTask;

                string response =
                    Encoding.UTF8.GetString(
                        result.Buffer
                    );

                if (response ==
                    SimpleNetwork.DISCOVERY_RESPONSE)
                {
                    return result.RemoteEndPoint.Address.ToString();
                }
            }

            return null;
        }
    }

    async Task ReceiveMessages(TcpClient currentClient, NetworkStream currentStream)
    {
        byte[] buffer = new byte[4096];
        char[] chars = new char[Encoding.UTF8.GetMaxCharCount(buffer.Length)];
        Decoder decoder = Encoding.UTF8.GetDecoder();
        StringBuilder pending = new StringBuilder();

        try
        {
            while (currentClient.Connected)
            {
                int bytes = await currentStream.ReadAsync(
                    buffer,
                    0,
                    buffer.Length
                );

                if (bytes <= 0)
                    break;

                int charCount = decoder.GetChars(buffer, 0, bytes, chars, 0);
                pending.Append(chars, 0, charCount);

                // Cada mensaje termina en '\n'. Un mismo Read puede traer
                // varios mensajes o solo una parte de uno.
                foreach (string msg in SimpleNetwork.ExtractMessages(pending))
                {
                    if (receivedText != null)
                        receivedText.text = msg;

                    if (UserSyncService.Instance != null)
                    {
                        UserSyncService.Instance.ProcessMessage(msg);
                    }
                }
            }
        }
        catch (Exception e)
        {
            if (!isQuitting)
                Debug.LogWarning("SimpleClient: conexión perdida: " + e.Message);
        }

        // Solo cerrar si sigue siendo la conexión activa (pudo reconectarse ya).
        if (client == currentClient)
        {
            CloseConnection();
            SetStatus("Desconectado");
            ScheduleReconnect();
        }
    }

    /// <summary>
    /// Envía un PING periódico. Le permite al servidor saber que el dispositivo sigue
    /// conectado y al cliente detectar rápido si la conexión se cayó (falla el envío).
    /// </summary>
    private async Task HeartbeatLoop(TcpClient currentClient)
    {
        while (!isQuitting && client == currentClient && IsConnected)
        {
            await Task.Delay(SimpleNetwork.PING_INTERVAL_MS);

            if (this == null || client != currentClient || !IsConnected)
                break;

            await SendRawMessage(SimpleNetwork.PING);
        }
    }

    public async void SendMessage()
    {
        if (stream == null || messageInput == null)
            return;

        await SendRawMessage(messageInput.text);
    }

    private void OnApplicationQuit()
    {
        isQuitting = true;
        CancelInvoke();
        CloseConnection();
    }

    public async Task SendRawMessage(string msg)
{
    if (!IsConnected)
    {
        Debug.LogWarning(
            "SimpleClient: no hay conexión activa."
        );
        return;
    }

    if (string.IsNullOrWhiteSpace(msg))
        return;

    // '\n' marca el final de cada mensaje.
    byte[] data = Encoding.UTF8.GetBytes(msg.Trim() + "\n");

    await writeLock.WaitAsync();

    NetworkStream currentStream = stream;

    try
    {
        if (currentStream == null)
            return;

        await currentStream.WriteAsync(
            data,
            0,
            data.Length
        );
    }
    catch (Exception e)
    {
        Debug.LogWarning("SimpleClient: error enviando mensaje: " + e.Message);

        if (stream == currentStream)
        {
            CloseConnection();
            SetStatus("Desconectado");
            ScheduleReconnect();
        }
    }
    finally
    {
        writeLock.Release();
    }
}
}
