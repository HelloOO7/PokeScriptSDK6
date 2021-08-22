package field.event.dialog;

public class InputDialog {
	#ifdef SANGO
	/**
	 *	Requests the player to enter a text string.
	 *	
	 *	@param successWork Work value to store the dialog result into. Unused.
	 *	@param mode Type of the requested text string, f.e. a greeting.
	 *	@param fade True if the dialog should automatically fade in and out.
	 *	@param enableDefaultValue True if the mode's default text value should take effect, false to start with a clean slate.
	 */
	static native void CallFreeWordInput(int successWork, int mode, boolean fade, boolean enableDefaultValue);
	#endif

	#ifdef XY
	/**
	 * 	Requests the player to enter a nickname by which their rivals should call them.
	 */
	static native void PlayerNicknameCallInput();

	/**
	 * 	Binds the input nickname to the player name.
	 */
	static native void PlayerNicknameInputFix();

	/**
	 * 	Binds one of the default nicknames to the player name.
	 * 	
	 * 	@param msgId MSGID of the nickname suffix in the nickname text file.
	 */
	static native void PlayerNickNameSelectFix(int msgId);
	#endif
}