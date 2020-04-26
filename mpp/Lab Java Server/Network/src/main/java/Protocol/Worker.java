package Protocol;

import IService.IServiceCaritate;
import IService.IServiceDonatii;
import IService.IServiceUser;
import Models.Caritate;
import Models.User;
import Observer.IObserver;
import Utils.Request;
import Utils.Response;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.net.Socket;
import java.util.List;

public class Worker implements Runnable, IObserver {

    private IServiceCaritate serviceCaritate;
    private IServiceDonatii serviceDonatii;
    private IServiceUser serviceUser;
    private Socket connection;
    private ObjectInputStream input;
    private ObjectOutputStream output;
    private volatile boolean connected;

    public Worker(IServiceCaritate sc, IServiceDonatii sd, IServiceUser su, Socket connection) {
        this.serviceCaritate = sc;
        this.serviceDonatii = sd;
        this.serviceUser = su;
        this.connection = connection;

        try {
            output = new ObjectOutputStream(connection.getOutputStream());
            output.flush();

            input = new ObjectInputStream(connection.getInputStream());

            connected = true;
        }
        catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    @Override
    public void reloadList(List<Caritate> list) {
        Response response = new Response("Observer");
        response.setListCaritate(list);

        try {
            output.writeObject(response);
            output.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void run() {
        while (connected) {
            try {
                Object request = input.readObject();
                respondTo((Request) request);
            } catch (IOException e) {
                e.printStackTrace();
            } catch (ClassNotFoundException e) {
                e.printStackTrace();
            }
        }
        try {
            input.close();
            output.close();
            connection.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void respondTo(Request request) {
        switch (request.getMesaj()) {
            case "LogIn":
                login(request);
                break;
            case "findAll":
                findAll();
                break;
        }
    }

    private void login(Request request) {

        System.out.println(request.getUser().getNume());

        User user = serviceUser.findByName(request.getUser().getNume(), this);

        Response response = new Response("Cautare efectuata", user);

        try {
            output.writeObject(response);
            output.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void findAll() {
        List<Caritate> list = (List<Caritate>) serviceCaritate.findAll();

        Response response = new Response("Lista Caritate", list);

        try {
            output.writeObject(response);
            output.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
