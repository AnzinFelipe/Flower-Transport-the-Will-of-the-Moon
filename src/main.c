#include "raylib.h"
#include "personagem.h"
#include "ataque.h"
#include "flor_dia.h"
#include "flor_noite.h"
#include "escolhas_primarias.h"

#include <stdlib.h>

int main(void)
{
    int largura = 1600, altura = 900;

    InitWindow(largura, altura, "Flower Transport - the Will of the Moon");

    InitAudioDevice();
    Music pink = LoadMusicStream("assets/music/Pink.mp3");
    PlayMusicStream(pink);

    int escolhas = 1, escolha_flores_diurnas = 0, escolha_flores_noturnas = 0, escolha_ataques = 0;
    int escolhido = 0;
    int personagem_num = 0;
    int vez_inimigo = 0;
    float pode_apertar = 0.0, delay = 0.2;

    Personagem *head = NULL;
    head = (Personagem *)malloc(sizeof(Personagem));
    
    adicionar_personagem(&head, "Roxo", 100, 100, ataque, flor_dia, flor_noite);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(pink);

        pode_apertar += GetFrameTime();

        BeginDrawing();

        ClearBackground(BLACK);
        DrawRectangle(0,  altura - (altura / 3), largura / 4, altura / 3, PURPLE);
        DrawRectangle(largura / 4, altura - (altura / 3), largura / 4, altura / 3, RED);
        DrawRectangle(largura / 2, altura - (altura / 3), largura / 4, altura / 3, ORANGE);
        DrawRectangle(largura - (largura / 4), altura - (altura / 3), largura / 4, altura / 3, GREEN);

        //Vez do inimigo ou vez do jogador
        if (vez_inimigo == 1) {
            DrawText("Vez do Inimigo", largura / 2 - 100, 100, 40, WHITE);
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                vez_inimigo = 0;
                personagem_num = 0;
                escolhas = 1;
                pode_apertar = 0.0;
            }
        } else {
            DrawText("Sua Vez", largura / 2 - 100, 100, 40, WHITE);
        }

        //Escolhas primarias de cada personagem
        if (escolhas == 1 && personagem_num == 0) {
            //Personagem 0
            mudar_escolha_primaria(&escolhido, &personagem_num, &pode_apertar, &delay);
            
            desenhar_escolhas_primarias(escolhido, personagem_num, largura, altura);

            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (escolhido == 0) {
                    escolha_flores_diurnas = 1;    
                } else if (escolhido == 1) {
                    escolha_flores_noturnas = 1;
                } else if (escolhido == 2) {
                    //Defesa;
                }
                escolhas = 0;
                escolhido = 0;
                pode_apertar = 0.0;
            }
        } else if (escolhas == 1 && personagem_num == 1) {
            //Personagem 1
            mudar_escolha_primaria(&escolhido, &personagem_num, &pode_apertar, &delay);

            desenhar_escolhas_primarias(escolhido, personagem_num, largura, altura);

            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (escolhido == 0) {
                    escolha_ataques = 1;    
                } else if (escolhido == 1) {
                    escolha_flores_diurnas = 1;
                } else if (escolhido == 2) {
                    //Defesa;
                }
                escolhas = 0;
                escolhido = 0;
                pode_apertar = 0.0;
            }
        } else if (escolhas == 1 && personagem_num == 2) {
            //Personagem 2
            mudar_escolha_primaria(&escolhido, &personagem_num, &pode_apertar, &delay);

            desenhar_escolhas_primarias(escolhido, personagem_num, largura, altura);

            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (escolhido == 0) {
                    escolha_ataques = 1;    
                } else if (escolhido == 1) {
                    escolha_flores_noturnas = 1;
                } else if (escolhido == 2) {
                    //Defesa;
                }
                escolhas = 0;
                escolhido = 0;
                pode_apertar = 0.0;
            }
        } else if (escolhas == 1 && personagem_num == 3) {
            //Personagem 3
            mudar_escolha_primaria(&escolhido, &personagem_num, &pode_apertar, &delay);

            desenhar_escolhas_primarias(escolhido, personagem_num, largura, altura);

            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (escolhido == 0) {
                    escolha_ataques = 1;    
                } else if (escolhido == 1) {
                    //Defesa;
                }
                escolhas = 0;
                escolhido = 0;
                pode_apertar = 0.0;
            }
        }

        //Escolhas secundarias
        if (escolha_ataques == 1) {
            //Escolha de ataques
            DrawText(head->ataque.nome, largura / 2 - 750, altura / 2, 30, WHITE);
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (personagem_num == 3) {
                    escolha_ataques = 0;
                    vez_inimigo = 1;
                    pode_apertar = 0.0;
                } else {
                    escolha_ataques = 0;
                    escolhas = 1;
                    personagem_num++;
                    pode_apertar = 0.0;
                }
            }
        }
        if (escolha_flores_diurnas == 1) {
            //Escolha de flores diurnas
            DrawText(head->flor_dia.nome, largura / 2 - 750, altura / 2, 30, WHITE);
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (personagem_num == 3) {
                    escolha_flores_diurnas = 0;
                    vez_inimigo = 1;
                    pode_apertar = 0.0;
                } else {
                    escolha_flores_diurnas = 0;
                    escolhas = 1;
                    personagem_num++;
                    pode_apertar = 0.0;
                }
            }
        }
        if (escolha_flores_noturnas == 1) {
            //Escolha de flores noturnas
            DrawText(head->flor_noite.nome, largura / 2 - 750, altura / 2, 30, WHITE);
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (personagem_num == 3) {
                    escolha_flores_noturnas = 0;
                    vez_inimigo = 1;
                    pode_apertar = 0.0;
                } else {
                    escolha_flores_noturnas = 0;
                    escolhas = 1;
                    personagem_num++;
                    pode_apertar = 0.0;
                }
            }
        }

        EndDrawing();
    }

    UnloadMusicStream(pink);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}