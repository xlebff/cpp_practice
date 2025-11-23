#include "Item.h"
#include "Room.h"

using namespace std;

Room* Room::currentRoom;
vector<Room*> Room::allRooms;
vector<bool> Room::availableRooms;

enum RoomIndexes {
    BEDROOM,
    LIVINGROOM,
    KITCHEN,
    BATHROOM,
    BALCONY
};

const std::string roomNames[] = {
    "Bedroom",
    "Livingroom",
    "Kitchen",
    "Bathroom",
    "Balcony"
};

/**
 * @brief Room availability matrix defining navigation possibilities
 *
 * Matrix where [fromRoom][toRoom] indicates if movement is allowed
 * Format: {Bedroom, Livingroom, Kitchen, Bathroom, Balcony}
 */
static std::vector<std::vector<bool>> availableForEachRoom = {
    { false, true,  false, false, false },  // From Bedroom
    { true,  false, true,  true,  false },  // From Livingroom
    { false, true,  false, true,  false },  // From Kitchen
    { false, true,  true,  false, false },  // From Bathroom
    { true,  false, false, false, false }   // From Balcony
};

const int roomsCount = 5;

// ==================== Constructor & Destructor ====================

Room::Room(const string& name,
    const string& desc,
    const vector<Object*> objs,
    const bool available) :
    name(name), desc(desc), objs(objs) {
    allRooms.push_back(this);
    availableRooms.push_back(available);
    index = (int)allRooms.size() - 1;
}

Room::~Room() {
    for (Object* obj : objs) 
        delete obj;

    objs.clear();
}

// ==================== Static Room Management ====================

void Room::initializeRooms() {
    allRooms = {
        new Room("Bedroom",
            "Your cozy bedroom. There's a bed, a wardrobe, and a nightstand.",
            {
                new Object("Cat", 
                    "A fluffy ginger cat named Vasya is lazily stretching on "
                    "the floor. There's a red ball under it..."),
                new Object("Bed", "A neatly made single bed with a blue "
                    "comforter. It looks comfortable and inviting."),
                new Object("Nightstand", "A small wooden nightstand with "
                    "a drawer. There's a lamp and an alarm clock on top."),
                new Item("Pencil", 
                    "A standard yellow pencil with a sharp tip."),
                new Item("Lamp", "A new, unpacked light bulb."),
                new Item("Phone", "Your smartphone. The battery is at 25%."),
                new Object("Wardrobe", 
                    "A tall wooden cabinet with two doors. "
                    "It looks like your clothes and other personal "
                    "items are stored in it.\n"
                    "For example, a toolbox. But it's empty... "
                    "You distributed its contents to your neighbors. "
                    "All that's left are the screwdriver tips, which you "
                    "just can't get... But they are magnetic.\n"
                    "Wow, there's also a bag of lonely socks!"),
                new Object("Door", "The jammed door to the balcony. "
                    "Perhaps you should use some kind of tool.")
            },
            true),

        new Room("Livingroom",
            "A comfortable living room with a sofa, TV, and coffee table. "
            "\nSunlight streams through the window, "
            "illuminating dust particles dancing in the air.",
            {
                new Object("Sofa", "A comfortable-looking sofa with "
                    "soft cushions. Perfect for relaxing after a long day."),
                new Item("Note",
                    "You unfold the note and read: \"Dear roommate, "
                    "I borrowed your sock for a art project. "
                    "Check the balcony! - Cat Vasya\""),
                new Object("TV", 
                    "A large flat-screen TV mounted on the wall. "
                    "There's a thin layer of dust on top - and what appear "
                    "to be tiny paw prints."),
                new Object("Bookshelf", 
                    "A tall oak bookshelf filled with books. "
                    "Several volumes on the lower shelf"
                    "are slightly askew, as if someone - or something - "
                    "has been browsing recently."),
                new Object("Armchair", 
                    "A brand new leather armchair that still smells "
                    "faintly of the store. "
                    "There are already a few fine scratch marks "
                    "on one armrest."),
                new Object("Fountain pen set", 
                    "An expensive-looking set of fountain pens in a "
                    "velvet case. One pen is missing from its slot."),
                new Object("Ficus", 
                    "A healthy ficus tree in a ceramic pot. "
                    "Some leaves on the lower branches look "
                    "slightly battered, and there's soil "
                    "scattered around the base."),
                new Object("Tulle", 
                    "Elegant tulle curtains framing the window. "
                    "The right curtain has "
                    "several small snags and loose threads "
                    "about a foot from the bottom."),
                new Object("Window", 
                    "Through the window you see a peaceful residential street."
                    " The balcony is visible to the left, where what appears "
                    "to be a single sock is draped over the railing. "
                    "A neighbor's cat suns itself on a nearby fence.")
            },
            true),

        new Room("Kitchen",
            "A clean kitchen with modern appliances and a cozy dining table. "
            "The room smells faintly of citrus cleaner.",
            {
                new Object("Kitchen table", "A simple wooden kitchen table "
                    "with a clean surface. A fruit bowl sits in the center."),
                new Object("Sink", "A stainless steel kitchen sink. "
                    "It's clean and dry, with a faucet that looks "
                    "relatively new."),
                new Item("Glass of water", 
                    "A full glass of clear, fresh water."),
                new Object("Flower", "A disgruntled flower... "
                    "The soil is completely dry!"),
                new Item("Apple", 
                    "A shiny red apple. It looks crisp and fresh."),
                new Item("Fork", "A standard stainless steel fork. "
                    "It's clean and polished."),
                new Object("Refrigerator", "A stainless steel refrigerator "
                    "covered in an assortment of magnets - a cartoon cat, "
                    "a miniature Eiffel Tower, a pizza-shaped magnet, and "
                    "one that says 'World's Okayest Roommate'. There's "
                    "a faint humming sound coming from it."),
                new Object("Cabinets", "White wooden cabinets containing "
                    "neatly organized dishes, cups, and cooking utensils. "
                    "One cabinet door doesn't quite close properly."),
                new Object("Microwave", "A sleek black microwave oven. "
                    "The digital display shows the current time."),
                new Object("Stove", "A full-sized gas stove with four burners"
                    " and a large oven below. The stovetop is spotless, "
                    "suggesting it hasn't been used recently."),
                new Object("Painting", "A colorful painting of a llama wearing"
                    " a sombrero, standing in a field of cacti. The llama has "
                    "an oddly judgmental expression."),
                new Object("Trash bin", "A stainless steel step-on trash can. "
                    "The lid opens smoothly when you press the pedal."),
                new Object("Entrance door",
                    "A solid wooden door leading outside. It has a sturdy lock and a peephole. "
                    "Your keys are definitely not in it right now.")
            }),

        new Room("Bathroom", "A dark bathroom. "
            "The light bulb burned out yesterday, so you can't see anything."),

        new Room("Balcony",
        "A cozy balcony with a wrought-iron railing, offering a "
        "pleasant view of the quiet street below.\nPotted plants line "
        "the edges, and the air smells fresh.",
        {
            new Object("Clothesline",
                "A drying clothesline stretched across the balcony. "
                "A single striped sock hangs from it, swaying "
                "gently in the breeze. The sock has some curious "
                "paint stains on it."),
            new Object("Trash bin", "A plastic trash bin in the corner. "
                "It's mostly empty with just some "
                "crumpled papers inside."),
            new Object("Planters", "Several terracotta pots containing "
                "herbs and flowers. The mint plant looks particularly "
                "healthy and fragrant."),
            new Object("Folding chair", "A simple folding chair leaning "
                "against the wall. There are a few cat "
                "hairs on the seat."),
            new Object("Railing", "The wrought-iron railing is slightly "
                "warm from the sun. You can see children playing "
                "in the street below."),
            new Item("Painted pebble", "A smooth, flat pebble with a "
                "colorful paw print painted on it. It feels warm from "
                "sitting in the sun."),
            new Item("Gardening_gloves", "A pair of worn leather "
                "gardening gloves, slightly too big but serviceable."),
            new Item("Empty flowerpot", "A small empty terracotta pot, "
                "perfect for planting something new."),
            new Item("Breeze chimes", "Delicate wooden chimes that make "
                "a soft clicking sound in the wind."),
            new Object("Bird feeder", "A small bird feeder hanging from "
                "the ceiling. It's empty, but there are bird tracks in "
                "the dust around it."),
            new Item("Corkscrew", "A simple corkscrew that must have "
                "been left out here after some balcony wine evening."),
            new Object("Floor mat", "A welcome mat by the balcony door "
                "with a faded 'Hello' pattern.")
        },
        false)
    };

    setCurrentRoom(getRoom("Bedroom"));
}

