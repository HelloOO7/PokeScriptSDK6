package field.event.dialog.msg;

public bitflags enum MsgFlags {
	TEXTALIGN_CENTER,
	TEXTALIGN_STRETCH,
	TEXT_INSTANT,
	FRAMEALIGN_TOPLEFT,
	FRAMEALIGN_TOPRIGHT,
	FRAMEALIGN_TOPOFFSET,
	FRAMEALIGN_BOTLEFT,
	FRAMEALIGN_BOTRIGHT,
	FRAMEALIGN_BOTTOM,
	FRAME_NOATTACH,

	TEXTALIGN_RIGHT = 14,
	SYS_AUTO_WINDOW_CHOICE,
	
	SYS_SKIP_WAIT_FOR_WINDOW_RT = 16
}