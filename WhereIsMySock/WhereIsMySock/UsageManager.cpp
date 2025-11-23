#include "UsageManager.h"

using namespace std;
using namespace Flags;
using namespace SerialPrint;

static void waterToCat(const Item* item, Object* target) {
	serialPrintln("You poured the water out of the glass on the cat... "
		"Why did you do that?\n"
		"The cat is very unhappy! He grabbed your leg, "
		"scratched it, and ran away.\n"
		"Yeah, it's better not to touch him now...\n"
		"and it is better to treat the wound, otherwise a scar will remain.\n"
		"There is a small red ball under it.");

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
	inventory->addItem(new Item("Glass", "An empty glass tumbler."));

	Room* bathroom = Room::getRoom("Bathroom");
	Room* room = Room::getCurrentRoom();

	room->removeObject(target);
	bathroom->addObject(target);
	target->setDesc("It's better to leave him alone!");

	room->addObject(new Item("Yarn", 
		"A soft ball of red yarn, slightly unraveled."));

	isHurts = true;
}

static void coinToCat(Item* item, Object* target) {
	serialPrintln("You dropped a coin next to the cat.\n"
		"Vasya woke up from the sound and left in displeasure!\n"
		"There is a small red ball under it.");

	Room* kitchen = Room::getRoom("Kitchen");
	Room* room = Room::getCurrentRoom();

	room->addObject(new Item("Yarn", 
		"A soft ball of red yarn, slightly unraveled."));
	room->addObject(item);

	room->removeObject(target);
	kitchen->addObject(target);
	target->setDesc("The cat looks at you with obvious displeasure...");

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
}

static void phoneToCat(const Item* item, Object* target) {
	serialPrintln("You take a photo of the cat with your phone.\n"
		"The flash startled Vasya! He jumped up and ran away to the kitchen."
		"\nA cute photo of a sleeping cat is now in your gallery.\n"
		"There is a small red ball under it.");

	Room* kitchen = Room::getRoom("Kitchen");
	Room* room = Room::getCurrentRoom();

	Object* cat = room->findObject("Cat");
	room->removeObject(cat);
	kitchen->addObject(cat);
	cat->setDesc("The cat is hiding under the table after the flash.");

	room->addObject(new Item("Yarn", 
		"A soft ball of red yarn, slightly unraveled."));
}

static void phoneFlashlight() {
	isFlashlightOn = !isFlashlightOn;

	serialPrintln(isFlashlightOn ?
		"You turn on the phone's flashlight." :
		"You turn off the phone's flashlight.");
}

static void phoneToSofa(Object* target) {
	if (!isFlashlightOn) {
		serialPrintln("It's too dark under the sofa to see anything.\n"
			"Maybe you need some light?");
		return;
	}

	serialPrintln("You shine the flashlight under the sofa and find a coin!");

	Room* room = Room::getCurrentRoom();
	room->addObject(new Item("Coin", 
		"A shiny coin. Maybe it will come in handy."));
}

static void glassOfWater(const Item* item) {
	serialPrintln("You drink the water from the glass. Refreshing!");

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
	inventory->addItem(new Item("Glass", "An empty glass tumbler."));
}

static void glassToSink(const Item* item) {
	serialPrintln("You fill the glass with water from the sink.");

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
	inventory->addItem(new Item("Glass of water", 
		"A full glass of clear, fresh water."));
}

static void waterToFlower(const Item* item, Object* target) {
	serialPrintln("You water the flowers with water from the glass. "
		"The flowers look happier!");

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
	inventory->addItem(new Item("Glass", "An empty glass tumbler."));
	target->setDesc("A little contented flower.");

	isFlowerAlive = true;
}

static void noteToBin(const Item* item) {
	serialPrintln("You throw the note in the trash. "
		"One less thing to worry about.");

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
}

static void phoneToBathroom(Item* item) {
	serialPrintln("You place the phone on the bathroom shelf, "
		"pointing the flashlight at the ceiling.\n"
		"The bathroom is now well lit. "
		"You can see the empty lamp socket clearly.");

	Room* room = Room::getCurrentRoom();
	room->addObject(new Item("Lamp socket", 
		"An empty light bulb holder, waiting for a light bulb."));
	room->setDesc("There's a little light in the bathroom now. "
		"\nYou need to turn on the light bulb to learn more...");
	isFlashlightOn = true;

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;
}

static void hydrogenPeroxide() {
	if (isHurts) {
		serialPrintln("You use hydrogen peroxide on the scratch... "
			"\nBubbles rise, droplets roll down the leg and "
			"fall to the floor. Soon the unpleasant sensations subside. "
			"\nThe wound has been successfully treated.");

		isHurts = false;
	}
	else {
		serialPrintln("You don't need it.");
	}
}

