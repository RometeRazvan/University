package Domain;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public class DbAdress {

    public DbAdress() {};

    public Connection getNewConnection() {
        Properties prop = new Properties();
        String fileName = "db.properties";
        InputStream inputStream;

        try {
            inputStream = getClass().getClassLoader().getResourceAsStream(fileName);
            prop.load(inputStream);
        }
        catch (IOException e) {
            System.out.println("Nu s-a putut citit fisierul db.properties" + e.getMessage());
        }
        String url = prop.getProperty("jbdc.url");
        Connection con = null;
        try {
            con = DriverManager.getConnection("jdbc:sqlite:C:\\Users\\Razvan-Laptop\\Desktop\\University\\mpp\\Tema_1_3_V2\\Baze de date\\IdentifierLab_1_3");
        }
        catch (SQLException e) {
            System.out.println("Nu s-a putut stabili conexiunea " + e.getMessage());
        }
        return con;
    }

}
