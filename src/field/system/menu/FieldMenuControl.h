package field.system.menu;

import field.system.menu.FieldMenu;
import field.system.menu.FieldMenuPage;
import field.system.menu.FieldMenuAddablePage;

public class FieldMenuControl {
	/**
	 * 	Checks if a field menu button is enabled.
	 * 	
	 * 	@param menu The field menu to check.
	 * 	@return True if the is enabled.
	 */
	static native boolean IsFieldMenuEnabled(FieldMenu menu) : PlayerGetFieldMenu;

	/**
	 * 	Enables a field menu button.
	 * 	
	 * 	@param menu The field menu to enable.
	 * 	@param refresh True if the field menu UI should be updated.
	 */
	static native void EnableFieldMenu(FieldMenu menu, boolean refresh) : PlayerSetFieldMenu;

	/**
	 * 	Changes the field menu mode.
	 * 	The effect of this function is temporary, either until FieldMenuPopPage is called, or the script ends.
	 * 	Despite the naming scheme, only one page can be pushed at a time.
	 * 	
	 * 	@param page The field menu mode.
	 */
	static native void FieldMenuPushPage(FieldMenuPage page);

	/**
	 * 	Resets the field menu mode.
	 */
	static native void FieldMenuPopPage();

	/**
	 * 	Enables the specified PSS/PlayNav field menu pages.
	 * 	
	 * 	@param pages Combinable bitflags of the pages to enable. 
	 */
	static native void FieldMenuAddPage(FieldMenuAddablePage pages);

	#ifdef SANGO
	/**
	 * 	Sets the field menu mode to the PlayNav.
	 */
	static native void FieldMenuChangePagePlayNavi();
	#endif
}