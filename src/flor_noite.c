#include "flor_noite.h"
#include <stdlib.h>

void adicionar_flor_noite(Flor_noite **head, char *nome, int dano, char *elemento, int energia_gasta, float velocidade, char *descricao) {
    Flor_noite *novo_flor_noite = (Flor_noite *)malloc(sizeof(Flor_noite));
    novo_flor_noite->prox = NULL;
    novo_flor_noite->nome = nome;
    novo_flor_noite->dano = dano;
    novo_flor_noite->elemento = elemento;
    novo_flor_noite->energia_gasta = energia_gasta;
    novo_flor_noite->descricao = descricao;
    novo_flor_noite->velocidade = velocidade;

    if (*head == NULL) {
        *head = novo_flor_noite;
        return;
    } else {
        Flor_noite *n = *head;
        while (n->prox != NULL) {
            n = n->prox;
        }
        n->prox = novo_flor_noite;
    }
}

void liberar_flor_noite(Flor_noite *head) {
    Flor_noite *n;
    while (head != NULL) {
        n = head;
        head = head->prox;
        free(n);
    }
}