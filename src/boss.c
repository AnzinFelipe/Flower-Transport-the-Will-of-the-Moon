#include "boss.h"
#include "personagem.h"
#include "raylib.h"
#include <string.h>
#include <stdio.h>

void adicionar_vantagens_desvantagens_boss(Boss **boss) {
    int i, j;

    // j = 0 Fraquezas | j = 1 Neutro | j = 2 Resistencias
    static char *elementos[4][3] = {
        {"Fogo", "Impacto", "Veneno"},
        {"Agua", "Eletricidade", "Gelo"},
        {"Perfuracao", "Ar", "Lunar"},
        {"Solar", "Corte", NULL}
    };

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            (*boss)->vantagens_desvantagens[i][j] = elementos[i][j];
        }
    }
}

void adicionar_boss (Boss **boss, Ataque *ataque) {
    (*boss)->nome = "Morticia, a vontade da lua";
    (*boss)->vida = 1200;
    (*boss)->ataque = ataque;
    adicionar_vantagens_desvantagens_boss(boss);
}

void desenhar_vida_boss(Boss *boss, int largura, Color vida) {
    DrawRectangle(largura/2 - 300, 20, 600, 25, DARKGRAY);
    DrawRectangle(largura/2 - 300, 20, boss->vida / 2, 25, vida);
}

void desenhar_coracao(Texture2D coracao, float largura) {
    DrawTextureEx(coracao, (Vector2){largura,0}, 0.0, 0.5, WHITE);
}

void subtrair_vida_boss(Boss **boss, int dano, float mult) {
    (*boss)->vida -= dano * mult;
    if ((*boss)->vida < 0) {
        (*boss)->vida = 0;
    }
}

void ataque_boss(Boss *boss, Personagem **personagem, int *p0_morto, int *p1_morto, int *p2_morto, int *p3_morto) {
    int i, j, dano = 0;
    float mult = 1;
    int personagem_num;
    int ataque_num = GetRandomValue(0, 3);
    
    Ataque *a = boss->ataque;
    for (i = 0; i < ataque_num && a != NULL; i++) {
        a = a->prox;
    }
    dano = a->dano;
    
    Personagem *p;

    while (1) {
        p = *personagem;
        personagem_num = GetRandomValue(0, 3);
        for (i = 0; i < personagem_num && p != NULL; i++) {
            p = p->prox;
        }
        if (p->vida != 0) {
            break;
        }
    }

    for (i = 0; i < 6; i++) {
        for (j = 0; j < 3; j++) {
            if (p->vantagens_desvantagens[i][j] != NULL) {
                if (j == 0 && strcmp(a->elemento, p->vantagens_desvantagens[i][j]) == 0) {
                    if (p->defesa == 1) {
                        mult = 1;
                        break;
                    } else {
                        mult = 1.5;
                        break;
                    }
                } else if (j == 1 && strcmp(a->elemento, p->vantagens_desvantagens[i][j]) == 0) {
                    if (p->defesa == 1) {
                        mult = 0.5;
                        break;
                    } else {
                        mult = 1;
                        break;
                    }
                } else if (j == 2 && strcmp(a->elemento, p->vantagens_desvantagens[i][j]) == 0) {
                    if (p->defesa == 1) {
                        mult = 0.25;
                        break;
                    } else {
                        mult = 0.75;
                        break;
                    }                     
                }   
            }
        }
    }

    subtrair_vida_personagem(personagem, personagem_num, dano, mult, p0_morto, p1_morto, p2_morto, p3_morto);
    printf("Boss usou %s no personagem %s causando %d de dano com multiplicador %.2f\n", a->nome, p->nome, dano, mult);
    printf("vida do personagem %s: %d\n", p->nome, p->vida);
}