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
    novo_personagem->defesa = 0;

    if (*head == NULL) {
        *head = novo_personagem;
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

void pegar_personagem(int personagem_num, Personagem **personagem_atual, Personagem *head) {
    *personagem_atual = head;
    for (int i = 0; i < personagem_num; i++) {
        if ((*personagem_atual)->prox != NULL) {
            (*personagem_atual) = (*personagem_atual)->prox;
        }
    }
}   

void adicionar_vantagens_desvantagens_personagem(Personagem **head, int num) {
    int i, j;
    
    Personagem *n = *head;
    for (i = 0; i < num; i++) {
        n = n->prox;
    }

    if (num == 0) {
        static char *elementos[6][3] = {
            // j = 0 Fraquezas | j = 1 Neutro | j = 2 Resistencias
            {"Fogo", "Eletricidade", "Solar"},
            {"Lunar", "Ar", "Agua"},
            {"Veneno", "Gelo", NULL},
            {NULL, "Impacto", NULL},
            {NULL, "Perfuracao", NULL},
            {NULL, "Corte", NULL}
        };

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                n->vantagens_desvantagens[i][j] = elementos[i][j];
            }
        }
    } else if (num == 1) {
        static char *elementos[6][3] = {
            {"Eletricidade", "Veneno", "Solar"},
            {"Lunar", "Gelo", "Fogo"},
            {"Ar", "Impacto", "Perfuracao"},
            {NULL, NULL, "Corte"},
            {NULL, NULL, "Agua"},
            {NULL, NULL, NULL}
        };

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                n->vantagens_desvantagens[i][j] = elementos[i][j];
            }
        }
    } else if (num == 2) {
        static char *elementos[6][3] = {
            {"Solar", "Ar", "Lunar"},
            {"Gelo", "Agua", "Veneno"},
            {"Fogo", "Eletricidade", NULL},
            {"Corte", "Impacto", NULL},
            {"Perfuracao", NULL, NULL},
            {NULL, NULL, NULL}
        };

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                n->vantagens_desvantagens[i][j] = elementos[i][j];
            }
        }
    } else if (num == 3) {
        static char *elementos[6][3] = {
            {"Lunar", "Gelo", "Solar"},
            {"Agua", "Eletricidade", "Veneno"},
            {"Perfuracao", "Ar", "Fogo"},
            {NULL, "Impacto", NULL},
            {NULL, "Corte", NULL},
            {NULL, NULL, NULL}
        };

        for (i = 0; i < 6; i++) {
            for (j = 0; j < 3; j++) {
                n->vantagens_desvantagens[i][j] = elementos[i][j];
            }
        }
    }
}

void subtrair_energia_personagem(Personagem **personagem_atual, int energia_gasta) {
    (*personagem_atual)->energia -= energia_gasta;
    if ((*personagem_atual)->energia < 0) {
        (*personagem_atual)->energia = 0;
    }
}