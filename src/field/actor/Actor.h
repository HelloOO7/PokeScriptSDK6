package field.actor;

import field.actor.Direction;

public class Actor {
	/**
	 * 	Reserved value that represents the Actor that invoked the currently running script.
	 */
	static final int ACTOR_CURRENT_SCROBJ 		= 	   -1;
	
	/**
	 * 	Finds an Actor by their overworld position.
	 * 	
	 * 	@param gridX X location on the grid.
	 * 	@param y World Y altitude.
	 * 	@param gridZ Z location on the grid.
	 * 	@param unused I'm fairly certain that this parameter does nothing. It sets a FPU register to Float.MAX_VALUE, but said value gets overwritten afterwards.
	 * 	@return ID of the found actor, or -1 if no actor was found.
	 */
	static native int MdlGetObjID(int gridX, int y, int gridZ, boolean unused);

	/**
	 * 	Finds an Actor by their OBJCODE.
	 * 	
	 * 	@param objCode The OBJCODE of the desired actor.
	 * 	@return ID of the found actor, or -1 if no actor was found.
	 */
	static native int MdlSearchByObjCode(int objCode);

	/**
	 * 	Checks if an Actor ID is a valid handle in the current zone.
	 * 	
	 * 	@param actor ID of the actor to check.
	 * 	@return True if the actor ID was resolved to an Actor.
	 */
	static native boolean MdlIsExists(int actor);

	/*
	 * 	SPAWN CONTROL.
	 */
	
	/**
	* 	Spawns an Actor model instance.
	* 	If the actor is already part of the scene, a duplicate will appear.
	* 	
	* 	@param actor ID of the actor to spawn.
	*/
	static native void MdlAdd(int actor);

	/**
	* 	Despawns an Actor model instance.
	* 	
	* 	@param actor ID of the actor to despawn.
	*/
	static native void MdlDel(int actor);

	/**
	* 	Despawns an Actor model instance that is bound to a Spawn Flag.
	* 	
	* 	@param flag The Spawn Flag of the Actor to despawn.
	*/
	static native void MdlDelByFlag(int flag);

	/*
	 * 	NPC PROPERTIES
	 */

	/**
	 * 	Gets the OBJCODE of an actor, accounting for work object codes.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@return The current model object code of the actor.
	 */
	static native int MdlGetObjCode(int actor);

	/**
	 * 	Gets the MoveCode of an actor.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@return The MoveCode value of the actor data.
	 */
	static native int MdlGetMoveCode(int actor);

	/**
	 * 	Changes an Actor's MoveCode.
	 * 	This function will fail on Actors with event types other than None(0) and AI(7).
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param moveCode The new MoveCode for the actor.
	 */
	static native void MdlChangeMoveCode(int actor, int moveCode);

	/**
	 * 	Gets the EvType of an actor.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@return The EvType value of the actor data.
	 */
	static native int MdlGetEventType(int actor);

	/**
	 * 	Checks if an Actor's EvType is the AI EvType.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@return True if the actor is set to use the AI EvType.
	 */
	static native boolean MdlEventTypeIsAI(int actor);

	/*
	 * DIRECTION AND POSITION
	 */

	/**
	 * 	Gets the current facing direction of an Actor.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@return The facing direction of the actor, or Direction.CURRENT if the actor could not be found.
	 */
	static native Direction MdlGetDirDisp(int actor);

	/**
	 * 	Gets the real-time facing direction of an Actor.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@return The direction derived from the real-time moving angle of the Actor, or Direction.CURRENT if the actor could not be found.
	 */
	static native Direction MdlGetDirMove(int actor);

	/**
	*	Sets the facing direction of an Actor.
	*
	*	@param target ID of the actor.
	*	@param dir The desired facing direction.
	*/
	static native void MdlSetDirDisp(int actor, Direction dir);

	/**
	*	Shows/hides an Actor.
	*
	*	@param actor ID of the Actor.
	*	@param visibility True if the actor should be visible, false if otherwise.
	*/
	static native void MdlSetVisible(int actor, boolean visibility);

