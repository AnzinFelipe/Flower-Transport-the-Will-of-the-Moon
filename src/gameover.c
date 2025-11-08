#include "raylib.h"
#include "screens.h"

GameScreen RunGameOver(void){
    const char opcao[2][16] = {"TENTAR DE NOVO!", "SUCUMBIR..."};
    int selecao = 0;
    float pode_apertar = 0.0, delay = 0.1;

    while (!WindowShouldClose()) {

        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_RIGHT)) selecao = !selecao;
        if (IsKeyPressed(KEY_LEFT)) selecao = !selecao;
        
        if (IsKeyPressed(KEY_F11) && pode_apertar >= delay) {
            ToggleFullscreen();
            pode_apertar = 0.0;
        }

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
            pode_apertar = 0.0;
            return (selecao == 0) ? SCREEN_GAME : SCREEN_MENU;
        }

        BeginDrawing();
        ClearBackground(PURPLE);

        DrawText("Todos foram nocauteados.", 300, 150, 50, RED);
        DrawText("Mas, você ainda pode fazer uma escolha.", 250, 220, 40, BLACK);

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