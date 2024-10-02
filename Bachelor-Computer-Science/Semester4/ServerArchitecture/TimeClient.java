import java.io.*;
import java.net.*;

public class TimeClient {

    private Protocol protocol = Protocol.UDP;
    private final String server;
    private int clientPort = 10000;
    private final int stringLen = 100;

    public TimeClient(Protocol protocol, String server, int clientPort) {
        this.protocol = protocol;
        this.server = server;
        this.clientPort = clientPort;
    }

    public TimeClient(Protocol protocol, String server) {
        this.protocol = protocol;
        this.server = server;
    }

    public TimeClient(String server, int clientPort) {
        this.server = server;
        this.clientPort = clientPort;
    }

    public TimeClient(String server) {
        this.server = server;
    }

    public static void main(String args[]) throws IOException {
        TimeClient timeClientUDP = new TimeClient(Protocol.UDP, "localhost", 10000);
        TimeClient timeClientTCP = new TimeClient(Protocol.TCP, "localhost", 10001);
        System.out.println("UDP ping: " + timeClientUDP.ping(timeClientUDP.server, 50000));
        System.out.println("TCP ping: " + timeClientTCP.ping(timeClientTCP.server, 50000));
    }

    public void pingNTimes(TimeClient timeClient, int amount) throws IOException {
        long time = System.currentTimeMillis();
        for(int i = 0; i < amount; i++) timeClient.ping(timeClient.server, 50000);
        System.out.println("Time elapsed: " + (System.currentTimeMillis() - time) + "ms");
    }

    public String ping(String addr, int serverPort) throws IOException {
        if (protocol == Protocol.UDP) {
            try {
                byte[] buffer = new byte[65507];
                DatagramSocket clientSocketUDP = new DatagramSocket();
                if(!clientSocketUDP.isBound()) clientSocketUDP = new DatagramSocket(clientPort);
                clientSocketUDP.send(new DatagramPacket("ping".getBytes(), 0, "ping".getBytes().length, InetAddress.getByName(addr), serverPort));
                while (true) {
                    DatagramPacket recieved = new DatagramPacket(buffer, 0, buffer.length);
                    clientSocketUDP.receive(recieved);
                    return (new String(recieved.getData(), 0, recieved.getLength()) + " send von UDP");
                }
            } catch (SocketException e) {
                e.printStackTrace();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else if (protocol == Protocol.TCP) {
            Socket clientStocketTCP = new Socket();
            if(!clientStocketTCP.isBound()) clientStocketTCP = new Socket(server, serverPort);
            PrintWriter printWriter = new PrintWriter(new OutputStreamWriter(clientStocketTCP.getOutputStream()));
            printWriter.println("ping");
            printWriter.flush();

            BufferedReader buf = new BufferedReader(new InputStreamReader((clientStocketTCP.getInputStream())));
            char[] buffer = new char[stringLen];
            int length = buf.read(buffer, 0, stringLen);
            return (new String(buffer, 0, length) + " send von TCP");
        }
        return "-1";
    }
}
