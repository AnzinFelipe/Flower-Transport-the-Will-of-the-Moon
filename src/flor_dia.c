#include "flor_dia.h"
#include <stdlib.h>

void adicionar_flor_dia(Flor_dia **head, char *nome, int dano, char *elemento, int energia_gasta, float velocidade) {
    Flor_dia *novo_flor_dia = (Flor_dia *)malloc(sizeof(Flor_dia));
    novo_flor_dia->prox = NULL;
    novo_flor_dia->nome = nome;
    novo_flor_dia->dano = dano;
    novo_flor_dia->elemento = elemento;
    novo_flor_dia->energia_gasta = energia_gasta;
    novo_flor_dia->velocidade = velocidade;

    if (*head == NULL) {
        *head = novo_flor_dia;
        return;
    } else {
        Flor_dia *n = *head;
        while (n->prox != NULL) {
            n = n->prox;
        }
        n->prox = novo_flor_dia;
    }
}

void liberar_flor_dia(Flor_dia *head) {
    Flor_dia *n;
    while (head != NULL) {
        n = head;
        head = head->prox;
        free(n);
    }
}