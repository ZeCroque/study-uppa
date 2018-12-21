package croquefer._BCMSUI.Panes;


import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Components.NumberTextField;
import croquefer._BCMSUI.Utilities.Service;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.TitledPane;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Label;

public class AlertPaneController implements Initializable
{
	@FXML private TitledPane alertPane;
	@FXML private NumberTextField countField;
	@FXML private Label availableVehiclesCount;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
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
	public void validateButtonController(ActionEvent event) 
	{
		
		try 
		{				
			String content = countField.getText();
			Scene scene = ((Node) event.getTarget()).getScene();

			if(content!=null && !content.isEmpty() && Integer.parseInt(content)<=Integer.parseInt(availableVehiclesCount.getText()))
			{
				if(BCMSUI.currentService.equals(Service.Pompier))
				{
					BCMSUI.bCMS.state_fire_truck_number(Integer.parseInt(content));
				}
				else
				{
					BCMSUI.bCMS.state_police_vehicle_number(Integer.parseInt(content));
				}
				TitledPane vehiclesPane = (TitledPane) scene.lookup("#vehiclesPane");
				Label countLabel = (Label) scene.lookup("#countLabel");
				countLabel.setText(""+Integer.parseInt(content));
				vehiclesPane.toFront();					
			}
			else
			{
				Alert alert = new Alert(AlertType.INFORMATION);
				alert.setTitle("Avertissement");
				alert.setHeaderText("Vous avez saisi un nombre incorrect ou supérieur au nombre d'unités disponibles.");
				alert.showAndWait();
			}					
		} 
		catch (Statechart_exception e) 
		{
			e.printStackTrace();
		}
	}
}
