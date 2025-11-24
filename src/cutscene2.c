#include "raylib.h"
#include "screens.h"
#include <stdlib.h>
#include <math.h>

Images* CriarCutsceneImages2(void)
{
    Images* listaImagens = NULL;
    Images* atual = NULL;
    
    
    for (int i = 1; i <= 4; i++)
    {
        Images* novaImagem = malloc(sizeof(Images));
        
        if (i == 1) novaImagem->imagem = LoadTexture("assets/images/final/1.png");
        else if (i == 2) novaImagem->imagem = LoadTexture("assets/images/final/2.png");
        else if (i == 3) novaImagem->imagem = LoadTexture("assets/images/final/3.png");
        else if (i == 4) novaImagem->imagem = LoadTexture("assets/images/final/4.png");
        
        GenTextureMipmaps(&novaImagem->imagem);
        SetTextureFilter(novaImagem->imagem, TEXTURE_FILTER_TRILINEAR);
        novaImagem->next = NULL;
        
        if (!listaImagens) 
            listaImagens = novaImagem;
        else 
            atual->next = novaImagem;
        
        atual = novaImagem;
    }
    
    return listaImagens;
}

void LiberarImagens2(Images* listaImagens)
{
    Images* atual = listaImagens;
    while (atual != NULL)
    {
        Images* proximo = atual->next;
        UnloadTexture(atual->imagem);
        free(atual);
        atual = proximo;
    }
}

GameScreen RunCutscene2(void)
{
    if (!IsAudioDeviceReady()) {
        InitAudioDevice();
    }
    Music inicio = LoadMusicStream("assets/music/Inicio.mp3");
    PlayMusicStream(inicio);
    Images* listaImagens = CriarCutsceneImages2();
    Images* imagemAtual = listaImagens;
    Font fonte = LoadFontEx("assets/fonts/EmilysCandy-Regular.ttf", 40, NULL, 252);
    int cont = 1;
    float temporizador = 0.0;
    int largura = 1600, altura = 900;
    RenderTexture2D janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(janela.texture, TEXTURE_FILTER_TRILINEAR);
    
    while (!WindowShouldClose())
    {

        UpdateMusicStream(inicio);

        temporizador += GetFrameTime();
        
        if (IsKeyPressed(KEY_Z) && temporizador >= 0.1)
        {
            if (imagemAtual->next)
            {
                imagemAtual = imagemAtual->next;
                cont++;                           
                temporizador = 0.0;
            }
            else
            {
                LiberarImagens2(listaImagens);
                UnloadMusicStream(inicio);
                CloseAudioDevice();
                UnloadFont(fonte);
                BeginDrawing();
                ClearBackground(BLACK);
                EndDrawing();

                return SCREEN_WIN;
            }
        }

        BeginTextureMode(janela);

        ClearBackground(BLACK);
        
        DrawTexture(imagemAtual->imagem, 0, 0, WHITE);
        
        DrawText(TextFormat("%d/4", cont), 10, 10, 20, WHITE);

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
    
    LiberarImagens2(listaImagens);
    return SCREEN_EXIT;
}