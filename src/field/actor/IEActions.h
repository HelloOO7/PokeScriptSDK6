package field.actor;

import field.actor.ActionCmd;
import field.actor.Direction;

public class IEActions {
	/**
	*	Queues an Action Command for a MoveModel that is controlled by an Interactive Event.
	*
	*	@param actor The IE Actor ID.
	*	@param acmd The Action Command ID.
	*	@param dir Movement direction of the Action.
	*	@param amount Length/repeat count of the Action.
	*/
	static native void IEMdlAcmdSet(int actor, ActionCmd acmd, Direction dir, int amount);

	static native boolean IEMdlAcmdIsEnd(int actor);

	static native void IEMdlAcmdSetByRoute(int actor, int a2, int a3, int a4); //unused method
}