package IRepository;

import Models.Donatie;

public interface IDonatiiRepo {

    Donatie findByNameAddressPhone(String nume, String address, String phone);

    Donatie findByName(String nume);

    Iterable<Donatie> searchByPartialName(String nume);

    Donatie findOne(int id);

    void clear();

    Donatie save(Donatie entity);
}
