// Personagens

#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include "ataque.h"
#include "flor_dia.h"
#include "flor_noite.h"

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

void subtrair_energia_personagem(Personagem **personagem_atual, int energia_gasta);

#endif