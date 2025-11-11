#pragma once
#include <iostream>
#include "Item.h"

class CoinItem : public Item {
public:
    bool useOn(Object* target, Player* player, Room* room) override;
};
