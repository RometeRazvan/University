package Controllers;

import IService.IServiceCaritate;
import IService.IServiceDonatii;
import Models.Caritate;
import Models.Donatie;
import Observer.Observable;
import Proxy.ProxyServiceCaritate;
import Proxy.ProxySeviceDonatii;
import Service.ServiceCaritate;
import Service.ServiceDonatie;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;


public class MainAppController implements Observable {

    private static final Logger logger = LogManager.getLogger();

    private IServiceDonatii sd;
    private IServiceCaritate sc;

    private Stage stage;

    @FXML private Pane pane;
    @FXML private TextField textNume, textAdresa, textNrTel, textSuma, textSearch;
    @FXML private Label labelAdauga;
    @FXML private TableView<Caritate> tableCazuri = new TableView<>();
    @FXML private TableView<Donatie> tableDonatii = new TableView<>();

    public void setData(IServiceDonatii sd, IServiceCaritate sc) {
        this.sd = sd;
        this.sc = sc;
        loadTables();
    }

    private void loadTables() {
        TableColumn<Caritate, String> numeCaz = new TableColumn("Nume");
        TableColumn<Caritate, Integer> suma = new TableColumn("Suma");

        numeCaz.setCellValueFactory(new PropertyValueFactory<Caritate, String>("nume"));
        suma.setCellValueFactory(new PropertyValueFactory<Caritate, Integer>("suma"));

        tableCazuri.getColumns().addAll(numeCaz, suma);


        TableColumn<Donatie, String> columnNume = new TableColumn<>("Nume");
        TableColumn<Donatie, String> columnAdresa = new TableColumn<>("Adresa");
        TableColumn<Donatie, String>  columnNrTel = new TableColumn<>("Nr. Tel.");
        TableColumn<Donatie, Integer>  columnSuma = new TableColumn<>("Suma");

        columnNume.setCellValueFactory(new PropertyValueFactory<Donatie, String>("nume"));
        columnAdresa.setCellValueFactory(new PropertyValueFactory<Donatie, String>("adresa"));
        columnNrTel.setCellValueFactory(new PropertyValueFactory<Donatie, String>("nrTel"));
        columnSuma.setCellValueFactory(new PropertyValueFactory<Donatie, Integer>("suma"));

        columnNume.prefWidthProperty().bind(tableDonatii.widthProperty().multiply(0.4));

        tableDonatii.getColumns().addAll(columnNume, columnAdresa, columnNrTel);

        //tableCazuri.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);

        loadFromDatabase();

    }

    private void loadFromDatabase() {
        tableCazuri.getItems().clear();

        List<Caritate> list = (List<Caritate>) sc.findAll();

        for(Caritate c : list) {
            tableCazuri.getItems().add(c);
        }
    }

    private void loadFromDatabase2(List<Caritate> list) {
        tableCazuri.getItems().clear();

        for(Caritate c : list) {
            tableCazuri.getItems().add(c);
        }
    }

    public void setStage(Stage stage) {
        this.stage = stage;
    }

    @FXML  public void logOut() {
        try {
            /*FXMLLoader loader = new FXMLLoader();
            loader.setLocation(getClass().getClassLoader().getResource("FXMLs/logIn.fxml"));
            AnchorPane root = loader.load();

            Stage logInStage = new Stage();
            logInStage.setTitle("Log In");
            logInStage.initModality(Modality.WINDOW_MODAL);

            Scene scene = new Scene(root);
            logInStage.setScene(scene);
            LogInController lc = loader.getController();
            lc.setData(new ProxyServiceUser());
            lc.setStage(logInStage);
            logInStage.show();

            sd.getConnection().close();
            sc.getConnection().close();
            stage.close();*/
        }
        catch (Exception e) {
            logger.error(e);
        }
    }

    @FXML public void addDonatie() {
        try {
            labelAdauga.setText("");

            String nume = textNume.getText();
            String adresa = textAdresa.getText();
            String nrTel = textNrTel.getText();
            Integer suma = Integer.parseInt(textSuma.getText());

            Caritate caritate = tableCazuri.getSelectionModel().getSelectedItem();

            sd.save(nume, adresa, nrTel, suma, caritate.getNume());

            //loadFromDatabase();

            clearFromAdd();

        }
        catch (Exception e) {
            logger.error(e);
            dateInvalideAdaugare();
        }
    }

    @FXML private void clearFromAdd() {
        textNume.clear();
        textAdresa.clear();
        textNrTel.clear();
        textSuma.clear();
        tableCazuri.getSelectionModel().clearSelection();
        labelAdauga.setText("");
        tableDonatii.getSelectionModel().clearSelection();
        textSearch.clear();
    }

    private void dateInvalideAdaugare() {
        labelAdauga.setTextFill(Color.web("#ff3300"));
        labelAdauga.setText("DATE INVALIDE !!!");
    }

    @FXML private void onSearch() {
        try {
            String searched = textSearch.getText();

            ArrayList<Donatie> al = (ArrayList<Donatie>) sd.searchByName(searched);

            tableDonatii.getItems().clear();

            for(Donatie d : al) {
                tableDonatii.getItems().add(d);
            }
        }
        catch (Exception e) {
            logger.error(e);
        }
    }

    @FXML private void fillDonatiiFromTable() {
        try {
            if(tableDonatii.getSelectionModel().getSelectedItem() != null) {
                Donatie donatie = tableDonatii.getSelectionModel().getSelectedItem();

                textNume.setText(donatie.getNume());
                textAdresa.setText(donatie.getAdresa());
                textNrTel.setText(donatie.getNrTel());
            }
        }
        catch (Exception e) {
            logger.error(e);
        }
    }

    @Override
    public void getNotified(List<Caritate> list) {
        loadFromDatabase2(list);
    }
}
