package croquefer._BCMSUI.Panes;

import java.io.InputStream;
import java.sql.SQLException;
import java.util.Optional;

import com.FranckBarbier.Java._BCMS.BCMS.Status;
import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.Utilities.Route;
import croquefer._BCMSUI.Utilities.Service;
import javafx.animation.PathTransition;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.geometry.NodeOrientation;
import javafx.scene.control.Alert;
import javafx.scene.control.ListView;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.ButtonType;
import javafx.scene.control.DialogEvent;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.shape.MoveTo;
import javafx.util.Duration;

public class VehiclesListPaneController
{
	@FXML private ListView<String> vehiclesList;
	public static ListView<String> vehiclesListStatic;
	public static AnchorPane mapPane;
	private static final double travelTime=15.0;
	private static PathTransition[] pathTransitions;
	
	public static synchronized void initialize() 
	{
		try 
		{
			//Add vehicles to list
			ObservableList<String> list=FXCollections.observableArrayList ();
			Class<?> cl = VehiclesListPaneController.class;
			InputStream input;
			int size=0;
			if(BCMSUI.currentService.equals(Service.Pompier))
			{
				for (String s : BCMSUI.bCMS.get_fire_trucks(Status.Dispatched)) 
				{
				    list.add(s);

				}
				input = cl.getResourceAsStream("/croquefer/_BCMSUI/Images/firetruck.png");
				size=BCMSUI.bCMS.get_fire_trucks(Status.Dispatched).size();
			} 
			else
			{
				for (String s : BCMSUI.bCMS.get_police_vehicles(Status.Dispatched)) 
				{
				    list.add(s);
				}
				input = cl.getResourceAsStream("/croquefer/_BCMSUI/Images/policevehicle.png");
				size=BCMSUI.bCMS.get_police_vehicles(Status.Dispatched).size();
			}
			vehiclesListStatic.setItems(list);
			
			//Add vehicles sprites
		 
			Image sprite=new Image(input,50.0,50.0,true,true);
			pathTransitions = new PathTransition[size];
			for(int i=0, delay=0; i<size; i++, delay+=3)
			{
				ImageView image=new ImageView(sprite);
				image.setNodeOrientation(NodeOrientation.RIGHT_TO_LEFT);
				MoveTo firstDirection=(MoveTo) RoutePaneController.routes[RoutePaneController.currentRouteIndex].getPath().getElements().get(0);
				if(Route.getStartPoint().getKey()>Route.getEndPoint().getKey() && firstDirection.getX()==Route.getStartPoint().getKey())
				{
					image.setScaleY(-1);
				}
				image.setVisible(false);
				mapPane.getChildren().add(image);
				pathTransitions[i]=new PathTransition();
				pathTransitions[i].setDuration(Duration.seconds(travelTime));
				pathTransitions[i].setPath(RoutePaneController.routes[RoutePaneController.currentRouteIndex].getPath());
				pathTransitions[i].setNode(image);
				pathTransitions[i].setOrientation(PathTransition.OrientationType.ORTHOGONAL_TO_TANGENT);
				pathTransitions[i].setDelay(Duration.seconds(delay));
				pathTransitions[i].play();
				pathTransitions[i].currentTimeProperty().addListener(new DurationListener(image));
				pathTransitions[i].setOnFinished(new EventHandler<ActionEvent>()
				{

					@Override
					public void handle(ActionEvent event) 
					{
						try 
						{	
							PathTransition path = (PathTransition) event.getSource();
							PathTransition[] tmp = new PathTransition[pathTransitions.length-1];
							for(int i=0, j=0; i<pathTransitions.length; i++, j++)
							{
								if(path.equals(pathTransitions[i]))
								{
									j--;
									if(BCMSUI.currentService.equals(Service.Pompier))
									{
										BCMSUI.bCMS.arrive_fire_truck(vehiclesListStatic.getItems().get(i));
										pathTransitions[i].stop();
									}
									else
									{
										BCMSUI.bCMS.arrive_police_vehicle(vehiclesListStatic.getItems().get(i));
										pathTransitions[i].stop();
									}
									vehiclesListStatic.getItems().remove(vehiclesListStatic.getItems().get(i));									
								}
								else
								{
									tmp[j]=pathTransitions[i];
								}
							}
							pathTransitions=tmp;
							
							if(vehiclesListStatic.getItems().size()==0)
							{
								Alert alert = new Alert(AlertType.INFORMATION);
								alert.setTitle("Véhicules arrivés");
								alert.setContentText("L'alerte a été traitée");
								alert.setOnHidden(new EventHandler<DialogEvent>() 
								{

									@Override
									public void handle(DialogEvent event) 
									{
										try 
										{
											if(BCMSUI.currentService.equals(Service.Pompier))
											{
												
												BCMSUI.bCMS.enough_fire_trucks_arrived();
											}
											else
											{
												BCMSUI.bCMS.enough_police_vehicles_arrived();
											}
											BCMSUI.bCMS.stop();
											BCMSUI.bCMS.start();
											BCMSUI.stage.setScene(BCMSUI.homeScene);
										} 
										catch (Statechart_exception e) 
										{
											// TODO Auto-generated catch block
											e.printStackTrace();
										}
								
									}
								});
								alert.show();
								
							}
							
						}
						catch (SQLException e) 
						{
							e.printStackTrace();
						}
					}					
				});
			}
			
			    
		    
		} 
		catch (SQLException e) 
		{
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		
		
	}
	
	public void validateButtonListener(ActionEvent event)
	{
	}
	
	public void playButtonListener(ActionEvent event)
	{
		try 
		{
			String selected=(String)vehiclesList.getSelectionModel().getSelectedItem();
			for(int i=0; i<vehiclesList.getItems().size(); i++)
			{
				if(vehiclesList.getItems().get(i).equals(selected))
				{
					pathTransitions[i].play();
					if(BCMSUI.currentService.equals(Service.Pompier))
					{
						BCMSUI.bCMS.recall_fire_truck(selected);
						BCMSUI.bCMS.dispatch_fire_truck(selected);
					}
					else
					{
						BCMSUI.bCMS.recall_police_vehicle(selected);
						BCMSUI.bCMS.dispatch_police_vehicle(selected);
					}				
				}
			}
		} 
		catch (SQLException e) 
		{
			e.printStackTrace();
		}
	}
	
	public void stopButtonListener(ActionEvent event)
	{
		try 
		{
			String selected=(String)vehiclesList.getSelectionModel().getSelectedItem();
			for(int i=0; i<vehiclesList.getItems().size(); i++)
			{
				if(vehiclesList.getItems().get(i).equals(selected))
				{
					pathTransitions[i].pause();
					if(BCMSUI.currentService.equals(Service.Pompier))
					{
						BCMSUI.bCMS.block_fire_truck(selected);
					}
					else
					{
						BCMSUI.bCMS.block_police_vehicle(selected);
					}				
				}
			}
		} 
		catch (SQLException e) 
		{
			e.printStackTrace();
		}
	}
	
	public void breakdownButtonListener(ActionEvent event)
	{
		//TODO Gérer breakdown+List type alertes+bug après déconnexion+replacer bouton déconnexion+replacer background+style
		try 
		{
			String selected=(String)vehiclesList.getSelectionModel().getSelectedItem();
			for(int i=0; i<vehiclesList.getItems().size(); i++)
			{
				if(vehiclesList.getItems().get(i).equals(selected))
				{
					pathTransitions[i].stop();
					if(BCMSUI.currentService.equals(Service.Pompier))
					{
						BCMSUI.bCMS.breakdown_fire_truck(selected, "");
					}
					else
					{
						BCMSUI.bCMS.breakdown_police_vehicle(selected, "");
					}				
				}
			}
		} 
		catch (SQLException e) 
		{
			e.printStackTrace();
		}
	}

}

class DurationListener implements ChangeListener<Duration>
{
	private ImageView img;
	
	public DurationListener(ImageView img)
	{
		this.img=img;
	}
	
	
	@Override
	public void changed(ObservableValue<? extends Duration> observable, Duration oldValue, Duration newValue) 
	{
		if(newValue.toSeconds()>0)
		{
			img.setVisible(true);
		}
		
	}
	
}

/*mapPane.getChildren().add(circle);
final PathTransition pathTransition = new PathTransition();

pathTransition.setDuration(Duration.seconds(1.0));
pathTransition.setDelay(Duration.seconds(.1));
pathTransition.setPath(r.getPath());
pathTransition.setNode(circle);
pathTransition.setOrientation(PathTransition.OrientationType.ORTHOGONAL_TO_TANGENT);

r.genPath(routeRightPane.getPrefWidth(), routeRightPane.getPrefHeight());
pathTransition.play();*/
