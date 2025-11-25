#ifndef RANKS_H
#define RANKS_H

#include "raylib.h"

typedef struct Ranks {
    int posicao;
    int total_pontos;
} Ranks;

void nova_pontuacao_ranking(int nova_pontuacao);
#endif