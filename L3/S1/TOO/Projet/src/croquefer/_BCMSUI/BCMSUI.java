package croquefer._BCMSUI;


import java.io.IOException;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

public class BCMSUI extends Application 
{
		
	@Override
	 public void start(Stage primaryStage) 
	 {

		//Lancement de la machine à état
		
		
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
			
			try 
			{
				StackPane root = (StackPane)FXMLLoader.load(getClass().getResource("BCMSUI.fxml"));
				Scene scene = new Scene(root,400,400);
				primaryStage.setScene(scene);
				primaryStage.setTitle("Barbados Crisis Management System");
				//Lancement de l'UI
				primaryStage.show();
			} 
			catch (IOException e) 
			{
				e.printStackTrace();
			}
	
	 }

	public static void main(String args[]) 
	{	
		Application.launch(BCMSUI.class, args);
    }

}
