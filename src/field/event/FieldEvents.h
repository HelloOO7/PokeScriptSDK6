package field.event;

import contest.ContestPortraitRoom;
import pokedex.PokedexCertificate;

public class FieldEvents {

	/**
	 * 	Plays the escape rope sequence and warps the player accordingly.
	 */
	static native void CallEscapeRope() : CallAnanukenohimoEffect;

	/**
	 * 	Plays the Teleport sequence and warps the player accordingly.
	 */
	static native void CallTeleport() : CallTeleportEffect;

	#ifdef SANGO
	/**
	 * 	Calls Soaring in the Sky.
	 */
	static native void CallSoaring() : CallOozorawotobu;

	/**
	 * 	Displays a Pokemon icon on a hardcoded material of a field object.
	 * 	
	 * 	@param room The room to display in.
	 * 	@param dispId Index of the display object.
	 */
	static native void CallFieldDispPokePortrait(ContestPortraitRoom room, int dispId);
	#endif

	/**
	 * 	Shows a pokedex certificate.
	 * 	
	 * 	@param cert The certificate to show.
	 * 	@param playEffect True if the animation and sound effect should be played. These are usually only active when the certificate is first obtained.
	 */
	static native void CallCommendation(PokedexCertificate cert, boolean playEffect);

	/**
	 * 	Calls the Hall of Fame induction sequence.
	 */
	static native void CallHallOfFame() : CallDendouDemo;

	/**
	 * 	Calls the ending sequence (staff roll and other cutscenes).
	 * 	
	 * 	@param isRepeated True if this is not the first time that the game has been cleared, allowing fast forward and skipping the rival battle.
	 */
	static native void CallGameClear(boolean isRepeated);
}