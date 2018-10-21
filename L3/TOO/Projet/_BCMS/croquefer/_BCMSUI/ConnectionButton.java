package croquefer._BCMSUI;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import com.FranckBarbier.Java._BCMS.BCMS;
import com.pauware.pauware_engine._Exception.Statechart_exception;

public class ConnectionButton extends Button
{
	ConnectionButton(Stage stage, Scene scene, String buttonText, String title, BCMS bCMS)
	{
		super(buttonText);
		stage.setTitle(title);
		this.setOnAction(new EventHandler<ActionEvent>() 
		{
			public void handle(ActionEvent event) 
			{
				try 
				{
					stage.setScene(scene);
					if(buttonText==BCMSUI.FSCConnectionButtonText)
					{
					 bCMS.FSC_connection_request();
					}
					else
					{
						bCMS.PSC_connection_request();
					}

				} 
				catch (Statechart_exception e) 
				{
					e.printStackTrace();
				} 

			}
		});

	}
}
