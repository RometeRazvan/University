import java.net.ConnectException;
import java.sql.*;
import java.util.logging.LogManager;
import java.util.logging.Logger;

public class Repository<ID> {

    private Connection conn;

    public Repository() {
        try {
            this.conn = DriverManager.getConnection("jdbc:sqlite:C:\\Users\\Razvan-Laptop\\Desktop\\An2\\mpp\\BazaLab2");
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    public Persoana findOne(String id) {
        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT * from Tabel where idPersoana = '"+id+"'");
            return new Persoana(rs.getInt("idPersoana"),rs.getString("nume"), rs.getString("prenume"));
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
        return null;
    }

    public void save(Persoana p) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeUpdate("INSERT into Tabel(nume,prenume) VALUES ('"+p.getNume()+"','"+p.getPrenume()+"')");
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
    }

    public void delete(ID id) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeUpdate("delete from Tabel WHERE idPersoana = '"+id+"'");
        } catch (SQLException ex) {
            System.out.println(ex.getMessage());
        }
    }
}
