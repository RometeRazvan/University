package Service;

import IService.IServiceDonatii;
import Models.Donatie;
import Repository.CazuriCaritabileRepo;
import Repository.DonatiiRepo;

import java.sql.Connection;

public class ServiceDonatie implements IServiceDonatii {
    private DonatiiRepo dr;
    private CazuriCaritabileRepo ccr;

    public ServiceDonatie(DonatiiRepo dr) {
        this.dr = dr;
    }

    public ServiceDonatie() {
        this.dr = new DonatiiRepo();
        this.ccr = new CazuriCaritabileRepo();
    }

    @Override
    public Donatie findByName(String nume) {
        return dr.findByName(nume);
    }

    @Override
    public Donatie findByNameAdressPhone(String nume, String adress, String phone) {
        return dr.findByNameAddressPhone(nume, adress, phone);
    }

    @Override
    public Donatie save(String nume, String adresa, String nrTel, int suma, String numeCaritate) {
        Donatie donatie = new Donatie(nume, adresa, nrTel, suma);
        ccr.addSuma(numeCaritate, suma);
        return dr.save(donatie);
    }

    @Override
    public Iterable<Donatie> searchByName(String nume) {
        return dr.searchByPartialName(nume);
    }

    @Override
    public Donatie findOne(int id) {
        return dr.findOne(id);
    }

    @Override
    public Connection getConnection() {
        return dr.getConneection();
    }
}
