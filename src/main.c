#include "raylib.h"

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
        DrawCircle(largura / 2, altura / 2, 200, PINK);
        DrawText("Flower Transport\nthe Will of the Moon", largura / 2, altura / 2, 50, DARKGRAY);

        EndDrawing();
    }

    UnloadMusicStream(pink);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}