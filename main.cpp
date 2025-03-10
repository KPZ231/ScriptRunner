// Wbudowane Nagłówki
#include <raylib.h>

// Swoje Nagłówki
#include "Player.h"

int main() {
    // Okno
    const int _WIDTH_ = 1200;
    const int _HEIGHT_ = 700;

    InitWindow(_WIDTH_, _HEIGHT_, "Code Thief");
    SetTargetFPS(60);

    // 🔹 Pozycja gracza
    float playerX = _WIDTH_ / 2;
    float playerY = _HEIGHT_ - 100; // Startowa pozycja nad podłogą
    float speed = 5.0f; // Szybkość ruchu w lewo/prawo
    float gravity = 0.6f; // Grawitacja
    float velocityY = 0.0f; // Prędkość pionowa (do skakania)
    bool isOnGround = false; // Czy gracz stoi na podłożu

    // 🔹 Podłoga
    float floorY = _HEIGHT_ - 50; // Pozycja podłogi

    while (!WindowShouldClose()) {
        // 🔹 Ruch w lewo/prawo
        if (IsKeyDown(KEY_A)) playerX -= speed;
        if (IsKeyDown(KEY_D)) playerX += speed;

        // 🔹 Skakanie
        if (isOnGround && IsKeyPressed(KEY_SPACE)) {
            velocityY = -12.0f; // Siła skoku
            isOnGround = false;
        }

        // 🔹 Grawitacja
        velocityY += gravity; // Przyspieszenie w dół
        playerY += velocityY; // Aktualizacja pozycji Y

        // 🔹 Kolizja z podłogą
        if (playerY + 50 >= floorY) {
            playerY = floorY - 50; // Ustawienie gracza na podłodze
            velocityY = 0; // Zerowanie prędkości Y
            isOnGround = true;
        }

        // 🔹 Ograniczenia ekranu (gracz nie wychodzi poza okno)
        if (playerX < 0) playerX = 0;
        if (playerX > _WIDTH_ - 50) playerX = _WIDTH_ - 50;

        // 🔹 Rysowanie ekranu
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Podłoga
        DrawRectangle(0, floorY, _WIDTH_, 50, DARKGRAY);

        // Kwadrat (gracz)
        DrawRectangle(playerX, playerY, 50, 50, RED);

        EndDrawing();
    }

    CloseWindow(); // Zamknięcie okna
    return 0;
}
