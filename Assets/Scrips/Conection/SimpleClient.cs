using System;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using TMPro;
using UnityEngine;

public class SimpleClient : MonoBehaviour
{
    public static SimpleClient Instance { get; private set; }
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

    public async void Connect()
    {
        try
        {
            statusText.text = "Buscando servidor...";

            string serverIP = await FindServer();

            if (string.IsNullOrEmpty(serverIP))
            {
                statusText.text = "Servidor no encontrado";
                Debug.LogWarning("No se encontró ningún servidor.");
                return;
            }

            Debug.Log("Servidor encontrado en: " + serverIP);

            // Conservamos este campo para mostrar la IP encontrada.
            if (serverIPInput != null)
                serverIPInput.text = serverIP;

            statusText.text = "Servidor encontrado. Conectando...";

            client = new TcpClient();

            await client.ConnectAsync(
                serverIP,
                SimpleNetwork.PORT
            );

            stream = client.GetStream();

            statusText.text = "Conectado";
            Debug.Log("Cliente conectado correctamente");

            _ = ReceiveMessages();
        }
        catch (Exception e)
        {
            statusText.text = "Error de conexión";
            Debug.LogError(e);
        }
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

    async Task ReceiveMessages()
    {
        byte[] buffer = new byte[1024];

        while (client != null && client.Connected)
        {
            int bytes = await stream.ReadAsync(
                buffer,
                0,
                buffer.Length
            );

            if (bytes <= 0)
                break;

            string msg = Encoding.UTF8.GetString(
                buffer,
                0,
                bytes
            );

            receivedText.text = msg;

if (UserSyncService.Instance != null)
{
    UserSyncService.Instance.ProcessMessage(msg);
}
        }

        statusText.text = "Desconectado";
    }

    public async void SendMessage()
    {
        if (stream == null)
            return;

        string msg = messageInput.text;

        if (string.IsNullOrWhiteSpace(msg))
            return;

        byte[] data = Encoding.UTF8.GetBytes(msg);

        await stream.WriteAsync(
            data,
            0,
            data.Length
        );
    }

    private void OnApplicationQuit()
    {
        stream?.Close();
        client?.Close();
    }

    public async Task SendRawMessage(string msg)
{
    if (stream == null)
    {
        Debug.LogWarning(
            "SimpleClient: no hay conexión activa."
        );
        return;
    }

    if (string.IsNullOrWhiteSpace(msg))
        return;

    byte[] data = Encoding.UTF8.GetBytes(msg);

    await stream.WriteAsync(
        data,
        0,
        data.Length
    );
}
}