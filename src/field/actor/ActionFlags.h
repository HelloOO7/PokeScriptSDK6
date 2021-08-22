package field.actor;

public bitflags enum ActionFlags {
	FLAG0,
	HALFSIT_ENABLE,
	HALFSIT_ACTIVE_RT, //Set at runtime
	DIRECTION_CHANGE_DISABLE,
	SET_AUTO_ANIME,
	MSG_SFX_DISABLE,

	//ORAS exclusive flag
	#ifdef SANGO
	SEIZA_ENABLE
	#endif
}
