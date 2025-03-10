#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h" // Dla Vector2

class Player {
public:
    Player();  // Konstruktor
    ~Player(); // Destruktor

    int getHealth() const;
    void setHealth(int hp);

    Vector2 getPosition() const;
    void setPosition(Vector2 pos);

    bool isPlayerAlive() const;

private:
    int health;
    Vector2 position;
    bool isAlive;
};

#endif // PLAYER_H

