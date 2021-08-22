package field.event.dialog;

import core.Runtime;
import field.event.dialog.DialogCommon;

public class ListMenu {
	/**
	*	Initializes a ListMenu dialog.
	*
	*	@param x X location of the dialog on the screen. The origin point is at the center of the screen and the dialog is anchored with its right edge.
	*	@param y Y location of the dialog on the screen. The origin point is at the center of the screen and the dialog is anchored with its top edge.
	*	@param selectedIndex Index of the default selected option.
	*	@param isCancellable True if the player should be able to cancel the ListMenu using the B button, defaulting the result to the last option.
	*	@param alignRight True if the text inside the list menu should be anchored to the right side of the dialog.
	*
	*	@return True if the list menu has finished initializing.
	*/
	static native boolean ListMenuInit_Seq(int x, int y, int selectedIndex, boolean isCancellable, boolean alignRight, boolean a6);

	/**
	*	Adds a message to the specified index of a ListMenu.
	*
	*	@param msgId The Line number in the currently loaded text file.
	*	@param index The index of the resulting ListMenu element.
	*/
	static native void ListMenuAdd(int msgId, int index, int unknown);

	/**
	*	Displays a previously defined ListMenu window.
	*	This method has to be called every frame until an option is selected.
	*
	*	@return True if the player has selected and confirmed a menu option.
	*/
	static native boolean ListMenuStart_Seq();

	/**
	*	Initializes a ListMenu dialog and blocks until the request has finished.
	*
	*	@param x X location of the dialog on the screen. The origin point is at the center of the screen and the dialog is anchored with its right edge.
	*	@param y Y location of the dialog on the screen. The origin point is at the center of the screen and the dialog is anchored with its top edge.
	*	@param selectedIndex Index of the default selected option.
	*	@param isCancellable True if the player should be able to cancel the ListMenu using the B button, defaulting the result to the last option.
	*	@param alignRight True if the text inside the list menu should be anchored to the right side of the dialog.
	*/
	static void ListMenuPrepare(int x, int y, int selectedIndex, boolean isCancellable, boolean alignRight){
		while (!ListMenuInit_Seq(x, y, selectedIndex, isCancellable, alignRight, false)){
			Runtime.sleep(1);
		}
	}

	/**
	*	Waits until the player chooses a ListMenu dialog option.
	*
	*	@return Index of the selected menu option.
	*/
	static int ListMenuWaitGet(){
		while (!ListMenuStart_Seq()){
			Runtime.sleep(1);
		}
		return ListMenuResultGet();
	}

	/**
	*	Gets the result of a completed ListMenu sequence from the reserved work value.
	*
	*	@return Index of the selected ListMenu element, read from WKID_LISTMENU_RESULT.
	*/
	static int ListMenuResultGet() {
		return DialogCommon.DialogResultGet();
	}
}