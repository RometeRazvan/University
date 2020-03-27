package Service;

import Domain.Donatie;
import Domain.Validator.ValidationException;
import Domain.Validator.Validator;
import Repository.CazuriCaritabileRepo;
import Repository.DonatiiRepo;

import java.sql.Connection;

public class ServiceDonatie implements IServiceDonatii<Donatie> {
    private DonatiiRepo dr;
    private CazuriCaritabileRepo ccr;
    private Validator validator;

    public ServiceDonatie(DonatiiRepo dr) {
        this.dr = dr;
        this.validator = new Validator();
    }

    public ServiceDonatie() {
        this.dr = new DonatiiRepo();
        this.ccr = new CazuriCaritabileRepo();
        this.validator = new Validator();
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
    public Donatie save(String nume, String adresa, String nrTel, int suma, String numeCaritate) throws ValidationException {
        Donatie donatie = new Donatie(nume, adresa, nrTel, suma);
        validator.validate(donatie);
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
