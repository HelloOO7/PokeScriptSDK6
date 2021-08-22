package field.camera;

import core.Runtime;
;
public class CameraAnimation {
	/*
	 * SETUP
	 */
	 
	/**
	 * 	Requests loading of a camera animation resource from the Field Camera Animation archive.
	 * 	
	 * 	@param rscId Index of the animation in the camera archive.
	 */
	static native void PrepareCameraAnimation(int rscId);

	/**
	 * 	Checks if a previously requested camera animation resource has finished loading.
	 * 	
	 * 	@return True if the camera animation has loaded.
	 */
	static native boolean IsReadyCameraAnimation();

	/**
	 * 	Releases the loaded camera animation resource.
	 * 	
	 * 	Due to a game bug, this will prevent any subsequent camera animations from playing until Field is reloaded.
	 * 	If this function is not called after a camera animation finishes, the field camera will remain at the animation's last frame's coordinates.
	 * 	Not releasing a camera animation may have undesirable effects caused by various memory leaks.
	 */
	static native void DestroyCameraAnimation();

	/**
	 * 	Blocks until a camera animation is loaded.
	 */
	static void WaitLoadCameraAnimation() {
		while (!IsReadyCameraAnimation()) {
			Runtime.sleep(1);
		}
	}

	/**
	 * 	Fully loads a camera animation.
	 * 	
	 * 	@param rscId Index of the animation in the camera archive.
	 */
	static void LoadCameraAnimation(int rscId) {
		PrepareCameraAnimation(rscId);
		WaitLoadCameraAnimation();
	}

	/*
	 * PLAYBACK
	 */

	/**
	 * 	Plays the currently loaded field camera animation.
	 */
	static native void PlayCameraAnimation();

	/**
	 * 	Checks if a camera animation is playing.
	 * 	
	 * 	@param True if there is an ongoing camera animation playback.
	 */
	static native boolean IsPlayingCameraAnimation();

	/**
	 * 	Waits until a camera animation has finished playing.
	 */
	static void WaitFinishCameraAnimationPlayback() {
		while (IsPlayingCameraAnimation()) {
			Runtime.sleep(1);
		}
	}

	/**
	 * 	Sets a translation origin point for camera animations.
	 * 	Effectively moves the camera a certain amount at all times.
	 * 	
	 * 	@param x X coordinate of the origin point.
	 * 	@param y Y coordinate of the origin point.
	 * 	@param z Z coordinate of the origin point.
	 */
	static native void SetCameraAnimationTranslation(float x, float y, float z);

	/**
	 * 	Sets a rotation origin for camera animations.
	 * 	This is done by premultiplying the camera matrix with a fixed rotation matrix.
	 * 	The camera animation will effectively be rotated by the given values at all times.
	 * 	
	 * 	@param x Pitch rotation (radians).
	 * 	@param y Yaw rotation (radians).
	 * 	@param z Roll rotation (radians).
	 */
	static native void SetCameraAnimationRotation(float x, float y, float z);

	/**
	 * 	Resets camera animation playback to the first frame of animation.
	 * 	Note that calling this function will also pause the animation.
	 */
	static native void SetCameraAnimationBeginFrame();

	/**
	 * 	Resets camera animation playback to the last frame of animation.
	 * 	Note that calling this function will also pause the animation.
	 */
	static native void SetCameraAnimationEndFrame();
}