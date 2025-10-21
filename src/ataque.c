#include "ataque.h"
#include <stdlib.h>

void adicionar_ataque(Ataque **head, char *nome, int dano, char *elemento, int energia_gasta, float velocidade) {
    Ataque *novo_ataque = (Ataque *)malloc(sizeof(Ataque));
    novo_ataque->prox = NULL;
    novo_ataque->nome = nome;
    novo_ataque->dano = dano;
    novo_ataque->elemento = elemento;
    novo_ataque->energia_gasta = energia_gasta;
    novo_ataque->velocidade = velocidade;

    if (*head == NULL) {
        *head = novo_ataque;
        return;
    } else {
        Ataque *n = *head;
        while (n->prox != NULL) {
            n = n->prox;
        }
        n->prox = novo_ataque;
    }
}

void liberar_ataque(Ataque *head) {
    Ataque *n;
    while (head != NULL) {
        n = head;
        head = head->prox;
        free(n);
    }
}