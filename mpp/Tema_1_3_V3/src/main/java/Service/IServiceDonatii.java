package Service;

import Domain.Entity;
import Domain.Validator.ValidationException;

public interface IServiceDonatii<E extends Entity> extends IService<E> {

    E findByName(String nume);

    E findByNameAdressPhone(String nume, String adress, String phone);

    E save(String nume, String adresa, String nrTel, int suma, String numeCaritate) throws ValidationException;

    Iterable<E> searchByName(String nume);

}
