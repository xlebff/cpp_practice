#include "Player.h"
#include "Room.h"
#include "Inventory.h"

Player* Player::instance = nullptr;

Player::Player() : curRoom(nullptr), inventory(new Inventory(10)) {}

Player::~Player() {
    delete inventory;
    inventory = nullptr;
}

Player* Player::getInstance() {
    if (instance == nullptr) {
        instance = new Player();
    }
    return instance;
}

Room* Player::getCurRoom() const {
    return curRoom;
}

Inventory* Player::getInventory() const {
    return inventory;
}

void Player::setRoom(Room* room) {
    curRoom = room;
}

void Player::completeGame() {
    // код завершения игры
}
