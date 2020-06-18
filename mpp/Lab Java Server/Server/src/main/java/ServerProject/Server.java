package ServerProject;

import IService.IServiceCaritate;
import IService.IServiceDonatii;
import IService.IServiceUser;
import Protocol.ConcurentServer;
import Service.ServiceCaritate;
import Service.ServiceDonatie;
import Service.ServiceUser;

import java.rmi.ServerException;

public class Server {

    private static int defaultPort = 55555;

    public static void main(String[] args) {
        int serverPort = defaultPort;

        IServiceCaritate serviceCaritate = new ServiceCaritate();
        IServiceDonatii serviceDonatii = new ServiceDonatie();
        IServiceUser serviceUser = new ServiceUser();

        ConcurentServer server = new ConcurentServer(serverPort, serviceCaritate, serviceDonatii, serviceUser);

        try {
            server.start();
        } catch (ServerException e) {
            e.printStackTrace();
        } finally {
            server.stop();
        }
    }

}
