#ifndef EFEITOS_H
#define EFEITOS_H

#include "raylib.h"

struct Efeito {
    char *nome;
    Texture2D imagem;
    int max_frames;
    int largura;
    int altura;
    struct Efeito *prox;
};

void adicionar_efeito(struct Efeito **head, char *nome, Texture2D imagem, int max_frame, int largura, int altura);

void liberar_efeito(struct Efeito *head);

void animacao_efeito(struct Efeito *head, char * elemento, int *terminou, float *efeito_animado, float delay, int *largura_frames, int *cont);

#endif EFEITOS_H