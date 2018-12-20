package croquefer._BCMSUI.Panes;

import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TitledPane;

import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;


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

		try 
		{
			if(BCMSUI.currentService.equals(Service.Pompier))
			{
				for(int i=0; i<dispatchedList.getItems().size(); i++)
				{
					BCMSUI.bCMS.dispatch_fire_truck(dispatchedList.getItems().get(i)); 
				}
			}
			else
			{
				for(int i=0; i<dispatchedList.getItems().size(); i++)
				{
					BCMSUI.bCMS.dispatch_police_vehicle(dispatchedList.getItems().get(i));
				}
			}
			Scene scene = ((Node) event.getTarget()).getScene();
			TitledPane routePane = (TitledPane) scene.lookup("#interventionPane");
			routePane.toFront();
		}
		catch (SQLException e) 
		{
			e.printStackTrace();
		}
	}
	
}
