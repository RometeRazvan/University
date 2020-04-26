package Service;

import IService.IServiceUser;
import Models.Caritate;
import Models.User;
import Observer.IObserver;
import Repository.UsersRepo;

import java.sql.Connection;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class ServiceUser implements IServiceUser {

    private UsersRepo ur;
    private List<IObserver> list;

    public ServiceUser(UsersRepo ur) {
        this.ur = ur;
    }

    public ServiceUser() {
        this.ur = new UsersRepo();
    }

    @Override
    public synchronized User findByName(String nume, IObserver observer) {
        list.add(observer);
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

    private final int defaultThreadsNo=5;

    public void notifyClients(List<Caritate> l) {
        ExecutorService executor= Executors.newFixedThreadPool(defaultThreadsNo);
        for(IObserver o : list)
        {
            executor.execute(() -> {
                try{
                    o.reloadList(l);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            });
        }
    }
}
