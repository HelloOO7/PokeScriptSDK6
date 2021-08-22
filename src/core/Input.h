package core;

import core.InputAxis;
import core.KeyCode;

public class Input {
	/**
	*	Gets a bit set of all pressed buttons on the console.
	*/
	static native KeyCode GetKeyCont();

	/**
	 * 	Gets a bit set of all held axes of the control pad.
	 */
	static native InputAxis GetStickHold();

	#ifdef SANGO
	/**
	 * 	Checks if any of the keys of a keycode mask, or the control stick, or the touchscreen, have just been pressed.
	 * 	Hold/release events are ignored.
	 * 	
	 * 	@param keycodes A bitflags mask of the keycodes that can be pressed to trigger a positive return.
	 * 	@param allowStick True if the Circle Pad can trigger a positive return.
	 * 	@param allowTouchscreen True if a touchscreen tap can trigger a positive return.
	 * 	
	 * 	@return True if any of the defined conditions are met by the immediate user input.
	 */
	static native boolean IsKeyTrigger(KeyCode keycodes, boolean allowStick, boolean allowTouchscreen);
	#endif

	/**
	*	Blocks until the player presses the A or B button.
	*/
	static native void _ABKeyWait();

	/**
	*	Blocks until the player presses the "last" button - one of the buttons eligible to terminate a sequence, e.g. AB or the direction keys.
	*/
	static native void LastKeyWait();
}