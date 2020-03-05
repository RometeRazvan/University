public class Persoana<ID> {

    ID id;
    Integer key;
    String nume,prenume;

    public Persoana(String nume, String prenume) {
        this.nume = nume;
        this.prenume = prenume;
    }

    public Persoana(Integer key, String nume, String prenume) {
        this.key = key;
        this.nume = nume;
        this.prenume = prenume;
    }

    public ID getId() {
        return id;
    }

    public Integer getKey() {
        return key;
    }

    public String getNume() {
        return nume;
    }

    public String getPrenume() {
        return prenume;
    }

    public void setId(ID id) {
        this.id = id;
    }

    public void setKey(Integer key) {
        this.key = key;
    }

    public void setNume(String nume) {
        this.nume = nume;
    }

    public void setPrenume(String prenume) {
        this.prenume = prenume;
    }
}
