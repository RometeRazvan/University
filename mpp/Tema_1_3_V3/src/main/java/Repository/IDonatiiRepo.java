package Repository;

import Domain.Entity;

public interface IDonatiiRepo<E extends Entity> extends ICrudRepo<E> {

    E findByNameAddressPhone(String nume, String address, String phone);

    E findByName(String nume);

}
