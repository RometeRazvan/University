package Repository;

import Domain.Entity;

import java.sql.SQLException;

public interface IUsersRepo<E extends Entity> extends  ICrudRepo<E> {

    E findByName(String nume);

}
