package croquefer._BCMSUI.Panes;

import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Service;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ListView;
import javafx.scene.control.TitledPane;

public class RoutePaneController implements Initializable
{
	@FXML private TitledPane routePane;
	@FXML private ListView<String> routeList;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		try 
		{
			if(BCMSUI.currentService.equals(Service.Pompier))
			{
				routePane.getContent().setStyle("-fx-background-color: red;");
				BCMSUI.bCMS.route_for_fire_trucks();
			}
			else
			{
				routePane.getContent().setStyle("-fx-background-color: blue;");
				BCMSUI.bCMS.route_for_police_vehicles();
			}
			routePane.setText(BCMSUI.currentService+" - Choix de la route");
			ObservableList<String> list=FXCollections.observableArrayList ();
			for(String s : BCMSUI.bCMS.get_routes())
			{
				list.add(s);
			}
			routeList.setItems(list);
		} 
		catch (Statechart_exception | SQLException e) 
		{
			e.printStackTrace();
		}

	}
	
	public void validateButtonListener(ActionEvent event)
	{
		
	}

}
