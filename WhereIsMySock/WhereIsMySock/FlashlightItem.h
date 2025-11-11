#pragma once
#include "Item.h"

class FlashlightItem : public Item {
private:
    bool isOn;

public:
    FlashlightItem();
    bool useOn(Object* target, Player* player, Room* room) override;
    void toggle();
};