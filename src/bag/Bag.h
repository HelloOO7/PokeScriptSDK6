package bag;

import bag.ItemPocket;

public class Bag {
	/**
	 * 	Checks how many of an item the player has in their bag.
	 * 	
	 * 	@param item ID of the item to check.
	 * 	@return Count of the item in the bag.
	 */
	static native int ItemGetNum(int item);

	/**
	 * 	Checks whether giving the player a certain amount of an item overflows the 1000 item limit.
	 * 	
	 * 	@param item ID of the item to check.
	 * 	@param amount Delta amount of items to evaluate.
	 * 	@return True if 'amount' items can be added losslessly.
	 */
	static native boolean ItemAddCheck(int item, int amount);

	/**
	 * 	Gives the player one or more of an item.
	 * 	
	 * 	@param item ID of the item.
	 * 	@param amount Number of items to add.
	 */
	static native void ItemAdd(int item, int amount);

	/**
	 * 	Removes items from the player's bag.
	 * 	
	 * 	@param item ID of the item to remove.
	 * 	@param amount Number of items to remove.
	 */
	static native void ItemSub(int item, int amount);

	/**
	 * 	Checks if an item ID is a Technical Machine item.
	 * 	
	 * 	@param item ID of the potential TM.
	 * 	@return True if the item is a TM.
	 */
	static native boolean ItemIsTM(int item) : ItemIsWazaMachine;

	/**
	 * 	Checks if an item ID is a Mega Stone item.
	 * 	
	 * 	@param item ID of the potential Mega Stone.
	 * 	@return True if the item is a Mega Stone.
	 */
	static native boolean ItemIsMegaStone(int item);

	/**
	 * 	Gets the berry ID of a berry item's item ID.
	 * 	
	 * 	@param item Item ID of the berry.
	 * 	@return ID of the berry, or 0xFFFF if the item is not a berry.
	 */
	static native int ItemGetBerryID(int item) : ItemGetNutsID;

	/**
	 * 	Gets the ItemPocket to which an Item belongs.
	 * 	
	 * 	@param item ID of the item.
	 */
	static native ItemPocket PocketGetID(int item);

	/**
	 * 	Gets the sum amount of items stored in a Bag Pocket.
	 * 	
	 * 	@param pocket The ItemPocket.
	 */
	static native int PocketGetTotalCount(ItemPocket pocket);
}