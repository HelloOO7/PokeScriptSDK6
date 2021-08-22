package field.system;

public class EventFlags {
	/**
	 * 	Gets the boolean state of an event flag.
	 * 	
	 * 	@param flag ID of the requested flag.
	 */
	static native boolean FlagGet(int flag);

	/**
	*	Sets an event flag to ON state.
	*
	*	@param flag ID of the flag to set.
	*/
	static native void FlagSet(int flag);

	/**
	 * 	Clears an event flag to OFF state.
	 * 	
	 * 	@param flag ID of the flag to clear.
	 */
	static native void FlagReset(int flag);

	#ifdef SANGO
	/**
	 * 	Raises the "place visited" flag of a zone that has implicit flag setting disabled.
	 */
	static native void FlyFlagSet(int zoneId);
	#endif

	/**
	 * 	Sets a flag to a boolean value, asynchronously.
	 * 	
	 * 	@param flag ID of the flag to change.
	 * 	@param value New value of the flag.
	 */
	static native void FlagSetReq(int flag, boolean value);

	/**
	 * 	Gets a script flag.
	 * 	
	 * 	@param flag The work to get.
	 */
	static native int ParentFlagGet(int flag);

	/**
	 * 	Sets a script flag, asynchronously.
	 * 	
	 * 	@param flag The flag to set.
	 * 	@param value New value of the flag.
	 */
	static native void ParentFlagSetReq(int flag, boolean value);
}