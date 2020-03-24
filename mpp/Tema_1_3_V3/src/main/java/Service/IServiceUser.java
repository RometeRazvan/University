package Service;

import Domain.Entity;

public interface IServiceUser<E extends Entity> extends IService<E> {

    E findByName(String nume);

}
