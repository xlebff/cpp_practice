#include "CoinItem.h"
#include "YarnItem.h"

using namespace std;

bool CoinItem::useOn(Object* target, Player* player, Room* room) {
    if (target->getName() == "cat") {
        cout << "The cat wakes up and leaves! He dropped a ball of yarn."
            << endl;

        room->removeObj("cat");
        player->getInventory()->takeItem(new YarnItem());
        return true;
    }
    return false;
}
