import Controllers.LogInController;
import Controllers.MainAppController;
import IService.IServiceCaritate;
import IService.IServiceDonatii;
import IService.IServiceUser;
import Models.User;
import Proxy.ProxyServiceCaritate;
import Proxy.ProxyServiceUser;
import Proxy.ProxySeviceDonatii;
import Proxy.ResponseReader;
import Service.ServiceDonatie;
import Service.ServiceUser;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.stage.Modality;
import javafx.stage.Stage;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class Main extends Application {

    private IServiceCaritate serviceCaritate;
    private IServiceDonatii serviceDonatii;
    private IServiceUser serviceUser;
    private ResponseReader responseReader;

    private Socket connection;
    private ObjectInputStream inputStream;
    private ObjectOutputStream outputStream;

    private static int defaultPort = 55555;
    private static String defaultServer = "localhost";

    private static  final Logger logger = LogManager.getLogger();

    private void setData() {
        responseReader = new ResponseReader(inputStream, outputStream, connection);
        responseReader.startReader();

        serviceCaritate = new ProxyServiceCaritate(inputStream, outputStream, connection, responseReader);
        serviceDonatii = new ProxySeviceDonatii(inputStream, outputStream, connection, responseReader);
        serviceUser = new ProxyServiceUser(inputStream, outputStream, connection, responseReader);

        responseReader.setServiceUser(serviceUser);
    }

    public static void main(String[] args) {launch(args);}

    public void start(Stage primaryStage) throws IOException {

        connection = new Socket(defaultServer, defaultPort);

        try {
            outputStream = new ObjectOutputStream(connection.getOutputStream());
            outputStream.flush();

            inputStream = new ObjectInputStream(connection.getInputStream());
        }
        catch (IOException ex) {
            ex.printStackTrace();
        }

        Parent root = null;

        setData();

        try {

            FXMLLoader loader2 = new FXMLLoader();
            loader2.setLocation(getClass().getClassLoader().getResource("FXMLs/mainApp.fxml"));
            AnchorPane root2 = loader2.load();

            Stage newStage = new Stage();
            newStage.setTitle("Meniu Donatii");
            newStage.initModality(Modality.WINDOW_MODAL);

            Scene scene = new Scene(root2);
            newStage.setScene(scene);
            MainAppController mac = loader2.getController();

            mac.setData(serviceDonatii, serviceCaritate);
            mac.setStage(newStage);

            MainAppController mainAppController = loader2.getController();

            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(getClass().getClassLoader().getResource("FXMLS/logIn.fxml"));
            root = loader.load();
            LogInController logIn = loader.getController();

            logIn.setData(serviceUser, mainAppController);
            logIn.setStage(primaryStage, newStage);;

            Scene scene2 = new Scene(root);

            primaryStage.setTitle("LogIn");
            primaryStage.setScene(scene2);
            primaryStage.setResizable(false);
            primaryStage.show();

            logger.info("Aplicatia a pornit !");


        }
        catch (Exception e) {
            logger.error(e);
        }
    }

}