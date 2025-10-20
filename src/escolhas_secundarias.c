#include "raylib.h"

void mudar_escolha_secundaria(int *escolhido, int *personagem_num, float *pode_apertar, float *delay) {
    int max_escolhido = 0;
    if (*personagem_num == 0 || *personagem_num == 1 || *personagem_num == 2) {
        max_escolhido = 2;
    } else if (*personagem_num == 3) {
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