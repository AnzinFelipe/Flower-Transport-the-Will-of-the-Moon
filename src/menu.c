#include "raylib.h"
#include "screens.h"

GameScreen RunMenu(void) {
    const char opcao[2][15] = {"INICIAR JOGO", "SAIR"};
    int selecao = 0;
    
    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_UP)) selecao = !selecao;
        if (IsKeyPressed(KEY_DOWN)) selecao = !selecao;
        
        if (IsKeyPressed(KEY_Z)) {
            return (selecao == 0) ? SCREEN_GAME : SCREEN_EXIT;
        }

        BeginDrawing();
        ClearBackground((Color){230, 200, 250, 255}); 
        
        DrawText("Flower Transport", 400, 150, 60, PINK);
        DrawText("the Will of the Moon", 450, 220, 30, PINK);
        
        for (int i = 0; i < 2; i++) {
            if (i == selecao) {
                DrawText(opcao[i], 500, 300 + i * 60, 40, PURPLE);
            } else {
                DrawText(opcao[i], 500, 300 + i * 60, 35, WHITE);
            }
        }
        
        EndDrawing();
    }
    
    return SCREEN_EXIT;
}