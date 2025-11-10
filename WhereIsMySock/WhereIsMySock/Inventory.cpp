#include <iostream>
#include <vector>
#include "Inventory.h"
#include "Room.h"

using namespace std;

Inventory::Inventory(int capacity) :
	capacity(capacity) {}

const int Inventory::getCapacity() {
	return this->capacity;
}

const vector<Item*> Inventory::getItems() {
	return this->items;
}

bool Inventory::takeItem(Item* item) {
	if (items.size() == capacity) return 0;
	else {
		items.push_back(item);
		return 1;
	}
}

bool Inventory::dropItem(Item* item, Room* room) {
	items.erase(remove(items.begin(), items.end(), item));

	return 0;
}

bool Inventory::dropAllItems() {
	items.clear();
}
