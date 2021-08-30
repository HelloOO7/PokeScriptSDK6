package field.actor;

import field.actor.ActionCmd;
import field.actor.ActionFlags;
import field.actor.Direction;
import field.actor.ActorCollisions;
import field.actor.DirectionLimit;
import core.Runtime;

public class Actions {

	/**
	*	Clears the action command queue.
	*/
	static native void AcmdListClear();

	/**
	*	Opens the Action Command queue for a given MoveModel.
	*
	*	@param target The MoveModel to control.
	*/
	static native void MdlAcmdInit(int target);

	#ifdef SANGO
	/**
	*	Queues an Action Command for a MoveModel.
	*
	*	@param acmd The Action Command ID.
	*	@param dir Movement direction of the Action.
	*	@param amount Length/repeat count of the Action.
	*	@param allowTurnAcmd If the model supports the motions required for turn actions, they will be used instead of generic rotation.
	*/
	static native void MdlAcmdSet(ActionCmd acmd, Direction dir, int amount, boolean allowTurnAcmd);
	#else if XY
	/**
	*	Queues an Action Command for a MoveModel.
	*
	*	@param acmd The Action Command ID.
	*	@param dir Movement direction of the Action.
	*	@param amount Length/repeat count of the Action.
	*/
	static native void MdlAcmdSet(ActionCmd acmd, Direction dir, int amount);
	#endif

	#ifdef SANGO
	/**
	*	Queues an Action Command for a MoveModel, allowing for TURN action commands where possible.
	*
	*	@param acmd The Action Command ID.
	*	@param dir Movement direction of the Action.
	*	@param amount Length/repeat count of the Action.
	*/
	static void MdlAcmdSet(ActionCmd acmd, Direction dir, int amount) {
		MdlAcmdSet(acmd, dir, amount, true);
	}
	#endif


	/**
	*	Flushes the currently active Action Command queue to the Actor set with MdlAcmdInit.
	*/
	static native void MdlAcmdSetEnd();

	/**
	 * 	Flushes the currently active Action Command queue to a specific Actor.
	 * 	This function is unused.
	 * 	
	 * 	@param actor The Actor to apply the commands to.
	 */
	static native void MdlAcmdSetToOtherMdl(int actor);

	/**
	 * 	Asynchronously closes an Actor's Action Command queue.
	 * 	
	 * 	@param actor ID of the actor.
	 */
	static native void MdlAcmdEndRequest(int actor);

	/**
	 * 	Checks if all asynchronous Action Command queue terminations have finished.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	
	 * 	@return True if all command MdlAcmdEndRequest functions have returned.
	 */
	static native boolean MdlAcmdEndWait(int actor);

	/**
	*	Check if and Actor has executed all Actions.
	*
	* 	@param actor ID of the Actor, or Actor.ACTOR_CURRENT_SCROBJ.
	*	@return True if the Actor has finished executing its Action Command queue.
	*/
	static native boolean MdlAcmdUpdate(int actor);

	/**
	 * 	Blocks until an Actor has executed all Actions.
	 * 	
	 * 	@param actor ID of the Actor, or Actor.ACTOR_CURRENT_SCROBJ.
	 */
	static void MdlAcmdWaitUpdate(int actor) {
		while (!MdlAcmdUpdate(actor)) {
			Runtime.sleep(1);
		}
	}

	/**
	*	Calculates a path to a given location and moves the NPC to it through an Action Command.
	*
	*	@param acmd The Action Command to walk with.
	*	@param destX X coordinate of the target tile.
	*	@param destY Y height of the target tile (ignored).
	*	@param destZ Z coordinate of the target tile.
	*	@param coll Collision rules that the path calculation should respect.
	*	@param mirrorDirTable True to use an alternate direction table.
	*	@param dirLimit Determines which set of directions the Actor should be allowed to use.
	*/
	static native void MdlAcmdMakeMoveEx(ActionCmd acmd, int destX, int destY, int destZ, ActorCollisions coll, boolean mirrorDirTable, DirectionLimit dirLimit);

	/**
	*	Internal function for Actor path-finding that allows moving actors between two locations along an automatically calculated path.
	*	Since action commands are relative, the source coordinates are used solely for the calculation, NOT for placing the Actor.
	*	If the Actor is at a position that is not equal to this function's parameters, the movement will be desynchronized.
	*
	*	@param acmd The Action Command to walk with.
	*	@param destX X coordinate of the target tile.
	*	@param destY Y height of the target tile (ignored).
	*	@param destZ Z coordinate of the target tile.
	*	@param srcX X coordinate of the source tile.
	*	@param srcY Y height of the source tile (ignored).
	*	@param srcZ Z coordinate of the source tile.
	*	@param coll Collision rules that the path calculation should respect.
	*	@param mirrorDirTable True to use an alternate direction table.
	*	@param dirLimit Determines which set of directions the Actor should be allowed to use.
	*/
	static native void _MdlAcmdMakeMoveCore(ActionCmd acmd, int destX, int destY, int destZ, int srcX, int srcY, int srcZ, ActorCollisions coll, boolean mirrorDirTable, DirectionLimit dirLimit);
}