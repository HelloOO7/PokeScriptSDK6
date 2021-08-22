package field.map;

import field.actor.Direction;

public class MapChange {
	/**
	*	Calls the internal function of the field subsystem that carries out a zone transition.
	*
	*	@param zoneId The Zone to transition to.
	*	@param destX X location of the player after the transition.
	*	@param destX Y location of the player after the transition.
	*	@param destX Z location of the player after the transition.
	*	@param dir Facing direction of the player after the transition.
	*	@param retainBGM If set, the BGM remains unchanged by the transition.
	*	@param doFieldEventEntranceIn If set, the game calls DllFieldEventEntranceIn and plays the default map fade animations.
	#ifdef SANGO
	*	@param unknown Unknown parameter.
	#endif
	*	@param showPlaceName If set, the place name display layout is invoked after the transition.
	*/
	#ifdef XY
	static native void _MapChangeCore(int zoneId, int destX, int destY, int destZ, Direction dir, boolean retainBGM, boolean doFieldEventEntranceIn, boolean showPlaceName);
	#else if SANGO
	static native void _MapChangeCore(int zoneId, int destX, int destY, int destZ, Direction dir, boolean retainBGM, boolean doFieldEventEntranceIn, boolean unknown, boolean showPlaceName);
	#endif

	/**
	 * 	Changes the current map zone and warps the player to a rail position.
	 * 	
	 *	@param zoneId The Zone to transition to.
	 *	@param lineKey The unique ID of the rail track.
	 *	@param front Front/Vertical/Y position on the track.
	 *	@param side Side/Horizontal/X position on the track.
	 *	@param dir Facing direction of the player after the transition.
	 *	@param retainBGM If set, the BGM remains unchanged by the transition.
	 *	@param doFieldEventEntranceIn If set, the game calls DllFieldEventEntranceIn and plays the default map fade animations.
	 *	@param showPlaceName If set, the place name display layout is invoked after the transition.
	 */
	static native void _MapChangeRailCore(int zoneId, int lineKey, float front, float side, Direction dir, boolean retainBgm, boolean doFieldEventEntranceIn, boolean showPlaceName);

	/**
	*	Plays a sequenced cutscene, changes the zone and warps the player.
	*
	*	@param zoneId The Zone to transition to.
	*	@param destX X location of the player after the transition.
	*	@param destX Y location of the player after the transition.
	*	@param destX Z location of the player after the transition.
	*	@param dir Facing direction of the player after the transition.
	*	@param demoId ID if the cutscene sequence to play.
	*	@param bgmFadeTime Length of the map BGM fade out, or 0 to keep the map BGM.
	*/
	static native void _MapChangeAndDemoCall(int zoneId, int destX, int destY, int destZ, Direction dir, int demoId, int bgmFadeTime);
	
	/**
	*	Performs the zone warp sequence without using a real warp entity.
	*
	*	@param entryWarpType The transition type (as seen in the Warp Editor) of the virtual source warp.
	*	@param arrivalWarpType The transition type (as seen in the Warp Editor) of the virtual destination warp.
	*	@param destX X location of the player after the transition.
	*	@param destX Y location of the player after the transition.
	*	@param destX Z location of the player after the transition.
	*	@param destDir Facing direction of the player after the transition.
	*/
	static native void MapChangeFake(int entryWarpType, int arrivalWarpType, int destX, int destY, int destZ, Direction destDir);
}