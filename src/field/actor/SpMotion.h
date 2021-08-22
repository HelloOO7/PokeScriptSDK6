package field.actor;

import field.actor.Direction;
import core.Runtime;

public class SpMotion {
	/**
	*	Loads a SpMotion bundle.
	*
	*	@param spMotId Index of the SpMotion bundle in the GARC.
	*/
	#ifdef SANGO
	static native void SpMotionReqLoad(int spMotId);
	#else if XY
	static void SpMotionReqLoad(int spMotId) {
		ReqLoadSpMotion(spMotId);
	}

	internal static native void ReqLoadSpMotion(int spMotId);
	#endif

	/**
	*	Checks if the last requested SpMotion bundle has finished loading.
	*
	*	@return True if the SpMotion has finished loading.
	*/
	#ifdef SANGO
	static native boolean SpMotionLoadIsEnd();
	#else if XY
	static boolean SpMotionLoadIsEnd() {
		return IsEndLoadSpMotion();
	}

	internal static native boolean IsEndLoadSpMotion();
	#endif

	static void SpMotionWaitLoad() {
		while (!SpMotionLoadIsEnd()) {
			Runtime.sleep(1);
		}
	}

	/**
	*	Sets up the currently loaded SpMotion to be ready for playback.
	*/
	#ifdef SANGO
	static native void SpMotionSetup();
	#else if XY
	static void SpMotionSetup() {
		SetupSpMotion();
	}

	internal static native void SetupSpMotion();
	#endif

	/**
	*	Plays a SpMotion on an Actor. The Actor has to be registered in the SpMotion header for this to work correctly.
	*
	*	@param targetNPC ID of the Actor to target.
	*	@param index Index of the animation in the SpMotion bundle.
	*	@param isLooped True if the motion should loop indefinitely until stopped.
	*/
	#ifdef SANGO
	static native void SpMotionPlay(int targetNPC, int index, boolean isLooped);
	#else if XY
	static void SpMotionPlay(int targetNPC, int index, boolean isLooped) {
		PlaySpMotion(targetNPC, index, isLooped);
	}

	internal static native void PlaySpMotion(int targetNPC, int index, boolean isLooped);
	#endif

	/**
	 * 	Convenience method to play a single SpMotion animation on an Actor.
	 * 	
	 * 	@param actor ID of the target actor.
	 * 	@param motionPack Index of the SpMotion pack in the archive.
	 * 	@param loop True if the animation should loop indefinitely.
	 * 	@param waitFor True if a non-looping animation should block until it is finished, then be automatically free'd.
	 */
	static void LoadAndPlaySpMotion(int actor, int motionPack, int motionIndex, boolean loop, boolean waitFor) {
		SpMotionReqLoad(motionPack);
		SpMotionWaitLoad();
		SpMotionSetup();
		SpMotionPlay(actor, motionIndex, loop);
		if (waitFor && !loop) {
			MdlSpMotionWaitFinish(actor);
			SpMotionDelete();
		}
	}

	/**
	*	Plays a SpMotion on an Actor and moves the Actor to a location right as it finishes.
	*/
	#ifdef SANGO
	static native void SpMotionPlayMove(int npc, int motion, int x, int y, int z, Direction dirSrc, Direction dirDst);
	#else if XY
	static void SpMotionPlayMove(int npc, int motion, int x, int y, int z, Direction dirSrc, Direction dirDst) {
		PlaySpMotionMove(npc, motion, x, y, z, dirSrc, dirDst);
	}
	
	internal static native void PlaySpMotionMove(int npc, int motion, int x, int y, int z, Direction dirSrc, Direction dirDst);
	#endif


	/**
	*	Frees loaded SpMotion resources.
	*/
	#ifdef SANGO
	static native void SpMotionDelete();
	#else if XY
	static void SpMotionDelete() {
		DeleteSpMotion();
	}

	internal static native void DeleteSpMotion();
	#endif

	/**
	*	Checks if an Actor's regular SpMotion sequence has finished.
	*
	*	@return True if the SpMotion has finished.
	*/
	static native boolean MdlSpMotionUpdate(int targetNPC);

	/**
	 * 	Blocks until an Actor's SpMotion sequence has finished.
	 */
	static void MdlSpMotionWaitFinish(int actor) {
		while (!MdlSpMotionUpdate(actor)) {
			Runtime.sleep(1);
		}
	}

	/**
	*	Checks if an Actor's movement SpMotion sequence has finished.
	*
	*	@return True if the SpMotion has finished.
	*/
	static native boolean MdlSpMotionMoveUpdate(int targetNPC);
}