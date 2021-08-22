package sound;

public class PokeVoice {
	/**
	*	Plays a Pokémon's cry.
	*
	*	@param pokeId The numeric ID of the Pokémon. (Dex No. in most cases)
	*	@param formeId Number of the Pokémon forme to play the voice for (usually 0).
	*/
	static native void VoicePlay(int pokeId, int formeId);

	/*
	*	Checks if playback of all Pokémon cries has finished.
	*/
	static native void VoiceIsEnd();
}