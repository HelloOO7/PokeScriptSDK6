package field.event.dialog;

public class DialogUI {
	/**
	*	Displays the "press a button" icon on the current message dialog.
	*/
	static native void SetKeyWaitMark();

	/**
	*	Hides the "press a button" icon on the current message dialog.
	*/
	static native void VanishKeyWaitMark();

	/**
	*	Displays the loading spinner on the current message dialog.
	*/
	static native void SetTimerIcon();

	/**
	*	Hides the loading spinner on the current message dialog.
	*/
	static native void VanishTimerIcon();
}