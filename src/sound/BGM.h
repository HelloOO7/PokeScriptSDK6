package sound;

public class BGM {

	/**
	*	Transitions to an Event BGM.
	*
	*	@param BGMid Numeric ID of the background music track.
	*	@param fadeTime Length of current BGM fade-out.
	*/
	#ifdef SANGO
	static native void BGMStartEvent(int BGMid, int fadeTime);
	#else if XY
	static native void EventBGMStart(int BGMid, int fadeTime);
	#endif

	/**
	*	Transitions the current Event BGM to another.
	*
	*	@param BGMid Numeric ID of the background music track.
	*	@param fadeOutTime Length of current BGM fade-out.
	*	@param fadeInTime Length of the other BGM fade-in.
	*/
	#ifdef SANGO
	static native void BGMChangeEvent(int BGMid, int fadeOutTime, int fadeInTime);
	#else if XY
	static native void EventBGMChange(int BGMid, int fadeOutTime, int fadeInTime);
	#endif

	/**
	*	Transitions back from an Event BGM.
	*
	*	@param fadeOutTime Length of the event BGM fade-out.
	*	@param fadeInTime Length of the returning BGM fade-in.
	*/
	#ifdef SANGO
	static native void BGMEndEvent(int fadeOutTime, int fadeInTime);
	#else if XY
	static native void EventBGMEnd(int fadeOutTime, int fadeInTime);
	#endif

	#ifdef SANGO
	/**
	*	Transitions to a Battle Event BGM.
	*
	*	@param BGMid Numeric ID of the background music track.
	*	@param fadeTime Length of current BGM fade-out.
	*/
	static native void BGMStartBattleEvent(int BGMid, int fadeTime);
	#else if XY
	static native void BattleEventBGMStart(int BGMid, int fadeTime);
	#endif

	/**
	*	Transitions back from a cutscene BGM.
	*
	*	@param fadeOutTime Length of the cutscene BGM fade-out.
	*	@param fadeInTime Length of the returning BGM fade-in.
	*/
	#ifdef SANGO
	static native void BGMEndDemo();
	#else if XY
	static native void DemoBGMEnd();
	#endif

	/**
	*	Check if the specified BGM is currently being played on the BGM channel.
	*
	*	@param BGMid Numeric ID of the background music track.
	*	@return True if the currently playing BGM is the one given by BGMid.
	*/
	static native boolean BGMIsPlaying(int BGMid);

	/**
	*	Performs a linear volume shift on the BGM channel.
	*
	*	@param targetVol The volume to change to (in percent).
	*	@param sourceVol The volume to fade to the target volume from (in percent).
	*/
	static native void BGMVolumeChange(int targetVol, int sourceVol);

	/**
	*	Discards the current BGM and changes it to the Zone's default track.
	*	This method is used when the Zone's BGM has changed externally (usually with an Event flag) and as such needs to be retrieved again.
	*
	*	@param fadeOutTime Length of current BGM fade-out.
	*	@param fadeInTime Length of new BGM fade-in.
	*/
	#ifdef SANGO
	static native void BGMChangeNowMap(int fadeOutTime, int fadeInTime);
	#else if XY
	static native void NowMapBGMChange(int fadeOutTime, int fadeInTime);
	#endif
}