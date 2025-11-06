#include "personagem.h"
#include "ataque.h"
#include "flor_dia.h"
#include "flor_noite.h"
#include "raylib.h"
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

void desenhar_personagem(Personagem *personagem, int personagem_num, int vida_max, Texture2D vida_cheia, Texture2D pouca_vida, Texture2D derrotado) {
    Personagem *p = personagem;
    int i;
    for (i = 0; i < personagem_num; i++) {
        p = p->prox;
    }

    if (p->vida <= vida_max * 0.25) {
        if (personagem_num == 0) {
            DrawTextureEx(pouca_vida, (Vector2){15, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 1) {
            DrawTextureEx(pouca_vida, (Vector2){415, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 2) {
            DrawTextureEx(pouca_vida, (Vector2){815, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 3) {
            DrawTextureEx(pouca_vida, (Vector2){1215, 650}, 0.0, 0.35, WHITE);
        }
    } else if (p->vida == 0) {
        if (personagem_num == 0) {
            DrawTextureEx(derrotado, (Vector2){15, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 1) {
            DrawTextureEx(derrotado, (Vector2){415, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 2) {
            DrawTextureEx(derrotado, (Vector2){815, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 3) {
            DrawTextureEx(derrotado, (Vector2){1215, 650}, 0.0, 0.35, WHITE);
        }
    } else {
        if (personagem_num == 0) {
            DrawTextureEx(vida_cheia, (Vector2){15, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 1) {
            DrawTextureEx(vida_cheia, (Vector2){415, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 2) {
            DrawTextureEx(vida_cheia, (Vector2){815, 650}, 0.0, 0.35, WHITE);
        } else if (personagem_num == 3) {
            DrawTextureEx(vida_cheia, (Vector2){1215, 650}, 0.0, 0.35, WHITE);
        }
    }
}

void desenhar_vida_personagens(Personagem *personagem, int num, Color vida) {
    Personagem *p = personagem;
    int i;
    for (i = 0; i < num; i++) {
        p = p->prox;
    }
    if (num == 0) {
        DrawRectangle(15, 615, 370, 35, DARKGRAY);
        DrawRectangle(15, 615, p->vida * 3.7, 35, vida);
    } else if (num == 1) {
        DrawRectangle(415, 615, 370, 35, DARKGRAY);
        DrawRectangle(415, 615, p->vida * 2.47, 35, vida);
    } else if (num == 2) {
        DrawRectangle(815, 615, 370, 35, DARKGRAY);
        DrawRectangle(815, 615, p->vida * 4.625, 35, vida);
    } else if (num == 3) {
        DrawRectangle(1215, 615, 370, 35, DARKGRAY);
        DrawRectangle(1215, 615, p->vida * 3.7, 35, vida);
    }
}

void desenhar_energia_personagens(Personagem *personagem, int num, Color energia) {
    Personagem *p = personagem;
    for (int i = 0; i < num; i++) {
        p = p->prox;
    }
    if (num == 0) {
        DrawRectangle(350, 650, 35, 240, DARKGRAY);
        DrawRectangle(350, 650, 35, p->energia * 2.9, energia);
    } else if (num == 1) {
        DrawRectangle(750, 650, 35, 240, DARKGRAY);
        DrawRectangle(750, 650, 35, p->energia * 5.9, energia);
    } else if (num == 2) {
        DrawRectangle(1150, 650, 35, 240, DARKGRAY);
        DrawRectangle(1150, 650, 35, p->energia * 2.9, energia);
    } else if (num == 3) {
        DrawRectangle(1550, 650, 35, 240, BLACK);
    }
}

void subtrair_vida_personagem(Personagem **personagem, int personagem_num, int dano, float mult, int *p0_morto, int *p1_morto, int *p2_morto, int *p3_morto) {
    Personagem *p = *personagem;
    for (int i = 0; i < personagem_num; i++) {
        p = p->prox;
    }

    p->vida -= dano * mult;
    if (p->vida < 0) {
        p->vida = 0;
    }
    if (personagem_num == 0 && p->vida == 0) {
        *p0_morto = 1;
    } else if (personagem_num == 1 && p->vida == 0) {
        *p1_morto = 1;
    } else if (personagem_num == 2 && p->vida == 0) {
        *p2_morto = 1;
    } else if (personagem_num == 3 && p->vida == 0) {
        *p3_morto = 1;
    }
}

void subtrair_energia_personagem(Personagem **personagem_atual, int energia_gasta) {
    (*personagem_atual)->energia -= energia_gasta;
    if ((*personagem_atual)->energia < 0) {
        (*personagem_atual)->energia = 0;
    }
}