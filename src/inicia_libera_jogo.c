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

    s->janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(s->janela.texture, TEXTURE_FILTER_TRILINEAR);
    
    if (!IsAudioDeviceReady()) {
        InitAudioDevice();
    }
    s->pink = LoadMusicStream("assets/music/Pink.mp3");
    PlayMusicStream(s->pink);
    

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
    s->pode_apertar = 0.0; s->delay = 0.1;
    s->ataque_boss_tempo = 0.0; s->delay_ataque_boss = 2;
    s->boss_animado = 0.0; s->delay_boss_animado = 0.4;
    s->vida_cor = (Color){120, 18, 18, 255};
    s->energia_cor = (Color){18, 120, 80, 255};
    s->colisao_teto = (Rectangle){0, 0, 1600, 1};

    adicionar_ataque(&s->ataque_head2, "Soco", 20, "Impacto", 5, 1.5, "");
    adicionar_ataque(&s->ataque_head2, "Chute", 15, "Impacto", 5, 1.0, "");
    adicionar_ataque(&s->ataque_head2, "Pa de jardinagem", 30, "Impacto", 10, 1.5, "");
    adicionar_ataque(&s->ataque_head2, "Tesoura de poda", 25, "Corte", 10, 1.5, "");

    adicionar_ataque(&s->ataque_head3, "Soco", 15, "Impacto", 5, 2.0, "");
    adicionar_ataque(&s->ataque_head3, "Unhada", 10, "Corte", 3, 2.5, "");
    adicionar_ataque(&s->ataque_head3, "Chute espiral", 25, "Perfuracao", 15, 2.0, "");
    adicionar_ataque(&s->ataque_head3, "Chifrada", 30, "Perfuracao", 20, 1.5, "");

    adicionar_ataque(&s->ataque_head4, "Soco solar", 35, "Impacto", 0, 2.0, "");
    adicionar_ataque(&s->ataque_head4, "Chute solar", 35, "Impacto", 0, 1.5, "");
    adicionar_ataque(&s->ataque_head4, "Lanca solar", 30, "Perfuracao", 0, 2.5, "");
    adicionar_ataque(&s->ataque_head4, "Espada solar", 30, "Corte", 0, 1.0, "");
    adicionar_ataque(&s->ataque_head4, "Fumaca venenosa", 10, "Veneno", 0, 1.0, "");

    adicionar_ataque(&s->ataque_head_boss, "Bafo lunar", 200, "Fogo", 0, 0, "");
    adicionar_ataque(&s->ataque_head_boss, "Chute dilacerante", 200, "Corte", 0, 0, "");
    adicionar_ataque(&s->ataque_head_boss, "Espectro lunatico", 200, "Lunar", 0, 0, "");
    adicionar_ataque(&s->ataque_head_boss, "Olhar sombrio", 200, "Lunar", 0, 0, "");

    adicionar_flor_dia(&s->flor_dia_head1, "Flamigera-do-dia", 25, "Fogo", 15, 1.5, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Tulipa afiada", 10, "Corte", 15, 1.5, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Orquidea voltaica", 20, "Eletricidade", 15, 2.5, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Nenufar real", 15, "Agua", 15, 1.5, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Girassol", 20, "Solar", 15, 2.0, "");
    adicionar_flor_dia(&s->flor_dia_head1, "Ventanilia", 15, "Ar", 15, 2.5, "");

    adicionar_flor_dia(&s->flor_dia_head2, "Rosa gelida", 15, "Gelo", 15, 1.0, "");
    adicionar_flor_dia(&s->flor_dia_head2, "Helicopdea", 10, "Ar", 15, 2.5, "");
    adicionar_flor_dia(&s->flor_dia_head2, "Girassol", 20, "Solar", 15, 2.0, "");
    adicionar_flor_dia(&s->flor_dia_head2, "Gravitiana", 20, "Impacto", 15, 1.0, "");
    adicionar_flor_dia(&s->flor_dia_head2, "Lotus", 15, "Agua", 15, 2.0, "");

    adicionar_flor_noite(&s->flor_noite_head1, "Rosa cromada", 20, "Impacto", 10, 1.0, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Rainha-da-noite", 20, "Fogo", 10, 2.0, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Realeza espinhenta", 15, "Perfuracao", 10, 2.5, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Flor de Mandacaru", 20, "Agua", 10, 1.5, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Trombeta-de-anjo", 15, "Veneno", 10, 1.5, "");
    adicionar_flor_noite(&s->flor_noite_head1, "Gloria-da-friagem", 20, "Gelo", 10, 1.5, "");

    adicionar_flor_noite(&s->flor_noite_head3, "Dama-da-noite", 20, "Lunar", 10, 2.0, "");
    adicionar_flor_noite(&s->flor_noite_head3, "Flamigera-da-noite", 25, "Fogo", 10, 1.5, "");
    adicionar_flor_noite(&s->flor_noite_head3, "Realeza espinhenta", 15, "Perfuracao", 10, 2.5, "");
    adicionar_flor_noite(&s->flor_noite_head3, "Gloria-da-friagem", 20, "Gelo", 10, 1.5, "");
    adicionar_flor_noite(&s->flor_noite_head3, "Energialida", 15, "Eletricidade", 10, 2.5, "");

    adicionar_personagem(&s->personagem_head, "Roxo", 100, 80, NULL, s->flor_dia_head1, s->flor_noite_head1);
    adicionar_personagem(&s->personagem_head, "Vermelho", 150, 40, s->ataque_head2, s->flor_dia_head2, NULL);
    adicionar_personagem(&s->personagem_head, "Laranja", 80, 80, s->ataque_head3, NULL, s->flor_noite_head3);
    adicionar_personagem(&s->personagem_head, "Verde", 100, 0, s->ataque_head4, NULL, NULL);

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
        UnloadTexture(s->relogio_dia);
        UnloadTexture(s->relogio_noite);
        UnloadTexture(s->borda);
        UnloadTexture(s->borda_escolhido);
        UnloadTexture(s->caixa);
        UnloadTexture(s->noite);
        UnloadTexture(s->BG);
        UnloadTexture(s->BG_noite);
        UnloadMusicStream(s->pink);
        CloseAudioDevice();
}