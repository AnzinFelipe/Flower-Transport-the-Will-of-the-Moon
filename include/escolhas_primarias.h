// Escolhas primárias de ações do jogador

#ifndef ESCOLHAS_PRIMARIAS_H
#define ESCOLHAS_PRIMARIAS_H

#include "raylib.h"

void mudar_escolha_primaria(int *escolhido, int personagem_num, float *pode_apertar, float *delay);

void desenhar_escolhas_primarias(int escolhido, int personagem_num, int largura, int altura, int horario, Font fonte);

#endif