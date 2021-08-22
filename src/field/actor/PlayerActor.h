package field.actor;

import field.actor.Direction;

public class PlayerActor {
	/**
	 * 	Actor ID of the player model.
	 */
	static final int ACTOR_PLAYER				=	  255;

	/**
	 * 	Gets the player model form/costume.
	 * 	
	 * 	@return ID of the current player form.
	 */
	static native int PlayerGetForm();

	/**
	 *	Resets the player model to the basic forme.
	 *	
	 *	@param dir Player model direction after the operation.
	 */
	static native void PlayerSetFormToNormalForce(Direction dir);

	/**
	 *	Gets the X coordinate of the tile in front of the player.
	 */
	static native int PlayerGetFrontGridPosX();

	/**
	 *	Gets the Y coordinate of the tile in front of the player.
	 */
	static native int PlayerGetFrontGridPosY();

	/**
	 *	Gets the Z coordinate of the tile in front of the player.
	 */
	static native int PlayerGetFrontGridPosZ();

	/**
	 * 	Gets the inverse of the player's facing direction.
	 * 	For example, this method would return SOUTH if the player is facing approximately NORTH.
	 */
	static native Direction PlayerGetReturnDir();

	/**
	 *	Turns the player model to face an Actor. Behaves the same as setting the orientation to PlayerGetReturnDir().
	 *	This method is unused.
	 *	
	 *	@param actor The actor to turn towards.
	 */
	static native void PlayerTurnToObj(int actor);

	#ifdef SANGO
	/**
	 * 	Attaches the Devon Scope sub-object to the player model.
	 */
	static native void PlayerAttachDebonScope();

	/**
	 * 	Detaches the Devon Scope sub-object from the player model.
	 */
	static native void PlayerDetachDebonScope();
	#endif
}