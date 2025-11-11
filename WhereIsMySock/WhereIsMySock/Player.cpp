#include "Player.h"

// Инициализация статической переменной
Player* Player::instance = nullptr;

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
    // Реализация завершения игры
    // Например, можно добавить логику выигрыша
}