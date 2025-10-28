// Flores noturnas

#ifndef FLOR_NOITE_H
#define FLOR_NOITE_H

typedef struct Flor_noite{
    char *nome;
    int dano;
    char *elemento;
    int energia_gasta;
    float velocidade;
    char *descricao;
    struct Flor_noite *prox;
} Flor_noite;

void adicionar_flor_noite(Flor_noite **head, char *nome, int dano, char *elemento, int energia_gasta, float velocidade);

void liberar_flor_noite(Flor_noite *head);

#endif