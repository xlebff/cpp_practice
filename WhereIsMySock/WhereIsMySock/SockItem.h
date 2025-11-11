#pragma once
#include "Item.h"

class SockItem : public Item {
public:
    SockItem(bool isMissing = false);
    bool useOn(Object* target, Player* player, Room* room) override;
};