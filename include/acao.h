// Acoes dos personagens contra o boss

#ifndef ACAO_H
#define ACAO_H

#include "personagem.h"
#include "boss.h"

void acao(int *escolhido, Personagem **personagem_atual, Boss **boss, int ataque, int flor_dia, int flor_noite, int acertou_ataque);

#endif