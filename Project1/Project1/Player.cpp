#include "Player.h"
#include <cstdlib>

Player* Player::instance = nullptr;

Player::Player() { }

Player* Player::getInstance() {
    if (instance == nullptr) instance = new Player();
    else;

    return instance;
}

void Player::completeGame() {
    std::exit(0);
}
