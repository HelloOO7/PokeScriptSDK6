package field.camera;

import field.camera.CameraShakeType;

public class ShakeCamera {
	/**
	 * 	Plays a camera shake effect once, unless it is a loop effect.
	 * 	
	 * 	@param type Type of the effect.
	 * 	@param intensity Intensity of the shaking, in Richter scale.
	 * 	@param speed Speed multiplier of the shaking animation.
	 */
	static native void ShakeCameraBegin(CameraShakeType type, float intensity, float speed);

	/**
	 * 	Plays a camera shake effect indefinitely, forcing it to loop even if the effect isn't looped by default.
	 * 	This method is unused and got replaced by the LOOP shake types.
	 * 	
	 * 	@param type Type of the effect.
	 * 	@param intensity Intensity of the shaking, in Richter scale.
	 * 	@param speed Speed multiplier of the shaking animation.
	 */
	static native void ShakeCameraBeginLoop(CameraShakeType type, float intensity, float speed);
	
	/**
	 * 	Plays a camera shake effect for a given amount of time.
	 * 	
	 * 	@param duration Length of the shake effect, in frames.
	 * 	@param type Type of the effect.
	 * 	@param intensity Intensity of the shaking, in Richter scale.
	 * 	@param speed Speed multiplier of the shaking animation.
	 */
	static native void ShakeCameraBeginEndFrame(int duration, CameraShakeType type, float intensity, float speed);

	/**
	 * 	Ends any and all active camera shake animations.
	 */
	static native void ShakeCameraEndAll();
}