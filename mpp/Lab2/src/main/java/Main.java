import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.sql.DataSource;
import java.sql.*;
import java.util.logging.LogManager;
import java.util.logging.Logger;

public class Main {

    public static void main(String[] args) throws NamingException, SQLException, NamingException, ClassNotFoundException {
        System.out.println("Hello World !!");
        Repository<String> repo = new Repository<>();
        Persoana<String> p = new Persoana<>(4,"Dan2","Rentea");
        Persoana<String> p2 = new Persoana<>(5,"Iulius2","Satmari");
        System.out.println(repo.findOne("1").getNume());

    }

}
