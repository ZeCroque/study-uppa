package croquefer._BCMSUI.Utilities;

import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.ListView;

public class VehiclesManagerController
{
	@FXML private ListView<String> idleList;
	@FXML private ListView<String> dispatchedList;
	
	public void dispatchButtonController(ActionEvent event)
	{
		ObservableList<String> selectedItems=idleList.getSelectionModel().getSelectedItems();
	
		dispatchedList.getItems().addAll(selectedItems);

		idleList.getItems().removeAll(selectedItems);
		
	}
	
	public void undispatchButtonController(ActionEvent event)
	{
		ObservableList<String> selectedItems=dispatchedList.getSelectionModel().getSelectedItems();
	
		idleList.getItems().addAll(selectedItems);

		dispatchedList.getItems().removeAll(selectedItems);
	}
	
}
