// Escolhas secundárias de ações do jogador, ataques, flores

#ifndef ESCOLHAS_SECUNDARIAS_H
#define ESCOLHAS_SECUNDARIAS_H

#include "personagem.h"
#include "raylib.h"

void mudar_escolha_secundaria(int *escolhido, Personagem *personagem_atual, int escolha_flores_diurnas, int escolha_flores_noturnas, int escolha_ataques, float *pode_apertar, float *delay);

void desenhar_escolhas_ataques(int *escolhido, int *inicio, Personagem *personagem_atual, int personagem_num, int largura, int altura, int *energia_sobra, char *elemento, float *velocidade, Font fonte);

void desenhar_escolhas_flores_dia(int *escolhido, int *inicio, Personagem *personagem_atual, int personagem_num, int largura, int altura, int *energia_sobra, char *elemento, float *velocidade, Font fonte);

void desenhar_escolhas_flores_noite(int *escolhido, int *inicio, Personagem *personagem_atual, int personagem_num, int largura, int altura, int *energia_sobra, char *elemento, float *velocidade, Font fonte);

#endif