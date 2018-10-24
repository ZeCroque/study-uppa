package _My_device;

public class My_device_GUI implements javafx.fxml.Initializable {

    /**
     * PauWare engine
     */
    private My_device _my_device;

    private final java.util.Map<String, javafx.scene.shape.Shape[]> _states = new java.util.HashMap();

    @Override
    public void initialize(java.net.URL url, java.util.ResourceBundle rb) {
        _states.put("Idle", new javafx.scene.shape.Shape[]{_idle_shape});
        _states.put("Busy", new javafx.scene.shape.Shape[]{_busy_shape});
        _states.put("S1", new javafx.scene.shape.Shape[]{S1, S1bis});
        _states.put("S11", new javafx.scene.shape.Shape[]{S11});
        _states.put("S12", new javafx.scene.shape.Shape[]{S12});
        _states.put("S2", new javafx.scene.shape.Shape[]{S2, S2bis});
        _states.put("S21", new javafx.scene.shape.Shape[]{S21});
        _states.put("S22", new javafx.scene.shape.Shape[]{S22});
        _states.put("S3", new javafx.scene.shape.Shape[]{S3, S3bis});
        _states.put("S31", new javafx.scene.shape.Shape[]{S31});
        _states.put("S32", new javafx.scene.shape.Shape[]{S32});
        try {
            _my_device = new My_device();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
    }
    @javafx.fxml.FXML
    private javafx.scene.shape.Ellipse _idle_shape;
    @javafx.fxml.FXML
    private javafx.scene.shape.Rectangle _busy_shape, S1, S1bis, S11, S12, S2, S2bis, S21, S22, S3, S3bis, S31, S32;
    @javafx.fxml.FXML
    private javafx.scene.control.TextArea _verbose;
    @javafx.fxml.FXML
    private javafx.scene.image.ImageView _robot_brain, _start_button, _stop_button, _go_button, _request_b_button, _request_c_button, _request_d_button, _request_e_button, _request_f_button, _request_g_button;
    @javafx.fxml.FXML
    private javafx.scene.image.ImageView _robot_eye, _go_arrow, _request_b_arrow, _request_c_arrow, _request_c_2_arrow, _request_d_arrow, _request_e_arrow, _request_f_arrow, _request_g_arrow;

    /**
     * START
     */
    @javafx.fxml.FXML
    public void start(javafx.event.ActionEvent event) {
        try {
            _my_device.start();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        _robot_eye.setVisible(false);
        _robot_brain.setVisible(false);
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_start_button() {
        _start_button.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_start_button() {
        _start_button.setVisible(true);
    }

    /**
     * STOP
     */
    @javafx.fxml.FXML
    public void stop(javafx.event.ActionEvent event) {
        try {
            _my_device.stop();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        _robot_eye.setVisible(true);
        _robot_brain.setVisible(true);
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_stop_button() {
        _stop_button.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_stop_button() {
        _stop_button.setVisible(true);
    }

    /**
     * Go
     */
    @javafx.fxml.FXML
    public void go(javafx.event.ActionEvent event) {
        try {
            _my_device.go();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_go_button() {
        _go_button.setVisible(false);
        _go_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_go_button() {
        _go_button.setVisible(true);
        _go_arrow.setVisible(true);
    }

    @javafx.fxml.FXML
    public void mouse_over_go_arrow() {
        _go_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_go_arrow() {
        _go_arrow.setVisible(true);
    }

    /**
     * Request_b
     */
    @javafx.fxml.FXML
    public void request_b(javafx.event.ActionEvent event) {
        try {
            _my_device.request_b();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_request_b_button() {
        _request_b_button.setVisible(false);
        _request_b_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_b_button() {
        _request_b_button.setVisible(true);
        _request_b_arrow.setVisible(true);
    }

    @javafx.fxml.FXML
    public void mouse_over_request_b_arrow() {
        _request_b_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_b_arrow() {
        _request_b_arrow.setVisible(true);
    }

    /**
     * Request_c
     */
    @javafx.fxml.FXML
    public void request_c(javafx.event.ActionEvent event) {
        try {
            _my_device.request_c();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_request_c_button() {
        _request_c_button.setVisible(false);
        _request_c_arrow.setVisible(false);
        _request_c_2_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_c_button() {
        _request_c_button.setVisible(true);
        _request_c_arrow.setVisible(true);
        _request_c_2_arrow.setVisible(true);
    }

    @javafx.fxml.FXML
    public void mouse_over_request_c_arrow() {
        _request_c_arrow.setVisible(false);
        _request_c_2_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_c_arrow() {
        _request_c_arrow.setVisible(true);
        _request_c_2_arrow.setVisible(true);
    }

    /**
     * Request_d
     */
    @javafx.fxml.FXML
    public void request_d(javafx.event.ActionEvent event) {
        try {
            _my_device.request_d();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_request_d_button() {
        _request_d_button.setVisible(false);
        _request_d_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_d_button() {
        _request_d_button.setVisible(true);
        _request_d_arrow.setVisible(true);
    }

    @javafx.fxml.FXML
    public void mouse_over_request_d_arrow() {
        _request_d_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_d_arrow() {
        _request_d_arrow.setVisible(true);
    }

    /**
     * Request_e
     */
    @javafx.fxml.FXML
    public void request_e(javafx.event.ActionEvent event) {
        try {
            _my_device.request_e();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_request_e_button() {
        _request_e_button.setVisible(false);
        _request_e_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_e_button() {
        _request_e_button.setVisible(true);
        _request_e_arrow.setVisible(true);
    }

    @javafx.fxml.FXML
    public void mouse_over_request_e_arrow() {
        _request_e_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_e_arrow() {
        _request_e_arrow.setVisible(true);
    }

    /**
     * Request_f
     */
    @javafx.fxml.FXML
    public void request_f(javafx.event.ActionEvent event) {
        try {
            _my_device.request_f();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_request_f_button() {
        _request_f_button.setVisible(false);
        _request_f_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_f_button() {
        _request_f_button.setVisible(true);
        _request_f_arrow.setVisible(true);
    }

    @javafx.fxml.FXML
    public void mouse_over_request_f_arrow() {
        _request_f_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_f_arrow() {
        _request_f_arrow.setVisible(true);
    }

    /**
     * Request_g
     */
    @javafx.fxml.FXML
    public void request_g(javafx.event.ActionEvent event) {
        try {
            _my_device.request_g();
        } catch (Throwable t) {
            javafx.scene.control.Alert alert = new javafx.scene.control.Alert(javafx.scene.control.Alert.AlertType.INFORMATION);
            alert.setTitle("PauWare engine software (www.PauWare.com)");
            alert.setHeaderText(null);
            alert.setContentText("Fatal error: " + t.getMessage() + " - Shutdown...");
            alert.showAndWait();
            System.exit(-1);
        }
        update_GUI();
    }

    @javafx.fxml.FXML
    public void mouse_over_request_g_button() {
        _request_g_button.setVisible(false);
        _request_g_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_g_button() {
        _request_g_button.setVisible(true);
        _request_g_arrow.setVisible(true);
    }

    @javafx.fxml.FXML
    public void mouse_over_request_g_arrow() {
        _request_g_arrow.setVisible(false);
    }

    @javafx.fxml.FXML
    public void mouse_off_request_g_arrow() {
        _request_g_arrow.setVisible(true);
    }

    @javafx.fxml.FXML
    private void update_GUI() {
        _verbose.appendText("\n\n" + _my_device.verbose());
        String current_state = _my_device.current_state();
        java.util.Set<String> states = _states.keySet();
        for (String state : states) {
            javafx.scene.shape.Shape shapes[] = _states.get(state);
            if (current_state.contains(state)) {
                for (int index = 0; index < shapes.length; index++) {
                    shapes[index].setFill(javafx.scene.paint.Color.BURLYWOOD);
                }
            } else {
                for (int index = 0; index < shapes.length; index++) {
                    shapes[index].setFill(javafx.scene.paint.Color.WHITE);
                }
            }
        }
    }
}
