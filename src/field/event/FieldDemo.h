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