package croquefer._BCMSUI.Components;

import java.io.IOException;

import javafx.beans.NamedArg;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.HBox;


public class VehiclesManager extends HBox
{
	private String _service;

	public VehiclesManager(/*@NamedArg("service") String service*/) throws IOException
	{
		super();
		this.getChildren().add((HBox)FXMLLoader.load(getClass().getResource("VehiclesManager.fxml")));
		//this._service=service;
	}
	
	public String getService()
	{
		return this._service;
	}
}
