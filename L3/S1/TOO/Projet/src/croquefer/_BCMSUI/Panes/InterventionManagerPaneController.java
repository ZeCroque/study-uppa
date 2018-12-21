package croquefer._BCMSUI.Panes;

import java.io.IOException;
import java.io.InputStream;
import java.sql.SQLException;
import java.util.ArrayList;

import com.FranckBarbier.Java._BCMS.BCMS.Status;
import com.pauware.pauware_engine._Exception.Statechart_exception;

import croquefer._BCMSUI.BCMSUI;
import croquefer._BCMSUI.CoreController;
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
import javafx.fxml.FXMLLoader;
import javafx.geometry.NodeOrientation;
import javafx.scene.control.Alert;
import javafx.scene.control.ListView;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.Alert.AlertType;
import javafx.scene.control.Button;
import javafx.scene.control.ButtonType;
import javafx.scene.control.DialogEvent;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.VBox;
import javafx.scene.shape.MoveTo;
import javafx.util.Duration;

public class InterventionManagerPaneController
{
	@FXML private ListView<String> vehiclesList;
	public static ListView<String> vehiclesListStatic;
	public static AnchorPane mapPane;
	private static Image sprite;
	private static final double travelTime=15.0;
	public static ArrayList<PathTransition> pathTransitions;
	private static Alert breakdownDialog;
	private static PathTransition breakdownPathTransition;
	private static int breakdownDialogState=0;
	
	public static void initialize() 
	{
		try 
		{
			//Add vehicles to list
			ObservableList<String> list=FXCollections.observableArrayList ();
			Class<?> cl = InterventionManagerPaneController.class;
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
		 
			sprite=new Image(input,50.0,50.0,true,true);
			pathTransitions = new ArrayList<PathTransition>();
			for(int i=0, delay=0; i<size; i++, delay+=3)
			{
				pathTransitions.add(createVehicle(delay));
			}
			
			    
		    
		} 
		catch (SQLException e) 
		{
			e.printStackTrace();
		}

		
		
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
					pathTransitions.get(i).play();
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
					pathTransitions.get(i).pause();
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
		String selected=(String)vehiclesList.getSelectionModel().getSelectedItem();
		for(int i=0; i<vehiclesList.getItems().size(); i++)
		{
			if(vehiclesList.getItems().get(i).equals(selected))
			{
				breakdownPathTransition=pathTransitions.get(i);
				breakdownPathTransition.pause();		
			}
		}
		
		breakdownDialog = new Alert(AlertType.WARNING);
		breakdownDialog.setTitle("Assistant de mise hors-service");
		breakdownDialog.getDialogPane().setContent(new Label("Etes vous sur de vouloir déclarer ce véhicule hors-service ?"));
		breakdownDialog.getDialogPane().getButtonTypes().remove(ButtonType.OK);
		breakdownDialog.getDialogPane().getButtonTypes().add(ButtonType.NEXT);	
		breakdownDialog.getDialogPane().getButtonTypes().add(ButtonType.CANCEL);
		final Button nextButton = (Button) breakdownDialog.getDialogPane().lookupButton(ButtonType.NEXT);
		nextButton.setText("Oui");
		nextButton.setDefaultButton(false);
		nextButton.addEventFilter(ActionEvent.ACTION,new EventHandler<ActionEvent>() 
		{
			@SuppressWarnings("unchecked")
			@Override
			public void handle(ActionEvent event) 
			{
				try 
				{
					if(breakdownDialogState==0)
					{
						event.consume();
						breakdownDialog.setAlertType(AlertType.CONFIRMATION);
						if(BCMSUI.bCMS.get_fire_trucks_unused().size()!=0)
						{
							breakdownDialog.getDialogPane().setContent(new Label("Voulez vous envoyer une autre unité en remplacement ?"));
							
						}
						else
						{
							final Button cancelButton = (Button) breakdownDialog.getDialogPane().lookupButton(ButtonType.CANCEL);
							cancelButton.fire();
						}

					}
					else if(breakdownDialogState==1)
					{
						event.consume();
						breakdownDialog.setAlertType(AlertType.NONE);
						
						final Button cancelButton = (Button) breakdownDialog.getDialogPane().lookupButton(ButtonType.CANCEL);
						cancelButton.setText("Annuler");
						
						final Button nextButton = (Button) breakdownDialog.getDialogPane().lookupButton(ButtonType.NEXT);
						nextButton.setText("Valider");
											
						VBox vehiclesManager = (VBox)FXMLLoader.load(getClass().getResource("../Utilities/VehiclesManager.fxml"));
						breakdownDialog.getDialogPane().setContent(vehiclesManager);
						breakdownDialog.getDialogPane().getScene().getWindow().sizeToScene();
						
						
						ObservableList<String> list;		
						if(BCMSUI.currentService.equals(Service.Pompier))
						{
							breakdownDialog.getDialogPane().setStyle("-fx-background-color: red;");
							list=FXCollections.observableArrayList(BCMSUI.bCMS.get_fire_trucks_unused());
						}
						else
						{
							breakdownDialog.getDialogPane().setStyle("-fx-background-color: blue;");
							list=FXCollections.observableArrayList(BCMSUI.bCMS.get_police_vehicles_unused());
						}
						
						//Initializing VehiclesController
						ListView<String> idleList = (ListView<String>) breakdownDialog.getDialogPane().getScene().lookup("#idleList");						
						idleList.setItems(list);
						idleList.getSelectionModel().setSelectionMode(SelectionMode.MULTIPLE);
						Label countLabel = (Label) breakdownDialog.getDialogPane().lookup("#countLabel");	
						countLabel.setText("1");

					}
					else
					{
						ListView<String> dispatchedList=(ListView<String>) breakdownDialog.getDialogPane().lookup("#dispatchedList");
						
						if(dispatchedList.getItems().size()==1)
						{
							try 
							{
								if(BCMSUI.currentService.equals(Service.Pompier))
								{								
									BCMSUI.bCMS.breakdown_fire_truck(selected, dispatchedList.getItems().get(0));
								}
								else
								{
									BCMSUI.bCMS.breakdown_police_vehicle(selected, dispatchedList.getItems().get(0));
									
								}
								pathTransitions.add(createVehicle(0));
								vehiclesListStatic.getItems().add(dispatchedList.getItems().get(0));
								removeVehicle(breakdownPathTransition);
								breakdownDialogState=0;
							}
							catch (SQLException e) 
							{
								e.printStackTrace();
							}
						}
						else
						{
							event.consume();
							Alert alert = new Alert(AlertType.WARNING);
				            alert.setTitle("Avertissement");
				            alert.setHeaderText("Vous n'avez pas envoyé le bon nombre d'unités.");
				            alert.show();
						}

					}
					breakdownDialogState++;
				}
				catch (SQLException | IOException e) 
				{
					e.printStackTrace();
				}
				
			}			         
		});
		
		final Button cancelButton = (Button) breakdownDialog.getDialogPane().lookupButton(ButtonType.CANCEL);
		cancelButton.setText("Non");
		cancelButton.setDefaultButton(true);
		cancelButton.addEventFilter(ActionEvent.ACTION,new EventHandler<ActionEvent>() 
		{
			@Override
			public void handle(ActionEvent event) 
			{
				if(breakdownDialogState==0)
				{
					breakdownPathTransition.play();
				}
				else 
				{
					String selected=(String)vehiclesList.getSelectionModel().getSelectedItem();
					try 
					{
						if(BCMSUI.currentService.equals(Service.Pompier))
						{
							BCMSUI.bCMS.breakdown_fire_truck(selected, "");
						}
						else
						{
							BCMSUI.bCMS.breakdown_police_vehicle(selected, "");
						}		
						removeVehicle(breakdownPathTransition);
					} catch (SQLException e) 
					{
						e.printStackTrace();
					}
					showErrorMessage();
					breakdownDialogState=0;
				}
			}			         
		});
		breakdownDialog.show(); 

	}
	
