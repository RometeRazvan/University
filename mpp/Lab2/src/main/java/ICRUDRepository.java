import java.util.Enumeration;

public interface ICRUDRepository<ID,E extends Entity<ID>> {

    public E findOne(String id);
    public void save(E e);
    public void delete(ID id);

}
