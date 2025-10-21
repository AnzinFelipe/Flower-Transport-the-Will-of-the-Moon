#include "raylib.h"
#include "personagem.h"
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

    Ataque *ataque_head = NULL;
    adicionar_ataque(&ataque_head, "Investida Floral", 30, "Corte", 20, 1.5);

    Flor_dia *flor_dia_head = NULL;
    adicionar_flor_dia(&flor_dia_head, "Raio Solar", 25, "Fogo", 15, 2.0);

    Flor_noite *flor_noite_head = NULL;
    adicionar_flor_noite(&flor_noite_head, "Sombra Lunar", 20, "Trevas", 10, 2.5);

    Personagem *personagem_head = NULL;
    adicionar_personagem(&personagem_head, "Roxo", 100, 100, ataque_head, flor_dia_head, flor_noite_head);

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
            DrawText(personagem_head->ataque->nome, largura / 2 - 750, altura / 2, 30, WHITE);
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
            DrawText(personagem_head->flor_dia->nome, largura / 2 - 750, altura / 2, 30, WHITE);
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
            DrawText(personagem_head->flor_noite->nome, largura / 2 - 750, altura / 2, 30, WHITE);
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

    liberar_ataque(ataque_head);
    liberar_flor_dia(flor_dia_head);
    liberar_flor_noite(flor_noite_head);
    liberar_personagem(personagem_head);

    UnloadMusicStream(pink);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}