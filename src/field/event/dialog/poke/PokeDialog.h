package field.event.dialog.poke;

import field.event.dialog.poke.PokeSelectDialogType;
import field.system.EventWork;

public class PokeDialog {

	static final int POKESEL_CANCELLED = 6;

	static final int WKID_POKE3SELECT_RESULT = 0x4030;

	/**
	 * 	Shows a menu for selecting a party pokemon.
	 * 	
	 * 	@param type Style and purpose of the dialog layout.
	 * 	@param targetWk A Work ID to which the resulting party index (or POKESEL_CANCELLED if the dialog is dismissed) should be stored.
	 * 	@param param A type-specific parameter.
	 * 	@param fade True if the layout should automatically fade in and out.
	 */
	static native void CallPokeSelect(PokeSelectDialogType type, int targetWk, int param, boolean fade);

	/**
	 * 	Calls the starter selection app.
	 * 	The result gift Pokémon index is stored into WKID_POKE3SELECT_RESULT.
	 * 	
	 * 	@param starterSet Index of the starter Pokémon group.
	 */
	#ifdef SANGO
	static native void _CallPoke3Select(int starterSet);
	#else if XY
	static native void _CallPoke3Select(int starterSet) : CallPoke3Select;
	#endif

	static int GetSelectedStarterPokemon() {
		return EventWork.WorkGet(WKID_POKE3SELECT_RESULT);
	}

	/**
	 * 	Calls the starter selection app and gets the result.
	 * 	
	 * 	@param starterSet Index of the starter Pokémon group.
	 * 	@return ID of the selected gift Pokémon starter.
	 */
	static int CallStarterSelection(int starterSet) {
		CallStarterSelection(starterSet);
		return GetSelectedStarterPokemon();
	}

	#ifdef SANGO
	/**
	 * 	Pops up a dialog for renaming a party member.
	 * 	This function is VERY buggy and often locks up the script completely for no reason. Use with caution and refrain from out of context calls.
	 * 	
	 * 	@param successWk Work value to which to store whether the dialog was confirmed (1) or dismissed (0);
	 * 	@param partyIdx Index of the party Pokémon.
	 * 	@param fade True if the layout should automatically fade in and out.
	 * 	@param setToDefaultFirst True if the Pokémon should be set to the default name before the dialog pops up, regardless of the oncoming result.
	 */
	static native void CallPokePartyNameInput(int successWk, int wk2, int partyIdx, boolean fade, boolean setToDefaultFirst);
	#else if XY
	/**
	 * 	Pops up a dialog for renaming a party member.
	 * 	This function is VERY buggy and often locks up the script completely for no reason. Use with caution and refrain from out of context calls.
	 * 	
	 * 	@param successWk Work value to which to store whether the dialog was confirmed (1) or dismissed (0);
	 * 	@param partyIdx Index of the party Pokémon.
	 * 	@param fade True if the layout should automatically fade in and out.
	 */
	static native void CallPokePartyNameInput(int successWk, int wk2, int partyIdx, boolean fade);
	#endif
}