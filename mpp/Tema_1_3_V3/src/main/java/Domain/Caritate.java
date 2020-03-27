package Domain;

import java.util.Objects;

public class Caritate extends Entity {

    private String nume;
    private Integer suma;

    public String getNume() {
        return nume;
    }

    public Integer getSuma() {
        return suma;
    }

    public Caritate(int id, String nume, Integer suma) {
        super(id);
        this.nume = nume;
        this.suma = suma;
    }

    public void setSuma(Integer suma) {
        this.suma = suma;
    }

    public Caritate(String nume, Integer suma) {
        super(0);
        this.nume = nume;
        this.suma = suma;
    }

    public Caritate(String nume) {
        super(0);
        this.nume = nume;
        this.suma = 0;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Caritate)) return false;
        Caritate caritate = (Caritate) o;
        return Objects.equals(getNume(), caritate.getNume()) &&
                Objects.equals(getSuma(), caritate.getSuma());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getNume(), getSuma());
    }
}
