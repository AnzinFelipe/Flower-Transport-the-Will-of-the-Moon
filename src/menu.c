#include "raylib.h"
#include "screens.h"

GameScreen RunMenu(void) {
    const char opcao[2][15] = {"INICIAR JOGO", "SAIR"};
    Texture2D menu1 = LoadTexture("assets/images/Menu1.png");
    GenTextureMipmaps(&menu1);
    SetTextureFilter(menu1, TEXTURE_FILTER_TRILINEAR);
    Texture2D menu2 = LoadTexture("assets/images/Menu2.png");
    GenTextureMipmaps(&menu2);
    SetTextureFilter(menu2, TEXTURE_FILTER_TRILINEAR);
    int selecao = 0;
    float pode_apertar = 0.0, delay = 0.1;

    while (!WindowShouldClose()) {

        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_UP)) selecao = !selecao;
        if (IsKeyPressed(KEY_DOWN)) selecao = !selecao;

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
            pode_apertar = 0.0;
            UnloadTexture(menu1);
            UnloadTexture(menu2); 
            return (selecao == 0) ? SCREEN_CUTSCENE : SCREEN_EXIT;
        }

        BeginDrawing();
        ClearBackground(PURPLE);
        for (int i = 0; i < 2; i++) {
            if (i == selecao) {
                DrawTextureEx(menu2, (Vector2){0, 0}, 0.0, 1, WHITE);
            } else {
                DrawTextureEx(menu1, (Vector2){0, 0}, 0.0, 1, WHITE);
            }
        }
        
        EndDrawing();
    }
    
    return SCREEN_EXIT;
}