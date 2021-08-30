package field.camera;

public enum CameraOrigin {
	/**
	 * 	Treats all camera coordinates absolute.
	 */
	WORLD = 0,
	/**
	 * 	Premultiplies all camera coordinates with the player model's world matrix.
	 */
	PLAYER = 2
}