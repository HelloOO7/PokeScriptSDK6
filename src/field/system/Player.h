package field.system;

import field.system.PlayerGender;

public class Player {
	/**
	 * 	Gets the player's TID, or a union of the TID and SID.
	 * 	
	 * 	@param simple True to get only the TID, false to get the full ID set.
	 * 	@return The player TID or TID/SID.
	 */
	static native int PlayerGetID(boolean simple);

	/**
	 * 	Gets the player's chosen gender.
	 */
	static native PlayerGender PlayerGetSex();

	/**
	 * 	Gets the amount of money in the player's wallet.
	 */
	static native int PlayerGetMoney();

	/**
	 * 	Sets the amount of money in the player's wallet to an absolute value.
	 * 	
	 * 	@param value Desired amount of money.
	 */
	static native void PlayerSetMoney(int value);

	/**
	 * 	Increases the amount of money in the player's wallet by a given amount.
	 * 	
	 * 	@param amount Amount of money to give.
	 */
	static native void PlayerAddMoney(int amount);

	/**
	 * 	Subtracts a given amount of money from the player's balance.
	 * 	
	 * 	@param amount Amount of money to take away.
	 */
	static native void PlayerSubMoney(int amount);

	/**
	 * 	Checks if the player can afford an item.
	 * 	
	 * 	@param price Price of the item.
	 */
	static boolean PlayerCheckMoney(int price) {
		return PlayerGetMoney() >= price;
	}

	/**
	 * 	Gets the player's Battle Point balance.
	 */
	static native int PlayerGetBP();

	/**
	 * 	Sets the player's Battle Point balance to an absolute value.
	 * 	
	 * 	@param value Number of Battle Points that the player should have.
	 */
	static native void PlayerSetBP(int value);

	/**
	 * 	Increases or decreases the player's Battle Point balance.
	 * 	
	 * 	@param offset A positive or negative amount of BP, to add or subtract respectively.
	 */
	static void PlayerChangeBP(int offset) {
		PlayerSetBP(PlayerGetBP() + offset);
	}

	/**
	 * 	Gets a player high score, f.e. chain fishing streak.
	 * 	
	 * 	@param recordId ID of the high score.
	 * 	@return The high score.
	 */
	static native int RecordGet(int recordId);

	/**
	 * 	Increments a player high score a certain amount.
	 * 	
	 * 	@param recordId ID of the high score.
	 * 	@param amount Amount to increase the high score by.
	 */
	static native void RecordAdd(int recordId, int amount);

	/**
	 * 	Sets a player high score to an absolute value.
	 * 	
	 * 	@param recordId ID of the high score.
	 * 	@param value Desired value of the high score.
	 */
	static native void RecordSet(int recordId, int value);

	/**
	 * 	Checks if a Japanese-language player uses the Kanji alphabet.
	 */
	static native boolean PlayerIsKanjiMode();

	/**
	 * 	Changes a Japanese-language player's alphabet.
	 * 	
	 * 	@param kanji True to use Kanji, false to use Kana.
	 */
	static native void PlayerSetKanjiMode(boolean kanji);
}