package Repository;

import Domain.Entity;

import java.sql.SQLException;

public interface ICrudRepo<E extends Entity> {

    E findOne(int id) throws SQLException;

    E save(E entity);

    public void clear();

}
