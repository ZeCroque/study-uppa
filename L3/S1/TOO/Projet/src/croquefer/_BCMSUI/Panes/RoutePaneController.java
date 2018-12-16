package croquefer._BCMSUI.Panes;

import java.net.URL;
import java.util.ResourceBundle;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Service;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TitledPane;

public class RoutePaneController implements Initializable
{
	@FXML private TitledPane routePane;
	
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
		} 
		catch (Statechart_exception e) 
		{
			e.printStackTrace();
		}

	}

}
