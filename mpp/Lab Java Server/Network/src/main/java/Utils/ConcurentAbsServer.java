package Utils;

import java.net.Socket;

public abstract class ConcurentAbsServer extends AbstractServer {

    public ConcurentAbsServer(int port) {
        super(port);
        System.out.println("Concurent Abstract Server");
    }

    @Override
    protected void processRequest(Socket client) {
        Thread thread = createWorker(client);
        thread.start();
    }

    protected abstract Thread createWorker(Socket client);
}
