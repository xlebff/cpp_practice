#include "Facade.h"

using namespace std;

const string commands[] = {
    "quit",
    "help",
    "go to",
    "look around",
    "take",
    "look at",
    "show inventory",
    "drop",
    "use",
    "combine",
    "decombine"
};

enum commandsNum { 
    QUIT,
    HELP,
    GO_TO,
    LOOK_AROUND,
    TAKE,
    LOOK_AT,
    SHOW_INVENTORY,
    DROP,
    USE,
    COMBINE,
    DECOMBINE
};

Facade* Facade::instance = nullptr;

Facade::Facade() {
    turns = 0;
    maxTurns = 50;

    lightTurns = 0;
    maxLightTurns = 10;
}

Facade* Facade::getInstance() {
    if (!instance) instance = new Facade();
    else;
    return instance;
}

bool Facade::isCommand(string& curCmd) {
    for (string cmd : commands) {
        if (curCmd == cmd) return true;
        else continue;
    }

    return false;
}

bool Facade::parseInput(string& input, string& action, vector<string>& args) {
    for (char& c : input) c = tolower(c);

    istringstream stream(input);
    string token;

    if (stream >> token) {
        action = token;

        if (!isCommand(action)) {
            string nextToken;
            if (stream >> nextToken) {
                action += " " + nextToken;
                if (!isCommand(action)) return false;
                else;
            }
            else return false;
        }

        while (stream >> token) {
            if (!token.empty()) {
                token[0] = toupper(token[0]);
                for (size_t i = 1; i < token.size(); ++i) token[i] = tolower(token[i]);
            }
            else;
            args.push_back(token);
        }
        return true;
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
            else;
            ss << word;
        }
        else ss << args[i];
    }
    return ss.str();
}

bool Facade::processInput(string& input) {
    string action;
    vector<string> args;

    if (parseInput(input, action, args)) {
        if (action == commands[QUIT]) return false;
        else if (action == commands[HELP]) showHelp();
        else if (action == commands[GO_TO] && !args.empty()) moveTo(args[0]);
        else if (action == commands[TAKE] && !args.empty()) takeItem(combineArgs(args));
        else if (action == commands[DROP] && !args.empty()) dropItem(combineArgs(args));
        else if (action == commands[LOOK_AT] && !args.empty()) inspect(combineArgs(args));
        else if (action == commands[SHOW_INVENTORY]) showInventory();
        else if (action == commands[LOOK_AROUND]) lookAround();
        else if (action == commands[USE]) useItem(args);
        else {
            cout << "Unknown command or missing arguments: '" << action << "'" << endl;
            cout << "Type 'help' to see available actions." << endl;
            return true;
        }
    }
    else {
        cout << "Unknown command: '" << input << "'" << endl;
        cout << "Type 'help' to see available actions." << endl;
        return true;
    }

    updateTurns();
    return true;
}

void Facade::showWelcome() {
    Room::initializeRooms();

    cout << "=== The Lost Sock Adventure ===" << endl
        << "You wake up and realize one of your favorite socks is missing!" << endl
        << "You can't leave the house with just one sock. Find the missing pair!" << endl
        << "Type 'help' to see available actions." << endl
        << "Type 'quit' to exit the game." << endl << endl
        << "You are in your bedroom. What do you do?" << endl;
    cout << endl << ">  ";
}

void Facade::showHelp() {
    cout << "Available actions:\n";
    cout << "look                - Look around the room\n";
    cout << "look at [object]    - Examine an object closely\n";
    cout << "use [item] [target] - Use an item on an object\n";
    cout << "take [item]         - Take an item\n";
    cout << "drop [item]         - Drop an item\n";
    cout << "go [location]       - Move to another room\n";
    cout << "inventory           - Show your inventory\n";
    cout << "help                - Show this help message\n";
    cout << "quit                - Exit the game\n";
}

bool Facade::moveTo(const string& roomName) {
    Room* room = Room::getRoom(roomName);
    if (!room) {
        cout << "There is no such room." << endl;
        return false;
    }
    else;

    if (Room::isAvailable(room->getName())) {
        cout << "You`re going to the " << room->getName() << endl
            << room->getDesc() << endl;
        Room::setCurrentRoom(room);
        return true;
    }
    else {
        cout << "You cannot enter this room from here." << endl;
        return false;
    }
}

bool Facade::takeItem(const string& itemName) {
    Room* room = Room::getCurrentRoom();
    Inventory* inventory = Inventory::getInstance();

    Object* target = room->findObject(itemName);
    if (!target) {
        cout << "There is no '" << itemName << "' here." << endl;
        return false;
    }
    else;

    Item* itemTarget = dynamic_cast<Item*>(target);
    if (!itemTarget) {
        cout << "You can't take the " << target->getName() << ". It's not an item." << endl;
        return false;
    }

    if (inventory->addItem(itemTarget)) {
        room->removeObj(target);
        cout << "You're taking the " << target->getName() << "." << endl;

        if (*itemTarget == "Sock") trueEnding();
        else;

        return true;
    }
    else;

    return false;
}

