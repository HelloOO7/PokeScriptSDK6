package field.fx;

import core.Runtime;

public class MotionBlur {
	#ifdef SANGO
	/**
	*	Initializes the Motion Blur effect.
	*/
	static native void InitMotionBlur();

	/**
	*	Checks if the Motion Blur effect has finished initializing.
	*
	*	@return True if the effect has initialized.
	*/
	static native boolean WaitInitMotionBlur();

	/**
	*	Frees the Motion Blur effect memory.
	*/
	static native void EndMotionBlur();

	/**
	*	Shows the Motion Blur effect.
	*
	*	@param edgeBlur Whether the edges of the screen should blur.
	*	@param heartBeat Whether the effect should be animated in a heart beat pattern.
	*/
	static native void OnMotionBlur(boolean edgeBlur, boolean heartBeat);

	/**
	*	Hides the Motion Blur effect, but does not free memory.
	*/
	static native void OffMotionBlur();

	/**
	*	Animates the motion blur strength.
	*
	*	@param strength The desired blur intensity.
	*/
	static native void ControlMotionBlur(float strength, int a2, int a3);

	/**
	*	Animates the motion blur color.
	*
	*	@param r Normalized red component of the blur color.
	*	@param g Normalized green component of the blur color.
	*	@param b Normalized blue component of the blur color.
	*/
	static native void ControlMotionBlurColor(float r, float g, float b, int a3, int a4);

	/**
	*	Safely initializes the Motion Blur effect.
	*	Unlike InitMotionBlur, this function blocks until the effect has loaded.
	*/
	static void PrepareMotionBlur(){
		InitMotionBlur();
		while (!WaitInitMotionBlur()){
			Runtime.sleep(1);
		}
	}
	#endif
}