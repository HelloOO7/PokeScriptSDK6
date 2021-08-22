package field.system;

public class EventWork {

	/**
	*	Retrieves a work's value.
	*
	*	@param work The work to get.
	*	@return Value of the work.
	*/
	static native int WorkGet(int work);

	/**
	*	Sets a work to a given value.
	*
	*	@param work The work to set.
	*	@param value The value to set the work to.
	*/
	static native void WorkSet(int work, int value);

	/**
	 * 	Sets a work value asynchronously.
	 * 	
	 * 	@param work The work to set.
	 * 	@param value The value to set the work to.
	 */
	static native void WorkSetReq(int work, int value);

	/**
	 * 	Gets a script work (0x4###).
	 * 	
	 * 	@param work The work to get.
	 */
	static native int ParentSeqGet(int work);

	/**
	 * 	Sets a script work (0x4###) asynchronously.
	 * 	
	 * 	@param work The work to set.
	 * 	@param value The value to set the work to.
	 */
	static native void ParentSeqSetReq(int work, int value);
}