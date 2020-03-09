import Domain.User;
import Repository.CazuriRepo;
import Repository.DonatieRepo;
import Repository.UserRepo;
import com.sun.org.slf4j.internal.Logger;
import com.sun.org.slf4j.internal.LoggerFactory;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World !");
        UserRepo<String> ur = new UserRepo<>();
        DonatieRepo<String> dr = new DonatieRepo<>();
        CazuriRepo<String> cr = new CazuriRepo<>();
        System.out.println(cr.get("3").getSuma());
    }
}
