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
			try 
			{
				StackPane root = (StackPane)FXMLLoader.load(getClass().getResource("BCMSUI.fxml"));
				Scene scene = new Scene(root,400,400);
				primaryStage.setScene(scene);
				primaryStage.setTitle("Barbados Crisis Management System");
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
