package Protocol;

import IService.IServiceCaritate;
import IService.IServiceDonatii;
import IService.IServiceUser;
import Utils.ConcurentAbsServer;

import java.net.Socket;

public class ConcurentServer extends ConcurentAbsServer {

    private IServiceCaritate sercCaritate;
    private IServiceDonatii servDonatii;
    private IServiceUser servUser;

    public ConcurentServer(int port, IServiceCaritate sc, IServiceDonatii sd, IServiceUser su) {
        super(port);
        this.sercCaritate = sc;
        this.servDonatii = sd;
        this.servUser = su;
    }

    @Override
    protected Thread createWorker(Socket client) {
        Worker worker = new Worker(sercCaritate, servDonatii, servUser, client);
        Thread thread = new Thread(worker);
        return thread;
    }

    @Override
    public void stop() {
        System.out.println("Stopping Services ... ");
    }
}
