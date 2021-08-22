package field.actor;

import field.actor.ActionFlags;
import field.actor.Direction;
import field.actor.PlayerActor;
import field.actor.Actor;
import field.actor.Actions;
import field.actor.ActionCmd;
import field.system.EventWork;
import field.event.dialog.msg.MsgFrame;
import field.event.dialog.msg.MsgFlags;
import field.event.dialog.msg.Message;
import sound.SE;

public class InteractActor {

	static final int INTERACT_ACTOR_SCROBJ 			= 	    -1;

	static final int WKID_INTERACT_ACTOR_SCROBJ 		= 	0x8011;
	static final int WKID_INTERACT_ACTOR_FLAGS 		= 	0x8012;
	static final int WKID_INTERACT_ACTOR_CURRENT 	=	0x8013;

	/**
	 * 	Checks if there is an actor currently being interacted with.
	 * 	
	 * 	@return True if INTERACT_ACTOR_SCROBJ represents a valid actor.
	 */
	static native boolean TalkMdlIsExist();

	#ifdef SANGO
	/**
	 * 	Sets reserved work values for an Actor interaction.
	 * 	
	 * 	@param actor The actor to target, or INTERACT_ACTOR_SCROBJ for the actor that invoked the script.
	 * 	@param flags Bitflags for various action parameters.
	 * 	@param returnDir The desired facing direction of the actor.
	 * 	@param isHalfSitSkel True if the player should crouch in front of the NPC.
	 * 	
	 * 	@return The flags param with runtime bits set.
	 */
	static native ActionFlags _TalkMdlStartInit(int actor, ActionFlags flags, Direction returnDir, boolean isHalfSitSkel);
	#else if XY
	/**
	 * 	Sets reserved work values for an Actor interaction.
	 * 	
	 * 	@param actor The actor to target, or INTERACT_ACTOR_SCROBJ for the actor that invoked the script.
	 * 	@param flags Bitflags for various action parameters.
	 * 	
	 * 	@return The flags param with runtime bits set.
	 */
	static native ActionFlags _TalkMdlStartInit(int actor, ActionFlags flags);
	#endif

	/**
	 * 	Resets reserved work values after an Actor interaction.
	 * 	If the values aren't reset, any subsequent _TalkMdlStartInit calls will fail.
	 * 	
	 * 	@param actor The actor to target, or INTERACT_ACTOR_SCROBJ for the actor that invoked the script.
	 * 	@param flags Bitflags for various action parameters.
	 */
	static native ActionFlags _TalkMdlEndInit(int actor, ActionFlags flags);

	/**
	 * 	Locks eye contact between the player and an actor.
	 * 	
	 * 	@param actor The actor to target, or INTERACT_ACTOR_SCROBJ for the actor that invoked the script.
	 */
	static native void TalkMdlSetEyeToEye(int actor);

	/**
	 * 	Unlocks eye contacts between the player and an actor.
	 * 	
	 * 	@param actor The actor to target, or INTERACT_ACTOR_SCROBJ for the actor that invoked the script.
	 */
	static native void TalkMdlClearEyeToEye(int actor);

	/**
	*	Makes an Actor look at another.
	*
	*	@param lookWho ID of the Actor, or INTERACT_ACTOR_SCROBJ.
	*	@param lookAt The Actor that lookWho should be looking at.
	*/
	static native void TalkMdlSetEye(int lookWho, int lookAt);
	
	/**
	*	Resets an Actor that is currently looking at another to no longer look at them.
	*
	*	@param lookWho The Actor to reset.
	*/
	static native void TalkMdlClearEye(int lookWho);

	/**
	 * 	Plays the TR_TALK animation on an actor.
	 * 	
	 * 	@param actor The actor to target, or INTERACT_ACTOR_SCROBJ for the actor that invoked the script.
	 */
	static native void TalkMdlSetTalkMotion(int actor);

	/**
	*	Sets the facing direction of an InteractActor.
	*
	*	@param dir The orientation to set the target to.
	*	@param target ID of the Actor, or INTERACT_ACTOR_SCROBJ.
	*/
	static native void TalkMdlSetDir(Direction dir, int target);

	static int GetCurrentInteractActor() {
		return EventWork.WorkGet(WKID_INTERACT_ACTOR_CURRENT);
	}

	static ActionFlags GetCurrentActionFlags() {
		return EventWork.WorkGet(WKID_INTERACT_ACTOR_FLAGS);
	}

	static void CallBasicMessageInteraction(int msgId, MsgFrame frame, MsgFlags flags) {
		#ifdef SANGO
		BeginPlayerInteraction(ActionFlags.HALFSIT_ENABLE | ActionFlags.SET_AUTO_ANIME | ActionFlags.SEIZA_ENABLE);
		#else if XY
		BeginPlayerInteraction(ActionFlags.HALFSIT_ENABLE | ActionFlags.SET_AUTO_ANIME);
		#endif

		Message.ShowMessageBox(msgId, Actor.ACTOR_CURRENT_SCROBJ, frame, Message.MSGWIN_NO_AUTOHIDE, flags, false);

		EndPlayerInteraction();
	}

