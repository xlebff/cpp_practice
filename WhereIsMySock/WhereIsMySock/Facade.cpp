#include "Facade.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define CYAN "\033[36m"

using namespace std;
using namespace Flags;
using namespace SerialPrint;

/* The names of the text commands and their corresponding numbers */
const string commands[] = {
    "help",
    "go to",
    "look around",
    "look at",
    "show inventory",
    "take",
    "drop",
    "use",
    "combine",
    "decombine",
    "quit"
};

const enum commandsNum {
    HELP,
    GO_TO,
    LOOK_AROUND,
    LOOK_AT,
    SHOW_INVENTORY,
    TAKE,
    DROP,
    USE,
    COMBINE,
    DECOMBINE,
    QUIT
};

/* Facade initialization */
Facade* Facade::instance = nullptr;

// ==================== Singleton Pattern ====================

Facade* Facade::getInstance() {
    if (!instance) {
        instance = new Facade();
        instance->showWelcome();
    }
    return instance;
}

Facade::Facade(const int maxTurns, const int maxLightTurns)
    : maxTurns(maxTurns), maxLightTurns(maxLightTurns)
{
    turns = 0;
    lightTurns = 0;
    Room::initializeRooms();
}

// ==================== Game Flow Methods ====================

bool Facade::processInput(string& input) {
    string action;
    vector<string> args;

    if (parseInput(input, action, args)) {
        if (action == commands[QUIT])
            return false;
        else if (action == commands[HELP])
            showHelp();
        else if (action == commands[GO_TO] && !args.empty())
            moveTo(args[0]);
        else if (action == commands[TAKE] && !args.empty())
            takeItem(combineArgs(args));
        else if (action == commands[DROP] && !args.empty())
            dropItem(combineArgs(args));
        else if (action == commands[LOOK_AT] && !args.empty())
            lookAt(combineArgs(args));
        else if (action == commands[SHOW_INVENTORY])
            showInventory();
        else if (action == commands[LOOK_AROUND])
            lookAround();
        else if (action == commands[USE])
            useItem(args);
        else if (action == commands[COMBINE])
            combineItems(args);
        else {
            serialPrintln("Wrong or missing arguments for \""
                + action + "\"");
            serialPrintln("Type 'help' to see available actions.");
            return true;
        }

        updateTurns();
    }
    else {
        serialPrintln("Unknown command: \"" + input + "\"");
        serialPrintln("Type 'help' to see available actions.");
        return true;
    }

    return true;
}

void Facade::showWelcome() {
    serialPrintln("=== The Lost Sock Adventure ===\n"
        "You wake up and realize one of your favorite socks is missing!\n"
        "You can't leave the house with just one sock. "
        "Find the missing pair!\n\n"
        "Type \"help\" to see available actions.\n"
        "Type \"quit\" to exit the game.\n\n"
        "You are in your bedroom. What do you do?");

    cout << endl << ">  ";
}

void Facade::showHelp() {
    serialPrintln("Available actions:");
    serialPrintln("look around            - Look around the room");
    serialPrintln("look at [object]       - Examine an object closely");
    serialPrintln("use [item] to [target] - Use an item on an object");
    serialPrintln("take [item]            - Take an item");
    serialPrintln("drop [item]            - Drop an item");
    serialPrintln("go to [location]       - Move to another room");
    serialPrintln("show inventory         - Show your inventory");
    serialPrintln("help                   - Show this help message");
    serialPrintln("quit                   - Exit the game");
}

void Facade::quitGame() {
    serialPrintln("Thanks for playing!");

    Room::cleanup();
    Inventory::cleanup();

    delete instance;
    instance = nullptr;

    exit(0);
}

// ==================== Game State Methods ====================

int Facade::getTurns() { return turns; }

int Facade::getMaxTurns() { return maxTurns; }

