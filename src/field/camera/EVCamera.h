package field.camera;

import field.camera.CameraOrigin;
import field.camera.CameraCurve;

public class EVCamera {
	/**
	*	Initializes the Event camera with the current camera's location as the SrcParam.
	*/
	static native void EVCameraSetInitParam();

	/**
	 * 	Initializes the Event camera with the calculated fixed player camera as the DstParam.
	 */
	static native void EVCameraSetGameCameraParam();

	/**
	 * 	Sets the coordinates of the initial/left/first frame of an event camera animation.
	 */
	static native void EVCameraSetSrcParam(CameraOrigin origin, float camX, float camY, float camZ, float tgtX, float tgtY, float tgtZ, float fov, float roll);

	/**
	 *	Sets the coordinates of the final/right/last frame of an event camera animation.
	 */
	static native void EVCameraSetDstParam(CameraOrigin origin, float camX, float camY, float camZ, float tgtX, float tgtY, float tgtZ, float fov, float roll);

	/**
	 * 	Sets the coordinates of a follow-up event camera animation.
	 * 	This method is equivalent to EVCameraSetInitParam followed by EVCameraSetDst param with this method's parameters.
	 */
	static native void EVCameraSetSlideParam(CameraOrigin origin, float camX, float camY, float camZ, float tgtX, float tgtY, float tgtZ, float fov, float roll);

	/**
	 * 	Sets parameters for the Event camera animation curve.
	 * 	
	 * 	@param transitionLength Length of the transition from the current camera state to the new calculated event camera. Keep in mind that the camera animation progresses normally during the transition.
	 * 	@param totalLength Length of the entire camera animation.
	 * 	@param curve Type of the curve - either linear or a spline.
	 * 	@param slope Spline tangent for curve type SPLINE_MANUAL.
	 */
	static native void EVCameraSetFrameParam(int transitionLength, int totalLength, CameraCurve curve, float slope);

	/**
	 * 	Starts the currently defined event camera motion sequence.
	 */
	static native void EVCameraBegin();

	/**
	 * 	Checks if all camera movement has finished.
	 * 	
	 * 	@return True if all EVCamera animations have reached their final frame.
	 */
	static native boolean EVCameraIsEndFrame();

	/**
	 * 	Releases the event camera.
	 * 	
	 * 	@param runLength Length of the transition from the event camera to the fixed camera.
	 */
	static native void EVCameraEnd(int transitionLength);

	/**
	 * 	Sets parameters that allow customizing the stereostopic 3D properties of the event camera.
	 * 	This function has to be called before EVCameraBegin.
	 * 	
	 * 	@param unused This parameter is skipped by the game code.
	 * 	@param eyeDist Distance between the two stereoscopy viewpoints. Behaves similarly to the 3DS's 3D slider.
	 * 	@param a3 This parameter does not seem to have a visible effect.
	 */
	static native void EVCameraULCDBegin(float unused, float eyeDist, float a3);

	/**
	 * 	Resets the custom stereoscopy parameters of the event camera to default values.
	 * 	
	 * 	@param unused This parameter is skipped by the game code.
	 */
	static native void EVCameraULCDEnd(int unused);
}