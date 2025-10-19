#include "raylib.h"
#include "../include/personagem.h"

int main(void)
{
    int largura = 1600, altura = 900;

    InitWindow(largura, altura, "Flower Transport - the Will of the Moon");

    InitAudioDevice();
    Music pink = LoadMusicStream("assets/music/Pink.mp3");
    PlayMusicStream(pink);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(pink);

        BeginDrawing();

        ClearBackground(WHITE);
        DrawRectangle(0, 600, largura / 4, 300, PURPLE);
        DrawRectangle(largura / 4, 600, largura / 4, 300, RED);
        DrawRectangle(largura / 2, 600, largura / 4, 300, ORANGE);
        DrawRectangle(largura - (largura / 4), 600, largura / 4, 300, GREEN);
        DrawText("Flower Transport\nthe Will of the Moon", largura / 2, altura / 2, 50, DARKGRAY);

        EndDrawing();
    }

    UnloadMusicStream(pink);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}