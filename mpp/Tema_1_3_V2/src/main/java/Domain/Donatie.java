package Domain;

import Domain.Entity;

public class Donatie<ID> implements Entity<ID> {

    private ID id;
    private String name, adresa, nrTel;
    private Integer suma;

    public Donatie(ID id, String name, String adresa, String nrTel, Integer suma) {
        this.id = id;
        this.name = name;
        this.adresa = adresa;
        this.nrTel = nrTel;
        this.suma = suma;
    }

    public Donatie(String name, String adresa, String nrTel, Integer suma) {
        this.name = name;
        this.adresa = adresa;
        this.nrTel = nrTel;
        this.suma = suma;
    }

    @Override
    public ID getId() {
        return id;
    }

    public void setId(ID id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAdresa() {
        return adresa;
    }

    public void setAdresa(String adresa) {
        this.adresa = adresa;
    }

    public String getNrTel() {
        return nrTel;
    }

    public void setNrTel(String nrTel) {
        this.nrTel = nrTel;
    }

    public Integer getSuma() {
        return suma;
    }

    public void setSuma(Integer suma) {
        this.suma = suma;
    }

}
