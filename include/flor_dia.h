// Flores diurnas

#ifndef FLOR_DIA_H
#define FLOR_DIA_H

typedef struct Flor_dia{
    char *nome;
    int dano;
    char *elemento;
    int energia_gasta;
    float velocidade;
    char *descricao;
    struct Flor_dia *prox;
} Flor_dia;

void adicionar_flor_dia(Flor_dia **head, char *nome, int dano, char *elemento, int energia_gasta, float velocidade);

void liberar_flor_dia(Flor_dia *head);

#endif