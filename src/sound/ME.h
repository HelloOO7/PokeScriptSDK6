package sound;

public class ME {
	/**
	*	Plays a music effect on the ME channel.
	*
	*	@param MEid Numeric ID of the music effect track.
	*/
	static native void MEPlay(int MEid);

	/**
	*	Check if the specified music effect is has finished playback on the ME channel.
	*
	*	@param MEid Numeric ID of the music effect track.
	*	@return True if the ME is no longer playing.
	*/
	static native boolean MEIsFinished(int MEid);

	/**
	*	Returns from a music effect playback to the previous BGM.
	*	Should be called after checking for playback completion with MEIsPlaying(int MEid).
	*/
	static native void MEReturnBGM();
}