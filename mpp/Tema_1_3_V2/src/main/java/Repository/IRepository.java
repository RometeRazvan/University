package Repository;

import Domain.Entity;

import javax.lang.model.type.ArrayType;

public interface IRepository<ID, E extends Entity<ID>> {

    public void save(E e);
    public E get(ID id);

}
