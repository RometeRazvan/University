package Repository;


import IRepository.ICazuriCaritabileRepo;
import Models.Caritate;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import Tools.DBAdd;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class CazuriCaritabileRepo implements ICazuriCaritabileRepo {

    private Connection conn;
    private static final Logger logger = LogManager.getLogger();

    public Connection getConnection() {return conn;}

    public CazuriCaritabileRepo() {conn = new DBAdd().getNewConnection();}

    @Override
    public Caritate findByName(String nume) {
        try {
            if(conn.isClosed())
                return null;
        }
        catch (Exception e) {
            logger.error(e);
            return null;
        }

        String stmt = "Select * from CazuriCaritabile where nume is ?";

        try(PreparedStatement ppstmt = conn.prepareStatement(stmt)) {
            ppstmt.setString(1, nume);
            ResultSet rs = ppstmt.executeQuery();
            if(rs.next())
                return new Caritate(rs.getInt("id"), rs.getString("nume"), rs.getInt("suma"));
            else logger.error("Nu s-a gasit cazul caritabul cu numele " + nume);
        }
        catch (Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public Iterable<Caritate> findAll() {
        try {
            if(conn.isClosed())
                return null;
        }
        catch (Exception e) {
            logger.error(e);
            return null;
        }

        String stmtStr = "SELECT * FROM CazuriCaritabile";

        try(PreparedStatement ppStmt = conn.prepareStatement(stmtStr)) {
            ResultSet rs = ppStmt.executeQuery();
            ArrayList<Caritate> ic = new ArrayList<>();
            while(rs.next()) {
                Caritate c = new Caritate(rs.getInt("id"), rs.getString("nume"), rs.getInt("suma"));
                ic.add(c);
            }
            return ic;
        }
        catch (Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public void addSuma(String nume, Integer suma) {
        try {
            if(conn.isClosed())
                return;
        }
        catch (Exception e) {
            logger.error(e);
            return;
        }

        try {

            Caritate caritate = findByName(nume);
            caritate.setSuma(caritate.getSuma() + suma);

            String stmt = "Update CazuriCaritabile set suma = ? where nume = ?";

            PreparedStatement ppstmt = conn.prepareStatement(stmt);
            ppstmt.setInt(1, caritate.getSuma());
            ppstmt.setString(2, caritate.getNume());

            ppstmt.executeUpdate();
        }
        catch (Exception e) {
            logger.error(e);
        }
    }

    @Override
    public Caritate findOne(int id) {
        try {
            if(conn.isClosed())
                return null;
        }
        catch (Exception e) {
            logger.error(e);
            return null;
        }

        String stmt = "Select * from CazuriCaritabile where id is ?";

        try(PreparedStatement ppstmt = conn.prepareStatement(stmt)) {
            ppstmt.setInt(1, id);
            ResultSet rs = ppstmt.executeQuery();
            if(rs.next())
                return new Caritate(rs.getInt("id"), rs.getString("nume"), rs.getInt("suma"));
            else logger.error("Nu s-a gasit cazul caritabil cu id-ul " + id);
        }
        catch (Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public Caritate save(Caritate entity) {
        try {
            if(conn.isClosed())
                return null;
        }
        catch (Exception e) {
            logger.error(e);
            return null;
        }

        String stmt = "Insert into Cazuricaritabile(nume, suma) Values(?, ?)";

        if(findByName(entity.getNume()) == null) {
            try(PreparedStatement ppstmt = conn.prepareStatement(stmt)) {
                ppstmt.setString(1, entity.getNume());
                ppstmt.setInt(2, entity.getSuma());
                ppstmt.executeUpdate();
                return findByName(entity.getNume());
            }
            catch (Exception e) {
                logger.error(e);
            }
        }

        return null;
    }

    @Override
    public void clear() {
        try {
            if(conn.isClosed())
                return;
        }
        catch(Exception e) {
            logger.error(e);
            return;
        }

        String stmt = "DELETE from CazuriCaritabile";
        try (PreparedStatement pstmt = conn.prepareStatement(stmt)) {
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            logger.error(ex);
        }
    }
}
