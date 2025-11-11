#pragma once
#include "Item.h"

class NoteItem : public Item {
public:
    NoteItem();
    bool useOn(Object* target, Player* player, Room* room) override;
    void read();
};