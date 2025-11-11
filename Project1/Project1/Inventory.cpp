#include <iostream>
#include <algorithm>
#include "Inventory.h"

using namespace std;

Inventory* Inventory::instance = nullptr;

Inventory::Inventory(const int capacity) :
	capacity(capacity) {
}

Inventory* Inventory::getInstance() {
	if (instance == nullptr) instance = new Inventory();
	else;

	return instance;
}

int Inventory::getCapacity() const { return capacity; }

vector<Item*> Inventory::getItems() const { return items; }

bool Inventory::addItem(Item* item) {
	if (items.size() == capacity) {
		cout << "The inventory is overflowing!" << endl;
		return false;
	}
	else {
		items.push_back(item);
		return true;
	}
}

bool Inventory::removeItem(Item* item) {
	auto it = remove(items.begin(), items.end(), item);
	if (it != items.end()) {
		items.erase(it, items.end());
		return true;
	}
	return false;
}

bool Inventory::clearItems() {
	items.clear();
	return true;
}

Item* Inventory::getItem(const std::string& name) const {
	for (Item* item : items) {
		if (item->getName() == name) return item;
		else continue;
	}
	return nullptr;
}

void Inventory::display() {
	cout << "=== Your Inventory ===" << endl
		<< "Capacity: " << items.size() << "/" << capacity << endl
		<< "Items:" << endl;

	for (size_t i = 0; i < items.size(); ++i) {
		cout << "  " << (i + 1) << ". " << items[i]->getName()
			<< " - " << items[i]->getDesc() << endl;
	}
}