void Room::cleanup() {
    for (Room* room : allRooms)
        delete room;

    allRooms.clear();
    availableRooms.clear();
    currentRoom = nullptr;
}

Room* Room::getCurrentRoom() { return currentRoom; }

void Room::setCurrentRoom(Room* room) {
    currentRoom = room;
    availableRooms = availableForEachRoom[room->getIndex()];
}

Room* Room::getRoom(const string& name) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (*allRooms[i] == name) 
            return allRooms[i];
        else continue;
    }

    return nullptr;
}

bool Room::setAvailability(const int fromRoom, 
    const int toRoom, const bool available) {
    if (fromRoom >= 0 && fromRoom < roomsCount &&
        toRoom >= 0 && toRoom < roomsCount) {
        availableForEachRoom[fromRoom][toRoom] = available;
        return true;
    }
    else return false;
}

bool Room::isAvailable(const std::string& roomName) {
    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (*allRooms[i] == roomName)
            return availableRooms[i];
        else continue;
    }

    return false;
}

vector<Room*> Room::getAllRooms() { return allRooms; }

vector<bool> Room::getAvailableRooms() { return availableRooms; }

vector<string> Room::getAvailableRoomsNames() {
    vector<string> names = {};

    for (size_t i = 0; i < allRooms.size(); ++i) {
        if (availableRooms[i]) 
            names.push_back(allRooms[i]->getName());
        else continue;
    }

    return names;
}

// ==================== Object Management ====================

Object* Room::findObject(const string& objName) {
    for (Object* obj : objs) {
        if (*obj == objName) return obj;
        else continue;
    }

    return nullptr;
}

bool Room::addObject(Object* item) {
    if (item == nullptr) return false;
    else {
        objs.push_back(item);
        return true;
    }
}

bool Room::removeObject(Object* item) {
    if (item == nullptr) return false;\
    else {
        for (auto it = objs.begin(); it != objs.end(); ++it) {
            if (*it == item) {
                objs.erase(it);
                return true;
            }
            else continue;
        }

        return false;
    }
}

vector<Object*> Room::getObjects() const { return objs; }

// ==================== Room Properties ====================

int Room::getIndex() const { return index; }

string Room::getName() const { return name; }

string Room::getDesc() const { return desc; }

void Room::setDesc(string newDesc) { desc = newDesc; }

void Room::setDesc(const char* newDesc) { desc = newDesc; }

// ==================== Operators ====================

bool Room::operator==(const string other) const {
    return (name == other);
}
