package Proxy;

import IService.IServiceDonatii;
import Models.Donatie;
import Observer.Observable;
import Utils.Request;
import Utils.Response;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;
import java.sql.Connection;

public class ProxySeviceDonatii implements IServiceDonatii {

    private ObjectInputStream inputStream;
    private ObjectOutputStream outputStream;
    private Socket connection;
    private ResponseReader responseReader;
    private Observable client;

    public ProxySeviceDonatii(ObjectInputStream inputStream, ObjectOutputStream outputStream, Socket connection, ResponseReader responseReader) {
        this.inputStream = inputStream;
        this.outputStream = outputStream;
        this.connection = connection;
        this.responseReader = responseReader;
    }

    @Override
    public Donatie findByName(String nume) {
        return null;
    }

    @Override
    public Donatie findByNameAdressPhone(String nume, String adress, String phone) {
        return null;
    }

    @Override
    public Donatie save(String nume, String adresa, String nrTel, int suma, String numeCaritate) {
        Donatie donatie = new Donatie(nume, adresa, nrTel, suma);
        Request request = new Request("SaveDonatie", numeCaritate, donatie);

        try {
            outputStream.writeObject(request);
            outputStream.flush();

            Response response = responseReader.readResponse();

            return response.getDonatie();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }

    @Override
    public Iterable<Donatie> searchByName(String nume) {
        Request request = new Request("listaDonatii");
        request.setDonationName(nume);

        try {
            outputStream.writeObject(request);
            outputStream.flush();

            Response response = responseReader.readResponse();

            return response.getListDonatie();
        } catch (IOException e) {
            e.printStackTrace();
        }

        return null;
    }

    @Override
    public Donatie findOne(int id) {
        return null;
    }

    @Override
    public Connection getConnection() {
        return null;
    }
}
