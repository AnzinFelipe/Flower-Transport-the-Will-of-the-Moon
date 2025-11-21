#include "raylib.h"
#include "screens.h"

GameScreen RunGameOver(void){
    const char opcao[2][16] = {"TENTAR DE NOVO!", "SUCUMBIR..."};
    int selecao = 0;
    Texture2D gameover = LoadTexture("assets/images/Gameover.png");
    GenTextureMipmaps(&gameover);
    SetTextureFilter(gameover, TEXTURE_FILTER_TRILINEAR);
    float pode_apertar = 0.0, delay = 0.1;

    while (!WindowShouldClose()) {

        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_RIGHT)) selecao = !selecao;
        if (IsKeyPressed(KEY_LEFT)) selecao = !selecao;

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
            pode_apertar = 0.0;
            UnloadTexture(gameover);
            return (selecao == 0) ? SCREEN_GAME : SCREEN_MENU;
        }

        BeginDrawing();
        ClearBackground(PURPLE);
        DrawTextureEx(gameover, (Vector2){0,0}, 0.0, 1, WHITE);

        DrawText("Todos foram nocauteados.", 450, 150, 50, RED);
        DrawText("Mas, você ainda pode fazer uma escolha.", 375, 220, 40, GRAY);

        for (int i = 0; i < 2; i++) {
            if (i == selecao) {
                DrawText(opcao[i], 250 + i * 550, 300, 40, (Color){255, 0, 144, 255});
            } else {
                DrawText(opcao[i], 250 + i * 550, 300, 35, WHITE);
            }
        }

        EndDrawing();
    }
    return SCREEN_EXIT;
}