#include "UsageManager.h"

using namespace std;

bool UsageManager::isFlashlightOn = false;

static void waterToCat(const Item* item, Object* target) {
	cout << "You poured the water out of the glass on the cat... Why did you do that?\n"
		<< "The cat is very unhappy! He grabbed your leg, scratched it, and ran away.\n"
		<< "Yeah, it's better not to touch him now...\n"
		<< "and it is better to treat the wound, otherwise a scar will remain.\n"
		<< "There is a small red ball under it." << endl;

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
	inventory->addItem(new Item("Glass",
		"An empty glass tumbler."));

	Room* bathroom = Room::getRoom("Bathroom");
	Room* room = Room::getCurrentRoom();

	room->removeObj(target);
	bathroom->addObj(target);
	target->setDesc("It's better to leave him alone!");

	room->addObj(new Item("Yarn",
		"A soft ball of red yarn, slightly unraveled."));
}

static void coinToCat(Item* item, Object* target) {
	cout << "You dropped a coin next to the cat.\n"
		<< "Vasya woke up from the sound and left in displeasure!\n"
		<< "There is a small red ball under it." << endl;

	Room* kitchen = Room::getRoom("Kitchen");
	Room* room = Room::getCurrentRoom();

	room->addObj(new Item("Yarn",
		"A soft ball of red yarn, slightly unraveled."));
	room->addObj(item);

	room->removeObj(target);
	kitchen->addObj(target);
	target->setDesc("The cat looks at you with obvious displeasure...");

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
}

static void phoneToCat(const Item* item, Object* target) {
	cout << "You take a photo of the cat with your phone.\n"
		<< "The flash startled Vasya! He jumped up and ran away to the kitchen.\n"
		<< "A cute photo of a sleeping cat is now in your gallery.\n"
		<< "There is a small red ball under it." << endl;

	Room* kitchen = Room::getRoom("Kitchen");
	Room* room = Room::getCurrentRoom();

	Object* cat = room->findObject(items.at(CAT));
	room->removeObj(cat);
	kitchen->addObj(cat);
	cat->setDesc("The cat is hiding under the table after the flash.");

	room->addObj(new Item("Yarn",
		"A soft ball of red yarn, slightly unraveled."));
}

static void phoneFlashlight() {
	UsageManager::isFlashlightOn = !UsageManager::isFlashlightOn;

	cout << (UsageManager::isFlashlightOn ?
		"You turn on the phone's flashlight."
		: "You turn off the phone's flashlight.") << endl;
}

static void phoneToSofa(Object* target) {
	if (!UsageManager::isFlashlightOn) {
		cout << "It's too dark under the sofa to see anything.\n"
			<< "Maybe you need some light?" << endl;
		return;
	}
	else;

	cout << "You shine the flashlight under the sofa and find a coin!" << endl;

	Room* room = Room::getCurrentRoom();
	room->addObj(new Item("Coin", "A shiny coin. Maybe it will come in handy."));
}

static void glassOfWater(const Item* item) {
	cout << "You drink the water from the glass. Refreshing!" << endl;

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
	inventory->addItem(new Item("Glass", "An empty glass tumbler."));
}

static void glassToSink(const Item* item) {
	cout << "You fill the glass with water from the sink." << endl;

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
	inventory->addItem(new Item("Glass of water", "A full glass of clear, fresh water."));
}

static void waterToFlower(const Item* item, Object* target) {
	cout << "You water the flowers with water from the glass. The flowers look happier!" << endl;

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
	inventory->addItem(new Item("Glass", "An empty glass tumbler."));
	target->setDesc("A little contented flower.");
}

static void noteToBin(const Item* item) {
	cout << "You throw the note in the trash. One less thing to worry about." << endl;

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
}

static void phoneToBathroom(Item* item) {
	cout << "You place the phone on the bathroom shelf, pointing the flashlight at the ceiling.\n"
		<< "The bathroom is now well lit. You can see the empty lamp socket clearly." << endl;

	Room* room = Room::getCurrentRoom();
	room->addObj(new Item("Lamp socket", 
		"An empty light bulb holder, waiting for a light bulb."));
	room->setDesc("There's a little light in the bathroom now. "
		"You need to turn on the light bulb to learn more...");
	UsageManager::isFlashlightOn = true;

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
}

