package croquefer._BCMSUI.Panes;

import java.net.URL;
import java.util.ResourceBundle;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Utilities.Service;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.TitledPane;

public class InterventionPaneController implements Initializable
{

	@FXML private TitledPane interventionPane;
	
	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		if(BCMSUI.currentService.equals(Service.Pompier))
		{
			interventionPane.getContent().setStyle("-fx-background-color: red;");
		}
		else
		{
			interventionPane.getContent().setStyle("-fx-background-color: blue;");
		}
		interventionPane.setText(BCMSUI.currentService+" - Choix de la route");
	}
	
}
