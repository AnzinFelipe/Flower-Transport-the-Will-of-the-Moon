// Boss

#ifndef BOSS_H
#define BOSS_H

#include "ataque.h"
#include "personagem.h"
#include <stdlib.h>
#include "raylib.h"

typedef struct Boss {
    char *nome;
    int vida;
    Ataque *ataque;
    char *vantagens_desvantagens[4][3];
} Boss;

void adicionar_vantagens_desvantagens_boss(Boss **boss);

void adicionar_boss (Boss **boss, Ataque *ataque);

void desenhar_vida_boss(Boss *boss, int largura, Color vida);

void desenhar_coracao(Texture2D coracao, float largura);

void subtrair_vida_boss(Boss **boss, int dano, float mult);

void ataque_boss(Boss *boss, Personagem **personagem, int *p0_morto, int *p1_morto, int *p2_morto, int *p3_morto);

#endif