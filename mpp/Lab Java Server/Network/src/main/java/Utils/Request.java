package Utils;

import Models.Caritate;
import Models.Donatie;
import Models.User;

import java.io.Serializable;

public class Request implements Serializable {

    private int id;
    private String mesaj;
    private User user;
    private String userName;
    private Donatie donatie;
    private Caritate caritate;

    public Request(String mesaj, String userName) {
        this.mesaj = mesaj;
        this.userName = userName;
    }

    public Request(String mesaj, User user) {
        this.mesaj = mesaj;
        this.user = user;
    }

    public Request(String mesaj) {
        this.mesaj = mesaj;
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

    public User getUser() {
        return user;
    }

    public void setUser(User user) {
        this.user = user;
    }

    public Donatie getDonatie() {
        return donatie;
    }

    public void setDonatie(Donatie donatie) {
        this.donatie = donatie;
    }

    public Caritate getCaritate() {
        return caritate;
    }

    public void setCaritate(Caritate caritate) {
        this.caritate = caritate;
    }
}
