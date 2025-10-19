// Personagens

#include "ataque.h"
#include "flor_dia.h"
#include "flor_noite.h"

typedef struct {
    char *nome;
    int vida;
    int energia;
    Ataque ataque;
    Flor_dia flor_dia;
    Flor_noite flor_noite;
} Personagem;