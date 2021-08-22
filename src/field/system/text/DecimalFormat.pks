package field.system.text;

public enum DecimalFormat {
	/**
	 *	Does not format nor align the number in any way.
	 */
	NONE,
	/**
	 *	Prepends the number with gaps where necessary and anchors it to the right.
	 */
	LEADING_GAPS,
	/**
	 *	Prepends the number with zeros where necessary and anchors it to the right.
	 */
	LEADING_ZEROS
}