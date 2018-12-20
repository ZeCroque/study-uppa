package croquefer._BCMSUI.Panes;

import java.net.URL;
import java.util.ResourceBundle;

import javafx.animation.PathTransition;
import javafx.event.ActionEvent;
import javafx.fxml.Initializable;

//TODO

public class VehiclesListPaneController implements Initializable
{

	@Override
	public void initialize(URL location, ResourceBundle resources) {
		// TODO Auto-generated method stub
		
	}
	
	public void validateButtonListener(ActionEvent event)
	{
		
	}

}

/*routeRightPane.getChildren().add(r.getPath());
routeRightPane.getChildren().add(circle);
final PathTransition pathTransition = new PathTransition();

pathTransition.setDuration(Duration.seconds(1.0));
pathTransition.setDelay(Duration.seconds(.1));
pathTransition.setPath(r.getPath());
pathTransition.setNode(circle);
pathTransition.setOrientation(PathTransition.OrientationType.ORTHOGONAL_TO_TANGENT);

r.genPath(routeRightPane.getPrefWidth(), routeRightPane.getPrefHeight());
pathTransition.play();*/
