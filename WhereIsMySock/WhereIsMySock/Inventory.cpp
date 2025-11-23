#include "Inventory.h"

using namespace std;
using namespace SerialPrint;

Inventory* Inventory::instance = nullptr;

Inventory::Inventory(const int capacity) :
	capacity(capacity) {
}

Inventory::~Inventory() {
	for (Item* item : items)
		delete item;

	items.clear();
}

void Inventory::cleanup() {
	delete instance;
	instance = nullptr;
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
		serialPrintln("The inventory is overflowing!");
		return false;
	}
	else {
		items.push_back(item);
		return true;
	}
}

bool Inventory::removeItem(const Item* item) {
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

Item* Inventory::getItem(const string& itemName) const {
	for (Item *item : items) {
		if (*item == itemName) return item;
		else continue;
	}
	return nullptr;
}

void Inventory::display() {
	serialPrintln("Capacity: " + to_string(items.size()) + 
		"/" + to_string(capacity));

	if (!items.empty()) {
		for (size_t i = 0; i < items.size(); ++i) {
			serialPrintln("  " + to_string(i + 1) + 
				". " + items[i]->getName() + " - " + items[i]->getDesc());
		}
	}
	else {
		// continue execution
	}
}
