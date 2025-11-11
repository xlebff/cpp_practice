#pragma once
#include "Item.h"

class ScrewdriverItem : public Item {
public:
    ScrewdriverItem();
    bool useOn(Object* target, Player* player, Room* room) override;
};