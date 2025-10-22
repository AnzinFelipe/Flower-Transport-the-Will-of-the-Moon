#include "personagem.h"
#include "ataque.h"
#include "flor_dia.h"
#include "flor_noite.h"
#include <stdlib.h>

void adicionar_personagem(Personagem **head, char *nome, int vida, int energia, Ataque *ataque, Flor_dia *flor_dia, Flor_noite *flor_noite) {
    Personagem *novo_personagem = (Personagem *)malloc(sizeof(Personagem));
    novo_personagem->prox = NULL;
    novo_personagem->nome = nome;
    novo_personagem->vida = vida;
    novo_personagem->energia = energia;
    novo_personagem->ataque = ataque;
    novo_personagem->flor_dia = flor_dia;
    novo_personagem->flor_noite = flor_noite;

    if (*head == NULL) {
        *head = novo_personagem;
        return;
    } else {
        Personagem *n = *head;
        while (n->prox != NULL) {
            n = n->prox;
        }
        n->prox = novo_personagem;
    }
}

void liberar_personagem(Personagem *head) {
    Personagem *n;
    while (head != NULL) {
        n = head;
        head = head->prox;
        free(n);
    }
}

Personagem * pegar_personagem(int personagem_num, Personagem *personagem_atual, Personagem *head) {
    personagem_atual = head;
    for (int i = 0; i < personagem_num; i++) {
        if (personagem_atual->prox != NULL) {
            personagem_atual = personagem_atual->prox;
        }
    }
    return personagem_atual;
}   