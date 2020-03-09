import Domain.User;
import Repository.CazuriRepo;
import Repository.DonatieRepo;
import Repository.UserRepo;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;


public class Main {

    private static final Logger logger = LogManager.getLogger();

    public static void main(String[] args) {
        System.out.println("Hello World !");
        //UserRepo<String> ur = new UserRepo<>();
       // DonatieRepo<String> dr = new DonatieRepo<>();
        CazuriRepo<String> cr = new CazuriRepo<>();
        logger.info("Repo created");
        System.out.println(cr.get("3").getSuma());
        logger.info("Executed repo.get(\"3\")");
    }
}
