package sound;

public class SE {

	/**
	*	Plays a sound effect on the SE channel.
	*
	*	@param SEid Numeric ID of the sound effect track.
	*/
	static native void SEPlay(int SEid);

	/**
	*	Check if the specified sound effect is currently being played on the SE channel.
	*
	*	@param SEid Numeric ID of the sound effect track.
	*	@return True if the SE is currently being played.
	*/
	static native boolean SEIsPlaying(int SEid);

	/**
	*	Stops a given sound effect of the SE channel.
	*
	*	@param SEid Numeric ID of the sound effect track.
	*/
	static native void SEStop(int SEid);
}