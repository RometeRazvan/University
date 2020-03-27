package Controllers;

import Domain.User;
import Service.ServiceCaritate;
import Service.ServiceDonatie;
import Service.ServiceUser;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Paint;
import javafx.stage.Modality;
import javafx.stage.Stage;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class LogInController {
    private static final Logger logger = LogManager.getLogger();

    private ServiceUser su;

    private Stage stage;

    @FXML TextField userField;
    @FXML PasswordField passwordField;
    @FXML Pane pane;
    @FXML Label info;

    public void setStage(Stage s) {
        this.stage = s;
    }

    public void setData() {
        this.su = new ServiceUser();
    }

    @FXML
    private void logIn() {
        try {
            String name = userField.getText();
            String password = passwordField.getText();
            User user = su.findByName(name);
            User user2 = new User(name, password);

            if(user.equals(user2)) {
                this.stage.close();
                maiApp(name);
            }
            else {
                badLogIn();
            }
        }
        catch (Exception e) {
            logger.error(e);
            badLogIn();
        }

    }

    @FXML
    private void originalPane() {
        String color = "ffffcc";
        pane.setStyle("-fx-background-color: #" + color);
    }

    private void badLogIn() {
        userField.clear();
        passwordField.clear();
        String color = "ff6666";
        pane.setStyle("-fx-background-color: #" + color);
    }

    @FXML
    private void exit() {
        this.stage.close();
    }

    private void maiApp(String name) {
        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(getClass().getClassLoader().getResource("FXMLs/mainApp.fxml"));
            AnchorPane root = loader.load();

            Stage mainAppStage = new Stage();
            mainAppStage.setTitle("Meniu Donatii");
            mainAppStage.initModality(Modality.WINDOW_MODAL);

            Scene scene = new Scene(root);
            mainAppStage.setScene(scene);
            MainAppController mac = loader.getController();
            mac.setData();
            mac.setStage(mainAppStage);
            //su.getConnection().close();
            mainAppStage.show();
            logger.info("Utilizatorul " + name + " s-a conectat !");
        }
        catch (Exception e) {
            logger.error(e);
        }
    }

}
