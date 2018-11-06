package croquefer._BCMSUI.Components;

import java.io.IOException;

import javafx.beans.NamedArg;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.HBox;


public class VehiclesManager extends HBox
{
	private String _service;

	public VehiclesManager(@NamedArg("service") String service) throws IOException
	{
		//super();
		FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("VehiclesManager.fxml"));
		fxmlLoader.setRoot(this);
		this._service=service;
		try 
		{
            fxmlLoader.load();
        } 
		catch (IOException exception) 
		{
            throw new RuntimeException(exception);
        }
	}
	
	public String getService()
	{
		return this._service;
	}
}
