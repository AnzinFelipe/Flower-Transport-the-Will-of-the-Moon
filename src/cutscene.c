#include "raylib.h"
#include "screens.h"
#include <stdlib.h>
#include <math.h>

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
    Font fonte = LoadFontEx("assets/fonts/EmilysCandy-Regular.ttf", 40, NULL, 252);
    int cont = 1;
    float temporizador = 0.0;
    int largura = 1600, altura = 900;
    RenderTexture2D janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(janela.texture, TEXTURE_FILTER_TRILINEAR);
    
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

        BeginTextureMode(janela);

        ClearBackground(BLACK);
        
        DrawTexture(imagemAtual->imagem, 0, 0, WHITE);
        
        DrawText(TextFormat("%d/10", cont), 10, 10, 20, WHITE);

        if (cont == 1) {
            DrawTextEx(fonte, "Após nossos transportadores\npassarem pelos Lagos Gelados\nao Norte da floresta espinhenta,\neles se encontram pensando\nem seus próximos passos.", (Vector2){800, 300}, 40, 2, BLACK); 
        } else if (cont == 2) {
            DrawTextEx(fonte, "Narciso", (Vector2){585, 370}, 40, 2, (Color){120, 0, 120, 255});
            DrawTextEx(fonte, "Conferindo o mapa,\nprecisamos andar mais\nalguns quilômetros para\no Sul até chegarmos\nà próxima ilha.", (Vector2){1200, 50}, 40, 2, BLACK);
        } else if (cont == 3) {
            DrawTextEx(fonte, "Roderick", (Vector2){220, 120}, 40, 2, (Color){120, 0, 0, 255});
            DrawTextEx(fonte, "Precisamos decidir se vamos descansar\nagora ou continuaremos andando.\nSó temos provisões para mais 3 dias,\no quanto antes chegarmos à próxima\ncidade, melhor.", (Vector2){850, 50}, 40, 2, BLACK);
        } else if (cont == 4) {
            DrawTextEx(fonte, "Edoras", (Vector2){1200, 250}, 40, 2, (Color){200, 60, 0, 255});
            DrawTextEx(fonte, "Vamos seguir em frente logo! Eu consigo\nver um caminho sem muitos espinhos ali\nmais pra frente, não vai ser tão difícil\nandar por ele. A gente precisa se distanciar\no máximo daquele caçador, o Lu já fez\no favor de nos atrasar demais.", (Vector2){50, 50}, 40, 2, BLACK);
        } else if (cont == 5) {
            DrawTextEx(fonte, "Lumennyl", (Vector2){725, 275}, 40, 2, (Color){152, 35, 107, 255});
            DrawTextEx(fonte, "Eu sei que todos\nvocês estão cansados.\nE eu não atrasei a gente\n                coisa nenhuma.", (Vector2){630, 550}, 40, 2, BLACK);
            DrawTextEx(fonte, "Aham.", (Vector2){1000, 750}, 40, 2, BLACK);
        } else if (cont == 6) {
            DrawTextEx(fonte, "Então tu quer que a gente acampe aqui?\nCom aquele cadáver decapitado todo estranho\nolhando pra gente? Ótima ideia viu, talvez\neu consiga dormir se aquilo não me der\nnenhum pesadelo.", (Vector2){75, 100}, 40, 2, BLACK);
        } else if (cont == 10) {
            DrawTextEx(fonte, "Kalma, a vontade do Lua", (Vector2){1050, 150}, 40, 2, (Color){152, 35, 35, 255});
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
    
    LiberarImagens(listaImagens);
    return SCREEN_EXIT;
}