package core;

/*
https://github.com/devkitPro/libctru/blob/master/libctru/include/3ds/services/cfgu.h
*/
public enum GameRegion {
	JPN,
	USA,
	EUR,
	AUS,
	CHN,
	KOR,
	TWN;

	#ifdef SANGO
	static native GameRegion Get() : RegionGet;
	#else if XY
	static native GameRegion Get() : GetHWRegion;
	#endif
}