bool Facade::flagsCheck() {
    bool res = true;

    if (!isFlowerAlive) {
        serialPrintln("As you leave for work, you suddenly remember "
            "the wilted flower and feel a pang of guilt. "
            "The thought haunts you all day long.");
        res = false;
    }
    else {
        // continue execution
    }

    if (!areKeysFound) {
        serialPrintln("In a frantic morning panic, you tear through "
            "the apartment searching for your keys. Your heart "
            "races as you check every surface.");
        res = false;
    }
    else {
        serialPrintln("With keys neatly in your pocket, you feel "
            "a satisfying sense of organization. "
            "Today is off to a proper start!");
    }

    if (areYouHungry) {
        serialPrintln("Your empty stomach growls relentlessly, "
            "making it impossible to focus on anything except "
            "food until lunchtime.");
        res = false;
    }
    else {
        // continue execution
    }

    if (areTeethDirty) {
        serialPrintln("All day you worry that people can tell you rushed "
            "through brushing your teeth. You keep nervously smiling "
            "at coworkers to check.");
        res = false;
    }
    else {
        // continue execution
    }

    if (isHurts) {
        serialPrintln("The untreated cut on your leg throbs with "
            "pain all day, making every step a reminder of your "
            "rushed morning.");
        res = false;
    }
    else {
        // continue execution
    }

    return res;
}

void Facade::endGame() {
    Inventory* inventory = Inventory::getInstance();
    bool isTrue = flagsCheck();

    if (inventory->getItem("Sock")) {
        serialPrintln("You did it! The couple was reunited.");

        if (isTrue) {
            setColor(CYAN);
            serialPrintln("True ending: Great day.");
            resetColor();
        }
        else {
            setColor(GREEN);
            serialPrintln("Good ending: Reunited couple.");
            resetColor();
        }

        quitGame();
    }
    else if (inventory->getItem("Sports sock") && inventory->getItem("Other sports sock")) {
        serialPrintln("You're late! In a hurry, you decide to go "
            "in a pair of sports socks. The boss will be unhappy!");

        setColor(GREEN);
        serialPrintln("Good ending: The other pair.");
        resetColor();
    }
    else if (inventory->getItem("Sports sock") || inventory->getItem("Other sports sock")){
        serialPrintln("You're late! In your haste, you decide "
            "to wear different socks."
            " How awful! It's completely unacceptable, "
            "but there's nothing you can do about it...");

        setColor(RED);
        serialPrintln("Bad ending: Tasteless "
            "and terribly disorganized.");
        resetColor();
    }
    else {
        serialPrintln("Horrible! You don't even have a sock! "
            "You'll have to run to the store, but that "
            "will take a long time.");
        setColor(YELLOW);
        serialPrintln("Bad ending: Seriously late.");
        resetColor();
    }

    quitGame();
}

// ==================== Player Actions ====================

bool Facade::moveTo(const string& roomName) {
    Room* room = Room::getRoom(roomName);
    if (!room) {
        serialPrintln("There is no such room.");
        return false;
    }
    else {
        // continue execution
    }

    if (Room::isAvailable(room->getName())) {
        serialPrintln("You`re going to the " + room->getName() + ".");
        serialPrintln(room->getDesc());
        Room::setCurrentRoom(room);
        return true;
    }
    else {
        serialPrintln("You cannot enter this room from here.");
        return false;
    }
}

bool Facade::takeItem(const string& itemName) {
    Room* room = Room::getCurrentRoom();
    Inventory* inventory = Inventory::getInstance();

    Object* target = room->findObject(itemName);
    if (!target) {
        serialPrintln("There is no \"" + itemName + "\" here.");
        return false;
    }
    else {
        // continue execution
    }

    /* Is an object a thing that can be taken? */
    Item* itemTarget = dynamic_cast<Item*>(target);
    if (!itemTarget) {
        serialPrintln("You can't take the " + target->getName() +
            ". It's not an item.");
        return false;
    }
    else {
        // continue execution
    }

    if (inventory->addItem(itemTarget)) {
        room->removeObject(target);
        serialPrintln("You're taking the " + target->getName() + ".");

        return true;
    }
    else {
        serialPrintln("The item remained in its place.");
        return false;
    }
}

