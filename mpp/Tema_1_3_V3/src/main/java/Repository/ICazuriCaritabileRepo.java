package Repository;

import Domain.Entity;

public interface ICazuriCaritabileRepo<E extends Entity> extends ICrudRepo<E> {

    E findByName(String nume);

    Iterable<E> findAll();

    void addSuma(String nume, Integer suma);

}
