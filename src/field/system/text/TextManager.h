package field.system.text;

import core.Runtime;

public class TextManager {
	/**
	*	Changes between the primary/alternate text buffers.
	*/
	static native void MsgSwap();
	
	/**
	*	Loads a text file into a text buffer.
	*	
	*	@param isScrText True if the desired text file is in the Script Message GARC.
	*	@param textId ID of the text file to load. This is NOT a GARC index, rather a special identifier specified in the MsgLoad subroutine switch-case block in DllField.cro.
	*/
	static native void MsgLoad(boolean isScrText, int textId);
	
	/**
	*	Checks if all text file load request have finished.
	*/
	static native boolean MsgIsLoaded();

	static void MsgLoadAndWait(boolean isScrText, int textId) {
		MsgLoad(isScrText, textId);

		while (!MsgIsLoaded()) {
			Runtime.sleep(1);
		}
	}
	
	/**
	*	Drops any text files in the current text buffer.
	*/
	static native void MsgRelease();
}