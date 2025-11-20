#include "UsageManager.h"

using namespace std;

static void glassOfWater(const Item* item) {
}

static void waterToCat(const Item* item) {
	cout << "You poured the water out of the glass on the cat... Why did you do that? "
		<< "The cat is very unhappy! He grabbed your leg, scratched it, and ran away.\n"
		<< "Yeah, it's better not to touch him now... "
		<< "and it is better to treat the wound, otherwise a scar will remain." << endl;

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	inventory->addItem(new Item("Glass",
		"An empty glass tumbler."));
}

static void coinToCat() {

}

static void phoneFlashlight() {

}

static void phoneToCat() {

}

bool UsageManager::processUsage(Item* item, Object* target) {
	if (*item == items.at(GLASS_OF_WATER)) {
		if (*target == "Cat") waterToCat(item);
		else if (*target == items.at(COIN)) coinToCat();
		else if (!target) glassOfWater(item);
		else return false;
	}
	else if (*item == items.at(PHONE)) {
		if (!target) phoneFlashlight();
		else if (*target == items.at(COIN)) phoneToCat();
		else return false;
	}
	else;

	return true;
}
