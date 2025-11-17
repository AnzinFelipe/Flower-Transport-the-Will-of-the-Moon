#include "raylib.h"
#include "screens.h"
#include <stdlib.h>

Images* CriarCutsceneImages(void)
{
    Images* listaImagens = NULL;
    Images* atual = NULL;
    
    for (int i = 1; i <= 10; i++)
    {
        Images* novaImagem = malloc(sizeof(Images));
        
        if (i == 1) novaImagem->imagem = LoadTexture("assets/images/inicio/1.png");
        else if (i == 2) novaImagem->imagem = LoadTexture("assets/images/inicio/2.png");
        else if (i == 3) novaImagem->imagem = LoadTexture("assets/images/inicio/3.png");
        else if (i == 4) novaImagem->imagem = LoadTexture("assets/images/inicio/4.png");
        else if (i == 5) novaImagem->imagem = LoadTexture("assets/images/inicio/5.png");
        else if (i == 6) novaImagem->imagem = LoadTexture("assets/images/inicio/6.png");
        else if (i == 7) novaImagem->imagem = LoadTexture("assets/images/inicio/7.png");
        else if (i == 8) novaImagem->imagem = LoadTexture("assets/images/inicio/8.png");
        else if (i == 9) novaImagem->imagem = LoadTexture("assets/images/inicio/9.png");
        else if (i == 10) novaImagem->imagem = LoadTexture("assets/images/inicio/10.png");
        
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

void LiberarImagens(Images* listaImagens)
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

GameScreen RunCutscene(void)
{
    Images* listaImagens = CriarCutsceneImages();
    Images* imagemAtual = listaImagens;
    int cont = 1;
    float temporizador = 0.0;
    
    while (!WindowShouldClose())
    {
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
                LiberarImagens(listaImagens);

                BeginDrawing();
                ClearBackground(BLACK);
                EndDrawing();

                return SCREEN_GAME;
            }
        }
        
        BeginDrawing();
        ClearBackground(BLACK);
        
        DrawTexture(
            imagemAtual->imagem,
            (GetScreenWidth() - imagemAtual->imagem.width) / 2,
            (GetScreenHeight() - imagemAtual->imagem.height) / 2,
            WHITE
        );
        
        DrawText(TextFormat("%d/10", cont), 10, 10, 20, WHITE);
        
        EndDrawing();
    }
    
    LiberarImagens(listaImagens);
    return SCREEN_EXIT;
}