package tp5;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Slider;
import javafx.scene.control.ToggleButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class TemperatureUI extends Application
{
	
	public void start(Stage primaryStage)
	{	
		Temperature temperature=new Temperature(40., 'F');
		primaryStage.setTitle("Gestionnaire de température");
		Group root = new Group();
		Scene scene = new Scene(root, 300, 250, Color.LIGHTBLUE);
		
		Text minLabel=new Text("40");
		Text minUnitLabel=new Text("°F");
		
		Slider temperatureSlider=new Slider(277.594, 305.372, 277.594);
		temperatureSlider.setBlockIncrement(temperature.getStep());
		
		Text maxLabel=new Text("90");
		Text maxUnitLabel=new Text("°F");
		
		ToggleButton celsiusButton = new ToggleButton("°C");
		ToggleButton fahrenheitButton = new ToggleButton("°F");
		ToggleGroup unitGroup = new ToggleGroup();
		celsiusButton.setToggleGroup(unitGroup);
		fahrenheitButton.setToggleGroup(unitGroup);
		fahrenheitButton.setSelected(true);
		
		HBox sliderLine = new HBox();
		
		sliderLine.getChildren().add(minLabel);
		sliderLine.getChildren().add(minUnitLabel);
		sliderLine.getChildren().add(temperatureSlider);
		sliderLine.getChildren().add(maxLabel);
		sliderLine.getChildren().add(maxUnitLabel);
		sliderLine.getChildren().add(celsiusButton);
		sliderLine.getChildren().add(fahrenheitButton);
		
		Text currentTemperature = new Text("40");
		Text currentTemperatureUnit = new Text("°F");
		HBox currentTemperatureLine = new HBox();
		
		currentTemperatureLine.getChildren().add(currentTemperature);
		currentTemperatureLine.getChildren().add(currentTemperatureUnit);	
		
		VBox mainLayout = new VBox();
		
		mainLayout.getChildren().add(sliderLine);
		mainLayout.getChildren().add(currentTemperatureLine);
	
		root.getChildren().add(mainLayout);	


		celsiusButton.setOnAction(new EventHandler<ActionEvent>() 
		{
			public void handle(ActionEvent event) 
			{
				minUnitLabel.setText("°C");
				minLabel.setText("4.44");
				maxUnitLabel.setText("°C");
				maxLabel.setText("32.22");
				currentTemperatureUnit.setText("°C");
				currentTemperature.setText(String.format("%.2f", temperature.getAsCelsius()));
			}
		});
		
		fahrenheitButton.setOnAction(new EventHandler<ActionEvent>() 
		{
			public void handle(ActionEvent event) 
			{
				minUnitLabel.setText("°F");
				minLabel.setText("40");
				maxUnitLabel.setText("°F");
				maxLabel.setText("90");
				currentTemperatureUnit.setText("°F");
				currentTemperature.setText(String.format("%.2f", temperature.getAsFahrenheit()));
			}
		});
		
		temperatureSlider.valueProperty().addListener(new ChangeListener<Number>() 
		{
            public void changed(ObservableValue<? extends Number> ov,  Number old_val, Number new_val) 
            {
            	System.out.println(temperature.getAsKelvin());
            	System.out.println(new_val);
            	if(new_val.doubleValue()-old_val.doubleValue()<0)
            	{
            		temperature.decrement();
            	}
            	else
            	{
            		temperature.increment();
            	}
            	if ((ToggleButton) unitGroup.getSelectedToggle()==celsiusButton)
            	{
                    currentTemperature.setText(String.format("%.2f", temperature.getAsCelsius()));
            	}
            	else
            	{
            		currentTemperature.setText(String.format("%.2f", temperature.getAsFahrenheit()));
            	}

            }
        });
 
		
		
     
		//ToggleButton selectedToggleButton =(ToggleButton) toggleGroup.getSelectedToggle();
		
		primaryStage.setScene(scene);
		primaryStage.show();
	}
}