bool Facade::dropItem(const string& itemName) {
    Inventory* inventory = Inventory::getInstance();

    Item* item = inventory->getItem(itemName);

    if (!item) {
        cout << "You don`t have the " << itemName << "." << endl;
        return false;
    }
    else if (!(item->isDetachable())) {
        cout << "You can't throw the " << itemName << " away." << endl;
        return false;
    }
    else;

    Room* room = Room::getCurrentRoom();

    inventory->removeItem(item);
    cout << "Now you don`t have the " << item->getName() << "." << endl;
    room->addObj(item);

    return true;
}

void Facade::lookAround() {
    Room* room = Room::getCurrentRoom();
    vector<string> availableRoomsNames = Room::getAvailableRoomsNames();
    vector<Object*> objects = room->getObjs();

    if (objects.size()) {
        cout << "You may interact with:" << endl;
        bool first = true;
        for (size_t i = 0; i < objects.size(); ++i) {
            if (!first) cout << ";" << endl;
            else first = false;
            cout << "  " << i + 1 << ". " << objects[i]->getName();
        }
    }
    else cout << "There is no objects to interact." << endl;

    cout << endl;

    if (availableRoomsNames.size()) {
        cout << endl << "You may go to:" << endl;
        bool first = true;
        for (size_t i = 0; i < availableRoomsNames.size(); ++i) {
            if (!first) cout << ";" << endl;
            else first = false;
            cout << "  " << i + 1 << ". " << availableRoomsNames[i];
        }
    }
    else cout << "You`re going to be here forever.." << endl;

    cout << endl;
}

bool Facade::inspect(const string& objectName) {
    Room* room = Room::getCurrentRoom();

    Object* target = room->findObject(objectName);
    if (!target) {
        cout << "There is no '" << objectName << "' here." << endl;
        return false;
    }
    else;

    cout << target->getDesc() << endl;

    if (*target == "Laundry basket")
        room->addObj(new Item("Sports sock",
            "A clean white sports sock with blue stripes at the top."));
    else;

    return true;
}

void Facade::showInventory() {
    Inventory* inventory = Inventory::getInstance();
    inventory->display();
}

bool Facade::useItem(vector<string> args) {
    Inventory* inventory = Inventory::getInstance();

    int index = 1;
    Item* item = nullptr;
    string itemName = args[0];

    for (; index <= args.size(); ++index) {
        item = inventory->getItem(itemName);
        if (!item) {
            string word = args[index];
            word[0] = tolower(word[0]);
            word = " " + word;
            itemName += word;
        }
        else break;
    }

    if (!item) {
        cout << "You don`t have the " << itemName << "." << endl;
        return false;
    }
    else;

    Object* target = nullptr;

    if (index < args.size()) {
        Room* room = Room::getCurrentRoom();

        string objectName = args[index];

        for (; index < args.size(); ++index) {
            target = room->findObject(objectName);
            if (!target) {
                if (index + 1 < args.size()) {
                    string word = args[index + 1];
                    word[0] = tolower(word[0]);
                    word = " " + word;
                    objectName += word;
                }
                else break;
            }
            else break;
        }
    }
    else;

    if (!UsageManager::processUsage(item, target)) {
        cout << "You can`t use your item this way." << endl;
        return false;
    }
    else return true;
}

int Facade::updateTurns() {
    ++turns;

    if (UsageManager::isFlashlightOn) {
        ++lightTurns;

        if (lightTurns >= maxLightTurns) {
            cout << "The phone went dead... Now you can't use it." << endl;

            UsageManager::isFlashlightOn = false;

            Inventory* inventory = Inventory::getInstance();
            Item* phone = inventory->getItem("Phone");

            if (phone) inventory->removeItem(phone);
            else {
                Room* room = Room::getCurrentRoom();
                room->removeObj(phone);
            }

            delete phone;
        }
        else;
    }
    else;

    if (turns >= maxTurns) {
        Inventory* inventory = Inventory::getInstance();

        if (inventory->getItem("Sports sock")) {
            if (inventory->getItem("Other sports sock")) {
                cout << "You're late! In a hurry, you decide to go in a pair of sports"
                    << " socks. The boss will be unhappy!" << endl;

                cout << "Good ending: The wrong pair." << endl;
            }
            else {
                cout << "You're late! In your haste, you decide to wear different socks."
                    << " How awful! It's completely unacceptable, "
                    << "but there's nothing you can do about it..." << endl;

                cout << "Bad ending: Tasteless and terribly disorganized." << endl;
            }
        }
        else {
            cout << "Horrible! You don't even have a sock! "
                << "You'll have to run to the store, but that will take a long time."
                << endl;

            cout << "Bad ending: Seriously late." << endl;
        }

        endGame();
    }
    else;
    
    return turns;
}

int Facade::getTurns() { return turns; }
int Facade::getMaxTurns() { return maxTurns; }

bool Facade::trueEnding() {
    Inventory* inventory = Inventory::getInstance();

    if (inventory->getItem("Sock")) {
        cout << "You did it! The couple was reunited. You went to work calmly."
            << endl;

        cout << "True ending: Great day." << endl;

        endGame();
        return true;
    }
    else return false;
}

void Facade::endGame() {
    cout << "Thanks for playing!" << endl;

    Room::cleanup();
    Inventory::cleanup();

    delete instance;
    instance = nullptr;

    exit(0);
}
