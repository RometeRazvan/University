package IService;


import Models.Caritate;
import Models.User;
import Observer.IObserver;

import java.sql.Connection;
import java.util.List;

public interface IServiceUser {

    User findByName(String nume, IObserver observer);

    User findOne(int id);

    Connection getConnection();

    void notifyClients(List<Caritate> l);
}
