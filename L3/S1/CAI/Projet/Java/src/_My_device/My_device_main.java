package _My_device;

public class My_device_main extends javafx.application.Application {

    @Override
    public void start(javafx.stage.Stage stage) throws Exception {
        stage.setScene(new javafx.scene.Scene(javafx.fxml.FXMLLoader.load(getClass().getResource("My_device_GUI.fxml"))));
        // stage.setScene(new javafx.scene.Scene(javafx.fxml.FXMLLoader.load(getClass().getClassLoader().getResource("_My_device/My_device_GUI.fxml"))));
        stage.setTitle("PauWare engine software (www.PauWare.com) - \"My device\" case study (simulator) - Click on \"START\" to start...");
        stage.getIcons().add(new javafx.scene.image.Image(new java.io.File("_My_device/_My_device/Images/favicon.ico").toURI().toString()));
        stage.setResizable(false);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
