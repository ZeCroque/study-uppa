import java.net.URL;
import java.util.ResourceBundle;

import javafx.animation.PathTransition;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.layout.AnchorPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.util.Duration;

public class RoutePaneController implements Initializable
{
	
	@FXML private AnchorPane routeRightPane;

	@Override
	public void initialize(URL location, ResourceBundle resources) 
	{
		Route r=new Route();
		
		final Circle circle = new Circle(20, 20, 15);
	    circle.setFill(Color.DARKRED);
	    
	
	    routeRightPane.getChildren().add(r.path);
	    routeRightPane.getChildren().add(circle);
	    final PathTransition pathTransition = new PathTransition();
	
	    pathTransition.setDuration(Duration.seconds(1.0));
	    pathTransition.setDelay(Duration.seconds(.1));
	    pathTransition.setPath(r.path);
	    pathTransition.setNode(circle);
	    pathTransition.setOrientation(PathTransition.OrientationType.ORTHOGONAL_TO_TANGENT);
		
		r.genPath(routeRightPane.getPrefWidth(), routeRightPane.getPrefHeight());
	    pathTransition.play();
	}
	
}
