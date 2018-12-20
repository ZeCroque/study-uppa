package croquefer._BCMSUI.Panes;

import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Utilities.Route;
import croquefer._BCMSUI.Utilities.Service;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.control.ListView;
import javafx.scene.control.SplitPane;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.VBox;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;


public class RoutePaneController implements Initializable
{
	@FXML private VBox routePane;
	@FXML private ListView<String> routeList;
	private AnchorPane mapPane;
	private static Route[] routes;
	
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		try 
		{
			//Initialisation du noeud liste
			ObservableList<String> list=FXCollections.observableArrayList ();
			for(String s : BCMSUI.bCMS.get_routes())
			{
				list.add(s);
			}
			routeList.setItems(list);		
			
			//Listener sur la liste
			routeList.getSelectionModel().selectedItemProperty().addListener(new ChangeListener<String>() 
			{

				public void changed(ObservableValue<? extends String> observable,String oldValue, String newValue) 
				{
					for(int i=0; i<routeList.getItems().size(); i++)
					{
						if(routeList.getItems().get(i)==newValue)
						{
							if(routes==null)
							{
								genRoutes();
							}
							if(mapPane.getChildren().size()!=0)
							{
								mapPane.getChildren().remove(0);
							}
							mapPane.getChildren().add(routes[i].getPath());
							
						}
					}
				}
			});
		} 
		catch (SQLException e) 
		{
			e.printStackTrace();
		}
	}
	
	private void genRoutes()
	{
		mapPane = (AnchorPane) routePane.getScene().lookup("#mapPane");
		routes=new Route[3];
		
		for(int i=0;i<routes.length; i++)
		{
			routes[i]=new Route();

			routes[i].genPath(mapPane.getPrefWidth(), mapPane.getPrefHeight());
		}
	}
	
	public void validateButtonListener(ActionEvent event)
	{
        try 
		{
			if(BCMSUI.currentService.equals(Service.Pompier))
			{
				BCMSUI.bCMS.route_for_fire_trucks();
		        BCMSUI.bCMS.FSC_agrees_about_fire_truck_route();
			}
			else
			{
		        BCMSUI.bCMS.route_for_police_vehicles();
		        BCMSUI.bCMS.FSC_agrees_about_police_vehicle_route();
			}
			SplitPane interventionSplitPane = (SplitPane) routePane.getScene().lookup("#interventionSplitPane");
			VBox vehiclesListPane = (VBox) FXMLLoader.load(getClass().getResource("VehiclesListPane.fxml"));
			interventionSplitPane.getItems().add(0, vehiclesListPane);
			interventionSplitPane.getItems().remove(1);
		}
		catch (Statechart_exception | IOException e) 
		{
			e.printStackTrace();
		}
	}

	

}
