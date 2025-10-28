#include "acao.h"
#include <string.h>
#include <stdio.h>

void acao(int *escolhido, Personagem **personagem_atual, Boss **boss, int ataque, int flor_dia, int flor_noite) {
    int i, j, dano = 0, energia = 0;
    float mult = 1.0;
    Personagem *p = (*personagem_atual);
    Ataque *a = p->ataque;
    Flor_dia *fd = p->flor_dia;
    Flor_noite *fn = p->flor_noite;
    
    if (ataque == 1) {
        for (int i = 0; i < *escolhido && a != NULL; i++) {
            a = a->prox;
        }
        dano = a->dano;
        energia = a->energia_gasta;
    
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if ((*boss)->vantagens_desvantagens[i][j] != NULL) {
                    if (j == 0 && strcmp(a->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        mult = 1.5;
                        break;
                    } else if (j == 1 && strcmp(a->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        break;
                    } else if (j == 2 && strcmp(a->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        mult = 0.75;
                        break;
                    }
                }
            }
        }
    }
    if (flor_dia == 1) {
        for (int i = 0; i < *escolhido && fd != NULL; i++) {
            fd = fd->prox;
        }
        dano = fd->dano;
        energia = fd->energia_gasta;
    
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if ((*boss)->vantagens_desvantagens[i][j] != NULL) {
                    if (j == 0 && strcmp(fd->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        mult = 1.5;
                        break;
                    } else if (j == 1 && strcmp(fd->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        break;
                    } else if (j == 2 && strcmp(fd->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        mult = 0.75;
                        break;                       
                    }    
                }
            }
        }
    }
    if (flor_noite == 1) {
        for (int i = 0; i < *escolhido && fn != NULL; i++) {
            fn = fn->prox;
        }
        dano = fn->dano;
        energia = fn->energia_gasta;
    
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if ((*boss)->vantagens_desvantagens[i][j] != NULL) {
                    if (j == 0 && strcmp(fn->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        mult = 1.5;
                        break;
                    } else if (j == 1 && strcmp(fn->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        break;
                    } else if (j == 2 && strcmp(fn->elemento, (*boss)->vantagens_desvantagens[i][j]) == 0) {
                        mult = 0.75;
                        break;                       
                    }    
                }
            }
        }
    }

    subtrair_vida_boss(&boss, dano, mult);
    printf("vida do boss: %d\n", (*boss)->vida);
    subtrair_energia_personagem(&personagem_atual, energia);
    printf("energia do personagem %s: %d\n", p->nome, p->energia);
}