bool Facade::dropItem(const string& itemName) {
    Inventory* inventory = Inventory::getInstance();
    Item* item = inventory->getItem(itemName);

    if (!item) {
        serialPrintln("You don`t have the \"" + itemName + "\".");
        return false;
    }
    else if (!(item->isDetachable())) {
        serialPrintln("You can't throw the " + itemName + " away.");
        return false;
    }
    else {
        // continue execution
    }

    Room* room = Room::getCurrentRoom();
    inventory->removeItem(item);
    serialPrintln("Now you don`t have the " + item->getName() + ".");
    room->addObject(item);

    return true;
}

bool Facade::useItem(const vector<string> args) {
    // Special cases
    if (args[0] == "Stool" && args.size() == 1) {
        Room* room = Room::getCurrentRoom();

        if (!room->findObject("Sock"))
            room->addObject(new Item("Sock", "Your other sock!"));

        serialPrintln("Now you can take a sock!");

        return true;
    }
    else if (args[0] == "Entrance" && args[1] == "Door") {
        endGame();
    }
    else {
        // continue execution
    }

    Item* item = nullptr;
    Object* target = nullptr;

    int index = 0;
    item = parseItem(args, &index);

    if (!item) {
        serialPrintln("You don`t have that item.");
        return false;
    }

    if (index < args.size() && args[index] == "To") {
        ++index;

        if (index < args.size()) {
            Room* room = Room::getCurrentRoom();
            string objectName;

            while (index < args.size()) {
                if (objectName.empty())
                    objectName = args[index];
                else {
                    string word = args[index];
                    word[0] = tolower(word[0]);
                    word = " " + word;
                    objectName += word;
                }

                target = room->findObject(objectName);
                if (target) break;
                else {
                    // continue execution
                }

                ++index;
            }
        }
    }
    else {
        // continue execution
    }

    if (!UsageManager::processUsage(item, target)) {
        serialPrintln("You can`t use your item this way.");
        return false;
    }
    else return true;
}

bool Facade::combineItems(const vector<string> args) {
    Item* item0 = nullptr;
    Item* item1 = nullptr;

    string itemName = args[0];
    int index = 0;

    item0 = parseItem(args, &index);

    if (!item0) {
        serialPrintln("You don`t have the \"" + itemName + "\".");
        return false;
    }
    else {
        // continue execution
    }

    if (index < args.size() && args[index] == "With") {
        ++index;
        item1 = parseItem(args, &index);

        if (!item1) {
            serialPrintln("Specify an item you want to combine " + itemName
                + " with.");
            return false;
        }
        else {
            // continue execution
        }
    }
    else {
        serialPrintln("Wrong syntaxis!");
        return false;
    }

    if (!CombineManager::processCombine(item0, item1)) {
        serialPrintln("You can`t combine " + item0->getName()
            + " with " + item1->getName() + ".");
        return false;
    }
    else return true;
}

bool Facade::lookAt(const string& objectName) {
    Room* room = Room::getCurrentRoom();
    Object* target = room->findObject(objectName);

    if (!target) {
        serialPrintln("There is no \"" + objectName + "\" here.");
        return false;
    }
    else {
        // continue execution
    }

    serialPrintln(target->getDesc());

    // Special cases
    if (*target == "Laundry basket") {
        if (room->findObject("Sports sock")) {
            // continue execution
        }
        else {
            room->addObject(new Item("Sports sock",
                "A clean white sports sock with blue stripes at the top."));
        }
    }
    else if (*target == "Wardrobe") {
        if (room->findObject("Pack")) {
            // continue execution
        }
        else {
            room->addObject(new Object("Pack",
                "A pack with different socks. "
                "One of them is quite interesting..."));
        }
    }
    else if (*target == "Pack")
        if (room->findObject("Other sports sock")) {
            // continue execution
        }
        else {
            room->addObject(new Item("Other sports sock",
                "A sports sock from a pile of lonely socks."));
        }
    else if (*target == "Washing machine") {
        if (!areKeysFound) {
            serialPrintln("You decide to look inside... And find the keys! "
                "Who knews...");

            if (Inventory::getInstance()->addItem(new Item("Keys",
                "Your set of house keys, finally! "
                "Now you can leave the apartment.", false))) {
                serialPrintln("Now you have your keys.");
                areKeysFound = true;
            }
            else {
                // continue execution
            }
        }
        else {
            // continue execution
        }
    }
    else {
        // continue execution
    }

    return true;
}

