package field.event;

import pokemon.PokemonGender;

public class FieldDemo {
	/**
	 * 	Hatches a party member from an Egg.
	 * 	
	 * 	@param partyIdx Index of the party member to hatch.
	 */
	static native void CallEggDemoEvent(int partyIdx);

	/**
	 * 	Plays a sequence over a capture of Field's framebuffer in Field's heap space.
	 * 	As a side effect of the capture, most 3D sequences will play behind it and won't be visible.
	 * 	
	 * 	@param seqId ID of the sequence.
	 */
	static native void CallFieldCaptureDemo(int seqId);

	/**
	 * 	Plays a sequence in the Field scene.
	 * 	
	 * 	@param seqId ID of the sequence.
	 * 	@param seqTextId Ranging from 0 to 6, this parameter describes an index into a lookup of text files to use for the sequence. Apart from the default value (0), this functionality is unused.
	 *	@param allowCameraMotion If set, cutscene camera animations are applied to the Field camera. The behavior is undefined if the camera's view mode is anything other than LookAt.
	 */

	static native void CallFieldNotCaptureDemo(int seqId, int seqTextId, boolean allowCameraMotion);

	/**
	 * 	Calls the game's single Pokémon showcase sequence.
	 * 	
	 * 	@param sequenceId ID of the sequence to play.
	 * 	@param pokeId Dex no. of the Pokémon.
	 * 	@param formId Index of the Pokémon's forme.
	 * 	@param gender The Pokémon's gender.
	 * 	@param isShiny True if the displayed Pokémon should be the shiny variant.
	 * 	@param isEgg True if the displayed Pokémon should be an egg.
	 */
	static native void CallFieldCaptureDemoSimplePoke(int sequenceId, int pokeId, int formId, PokemonGender gender, boolean isShiny, boolean isEgg, int a7);
}