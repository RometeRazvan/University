package Controllers;

import Models.Caritate;
import Models.User;
import Services.IObserver;
import Services.IService;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.Pane;
import javafx.stage.Modality;
import javafx.stage.Stage;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.Serializable;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.List;

public class LogInController extends UnicastRemoteObject implements Serializable, IObserver {
    private static final Logger logger = LogManager.getLogger();
    private MainAppController client = new MainAppController();
    private IService service;

    private Stage stage;

    @FXML TextField userField;
    @FXML PasswordField passwordField;
    @FXML Pane pane;
    @FXML Label info;

    public LogInController() throws RemoteException {}

    public void setStage(Stage s) {
        this.stage = s;
    }

    public void setData(IService service) {
        this.service = service;
    }

    @FXML
    private void logIn() {
        try {
            String name = userField.getText();
            String password = passwordField.getText();

            User user = service.findByName(name);
            User user2 = new User(name, password);

            if(user.equals(user2)) {
                service.addClient(this);
                this.stage.close();
                showMainApp();
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
        stage.close();
    }

    private void showMainApp() {
        try {
            FXMLLoader loader = new FXMLLoader();

            loader.setLocation(getClass().getResource("/FXMLS/mainApp.fxml"));
            AnchorPane root = loader.load();

            Stage mainAppStage = new Stage();
            mainAppStage.setTitle("App");
            mainAppStage.initModality(Modality.WINDOW_MODAL);

            Scene scene = new Scene(root);
            mainAppStage.setScene(scene);

            client = loader.getController();
            client.setData(service);

            mainAppStage.show();
        }
        catch (Exception ex) {
            logger.error(ex.getMessage());
        }
    }

    @Override
    public void notify(List<Caritate> list) {

    }
}
