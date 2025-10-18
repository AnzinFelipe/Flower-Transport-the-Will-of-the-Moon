#include "raylib.h"

int main(void)
{
    // Inicializa a janela com a raylib
    InitWindow(800, 600, "Hello Raylib!");

    // Define a taxa de quadros por segundo
    SetTargetFPS(60);

    // Loop de execução
    while (!WindowShouldClose())
    {
        // Inicia o desenho
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Olá, Raylib!", 10, 10, 20, DARKGRAY);

        EndDrawing();
    }

    // Fecha a janela
    CloseWindow();

    return 0;
}