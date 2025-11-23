#include "raylib.h"
#include "screens.h"
#include <math.h>

GameScreen RunGameWin(void)
{
    if (!IsAudioDeviceReady()) {
        InitAudioDevice();
    }
    Music menu = LoadMusicStream("assets/music/Menu.mp3");
    PlayMusicStream(menu);

    const char opcao[2][16] = {"JOGAR NOVAMENTE", "MENU PRINCIPAL"};
    int selecao = 0;
    
    Texture2D gamewin = LoadTexture("assets/images/Gamewin.png");
    SetTextureFilter(gamewin, TEXTURE_FILTER_TRILINEAR);
    

    float pode_apertar = 0.0, delay = 0.1;

    int largura = 1600, altura = 900;
    RenderTexture2D janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(janela.texture, TEXTURE_FILTER_TRILINEAR);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(menu);

        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_RIGHT)) selecao = !selecao;
        if (IsKeyPressed(KEY_LEFT)) selecao = !selecao;

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay)
        {
            pode_apertar = 0.0;
            UnloadMusicStream(menu);
            CloseAudioDevice();
            UnloadTexture(gamewin);
            return (selecao == 0) ? SCREEN_GAME : SCREEN_MENU;
        }

        BeginTextureMode(janela);

        ClearBackground(BLACK);
        DrawTexture(gamewin, 0, 0, WHITE);

        DrawText("Vitória!", 650, 50, 80, (Color){152, 35, 35, 255});
        DrawText("Parabéns! Você venceu o jogo.", 500, 150, 40, WHITE);

        for (int i = 0; i < 2; i++)
        {
            if (i == selecao)
            {
                DrawText(opcao[i], 250 + i * 700, 300, 40, (Color){152, 35, 35, 255});
            }
            else
            {
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