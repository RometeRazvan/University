package Repository;

import Domain.User;
import Tools.DBAdd;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class UsersRepo implements IUsersRepo<User>{
    private Connection conn;
    private static final Logger logger = LogManager.getLogger();

    public UsersRepo() { conn = new DBAdd().getNewConnection();}

    Connection getConnection() {return conn;}

    @Override
    public User findByName(String nume) {
        try {
            if(conn.isClosed())
                return null;
        } catch (Exception e) {
            logger.error(e);
            return null;
        }

        String stmtStr= "SELECT * FROM USERS WHERE nume is ?";
        try(PreparedStatement ppstm = conn.prepareStatement(stmtStr)) {
            ppstm.setString(1, nume);
            ResultSet rs = ppstm.executeQuery();
            if(rs.next())
                return new User(rs.getInt("id"), rs.getString("nume"), rs.getString("password"));
            else {
                logger.info("Nu s-a gasit user pt numele " + nume);
            }
        }
        catch (Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public User findOne(int id) {
        try {
            if(conn.isClosed())
                return null;
        } catch (Exception e) {
            logger.error(e);
            return null;
        }

        String stmtStr= "SELECT * FROM USERS WHERE id is ?";
        try(PreparedStatement ppstm = conn.prepareStatement(stmtStr)) {
            ppstm.setInt(1,id);
            ResultSet rs = ppstm.executeQuery();
            if(rs.next())
                return new User(rs.getInt("id"), rs.getString("nume"), rs.getString("password"));
            else {
                logger.info("Nu s-a gasit user pt id-ul " + Integer.toString(id));
            }
        }
        catch (Exception e) {
            logger.error(e);
        }

        return null;
    }

    @Override
    public User save(User entity) {
        try {
            if(conn.isClosed())
                return null;
        } catch (Exception e) {
            logger.error(e);
            return null;
        }

        String stmtStr = "Insert into Users(nume, password) Values(?,?)";

        if(this.findByName(entity.getNume()) == null) {
            try(PreparedStatement ppstmt = conn.prepareStatement(stmtStr)) {
                ppstmt.setString(1, entity.getNume());
                ppstmt.setString(2, entity.getPassword());
                ppstmt.executeUpdate();
                return this.findByName(entity.getNume());
            }
            catch (Exception e) {
                logger.error(e);
            }
        }
        else logger.info("User-ul " + entity.getNume() + " este deja in lista si nu poate fi adaugat");

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

        String stmtStr = "DELETE from Users";

        try (PreparedStatement pstmt = conn.prepareStatement(stmtStr)) {
            pstmt.executeUpdate();
        } catch (SQLException ex) {
            logger.error(ex);
        }
    }
}
