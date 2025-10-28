// Ataques

#ifndef ATAQUE_H
#define ATAQUE_H

typedef struct Ataque{
    char *nome;
    int dano;
    char *elemento;
    int energia_gasta;
    float velocidade;
    char *descricao;
    struct Ataque *prox;
} Ataque;

void adicionar_ataque(Ataque **head, char *nome, int dano, char *elemento, int energia_gasta, float velocidade, char *descricao);

void liberar_ataque(Ataque *head);

#endif