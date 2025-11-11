#include "InventoryCommand.h"

InventoryCommand::InventoryCommand()
    : Command("inventory", "Show your inventory") { }

bool InventoryCommand::execute(const std::vector<std::string>& args) {
    Player* player = Player::getInstance();
    player->getInventory()->show();
    return true;
}
