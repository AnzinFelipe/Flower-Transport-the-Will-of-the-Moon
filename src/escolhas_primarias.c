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

void desenhar_escolhas_primarias(int escolhido, int personagem_num, int largura, int altura, int horario, Font fonte) {
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
                DrawTextEx(fonte, "Flores Diurnas", (Vector2){largura1, altura_geral}, 40, 2, WHITE);
            } else {
                DrawTextEx(fonte, "Flores Diurnas", (Vector2){largura1, altura_geral}, 40, 2, GRAY);
            }
            if (escolhido == 1) {
                DrawTextEx(fonte, "Flores Noturnas", (Vector2){largura1, altura_geral + 50}, 40, 2, nao_pode_escolhido);
            } else {
                DrawTextEx(fonte, "Flores Noturnas", (Vector2){largura1, altura_geral + 50}, 40, 2, nao_pode);
            }
        } else if (horario == 1) {
            if (escolhido == 0) {
                DrawTextEx(fonte, "Flores Diurnas", (Vector2){largura1, altura_geral}, 40, 2, nao_pode_escolhido);
            } else {
                DrawTextEx(fonte, "Flores Diurnas", (Vector2){largura1, altura_geral}, 40, 2, nao_pode);
            }
            if (escolhido == 1) {
                DrawTextEx(fonte, "Flores Noturnas", (Vector2){largura1, altura_geral + 50}, 40, 2, WHITE);
            } else {
                DrawTextEx(fonte, "Flores Noturnas", (Vector2){largura1, altura_geral + 50}, 40, 2, GRAY);
            }
        }
        if (escolhido == 2){
            DrawTextEx(fonte, "Defender", (Vector2){largura1, altura_geral + 100}, 40, 2, WHITE);
        } else {
            DrawTextEx(fonte, "Defender", (Vector2){largura1, altura_geral + 100}, 40, 2, GRAY);
        }
    } else if (personagem_num == 1) {
       if (escolhido == 0) {
            DrawTextEx(fonte, "Ataques", (Vector2){largura2, altura_geral}, 40, 2, WHITE);
        } else {
            DrawTextEx(fonte, "Ataques", (Vector2){largura2, altura_geral}, 40, 2, GRAY);
        }
        if (horario == 0) {
            if (escolhido == 1) {
                DrawTextEx(fonte, "Flores Diurnas", (Vector2){largura2, altura_geral + 50}, 40, 2, WHITE);
            } else {
                DrawTextEx(fonte, "Flores Diurnas", (Vector2){largura2, altura_geral + 50}, 40, 2, GRAY);
            }
        } else if (horario == 1) { 
            if (escolhido == 1) {
                DrawTextEx(fonte, "Flores Diurnas", (Vector2){largura2, altura_geral + 50}, 40, 2, nao_pode_escolhido);
            } else {
                DrawTextEx(fonte, "Flores Diurnas", (Vector2){largura2, altura_geral + 50}, 40, 2, nao_pode);
            }
        }
        if (escolhido == 2){
            DrawTextEx(fonte, "Defender", (Vector2){largura2, altura_geral + 100}, 40, 2, WHITE);
        } else {
            DrawTextEx(fonte, "Defender", (Vector2){largura2, altura_geral + 100}, 40, 2, GRAY);
        } 
    } else if (personagem_num == 2) {
        if (escolhido == 0) {
            DrawTextEx(fonte, "Ataques", (Vector2){largura3, altura_geral}, 40, 2, WHITE);
        } else {
            DrawTextEx(fonte, "Ataques", (Vector2){largura3, altura_geral}, 40, 2, GRAY);
        }
        if (horario == 0) {
            if (escolhido == 1) {
                DrawTextEx(fonte, "Flores Noturnas", (Vector2){largura3, altura_geral + 50}, 40, 2, nao_pode_escolhido);
            } else {
                DrawTextEx(fonte, "Flores Noturnas", (Vector2){largura3, altura_geral + 50}, 40, 2, nao_pode);
            }
        } else if (horario == 1) {
            if (escolhido == 1) {
                DrawTextEx(fonte, "Flores Noturnas", (Vector2){largura3, altura_geral + 50}, 40, 2, WHITE);
            } else {
                DrawTextEx(fonte, "Flores Noturnas", (Vector2){largura3, altura_geral + 50}, 40, 2, GRAY);
            }
        }
        if (escolhido == 2){
            DrawTextEx(fonte, "Defender", (Vector2){largura3, altura_geral + 100}, 40, 2, WHITE);
        } else {
            DrawTextEx(fonte, "Defender", (Vector2){largura3, altura_geral + 100}, 40, 2, GRAY);
        }
    } else if (personagem_num == 3) {
        if (escolhido == 0) {
            DrawTextEx(fonte, "Ataques", (Vector2){largura4, altura_geral + 25}, 40, 2, WHITE);
        } else {
            DrawTextEx(fonte, "Ataques", (Vector2){largura4, altura_geral + 25}, 40, 2, GRAY);
        }
        if (escolhido == 1){
            DrawTextEx(fonte, "Defender", (Vector2){largura4, altura_geral + 75}, 40, 2, WHITE);
        } else {
            DrawTextEx(fonte, "Defender", (Vector2){largura4, altura_geral + 75}, 40, 2, GRAY);
        }
    }
}