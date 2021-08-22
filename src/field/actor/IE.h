package field.actor;

public class IE {
	/**
	 * 	Attaches a background interactive event script to an Actor.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param scrId ID of the event script in the Zone's script file.
	 */
	static native void IECreate(int actor, int scrId);

	/**
	 * 	Frees an interactive event bound to an Actor.
	 * 	
	 * 	@param actor ID of the actor.
	 */
	static native void IEDelete(int actor);

	/**
	 * 	Safely finishes all interactive events bound to an Actor.
	 * 	
	 * 	@param actor ID of the actor.
	 */
	static native void IETerminate(int actor);

	/**
	 * 	Changes the Interactive Event script that an Actor is executing.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@param newScrId The new event script ID to assign.
	 */
	static native void IEReqChangeScript(int actor, int newScrId, boolean a3);

	/**
	 * 	Gets the Actor ID of the parent Interactive Event process.
	 * 	
	 * 	@return Valid actor handle, or undefined behavior if the script isn't an Interactive Event.
	 */
	static native int IEGetOBJID();

	/**
	 * 	Sends an arbitrary integer message to the IE executor.
	 */
	static native void IESendMessage(int message);

	/**
	 * 	Gets the stored IE state message.
	 * 	
	 * 	@return Requested IE state set with IESendMessage.
	 */
	static native int IEReceiveState();

	static native boolean IEIsAIEnd();
}