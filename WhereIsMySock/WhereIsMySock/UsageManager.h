#pragma once

#include <string>
#include <iostream>

#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "Object.h"
#include "SerialPrint.h"
#include "Flags.h"

/**
* @namespace UsageManager
* @brief Manages item usage logic in the game
*
* Handles all interactions between items and objects in the game world.
* Processes usage of items on targets and manages special usage states.
*/
namespace UsageManager {
    /**
    * @brief Process the usage of an item on a target object
    * @param item Item to be used
    * @param target Target object to use the item on (optional)
    * @return true if usage was successful, false if usage is not possible
    *
    * Handles various item usage scenarios:
    * - Using items on specific objects in the environment
    * - Using items without targets (self-use)
    * - Triggering game events through item usage
    * - Updating game state based on usage results
    */
	bool processUsage(Item* item, Object* target = nullptr);
};
