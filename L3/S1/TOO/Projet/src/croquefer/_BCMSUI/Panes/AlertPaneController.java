package croquefer._BCMSUI.Panes;


import java.net.URL;
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

public class AlertPaneController implements Initializable
{
	@FXML private TitledPane alertPane;
	@FXML private NumberTextField countField;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		if(BCMSUI.currentService.equals(Service.Pompier))
		{
			alertPane.getContent().setStyle("-fx-background-color: red;");
		}
		else
		{
			alertPane.getContent().setStyle("-fx-background-color: blue;");
		}
		alertPane.setText(BCMSUI.currentService+" - Déclaration d'alerte");
		
	}
	public void validateButtonController(ActionEvent event) 
	{
		
		try 
		{				
			String content = countField.getText();
			Scene scene = ((Node) event.getTarget()).getScene();

			if(content!=null && !content.isEmpty())
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
				vehiclesPane.toFront();					
			}
			else
			{
				Alert alert = new Alert(AlertType.INFORMATION);
				alert.setTitle("Avertissement");
				alert.setHeaderText("Vous devez entrer un nombre dans le champ avant de valider.");
				alert.showAndWait();
			}					
		} 
		catch (Statechart_exception e) 
		{
			e.printStackTrace();
		}
	}
}
