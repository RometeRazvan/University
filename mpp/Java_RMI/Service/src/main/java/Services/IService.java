package Services;

import Models.Caritate;
import Models.Donatie;
import Models.User;

import java.util.List;

public interface IService {

    User findByName(String name) throws ChatException;

    void addClient(IObserver observer) throws ChatException;

    List<Caritate> findAll() throws ChatException;

    void save(String nume, String adresa, String nrTel, int suma, String caritate) throws ChatException;

    List<Donatie> searchByName(String name) throws ChatException;

}
