#include "Facade.h"

using namespace std;

const string commands[] = {
    "quit",
    "help",
    "go to",
    "look around",
    "take",
    "inspect"
};

enum commandsNum { QUIT, HELP, GO_TO, LOOK_AROUND, TAKE, INSPECT };

Facade* Facade::instance = nullptr;

Facade::Facade() { }

Facade* Facade::getInstance() {
    if (!instance) instance = new Facade();
    else;
    return instance;
}

bool Facade::processInput(string& input) {
    string action;
    vector<string> args;
    
    if (parseInput(input, action, args)) {
        if (action == commands[QUIT]) {
            cout << "Thanks for playing!" << endl;
            return false;
        }
        else if (action == commands[HELP]) showHelp();
        else if (action == commands[GO_TO] && args.size()) moveTo(args[0]);
        /* else if (action == commands[TAKE] && args.size()) takeItem(args[0]); */
        /*
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
        } */
        else if (action == commands[INSPECT] && args.size()) inspect(args[0]);
        /* else if (action == "inventory") {
            showInventory();
        } */
        else if (action == commands[LOOK_AROUND]) lookAround();
        else;
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
        cout << "You`re taking the " << target->getName() << "." << endl;
        return true;
    }
    else;

    return false;
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
    return true;
}

bool isCommand(string& curCmd) {
    for (string cmd : commands) {
        if (curCmd == cmd) return true;
        else continue;
    }

    return false;
}

bool Facade::parseInput(string& input, string& action, vector<string>& args) {
    for (char &c : input) c = tolower(c);

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
        else;

        while (stream >> token) args.push_back(token);
        return true;
    }
    else return false;
}
