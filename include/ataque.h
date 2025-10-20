// Ataques

typedef struct {
    char *nome;
    int dano;
    char *elemento;
    int energia_gasta;
    float velocidade;
    Ataque *prox;
} Ataque;