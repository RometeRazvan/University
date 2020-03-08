package Repository;

import Domain.DbAdress;
import Domain.Donatie;

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
}
