package trainer;

/**
 * 	Request enum for trainer message ID types.
 * 	These constants technically belong to the same enum as TrainerMessageType, but I decided separating them makes it less confusing.
 */
public enum TrainerMessageTypeRequest {
	#ifdef SANGO
	FIELD_CLASH_REQ = 22,
	#else if XY
	FIELD_CLASH_REQ = 19,
	#endif
	FIELD_NOT_ENOUGH_POKE_REQ,
	FIELD_DEFEATED_REQ,

	#ifdef SANGO
	FIELD_GIVE_ITEM_REQ
	#endif
}