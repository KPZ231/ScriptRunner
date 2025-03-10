#pragma once
#include <raylib.h>

class Player {
public:
    Player();  // Konstruktor
    ~Player(); // Destruktor

    int getHealth() const { return health; }  // Getter dla zdrowia
    void setHealth(int hp) { health = hp; }   // Setter dla zdrowia

    Vector2 getPosition() const { return position; } // Getter dla pozycji
    void setPosition(Vector2 pos) { position = pos; } // Setter dla pozycji

    bool isPlayerAlive() const { return isAlive; } // Getter dla statusu ¿ycia

private:
    int health;
    Vector2 position;
    bool isAlive;
};




