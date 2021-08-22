package field.Actor;

public class AI {
	/**
	*	Creates heap space and loads the specified AI into it.
	*
	*	@param AIid The integer representation of the AI class.
	*
	*	@throws AIException if the AI is already loaded.
	*	@throws IllegalArgumentException if the AIid is invalid.
	*/
	static native void AILoad(int AIid);

	/**
	*	Checks if the current AI load sequence (requested by AIload(int AIid)) has finished.
	*
	*	@return true if the sequence has finished
	*			false if otherwise
	*/
	static native boolean AIIsLoaded();

	/**
	*	Sets up a selected NPC with an AI. The AI must be loaded beforehand.
	*
	*	@param AIid The integer representation of the AI class.
	*	@param actor ActorID of the actor to bind the AI to.
	*	@param arg3
	*
	*	@throws AIException if the AI is not loaded. (see AIIsLoaded())
	*	@throws IllegalArgumentException if the AIid is invalid or the targetUnit does not exist.
	*/
	static native void AICreate(int AIid, int actor, int arg3);

	/**
	*	Checks if the given AI is loaded and is currently controlling an Actor.
	*	
	*	@param AIid The integer representation of the AI class.
	*	
	*	@return true if the AI is loaded and assigned to an Actor
	*			false if otherwise
	*
	*	@throws IllegalArgumentException if the AIid is invalid.
	*/
	static native boolean AIIsAlive(int AIid);

	/**
	*	Decouples the given AI from its assigned Actor.
	*
	*	@param AIid The integer representation of the AI class.
	*
	*	@throws AIException if the AI is not alive. (see AIIsAlive(int AIid))
	*	@throws IllegalArgumentException if the AIid is invalid.
	*/
	static native void AIDelete(int AIid);
}