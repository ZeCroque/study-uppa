package croquefer._BCMSUI;

import java.sql.SQLException;
import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.Components.*;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TitledPane;
import javafx.scene.layout.HBox;
import javafx.scene.control.Alert.AlertType;


public class BCMSUIController
{
	
	 @FXML public Label vehiclesCount;

	public void connectionButtonController(ActionEvent event)
	{
		Button target = (Button) event.getTarget();
		Scene scene = target.getScene();
		
		String buttonText = target.getText();

		try 
		{
			if(buttonText.equals(Service.Pompier.toString()))
			{
				TitledPane fSCHomePane= (TitledPane) scene.lookup("#fSCHomePane");
				fSCHomePane.toFront();
				BCMSUI.bCMS.FSC_connection_request();
			}
			else
			{
				TitledPane pSCHomePane= (TitledPane) scene.lookup("#pSCHomePane");
				pSCHomePane.toFront();
				BCMSUI.bCMS.PSC_connection_request();
			}

		} 
		catch (Statechart_exception e) 
		{
			e.printStackTrace();
		} 
	}
	
	public void unlogButtonController(ActionEvent event) 
	{	
		Button target = (Button) event.getTarget();
		Scene scene = target.getScene();
		
		try
		{
			TitledPane connexionPane= (TitledPane) scene.lookup("#connexionPane");
			connexionPane.toFront();
            Thread.sleep(100);
            BCMSUI.bCMS.reset();
		}
		catch (InterruptedException e) 
		{
			e.printStackTrace();
		} catch (Statechart_exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void vehiclesManagerController(ActionEvent event) 
	{
		try 
		{					
			Button target = (Button) event.getTarget();
			HBox countHBox = (HBox) target.getParent();
			NumberTextField countField = (NumberTextField) countHBox.getChildren().get(0);
			String content = countField.getText();
			VehiclesManager manager = (VehiclesManager) countHBox.getParent();
			if(content!=null && !content.isEmpty())
			{
				if(manager.getService().equals(Service.Pompier.toString()))
				{
					BCMSUI.bCMS.state_fire_truck_number(Integer.parseInt(content));
					BCMSUI.bCMS.route_for_fire_trucks();
					for (String s : BCMSUI.bCMS.get_fire_trucks()) {
		                System.out.println("Idle: " + s);
		            }
				}
				else
				{
					BCMSUI.bCMS.state_police_vehicle_number(Integer.parseInt(content));
					BCMSUI.bCMS.route_for_police_vehicles();
				}
				countField.setText("");					
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
		} catch (SQLException e) 
		{
			e.printStackTrace();
		} 

	}

}