	static void BeginPlayerInteraction(ActionFlags flags) {
		#ifdef SANGO
		flags = _TalkMdlStartInit(INTERACT_ACTOR_SCROBJ, flags, PlayerActor.PlayerGetReturnDir(), Actor.MdlIsHalfSitSkelPreset(Actor.ACTOR_CURRENT_SCROBJ));
		#else if XY
		flags = _TalkMdlStartInit(INTERACT_ACTOR_SCROBJ, flags);
		#endif

		int actualActor = GetCurrentInteractActor();

		if ((flags & ActionFlags.MSG_SFX_DISABLE) == 0) {
			PlayMsgSFX();
		}

		if ((flags & ActionFlags.DIRECTION_CHANGE_DISABLE) == 0) {
			TurnActorTowardsPlayer(actualActor);
		}

		if ((flags & ActionFlags.HALFSIT_ENABLE) != 0 && (flags & ActionFlags.HALFSIT_ACTIVE_RT) != 0) {
			SetPlayerToHalfSitAnm();
		}
		#ifdef SANGO
		else if ((flags & ActionFlags.SEIZA_ENABLE) != 0 && Actor.MdlGetMoveCode(actualActor) == 60) {
			SetPlayerToSeizaAnm();
		}
		#endif
		else {
			TalkMdlSetEyeToEye(actualActor);
		}

		if ((flags & ActionFlags.SET_AUTO_ANIME) != 0) {
			TalkMdlSetTalkMotion(actualActor);
		}
	}

	static void EndPlayerInteraction() {
		int actualActor = GetCurrentInteractActor();
		ActionFlags flags = GetCurrentActionFlags();
		
		flags = _TalkMdlEndInit(INTERACT_ACTOR_SCROBJ, flags);

		if ((flags & ActionFlags.HALFSIT_ENABLE) != 0 && (flags & ActionFlags.HALFSIT_ACTIVE_RT) != 0 && Actor.MdlIsHalfSitSkelPreset(actualActor)) {
			ResetPlayerFromHalfSitAnm();
		}
		#ifdef SANGO
		else if ((flags & ActionFlags.SEIZA_ENABLE) != 0 && Actor.MdlGetMoveCode(actualActor) == 60) {
			ResetPlayerFromSeizaAnm();
		}
		else {
			TalkMdlClearEyeToEye(actualActor);
		}

		Actions.MdlAcmdWaitUpdate(PlayerActor.ACTOR_PLAYER);

		if ((flags & ActionFlags.SET_AUTO_ANIME) != 0) {
			Actor.MdlSetWaitAnimeReq(Actor.ACTOR_CURRENT_SCROBJ);
		}
		
		#endif
	}

	static void PlayMsgSFX() {
		SE.SEPlay(393216);
	}

	static void TurnActorTowardsPlayer(int actor) {
		Direction dir = Actor.MdlGetDirDisp(actor);
		Direction playerDirInv = PlayerActor.PlayerGetReturnDir();

		#ifdef SANGO
		if (Actor.MdlCanUseTurnAcmd(actor) && dir != playerDirInv) {
			SetInteractActorAcmdSimple(actor, ActionCmd.TURN_8F, playerDirInv);
		} else {
		#endif
			SetInteractActorAcmdSimple(actor, ActionCmd.DIR_ROTATE_4F, playerDirInv);
		#ifdef SANGO
		}
		#endif
		Actions.MdlAcmdWaitUpdate(actor);
	}

	static void SetPlayerToHalfSitAnm() {
		SetInteractPlayerAcmdSimple(ActionCmd.MOTION_101);
	}

	static void ResetPlayerFromHalfSitAnm() {
		SetInteractPlayerAcmdSimple(ActionCmd.MOTION_102);
	}

	#ifdef SANGO
	static void SetPlayerToSeizaAnm() {
		SetInteractPlayerAcmdSimple(ActionCmd.MOTION_170);
	}

	static void ResetPlayerFromSeizaAnm() {
		SetInteractPlayerAcmdSimple(ActionCmd.MOTION_171);
	}
	#endif

	static void SetInteractPlayerAcmdSimple(ActionCmd acmd) {
		SetInteractPlayerAcmdSimple(acmd, Direction.CURRENT);
	}

	static void SetInteractPlayerAcmdSimple(ActionCmd acmd, Direction dir) {
		Actions.MdlAcmdInit(PlayerActor.ACTOR_PLAYER);
		Actions.MdlAcmdSet(acmd, dir, 1);
		Actions.MdlAcmdSetEnd();
	}

	static void SetInteractActorAcmdSimple(int actor, ActionCmd acmd, Direction dir) {
		Actions.MdlAcmdInit(actor);
		Actions.MdlAcmdSet(acmd, dir, 1);
		Actions.MdlAcmdSetEnd();
	}
}