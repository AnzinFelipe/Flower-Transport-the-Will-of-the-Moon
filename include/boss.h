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

void desenhar_vida_boss(Boss *boss, int largura, Color vida, Font fonte);

void desenhar_coracao(Texture2D coracao, float largura);

void desenhar_olho(Texture2D olho1, Texture2D olho2, Texture2D olho3, float *olho_animado, float olho_delay);

void subtrair_vida_boss(Boss **boss, int dano, float mult);

void pegar_personagem_aleatorio(Personagem *personagem, int *random_p);

void ataque_boss(Boss *boss, Personagem **personagem, int random_p, int *p0_morto, int *p1_morto, int *p2_morto, int *p3_morto, int *sobreviventes);

#endif