package trainer;

public enum TrainerMessageType {
	//In ORAS, the files are encoded with msgtype + 1. No effect on scripts.
	/**
	 * 	Dialogue shown when the trainers' eyes meet.
	 */
	FIELD_CLASH = 0,
	/**
	 * 	Dialogue shown in-battle right as the trainer is defeated.
	 */
	BATTLE_LOSE,
	/**
	 * 	Dialogue triggered by interacting with a defeated trainer in the field.
	 */
	FIELD_DEFEATED,
	/**
	 * 	Dialogue shown when the trainers' eyes meet - primary double pair member.
	 */
	FIELD_CLASH_DOUBLE_PRI,
	/**
	 * 	Dialogue shown when the trainers' eyes meet - secondary double pair member.
	 */
	FIELD_CLASH_DOUBLE_SEC,
	/**
	 * 	Dialogue triggered by interacting with the primary member of a defeated trainer pair in the field.
	 */
	FIELD_DEFEATED_DOUBLE_PRI,
	/**
	 * 	Dialogue triggered by interacting with the secondary member of a defeated trainer pair in the field.
	 */
	FIELD_DEFEATED_DOUBLE_SEC,
	/**
	 * 	Dialogue triggered when a player with less than two Pokémon in their party attempts to challenge the primary member of a trainer pair.
	 */
	FIELD_NOT_ENOUGH_POKE_DOUBLE_PRI = 8,
	/**
	 * 	Dialogue triggered when a player with less than two Pokémon in their party attempts to challenge the secondary member of a trainer pair.
	 */
	FIELD_NOT_ENOUGH_POKE_DOUBLE_SEC,
	/**
	 * 	Implicit NOT_ENOUGH_POKE constant for single battles. Unused.
	 */
	FIELD_NOT_ENOUGH_POKE,

	#ifdef SANGO
	/**
	 * 	Dialogue shown after battle in the field as the trainer is about to give the player a prize item.
	 */
	FIELD_GIVE_ITEM = 18,
	/**
	 * 	Dialogue shown after battle in the field as the primary member of the trainer pair is about to give the player a prize item.
	 */
	FIELD_GIVE_ITEM_DOUBLE_PRI,
	/**
	 * 	Dialogue shown after battle in the field as the secondary member of the trainer pair is about to give the player a prize item.
	 */
	FIELD_GIVE_ITEM_DOUBLE_SEC
	#endif
}