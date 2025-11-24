#include "raylib.h"
#include "screens.h"
#include <stdlib.h>
#include <math.h>

GameScreen RunGameOver(void){
    if (!IsAudioDeviceReady()) {
        InitAudioDevice();
    }
    Music gameover_musica = LoadMusicStream("assets/music/Gameover.mp3");
    PlayMusicStream(gameover_musica);
    const char opcao[2][16] = {"TENTAR DE NOVO!", "SUCUMBIR..."};
    Font fonte = LoadFontEx("assets/fonts/EmilysCandy-Regular.ttf", 40, NULL, 252);
    int selecao = 0;
    Texture2D gameover = LoadTexture("assets/images/Gameover.png");
    GenTextureMipmaps(&gameover);
    SetTextureFilter(gameover, TEXTURE_FILTER_TRILINEAR);
    float pode_apertar = 0.0, delay = 0.1;
    int largura = 1600, altura = 900;
    RenderTexture2D janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(janela.texture, TEXTURE_FILTER_TRILINEAR);

    while (!WindowShouldClose()) {

        UpdateMusicStream(gameover_musica);

        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_RIGHT)) selecao = !selecao;
        if (IsKeyPressed(KEY_LEFT)) selecao = !selecao;

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
            pode_apertar = 0.0;
            UnloadMusicStream(gameover_musica);
            CloseAudioDevice();
            UnloadFont(fonte);
            UnloadTexture(gameover);
            return (selecao == 0) ? SCREEN_GAME : SCREEN_MENU;
        }
        
        BeginTextureMode(janela);
        
        ClearBackground(PURPLE);
        DrawTextureEx(gameover, (Vector2){0,0}, 0.0, 1, WHITE);

        DrawTextEx(fonte, "Todos foram nocauteados.", (Vector2){550, 150}, 50, 2, RED);
        DrawTextEx(fonte, "Mas, você ainda pode fazer uma escolha.", (Vector2){475, 220}, 40, 2, GRAY);

        for (int i = 0; i < 2; i++) {
            if (i == selecao) {
                DrawTextEx(fonte, opcao[i], (Vector2){300 + i * 700, 300}, 40, 2, (Color){255, 0, 144, 255});
            } else {
                DrawTextEx(fonte, opcao[i], (Vector2){300 + i * 700, 300}, 35, 2, WHITE);
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