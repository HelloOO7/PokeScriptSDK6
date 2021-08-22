package field.actor;

import field.actor.InterestViewMode;

public class InterestView {
	/**
	 * 	Sets a limit to the InterestView IK function of an actor.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param mode The enum constant value of the limit.
	 */
	static native void MdlInterestViewSetMode(int actor, InterestViewMode mode);

	/**
	 * 	Makes an Actor look at an absolute world location.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param x X component of the target point.
	 * 	@param y Y component of the target point.
	 * 	@param z Z component of the target point.
	 */
	static native void MdlInterestViewSet(int actor, float x, float y, float z);

	/**
	 * 	Clears an InterestView look target.
	 * 	
	 * 	@param actor ID of the actor.
	 */
	static native void MdlInterestViewClear(int actor);

	
	/**
	 *	Checks if an Actor is currently influenced by an InterestView IK function.
	 *	
	 *	@param actor ID of the actor to check.
	 *	@return True if the Actor is bound to a look target.
	 */
	static native boolean MdlInterestViewIsEnable(int actor);
}