package Repository;

import Domain.DbAdress;
import Domain.Entity;
import Domain.User;
import com.sun.org.apache.xpath.internal.operations.Bool;

import java.io.FileInputStream;
import java.io.IOException;
import java.sql.*;
import java.util.Properties;

public class UserRepo<ID> implements IRepository<ID, User<ID>> {

    Connection conn;

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
            stmt.executeUpdate("INSERT INTO Users(name, password) VALUES ('"+userCl.getName()+"','"+userCl.getPassword()+"')");
            val = true;
        }
        catch (Exception e) {
            System.out.println("Adaugare esuata !");
        }
        System.out.println("User-ul " + userCl.getName() + " a fost adaugat !");
    }

    @Override
    public User<ID> get(ID id) {
        try (Statement stmt = conn.createStatement()) {
            ResultSet rs = stmt.executeQuery("SELECT * FROM Users WHERE id = '"+id+"'");
            return new User<>((ID) String.format("%d",rs.getInt("id")), rs.getString("name"), rs.getString("password"));
        }
        catch (Exception e) {
            System.out.println("Couldn't get user");
        }
        return null;
    }

    @Override
    public void delete(ID id) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeQuery("Delete from Users where id = "+id+"");
        }
        catch (Exception e) {
            System.out.println("Couldn't delete user");
        }
    }

    @Override
    public void update(User<ID> idUser) {
        try (Statement stmt = conn.createStatement()) {
            stmt.executeQuery("Update Users set name ='"+idUser.getName()+"', password='"+idUser.getPassword()+"' where id = '"+idUser.getId()+"' ");
        }
        catch (Exception e) {
            System.out.println("Couldn't update user");
        }
    }


}
