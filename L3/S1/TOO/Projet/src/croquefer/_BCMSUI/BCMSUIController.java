package croquefer._BCMSUI;

import java.net.URL;
import java.util.ResourceBundle;

import com.FranckBarbier.Java._BCMS.BCMS;
import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.Components.*;
import javafx.event.ActionEvent;
import javafx.fxml.Initializable;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.TitledPane;
import javafx.scene.control.Alert.AlertType;


public class BCMSUIController implements Initializable
{
	private static BCMS bCMS;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		try 
		{
			bCMS = new BCMS();
			bCMS.start();
			
            /*bCMS.FSC_connection_request();
            bCMS.PSC_connection_request();

            bCMS.state_police_vehicle_number(2);

            bCMS.route_for_police_vehicles();
            Thread.sleep(100);
            **
             * Bug due to PlantUML modeling style. One must await so that
             * 'route_for_police_vehicles' that is re-sent internally, arrives
             * before what follows:
             *
            bCMS.route_for_fire_trucks();
            bCMS.FSC_disagrees_about_fire_truck_route();
            bCMS.route_for_fire_trucks();
            bCMS.FSC_agrees_about_police_vehicle_route();
            bCMS.FSC_agrees_about_fire_truck_route();
            Thread.sleep(100);
            **
             * Bug due to PlantUML modeling style. One must await so that
             * 'completion' that is sent internally, arrives before what
             * follows:
             *

            bCMS.fire_truck_dispatched("FT1");
            Thread.sleep(100);
            bCMS.fire_truck_dispatched("FT2");
            Thread.sleep(100);
            bCMS.police_vehicle_dispatched("PV1");
            Thread.sleep(100);
            bCMS.police_vehicle_dispatched("PV2");
            Thread.sleep(100);
            bCMS.police_vehicle_breakdown("PV1", null);
            bCMS.fire_truck_arrived("FT1");
            bCMS.fire_truck_arrived("FT2");

            bCMS.police_vehicle_arrived("PV2");
            // 'PV1' had an accident above, so between comments:
            // bCMS.police_vehicle_arrived("PV1");
            Thread.sleep(100);
            bCMS.close();

            Thread.sleep(100);
            bCMS.reset();

            Thread.sleep(100);
            bCMS.FSC_connection_request();
            bCMS.PSC_connection_request();
            bCMS.state_fire_truck_number(4);
            bCMS.state_police_vehicle_number(2);

            bCMS.route_for_police_vehicles();
            Thread.sleep(100);
            **
             * Bug due to PlantUML modeling style. One must await so that
             * 'route_for_police_vehicles' that is re-sent internally, arrives
             * before what follows:
             *
            bCMS.route_for_fire_trucks();
            bCMS.FSC_agrees_about_police_vehicle_route();
            bCMS.FSC_agrees_about_fire_truck_route();
            Thread.sleep(100);
            **
             * Bug due to PlantUML modeling style. One must await so that
             * 'completion' that is sent internally, arrives before what
             * follows:
             *

            bCMS.fire_truck_dispatched("FT1");
            Thread.sleep(100);
            bCMS.fire_truck_dispatched("FT2");
            Thread.sleep(100);
            bCMS.fire_truck_dispatched("FT3");
            Thread.sleep(100);
            bCMS.fire_truck_dispatched("FT4");
            Thread.sleep(100);
            bCMS.police_vehicle_dispatched("PV1");
            Thread.sleep(100);
            bCMS.police_vehicle_dispatched("PV2");
            Thread.sleep(100);
            bCMS.fire_truck_breakdown("FT1", "FT1_outsider");
            bCMS.fire_truck_arrived("FT4");
            bCMS.fire_truck_arrived("FT2");
            bCMS.fire_truck_arrived("FT3");
            bCMS.police_vehicle_arrived("PV1");
            bCMS.police_vehicle_arrived("PV2");
            bCMS.crisis_is_less_severe();
            Thread.sleep(100);
            bCMS.close();
            **
             * End of state machine is delayed so that events sent internally
             * are effectively processed:
             *
            Thread.sleep(100);
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
			VehiclesManager manager = (VehiclesManager) target.getParent();
			NumberTextField countField = (NumberTextField) manager.getChildrenUnmodifiable().get(0);
			String content = countField.getText();
			if(content!=null && !content.isEmpty())
			{
				if(manager.getService()==Service.Pompier.toString())
				{
					bCMS.state_fire_truck_number(Integer.parseInt(content));
				}
				else
				{
					bCMS.state_police_vehicle_number(Integer.parseInt(content));
				}
					
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
