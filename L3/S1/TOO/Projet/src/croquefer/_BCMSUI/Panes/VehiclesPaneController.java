package croquefer._BCMSUI.Panes;

import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Utilities.Service;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TitledPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.control.Alert.AlertType;

public class VehiclesPaneController implements Initializable
{	
	@FXML private TitledPane vehiclesPane;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		vehiclesPane.setText(BCMSUI.currentService+" - Gestion des véhicules");	
	}
	
	@SuppressWarnings("unchecked")
	public void validateButtonController(ActionEvent event)
	{
		VBox content=(VBox) vehiclesPane.getContent();
		VBox vehiclesManager=(VBox) content.getChildren().get(0);
		HBox countLine=(HBox) vehiclesManager.getChildren().get(0);
		Label countLabel=(Label) countLine.getChildren().get(1);
		HBox listLine=(HBox) vehiclesManager.getChildren().get(1);
		ListView<String> dispatchedList=(ListView<String>) listLine.getChildren().get(2);
		
		if(dispatchedList.getItems().size()==Integer.parseInt(countLabel.getText()))
		{
			try 
			{
				if(BCMSUI.currentService.equals(Service.Pompier))
				{
					for(int i=0; i<dispatchedList.getItems().size(); i++)
					{
						BCMSUI.bCMS.dispatch_fire_truck(dispatchedList.getItems().get(i)); 
					}
					BCMSUI.bCMS.enough_fire_trucks_dispatched();
				}
				else
				{
					for(int i=0; i<dispatchedList.getItems().size(); i++)
					{
						BCMSUI.bCMS.dispatch_police_vehicle(dispatchedList.getItems().get(i));
					}
					BCMSUI.bCMS.enough_police_vehicles_dispatched();
				}
				Scene scene = ((Node) event.getTarget()).getScene();
				TitledPane interventionPane = (TitledPane) scene.lookup("#interventionPane");
				interventionPane.toFront();
			}
			catch (SQLException | Statechart_exception e) 
			{
				e.printStackTrace();
			}
		}
		else
		{
			Alert alert = new Alert(AlertType.WARNING);
            alert.setTitle("Avertissement");
            alert.setHeaderText("Vous n'avez pas envoyé le bon nombre d'unités.");
            alert.showAndWait();
		}
	}


}
