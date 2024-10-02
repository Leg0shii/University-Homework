import java.io.*;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.ServerSocket;
import java.net.Socket;
import java.time.Instant;

public class TimeServer {

    private final int serverPort;

    public TimeServer(int serverPort) {
        this.serverPort = serverPort;
    }

    public TimeServer() {
        this.serverPort = 50000;
    }

    public static void main(String[] args) {
        TimeServer timeServer = new TimeServer(50000);
        timeServer.startServer();
    }

    public void listenForUDP() throws IOException {
        byte[] buffer = new byte[65507];
        DatagramSocket serverSocketUDP = new DatagramSocket(serverPort);
        System.out.println("UDP started!");
        while (true) {
            DatagramPacket datagramPacket = new DatagramPacket(buffer, 0, buffer.length);
            serverSocketUDP.receive(datagramPacket); //wartet bis client gesendet hat
            byte[] message = Instant.now().toString().getBytes();
            DatagramPacket sendPacket = new DatagramPacket(message, message.length, datagramPacket.getAddress(), datagramPacket.getPort());
            serverSocketUDP.send(sendPacket);
        }
    }

    public void listenForTCP() throws IOException {
        ServerSocket serverSocketTCP = new ServerSocket(serverPort);
        System.out.println("TCP started!");

        while (true) {
        Socket clientSocket = serverSocketTCP.accept();
            //warte bis ping vom Client kommt
            new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            PrintWriter printWriter = new PrintWriter(new OutputStreamWriter(clientSocket.getOutputStream()));
            printWriter.print(Instant.now().toString());
            printWriter.flush();
        }
    }

    public void startServer() {
        Thread udpListener = new Thread(() -> {
            try { listenForUDP(); }
            catch (IOException e) { e.printStackTrace(); }
        });
        udpListener.start();

        Thread tcpListener = new Thread(() -> {
            try { listenForTCP(); }
            catch (IOException e) { e.printStackTrace(); }
        });
        tcpListener.start();
    }
}