	/**
	 * 	Checks if an Actor is currently on a rail track.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@return True if the Actor is on a rail, false if it is on the regular grid.
	 */
	static native boolean MdlIsRail(int actor);
	
	/**
	*	Gets an Actor's horizontal grid position.
	*
	*	@param actor ID of the Actor.
	*
	*	@return X grid position of target.
	*/
	static native int MdlGetGPosX(int actor);

	/**
	 * 	Gets the X position of a tile that is a given distance away from the actor in a direction.
	 * 	For example, dir = EAST and stride = 2 would return the X position of the tile 2 tiles to the right of the actor.
	 * 	
	 * 	@param dir The direction in which the tile should be from the actor.
	 * 	@param stride Distance between the actor and the tile in grid units.
	 * 	@param actor The actor to measure from.
	 * 	@return Calculated offset grid position.
	 */
	static native int MdlGetGPosDirX(Direction dir, int stride, int actor);

	/**
	 * 	Gets the Z position of a tile that is a given distance away from the actor in a direction.
	 * 	For example, dir = SOUTH and stride = 3 would return the Z position of the tile 3 tiles under the actor.
	 * 	
	 * 	@param dir The direction in which the tile should be from the actor.
	 * 	@param stride Distance between the actor and the tile in grid units.
	 * 	@param actor The actor to measure from.
	 * 	@return Calculated offset grid position.
	 */
	static native int MdlGetGPosDirZ(Direction dir, int stride, int actor);
	
	/**
	*	Gets an Actor's vertical grid position.
	*
	*	@param actor ID of the Actor.
	*
	*	@return Z grid position of target.
	*/
	static native int MdlGetGPosZ(int actor);

	/**
	*	Sets the location of an Actor to given grid coordinates.
	*
	*	@param gridX X location on the grid.
	*	@param y Y altitude (redundant)
	*	@param gridZ Z location on the grid
	*	@param actor ID of the Actor to move, or ACTOR_CURRENT_SCROBJ.
	*/
	static native void MdlSetGPos(int gridX, int y, int gridZ, int actor);

	/**
	 * 	Gets the world-space X location of an Actor model.
	 * 	
	 * 	@param actor ID of the Actor, or ACTOR_CURRENT_SCROBJ.
	 */
	static native float MdlGetPosX(int actor);

	/**
	 * 	Gets the world-space Y location of an Actor model.
	 * 	
	 * 	@param actor ID of the Actor, or ACTOR_CURRENT_SCROBJ.
	 */
	static native float MdlGetPosY(int actor);

	/**
	 * 	Gets the world-space Z location of an Actor model.
	 * 	
	 * 	@param actor ID of the Actor, or ACTOR_CURRENT_SCROBJ.
	 */
	static native float MdlGetPosZ(int actor);

	/**
	*	Sets the location of an Actor to given world coordinates.
	*
	*	@param x X location.
	*	@param y Y location.
	*	@param z Z location.
	*	@param actor ID of the Actor to move, or ACTOR_CURRENT_SCROBJ.
	*/
	static native void MdlSetPos(float x, float y, float z, int actor);

	/**
	 * 	Gets the 16-bit hash name of the FieldRailSystem line of an actor's PositionRail.
	 * 
	 * 	@param actor ID of the Actor.
	 * 	@param Hash of the Actor's rail's name.
	 */
	static native int MdlGetRailPosLineHashID(int actor);

	/**
	 * 	Gets the full unique ID of the FieldRailSystem track of an actor's PositionRail.
	 * 	
	 * 	@param actor ID of the Actor.
	 * 	@return The track key, composed of a name hash and chunk coordinates.
	 */
	static native int MdlGetRailPosKey(int actor);

	/**
	 * 	Gets the Front position component of an actor's PositionRail.
	 * 	
	 * 	@param actor ID of the Actor.
	 * 	@return Front/Vertical location of an Actor on their Rail.
	 */
	static native int MdlGetRailPosFront(int actor);

