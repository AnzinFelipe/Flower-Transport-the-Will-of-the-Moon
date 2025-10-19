#include "raylib.h"
#include "../include/personagem.h"

int main(void)
{
    int largura = 1600, altura = 900;

    InitWindow(largura, altura, "Flower Transport - the Will of the Moon");

    InitAudioDevice();
    Music pink = LoadMusicStream("assets/music/Pink.mp3");
    PlayMusicStream(pink);

    int escolhas = 1, escolhas_flores = 0;
    int vez_inimigo = 0;
    float pode_apertar = 0.0, delay = 0.3;
    Personagem roxo;
    roxo.vida = 100;
    roxo.energia = 100;
    roxo.flor_dia.nome = "Flor Solar";

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(pink);

        pode_apertar += GetFrameTime();

        BeginDrawing();

        ClearBackground(WHITE);
        DrawRectangle(0, 600, largura / 4, 300, PURPLE);
        DrawRectangle(largura / 4, 600, largura / 4, 300, RED);
        DrawRectangle(largura / 2, 600, largura / 4, 300, ORANGE);
        DrawRectangle(largura - (largura / 4), 600, largura / 4, 300, GREEN);

        if (vez_inimigo == 1) {
            DrawText("Vez do Inimigo", largura / 2 - 100, 100, 40, BLACK);
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                vez_inimigo = 0;
                escolhas = 1;
                pode_apertar = 0.0;
            }
        } else {
            DrawText("Sua Vez", largura / 2 - 100, 100, 40, BLACK);
        }

        if (escolhas == 1) {
            DrawText("Flores Diurnas", largura / 2 - 100, altura / 2, 40, BLACK);
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                escolhas = 0;
                escolhas_flores = 1;
                pode_apertar = 0.0;
            }
        }
        if (escolhas_flores == 1) {
            DrawText(roxo.flor_dia.nome, largura / 2 - 100, altura / 2, 40, BLACK);
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                escolhas_flores = 0;
                vez_inimigo = 1;
                pode_apertar = 0.0;
            }
        }

        EndDrawing();
    }

    UnloadMusicStream(pink);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}