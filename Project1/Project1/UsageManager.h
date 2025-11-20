#pragma once

#include <string>
#include <iostream>

#include "Player.h"
#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "Object.h"
#include "Items.h"

namespace UsageManager {
	bool processUsage(Item* item, Object* target = nullptr);
};
