package core;

public enum GameVersion {
	X = 24,
	Y = 25,
	ALPHA_SAPPHIRE = 26,
	OMEGA_RUBY = 27;

	/**
	 * 	Gets the running game version, f.e. X or Alpha Sapphire.
	 */
	#ifdef SANGO
	static native GameVersion Get() : RomGetVersion;
	#else if XY
	static native GameVersion Get() : GetRomVersion;
	#endif
}