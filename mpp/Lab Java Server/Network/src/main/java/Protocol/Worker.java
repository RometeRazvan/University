package Protocol;

import IService.IServiceCaritate;
import IService.IServiceDonatii;
import IService.IServiceUser;
import Models.Caritate;
import Models.Donatie;
import Models.User;
import Observer.Observable;
import Utils.Request;
import Utils.Response;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.util.List;

public class Worker implements Runnable, Observable {

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
            case "LogOut":
                logOut();
                break;
            case "SaveDonatie":
                saveDonatie(request);
                break;
            case "listaDonatii":
                getListDonatii(request);
                break;
        }
    }

    private void login(Request request) {

        User user = serviceUser.findByName(request.getUserName(), this);

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

    private void logOut() {
        connected = false;
    }

    public void notifyClients(List<Caritate> list) {
        serviceUser.notifyClients(list);
    }

    @Override
    public void getNotified(List<Caritate> list) {
        Response response = new Response("getNotified", list);

        try {
            output.writeObject(response);
            output.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void saveDonatie(Request request) {
        Donatie donatie = request.getDonatie();

        Donatie donatie2 = serviceDonatii.save(donatie.getNume(), donatie.getAdresa(), donatie.getNrTel(), donatie.getSuma(), request.getNumeCaritate());

        Response response = new Response("Salvat Donatie", donatie2);

        try {
            output.writeObject(response);
            output.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }

        notifyClients((List<Caritate>) serviceCaritate.findAll());
    }

    public void getListDonatii(Request request) {
        String nume = request.getDonationName();

        List<Donatie> list = (List<Donatie>) serviceDonatii.searchByName(nume);

        Response response = new Response("Return lista donatii");
        response.setListDonatie(list);

        try {
            output.writeObject(response);
            output.flush();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
