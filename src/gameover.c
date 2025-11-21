#include "raylib.h"
#include "screens.h"
#include <math.h>

GameScreen RunGameOver(void){
    const char opcao[2][16] = {"TENTAR DE NOVO!", "SUCUMBIR..."};
    int selecao = 0;
    Texture2D gameover = LoadTexture("assets/images/Gameover.png");
    GenTextureMipmaps(&gameover);
    SetTextureFilter(gameover, TEXTURE_FILTER_TRILINEAR);
    float pode_apertar = 0.0, delay = 0.1;
    int largura = 1600, altura = 900;
    RenderTexture2D janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(janela.texture, TEXTURE_FILTER_TRILINEAR);

    while (!WindowShouldClose()) {

        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_RIGHT)) selecao = !selecao;
        if (IsKeyPressed(KEY_LEFT)) selecao = !selecao;

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
            pode_apertar = 0.0;
            UnloadTexture(gameover);
            return (selecao == 0) ? SCREEN_GAME : SCREEN_MENU;
        }
        
        BeginTextureMode(janela);
        
        ClearBackground(PURPLE);
        DrawTextureEx(gameover, (Vector2){0,0}, 0.0, 1, WHITE);

        DrawText("Todos foram nocauteados.", 450, 150, 50, RED);
        DrawText("Mas, você ainda pode fazer uma escolha.", 375, 220, 40, GRAY);

        for (int i = 0; i < 2; i++) {
            if (i == selecao) {
                DrawText(opcao[i], 250 + i * 700, 300, 40, (Color){255, 0, 144, 255});
            } else {
                DrawText(opcao[i], 250 + i * 700, 300, 35, WHITE);
            }
        }

        EndTextureMode();

        BeginDrawing();

        int largura_nova = GetScreenWidth();
        int altura_nova = GetScreenHeight();

        float escala = fminf((float)largura_nova/largura, (float)altura_nova/altura);
        float largura_escala = largura * escala;
        float altura_escala = altura * escala;
        float offsetX = (largura_nova - largura_escala) / 2.0f;
        float offsetY = (altura_nova - altura_escala) / 2.0f;

        DrawTexturePro(janela.texture,
            (Rectangle){ 0, 0, largura, -altura },
            (Rectangle){ offsetX, offsetY, largura_escala, altura_escala },
            (Vector2){ 0, 0 },
            0.0,
            WHITE);

        EndDrawing();
    }
    return SCREEN_EXIT;
}