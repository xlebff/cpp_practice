#include "CombineManager.h"

using namespace std;
using namespace SerialPrint;

namespace {
	void yarnWithCat(Item* item0, Item* item1) {
		Inventory* inventory = Inventory::getInstance();

		inventory->removeItem(item0);
		delete item0;
		inventory->removeItem(item1);
		delete item1;

		inventory->addItem(new Item("Coin on a string",
			"A coin tied on a woolen thread. But why..?"));

		serialPrintln("You tied a coin to a string... Why did you do that?");
	}

	void screwdriver(Item* item0, Item* item1) {
		Inventory* inventory = Inventory::getInstance();

		inventory->removeItem(item0);
		inventory->removeItem(item1);
		inventory->addItem(new Item("Screwdriver", "A regular screwdriver with a blue stripe."));
		delete item0;
		delete item1;

		serialPrintln("You've assembled a screwdriver!");
	}
}

bool CombineManager::processCombine(Item* item0, Item* item1) {
	if ((*item0 == "Yarn" && *item1 == "Coin")
		|| (*item0 == "Coin" && *item1 == "Yarn")) {
		yarnWithCat(item0, item1);
	}
	else if ((*item0 == "Screwdriver base" && *item1 == "Screwdriver tip")
		|| (*item1 == "Screwdriver base" && *item0 == "Screwdriver tip")) {
		screwdriver(item0, item1);
	}
	else return false;

	return true;
}