#include "raylib.h"
#include "../include/personagem.h"

int * selecionar_escolha(int *escolhido, int max_escolhido);

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
    Personagem roxo;
    roxo.vida = 100;
    roxo.energia = 100;
    roxo.flor_dia.nome = "Flor Solar";
    roxo.flor_noite.nome = "Flor Lunar";
    roxo.ataque.nome = "Chute";

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateMusicStream(pink);

        pode_apertar += GetFrameTime();

        BeginDrawing();

        ClearBackground(BLACK);
        DrawRectangle(0, 600, largura / 4, 300, PURPLE);
        DrawRectangle(largura / 4, 600, largura / 4, 300, RED);
        DrawRectangle(largura / 2, 600, largura / 4, 300, ORANGE);
        DrawRectangle(largura - (largura / 4), 600, largura / 4, 300, GREEN);

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
            escolhido = selecionar_escolha(&escolhido, 2);
            
            if (escolhido == 0) {
                DrawText("Flores Diurnas", largura / 2 - 750, altura / 2, 30, WHITE);
            } else {
                DrawText("Flores Diurnas", largura / 2 - 750, altura / 2, 30, GRAY);
            }
            if (escolhido == 1) {
                DrawText("Flores Noturnas", largura / 2 - 750, altura / 2 + 50, 30, WHITE);
            } else {
                DrawText("Flores Noturnas", largura / 2 - 750, altura / 2 + 50, 30, GRAY);
            }
            if (escolhido == 2){
                DrawText("Defender", largura / 2 - 750, altura / 2 + 100, 30, WHITE);
            } else {
                DrawText("Defender", largura / 2 - 750, altura / 2 + 100, 30, GRAY);
            }

            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (escolhido == 0) {
                    escolha_flores_diurnas = 1;    
                } elif (escolhido == 1) {
                    escolha_flores_noturnas = 1;
                } elif (escolhido == 2) {
                    //Defesa;
                }
                escolhas = 0;
                pode_apertar = 0.0;
            }
        } else if (escolhas == 1 && personagem_num == 1) {
            //Personagem 1
            escolhido = selecionar_escolha(&escolhido, 2);

            if (escolhido == 0) {
                DrawText("Ataques", largura / 2 - 350, altura / 2, 30, WHITE);
            } else {
                DrawText("Ataques", largura / 2 - 350, altura / 2, 30, GRAY);
            }
            if (escolhido == 1) {
                DrawText("Flores Diurnas", largura / 2 - 350, altura / 2 + 50, 30, WHITE);
            } else {
                DrawText("Flores Diurnas", largura / 2 - 350, altura / 2 + 50, 30, GRAY);
            }
            if (escolhido == 2){
                DrawText("Defender", largura / 2 - 350, altura / 2 + 100, 30, WHITE);
            } else {
                DrawText("Defender", largura / 2 - 350, altura / 2 + 100, 30, GRAY);
            }

            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (escolhido == 0) {
                    escolha_ataques = 1;    
                } elif (escolhido == 1) {
                    escolha_flores_diurnas = 1;
                } elif (escolhido == 2) {
                    //Defesa;
                }
                escolhas = 0;
                pode_apertar = 0.0;
            }
        } else if (escolhas == 1 && personagem_num == 2) {
            //Personagem 2
            escolhido = selecionar_escolha(&escolhido, 2);

            if (escolhido == 0) {
                DrawText("Ataques", largura / 2 + 50, altura / 2, 30, WHITE);
            } else {
                DrawText("Ataques", largura / 2 + 50, altura / 2, 30, GRAY);
            }
            if (escolhido == 1) {
                DrawText("Flores Noturnas", largura / 2 + 50, altura / 2 + 50, 30, WHITE);
            } else {
                DrawText("Flores Noturnas", largura / 2 + 50, altura / 2 + 50, 30, GRAY);
            }
            if (escolhido == 2){
                DrawText("Defender", largura / 2 + 50, altura / 2 + 100, 30, WHITE);
            } else {
                DrawText("Defender", largura / 2 + 50, altura / 2 + 100, 30, GRAY);
            }

            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (escolhido == 0) {
                    escolha_ataques = 1;    
                } elif (escolhido == 1) {
                    escolha_flores_noturnas = 1;
                } elif (escolhido == 2) {
                    //Defesa;
                }
                escolhas = 0;
                pode_apertar = 0.0;
            }
        } else if (escolhas == 1 && personagem_num == 3) {
            //Personagem 3
            escolhido = selecionar_escolha(&escolhido, 1);

            if (escolhido == 0) {
                DrawText("Ataques", largura / 2 + 450, altura / 2 + 25, 30, WHITE);
            } else {
                DrawText("Ataques", largura / 2 + 450, altura / 2 + 25, 30, GRAY);
            }
            if (escolhido == 1){
                DrawText("Defender", largura / 2 + 450, altura / 2 + 75, 30, WHITE);
            } else {
                DrawText("Defender", largura / 2 + 450, altura / 2 + 75, 30, GRAY);
            }

            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                if (escolhido == 0) {
                    escolha_ataques = 1;    
                } elif (escolhido == 1) {
                    //Defesa;
                }
                escolhas = 0;
                pode_apertar = 0.0;
            }
        }

        //Escolhas secundarias
        if (escolha_ataques == 1) {
            //Escolha de ataques
            DrawText(roxo.ataque.nome, largura / 2 - 750, altura / 2, 30, WHITE);
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
            DrawText(roxo.flor_dia.nome, largura / 2 - 750, altura / 2, 30, WHITE);
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
            DrawText(roxo.flor_noite.nome, largura / 2 - 750, altura / 2, 30, WHITE);
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

int * selecionar_escolha(int *escolhido, int max_escolhido) {
    if (IsKeyPressed(KEY_DOWN) && pode_apertar >= delay) {
        *escolhido++;
        pode_apertar = 0.0;
        if(*escolhido > max_escolhido) {
            *escolhido = 0;
        }
    }
    if (IsKeyPressed(KEY_UP) && pode_apertar >= delay) {
        *escolhido--;
        pode_apertar = 0.0;
        if(*escolhido < max_escolhido) {
            *escolhido = 2;
        }
    }
    return *escolhido;
}