#pragma once

#include <string>
#include <iostream>

#include "Room.h"
#include "Inventory.h"
#include "Item.h"
#include "Object.h"
#include "AllObjs.h"

namespace UsageManager {
	bool processUsage(Item* item, Object* target = nullptr);
	extern bool isFlashlightOn;
};
