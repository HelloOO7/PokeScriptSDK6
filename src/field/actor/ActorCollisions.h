package field.actor;

/**
 * 	Specifies collision rules for actor movement.
 * 	Can technically be used as inverse bitflags.
 */
public enum ActorCollisions {
	/**
	 * 	Actor uses full collision data.
	 */
	FULL,
	/**
	 * 	Actor ignores other Actors' collisions.
	 */
	IGNORE_ACTOR,
	/**
	 * 	Actor ignores map collisions.
	 */
	IGNORE_MAP,
	/**
	 * 	Actor is not bound by any collisions.
	 */
	IGNORE_ALL
}