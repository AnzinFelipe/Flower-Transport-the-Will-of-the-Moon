#include "escolhas_secundarias.h"
#include "raylib.h"
#include <string.h>
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

void desenhar_escolhas_ataques(int *escolhido, int *inicio, Personagem *personagem_atual, int personagem_num, int largura, int altura, int *energia_sobra, char *elemento, float *velocidade) {
    Color nao_pode = {100, 50, 50, 255};
    Color nao_pode_escolhido = {200, 50, 50, 255};
    int total_ataques = 0;
    Ataque *a = personagem_atual->ataque;

    largura = 50 + (personagem_num * largura / 4);
  
    while (a != NULL) {
        total_ataques++;
        a = a->prox;
    }

    // Faz com que ele va ate a ultima opcao e fique nela descendo
    if (total_ataques <= 3) {
    *inicio = 0;
    } else {
        if (*escolhido < *inicio) {
            *inicio = *escolhido;
        } else if (*escolhido >= *inicio + 3) {
            *inicio = *escolhido - 2;
        }
    }
    if (*inicio < 0) {
        *inicio = 0;
    }
    if (*inicio > total_ataques - 3) {
        *inicio = total_ataques - 3;
    }

    Ataque *n = personagem_atual->ataque;
    for (int i = 0; i < *inicio && n != NULL; i++) {
        n = n->prox;
    }

    for (int i = 0; i < 3 && n != NULL; i++) {
        int indice_atual = *inicio + i;
        if (*escolhido == indice_atual) {
            if (n->energia_gasta > personagem_atual->energia) {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, nao_pode_escolhido);
                *energia_sobra = 0;
            } else {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, WHITE);
                *energia_sobra = 1;
                strcpy(elemento, n->elemento);
                *velocidade = n->velocidade;
            }
        } else {
            if (n->energia_gasta > personagem_atual->energia) {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, nao_pode);
            } else {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, GRAY);
            }
        }
        n = n->prox;
    }
}

void desenhar_escolhas_flores_dia(int *escolhido, int *inicio, Personagem *personagem_atual, int personagem_num, int largura, int altura, int *energia_sobra, char *elemento, float *velocidade) {
    Color nao_pode = {100, 50, 50, 255};
    Color nao_pode_escolhido = {200, 50, 50, 255};
    int total_flores_dias = 0;
    Flor_dia *fd = personagem_atual->flor_dia;

    largura = 50 + (personagem_num * largura / 4);

    while (fd != NULL) {
        total_flores_dias++;
        fd = fd->prox;
    }

    if (total_flores_dias <= 3) {
    } else {
        if (*escolhido < *inicio) {
            *inicio = *escolhido;
        } else if (*escolhido >= *inicio + 3) {
            *inicio = *escolhido - 2;
        }
    }
    if (*inicio < 0) {
        *inicio = 0;
    }
    if (*inicio > total_flores_dias - 3) {
        *inicio = total_flores_dias - 3;
    }

    Flor_dia *n = personagem_atual->flor_dia;
    int contador = 0;
    while (n != NULL && contador < *inicio) {
        n = n->prox;
        contador++;
    }

    for (int i = 0; i < 3 && n != NULL; i++) {
        int indice_atual = *inicio + i;
        if (*escolhido == indice_atual) {
            if (n->energia_gasta > personagem_atual->energia) {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, nao_pode_escolhido);
                *energia_sobra = 0;
            } else {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, WHITE);
                *energia_sobra = 1;
                strcpy(elemento, n->elemento);
                *velocidade = n->velocidade;
            }
        } else {
            if (n->energia_gasta > personagem_atual->energia) {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, nao_pode);
            } else {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, GRAY);
            }
        }
        n = n->prox;
    }
}

void desenhar_escolhas_flores_noite(int *escolhido, int *inicio, Personagem *personagem_atual, int personagem_num, int largura, int altura, int *energia_sobra, char *elemento, float *velocidade) {
    Color nao_pode = {100, 50, 50, 255};
    Color nao_pode_escolhido = {200, 50, 50, 255};
    int total_flores_noites = 0;
    Flor_noite *fn = personagem_atual->flor_noite;

    largura = 50 + (personagem_num * largura / 4);

    while (fn != NULL) {
        total_flores_noites++;
        fn = fn->prox;
    }

    if (total_flores_noites <= 3) {
    *inicio = 0;
    } else {
        if (*escolhido < *inicio) {
            *inicio = *escolhido;
        } else if (*escolhido >= *inicio + 3) {
            *inicio = *escolhido - 2;
        }
    }
    if (*inicio < 0) {
        *inicio = 0;
    }
    if (*inicio > total_flores_noites - 3) {
        *inicio = total_flores_noites - 3;
    }

    Flor_noite *n = personagem_atual->flor_noite;
    int contador = 0;
    while (n != NULL && contador < *inicio) {
        n = n->prox;
        contador++;
    }

    for (int i = 0; i < 3 && n != NULL; i++) {
        int indice_atual = *inicio + i;
        if (*escolhido == indice_atual) {
            if (n->energia_gasta > personagem_atual->energia) {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, nao_pode_escolhido);
                *energia_sobra = 0;
            } else {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, WHITE);
                *energia_sobra = 1;
                strcpy(elemento, n->elemento);
                *velocidade = n->velocidade;
            }
        } else {
            if (n->energia_gasta > personagem_atual->energia) {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, nao_pode);
            } else {
                DrawText(n->nome, largura, altura / 2 + i * 50, 30, GRAY);
            }
        }
        n = n->prox;
    }
}