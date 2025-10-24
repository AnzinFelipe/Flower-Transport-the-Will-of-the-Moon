#include "escolhas_primarias.h"
#include "raylib.h"

void mudar_escolha_primaria(int *escolhido, int personagem_num, float *pode_apertar, float *delay) {
    int max_escolhido = 0;
    if (personagem_num == 0 || personagem_num == 1 || personagem_num == 2) {
        max_escolhido = 2;
    } else if (personagem_num == 3) {
        max_escolhido = 1;
    }
    
    if (IsKeyPressed(KEY_DOWN) && *pode_apertar >= *delay) {
        (*escolhido)++;
        *pode_apertar = 0.0;
        if(*escolhido > max_escolhido) {
            *escolhido = 0;
        }
    }
    if (IsKeyPressed(KEY_UP) && *pode_apertar >= *delay) {
        (*escolhido)--;
        *pode_apertar = 0.0;
        if(*escolhido < 0) {
            *escolhido = max_escolhido;
        }
    }
}

void desenhar_escolhas_primarias(int escolhido, int personagem_num, int largura, int altura, int horario) {
    Color nao_pode = {100, 50, 50, 255};
    Color nao_pode_escolhido = {200, 50, 50, 255};
    int largura1 = largura - (largura - 50);
    int altura_geral = altura / 2;
    int largura2 = largura1 + largura / 4;
    int largura3 = largura2 + largura / 4;
    int largura4 = largura3 + largura / 4;
    
    if (personagem_num == 0) {
        if (horario == 0) {
            if (escolhido == 0) {
                DrawText("Flores Diurnas", largura1, altura_geral, 30, WHITE);
            } else {
                DrawText("Flores Diurnas", largura1, altura_geral, 30, GRAY);
            }
            if (escolhido == 1) {
                DrawText("Flores Noturnas", largura1, altura_geral + 50, 30, nao_pode_escolhido);
            } else {
                DrawText("Flores Noturnas", largura1, altura_geral + 50, 30, nao_pode);
            }
        } else if (horario == 1) {
            if (escolhido == 0) {
                DrawText("Flores Diurnas", largura1, altura_geral, 30, nao_pode_escolhido);
            } else {
                DrawText("Flores Diurnas", largura1, altura_geral, 30, nao_pode);
            }
            if (escolhido == 1) {
                DrawText("Flores Noturnas", largura1, altura_geral + 50, 30, WHITE);
            } else {
                DrawText("Flores Noturnas", largura1, altura_geral + 50, 30, GRAY);
            }
        }
        if (escolhido == 2){
            DrawText("Defender", largura1, altura_geral + 100, 30, WHITE);
        } else {
            DrawText("Defender", largura1, altura_geral + 100, 30, GRAY);
        }
    } else if (personagem_num == 1) {
       if (escolhido == 0) {
            DrawText("Ataques", largura2, altura_geral, 30, WHITE);
        } else {
            DrawText("Ataques", largura2, altura_geral, 30, GRAY);
        }
        if (horario == 0) {
            if (escolhido == 1) {
                DrawText("Flores Diurnas", largura2, altura_geral + 50, 30, WHITE);
            } else {
                DrawText("Flores Diurnas", largura2, altura_geral + 50, 30, GRAY);
            }
        } else if (horario == 1) { 
            if (escolhido == 1) {
                DrawText("Flores Diurnas", largura2, altura_geral + 50, 30, nao_pode_escolhido);
            } else {
                DrawText("Flores Diurnas", largura2, altura_geral + 50, 30, nao_pode);
            }
        }
        if (escolhido == 2){
            DrawText("Defender", largura2, altura_geral + 100, 30, WHITE);
        } else {
            DrawText("Defender", largura2, altura_geral + 100, 30, GRAY);
        } 
    } else if (personagem_num == 2) {
        if (escolhido == 0) {
            DrawText("Ataques", largura3, altura_geral, 30, WHITE);
        } else {
            DrawText("Ataques", largura3, altura_geral, 30, GRAY);
        }
        if (horario == 0) {
            if (escolhido == 1) {
                DrawText("Flores Noturnas", largura3, altura_geral + 50, 30, nao_pode_escolhido);
            } else {
                DrawText("Flores Noturnas", largura3, altura_geral + 50, 30, nao_pode);
            }
        } else if (horario == 1) {
            if (escolhido == 1) {
                DrawText("Flores Noturnas", largura3, altura_geral + 50, 30, WHITE);
            } else {
                DrawText("Flores Noturnas", largura3, altura_geral + 50, 30, GRAY);
            }
        }
        if (escolhido == 2){
            DrawText("Defender", largura3, altura_geral + 100, 30, WHITE);
        } else {
            DrawText("Defender", largura3, altura_geral + 100, 30, GRAY);
        }
    } else if (personagem_num == 3) {
        if (escolhido == 0) {
            DrawText("Ataques", largura4, altura_geral + 25, 30, WHITE);
        } else {
            DrawText("Ataques", largura4, altura_geral + 25, 30, GRAY);
        }
        if (escolhido == 1){
            DrawText("Defender", largura4, altura_geral + 75, 30, WHITE);
        } else {
            DrawText("Defender", largura4, altura_geral + 75, 30, GRAY);
        }
    }
}