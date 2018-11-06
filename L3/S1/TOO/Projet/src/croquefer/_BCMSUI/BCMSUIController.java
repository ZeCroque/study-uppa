package croquefer._BCMSUI;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import javafx.event.ActionEvent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;

public class BCMSUIController 
{

	public void connectionButtonController(ActionEvent event)
	{
		Button target = (Button) event.getTarget();
		Scene scene = target.getScene();
		StackPane stackPanel = (StackPane) scene.lookup("#root");
		
		String buttonText = target.getText();
		for(int i=0; i<stackPanel.getChildren().size(); i++)
		{
			if(stackPanel.getChildren().get(i)==null) {}
		}

		try 
		{
			if(buttonText.equals(Service.Pompier.toString()))
			{
				BCMSUI.bCMS.FSC_connection_request();
			}
			else
			{
				BCMSUI.bCMS.PSC_connection_request();
			}

		} 
		catch (Statechart_exception e) 
		{
			e.printStackTrace();
		} 
	}
	
}
