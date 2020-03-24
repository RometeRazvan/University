package Service;

import Domain.Entity;

public interface IService<E extends Entity> {

    E findOne(int id);

}
