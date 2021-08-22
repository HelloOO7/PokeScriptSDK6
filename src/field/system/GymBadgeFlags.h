package field.system;

public class GymBadgeFlags {
	/**
	 * 	Checks if the player has a Gym badge.
	 * 	
	 * 	@param gymId Index of the Gym, from 0 to 8.
	 * 	@return True if the player has obtained the Gym badge.
	 */
	static native boolean BadgeGetFlag(int gymId);

	/**
	 * 	Marks a Gym badge as obtained.
	 * 	
	 * 	@param gymId Index of the Gym, from 0 to 8.
	 */
	static native void BadgeSetFlag(int gymId);

	/**
	 * 	Marks a Gym badge as not yet obtained.
	 * 	
	 * 	@param gymId Index of the Gym, from 0 to 8.
	 */
	static native void BadgeResetFlag(int gymId);

	/**
	 * 	Gets the amount of Gym Badges that the player is in possession of.
	 * 	This method is equivalent to for (#0...8) if (BadgeGetFlag(#)) count++
	 * 	
	 * 	@return Number of obtained Gym Badges, from 0 to 8.
	 */
	static native int BadgeGetCount();
}