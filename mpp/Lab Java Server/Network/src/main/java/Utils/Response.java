package Utils;

import Models.Caritate;
import Models.Donatie;
import Models.User;

import java.io.Serializable;

public class Response implements Serializable {

    private int id;
    private String mesaj;
    private boolean val;
    private Iterable<Caritate> listCaritate;
    private Iterable<Donatie> listDonatie;
    private User user;

    public Response(String mesaj, Iterable<Caritate> listCaritate) {
        this.mesaj = mesaj;
        this.listCaritate = listCaritate;
    }

    public Response(String mesaj, User user) {
        this.mesaj = mesaj;
        this.user = user;
    }

    public Response(String mesaj) {
        this.mesaj = mesaj;
    }

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getMesaj() {
        return mesaj;
    }

    public void setMesaj(String mesaj) {
        this.mesaj = mesaj;
    }

    public boolean isVal() {
        return val;
    }

    public void setVal(boolean val) {
        this.val = val;
    }

    public Iterable<Caritate> getListCaritate() {
        return listCaritate;
    }

    public void setListCaritate(Iterable<Caritate> listCaritate) {
        this.listCaritate = listCaritate;
    }

    public Iterable<Donatie> getListDonatie() {
        return listDonatie;
    }

    public void setListDonatie(Iterable<Donatie> listDonatie) {
        this.listDonatie = listDonatie;
    }
}
