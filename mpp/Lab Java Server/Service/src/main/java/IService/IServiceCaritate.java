package IService;


import Models.Caritate;

import java.sql.Connection;

public interface IServiceCaritate {

    Caritate findByName(String nume);

    Iterable<Caritate> findAll();

    Caritate findOne(int id);

    Connection getConnection();
}
