package Proxy;

import IService.IServiceUser;
import Models.Caritate;
import Models.User;
import Observer.IObserver;
import Utils.Request;
import Utils.Response;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.sql.Connection;
import java.util.List;

public class ProxyServiceUser implements IServiceUser {

    private ObjectInputStream inputStream;
    private ObjectOutputStream outputStream;
    private Socket connection;
    private ResponseReader responseReader;
    private IObserver client;

    public ProxyServiceUser(ObjectInputStream inputStream, ObjectOutputStream outputStream, Socket connection, ResponseReader responseReader) {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
        this.connection = connection;
        this.responseReader = responseReader;
    }

    @Override
    public User findByName(String nume, IObserver observer) {
        this.client = observer;

        Request request = new Request("LogIn", nume);

        try {
            outputStream.writeObject(request);
            outputStream.flush();

            Response response = responseReader.readResponse();

            System.out.println("!!!!!");

            return response.getUser();

        } catch (IOException e) {
            e.printStackTrace();
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }

    @Override
    public User findOne(int id) {
        return null;
    }

    @Override
    public Connection getConnection() {
        return null;
    }

    @Override
    public void notifyClients(List<Caritate> l) {
        this.client.reloadList(l);
    }
}
