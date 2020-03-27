package Service;

import Domain.Entity;

import java.sql.Connection;

public interface IService<E extends Entity> {

    E findOne(int id);

    Connection getConnection();

}
