#include "inicia_libera_jogo.h"
#include <stdlib.h>
#include <string.h>

void novo_jogo(VariaveisInicioJogo *s, int largura, int altura){
    s->ataque_head2 = NULL; s->ataque_head3 = NULL; s->ataque_head4 = NULL; s->ataque_head_boss = NULL;
    s->flor_dia_head1 = NULL; s->flor_dia_head2 = NULL;
    s->flor_noite_head1 = NULL; s->flor_noite_head3 = NULL;
    s->personagem_atual = NULL; s->personagem_head = NULL;
    s->boss = NULL;
    s->elemento_atual = NULL;
}
void liberar_jogo(VariaveisInicioJogo *s){}