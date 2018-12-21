package croquefer._BCMSUI;

import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.Panes.InterventionManagerPaneController;
import croquefer._BCMSUI.Panes.RoutePaneController;
import croquefer._BCMSUI.Utilities.Route;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Alert.AlertType;

public class CoreController 
{
	public void unlogButtonController(ActionEvent event) 
	{	
		Alert alert = new Alert(AlertType.WARNING);
		alert.setTitle("Avertissement");
		alert.setHeaderText("Etes vous sur de vouloir vous déconnecter ?");
		alert.setContentText("Vous perdrez la session en cours.");	
		alert.getDialogPane().getButtonTypes().add(ButtonType.CANCEL);
		final Button okButton = (Button) alert.getDialogPane().lookupButton(ButtonType.OK);
		okButton.setText("Oui");
		okButton.addEventFilter(ActionEvent.ACTION,new EventHandler<ActionEvent>() 
		{

			@Override
			public void handle(ActionEvent event) 
			{
				cleanup();			
			}
		});
		okButton.setDefaultButton(false);
		final Button cancelButton = (Button) alert.getDialogPane().lookupButton(ButtonType.CANCEL);
		cancelButton.setDefaultButton(true);
		alert.show();
	}

	
	public static void cleanup()
	{
		try
		{
            Route.resetCoords();
            RoutePaneController.routes=null;
			BCMSUI.stage.setScene(BCMSUI.homeScene);
            Thread.sleep(100);
            BCMSUI.bCMS.stop();
            BCMSUI.bCMS.start();
            if(InterventionManagerPaneController.pathTransitions!=null)
            {
                InterventionManagerPaneController.pathTransitions.clear();
            }
		}
		catch (InterruptedException | Statechart_exception e) 
		{
			e.printStackTrace();
		}
	}
}
