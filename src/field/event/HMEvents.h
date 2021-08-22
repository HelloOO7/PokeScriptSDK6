package field.event;

public class HMEvents {
	/**
	 * 	Plays the Dig sequence and warps the player accordingly.
	 */
	static native void CallDig() : CallAnawohoruEffect;

	/**
	 * 	Plays the Dive effect with a party Pokémon as the HM user.
	 * 	
	 * 	@param partyIdx Index of the HM user in the party.
	 */
	static native void CallDive(int partyIdx) : CallDivingEffect;

	/**
	 * 	Plays the overworld effect of TM70 Flash.
	 */
	static native void CallFlash() : CallFlashEffect;

	/**
	 * 	Plays an HM cutscene with a party Pokémon.
	 * 	
	 * 	@param seqId Index of the cutscene sequence.
	 * 	@param partyIdx Index of the party Pokémon.
	 */
	static native void CallHidenDemo(int seqId, int partyIdx);
}