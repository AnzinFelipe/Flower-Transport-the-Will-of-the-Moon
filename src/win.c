#include "raylib.h"
#include "screens.h"

GameScreen RunGameWin(void)
{
    const char opcao[2][16] = {"JOGAR NOVAMENTE", "MENU PRINCIPAL"};
    int selecao = 0;
    
    Texture2D gamewin = LoadTexture("assets/images/Gamewin.png");
    SetTextureFilter(gamewin, TEXTURE_FILTER_TRILINEAR);
    
    float pode_apertar = 0.0, delay = 0.1;

    while (!WindowShouldClose())
    {
        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_RIGHT)) selecao = !selecao;
        if (IsKeyPressed(KEY_LEFT)) selecao = !selecao;

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay)
        {
            pode_apertar = 0.0;
            UnloadTexture(gamewin);
            return (selecao == 0) ? SCREEN_GAME : SCREEN_MENU;
        }

        BeginDrawing();
        
        ClearBackground(GREEN);
        DrawTexture(gamewin, 0, 0, WHITE);

        DrawText("Vitória!", 600, 150, 80, GOLD);
        DrawText("Parabéns! Você venceu o jogo.", 450, 250, 40, WHITE);

        for (int i = 0; i < 2; i++)
        {
            if (i == selecao)
            {
                DrawText(opcao[i], 250 + i * 700, 500, 40, YELLOW);
            }
            else
            {
                DrawText(opcao[i], 250 + i * 700, 500, 35, WHITE);
            }
        }

        EndDrawing();
    }
    
    return SCREEN_EXIT;
}