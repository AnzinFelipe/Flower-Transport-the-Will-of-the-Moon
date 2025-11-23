#include "efeitos.h"
#include <stdlib.h>
#include <string.h>

void adicionar_efeito(struct Efeito **head, char *nome, Texture2D imagem, int max_frame, int largura, int altura) {
    struct Efeito *novo = (struct Efeito *)malloc(sizeof(struct Efeito));
    novo->nome = (char *)malloc(50);
    strcpy(novo->nome, nome);
    novo->imagem = imagem;
    novo->max_frames = max_frame;
    novo->largura = largura;
    novo->altura = altura;
    novo->prox = NULL;

    if (*head == NULL) {
        *head = novo;
    } else {
        struct Efeito *e = *head;
        while (e->prox != NULL) {
            e = e->prox;
        }
        e->prox = novo;
    }
}

void liberar_efeito(struct Efeito *head) {
    struct Efeito *e;
    while (head != NULL) {
        e = head;
        head = head->prox;
        free(e->nome);
        free(e);
    }
}

void animacao_efeito(struct Efeito *head, char * elemento, int *terminou, float *efeito_animado, float delay, int *largura_frame, int *cont) {
    
    struct Efeito *efeito = head;
    while (efeito != NULL) {
        if (strcmp(efeito->nome, elemento) == 0) {
            break;
        } else {
            efeito = efeito->prox;
        }
    }
    if (efeito == NULL) {
        *terminou = 1;
        return;
    }
    
    if (*efeito_animado > delay) {
        *largura_frame = efeito->largura * *cont;
        (*cont)++;
        *efeito_animado = 0;
    }
    Rectangle frame = { *largura_frame, 0, efeito->largura, efeito->altura };
    Rectangle escala = { 685, 100, efeito->largura * 5, efeito->altura * 5 };
    DrawTextureRec(efeito->imagem, frame, (Vector2){0, 0}, BLACK);
    DrawTexturePro(efeito->imagem, frame, escala, (Vector2){0, 0}, 0, WHITE);

    if (*cont == efeito->max_frames) {
        *terminou = 1;
        *largura_frame = 0;
        *cont = 0;
    }
}