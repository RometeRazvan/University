package Server;

import Models.Caritate;
import Models.Donatie;
import Models.User;
import Repository.CazuriCaritabileRepo;
import Repository.DonatiiRepo;
import Repository.UsersRepo;
import Services.ChatException;
import Services.IObserver;
import Services.IService;
import javafx.beans.Observable;

import java.io.Serializable;
import java.rmi.RemoteException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class Service implements IService, Serializable {

    private UsersRepo usersRepo;
    private DonatiiRepo donatiiRepo;
    private CazuriCaritabileRepo cazuriCaritabileRepo;
    private List<IObserver> list = new ArrayList<>();

    public Service(UsersRepo usersRepo, DonatiiRepo donatiiRepo, CazuriCaritabileRepo cazuriCaritabileRepo) {
        this.usersRepo = usersRepo;
        this.donatiiRepo = donatiiRepo;
        this.cazuriCaritabileRepo = cazuriCaritabileRepo;
    }

    @Override
    public synchronized User findByName(String name) throws ChatException {
        try {
            User user = usersRepo.findByName(name);
            return user;
        }
        catch (Exception ex) {
            throw new ChatException(ex.getMessage());
        }
    }

    @Override
    public synchronized void addClient(IObserver observer) throws ChatException {
        try {
            list.add(observer);
        }
        catch (Exception ex) {
            throw new ChatException(ex.getMessage());
        }
    }

    @Override
    public synchronized List<Caritate> findAll() throws ChatException {
        try {
            List<Caritate> caritateList = (List<Caritate>) cazuriCaritabileRepo.findAll();
            return caritateList;
        }
        catch (Exception ex) {
            throw new ChatException(ex.getMessage());
        }
    }

    @Override
    public synchronized void save(String nume, String adresa, String nrTel, int suma, String caritate) throws ChatException {
        try {
            Donatie donatie = new Donatie(nume, adresa, nrTel, suma);
            donatiiRepo.save(donatie);
            cazuriCaritabileRepo.addSuma(caritate, suma);
        }
        catch (Exception ex) {
            throw new ChatException(ex.getMessage());
        }
        notifyObservers();
    }

    @Override
    public synchronized List<Donatie> searchByName(String name) throws ChatException {
        try {
            List<Donatie> donatieList = (List<Donatie>) donatiiRepo.findByName(name);
            return donatieList;
        }
        catch (Exception ex) {
            throw new ChatException(ex.getMessage());
        }
    }

    private void notifyObservers() {
        int defaultThreadsNo = 5;
        ExecutorService executor = Executors.newFixedThreadPool(defaultThreadsNo);
        for (IObserver observable : list) {
            executor.execute(() -> {
                try {
                    System.out.println("Notifying everyone for added new entity.");
                    observable.notify((List<Caritate>) cazuriCaritabileRepo.findAll());
                } catch (Exception ex) {
                    System.err.println("Error notifying friend " + ex.getMessage());
                }
            });
        }

        executor.shutdown();
    }
}
