package croquefer._BCMSUI.Components;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import javafx.event.ActionEvent;

public class UnlogButtonController 
{
	public void unlogButtonController(ActionEvent event) 
	{		
		try
		{
			BCMSUI.stage.setScene(BCMSUI.homeScene);
            Thread.sleep(100);
            BCMSUI.bCMS.stop();
            BCMSUI.bCMS.start();
		}
		catch (InterruptedException | Statechart_exception e) 
		{
			e.printStackTrace();
		}
	}
}
