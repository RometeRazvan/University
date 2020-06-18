package Utils;

import Models.Caritate;
import Models.Donatie;
import Models.User;
import Observer.Observable;

import java.io.Serializable;

public class Request implements Serializable {

    private int id;
    private String mesaj;
    private User user;
    private String userName, numeCaritate;
    private Donatie donatie;
    private Caritate caritate;
    private Observable observable;
    private String donationName;

    public String getDonationName() {
        return donationName;
    }

    public void setDonationName(String donationName) {
        this.donationName = donationName;
    }

    public String getUserName() {
        return userName;
    }

    public Request(String mesaj, String numeCaritate, Donatie donatie) {
        this.mesaj = mesaj;
        this.numeCaritate = numeCaritate;
        this.donatie = donatie;
    }

    public String getNumeCaritate() {
        return numeCaritate;
    }

    public void setNumeCaritate(String numeCaritate) {
        this.numeCaritate = numeCaritate;
    }

    public Observable getObservable() {
        return observable;
    }

    public void setObservable(Observable observable) {
        this.observable = observable;
    }

    public Request(String mesaj, String userName, Observable observable) {
        this.mesaj = mesaj;
        this.userName = userName;
        this.observable = observable;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

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
