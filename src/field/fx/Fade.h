package field.fx;

import field.fx.FadeType;
import field.fx.FadeMode;
import core.Runtime;

public class Fade {
	/**
	*	Requests a fade transition effect.
	*
	*	@param type Style of the fade effect.
	*	@param mode The screen(s) that the fade-out should affect.
	*	@param duration Length of the fade-out (in frames).
	*/
	static native void FadeRequestOut(FadeType type, FadeMode mode, int duration);
	
	/**
	*	Fades back from a Fade effect that was previously called with FadeRequestOut.
	*	
	*	@param mode The screen(s) that the fade-out should affect.
	*	@param duration Length of the fade-in (in frames).
	*/
	#ifdef SANGO
	static native void _FadeRequestIn(FadeMode mode, int duration);
	#else if XY
	static native void _FadeRequestIn(FadeMode mode, int duration) : FadeRequestIn;
	#endif

	
	/**
	*	Checks if a requested fade effect has finished (i.e. the screen has faded completely in or out).
	*
	*	@return True if the fade effect has reached its end frame, false if otherwise.
	*/
	static native boolean FadeIsEnd();

	/**
	 * 	Waits for all Fade effects to finish.
	 */
	static void FadeWaitEnd() {
		while (!FadeIsEnd()) {
			Runtime.sleep(1);
		}
	}
}