// Escolhas secundárias de ações do jogador, ataques, flores

#ifndef ESCOLHAS_SECUNDARIAS_H
#define ESCOLHAS_SECUNDARIAS_H

void mudar_escolha_secundaria(int *escolhido, int *personagem_num, float *pode_apertar, float *delay);

void desenhar_escolhas_ataques(int *escolhido, int *personagem_num, int largura, int altura);

void desenhar_escolhas_flores_dia(int *escolhido, int *personagem_num, int largura, int altura);

void desenhar_escolhas_flores_noite(int *escolhido, int *personagem_num, int largura, int altura);

#endif