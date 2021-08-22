package field;

public class FieldControl {
	/**
	*	Unloads the Field module.
	*/
	static native void _FieldClose(boolean unknown1, boolean unknown2);

	/**
	*	Reloads the Field module.
	*/
	static native void _FieldOpen(boolean unknown1);
}