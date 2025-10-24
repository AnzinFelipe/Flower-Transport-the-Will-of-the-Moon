#include "boss.h"

void adicionar_vantagens_desvantagens_boss(Boss *boss) {
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
            boss->vantagens_desvantagens[i][j] = elementos[i][j];
        }
    }
}

void adicionar_boss (Boss *boss, Ataque *ataque) {
    boss->nome = "Morticia, a vontade da lua";
    boss->vida = 600;
    boss->ataque = ataque;
    adicionar_vantagens_desvantagens_boss(boss);
}

void subtrair_vida_boss(Boss *boss, int dano, float mult) {
    boss->vida -= dano * mult;
    if (boss->vida < 0) {
        boss->vida = 0;
    }
}