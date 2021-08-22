package field.event;

import battle.WildBattleResult;

public class BattleEvent {

	/**
	Force-hides the battle background's Pokémon pedestal.
	*/
	static final int BTLFLAG_NO_PEDESTAL			= 0x0001;
	/**
	Makes the battle camera animations play at a lower Y position (often below the ground).
	*/
	static final int BTLFLAG_LOW_ALTITUDE_CAMERA		= 0x0002;
	/**
	Forces the player's party to be solely the Mega Lucario received from Korrina in Tower of Mastery.
	*/
	static final int BTLFLAG_MEGA_LUCARIO 			= 0x0100;
	/**
	Allows trainer battles to retain the currently playing event BGM.
	(CTRMap extension flag)
	*/
	static final int BTLFLAG_RETAIN_FIELD_BGM_EX 	= 0x8000;

	#ifdef SANGO
	/**
	Reserved value for the nextBGM param used to represent the current Field BGM.
	*/
	static final int BTL_NEXTBGM_NONE				=     -1;
	#endif

	#ifdef SANGO
	/**
	*	Starts a static wild encounter battle without needing to have the Field module loaded.
	*
	*	@param encID The index of the static wild encounter.]
	*	@param enableBattleBGM True to use the battle intro's BGM, false to retain the currently playing BGM.
	*	@param needsManualFieldReopen True to require explicit reloading of the Field module using _FieldOpen, false to automatically reload it when the battle ends.
	*	@param nextBGM A BGM ID to switch to after the battle ends, or BTL_NEXTBGM_NONE to preserve the current Field BGM.
	*/
	static native void _CallWildBattleWithoutField(int encId, boolean enableBattleBGM, boolean needsManualFieldReopen, int nextBGM);
	#endif

	#ifdef XY
	/**
	*	Starts a static wild encounter battle without needing to have the Field module loaded.
	*
	*	@param encID The index of the static wild encounter.
	*/
	static native void _CallWildBattleWithoutField(int encId);
	#endif

	/**
	*	Starts a static wild encounter battle.
	*
	*	@param encID The index of the static wild encounter.
	*/
	static native void CallWildBattle(int encId);

	/**
	*	Starts a wild battle with a random Rock Smash encounter of the current zone.
	*/
	static native void CallWildBattleRockCrash();

	/**
	 * 	Gets the result of the last wild battle.
	 */
	static native WildBattleResult WildBattleResultGet();

	/**
	 * 	Calls a blackout sequence after being defeated by a Wild Pokémon.
	 */
	static native void _CallWildLose();

	/**
	*	Starts a trainer battle.
	*
	*	@param isDouble True if there should be two opposing trainers.
	*	@param trainerId Index of the trainer data, or the primary trainer data of a double battle.
	*	@param trainerIdSec Index of the secondary trainer data of a double battle. The parameter is ignored in single battles.
	*	@param flags Boolean bitfield of BTLFLAG constants.
	*	@param battleForeground The main battle field resource number.
	*	@param battleBackground The far battle field resource number.
	*	@param battleIntro Index of the battle intro and sound environment.
	*/
	static native void _CallTrainerBattleCore(boolean isDouble, int trainerId, int trainerIdSec, int flags, int battleForeground, int battleBackground, int battleIntro);

	/**
	*	Starts an Inverse battle with Psychic/Proprietor Inver.
	*	The battle will use the generic interior background/foreground.
	*
	*	@param unused Unused parameter.
	*	@param levels The level of all of Inver's Pokémon.
	*	@param ivs The IV value of all of Inver's Pokémon's IVs.
	*/
	static native void CallSakasaBattle(int unused, int levels, int ivs);

	/**
	 * 	Calls a blackout sequence after being defeated by a Trainer.
	 */
	static native void CallTrainerLose();

	/**
	*	Starts a game-specific Pokémon catching tutorial battle.
	*	The battle will not allow user input.
	*/
	static native void CallCaptureDemo();
}