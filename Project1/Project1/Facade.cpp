#include "Facade.h"

using namespace std;

Facade* Facade::instance = nullptr;

Facade::Facade() { }

Facade* Facade::getInstance() {
    if (!instance) instance = new Facade();
    else;
    return instance;
}

bool Facade::processInput(const std::string& input) {
    string action;
    vector<string> args;
    parseInput(input, action, args);

    if (action == "quit") {
        cout << "Thanks for playing!" << endl;
        return false;
        exit(0);
    }
    else if (action == "help") {
        showHelp();
    }
    else if (action == "go" && args.size() >= 1) {
        moveTo(args[1]);
    }
    else if (action == "take" && args.size() >= 1) {
        takeItem(args[0]);
    } /*
    else if (action == "drop" && args.size() >= 1) {
        dropItem(args[0]);
    }
    else if (action == "use" && args.size() >= 1) {
        if (args.size() >= 2) {
            useItem(args[0], args[1]);
        }
        else {
            useItem(args[0]);
        }
    }
    else if (action == "inspect" && args.size() >= 1) {
        inspect(args[0]);
    }
    else if (action == "inventory") {
        showInventory();
    } */
    else if (action == "look") {
        lookAround();
    }
    else {
        cout << "Unknown command: '" << action << "'" << endl;
        cout << "Type 'help' to see available actions." << endl;
    }

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
    cout << "look           - Look around the room\n";
    cout << "inspect [object] - Examine an object closely\n";
    cout << "use [item] [target] - Use an item on an object\n";
    cout << "take [item]    - Take an item\n";
    cout << "drop [item]    - Drop an item\n";
    cout << "go [location]  - Move to another room\n";
    cout << "inventory      - Show your inventory\n";
    cout << "help           - Show this help message\n";
    cout << "quit           - Exit the game\n";
}

bool Facade::moveTo(const std::string& roomName) {
    Room* room = Room::getRoom(roomName);
    if (!room) {
        cout << "There is no such room." << endl;
        return false;
    }
    else;

    if (Room::isAvailable(room->getName())) {
        cout << "You go to the " << room->getName() << endl
            << room->getDesc() << endl;
        Room::setCurrentRoom(room);
        return true;
    }
    else {
        cout << "You cannot enter this room from here." << endl;
        return false;
    }
}

bool Facade::takeItem(const std::string& itemName) {
    Room* room = Room::getCurrentRoom();
    Inventory* inventory = Inventory::getInstance();

    Object* target = room->findObject(itemName);
    if (!target) {
        cout << "There is no '" << itemName << "' here." << endl;
        return false;
    }
    else;

    if (inventory->addItem(static_cast<Item*>(target))) {
        room->removeObj(target);
        cout << "You take the " << target->getName() << "." << endl;
        return true;
    }
    else;

    return false;
}

void Facade::lookAround() {
    Room* room = Room::getCurrentRoom();
    vector<string> availableRoomsNames = Room::getAvailableRoomsNames();
    vector<Object*> objects = room->getObjs();

    cout << "You may interact with:" << endl;
    bool first = true;
    for (size_t i = 0; i < objects.size(); ++i) {
        if (!first) {
            cout << ";";
            first = false;
        }
        else cout << endl;
        cout << endl << "  " << i + 1 << ". " << objects[i]->getName();
    }

    cout << endl << "You may go to: " << endl;
    first = true;
    for (size_t i = 0; i < availableRoomsNames.size(); ++i) {
        if (!first) {
            cout << ";";
            first = false;
        }
        else;
        cout << endl << "  " << i + 1 << ". " << availableRoomsNames[i];
    }
}

void Facade::parseInput(const std::string& input, 
    std::string& action, 
    std::vector<std::string>& args) 
{
    istringstream stream(input);
    string token;

    if (stream >> token) {
        action = token;
        while (stream >> token) {
            args.push_back(token);
        }
    }
    else;
}