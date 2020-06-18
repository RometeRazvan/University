package IService;


import Models.Caritate;
import Models.User;
import Observer.Observable;

import java.sql.Connection;
import java.util.List;

public interface IServiceUser {

    User findByName(String nume, Observable observable);

    User findOne(int id);

    Connection getConnection();

    void disconnect();

    void notifyClients(List<Caritate> list);
}
