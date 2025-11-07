#include "raylib.h"
#include "screens.h"

GameScreen RunMenu(void) {
    const char opcao[2][15] = {"INICIAR JOGO", "SAIR"};
    int selecao = 0;
    float pode_apertar = 0.0, delay = 0.1;

    while (!WindowShouldClose()) {

        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_UP)) selecao = !selecao;
        if (IsKeyPressed(KEY_DOWN)) selecao = !selecao;
        
        if (IsKeyPressed(KEY_F11) && pode_apertar >= delay) {
            ToggleFullscreen();
            pode_apertar = 0.0;
        }

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
            pode_apertar = 0.0;
            return (selecao == 0) ? SCREEN_GAME : SCREEN_EXIT;
        }

        BeginDrawing();
        ClearBackground(PURPLE);
        
        DrawText("Flower Transport", 400, 150, 60, BLACK);
        DrawText("The Will of The Moon", 450, 220, 30, BLACK);
        
        for (int i = 0; i < 2; i++) {
            if (i == selecao) {
                DrawText(opcao[i], 500, 300 + i * 60, 40, (Color){255, 0, 144, 255});
            } else {
                DrawText(opcao[i], 500, 300 + i * 60, 35, WHITE);
            }
        }
        
        EndDrawing();
    }
    
    return SCREEN_EXIT;
}