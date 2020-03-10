package Repository;

import Domain.Caritate;
import Domain.DbAdress;
import Domain.Entity;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;

public class CazuriRepo<ID> implements IRepository<ID, Caritate<ID>> {

    Connection conn;

    public CazuriRepo() {
        try {
            conn = new DbAdress().getNewConnection();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void save(Caritate<ID> caritate) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeUpdate("INSERT INTO CazuriCaritabile(name, suma) VALUES('"+caritate.getName()+"','"+caritate.getSuma()+"') ");
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public Caritate<ID> get(ID id) {
        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT * FROM CazuriCaritabile WHERE id = '"+id+"'");
            return new Caritate<>(rs.getString("name"), rs.getInt("suma"));
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
        return null;
    }

    @Override
    public void delete(ID id) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeQuery("Delete from CazuriCaritabile where id = "+id+"");
        }
        catch (Exception e) {
            System.out.println("Couldn't delete charitable case");
        }
    }

    @Override
    public void update(Caritate<ID> idCaritate) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeQuery("Update Donatii set nume ='"+idCaritate.getName()+"', suma='"+String.format("%s",idCaritate.getSuma())+"',  where id = '"+idCaritate.getId()+"' ");
        }
        catch (Exception e) {
            System.out.println("Couldn't update charitable case");
        }
    }

}