void Facade::showInventory() {
    Inventory* inventory = Inventory::getInstance();
    inventory->display();
}

void Facade::lookAround() {
    Room* room = Room::getCurrentRoom();
    vector<string> availableRoomsNames = Room::getAvailableRoomsNames();
    vector<Object*> objects = room->getObjects();

    if (objects.size()) {
        serialPrintln("You may interact with:");
        bool first = true;
        for (size_t i = 0; i < objects.size(); ++i) {
            if (!first) cout << ';' << endl;
            else first = false;
            serialPrint("  " + to_string(i + 1) + 
                ". " + objects[i]->getName());
        }
    }
    else serialPrintln("There is no objects to interact.");

    cout << endl;

    if (availableRoomsNames.size()) {
        serialPrintln("");
        serialPrintln("You may go to:");
        bool first = true;
        for (size_t i = 0; i < availableRoomsNames.size(); ++i) {
            if (!first) cout << ';' << endl;
            else first = false;
            serialPrint("  " + to_string(i + 1) + 
                ". " + availableRoomsNames[i]);
        }
    }
    else serialPrintln("You`re going to be here forever..");

    serialPrintln("");
}

// ==================== Input Processing ====================

bool Facade::parseInput(string& input, string& action, vector<string>& args) {
    // Convert entire input to lowercase for case-insensitive parsing
    for (char& c : input) c = tolower(c);

    istringstream stream(input);
    string token;

    if (stream >> token) {
        action = token;

        // Check for two-word commands
        if (!isCommand(action)) {
            string nextToken;
            if (stream >> nextToken) {
                action += " " + nextToken;
                if (!isCommand(action)) return false;
                else {
                    // continue execution
                }
            }
            else return false;
        }
        else {
            // continue execution
        }

        // Process arguments with proper capitalization
        while (stream >> token) {
            if (!token.empty()) {
                token[0] = toupper(token[0]);
                for (size_t i = 1; i < token.size(); ++i)
                    token[i] = tolower(token[i]);
            }
            else {
                // continue execution
            }
            args.push_back(token);
        }
        return true;
    }
    else {
        // continue execution
    }

    return false;
}

bool Facade::isCommand(const string& curCmd) {
    for (string cmd : commands) {
        if (curCmd == cmd) return true;
        else continue;
    }

    return false;
}

string Facade::combineArgs(const vector<string>& args) {
    stringstream ss;
    for (size_t i = 0; i < args.size(); ++i) {
        if (i > 0) {
            ss << " ";
            string word = args[i];
            if (!word.empty()) word[0] = tolower(word[0]);
            else {
                // continue execution
            }
            ss << word;
        }
        else ss << args[i];
    }
    return ss.str();
}

Item* Facade::parseItem(const vector<string> args, int* index) {
    Inventory* inventory = Inventory::getInstance();
    Item* item = nullptr;
    string itemName;

    while (*index < args.size()) {
        if (itemName.empty())
            itemName = args[*index];
        else {
            string word = args[*index];
            word[0] = tolower(word[0]);
            word = " " + word;
            itemName += word;
        }

        item = inventory->getItem(itemName);
        if (item) {
            ++(*index);
            return item;
        }
        else {
            // continue execution
        }

        ++(*index);
    }

    return item;
}

// ==================== Turn Management ====================

int Facade::updateTurns() {
    ++turns;

    // Update flashlight usage if active
    if (isFlashlightOn) {
        ++lightTurns;

        if (lightTurns >= maxLightTurns) {
            serialPrintln("The phone went dead... Now you can't use it.");

            isFlashlightOn = false;

            Inventory* inventory = Inventory::getInstance();
            Item* phone = inventory->getItem("Phone");

            if (phone) inventory->removeItem(phone);
            else {
                Room* room = Room::getCurrentRoom();
                room->removeObject(phone);
            }

            delete phone;
        }
        else {
            // continue execution
        }
    }
    else {
        // continue execution
    }

    // Check for game over due to time limit
    if (turns >= maxTurns) {
        endGame();
        quitGame();
    }
    else {
        // continue execution
    }

    return turns;
}