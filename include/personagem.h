// Personagens

#define PERSONAGEM_H
#ifdef PERSONAGEM_H

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
    struct Personagem *prox;
} Personagem;

void adicionar_personagem(Personagem **head, char *nome, int vida, int energia, Ataque *ataque, Flor_dia *flor_dia, Flor_noite *flor_noite);

void liberar_personagem(Personagem *head);

Personagem * pegar_personagem(int personagem_num, Personagem *personagem_atual, Personagem *head);

#endif