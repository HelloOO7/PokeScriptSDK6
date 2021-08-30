package core;

public enum GameLanguage {
	NULL,
	JAPANESE,
	ENGLISH,
	FRENCH,
	ITALIAN,
	GERMAN,
	SPANISH = 7,
	KOREAN = 8;

	#ifdef SANGO
	static native GameLanguage Get() : RomGetLanguageID;
	#else if XY
	static native GameLanguage Get() : GetLanguageID;
	#endif
}