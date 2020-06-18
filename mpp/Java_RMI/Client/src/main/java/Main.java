import Controllers.LogInController;
import Services.IService;
import javafx.application.Application;
import javafx.fxml.*;
import javafx.scene.*;
import javafx.stage.Stage;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Main extends Application {

    private static final Logger logger = LogManager.getLogger();

    public static void main(String[] args) {
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {

        ApplicationContext factory = new ClassPathXmlApplicationContext("spring-client.xml");

        IService service = (IService) factory.getBean("chatService");

        Parent root = null;

        try {
            FXMLLoader loader = new FXMLLoader(Main.class.getResource("/FXMLS/logIn.fxml"));
            root = loader.load();

            LogInController logInController = loader.getController();
            logInController.setData(service);
            logInController.setStage(primaryStage);

            Scene scene = new Scene(root);
            primaryStage.setScene(scene);
            primaryStage.show();
        }
        catch (Exception ex) {
            logger.error(ex.getMessage());
        }

    }
}