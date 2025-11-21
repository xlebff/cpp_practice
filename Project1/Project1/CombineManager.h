#pragma once

#include <string>
#include <iostream>

#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "Object.h"
#include "AllObjs.h"

namespace CombineManager {
	bool processCombine(Item* item0, Item* item1);
}
