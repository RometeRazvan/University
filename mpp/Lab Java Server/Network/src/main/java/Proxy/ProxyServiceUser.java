package Proxy;

import IService.IServiceUser;
import Models.Caritate;
import Models.User;
import Observer.Observable;
import Utils.Request;
import Utils.Response;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.sql.Connection;
import java.util.List;

public class ProxyServiceUser implements IServiceUser, Observable {

    private ObjectInputStream inputStream;
    private ObjectOutputStream outputStream;
    private Socket connection;
    private ResponseReader responseReader;
    private Observable client;

    public ProxyServiceUser(ObjectInputStream inputStream, ObjectOutputStream outputStream, Socket connection, ResponseReader responseReader) {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
        this.connection = connection;
        this.responseReader = responseReader;
    }

    @Override
    public User findByName(String nume, Observable observable) {
        this.client = observable;

        Request request = new Request("LogIn", nume);

        try {
            outputStream.writeObject(request);
            outputStream.flush();

            Response response = responseReader.readResponse();

            return response.getUser();

        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }

    public void disconnect() {

        Request request = new Request("LogOut");

        try {
            outputStream.writeObject(request);
            outputStream.flush();

            inputStream.close();
            outputStream.close();

            connection.close();

            client = null;
        } catch (IOException e) {
            e.printStackTrace();
        }

        responseReader.logOut();
    }

    @Override
    public void notifyClients(List<Caritate> list) {
        getNotified(list);
    }

    @Override
    public void getNotified(List<Caritate> list) {
        this.client.getNotified(list);
    }

    @Override
    public User findOne(int id) {
        return null;
    }

    @Override
    public Connection getConnection() {
        return null;
    }
}
