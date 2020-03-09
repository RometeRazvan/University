package Domain;

import Domain.Entity;

public class Caritate<ID> implements Entity<ID> {

    private ID id;
    private String name;
    private Integer suma;

    public Caritate(ID id, String name, Integer suma) {
        this.id = id;
        this.name = name;
        this.suma = suma;
    }

    public Caritate(String name, Integer suma) {
        this.name = name;
        this.suma = suma;
    }

    @Override
    public ID getId() {
        return id;
    }

    public void setId(ID id) {
        this.id = id;
    }

    public String getname() {
        return name;
    }

    public void setname(String name) {
        this.name = name;
    }

    public Integer getSuma() {
        return suma;
    }

    public void setSuma(Integer suma) {
        this.suma = suma;
    }
}
