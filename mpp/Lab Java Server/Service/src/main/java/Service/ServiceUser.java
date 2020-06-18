package Service;

import IService.IServiceUser;
import Models.Caritate;
import Models.User;
import Observer.Observable;
import Repository.UsersRepo;

import java.sql.Connection;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ServiceUser implements IServiceUser {

    private UsersRepo ur;
    private List<Observable> listObs;

    public ServiceUser(UsersRepo ur) {
        this.ur = ur;
    }

    public ServiceUser() {
        this.ur = new UsersRepo();
        listObs = new ArrayList<>();
    }

    @Override
    public synchronized User findByName(String nume, Observable observable) {
        listObs.add(observable);
        return ur.findByName(nume);
    }

    @Override
    public User findOne(int id) {
        return ur.findOne(id);
    }

    @Override
    public Connection getConnection() {
        return ur.getConnection();
    }

    @Override
    public void disconnect() {

    }

    private final int defaultThreadsNo=200;

    @Override
    public void notifyClients(List<Caritate> list) {
        ExecutorService executor= Executors.newFixedThreadPool(defaultThreadsNo);
        for(Observable o : listObs)
        {
            executor.execute(() -> {
                try{
                    o.getNotified(list);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
        }
    }
}
