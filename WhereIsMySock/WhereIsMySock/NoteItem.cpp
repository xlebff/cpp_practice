#include <iostream>

using namespace std;

NoteItem::NoteItem()
    : Item("note", "A folded piece of paper with writing", {}, {}, true) {
}

bool NoteItem::useOn(Object* target, Player* player, Room* room) {
    if (target->getName() == "read" || target->getName() == "player") {
        read();
        return true;
    }
    cout << "You can't use the note on the " << target->getName() << "." << endl;
    return false;
}

void NoteItem::read() {
    cout << "You unfold the note and read:" << endl
        << "\"Dear roommate, I borrowed your sock for a art project.\"" << endl
        << "\"Check the balcony! - Cat Vasya\"" << endl;
}