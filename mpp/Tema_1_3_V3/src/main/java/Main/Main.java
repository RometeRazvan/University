package Main;

import Controllers.LogInController;
import Controllers.MainAppController;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;
import java.sql.Connection;


public class Main extends Application {

    private static  final Logger logger = LogManager.getLogger();

    public static void main(String[] args) {launch(args);}

    public void start(Stage primaryStage) throws IOException {

        Parent root = null;


        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(getClass().getClassLoader().getResource("FXMLs/logIn.fxml"));
            root = loader.load();
            LogInController logIn = loader.getController();

            logIn.setData();
            logIn.setStage(primaryStage);

            Scene scene = new Scene(root);

            primaryStage.setTitle("LogIn");
            primaryStage.setScene(scene);
            primaryStage.setResizable(false);
            primaryStage.show();

            logger.info("Aplicatia a pornit !");

            /*FXMLLoader loader = new FXMLLoader();
            loader.setLocation(getClass().getClassLoader().getResource("FXMLs/mainApp.fxml"));
            root = loader.load();
            MainAppController mac = loader.getController();

            mac.setData();
            mac.setStage(primaryStage);

            Scene scene = new Scene(root);

            primaryStage.setTitle("Main");
            primaryStage.setScene(scene);
            primaryStage.setResizable(false);
            primaryStage.show();*/


        }
        catch (Exception e) {
            logger.error(e);
        }
    }

}
