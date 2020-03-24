import Domain.User;
import Repository.CazuriRepo;
import Repository.DonatieRepo;
import Repository.UserRepo;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
//import org.springframework.context.ApplicationContext;
//import org.springframework.context.support.ClassPathXmlApplicationContext;


public class Main {

    //private static final Logger logger = LogManager.getLogger();

    public static void main(String[] args) {
        System.out.println("Hello World !");
        UserRepo<String> ur = new UserRepo<>();
        DonatieRepo<String> dr = new DonatieRepo<>();
        CazuriRepo<String> cr = new CazuriRepo<>();
        //System.out.println(ur.getLg());

        /*User<String> u1 = new User<>("Romete", "Razvan");
        System.out.println(ur.getIdByUaP(u1));
        User<String> u2 = ur.get(ur.getIdByUaP(u1));
        System.out.println(u2.getName());*/

       /* ApplicationContext factory = new
                ClassPathXmlApplicationContext("UserS.xml");
        User<String> u1 = factory.getBean(User.class);
        System.out.println(u1.getName());*/
    }
}
