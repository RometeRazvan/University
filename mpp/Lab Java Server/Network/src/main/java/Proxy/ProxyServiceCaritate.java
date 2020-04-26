package Proxy;

import IService.IServiceCaritate;
import Models.Caritate;
import Observer.IObserver;
import Utils.Request;
import Utils.Response;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.sql.Connection;

public class ProxyServiceCaritate implements IServiceCaritate {

    private ObjectInputStream inputStream;
    private ObjectOutputStream outputStream;
    private Socket connection;
    private ResponseReader responseReader;

    public ProxyServiceCaritate(ObjectInputStream inputStream, ObjectOutputStream outputStream, Socket connection, ResponseReader responseReader) {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
        this.connection = connection;
        this.responseReader = responseReader;
    }

    @Override
    public Caritate findByName(String nume) {
        return null;
    }

    @Override
    public Iterable<Caritate> findAll() {
        Request request = new Request("findAll");

        try {
            outputStream.writeObject(request);
            outputStream.flush();

            Response response = responseReader.readResponse();

            return response.getListCaritate();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }

    @Override
    public Caritate findOne(int id) {
        return null;
    }

    @Override
    public Connection getConnection() {
        return null;
    }
}
