package Service;

import Domain.Entity;

public interface IServiceCaritate<E extends Entity> extends IService<E> {

    E findByName(String nume);

    Iterable<E> findAll();

}
