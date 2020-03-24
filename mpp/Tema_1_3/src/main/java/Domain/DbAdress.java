package Domain;

import java.io.FileInputStream;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DbAdress {

    public DbAdress() {};

    public Connection getNewConnection() {
        Properties prop = new Properties();
        try {
            prop.load(new FileInputStream("C:\\Users\\Razvan-Laptop\\Desktop\\University\\mpp\\Tema_1_3\\src\\main\\resources\\db.properties"));
        }
        catch (IOException e) {
            System.out.println("Nu s-a putut incarca fisierul cu proprietati " + e.getMessage());
        }
        String url = prop.getProperty("jbdc.url");
        Connection con = null;
        try {
            con = DriverManager.getConnection("jdbc:sqlite:C:\\Users\\Razvan-Laptop\\Desktop\\University\\mpp\\Tema_1_3\\Baze de date\\IdentifierLab_1_3");
        }
        catch (SQLException e) {
            System.out.println("Nu s-a putut stabili conexiunea " + e.getMessage());
        }
        return con;
    }

}
