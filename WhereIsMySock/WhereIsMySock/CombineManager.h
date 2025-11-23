#pragma once

#include <string>
#include <iostream>

#include "Room.h"
#include "Inventory.h"
#include "Object.h"
#include "Item.h"
#include "SerialPrint.h"

/**
* @namespace CombineManager
* @brief Manages item combination logic in the game
*
* Provides functionality for combining two items to create new items
* or trigger special game events. Handles all combination recipes
* and their outcomes.
*/
namespace CombineManager {
    /**
    * @brief Process the combination of two items
    * @param item0 First item to combine
    * @param item1 Second item to combine
    * @return true if combination was successful, false if items cannot be combined
    *
    * Checks if the two items can be combined according to game recipes.
    * If combination is possible, performs the combination action which may:
    * - Create new items
    * - Remove original items
    * - Trigger special events
    * - Update game state
    */
    bool processCombine(Item* item0, Item* item1);
}
