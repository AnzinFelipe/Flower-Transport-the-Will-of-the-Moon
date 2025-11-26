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
        {"Água", "Eletricidade", "Gelo"},
        {"Perfuração", "Ar", "Lunar"},
        {"Solar", "Corte", NULL}
    };

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            (*boss)->vantagens_desvantagens[i][j] = elementos[i][j];
        }
    }
}

void adicionar_boss (Boss **boss, Ataque *ataque) {
    (*boss)->nome = "Kalma, a vontade da lua";
    (*boss)->vida = 1200;
    (*boss)->ataque = ataque;
    adicionar_vantagens_desvantagens_boss(boss);
}

void desenhar_vida_boss(Boss *boss, int largura, Color vida, Font fonte) {
    DrawRectangle(largura/2 - 300, 20, 600, 25, DARKGRAY);
    DrawRectangle(largura/2 - 300, 20, boss->vida / 2, 25, vida);
    DrawTextEx(fonte, "Kalma, a vontade do Lua", (Vector2){50, 20}, 40, 2, WHITE);
}

void desenhar_coracao(Texture2D coracao, float largura) {
    DrawTextureEx(coracao, (Vector2){largura,0}, 0.0, 0.5, WHITE);
}

void desenhar_olho(Texture2D olho1, Texture2D olho2, Texture2D olho3, float *olho_animado, float olho_delay) {
    *olho_animado += GetFrameTime();

    if (*olho_animado >= olho_delay * 3) {
        *olho_animado = 0;
        DrawTextureEx(olho1, (Vector2){1375, 280}, 0.0, 0.5, WHITE);
    } else if (*olho_animado >= olho_delay * 2) {
        DrawTextureEx(olho3, (Vector2){1375, 280}, 0.0, 0.5, WHITE);
    } else if (*olho_animado >= olho_delay) {
        DrawTextureEx(olho2, (Vector2){1375, 280}, 0.0, 0.5, WHITE);
    } else {
        DrawTextureEx(olho1, (Vector2){1375, 280}, 0.0, 0.5, WHITE);
    }
}

void subtrair_vida_boss(Boss **boss, int dano, float mult) {
    (*boss)->vida -= dano * mult;
    if ((*boss)->vida < 0) {
        (*boss)->vida = 0;
    }
}

void pegar_personagem_aleatorio(Personagem *personagem, int *random_p) {
    int i;
    Personagem *p;

    while (1) {
        p = personagem;
        *random_p = GetRandomValue(0, 3);
        for (i = 0; i < *random_p && p != NULL; i++) {
            p = p->prox;
        }
        if (p->vida != 0) {
            break;
        }
    }
}

void ataque_boss(Boss *boss, Personagem **personagem, int random_p, int *p0_morto, int *p1_morto, int *p2_morto, int *p3_morto, int *sobreviventes) {
    int i, j, dano = 0;
    float mult = 1;
    int ataque_num = GetRandomValue(0, 3);
    
    Ataque *a = boss->ataque;
    for (i = 0; i < ataque_num && a != NULL; i++) {
        a = a->prox;
    }
    dano = a->dano;
    
    Personagem *p = *personagem;

    for (i = 0; i < random_p && p != NULL; i++) {
        p = p->prox;
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

    subtrair_vida_personagem(personagem, random_p, dano, mult, p0_morto, p1_morto, p2_morto, p3_morto, sobreviventes);
    printf("Boss usou %s no personagem %s causando %d de dano com multiplicador %.2f\n", a->nome, p->nome, dano, mult);
    printf("vida do personagem %s: %d\n", p->nome, p->vida);
}