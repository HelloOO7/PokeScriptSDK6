package field.map;

public class BuildMdl {
	/**
	 * 	Creates a Building Model handle from grid coordinates.
	 * 	This method is equivalent to (z | (x << 16))
	 * 	
	 * 	@param x X location of the prop on the grid.
	 * 	@param z Z location of the prop on the grid.
	 */
	static native int BuildMdlGetHandleByGPos(int x, int z);

	/**
	 * 	Creates a Building Model handle for a building looked up by its defined Unique ID.
	 * 	The method first searches for a prop with the Handle UID field equal to the requested value, then gets its grid position and calculates the handle as normal.
	 * 	
	 * 	@param uniqueID The user-defined Handle UID of the prop.
	 */
	static native int BuildMdlGetHandleByUniqID(int uniqueID);

	/**
	 * 	Shows or hides a Building Model.
	 * 	
	 * 	@param handle Static prop handle.
	 * 	@param visible True to show the prop, false to hide it.
	 */
	static native void BuildMdlSetVisible(int handle, boolean visible);

	/**
	 * 	Plays a Building Model's registered Event Animation.
	 * 	
	 * 	@param handle Static prop handle.
	 * 	@param anm Registry index of the event animation.
	 * 	@param speed Speed multiplier of the playback.
	 */
	static native void BuildMdlEventAnimeStart(int handle, int anm, float speed);

	/**
	 * 	Plays a Building Model's registered Event Animation in reverse, from end to start.
	 * 	
	 * 	@param handle Static prop handle.
	 * 	@param anm Registry index of the event animation.
	 * 	@param play True if the animation should start automatically.
	 * 	@param speed Speed multiplier of the playback.
	 */
	static native void BuildMdlEventAnimeInvStart(int handle, int anm, boolean play, float speed);

	/**
	 * 	Restarts all playing event animations of a Building Model.
	 * 	
	 * 	@param handle Static prop handle.
	 */
	static native void BuildMdlAllTimeAnimeRestart(int handle);
	
	/**
	 * 	Stops a Building Model's playing Event Animation.
	 * 	
	 * 	@param handle Static prop handle.
	 * 	@param anm Registry index of the event animation.
	 */
	static native void BuildMdlEventAnimeStop(int handle, int anm);

	/**
	 * 	Pauses a Building Model's playing Event Animation.
	 * 	
	 * 	@param handle Static prop handle.
	 * 	@param anm Registry index of the event animation.
	 */
	static native void BuildMdlEventAnimePause(int handle, int anm);

	/**
	 * 	Sets a playing event animation of a Building Model to the first frame.
	 * 	
	 * 	@param handle Static prop handle.
	 * 	@param anm Registry index of the event animation.
	 */
	static native void BuildMdlEventAnimeReset(int handle, int anm);

	/**
	 * 	Sets a playing event animation of a Building Model to the last frame.
	 * 	
	 * 	@param handle Static prop handle.
	 * 	@param anm Registry index of the event animation.
	 */
	static native void BuildMdlEventAnimeSetEnd(int handle, int anm);

	/**
	 * 	Checks if a Building Model's event animation has finished.
	 * 	
	 * 	@param handle Static prop handle.
	 * 	@param anm Registry index of the event animation.
	 * 	@return True if the animation has finished.
	 */
	static native boolean BuildMdlEventAnimeIsEnd(int handle, int anm);

	/**
	 * 	Stops all resident non-event animations of a Building Model.
	 * 	
	 * 	@param handle Static prop handle.
	 */
	static native void BuildMdlAllTimeAnimeStop(int handle);

	/**
	 * 	Restarts all resident non-event animations of a Building Model.
	 * 	
	 * 	@param handle Static prop handle.
	 */
	static native void BuildMdlAllTimeAnimeRestart(int handle);
}