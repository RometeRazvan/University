package Repository;

import Domain.DbAdress;
import Domain.Entity;
import Domain.User;
import Tools.PropertiesLoader;
import com.sun.org.apache.xpath.internal.operations.Bool;

import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;


import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class UserRepo<ID> implements IRepository<ID, User<ID>> {

    Connection conn;
    private static final Logger logger = LogManager.getLogger();

    public UserRepo() {
        try {
            conn = new DbAdress().getNewConnection();
        }
        catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    @Override
    public void save(User<ID> userCl) {
        Boolean val = false;
        try(Statement stmt = conn.createStatement()) {
            stmt.executeUpdate("INSERT INTO Users(nume, password) VALUES ('"+userCl.getName()+"','"+userCl.getPassword()+"')");
            val = true;
            logger.info("Adaugat user" + userCl.getName());
        }
        catch (Exception e) {
            System.out.println("Adaugare esuata !");
        }
        //System.out.println("User-ul " + userCl.getName() + " a fost adaugat !");
    }

    @Override
    public User<ID> get(ID id) {
        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT * FROM Users WHERE id = '"+id+"'");
            return new User<>((ID) String.format("%d",rs.getInt("id")), rs.getString("nume"), rs.getString("password"));
        }
        catch (Exception e) {
            System.out.println("Couldn't get user");
        }
        return null;
    }

    @Override
    public void delete(ID id) {
        try (Statement stmt = conn.createStatement()) {
            String name = this.get(id).getName();
            stmt.execute("Delete from Users where id = "+id+"");
            logger.info("Deleted user" + name);
        }
        catch (Exception e) {
            System.out.println("Couldn't delete user" + e.getMessage());
        }
    }

    @Override
    public void update(User<ID> idUser) {
        try (Statement stmt = conn.createStatement()) {
            stmt.execute("Update Users set nume ='"+idUser.getName()+"', password ='"+idUser.getPassword()+"' where id = '"+idUser.getId()+"' ");
            logger.info("Updated use " + idUser.getName());
        }
        catch (Exception e) {
            System.out.println("Couldn't update user");
        }
    }

    @Override
    public Integer getLg() {
        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("select count(id) as rowcount from Users");
            return rs.getInt("rowcount");
        }
        catch (Exception e) {
            System.out.println("Couldn't return length");
        }
        return null;
    }

    public String getIdByUaP(User<ID> userCl) {
        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT id FROM Users WHERE nume = '"+userCl.getName()+"' AND password = '"+userCl.getPassword()+"' ");
            return String.format("%s", rs.getString("id"));
        }
        catch (Exception e) {
            System.out.println("Couldn't get user");
        }
        return null;
    }


}
