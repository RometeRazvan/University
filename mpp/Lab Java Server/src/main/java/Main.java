import Controllers.LogInController;
import Controllers.MainAppController;
import IService.IServiceCaritate;
import IService.IServiceDonatii;
import IService.IServiceUser;
import Models.User;
import Proxy.ProxyServiceCaritate;
import Proxy.ProxyServiceUser;
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

    public static void main(String[] args) {launch(args);}

    public void start(Stage primaryStage) throws IOException {

        FXMLLoader loader2 = new FXMLLoader();
        loader2.setLocation(getClass().getClassLoader().getResource("FXMLs/mainApp.fxml"));
        AnchorPane root2 = loader2.load();

        Stage newStage = new Stage();
        newStage.setTitle("Meniu Donatii");
        newStage.initModality(Modality.WINDOW_MODAL);

        Scene scene = new Scene(root2);
        newStage.setScene(scene);
        MainAppController mac = loader2.getController();
        mac.setData();
        mac.setStage(newStage);

        MainAppController mainAppController = loader2.getController();

        //User user = new ProxyServiceUser().findByName("Romete", mainAppController);

        //System.out.println(user.getNume());

    }
}