package Controllers;

import IService.IServiceUser;
import Models.User;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.sql.SQLException;

public class LogInController {
    private static final Logger logger = LogManager.getLogger();
    private MainAppController client;
    private IServiceUser su;
    private Stage newStage;

    private Stage stage;

    @FXML TextField userField;
    @FXML PasswordField passwordField;
    @FXML Pane pane;
    @FXML Label info;

    public void setStage(Stage s, Stage newStage) {
        this.newStage = newStage;
        this.stage = s;
    }

    public void setData(IServiceUser serviceUser,MainAppController observer) {
        this.su = serviceUser;
        this.client = observer;
    }

    @FXML
    private void logIn() {
        try {
            String name = userField.getText();
            String password = passwordField.getText();

            User user = su.findByName(name, client);
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
        newStage.close();
        su.disconnect();
        stage.close();
    }

    private void maiApp(String name) {
        try {

            newStage.show();
            logger.info("Utilizatorul " + name + " s-a conectat !");
        }
        catch (Exception e) {
            logger.error(e);
        }
    }

}
