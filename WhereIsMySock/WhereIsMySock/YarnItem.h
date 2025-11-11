#pragma once
#include "Item.h"

class YarnItem : public Item {
public:
    YarnItem();
    bool useOn(Object* target, Player* player, Room* room) override;
};