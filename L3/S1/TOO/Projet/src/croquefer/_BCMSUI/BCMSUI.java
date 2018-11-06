/*
 * 
 * 
    toBack

    public void toBack()

    Moves this Node to the back of its sibling nodes in terms of z-order. This is accomplished by moving this Node to the first position in its parent's content ObservableList. This function has no effect if this Node is not part of a group.

    toFront

    public void toFront()

    Moves this Node to the front of its sibling nodes in terms of z-order. This is accomplished by moving this Node to the last position in its parent's content ObservableList. This function has no effect if this Node is not part of a group.

 */


package croquefer._BCMSUI;

import com.FranckBarbier.Java._BCMS.BCMS;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class BCMSUI extends Application 
{
	//Titre des écrans
	private static final String connectionTitle="Connexion";
	private static final String FSCHomeTitle="Pompier - Acceuil";
	private static final String PSCHomeTitle="Police - Acceuil";
	
	//Texte des boutons
	private static final String unlogButtonText="Se déconnecter";
	public static final String FSCConnectionButtonText="Pompier";
	public static final String PSCConnectionButtonText="Policier";
	public static BCMS bCMS;
	
	
	@Override
	 public void start(Stage primaryStage) 
	 {

		//Lancement de la machine à état
		try 
		{
			bCMS = new BCMS();
			bCMS.start();
		
			/*//Déclaration des Scènes
			Group connectionRoot = new Group();
			Scene connectionScene = new Scene(connectionRoot, 300, 250, Color.LIGHTGREEN);
			Group FSCHomeRoot = new Group();
			Scene FSCHomeScene = new Scene(FSCHomeRoot, 300, 250, Color.RED);
			Group PSCHomeRoot = new Group();
			Scene PSCHomeScene = new Scene(PSCHomeRoot, 300, 250, Color.BLUE);
			
			//Ecran de connexion		
			VBox connectionMainLayout=new VBox();
			Label connectionLabel=new Label("Précisez votre statut :");
			connectionMainLayout.getChildren().add(connectionLabel); 
			HBox connectionButtonsLayout = new HBox();
			ConnectionButton FSCConnectionButton=new ConnectionButton(primaryStage, FSCHomeScene, FSCConnectionButtonText, FSCHomeTitle, bCMS);
			ConnectionButton PSCConnectionButton=new ConnectionButton(primaryStage, PSCHomeScene, PSCConnectionButtonText, PSCHomeTitle, bCMS);
			connectionButtonsLayout.getChildren().add(FSCConnectionButton);
			connectionButtonsLayout.getChildren().add(PSCConnectionButton);
			connectionMainLayout.getChildren().add(connectionButtonsLayout);
			connectionRoot.getChildren().add(connectionMainLayout);
			
				
			//Ecran d'acceuil des pompiers
			VBox FSCHomeMainLayout=new VBox();
			FSCHomeRoot.getChildren().add(FSCHomeMainLayout);
			VehiclesManager FTManager = new VehiclesManager(Service.FSC, bCMS);			
			FSCHomeMainLayout.getChildren().add(FTManager);
			FSCHomeMainLayout.getChildren().add(new UnlogButton(primaryStage, connectionScene, unlogButtonText, connectionTitle, bCMS));
			
			//Ecran d'acceuil des policiers
			VBox PSCHomeMainLayout=new VBox();
			PSCHomeRoot.getChildren().add(PSCHomeMainLayout);
			VehiclesManager PVManager = new VehiclesManager(Service.PSC, bCMS);			
			PSCHomeMainLayout.getChildren().add(PVManager);
			PSCHomeMainLayout.getChildren().add(new UnlogButton(primaryStage, connectionScene, unlogButtonText, connectionTitle, bCMS));
			
			//Préparation de l'écran de connexion		
	
			primaryStage.setTitle("Connexion");
			primaryStage.setScene(connectionScene);*/
			
			StackPane root = (StackPane)FXMLLoader.load(getClass().getResource("BCMSUI.fxml"));
			Scene scene = new Scene(root,400,400);
			primaryStage.setScene(scene);
			//Lancement de l'UI
			primaryStage.show();
		}
		catch (Throwable t) 
		{
			t.printStackTrace();
		}
	 }

	public static void main(String args[]) 
	{	
		Application.launch(BCMSUI.class, args);
        /*try {
            final BCMS bCMS = new BCMS();
            bCMS.start();

            bCMS.FSC_connection_request();
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
            bCMS.stop();
        } catch (Throwable t) {
            t.printStackTrace();
        }*/
    }

}
