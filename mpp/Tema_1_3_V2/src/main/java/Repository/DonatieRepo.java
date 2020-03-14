package Repository;

import Domain.DbAdress;
import Domain.Donatie;
import Domain.Entity;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.concurrent.ExecutionException;

public class DonatieRepo<ID> implements IRepository<ID, Donatie<ID>> {

    Connection conn;

    public DonatieRepo() {
        try {
            conn = new DbAdress().getNewConnection();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void save(Donatie<ID> donatie) {
        Boolean val = false;
        try(Statement stmt = conn.createStatement()) {
            stmt.executeUpdate("INSERT INTO Donatii(nume, adresa, nrTel, suma) VALUES ('"+donatie.getName()+"','"+donatie.getAdresa()+"','"+donatie.getNrTel()+"','"+donatie.getSuma()+"')");
            val = true;
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
        if(val) System.out.println("Donatia din partea lui " + donatie.getName() + " a fost adaugata");
    }

    @Override
    public Donatie<ID> get(ID id) {
        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT * FROM Donatii WHERE id = '"+id+"'");
            return new Donatie<>(rs.getString("nume"),rs.getString("adresa"), rs.getString("nrTel"), rs.getInt("suma"));
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return null;
    }

    @Override
    public void delete(ID id) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeQuery("Delete from Donatii where id = "+id+"");
        }
        catch (Exception e) {
            System.out.println("Couldn't delete donatio");
        }
    }

    @Override
    public void update(Donatie<ID> idDonatie) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeQuery("Update Donatii set nume ='"+idDonatie.getName()+"', adresa='"+idDonatie.getAdresa()+"', nrTel='"+idDonatie.getNrTel()+"' where id = '"+idDonatie.getId()+"' ");
        }
        catch (Exception e) {
            System.out.println("Couldn't update donation");
        }
    }

    @Override
    public Integer getLg() {
        return null;
    }

}
