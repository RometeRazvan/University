package IService;

import Models.Donatie;

import java.sql.Connection;

public interface IServiceDonatii {

    Donatie findByName(String nume);

    Donatie findByNameAdressPhone(String nume, String adress, String phone);

    Donatie save(String nume, String adresa, String nrTel, int suma, String numeCaritate);

    Iterable<Donatie> searchByName(String nume);

    Donatie findOne(int id);

    Connection getConnection();
}
