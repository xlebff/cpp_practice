#pragma once
#include <string>
#include "Object.h"

/**
* @class Item
* @brief Represents a collectible and usable item in the game
*
* Inherits from Object and adds inventory-specific functionality.
* Items can be picked up, carried in inventory, used, and combined.
*/
class Item : public Object {
public:
	/**
	* @brief Construct a new Item
	* @param name The name of the item
	* @param desc The description of the item
	* @param detachable Whether the item can be dropped from inventory
	*/
	Item(const std::string& name, 
		const std::string& desc = "",
		const bool detachable = true);

	/**
	* @brief Check if the item can be dropped from inventory
	* @return true if item can be dropped, false if it's permanently in inventory
	*
	* Some items may be non-detachable if they are essential for gameplay
	* or have special significance to the player character.
	*/
	bool isDetachable() const;

private:
	bool detachable;	///< Flag indicating if item can be dropped from inventory
};
