package croquefer._BCMSUI;


import java.io.IOException;

import com.FranckBarbier.Java._BCMS.BCMS;
import com.pauware.pauware_engine._Exception.Statechart_exception;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class BCMSUI extends Application 
{
	public static BCMS bCMS;
	public static Stage stage;
	public static Scene homeScene;
	public static Service currentService;
	
	@Override
	 public void start(Stage primaryStage) 
	 {	
		//Statechart
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
			
			
			//UI
			BCMSUI.stage=primaryStage;
			VBox root = (VBox)FXMLLoader.load(getClass().getResource("Logon.fxml"));
			BCMSUI.homeScene = new Scene(root,400,400);
			BCMSUI.stage.setScene(BCMSUI.homeScene);
			BCMSUI.stage.setTitle("Barbados Crisis Management System");
			BCMSUI.stage.show();
		}
		catch (Statechart_exception | IOException e) 
		{
			e.printStackTrace();	
		}

	
	 }

	public static void main(String args[]) 
	{	
		Application.launch();
    }

}
