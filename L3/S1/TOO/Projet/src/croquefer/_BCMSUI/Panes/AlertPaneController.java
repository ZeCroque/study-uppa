package croquefer._BCMSUI.Panes;


import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Utilities.NumberTextField;
import croquefer._BCMSUI.Utilities.Service;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TitledPane;
import javafx.scene.layout.VBox;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;

public class AlertPaneController implements Initializable
{
	@FXML private TitledPane alertPane;
	@FXML private NumberTextField countField;
	@FXML private Label availableVehiclesCount;
	@FXML private ChoiceBox<String> alertChoiceBox;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		alertChoiceBox.setItems(FXCollections.observableArrayList("Incendie", "Accident de la route", "Autre"));

		try 
		{
			
			if(BCMSUI.currentService.equals(Service.Pompier))
			{
				availableVehiclesCount.setText(""+BCMSUI.bCMS.get_fire_trucks().size());
				alertPane.getContent().setStyle("-fx-background-color: red;");
			}
			else
			{
				availableVehiclesCount.setText(""+BCMSUI.bCMS.get_police_vehicles().size());
				alertPane.getContent().setStyle("-fx-background-color: blue;");
			}
			alertPane.setText(BCMSUI.currentService+" - Déclaration d'alerte");
		}
		catch (SQLException e) 
		{
			e.printStackTrace();
		}
		
	}
	@SuppressWarnings("unchecked")
	public void validateButtonController(ActionEvent event) 
	{
		
		try 
		{				
			String content = countField.getText();
			Scene scene = ((Node) event.getTarget()).getScene();

			if(content!=null && !content.isEmpty() && Integer.parseInt(content)<=Integer.parseInt(availableVehiclesCount.getText()) && Integer.parseInt(content)!=0)
			{
				//Initializing VehiclesPane
				TitledPane vehiclesPane = (TitledPane) scene.lookup("#vehiclesPane");
				VBox vehiclesPaneContent = (VBox) vehiclesPane.getContent();
				VBox vehiclesManager = (VBox)FXMLLoader.load(getClass().getResource("../Utilities/VehiclesManager.fxml"));
				vehiclesPaneContent.getChildren().add(0,vehiclesManager);
				
				ObservableList<String> list;		
				if(BCMSUI.currentService.equals(Service.Pompier))
				{
					BCMSUI.bCMS.state_fire_truck_number(Integer.parseInt(content));
					vehiclesPane.getContent().setStyle("-fx-background-color: red;");
					list=FXCollections.observableArrayList(BCMSUI.bCMS.get_fire_trucks_unused());
				}
				else
				{
					BCMSUI.bCMS.state_police_vehicle_number(Integer.parseInt(content));
					vehiclesPane.getContent().setStyle("-fx-background-color: blue;");
					list=FXCollections.observableArrayList(BCMSUI.bCMS.get_police_vehicles_unused());
				}
				
				//Initializing VehiclesController
				ListView<String> idleList = (ListView<String>) scene.lookup("#idleList");						
				idleList.setItems(list);
				idleList.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
				Label countLabel = (Label) scene.lookup("#countLabel");	
				countLabel.setText(""+Integer.parseInt(content));
				
				//Showing the result
				vehiclesPane.toFront();
				
				
			}
			else
			{
				Alert alert = new Alert(AlertType.WARNING);
				alert.setTitle("Avertissement");
				alert.setHeaderText("Vous avez saisi un nombre incorrect ou supérieur au nombre d'unités disponibles.");
				alert.showAndWait();
			}					
		} 
		catch (Statechart_exception | NumberFormatException | IOException | SQLException e) 
		{
			e.printStackTrace();
		}
	}
}
