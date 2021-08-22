package field.actor;

public enum Direction {
	NORTH,
	SOUTH,
	WEST,
	EAST,
	NORTH_WEST,
	NORTH_EAST,
	SOUTH_WEST,
	SOUTH_EAST,

	//Reserved value for the current facing direction of an Actor
	CURRENT = 9;

	/**
	 * 	Gets the Direction that is the closest to a given direction vector.
	 * 	
	 * 	@param x X component of the grid-wise direction vector.
	 * 	@param z Z component of the grid-wise direction vector.
	 */
	static native Direction CalcVecToDir(float x, float z);

	/**
	 * 	Inverts a Direction value.
	 * 	
	 * 	@param dir A direction.
	 * 	@return A Direction that faces opposite from dir.
	 */
	static native Direction GetReturnDir(Direction dir);

	/**
	 * 	Gets a Direction that is the sum of two other directions - in other words, one rotated by the other.
	 * 	The second direction gets translated into a relative increment with SOUTH as its origin - a value of NORTH would thereby rotate by 180 degrees and so on.
	 * 	This method is unused.
	 * 	
	 * 	@param dir1 The base direction.
	 * 	@param dir2 The direction to rotate by.
	 */
	static native Direction GetTurnDirByDir(Direction dir1, Direction dir2);

	/**
	 * 	Gets the X component of a normalized direction vector represented by a Direction.
	 * 	
	 * 	@param dir A direction.
	 * 	@return -1, 0 or 1 depending on the horizontal characteristics of the Direction.
	 */
	static native int GetDirAddValueGridX(Direction dir);

	/**
	 * 	Gets the Z component of a normalized direction vector represented by a Direction.
	 * 	
	 * 	@param dir A direction.
	 * 	@return -1, 0 or 1 depending on the vertical characteristics of the Direction.
	 */
	static native int GetDirAddValueGridZ(Direction dir);
}