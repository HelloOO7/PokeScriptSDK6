package field.system;

public class RTC {
	/**
	 * 	Forces the game's real-time clock to a fixed hour/minute time of day.
	 */


	/**
	 * 	Resets the game's real-time clock to the system time.
	 */
	static native void ResetRTCTime() : SkyboxEventTimeReset;
}