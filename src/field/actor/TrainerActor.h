package field.actor;

import trainer.TrainerHandle;
import field.actor.Direction;

public class TrainerActor {
	/**
	 * 	Checks if an actor is a double battle trainer.
	 * 	
	 * 	@param actor ID of the actor.
	 * 	@return True if the actor is a double battle trainer.
	 */
	static native boolean TrainerBattleRuleIsDouble(int actor);

	/**
	 * 	Gets the facing direction of a trainer actor handle.
	 * 	
	 * 	@param tr Handle of the trainer.
	 * 	@return Facing direction of the actor resolved from the handle.
	 */
	#ifdef SANGO
	static native Direction TrainerGetDir(TrainerHandle tr);
	#else if XY
	static Direction TrainerGetDir(TrainerHandle tr) {
		return GetBTLTrainerDir(tr);
	}
	
	internal static native Direction GetBTLTrainerDir(TrainerHandle tr);
	#endif

	/**
	 * 	Clears a trainer's MoveCode and EventType to no longer seek opponents.
	 * 	
	 * 	@param actor ID of a trainer Actor.
	 */
	#ifdef SANGO
	static native void TrainerMoveOff(int actor);
	#else if XY
	static void TrainerMoveOff(int actor) {
		return OffBTLTrainerMove(actor);
	}
	internal static native void OffBTLTrainerMove(int actor);
	#endif
}