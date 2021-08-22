package core;

public class Runtime {
	/**
	*	Suspends the abstract machine for a given period of time.
	*
	*	@param time Length of the sleep period.
	*/
	static native void _Suspend(int time);

	/**
	*	Does nothing.
	*/
	static native void CommandNOP();

	/**
	*	Calls an external AMX script from the corresponding GARC.
	*
	*	@param scrId The numeric ID of the global script.
	*/
	static native void GlobalCall(int scrId);

	/**
	*	Sets the g_mode script parameter for automatic execution for the next script to be loaded.
	*
	*	@param scrId The entity script ID/g_mode param.
	*/
	static native void ReserveScript(int scrId);

	/**
	*	Requests the abstract machine to pause for a given amount of frames.
	*	Unlike the native _Suspend(time) method, this function ensures proper halt of the VM.
	*/
	static void sleep(int frames) {
		_Suspend(frames);
		pause;
	}
}