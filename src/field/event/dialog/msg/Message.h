package field.event.dialog.msg;

import field.event.dialog.msg.MsgFrame;
import field.event.dialog.msg.MsgFlags;
import core.Input;
import field.event.dialog.DialogCommon;
import field.event.dialog.DialogUI;

public class Message {
	static final int MSGWIN_NO_AUTOHIDE = -1;

	/**
	*	The juggernaut function to display a message window with various parameters.
	*	This function holds the record for the highest number of arguments in Pokémon with a whopping 19.
	*
	*	@param msgId Index of the message line in the currently loaded text file.
	*	@param windowNo The window unit to bind the message dialog to.
	*	@param actor ID of an Actor to bind the window to, or Actor.ACTOR_CURRENT_SCROBJ
	*	@param frame The frame style to be used for the window.
	*	@param winX X location of the windows if MsgFlags.FRAME_NOATTACH is enabled.
	*	@param winY Y location of the windows if MsgFlags.FRAME_NOATTACH is enabled.
	*	@param attachOfsSrc If attachIsAbs, the value of this parameter scrolls the attachment sprite's inner end around the message box.
	*	@param attachOfsTgt If attachIsAbs, the value of this parameter scrolls the attachment sprite's outer end around the message box.
	*	@param winIsAbs If true, the message window uses absolute coordinates. It is not know how those are set.
	*	@param attachIsAbs If true, the attachment sprite uses absolute coordinates instead of being dynamically bound to an Actor.
	*	@param attachIsActor If true, attaches the message bubble to the Actor specified with target.
	*	@param autoHideFrames If not set to MSGWIN_NO_AUTOHIDE, the window will close automatically after autoHideFrames frames.
	*	@param flags Bitflags that further control the window's behavior, like alignment and positioning.
	*/
	native void TalkMdlMsg_Seq(int msgId, int windowNo, int actor, MsgFrame frame, int winX, int a6, int winY, int a8, int a9, int a10, int attachOfsSrc, int attachOfsTgt, int a13, boolean winIsAbs, boolean attachIsAbs, boolean attachIsActor, int autoHideFrames, int a18, MsgFlags flags);

	static void ShowMessageBox(int msgId, int actor, MsgFrame frame, int autoHideFrames, MsgFlags flags, boolean continuous) {
		TalkMdlMsg_Seq(msgId, 0, actor, frame, 0, 0, 0, 0, 0, 0, 0, 0, 0, false, false, true, autoHideFrames, 0, flags);

		if ((flags & MsgFlags.SYS_SKIP_WAIT_FOR_WINDOW_RT) == 0) {
			DialogCommon.WaitForWindowLoad();
		}

		if (autoHideFrames != MSGWIN_NO_AUTOHIDE) {
			if (continuous) {
				DialogUI.SetKeyWaitMark();
				Input._ABKeyWait();
				DialogUI.VanishKeyWaitMark();
			}
			else {
				Input.LastKeyWait();
			}
			
			DialogCommon.MsgWinAllClose();
		}
	}
}