#include "raylib.h"
#include "screens.h"
#include <math.h>

GameScreen RunMenu(void) {
    if (!IsAudioDeviceReady()) {
        InitAudioDevice();
    }
    Music menu = LoadMusicStream("assets/music/Menu.ogg");
    PlayMusicStream(menu);
    const char opcao[2][15] = {"INICIAR JOGO", "SAIR"};
    Texture2D menu1 = LoadTexture("assets/images/Menu1.png");
    GenTextureMipmaps(&menu1);
    SetTextureFilter(menu1, TEXTURE_FILTER_TRILINEAR);
    Texture2D menu2 = LoadTexture("assets/images/Menu2.png");
    GenTextureMipmaps(&menu2);
    SetTextureFilter(menu2, TEXTURE_FILTER_TRILINEAR);
    int selecao = 0;
    float pode_apertar = 0.0, delay = 0.1;
    int largura = 1600, altura = 900;
    RenderTexture2D janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(janela.texture, TEXTURE_FILTER_TRILINEAR);

    while (!WindowShouldClose()) {

        UpdateMusicStream(menu);

        pode_apertar += GetFrameTime();
        if (IsKeyPressed(KEY_UP)) selecao = !selecao;
        if (IsKeyPressed(KEY_DOWN)) selecao = !selecao;

        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
            pode_apertar = 0.0;
            UnloadMusicStream(menu);
            CloseAudioDevice();
            UnloadTexture(menu1);
            UnloadTexture(menu2); 
            return (selecao == 0) ? SCREEN_CUTSCENE : SCREEN_EXIT;
        }

        BeginTextureMode(janela);
        
        ClearBackground(PURPLE);
        for (int i = 0; i < 2; i++) {
            if (i == selecao) {
                DrawTextureEx(menu2, (Vector2){0, 0}, 0.0, 1, WHITE);
            } else {
                DrawTextureEx(menu1, (Vector2){0, 0}, 0.0, 1, WHITE);
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