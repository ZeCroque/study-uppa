package croquefer._BCMSUI;

import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;

import com.FranckBarbier.Java._BCMS.BCMS;
import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.Components.*;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TitledPane;
import javafx.scene.layout.HBox;
import javafx.scene.control.Alert.AlertType;


public class BCMSUIController implements Initializable
{
	
	 @FXML public Label vehiclesCount;
	private static BCMS bCMS;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		if(vehiclesCount!=null)
		{
			vehiclesCount.setText("tyr");
		}

		try 
		{
			bCMS = new BCMS();
			bCMS.start();
			
            /*bCMS.FSC_connection_request();
            bCMS.PSC_connection_request();
            bCMS.state_fire_truck_number(2);
            bCMS.state_police_vehicle_number(2);

            for (String s : bCMS.get_fire_trucks()) {
                System.out.println("Idle: " + s);
            }

            bCMS.route_for_police_vehicles();

            bCMS.route_for_fire_trucks();
            bCMS.FSC_disagrees_about_fire_truck_route();
            bCMS.route_for_fire_trucks();
            bCMS.FSC_agrees_about_police_vehicle_route();
            bCMS.FSC_agrees_about_fire_truck_route();
            Thread.sleep(10);
    

            bCMS.fire_truck_dispatched("Fire truck #1");
            Thread.sleep(10);
            bCMS.fire_truck_dispatched("Fire truck #2");
            Thread.sleep(10);
            for (String s : bCMS.get_fire_trucks(Status.Dispatched)) {
                System.out.println(Status.Dispatched + ": " + s);
            }

            bCMS.police_vehicle_dispatched("Police vehicle #1");
            Thread.sleep(10);
            bCMS.police_vehicle_dispatched("Police vehicle #2");
            Thread.sleep(10);
            for (String s : bCMS.get_police_vehicles(Status.Dispatched)) {
                System.out.println(Status.Dispatched + ": " + s);
            }

            bCMS.police_vehicle_breakdown("Police vehicle #1", "");
            for (String s : bCMS.get_police_vehicles(Status.Breakdown)) {
                System.out.println(Status.Breakdown + ": " + s);
            }

            bCMS.fire_truck_arrived("Fire truck #1");
            Thread.sleep(10);
            bCMS.fire_truck_arrived("Fire truck #2");
            Thread.sleep(10);
            for (String s : bCMS.get_fire_trucks(Status.Dispatched)) {
                System.out.println(Status.Dispatched + ": " + s);
            }
            for (String s : bCMS.get_fire_trucks(Status.Arrived)) {
                System.out.println(Status.Arrived + ": " + s);
            }

            bCMS.police_vehicle_arrived("Police vehicle #2");
            Thread.sleep(10);
            for (String s : bCMS.get_police_vehicles(Status.Dispatched)) {
                System.out.println(Status.Dispatched + ": " + s);
            }
            for (String s : bCMS.get_police_vehicles(Status.Arrived)) {
                System.out.println(Status.Arrived + ": " + s);
            }
            bCMS.close();
      
            Thread.sleep(10);
            bCMS.stop();

            bCMS = new BCMS();
            bCMS.start();

            Thread.sleep(10);
            bCMS.FSC_connection_request();
            bCMS.PSC_connection_request();
            bCMS.state_fire_truck_number(3);
            bCMS.state_police_vehicle_number(2);

            bCMS.route_for_police_vehicles();
            Thread.sleep(10);

            bCMS.route_for_fire_trucks();
            bCMS.FSC_agrees_about_police_vehicle_route();
            bCMS.FSC_agrees_about_fire_truck_route();
            Thread.sleep(10);


            bCMS.fire_truck_dispatched("Fire truck #1");
            Thread.sleep(10);
            bCMS.fire_truck_dispatched("Fire truck #2");
            Thread.sleep(10);
            bCMS.fire_truck_dispatched("Fire truck #3");
            Thread.sleep(10);
            bCMS.police_vehicle_dispatched("Police vehicle #2");
            Thread.sleep(10);
            bCMS.police_vehicle_dispatched("Police vehicle #1");
            Thread.sleep(10);
            bCMS.fire_truck_breakdown("Fire truck #1", "Fire truck #4");
            Thread.sleep(10);
            for (String s : bCMS.get_fire_trucks(Status.Dispatched)) {
                System.out.println(Status.Dispatched + ": " + s);
            }

            bCMS.fire_truck_arrived("Fire truck #4");
            Thread.sleep(10);
            bCMS.fire_truck_arrived("Fire truck #3");
            Thread.sleep(10);
            bCMS.fire_truck_arrived("Fire truck #2");
            Thread.sleep(10);
            bCMS.fire_truck_arrived("Fire truck #1"); // No effect!
            Thread.sleep(10);
            for (String s : bCMS.get_fire_trucks(Status.Arrived)) {
                System.out.println(Status.Arrived + ": " + s);
            }
            bCMS.police_vehicle_arrived("Police vehicle #1");
            Thread.sleep(10);
            bCMS.crisis_is_less_severe();
            Thread.sleep(10);
            for (String s : bCMS.get_police_vehicles(Status.Dispatched)) {
                System.out.println(Status.Dispatched + ": " + s);
            }
            for (String s : bCMS.get_police_vehicles(Status.Arrived)) {
                System.out.println(Status.Arrived + ": " + s);
            }
            bCMS.police_vehicle_arrived("Police vehicle #2"); // No effect!
            Thread.sleep(10);
            bCMS.close();
           
            Thread.sleep(10);
            bCMS.stop();*/
		}
		catch (Statechart_exception e) 
		{
			e.printStackTrace();
		}
		
	}
	
	
	
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
				bCMS.FSC_connection_request();
			}
			else
			{
				TitledPane pSCHomePane= (TitledPane) scene.lookup("#pSCHomePane");
				pSCHomePane.toFront();
				bCMS.PSC_connection_request();
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
            bCMS.reset();
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
					bCMS.state_fire_truck_number(Integer.parseInt(content));
					bCMS.route_for_fire_trucks();
					for (String s : bCMS.get_fire_trucks()) {
		                System.out.println("Idle: " + s);
		            }
				}
				else
				{
					bCMS.state_police_vehicle_number(Integer.parseInt(content));
					bCMS.route_for_police_vehicles();
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
