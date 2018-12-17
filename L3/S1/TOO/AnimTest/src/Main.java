
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.TitledPane;
import javafx.scene.paint.Color;

import javafx.stage.Stage;

public class Main extends Application {

  @Override
  public void start(final Stage stage) throws Exception {
    final TitledPane routePane = (TitledPane)FXMLLoader.load(getClass().getResource("RoutePane.fxml"));
    final Scene scene = new Scene(routePane, 600, 400, Color.GHOSTWHITE);
    stage.setScene(scene);
    stage.setTitle("JavaFX 2 Animations");
    stage.show();
  }

  public static void main(final String[] arguments) {
    Application.launch(arguments);
  }
}