	public static PathTransition createVehicle(int delay)
	{
		PathTransition result=new PathTransition();
		ImageView image=new ImageView(sprite);
		image.setNodeOrientation(NodeOrientation.RIGHT_TO_LEFT);
		MoveTo firstDirection=(MoveTo) RoutePaneController.routes[RoutePaneController.currentRouteIndex].getPath().getElements().get(0);
		if(Route.getStartPoint().getKey()>Route.getEndPoint().getKey() && firstDirection.getX()==Route.getStartPoint().getKey())
		{
			image.setScaleY(-1);
		}
		image.setVisible(false);
		mapPane.getChildren().add(image);
		result.setDuration(Duration.seconds(travelTime));
		result.setPath(RoutePaneController.routes[RoutePaneController.currentRouteIndex].getPath());
		result.setNode(image);
		result.setOrientation(PathTransition.OrientationType.ORTHOGONAL_TO_TANGENT);
		result.setDelay(Duration.seconds(delay));
		result.play();
		result.currentTimeProperty().addListener(new DurationListener(image));
		result.setOnFinished(new EventHandler<ActionEvent>()
		{

			@Override
			public void handle(ActionEvent event) 
			{
				try 
				{	
					PathTransition path = (PathTransition) event.getSource();
					removeVehicle(path);
					
					
					if(vehiclesListStatic.getItems().size()==0)
					{
						showSuccessMessage();
					}
					
				}
				catch (SQLException e) 
				{
					e.printStackTrace();
				}
			}					
		});
		return result;
	}

	public static void removeVehicle(PathTransition path) throws SQLException
	{

		for(int i=0; i<pathTransitions.size(); i++)
		{
			
			if(path.equals(pathTransitions.get(i)))
			{
				if(BCMSUI.currentService.equals(Service.Pompier))
				{
					BCMSUI.bCMS.arrive_fire_truck(vehiclesListStatic.getItems().get(i));
				}
				else
				{
					BCMSUI.bCMS.arrive_police_vehicle(vehiclesListStatic.getItems().get(i));
				}
				vehiclesListStatic.getItems().remove(vehiclesListStatic.getItems().get(i));									
			}
		}
		path.stop();
		pathTransitions.remove(path);
		
	}
	
	private static void showSuccessMessage()
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
					CoreController.cleanup();
				} 
				catch (Statechart_exception e) 
				{
					e.printStackTrace();
				}
		
			}
		});
		alert.show();
	}

	private static void showErrorMessage()
	{
		Alert alert = new Alert(AlertType.ERROR);
		alert.setTitle("Nombre de véhicule insuffisant");
		alert.setContentText("L'alerte n'a pas pu être traitée");
		alert.setOnHidden(new EventHandler<DialogEvent>() 
		{
	
			@Override
			public void handle(DialogEvent event) 
			{
				CoreController.cleanup();
		
			}
		});
		alert.show();
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
