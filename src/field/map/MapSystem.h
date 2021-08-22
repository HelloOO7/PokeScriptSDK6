package field.map;

public class MapSystem {
	#ifdef SANGO
	/**
	*	Sets a grid position for FieldMapper to calculate chunk culling from.
	*
	*	@param x X location on the grid. 
	*	@param y Y altitude in world coordinates.
	*	@param z Z location on the grid.
	*/
	static native void MapperBlockCalcPosSet(int x, int y, int z);
	
	/**
	*	Clears the overriden grid position of the FieldMapper.
	*/
	static native void MapperBlockCalcPosClear();

	/**
	 * 	Checks if any map chunk has not yet finished loading.
	 */
	static native boolean MapperBlockIsLoading();

	/**
	 * 	Checks if any map chunk has not yet finished loading.
	 * 	This method can be called even outside of Field.
	 */
	static native boolean _FieldMapBlockIsLoading();
	#endif

	/**
	 * 	Gets the currently loaded field zone.
	 * 	This method overrides PlayerGetZoneID due to confusing naming.
	 */
	static native int GetCurrentZoneID() : PlayerGetZoneID;

	/**
	 * 	Sets the last visited Pokémon Center/Teleport location to an explicit ID.
	 * 	Note that this is not a Zone ID, but rather a special index into the teleport zone table.
	 * 	
	 * 	@param tpID Index of the teleport zone entry.
	 */
	static native void SetTeleportLocation(int tpID) : WarpSetID;
}