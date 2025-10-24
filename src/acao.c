#include "acao.h"
#include <string.h>
#include <stdio.h>

void acao(int *escolhido, Personagem *personagem_atual, Boss *boss, int ataque, int flor_dia, int flor_noite) {
    int i, j, dano = 0, energia = 0;
    float mult = 1.0;
    Personagem *p = personagem_atual;
    
    if (ataque == 1) {
        for (int i = 0; i < *escolhido && p->ataque != NULL; i++) {
            p->ataque = p->ataque->prox;
        }
        dano = p->ataque->dano;
        energia = p->ataque->energia_gasta;
    
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if (boss->vantagens_desvantagens[i][j] != NULL) {
                    if (j == 0 && strcmp(p->ataque->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        mult = 1.5;
                        break;
                    } else if (j == 1 && strcmp(p->ataque->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        break;
                    } else if (j == 2 && strcmp(p->ataque->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        mult = 0.75;
                        break;
                    }
                }
            }
        }
    }
    if (flor_dia == 1) {
        for (int i = 0; i < *escolhido && p->flor_dia != NULL; i++) {
            p->flor_dia = p->flor_dia->prox;
        }
        dano = p->flor_dia->dano;
        energia = p->flor_dia->energia_gasta;
    
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if (boss->vantagens_desvantagens[i][j] != NULL) {
                    if (j == 0 && strcmp(p->flor_dia->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        mult = 1.5;
                        break;
                    } else if (j == 1 && strcmp(p->flor_dia->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        break;
                    } else if (j == 2 && strcmp(p->flor_dia->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        mult = 0.75;
                        break;                       
                    }    
                }
            }
        }
    }
    if (flor_noite == 1) {
        for (int i = 0; i < *escolhido && p->flor_noite != NULL; i++) {
            p->flor_noite = p->flor_noite->prox;
        }
        dano = p->flor_noite->dano;
        energia = p->flor_noite->energia_gasta;
    
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 3; j++) {
                if (boss->vantagens_desvantagens[i][j] != NULL) {
                    if (j == 0 && strcmp(p->flor_noite->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        mult = 1.5;
                        break;
                    } else if (j == 1 && strcmp(p->flor_noite->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        break;
                    } else if (j == 2 && strcmp(p->flor_noite->elemento, boss->vantagens_desvantagens[i][j]) == 0) {
                        mult = 0.75;
                        break;                       
                    }    
                }
            }
        }
    }

    subtrair_vida_boss(boss, dano, mult);
    printf("vida do boss: %d\n", boss->vida);
    subtrair_energia_personagem(p, energia);
    printf("energia do personagem %s: %d\n", p->nome, p->energia);
}