	/**
	 * 	Gets the Side position component of an actor's PositionRail.
	 * 	
	 * 	@param actor ID of the Actor.
	 * 	@return Side/Horizontal location of an Actor on their Rail.
	 */
	static native int MdlGetRailPosSide(int actor);

	/**
	 * 	Sets an Actor position to a FieldRailSystem line.
	 * 	
	 * 	@param actor ID of the Actor to move.
	 * 	@param lineKey Unique ID of the rail line.
	 * 	@param posFront Front/Vertical position on the rail.
	 * 	@param y Absolute Y altitude.
	 * 	@param posSide Side/Horizontal position on the rail.
	 */
	static native void MdlSetRailPos(int actor, int lineKey, int posFront, float y, int posSide);

	/**
	 * 	Moves an Actor close to another.
	 * 	
	 * 	@param actor The actor to move.
	 * 	@param nearActor The other actor to move 'actor' near to.
	 */
	static native void MdlSetPosToOBJNear(int actor, int nearActor);

	/*
	 * ACTIONS AND ANIMATION
	 */

	/**
	 * 	Ensures that no two actors overlap at the same position.
	 * 	
	 * 	@param actor ID of the actor that should potentially free up space for other actors.
	 */
	static native void MdlOverlapShift(int actor);

	/**
	 * 	Shows or hides an Actor's shadow.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param enableShadow Whether the actor's shadow should be visible.
	 */
	static native void MdlSetShadow(int actor, boolean enableShadow);

	/**
	 * 	Checks if an Actor should be crouched before on interaction.
	 * 	
	 * 	@param actor ID of the actor, or ACTOR_CURRENT_SCROBJ.
	 * 	@return True if the preset is used.
	 */
	static native boolean MdlIsHalfSitSkelPreset(int actor);

	#ifdef SANGO
	/**
	 * 	Checks if an Actor is capable of using the TURN ActionCommands.
	 * 	This is done by querying the required motions in the motion pack.
	 * 	
	 * 	@param actor ID of the actor, or ACTOR_CURRENT_SCROBJ.
	 */
	static native boolean MdlCanUseTurnAcmd(int actor);
	#endif

	/**
	 * 	Sets an Actor to their idle pose.
	 * 	
	 * 	@param actor ID of the actor, or ACTOR_CURRENT_SCROBJ.
	 */
	static native void MdlSetWaitAnimeReq(int actor);

	/**
	 * 	Sets an Actor to their sitting idle pose.
	 * 	This function has a sanity check to only take effect on the player actor.
	 * 	
	 * 	@param actor ID of the actor - must be PlayerActor.ACTOR_PLAYER.
	 */
	static native void _MdlSetSitWait(int actor);

	/**
	 * 	Sets if an Actor should automatically change to their bind pose after all other animations finish.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param enable True to enable automatic idle animation reset.
	 */
	static native void MdlSetPauseAutoWaitAnime(int actor, boolean enable);

	/**
	 * 	Sets the face texture animation frame of an actor.
	 * 	Each actor with more than one face in their texture sheet has a simple UV animation that has a different one mapped for every 10 frames.
	 * 	This function effectively sets the static animation frame of said animation to 10 * faceNo.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param faceNo Actor specific face index.
	 */
	static native void ChangeFace(int actor, int faceNo);

	/**
	 * 	Locks or unlocks changes to the Actor's motion number.
	 * 	
	 * 	@param actor ID of the motion actor.
	 * 	@param value True to disable motion changes, false to re-enable.
	 */
	static native void MdlPauseAnimNo(int actor, boolean value);

	/**
	 * 	Freezes or unfreezes the animation frame of all current and future animation controllers.
	 * 	
	 * 	@param actor ID of the motion actor.
	 * 	@param value True to pause all animations, false to unpause.
	 */
	static native void MdlPauseAnim(int actor, boolean value);

	#ifdef SANGO
	/**
	 * 	Disables actor model culling.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param value True to disable culling, false to re-enable.
	 */
	static native void MdlSetCullingOff(int actor, boolean value);
	#endif
}