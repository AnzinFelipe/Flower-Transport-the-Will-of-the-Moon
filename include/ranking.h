#ifndef RANKS_H
#define RANKS_H

#include "raylib.h"

typedef struct Ranks {
    int posicao;
    int total_pontos;
    struct Ranks *next;
} Ranks;

void nova_pontuacao_ranking(Ranks **head, int nova_pontuacao);
#endif