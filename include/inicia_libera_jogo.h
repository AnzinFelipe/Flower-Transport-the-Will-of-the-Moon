#ifndef INICIA_LIBERA_JOGO_H
#define INICIA_LIBERA_JOGO_H

#include "raylib.h"
#include "ataque.h"
#include "flor_dia.h"
#include "flor_noite.h"
#include "personagem.h"
#include "boss.h"
#include "efeitos.h"
#include "ranking.h"

typedef struct VariaveisInicioJogo{
    RenderTexture2D janela;
    Music batalha, batalha2;
    Font fonte; 
    Texture2D BG, BG_noite, noite, relogio_dia, relogio_noite, borda_escolhido, borda, caixa;
    Texture2D quadro_roxo, quadro_roxo_noite, quadro_vermelho, quadro_vermelho_noite;
    Texture2D quadro_laranja, quadro_laranja_noite, quadro_vinho, quadro_vinho_noite;
    Texture2D quadro_roxo2, quadro_roxo2_noite, quadro_vermelho2, quadro_vermelho2_noite;
    Texture2D quadro_laranja2, quadro_laranja2_noite, quadro_vinho2, quadro_vinho2_noite;
    Texture2D quadro_roxo3, quadro_roxo3_noite, quadro_vermelho3, quadro_vermelho3_noite;
    Texture2D quadro_laranja3, quadro_laranja3_noite, quadro_vinho3, quadro_vinho3_noite;
    Texture2D boss_dia_f1, boss_dia_f2, boss_dia_f3, boss_noite_f1, boss_noite_f2, boss_noite_f3;
    Texture2D boss_acertar, boss_coracao, boss_ataque_dia, boss_ataque_noite;
    Texture2D olho1, olho2, olho3;
    Texture2D proj_agua, proj_ar, proj_corte, proj_eletricidade, proj_fogo, proj_gelo, proj_impacto, proj_lunar, proj_perfuracao, proj_solar, proj_veneno;
    Texture2D efeito_agua, efeito_ar, efeito_corte, efeito_eletricidade, efeito_fogo, efeito_gelo, efeito_impacto, efeito_lunar, efeito_perfuracao, efeito_solar, efeito_veneno;
    int escolhas, escolha_flores_diurnas, escolha_flores_noturnas, escolha_ataques, defender;
    int escolhido, inicio_escolhas_secundarios, personagem_num, vez_inimigo, horario, energia_sobra;
    int momento_atacar, verificar_ataque, ataque_apertado, acertou_ataque;
    int projetil_ataque, projetil_flor_diurna, projetil_flor_noturna;
    int p0_morto, p1_morto, p2_morto, p3_morto;
    int ir_coracao, voltar_coracao;
    int comeco, random_p;
    int animacao_efeito, efeito_terminou, cont_frames, largura_frame;
    int pontuacao_inicio;
    float velocidade_atual;
    float largura_coracao, altura_proj;
    Rectangle colisao_proj_horizontal, colisao_proj_vertical, colisao_teto;
    Vector2 colisao_coracao;
    float pode_apertar, delay;
    float ataque_boss_tempo, delay_ataque_boss;
    float boss_animado, delay_boss_animado;
    float olho_animado, olho_delay;
    float efeito_animado, efeito_delay;
    char *elemento_atual;
    Color vida_cor, energia_cor;
    Personagem *personagem_atual;
    Ataque *ataque_head2, *ataque_head3, *ataque_head4, *ataque_head_boss;
    Flor_dia *flor_dia_head1, *flor_dia_head2;
    Flor_noite *flor_noite_head1, *flor_noite_head3;
    Personagem *personagem_head;
    struct Efeito *efeitos;
    Boss *boss;
} VariaveisInicioJogo;

void novo_jogo(VariaveisInicioJogo *s, int largura, int altura);
void liberar_jogo(VariaveisInicioJogo *s);

#endif