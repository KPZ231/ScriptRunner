#include "Player.h"

Player::Player() : health(100), position({ 0, 0 }), isAlive(true) {}

Player::~Player() {}

int Player::getHealth() const {
    return health;
}

void Player::setHealth(int hp) {
    health = hp;
}

Vector2 Player::getPosition() const {
    return position;
}

void Player::setPosition(Vector2 pos) {
    position = pos;
}

bool Player::isPlayerAlive() const {
    return isAlive;
}