static void lampToSocket(const Item* item, Object* target) {
	Room* room = Room::getCurrentRoom();

	if (!UsageManager::isFlashlightOn) {
		cout << "It's too dark in the bathroom to see the lamp socket properly." << endl;
		return;
	}
	else {
		cout << "You screw the light bulb into the socket. The bathroom is now properly lit!\n"
			<< "You can now take your phone back." << endl;

		Inventory* inventory = Inventory::getInstance();
		inventory->removeItem(item);
		delete item;

		room->addObj(new Item("Phone", "Your smartphone. The battery is at 5%."));
		room->addObj(new Object("Bathtub",
			"A clean white bathtub with silver faucets. The drain looks clear."));
		room->addObj(new Object("Laundry basket",
			"A tall wicker laundry basket filled with clean, folded clothes. And inside... A sock! But not that one."));
		room->addObj(new Object("Sink",
			"A stainless steel sink. It's clean and dry, with a faucet that looks relatively new."));
		room->addObj(new Item("Screwdriver base", "A screwdriver without a tip."));
		room->removeObj(target);
		delete target;
	}
}

static void coinToWardrobe() {
	Room* room = Room::getCurrentRoom();
	Inventory* inventory = Inventory::getInstance();

	if (inventory->addItem(new Item("Screwdriver tip",
		"The tip of the screwdriver. It can be combined with a screwdriver!"))) {
		cout << "You have picked up the tip of the screwdriver." << endl;
	}
	else {
		cout << "You have found the tip of the screwdriver, but there is not enough space in the inventory..." << endl;
		room->addObj(new Item("Screwdriver tip",
			"The tip of the screwdriver. It can be combined with a screwdriver!"));
	}
}

static void screwdriverToDoor(Object* target) {
	Room* room = Room::getCurrentRoom();
	Room* balcony = Room::getRoom("Balcony");
	
	Room::setAvailability(room->getIndex(), balcony->getIndex(), true);

	cout << "The balcony is now available!" << endl;

	room->removeObj(target);
	delete target;

	Room::setCurrentRoom(room);
}

bool UsageManager::processUsage(Item* item, Object* target) {
	if (*item == items.at(GLASS_OF_WATER)) {
		if (!target) glassOfWater(item);
		else if (*target == items.at(CAT)) waterToCat(item, target);
		else if (*target == items.at(FLOWER)) waterToFlower(item, target);
		else return false;
	}
	else if (*item == items.at(PHONE)) {
		if (Room::getCurrentRoom()->getName() == "Bathroom") {
			if (!UsageManager::isFlashlightOn) phoneFlashlight();
			else;
			phoneToBathroom(item);
		}
		else if (!target) phoneFlashlight();
		else if (*target == items.at(CAT)) phoneToCat(item, target);
		else if (*target == items.at(SOFA)) phoneToSofa(item);
		else return false;
	}
	else if (*item == items.at(COIN)) {
		if (!target) return false;
		else if (*target == items.at(CAT)) coinToCat(item, target);
		else return false;
	}
	else if (*item == items.at(GLASS)) {
		if (!target) return false;
		else if (*target == items.at(SINK)) glassToSink(item);
		else return false;
	}
	else if (*item == items.at(NOTE)) {
		if (!target) cout << item->getDesc() << endl;
		else if (*target == items.at(BIN)) noteToBin(item);
		else return false;
	}
	else if (*item == items.at(LAMP)) {
		if (!target) return false;
		else if (*target == items.at(LAMP_SOCKET)) lampToSocket(item, target);
		else return false;
	}
	else if (*item == items.at(COIN_ON_A_STRING)) {
		if (!target) return false;
		else if (*target == items.at(WARDROBE)) coinToWardrobe();
		else return false;
	}
	else if (*item == items.at(SCREWDRIVER)) {
		if (!target) return false;
		else if (*target == items.at(DOOR)) screwdriverToDoor(target);
	}
	else return false;

	return true;
}
