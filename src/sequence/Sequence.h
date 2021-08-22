package sequence;

public class Sequence {
	#ifdef SANGO
	static final int SEQ_CURRENT_BGM_FADEOUT_NONE = -1;
	#endif

	/**
	*	Plays a sequenced scene.
	*
	*	@param sequenceId Index of the sequence binary in the Sequence GARC.
	*	@param hasExtraParams True if the sequence should use the exPrm fields.
	*	@param exPrm1...exPrm6 Sequence-specific special parameters.
	#ifdef SANGO
	*	@param bgmFadeTime Length of the current BGM fade-out, or SEQ_CURRENT_BGM_FADEOUT_NONE to transition instantly.
	#endif
	*/
	#ifdef XY
	static native void CallApplicationDemo(int sequenceId, boolean hasExtraParams, int exPrm1, int exPrm2, int exPrm3, boolean exPrm4, boolean exPrm5, int exPrm6);
	#else if SANGO
	static native void CallApplicationDemo(int sequenceId, boolean hasExtraParams, int exPrm1, int exPrm2, int exPrm3, boolean exPrm4, boolean exPrm5, int exPrm6, int bgmFadeTime);
	#endif

	/**
	*	Plays a sequenced scene without the need to have the Field module loaded.
	*
	*	@param sequenceId Index of the sequence binary in the Sequence GARC.
	*	@param hasExtraParams True if the sequence should use the exPrm fields.
	*	@param exPrm1...exPrm6 Sequence-specific special parameters.
	*	@param keepSeqBGM True if the sequence's BGM track should not be stopped after the sequence finishes.
	#ifdef SANGO
	*	@param bgmFadeTime Length of the current BGM fade-out, or SEQ_CURRENT_BGM_FADEOUT_NONE to transition instantly.
	#endif
	*/
	#ifdef XY
	static native void _CallApplicationDemoNotFieldControl(int sequenceId, boolean hasExtraParam, int exPrm1, int exPrm2, int exPrm3, boolean exPrm4, boolean exPrm5, int exPrm6, boolean keepSeqBGM);
	#else if SANGO
	static native void _CallApplicationDemoNotFieldControl(int sequenceId, boolean hasExtraParam, int exPrm1, int exPrm2, int exPrm3, boolean exPrm4, boolean exPrm5, int exPrm6, boolean keepSeqBGM, int bgmFadeTime);
	#endif
}