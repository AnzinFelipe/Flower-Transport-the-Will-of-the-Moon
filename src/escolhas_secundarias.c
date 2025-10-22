#include "escolhas_secundarias.h"
#include "raylib.h"
#include <stdlib.h>

void mudar_escolha_secundaria(int *escolhido, Personagem *personagem_atual, int escolha_flores_diurnas, int escolha_flores_noturnas, int escolha_ataques, float *pode_apertar, float *delay) {
    int max_escolhido = 0;

    if (escolha_ataques == 1) {
        Ataque *a = personagem_atual->ataque;
        while (a != NULL) {
            max_escolhido++;
            a = a->prox;
        }
    } else if (escolha_flores_diurnas == 1) {
        Flor_dia *fd = personagem_atual->flor_dia;
        while (fd != NULL) {
            max_escolhido++;
            fd = fd->prox;
        }
    } else if (escolha_flores_noturnas == 1) {
        Flor_noite *fn = personagem_atual->flor_noite;
        while (fn != NULL) {
            max_escolhido++;
            fn = fn->prox;
        }
    }
    
    if (IsKeyPressed(KEY_DOWN) && *pode_apertar >= *delay) {
        (*escolhido)++;
        *pode_apertar = 0.0;
        if(*escolhido >= max_escolhido) {
            *escolhido = 0;
        }
    }
    if (IsKeyPressed(KEY_UP) && *pode_apertar >= *delay) {
        (*escolhido)--;
        *pode_apertar = 0.0;
        if(*escolhido < 0) {
            *escolhido = max_escolhido - 1;
        }
    }
}

void desenhar_escolhas_ataques(int *escolhido, Personagem *personagem_atual, int personagem_num, int largura, int altura) {
    int total_ataques = 0;
    int inicio = 0;
    Ataque *a = personagem_atual->ataque;

    largura = (largura - (largura - 50)) + (personagem_num * largura / 4);
  
    while (a != NULL) {
        total_ataques++;
        a = a->prox;
    }

    if (*escolhido >= total_ataques) {
        *escolhido = total_ataques - 1;
    } else if (*escolhido < 0) {
        *escolhido = 0;
    }

    if (*escolhido >= 2) {
        inicio = *escolhido - 1;
        if (inicio + 2 >= total_ataques) {
            inicio = total_ataques - 3;
            if (inicio < 0) {
                inicio = 0;
            }
        }
    }

    Ataque *n = personagem_atual->ataque;
    int contador = 0;
    while (n != NULL && contador < inicio) {
        n = n->prox;
        contador++;
    }

    for (int i = 0; i < 3 && n != NULL; i++) {
        int indice_atual = inicio + i;
        if (*escolhido == indice_atual) {
            DrawText(n->nome, largura, altura / 2 + i * 50, 30, WHITE);
        } else {
            DrawText(n->nome, largura, altura / 2 + i * 50, 30, GRAY);
        }
        n = n->prox;
    }
}

void desenhar_escolhas_flores_dia(int *escolhido, Personagem *personagem_atual, int personagem_num, int largura, int altura) {
    int total_flores_dias = 0;
    int inicio = 0;
    Flor_dia *fd = personagem_atual->flor_dia;

    largura = (largura - (largura - 50)) + (personagem_num * largura / 4);

    while (fd != NULL) {
        total_flores_dias++;
        fd = fd->prox;
    }

    if (*escolhido >= total_flores_dias) {
        *escolhido = total_flores_dias - 1;
    } else if (*escolhido < 0) {
        *escolhido = 0;
    }

    if (*escolhido >= 2) {
        inicio = *escolhido - 1;
        if (inicio + 2 >= total_flores_dias) {
            inicio = total_flores_dias - 3;
            if (inicio < 0) {
                inicio = 0;
            }
        }
    }

    Flor_dia *n = personagem_atual->flor_dia;
    int contador = 0;
    while (n != NULL && contador < inicio) {
        n = n->prox;
        contador++;
    }

    for (int i = 0; i < 3 && n != NULL; i++) {
        int indice_atual = inicio + i;
        if (*escolhido == indice_atual) {
            DrawText(n->nome, largura, altura / 2 + i * 50, 30, WHITE);
        } else {
            DrawText(n->nome, largura, altura / 2 + i * 50, 30, GRAY);
        }
        n = n->prox;
    }
}

void desenhar_escolhas_flores_noite(int *escolhido, Personagem *personagem_atual, int personagem_num, int largura, int altura) {
    int total_flores_noites = 0;
    int inicio = 0;
    Flor_noite *fn = personagem_atual->flor_noite;

    largura = (largura - (largura - 50)) + (personagem_num * largura / 4);

    while (fn != NULL) {
        total_flores_noites++;
        fn = fn->prox;
    }

    if (*escolhido >= total_flores_noites) {
        *escolhido = total_flores_noites - 1;
    } else if (*escolhido < 0) {
        *escolhido = 0;
    }

    if (*escolhido >= 2) {
        inicio = *escolhido - 1;
        if (inicio + 2 >= total_flores_noites) {
            inicio = total_flores_noites - 3;
            if (inicio < 0) {
                inicio = 0;
            }
        }
    }

    Flor_noite *n = personagem_atual->flor_noite;
    int contador = 0;
    while (n != NULL && contador < inicio) {
        n = n->prox;
        contador++;
    }

    for (int i = 0; i < 3 && n != NULL; i++) {
        int indice_atual = inicio + i;
        if (*escolhido == indice_atual) {
            DrawText(n->nome, largura, altura / 2 + i * 50, 30, WHITE);
        } else {
            DrawText(n->nome, largura, altura / 2 + i * 50, 30, GRAY);
        }
        n = n->prox;
    }
}