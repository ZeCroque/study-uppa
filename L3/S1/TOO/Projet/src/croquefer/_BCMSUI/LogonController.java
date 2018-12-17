package croquefer._BCMSUI;

import java.io.IOException;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;


public class LogonController
{

	public void connectionButtonController(ActionEvent event)
	{
		Button target = (Button) event.getTarget();		
		String buttonText = target.getText();
		try 
		{
			if(buttonText.equals(Service.Pompier.toString()))
			{	
				BCMSUI.currentService=Service.Pompier;
				BCMSUI.bCMS.FSC_connection_request();
			}
			else
			{
				BCMSUI.currentService=Service.Policier;
				BCMSUI.bCMS.PSC_connection_request();
			}
			StackPane root = (StackPane)FXMLLoader.load(getClass().getResource("Core.fxml"));
			Scene scene = new Scene(root,400,400);
			BCMSUI.stage.setScene(scene);

		} 
		catch (Statechart_exception | IOException e) 
		{
			e.printStackTrace();
		}
	}
}