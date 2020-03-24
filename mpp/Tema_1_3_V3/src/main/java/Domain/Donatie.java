package Domain;

import java.util.Objects;

public class Donatie extends Entity {

    private String nume, adresa, nrTel;
    private Integer suma;

    public String getNume() {
        return nume;
    }

    public String getAdresa() {
        return adresa;
    }

    public String getNrTel() {
        return nrTel;
    }

    public Integer getSuma() {
        return suma;
    }

    public Donatie(int id, String nume, String adresa, String nrTel, Integer suma) {
        super(id);
        this.nume = nume;
        this.adresa = adresa;
        this.nrTel = nrTel;
        this.suma = suma;
    }

    public Donatie(String nume, String adresa, String nrTel, Integer suma) {
        super(0);
        this.nume = nume;
        this.adresa = adresa;
        this.nrTel = nrTel;
        this.suma = suma;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Donatie)) return false;
        Donatie donatie = (Donatie) o;
        return Objects.equals(getNume(), donatie.getNume()) &&
                Objects.equals(getAdresa(), donatie.getAdresa()) &&
                Objects.equals(getNrTel(), donatie.getNrTel()) &&
                Objects.equals(getSuma(), donatie.getSuma());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getNume(), getAdresa(), getNrTel(), getSuma());
    }
}
