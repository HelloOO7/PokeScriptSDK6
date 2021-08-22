package field.event.dialog;

import core.Runtime;
import field.event.dialog.DialogCommon;

public class YesNoWin {
	/**
	*	Shows the Yes/No dialog or checks its state if it's already displayed.
	*	The result is stored into a static Work value.
	*
	*	@param useCustomText If true, the dialog uses further specified dialogue options instead of generic "Yes/No" answers.
	*	@param customMsgIdYes MsgId line replacement of the generic "Yes" option if useCustomText is enabled.
	*	@param customMsgIdNo MsgId line replacement of the generic "No" option if useCustomText is enabled.
	*	@param isNoDefault If true, the cursor starts at the No option by default.
	*
	*	@return False if the window query has not yet been answered, true if an option has been selected and confirmed.
	*/
	native boolean YesNoWin_Seq(boolean useCustomText, int customMsgIdYes, int customMsgIdNo, boolean isNoDefault);

	/**
	*	Shows a Yes/No dialog and waits until the player chooses an option.
	*/
	static int YesNoWinPopup() {
		return YesNoWinPopup(false, 0, 0, false);
	}

	/**
	*	Shows a Yes/No dialog and waits until the player chooses an option.
	*
	*	@param isNoDefault If true, the cursor starts at the No option by default.
	*/
	static int YesNoWinPopup(boolean isNoDefault) {
		return YesNoWin_Seq(false, 0, 0, isNoDefault);
	}

	/**
	*	Shows a Yes/No dialog and waits until the player chooses an option.
	*
	*	@param useCustomText If true, the dialog uses further specified dialogue options instead of generic "Yes/No" answers.
	*	@param customMsgIdYes MsgId line replacement of the generic "Yes" option if useCustomText is enabled.
	*	@param customMsgIdNo MsgId line replacement of the generic "No" option if useCustomText is enabled.
	*	@param isNoDefault If true, the cursor starts at the No option by default.
	*
	*	@return True if the Yes option has been selected, false if otherwise.
	*/
	static int YesNoWinPopup(boolean useCustomText, int customMsgIdYes, int customMsgIdNo, boolean isNoDefault){
		while (!YesNoWin_Seq(useCustomText, customMsgIdYes, customMsgIdNo, isNoDefault)){
			Runtime.sleep(1);
		}
		return YesNoWinResultGet();
	}

	/**
	*	Gets the result of a completed Yes/No dialog.
	*
	*	@return True if the Yes option has been selected, false if otherwise.
	*/
	static int YesNoWinResultGet() {
		return DialogCommon.DialogResultGet();
	}
}