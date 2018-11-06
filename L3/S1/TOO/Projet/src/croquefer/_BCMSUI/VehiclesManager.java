package croquefer._BCMSUI;

import com.FranckBarbier.Java._BCMS.BCMS;
import com.pauware.pauware_engine._Exception.Statechart_exception;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Alert;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;

public class VehiclesManager extends HBox
{
	private NumberTextField countField;
	private Button validButton;

	public VehiclesManager(Service service, BCMS bCMS)
	{
		super();
		this.validButton = new Button();
		this.validButton.setText("Envoyer");
		this.validButton.setOnAction(new EventHandler<ActionEvent>() 
		{
			public void handle(ActionEvent event) 
			{
				try 
				{					
					Button target = (Button) event.getTarget();
					NumberTextField countField = (NumberTextField) target.getParent().getChildrenUnmodifiable().get(0);
					String content = countField.getText();
					if(content!=null && !content.isEmpty())
					{
						if(service==Service.Pompier)
						{
							bCMS.state_fire_truck_number(Integer.parseInt(content));
						}
						else
						{
							bCMS.state_police_vehicle_number(Integer.parseInt(content));
						}
							
					}
					else
					{
						Alert alert = new Alert(AlertType.INFORMATION);
						alert.setTitle("Avertissement");
						alert.setHeaderText("Vous devez entrer un nombre dans le champ avant de valider.");
						alert.showAndWait();
					}					
				} 
				catch (Statechart_exception e) 
				{
					e.printStackTrace();
				} 

			}
		});
		this.countField = new NumberTextField();
		this.getChildren().add(countField);
		this.getChildren().add(validButton);

		
	}
}
