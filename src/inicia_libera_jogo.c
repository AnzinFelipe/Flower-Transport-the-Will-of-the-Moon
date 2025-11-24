#include "inicia_libera_jogo.h"
#include <stdlib.h>
#include <string.h>

void novo_jogo(VariaveisInicioJogo *s, int largura, int altura){
    s->ataque_head2 = NULL; s->ataque_head3 = NULL; s->ataque_head4 = NULL; s->ataque_head_boss = NULL;
    s->flor_dia_head1 = NULL; s->flor_dia_head2 = NULL;
    s->flor_noite_head1 = NULL; s->flor_noite_head3 = NULL;
    s->personagem_atual = NULL; s->personagem_head = NULL;
    s->efeitos = NULL;
    s->boss = NULL;
    s->elemento_atual = NULL;

    s->janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(s->janela.texture, TEXTURE_FILTER_TRILINEAR);
    
    s->fonte = LoadFontEx("assets/fonts/EmilysCandy-Regular.ttf", 40, NULL, 252);
    SetTextureFilter(s->fonte.texture, TEXTURE_FILTER_BILINEAR);

    if (!IsAudioDeviceReady()) {
        InitAudioDevice();
    }
    s->batalha = LoadMusicStream("assets/music/Batalha.mp3");
    PlayMusicStream(s->batalha);
    s->batalha2 = LoadMusicStream("assets/music/Batalha2.mp3");
    PlayMusicStream(s->batalha2);

    s->BG = LoadTexture("assets/images/BG.png");
    GenTextureMipmaps(&s->BG);
    SetTextureFilter(s->BG, TEXTURE_FILTER_TRILINEAR);
    s->BG_noite = LoadTexture("assets/images/BG_noite.png");
    GenTextureMipmaps(&s->BG_noite);
    SetTextureFilter(s->BG_noite, TEXTURE_FILTER_TRILINEAR);

    s->noite = LoadTexture("assets/images/Noite.png");
    GenTextureMipmaps(&s->noite);
    SetTextureFilter(s->noite, TEXTURE_FILTER_TRILINEAR);

    s->relogio_dia = LoadTexture("assets/images/Relogio_dia.png");
    GenTextureMipmaps(&s->relogio_dia);
    SetTextureFilter(s->relogio_dia, TEXTURE_FILTER_TRILINEAR);
    s->relogio_noite = LoadTexture("assets/images/Relogio_noite.png");
    GenTextureMipmaps(&s->relogio_noite);
    SetTextureFilter(s->relogio_noite, TEXTURE_FILTER_TRILINEAR);

    s->borda_escolhido = LoadTexture("assets/images/Borda.png");
    GenTextureMipmaps(&s->borda_escolhido);
    SetTextureFilter(s->borda_escolhido, TEXTURE_FILTER_TRILINEAR);
    s->borda = LoadTexture("assets/images/Borda2.png");
    GenTextureMipmaps(&s->borda);
    SetTextureFilter(s->borda, TEXTURE_FILTER_TRILINEAR);
    s->caixa = LoadTexture("assets/images/Caixa.png");
    GenTextureMipmaps(&s->caixa);
    SetTextureFilter(s->caixa, TEXTURE_FILTER_TRILINEAR);

    s->quadro_roxo = LoadTexture("assets/images/roxo/Roxo1.png");
    GenTextureMipmaps(&s->quadro_roxo);
    SetTextureFilter(s->quadro_roxo, TEXTURE_FILTER_TRILINEAR);
    s->quadro_roxo_noite = LoadTexture("assets/images/roxo/Roxo1_noite.png");
    GenTextureMipmaps(&s->quadro_roxo_noite);
    SetTextureFilter(s->quadro_roxo_noite, TEXTURE_FILTER_TRILINEAR);
    s->quadro_roxo2 = LoadTexture("assets/images/roxo/Roxo2.png");
    GenTextureMipmaps(&s->quadro_roxo2);
    SetTextureFilter(s->quadro_roxo2, TEXTURE_FILTER_TRILINEAR);
    s->quadro_roxo2_noite = LoadTexture("assets/images/roxo/Roxo2_noite.png");
    GenTextureMipmaps(&s->quadro_roxo2_noite);
    SetTextureFilter(s->quadro_roxo2_noite, TEXTURE_FILTER_TRILINEAR);
    s->quadro_roxo3 = LoadTexture("assets/images/roxo/Roxo3.png");
    GenTextureMipmaps(&s->quadro_roxo3);
    SetTextureFilter(s->quadro_roxo3, TEXTURE_FILTER_TRILINEAR);
    s->quadro_roxo3_noite = LoadTexture("assets/images/roxo/Roxo3_noite.png");
    GenTextureMipmaps(&s->quadro_roxo3_noite);
    SetTextureFilter(s->quadro_roxo3_noite, TEXTURE_FILTER_TRILINEAR);

    s->quadro_vermelho = LoadTexture("assets/images/vermelho/Vermelho1.png");
    GenTextureMipmaps(&s->quadro_vermelho);
    SetTextureFilter(s->quadro_vermelho, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vermelho_noite = LoadTexture("assets/images/vermelho/Vermelho1_noite.png");
    GenTextureMipmaps(&s->quadro_vermelho_noite);
    SetTextureFilter(s->quadro_vermelho_noite, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vermelho2 = LoadTexture("assets/images/vermelho/Vermelho2.png");
    GenTextureMipmaps(&s->quadro_vermelho2);
    SetTextureFilter(s->quadro_vermelho2, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vermelho2_noite = LoadTexture("assets/images/vermelho/Vermelho2_noite.png");
    GenTextureMipmaps(&s->quadro_vermelho2_noite);
    SetTextureFilter(s->quadro_vermelho2_noite, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vermelho3 = LoadTexture("assets/images/vermelho/Vermelho3.png");
    GenTextureMipmaps(&s->quadro_vermelho3);
    SetTextureFilter(s->quadro_vermelho3, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vermelho3_noite = LoadTexture("assets/images/vermelho/Vermelho3_noite.png");
    GenTextureMipmaps(&s->quadro_vermelho3_noite);
    SetTextureFilter(s->quadro_vermelho3_noite, TEXTURE_FILTER_TRILINEAR);

    s->quadro_laranja = LoadTexture("assets/images/laranja/Laranja1.png");
    GenTextureMipmaps(&s->quadro_laranja);
    SetTextureFilter(s->quadro_laranja, TEXTURE_FILTER_TRILINEAR);
    s->quadro_laranja_noite = LoadTexture("assets/images/laranja/Laranja1_noite.png");
    GenTextureMipmaps(&s->quadro_laranja_noite);
    SetTextureFilter(s->quadro_laranja_noite, TEXTURE_FILTER_TRILINEAR);
    s->quadro_laranja2 = LoadTexture("assets/images/laranja/Laranja2.png");
    GenTextureMipmaps(&s->quadro_laranja2);
    SetTextureFilter(s->quadro_laranja2, TEXTURE_FILTER_TRILINEAR);
    s->quadro_laranja2_noite = LoadTexture("assets/images/laranja/Laranja2_noite.png");
    GenTextureMipmaps(&s->quadro_laranja2_noite);
    SetTextureFilter(s->quadro_laranja2_noite, TEXTURE_FILTER_TRILINEAR);
    s->quadro_laranja3 = LoadTexture("assets/images/laranja/Laranja3.png");
    GenTextureMipmaps(&s->quadro_laranja3);
    SetTextureFilter(s->quadro_laranja3, TEXTURE_FILTER_TRILINEAR);
    s->quadro_laranja3_noite = LoadTexture("assets/images/laranja/Laranja3_noite.png");
    GenTextureMipmaps(&s->quadro_laranja3_noite);
    SetTextureFilter(s->quadro_laranja3_noite, TEXTURE_FILTER_TRILINEAR);

    s->quadro_vinho = LoadTexture("assets/images/vinho/Vinho1.png");
    GenTextureMipmaps(&s->quadro_vinho);
    SetTextureFilter(s->quadro_vinho, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vinho_noite = LoadTexture("assets/images/vinho/Vinho1_noite.png");
    GenTextureMipmaps(&s->quadro_vinho_noite);
    SetTextureFilter(s->quadro_vinho_noite, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vinho2 = LoadTexture("assets/images/vinho/Vinho2.png");
    GenTextureMipmaps(&s->quadro_vinho2);
    SetTextureFilter(s->quadro_vinho2, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vinho2_noite = LoadTexture("assets/images/vinho/Vinho2_noite.png");
    GenTextureMipmaps(&s->quadro_vinho2_noite);
    SetTextureFilter(s->quadro_vinho2_noite, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vinho3 = LoadTexture("assets/images/vinho/Vinho3.png");
    GenTextureMipmaps(&s->quadro_vinho3);
    SetTextureFilter(s->quadro_vinho3, TEXTURE_FILTER_TRILINEAR);
    s->quadro_vinho3_noite = LoadTexture("assets/images/vinho/Vinho3_noite.png");
    GenTextureMipmaps(&s->quadro_vinho3_noite);
    SetTextureFilter(s->quadro_vinho3_noite, TEXTURE_FILTER_TRILINEAR);

    s->boss_dia_f1 = LoadTexture("assets/images/boss/Boss_dia_f1.png");
    GenTextureMipmaps(&s->boss_dia_f1);
    SetTextureFilter(s->boss_dia_f1, TEXTURE_FILTER_TRILINEAR);
    s->boss_noite_f1 = LoadTexture("assets/images/boss/Boss_noite_f1.png");
    GenTextureMipmaps(&s->boss_noite_f1);
    SetTextureFilter(s->boss_noite_f1, TEXTURE_FILTER_TRILINEAR);
    s->boss_dia_f2 = LoadTexture("assets/images/boss/Boss_dia_f2.png");
    GenTextureMipmaps(&s->boss_dia_f2);
    SetTextureFilter(s->boss_dia_f2, TEXTURE_FILTER_TRILINEAR);
    s->boss_noite_f2 = LoadTexture("assets/images/boss/Boss_noite_f2.png");
    GenTextureMipmaps(&s->boss_noite_f2);
    SetTextureFilter(s->boss_noite_f2, TEXTURE_FILTER_TRILINEAR);
    s->boss_dia_f3 = LoadTexture("assets/images/boss/Boss_dia_f3.png");
    GenTextureMipmaps(&s->boss_dia_f3);
    SetTextureFilter(s->boss_dia_f3, TEXTURE_FILTER_TRILINEAR);
    s->boss_noite_f3 = LoadTexture("assets/images/boss/Boss_noite_f3.png");
    GenTextureMipmaps(&s->boss_noite_f3);
    SetTextureFilter(s->boss_noite_f3, TEXTURE_FILTER_TRILINEAR);

    s->boss_acertar = LoadTexture("assets/images/boss/Boss_acertar.png");
    GenTextureMipmaps(&s->boss_acertar);
    SetTextureFilter(s->boss_acertar, TEXTURE_FILTER_TRILINEAR);
    s->boss_coracao = LoadTexture("assets/images/boss/Boss_coracao.png");
    GenTextureMipmaps(&s->boss_coracao);
    SetTextureFilter(s->boss_coracao, TEXTURE_FILTER_TRILINEAR);

    s->boss_ataque_dia = LoadTexture("assets/images/boss/Boss_ataque_dia.png");
    GenTextureMipmaps(&s->boss_ataque_dia);
    SetTextureFilter(s->boss_ataque_dia, TEXTURE_FILTER_TRILINEAR);
    s->boss_ataque_noite = LoadTexture("assets/images/boss/Boss_ataque_noite.png");
    GenTextureMipmaps(&s->boss_ataque_noite);
    SetTextureFilter(s->boss_ataque_noite, TEXTURE_FILTER_TRILINEAR);

    s->olho1 = LoadTexture("assets/images/boss/Olho_f1.png");
    GenTextureMipmaps(&s->olho1);
    SetTextureFilter(s->olho1, TEXTURE_FILTER_TRILINEAR);
    s->olho2 = LoadTexture("assets/images/boss/Olho_f2.png");
    GenTextureMipmaps(&s->olho2);
    SetTextureFilter(s->olho2, TEXTURE_FILTER_TRILINEAR);
    s->olho3 = LoadTexture("assets/images/boss/Olho_f3.png");
    GenTextureMipmaps(&s->olho3);
    SetTextureFilter(s->olho3, TEXTURE_FILTER_TRILINEAR);


    s->proj_agua = LoadTexture("assets/images/projeteis/Agua.png");
    GenTextureMipmaps(&s->proj_agua);
    SetTextureFilter(s->proj_agua, TEXTURE_FILTER_TRILINEAR);
    s->proj_ar = LoadTexture("assets/images/projeteis/Ar.png");
    GenTextureMipmaps(&s->proj_ar);
    SetTextureFilter(s->proj_ar, TEXTURE_FILTER_TRILINEAR);
    s->proj_corte = LoadTexture("assets/images/projeteis/Corte.png");
    GenTextureMipmaps(&s->proj_corte);
    SetTextureFilter(s->proj_corte, TEXTURE_FILTER_TRILINEAR);
    s->proj_eletricidade = LoadTexture("assets/images/projeteis/Eletricidade.png");
    GenTextureMipmaps(&s->proj_eletricidade);
    SetTextureFilter(s->proj_eletricidade, TEXTURE_FILTER_TRILINEAR);
    s->proj_fogo = LoadTexture("assets/images/projeteis/Fogo.png");
    GenTextureMipmaps(&s->proj_fogo);
    SetTextureFilter(s->proj_fogo, TEXTURE_FILTER_TRILINEAR);
    s->proj_gelo = LoadTexture("assets/images/projeteis/Gelo.png");
    GenTextureMipmaps(&s->proj_gelo);
    SetTextureFilter(s->proj_gelo, TEXTURE_FILTER_TRILINEAR);
    s->proj_impacto = LoadTexture("assets/images/projeteis/Impacto.png");
    GenTextureMipmaps(&s->proj_impacto);
    SetTextureFilter(s->proj_impacto, TEXTURE_FILTER_TRILINEAR);
    s->proj_lunar = LoadTexture("assets/images/projeteis/Lunar.png");
    GenTextureMipmaps(&s->proj_lunar);
    SetTextureFilter(s->proj_lunar, TEXTURE_FILTER_TRILINEAR);
    s->proj_perfuracao = LoadTexture("assets/images/projeteis/Perfuracao.png");
    GenTextureMipmaps(&s->proj_perfuracao);
    SetTextureFilter(s->proj_perfuracao, TEXTURE_FILTER_TRILINEAR);
    s->proj_solar = LoadTexture("assets/images/projeteis/Solar.png");
    GenTextureMipmaps(&s->proj_solar);
    SetTextureFilter(s->proj_solar, TEXTURE_FILTER_TRILINEAR);
    s->proj_veneno = LoadTexture("assets/images/projeteis/Veneno.png");
    GenTextureMipmaps(&s->proj_veneno);
    SetTextureFilter(s->proj_veneno, TEXTURE_FILTER_TRILINEAR);

    s->efeito_agua = LoadTexture("assets/images/efeitos/agua.png");
    GenTextureMipmaps(&s->efeito_agua);
    SetTextureFilter(s->efeito_agua, TEXTURE_FILTER_POINT);
    s->efeito_ar = LoadTexture("assets/images/efeitos/ar.png");
    GenTextureMipmaps(&s->efeito_ar);
    SetTextureFilter(s->efeito_ar, TEXTURE_FILTER_POINT);
    s->efeito_corte = LoadTexture("assets/images/efeitos/corte.png");
    GenTextureMipmaps(&s->efeito_corte);
    SetTextureFilter(s->efeito_corte, TEXTURE_FILTER_POINT);
    s->efeito_eletricidade = LoadTexture("assets/images/efeitos/eletricidade.png");
    GenTextureMipmaps(&s->efeito_eletricidade);
    SetTextureFilter(s->efeito_eletricidade, TEXTURE_FILTER_POINT);
    s->efeito_fogo = LoadTexture("assets/images/efeitos/fogo.png");
    GenTextureMipmaps(&s->efeito_fogo);
    SetTextureFilter(s->efeito_fogo, TEXTURE_FILTER_POINT);
    s->efeito_gelo = LoadTexture("assets/images/efeitos/gelo.png");
    GenTextureMipmaps(&s->efeito_gelo);
    SetTextureFilter(s->efeito_gelo, TEXTURE_FILTER_POINT);
    s->efeito_impacto = LoadTexture("assets/images/efeitos/impacto.png");
    GenTextureMipmaps(&s->efeito_impacto);
    SetTextureFilter(s->efeito_impacto, TEXTURE_FILTER_POINT);
    s->efeito_lunar = LoadTexture("assets/images/efeitos/lunar.png");
    GenTextureMipmaps(&s->efeito_lunar);
    SetTextureFilter(s->efeito_lunar, TEXTURE_FILTER_POINT);
    s->efeito_perfuracao = LoadTexture("assets/images/efeitos/perfuracao.png");
    GenTextureMipmaps(&s->efeito_perfuracao);
    SetTextureFilter(s->efeito_perfuracao, TEXTURE_FILTER_POINT);
    s->efeito_solar = LoadTexture("assets/images/efeitos/solar.png");
    GenTextureMipmaps(&s->efeito_solar);
    SetTextureFilter(s->efeito_solar, TEXTURE_FILTER_POINT);
    s->efeito_veneno = LoadTexture("assets/images/efeitos/veneno.png");
    GenTextureMipmaps(&s->efeito_veneno);
    SetTextureFilter(s->efeito_veneno, TEXTURE_FILTER_POINT);

    s->escolhas = 1; s->escolha_flores_diurnas = 0; s->escolha_flores_noturnas = 0; s->escolha_ataques = 0; s->defender = 0;
    s->escolhido = 0; s->inicio_escolhas_secundarios = 0; s->personagem_num = 0; s->vez_inimigo = 0; s->horario = 0;
    s->p0_morto = 0, s->p1_morto = 0; s->p2_morto = 0; s->p3_morto = 0;
    s->momento_atacar = 0, s->verificar_ataque = 0, s->ataque_apertado = 0, s->acertou_ataque = 0;
    s->projetil_ataque = 0, s->projetil_flor_diurna = 0, s->projetil_flor_noturna = 0;
    s->ir_coracao = 0, s->voltar_coracao = 0;
    s->largura_coracao = 0, s->altura_proj = 0;
    s->elemento_atual = (char *)malloc(20);
    s->velocidade_atual = 0.0;
    s->energia_sobra = 0;
    s->comeco = 1, s->random_p = 0;
    s->animacao_efeito = 0, s->efeito_terminou = 0, s->cont_frames = 0, s->largura_frame = 0;
    s->pode_apertar = 0.0; s->delay = 0.1;
    s->ataque_boss_tempo = 0.0; s->delay_ataque_boss = 2;
    s->boss_animado = 0.0; s->delay_boss_animado = 0.4;
    s->olho_animado = 0.0; s->olho_delay = 0.2;
    s->efeito_animado = 0.0; s->efeito_delay = 0.1;
    s->vida_cor = (Color){120, 18, 18, 255};
    s->energia_cor = (Color){18, 120, 80, 255};
    s->colisao_teto = (Rectangle){0, 0, 1600, 1};

    adicionar_ataque(&s->ataque_head2, "Soco", 20, "Impacto", 5, 1.5, "");
    adicionar_ataque(&s->ataque_head2, "Chute", 15, "Impacto", 5, 1.0, "");
    adicionar_ataque(&s->ataque_head2, "Pá de jardinagem", 30, "Impacto", 10, 1.5, "");
    adicionar_ataque(&s->ataque_head2, "Tesoura de poda", 25, "Corte", 10, 1.5, "");

    adicionar_ataque(&s->ataque_head3, "Soco", 15, "Impacto", 5, 2.0, "");
    adicionar_ataque(&s->ataque_head3, "Unhada", 10, "Corte", 3, 2.5, "");
    adicionar_ataque(&s->ataque_head3, "Chute espiral", 25, "Perfuração", 15, 2.0, "");
    adicionar_ataque(&s->ataque_head3, "Chifrada", 30, "Perfuração", 20, 1.5, "");

    adicionar_ataque(&s->ataque_head4, "Soco solar", 35, "Impacto", 0, 2.0, "");
    adicionar_ataque(&s->ataque_head4, "Chute solar", 35, "Impacto", 0, 1.5, "");
    adicionar_ataque(&s->ataque_head4, "Lança solar", 30, "Perfuração", 0, 2.5, "");
    adicionar_ataque(&s->ataque_head4, "Espada solar", 30, "Corte", 0, 1.0, "");
    adicionar_ataque(&s->ataque_head4, "Fumaça venenosa", 10, "Veneno", 0, 1.0, "");

    adicionar_ataque(&s->ataque_head_boss, "Bafo lunar", 25, "Fogo", 0, 0, "");
    adicionar_ataque(&s->ataque_head_boss, "Chute dilacerante", 20, "Corte", 0, 0, "");
    adicionar_ataque(&s->ataque_head_boss, "Espectro lunático", 30, "Lunar", 0, 0, "");
    adicionar_ataque(&s->ataque_head_boss, "Olhar sombrio", 25, "Lunar", 0, 0, "");

    adicionar_flor_dia(&s->flor_dia_head1, "Flamígera-do-dia", 25, "Fogo", 15, 1.5, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Tulipa afiada", 10, "Corte", 15, 1.5, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Orquídea voltaica", 20, "Eletricidade", 15, 2.5, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Nenúfar real", 15, "Água", 15, 1.5, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Girassol", 20, "Solar", 15, 2.0, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Ventanilia", 15, "Ar", 15, 2.5, "");

    adicionar_flor_dia(&s->flor_dia_head2, "Rosa gélida", 15, "Gelo", 15, 1.0, "");
    adicionar_flor_dia(&s->flor_dia_head2, "Helicopdea", 10, "Ar", 15, 2.5, "");
    adicionar_flor_dia(&s->flor_dia_head2, "Girassol", 20, "Solar", 15, 2.0, "");
    adicionar_flor_dia(&s->flor_dia_head2, "Gravitiana", 20, "Impacto", 15, 1.0, "");
    adicionar_flor_dia(&s->flor_dia_head2, "Lótus", 15, "Água", 15, 2.0, "");

    adicionar_flor_noite(&s->flor_noite_head1, "Rosa cromada", 20, "Impacto", 10, 1.0, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Rainha-da-noite", 20, "Fogo", 10, 2.0, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Realeza espinhenta", 15, "Perfuração", 10, 2.5, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Flor de Mandacaru", 20, "Água", 10, 1.5, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Trombeta-de-anjo", 15, "Veneno", 10, 1.5, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Glória-da-friagem", 20, "Gelo", 10, 1.5, "");

    adicionar_flor_noite(&s->flor_noite_head3, "Dama-da-noite", 20, "Lunar", 10, 2.0, "");
    adicionar_flor_noite(&s->flor_noite_head3, "Flamígera-da-noite", 25, "Fogo", 10, 1.5, "");
    adicionar_flor_noite(&s->flor_noite_head3, "Realeza espinhenta", 15, "Perfuração", 10, 2.5, "");
    adicionar_flor_noite(&s->flor_noite_head3, "Glória-da-friagem", 20, "Gelo", 10, 1.5, "");
    adicionar_flor_noite(&s->flor_noite_head3, "Energiálida", 15, "Eletricidade", 10, 2.5, "");

    adicionar_personagem(&s->personagem_head, "Narciso", 100, 80, NULL, s->flor_dia_head1, s->flor_noite_head1);
    adicionar_personagem(&s->personagem_head, "Roderick", 150, 50, s->ataque_head2, s->flor_dia_head2, NULL);
    adicionar_personagem(&s->personagem_head, "Edoras", 80, 80, s->ataque_head3, NULL, s->flor_noite_head3);
    adicionar_personagem(&s->personagem_head, "Lumennyl", 100, 0, s->ataque_head4, NULL, NULL);

    adicionar_efeito(&s->efeitos, "Água", s->efeito_agua, 15, 48, 47);
    adicionar_efeito(&s->efeitos, "Ar", s->efeito_ar, 9, 45, 43);
    adicionar_efeito(&s->efeitos, "Corte", s->efeito_corte, 8, 44, 42);
    adicionar_efeito(&s->efeitos, "Eletricidade", s->efeito_eletricidade, 13, 46, 47);
    adicionar_efeito(&s->efeitos, "Fogo", s->efeito_fogo, 20, 50, 95);
    adicionar_efeito(&s->efeitos, "Gelo", s->efeito_gelo, 28, 48, 48);
    adicionar_efeito(&s->efeitos, "Impacto", s->efeito_impacto, 9, 54, 55);
    adicionar_efeito(&s->efeitos, "Lunar", s->efeito_lunar, 31, 47, 43);
    adicionar_efeito(&s->efeitos, "Perfuração", s->efeito_perfuracao, 8, 25, 37);
    adicionar_efeito(&s->efeitos, "Solar", s->efeito_solar, 17, 45, 46);
    adicionar_efeito(&s->efeitos, "Veneno", s->efeito_veneno, 24, 46, 44);

    adicionar_vantagens_desvantagens_personagem(&s->personagem_head, 0);
    adicionar_vantagens_desvantagens_personagem(&s->personagem_head, 1);
    adicionar_vantagens_desvantagens_personagem(&s->personagem_head, 2);
    adicionar_vantagens_desvantagens_personagem(&s->personagem_head, 3);

    s->boss = (Boss *)malloc(sizeof(Boss));
    adicionar_boss(&s->boss, s->ataque_head_boss);
}

void liberar_jogo(VariaveisInicioJogo *s){
    liberar_ataque(s->ataque_head2);
    liberar_ataque(s->ataque_head3);
    liberar_ataque(s->ataque_head4);
    liberar_ataque(s->ataque_head_boss);
    liberar_flor_dia(s->flor_dia_head1);
    liberar_flor_dia(s->flor_dia_head2);
    liberar_flor_noite(s->flor_noite_head1);
    liberar_flor_noite(s->flor_noite_head3);
    liberar_personagem(s->personagem_head);
    liberar_efeito(s->efeitos);
    free(s->elemento_atual);
    free(s->boss);

    UnloadRenderTexture(s->janela);
    UnloadTexture(s->quadro_roxo);
    UnloadTexture(s->quadro_roxo2);
    UnloadTexture(s->quadro_roxo3);
    UnloadTexture(s->quadro_vermelho);
    UnloadTexture(s->quadro_vermelho2);
    UnloadTexture(s->quadro_vermelho3);
    UnloadTexture(s->quadro_laranja);
    UnloadTexture(s->quadro_laranja2);
    UnloadTexture(s->quadro_laranja3);
    UnloadTexture(s->quadro_vinho);
    UnloadTexture(s->quadro_vinho2);
    UnloadTexture(s->quadro_vinho3);
    UnloadTexture(s->boss_dia_f1);
    UnloadTexture(s->boss_dia_f2);
    UnloadTexture(s->boss_dia_f3);
    UnloadTexture(s->boss_ataque_dia); 
    UnloadTexture(s->quadro_roxo_noite);
    UnloadTexture(s->quadro_roxo2_noite);
    UnloadTexture(s->quadro_roxo3_noite);
    UnloadTexture(s->quadro_vermelho_noite);
    UnloadTexture(s->quadro_vermelho2_noite);
    UnloadTexture(s->quadro_vermelho3_noite);
    UnloadTexture(s->quadro_laranja_noite);
    UnloadTexture(s->quadro_laranja2_noite);
    UnloadTexture(s->quadro_laranja3_noite);
    UnloadTexture(s->quadro_vinho_noite);
    UnloadTexture(s->quadro_vinho2_noite);
    UnloadTexture(s->quadro_vinho3_noite);
    UnloadTexture(s->boss_noite_f1);
    UnloadTexture(s->boss_noite_f2);
    UnloadTexture(s->boss_noite_f3);
    UnloadTexture(s->boss_ataque_noite);
    UnloadTexture(s->boss_acertar);
    UnloadTexture(s->boss_coracao);
    UnloadTexture(s->olho1);
    UnloadTexture(s->olho2);
    UnloadTexture(s->olho3);
    UnloadTexture(s->proj_agua);
    UnloadTexture(s->proj_ar);
    UnloadTexture(s->proj_corte);
    UnloadTexture(s->proj_eletricidade);
    UnloadTexture(s->proj_fogo);
    UnloadTexture(s->proj_gelo);
    UnloadTexture(s->proj_impacto);
    UnloadTexture(s->proj_lunar);
    UnloadTexture(s->proj_perfuracao);
    UnloadTexture(s->proj_solar);
    UnloadTexture(s->proj_veneno);
    UnloadTexture(s->efeito_fogo);
    UnloadTexture(s->efeito_corte);
    UnloadTexture(s->efeito_gelo);
    UnloadTexture(s->relogio_dia);
    UnloadTexture(s->relogio_noite);
    UnloadTexture(s->borda);
    UnloadTexture(s->borda_escolhido);
    UnloadTexture(s->caixa);
    UnloadTexture(s->noite);
    UnloadTexture(s->BG);
    UnloadTexture(s->BG_noite);
    UnloadFont(s->fonte);
    UnloadMusicStream(s->batalha);
    UnloadMusicStream(s->batalha2);
    CloseAudioDevice();
}