package croquefer._BCMSUI;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.stage.Stage;
import com.FranckBarbier.Java._BCMS.BCMS;
import com.pauware.pauware_engine._Exception.Statechart_exception;

public class UnlogButton extends Button
{
	UnlogButton(Stage stage, Scene scene, String buttonText, String title, BCMS bCMS)
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
		});

	}


}
