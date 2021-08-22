package trainer;

import trainer.TrainerHandle;
import trainer.TrainerMessageType;
import trainer.TrainerSPType;
import trainer.TrainerMessageTypeRequest;
import battle.BtlRule;

public class Trainer {
	/**
	 * 	Gets the Script ID of the actor bound to a trainer handle.
	 * 	
	 * 	@param tr Handle of the trainer.
	 * 	@return Script ID of the actor resolved from the trainer handle.
	 */
	#ifdef SANGO
	static native int TrainerGetScrID(TrainerHandle tr);
	#else if XY
	static int TrainerGetScrID(TrainerHandle tr) {
		return GetBTLTrainerScrID(tr);
	}
	
	internal static native int GetBTLTrainerScrID(TrainerHandle tr);
	#endif

	/**
	 * 	Gets the Actor ID of the actor bound to a trainer handle.
	 * 	
	 * 	@param tr Handle of the trainer.
	 * 	@return ID of the actor resolved from the trainer handle.
	 */
	#ifdef SANGO
	static native int TrainerGetObjID(TrainerHandle tr);
	#else if XY
	static int TrainerGetObjID(TrainerHandle tr) {
		return GetBTLTrainerObjID(tr);
	}
	
	internal static native int GetBTLTrainerObjID(TrainerHandle tr);
	#endif

	/**
	 * 	Gets the narrowed TrainerMessageType for a general request.
	 * 	
	 * 	@param trID ID of the trainer, used to determine battle rule type.
	 * 	@param req Type of the requested message type.
	 * 	@return The final TrainerMessageType valid for the trainer.
	 */
	static native TrainerMessageType TrainerTalkTypeGet(int trID, TrainerMessageTypeRequest req);

	/**
	 * 	Gets the MSGID of the message line corresponding to a defined trainer dialogue of a trainer.
	 * 	
	 * 	@param trID ID of the trainer.
	 * 	@param type Trainer dialogue type.
	 * 	@return Printable message ID of the dialogue.
	 */
	static native int TrainerGetMsgID(int trID, TrainerMessageType type);

	/**
	 * 	Gets the battle type of a trainer.
	 * 	
	 * 	@param trID ID of the trainer.
	 * 	@return BtlRule battle type.
	 */
	static native BtlRule TrainerBattleRuleGet(int trID);

	/**
	 * 	Gets the prize item of a trainer.
	 * 	
	 * 	@param trID ID of the trainer.
	 * 	@return Global item ID of the prize item, or 0 if none.
	 */
	static native int TrainerItemGet(int trID);

	/**
	 * 	Gets the TrainerSPType of a trainer.
	 * 	See the TrainerSPType class for possible values.
	 * 	
	 * 	@param trID ID of the trainer.
	 */
	static native TrainerSPType TrainerSPTypeGet(int trID);
}