static void lampToSocket(const Item* item, Object* target) {
	Room* room = Room::getCurrentRoom();

	if (!isFlashlightOn) {
		serialPrintln("It's too dark in the bathroom to see "
			"the lamp socket properly.");
		return;
	}
	else {
		// continue execution
	}

	serialPrintln("You screw the light bulb into the socket. "
		"The bathroom is now properly lit!\n"
		"You can now take your phone back.");

	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;

	room->addObject(new Item("Phone", 
		"Your smartphone. The battery is at 5%."));
	room->addObject(new Object("Bathtub",
		"A clean white bathtub with silver faucets. The drain looks clear."));
	room->addObject(new Object("Laundry basket",
		"A tall wicker laundry basket filled with clean, folded clothes. "
		"And inside... A sock! But not that one."));
	room->addObject(new Object("Sink",
		"A stainless steel sink. It's clean and dry, "
		"with a faucet that looks relatively new."));
	room->addObject(new Item("Screwdriver base", 
		"A screwdriver without a tip."));
	room->addObject(new Item("Towel",
		"A soft, fluffy bath towel hanging on a hook. It smells clean."));
	room->addObject(new Object("Scale",
		"A digital bathroom scale tucked away in the corner. "
		"The display is dark."));
	room->addObject(new Item("Hair clip",
		"A simple black hair clip left on the edge of the sink."));
	room->addObject(new Object("Shower curtain",
		"A blue plastic shower curtain with a pattern of little fish. "
		"It's pulled to one side."));
	room->addObject(new Item("Toothbrush",
		"Your electric toothbrush, still charging on the counter."));
	room->addObject(new Item("Hydrogen peroxide",
		"A small brown bottle of hydrogen peroxide. The liquid inside "
		"is clear and bubbles gently when shaken."));
	room->addObject(new Object("Washing machine",
		"A compact washing machine tucked neatly in the corner. "
		"Its digital display is dark and the door is securely closed."));

	room->setDesc("A small but tidy bathroom with white tiles "
		"and good lighting."
		"\nThe air smells faintly of lemon cleaning products.\nEverything is "
		"neatly arranged except for a few minor signs of daily use.");

	room->removeObject(target);
	delete target;
}

static void coinToWardrobe() {
	Room* room = Room::getCurrentRoom();
	Inventory* inventory = Inventory::getInstance();

	if (inventory->addItem(new Item("Screwdriver tip",
		"The tip of the screwdriver. "
		"It can be combined with a screwdriver!"))) {
		serialPrintln("You have picked up the tip of the screwdriver.");
	}
	else {
		serialPrintln("You have found the tip of the screwdriver, "
			"but there is not enough space in the inventory...");
		room->addObject(new Item("Screwdriver tip",
			"The tip of the screwdriver. "
			"It can be combined with a screwdriver!"));
	}
}

static void screwdriverToDoor(Object* target) {
	Room* room = Room::getCurrentRoom();
	Room* balcony = Room::getRoom("Balcony");

	Room::setAvailability(room->getIndex(), balcony->getIndex(), true);

	serialPrintln("The balcony is now available!");

	room->removeObject(target);
	delete target;

	Room::setCurrentRoom(room);
}

static void apple(Item* item) {
	Inventory* inventory = Inventory::getInstance();
	inventory->removeItem(item);
	delete item;

	serialPrintln("You ate an apple. Now you're not hungry!\n"
		"But the apple peel got stuck between the teeth, "
		"creating an unpleasant sensation...");

	areYouHungry = false;
	areTeethDirty = true;
}

static void toothbrush() {
	serialPrintln("You're brushing your teeth.....");

	if (areTeethDirty) {
		serialPrintln("The apple peel is defeated! Nothing else gets in the way.");
		areTeethDirty = false;
	}
	else {
		// continue execution
	}
}

bool UsageManager::processUsage(Item* item, Object* target) {
	if (*item == "Glass of water") {
		if (!target) glassOfWater(item);
		else if (*target == "Cat") waterToCat(item, target);
		else if (*target == "Flower") waterToFlower(item, target);
		else return false;
	}
	else if (*item == "Phone") {
		if (*(Room::getCurrentRoom()) == "Bathroom") {
			if (!isFlashlightOn) phoneFlashlight();
			phoneToBathroom(item);
		}
		else if (!target) phoneFlashlight();
		else if (*target == "Cat") phoneToCat(item, target);
		else if (*target == "Sofa") phoneToSofa(item);
		else return false;
	}
	else if (*item == "Coin") {
		if (!target) return false;
		else if (*target == "Cat") coinToCat(item, target);
		else return false;
	}
	else if (*item == "Glass") {
		if (!target) serialPrintln(item->getDesc());
		else if (*target == "Sink") glassToSink(item);
		else return false;
	}
	else if (*item == "Note") {
		if (!target) serialPrintln(item->getDesc());
		else if (*target == "Trash bin") noteToBin(item);
		else return false;
	}
	else if (*item == "Lamp") {
		if (!target) return false;
		else if (*target == "Lamp socket") lampToSocket(item, target);
		else return false;
	}
	else if (*item == "Coin on a string") {
		if (!target) return false;
		else if (*target == "Wardrobe") coinToWardrobe();
		else return false;
	}
	else if (*item == "Screwdriver") {
		if (!target) return false;
		else if (*target == "Door") screwdriverToDoor(target);
		else return false;
	}
	else if (*item == "Apple") {
		if (!target) apple(item);
		else return false;
	}
	else if (*item == "Toothbrush") {
		if (!target) toothbrush();
		else return false;
	}
	else if (*item == "Hydrogen peroxide") {
		if (!target) hydrogenPeroxide();
		else return false;
	}
	else return false;

	return true;
}