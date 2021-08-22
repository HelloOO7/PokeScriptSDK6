package field.event.dialog;

import field.system.EventWork;
import core.Runtime;

public class DialogCommon {
	static final int WKID_DIALOG_RESULT = 0x8010;

	/**
	*	Gets the result of a completed dialog sequence from the reserved work value.
	*
	*	@return Dialog-specific result value.
	*/
	static int DialogResultGet() {
		return EventWork.WorkGet(WKID_DIALOG_RESULT);
	}

	/**
	 * 	Checks if all requested windows have opened.
	 * 	
	 * 	@return True if all windows are loaded and visible.
	 */
	static native boolean CheckWinAllSuspend();

	/**
	 * 	Blocks until all requested windows have opened.
	 */
	static void WaitForWindowLoad() {
		while (!CheckWinAllSuspend()) {
			Runtime.sleep(1);
		}
	}

	/**
	 * 	Closes a specific dialog window.
	 * 	
	 * 	@param windowId ID of the window to be closed, as specified in the method that created it.
	 */
	static native void MsgWinCloseNo(int windowId);

	/**
	 * 	Closes the main dialog window.
	 * 	This method is equivalent to MsgWinCloseNo(0)
	 */
	static native void MsgWinClose();

	/**
	 * 	Closes all active dialogs.
	 */
	static native void MsgWinAllClose();
}