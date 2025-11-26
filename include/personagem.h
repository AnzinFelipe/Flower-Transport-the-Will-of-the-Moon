// Personagens

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "ataque.h"
#include "flor_dia.h"
#include "flor_noite.h"
#include "raylib.h"

typedef struct Personagem{
    char *nome;
    int vida;
    int energia;
    Ataque *ataque;
    Flor_dia *flor_dia;
    Flor_noite *flor_noite;
    int defesa;
    char *vantagens_desvantagens[6][3];
    struct Personagem *prox;
} Personagem;

void adicionar_personagem(Personagem **head, char *nome, int vida, int energia, Ataque *ataque, Flor_dia *flor_dia, Flor_noite *flor_noite);

void liberar_personagem(Personagem *head);

void pegar_personagem(int personagem_num, Personagem **personagem_atual, Personagem *head);

void adicionar_vantagens_desvantagens_personagem(Personagem **head, int num);

void desenhar_personagem(Personagem *personagem, int personagem_num, int vida_max, Texture2D vida_cheia, Texture2D pouca_vida, Texture2D derrotado);

void desenhar_vida_personagens(Personagem *personagem, int num, Color vida);

void desenhar_energia_personagens(Personagem *personagem, int num, Color energia);

void subtrair_vida_personagem(Personagem **personagem, int personagem_num, int dano, float mult, int *p0_morto, int *p1_morto, int *p2_morto, int *p3_morto, int *sobreviventes);

void subtrair_energia_personagem(Personagem **personagem_atual, int energia_gasta);

#endif