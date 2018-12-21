package croquefer._BCMSUI.Panes;

import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TitledPane;
import javafx.scene.control.Alert.AlertType;

import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Utilities.Service;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;

public class VehiclesPaneController implements Initializable
{

	//@FXML private VehiclesPane vehiclesPane;
	@FXML private ListView<String> idleList;
	@FXML private ListView<String> dispatchedList;
	@FXML private TitledPane vehiclesPane;
	@FXML private Label countLabel;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		try 
		{
			ObservableList<String> list=FXCollections.observableArrayList ();
			if(BCMSUI.currentService.equals(Service.Pompier))
			{
				for (String s : BCMSUI.bCMS.get_fire_trucks()) 
				{
				    list.add(s);

				}
				vehiclesPane.getContent().setStyle("-fx-background-color: red;");
			} 
			else
			{
				for (String s : BCMSUI.bCMS.get_police_vehicles()) 
				{
				    list.add(s);
				}
				vehiclesPane.getContent().setStyle("-fx-background-color: blue;");
			}
			idleList.setItems(list);
			idleList.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
			vehiclesPane.setText(BCMSUI.currentService+" - Gestion des véhicules");
		}
		catch (SQLException e) 
		{
			e.printStackTrace();
		}
	}
	
	public void dispatchButtonController(ActionEvent event)
	{
		ObservableList<String> selectedItems=idleList.getSelectionModel().getSelectedItems();
	
		dispatchedList.getItems().addAll(selectedItems);

		idleList.getItems().removeAll(selectedItems);
		
	}
	
	public void undispatchButtonController(ActionEvent event)
	{
		ObservableList<String> selectedItems=dispatchedList.getSelectionModel().getSelectedItems();
	
		idleList.getItems().addAll(selectedItems);

		dispatchedList.getItems().removeAll(selectedItems);
	}

	public void validateButtonController(ActionEvent event)
	{
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
			Alert alert = new Alert(AlertType.INFORMATION);
            alert.setTitle("Avertissement");
            alert.setHeaderText("Vous n'avez pas envoyé le bon nombre d'unités.");
            alert.showAndWait();
		}
	}
	
}
