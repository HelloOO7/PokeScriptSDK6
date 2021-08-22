package field.system.text;

import field.system.text.DecimalFormat;
import field.system.text.ItemFormat;
import field.system.text.TextRegister;
import pokemon.PokeType;
import pokemon.PokeNature;
import battle.BtlRule;
import bag.ItemPocket;
import contest.ContestPortraitRoom;
import contest.ContestRank;
import contest.ContestCondition;

public class TextVariables {
	/**
	 * 	Loads a resident preloaded text line to a strbuf.
	 * 	
	 * 	@param reg The resident text storage to choose from.
	 * 	@param strbuf The strbuf to copy into.
	 * 	@param param A reg-specific parameter. For example, the MONSNAME register interprets it as a Dex No.
	 */
	static native void _WordSetRegister(TextRegister reg, int strbuf, int param);

	/**
	 * 	Loads an entire message line into a strbuf and carries out a handful of unknown language-specific operations.
	 * 	
	 * 	@param strbuf The strbuf to copy into.
	 * 	@param msgId Index of the message to be copied in the currently loaded text file.
	 */
	static native void WordSetWordWithCount(int strbuf, int msgId, boolean a3, boolean a4);

	/**
	 * 	Loads an arbitrary integer to a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to format the number into.
	 * 	@param number The integer constant.
	 * 	@param maxDigits Maximum number of printed decimal places.
	 * 	@param format Method of formatting the printed integer.
	 */
	static native void WordSetNumber(int strbuf, int number, int maxDigits, DecimalFormat format);

	/**
	 * 	Loads a number into strbuf no. 8 for money dialog manipulation.
	 * 	
	 * 	@param value Amount of money, usually equal to that in the player's wallet.
	 * 	@param maxDigits Maximum number of printed decimal places.
	 * 	@param format Method of formatting the printed money amount.
	 */
	static native void WordSetMoney(int value, int maxDigits, DecimalFormat format);

	/**
	 * 	Loads the player's name into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 */
	static native void WordSetPlayerNickName(int strbuf);

	#ifdef XY
	/**
	 * 	Loads the nickname that the player has chosen their rivals to call them with in Aquacorde Town into a strbuf.
	 * 	Oddly enough, I'm pretty sure this is actually a suffix.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 */
	static native void WordSetPlayerNickNamePrefix(int strbuf);
	#endif

	/**
	 * 	Loads the Rival's name to a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 */
	static native void WordSetRivalName(int strbuf);

	/**
	 * 	Loads the name of a specified Trainer into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param trID Index of the trainer data.
	 */
	static native void WordSetTrainerName(int strbuf, int trID);

	/**
	 * 	Loads the name of a Trainer Class into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param trClass Index of the trainer class.
	 */
	static native void WordSetTrainerTypeName(int strbuf, int trClass);

	/**
	 * 	Loads the name of the Trainer Class of a Trainer into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param trID Index of the trainer data.
	 */
	static native void WordSetTrainerTypeNameFromTrainerID(int strbuf, int trID);

	/**
	 * 	Loads the name of an Item into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param itemID Index of the item.
	 * 	@param format Method of formatting the item name - either as singular or plural.
	 */
	static native void WordSetItemName(int strbuf, int itemID, ItemFormat format);

	/**
	 * 	Loads the name of an Item Pocket into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param pocket Internal ID of the pocket.
	 */
	static native void WordSetItemPocketName(int strbuf, ItemPocket pocket);

	/**
	 * 	Loads the name of a Berry Item into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param itemID Item ID of the Berry.
	 */
	static native void WordSetNutsTypeName(int strbuf, int itemID);

	/**
	 * 	Loads the name of a battle style into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param rule The battle style's internal ID.
	 */
	static native void WordSetBtlRuleTypeName(int strbuf, BtlRule rule);

	/**
	 * 	Loads the customized name of a PC Box into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param boxNo Number of the box in the save file.
	 */
	static native void WordSetBoxTrayName(int strbuf, int boxNo);

	/**
	 * 	Loads the nickname of a party Pokémon into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param partyIndex Index of the Pokémon in the party.
	 */
	static native void WordSetTemotiMonsNickName(int strbuf, int partyIndex);

	/**
	 * 	Loads the nickname of a Box Pokémon into a strbuf.
	 * 	This method is unused.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param pcMonsIndex Absolute index of the Pokémon in the Pokémon Storage System. It is represented as (boxNo * 30) + positionInBox.
	 */
	static native void WordSetPCMonsNickName(int strbuf, int pcMonsIndex);

	/**
	 * 	Loads the name of a Pokémon type into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param type Internal ID of the Pokémon type.
	 */
	static native void WordSetPokeTypeName(int strbuf, PokeType type);

	/**
	 * 	Loads the name of a Pokémon nature into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param nature Internal ID of the nature to print.
	 */
	static native void WordSetSeikakuName(int strbuf, PokeNature nature);

	/**
	 * 	Loads the name of a Pokémon ability into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param tokuseiID Index of the ability.
	 */
	static native void WordSetTokuseiName(int strbuf, int tokuseiID);

	/**
	 * 	Loads the name of a Pokémon move into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param wazaID Index of the move.
	 */
	static native void WordSetWazaName(int strbuf, int wazaID);

	/**
	 * 	Loads the name of the move contained inside a specified TM item to a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param itemID Item index of the TM.
	 */
	static native void WordSetItemWazaName(int strbuf, int itemID);

	/**
	 * 	Loads the name of a Zone to a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param zoneID Index of the Zone.
	 */
	static native void WordSetPlaceName(int strbuf, int zoneID);

	#ifdef SANGO
	/**
	 * 	Loads the name of the currently visited Secret Base's owner into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 */
	static native void _WordSetCurrentSecretBaseOwnerName(int strbuf);

	/**
	 * 	Loads the name of a Secret Base Decoration into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param decorID Index of the decoration.
	 */
	static native void WordSetSecretBaseGoodsName(int strbuf, int decorID);

	static native void WordSetContestPortraitNickname(int strbuf, ContestPortraitRoom room, int portraitNo);

	static native void WordSetContestNewestNickname(int strbuf);

	/**
	 * 	Loads the name of a Contest Rank into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param cond Internal ID of the Contest Rank.
	 */
	static native void WordSetContestRank(int strbuf, ContestRank rank);

	static native void ContestWordSetAppeal(int strbuf);

	/**
	 * 	Loads the name of a Contest Condition into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param cond Internal ID of the Condition.
	 */
	static native void WordSetCondition(int strbuf, ContestCondition cond);

	static native void WordSetInterview(int strbuf);

	static native void WordSetTrendCategory(int strbuf);
	#endif

	#ifdef XY
	static native void WordSetFashionItem(int strbuf, int fashionID);

	static native void WordSetFashionTalk(int fashionSet);

	static native void WordSetFashionBuy();
	#endif

	/**
	 * 	Loads a friendly representation of the current weather configuration into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param weatherID ID of the weather configuration.
	 */
	static native void WordSetWeatherName(int strbuf, int weatherID);

	/**
	 * 	Loads the name of an O-Power into a strbuf.
	 * 	
	 * 	@param strbuf The strbuf to copy to.
	 * 	@param oPower ID of the O-Power.
	 */
	static native void WordSetAPowerName(int strbuf, int oPower);
}