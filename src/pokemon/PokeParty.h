package pokemon;

import pokemon.PokePartyFilter;
import pokemon.PokeAmieParam;
import pokemon.PokeParam;
import pokemon.PokeParamSet;
import pokemon.FurfrouParam;

public class PokeParty {

	static final int POKE_PARTY_MAX = 6;
	
	static final int POKE_PARTY_ALL = -1;

	static final int POKE_WAZA_ANYSLOT = 5;
	static final int POKE_WAZA_NONE = 0;

	/**
	 * 	Gets the number of party Pokémon that match a certain condition.
	 * 	
	 * 	@param filter Filter that a party Pokémon must meet to be counted towards the total.
	 */
	static native int PokePartyGetCount(PokePartyFilter filter);

	/**
	*	Adds a Pokémon to the player's party.
	*
	*	@param giftPokeNo Number of the Gift Pokémon in the data table.
	*	@param moveToFirstSlot Move the Pokémon to the first party slot.
	*/
	static native void PokePartyAdd(int giftPokeNo, boolean moveToFirstSlot);

	/**
	 * 	Moves a party Pokémon to a Pokémon Storage System PC Box.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@return True if the operation succeeded, or false if all boxes are full.
	 */
	static native boolean PokePartyToBox(int partyIdx);

	/**
	 * 	Changes the Forme of a party Pokémon.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@param newForme Species-specific ID of the Pokémon forme.
	 */
	static native void PokePartyChangeFormNo(int partyIdx, int newForme);

	/**
	 * 	Changes the Forme of a party Rotom.
	 * 	
	 * 	@param partyIdx Index of the Rotom in the party.
	 * 	@param formeMoveIdx Index of the to-be-learned forme-specific special move.
	 * 	@param newForme ID of the Rotom forme.
	 */
	static native void PokePartyChangeRotomFormNo(int partyIdx, int formeMoveIdx, int newForme);

	/**
	 * 	Changes the Forme of a party Furfrou.
	 * 	
	 * 	@param partyIdx Index of the Furfrou in the party.
	 * 	@param newForme ID of the Furfrou forme.
	 */
	static native void PokePartyChangePoodleFormNo(int partyIdx, int newForme);

	/**
	 * 	Gets the number of learned moves of a party Pokémon.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@return Number of learned moves, between 0 and 4.
	 */
	static native int PokePartyGetWazaCount(int partyIdx);

	/**
	 * 	Checks if any party member, or a given party Pokémon knows a certain move.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party, or POKE_PARTY_ALL to search through entire party.
	 * 	@param moveId ID of the move.
	 * 	@return True if the specified party member(s) know(s) the given move.
	 */
	static native boolean PokePartyHaveWaza(int partyIdx, int moveId);

	/**
	 * 	Gets the move in a given move slot of a party Pokémon.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@param moveIdx Index of the move slot, between 0 and 4.
	 * 	@return ID of the move, or POKE_WAZA_NONE if there is no move learned in the slot.
	 */
	static native int PokePartyGetWazaID(int partyIdx, int moveIdx);

	/**
	 * 	Teaches a move to a party Pokémon, or deletes one.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@param moveIdx Index of the move slot, or POKE_WAZA_ANYSLOT to teach to the first available slot.
	 * 	@param moveId ID of the move, or POKE_WAZA_NONE to delete the move that is currently in the slot.
	 */
	static native void PokePartySetWaza(int partyIdx, int moveIdx, int moveId);

	/**
	 * 	Checks if the player is a party Pokémon's original trainer.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@return True if the OT of the Pokémon matches the trainer ID.
	 */
	static native boolean PokePartyIsOwner(int partyIdx);

	/**
	 * 	Increases a Pokémon Amie stat of a Pokémon.
	 * 	
	 * 	@param partyIdx Index of the party Pokémon, or POKE_PARTY_ALL to target the entire party.
	 * 	@param param The parameter to increment.
	 * 	@param amount Increment amount.
	 */
	static native void PokePartyAddParam(int partyIdx, PokeAmieParam param, int amount);

	/**
	 * 	Gets a party Pokémon property.
	 * 	
	 * 	@param partyIdx Index of the party Pokémon.
	 * 	@param param The property to retrieve.
	 * 	@param subParam Property-specific sub-param, f.e. a move index.
	 */
	static native int PokePartyGetParam(int partyIdx, PokeParam param, int subParam);

	/**
	 * 	Sets a party Pokémon property.
	 * 	
	 * 	@param partyIdx Index of the party Pokémon.
	 * 	@param param The property to set.
	 * 	@param subParam Property-specific sub-param.
	 * 	@param value The value to set the property to.
	 */
	static native void PokePartySetParam(int partyIdx, PokeParamSet param, int subParam, int value);

	/**
	 * 	Increases the level of a party Pokémon by a given amount.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@param amount Amount of levels to add.
	 * 	@return False if the Pokémon's level has already been maxed out, true if otherwise.
	 */
	static native boolean PokePartyLevelUp(int partyIdx, int amount);

	/**
	 * 	Sets a party Pokémon's nickname to the species name.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@return True if the operation was successful.
	 */
	static native boolean PokePartySetDefaultName(int partyIdx);

	/**
	 * 	Checks if a party Pokémon can relearn at least one move.
	 * 	
	 * 	@param partyIdx Index of the party Pokémon.
	 * 	@return True if there is at least one move that can be relearned.
	 */
	static native boolean PokePartyCheckWazaRemind(int partyIdx);

	/**
	 * 	Checks if a party Pokémon is capable of fighting in a Sky Battle.
	 * 	
	 * 	@param partyIdx Index of the Pokémon in the party.
	 * 	@return True if the specified Pokémon meets the conditions needed for participating in a Sky Battle.
	 */
	static native boolean PokePartyCheckSkyBattle(int partyIdx);
	
	/**
	*	Fully heals all of the player's party Pokémon.
	*/
	static native void PokePartyRecoverAll();
	
	#ifdef SANGO
	/**
	*	Fully heals a given Pokémon in the player's party.
	*
	*	@param partyIdx Index of the Pokémon in the party.
	*/
	static native void PokePartyRecover(int partyIdx);
	#endif

	static int PokePartyFindByParam(PokeParam param, int value) {
		return PokePartyFindByParam(param, 0, value);
	}

	/**
	 * 	Returns the index of the first party Pokémon whose given property has a certain value.
	 * 	
	 * 	@param param The property to evaluate.
	 * 	@param subParam The property-specific sub-parameter to evaluate.
	 * 	@param value The value that 'param' of a Pokémon should have for a positive match.
	 * 	@return Index of the first matching Pokémon, or -1 if none found.
	 */
	static int PokePartyFindByParam(PokeParam param, int subParam, int value) {
		for (int i = 0; i < POKE_PARTY_MAX; i++) {
			if (PokePartyGetParam(i, param, subParam) == value) {
				return i;
			}
		}
		return -1;
	}

	/**
	 * 	Returns the index of the first party Pokémon of a certain species.
	 * 	
	 * 	@param species The desired Pokémon species.
	 * 	@return Index of the first matching Pokémon, or -1 if none found.
	 */
	static int PokePartyFindBySpecies(int species) {
		return PokePartyFindByParam(PokeParam.SPECIES, species);
	}
}