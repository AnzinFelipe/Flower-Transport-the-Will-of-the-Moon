#include "raylib.h"
#include "escolhas_primarias.h"
#include "escolhas_secundarias.h"
#include "projeteis.h"
#include "boss.h"
#include "acao.h"
#include "screens.h" 
#include <stdlib.h>
#include <math.h>

int main(void) {
    int largura = 1600, altura = 900;

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);
    InitWindow(largura, altura, "Flower Transport - the Will of the Moon");

    GameScreen currentScreen = SCREEN_MENU;
    
    RenderTexture2D janela;
    Music pink;
    Texture2D BG, BG_noite, noite, relogio_dia, relogio_noite, borda_escolhido, borda, caixa;
    Texture2D quadro_roxo, quadro_roxo_noite, quadro_vermelho, quadro_vermelho_noite;
    Texture2D quadro_laranja, quadro_laranja_noite, quadro_vinho, quadro_vinho_noite;
    Texture2D quadro_roxo2, quadro_roxo2_noite, quadro_vermelho2, quadro_vermelho2_noite;
    Texture2D quadro_laranja2, quadro_laranja2_noite, quadro_vinho2, quadro_vinho2_noite;
    Texture2D quadro_roxo3, quadro_roxo3_noite, quadro_vermelho3, quadro_vermelho3_noite;
    Texture2D quadro_laranja3, quadro_laranja3_noite, quadro_vinho3, quadro_vinho3_noite;
    Texture2D boss_dia_f1, boss_dia_f2, boss_dia_f3, boss_noite_f1, boss_noite_f2, boss_noite_f3;
    Texture2D boss_acertar, boss_coracao, boss_ataque_dia, boss_ataque_noite;
    Texture2D proj_agua, proj_ar, proj_corte, proj_eletricidade, proj_fogo, proj_gelo, proj_impacto, proj_lunar, proj_perfuracao, proj_solar, proj_veneno;
    int escolhas, escolha_flores_diurnas, escolha_flores_noturnas, escolha_ataques, defender;
    int escolhido, inicio_escolhas_secundarios, personagem_num, vez_inimigo, horario, energia_sobra;
    int momento_atacar, verificar_ataque, ataque_apertado, acertou_ataque;
    int projetil_ataque, projetil_flor_diurna, projetil_flor_noturna;
    int p0_morto, p1_morto, p2_morto, p3_morto;
    int ir_coracao, voltar_coracao;
    char *elemento_atual;
    Personagem *personagem_atual = NULL;
    float velocidade_atual;
    float largura_coracao, altura_proj;
    float pode_apertar, delay;
    float ataque_boss_tempo, delay_ataque_boss;
    float boss_animado, delay_boss_animado;
    Color vida_cor, energia_cor;
    Ataque *ataque_head2 = NULL, *ataque_head3 = NULL, *ataque_head4 = NULL, *ataque_head_boss = NULL;
    Flor_dia *flor_dia_head1 = NULL, *flor_dia_head2 = NULL;
    Flor_noite *flor_noite_head1 = NULL, *flor_noite_head3 = NULL;
    Personagem *personagem_head = NULL;
    Boss *boss = NULL;
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        switch (currentScreen) {
            case SCREEN_EXIT:
                CloseWindow();
                return 0;
            case SCREEN_MENU:
                currentScreen = RunMenu();
                if (currentScreen == SCREEN_GAME) {
                    // Inicializa todas as variáveis do jogo se entrar na tela de jogo
                    janela = LoadRenderTexture(largura, altura);
                    SetTextureFilter(janela.texture, TEXTURE_FILTER_TRILINEAR);
                    
                    InitAudioDevice();
                    pink = LoadMusicStream("assets/music/Pink.mp3");
                    PlayMusicStream(pink);
                    

                    BG = LoadTexture("assets/images/BG.png");
                    GenTextureMipmaps(&BG);
                    SetTextureFilter(BG, TEXTURE_FILTER_TRILINEAR);
                    BG_noite = LoadTexture("assets/images/BG_noite.png");
                    GenTextureMipmaps(&BG_noite);
                    SetTextureFilter(BG_noite, TEXTURE_FILTER_TRILINEAR);

                    noite = LoadTexture("assets/images/Noite.png");
                    GenTextureMipmaps(&noite);
                    SetTextureFilter(noite, TEXTURE_FILTER_TRILINEAR);

                    relogio_dia = LoadTexture("assets/images/Relogio_dia.png");
                    GenTextureMipmaps(&relogio_dia);
                    SetTextureFilter(relogio_dia, TEXTURE_FILTER_TRILINEAR);
                    relogio_noite = LoadTexture("assets/images/Relogio_noite.png");
                    GenTextureMipmaps(&relogio_noite);
                    SetTextureFilter(relogio_noite, TEXTURE_FILTER_TRILINEAR);

                    borda_escolhido = LoadTexture("assets/images/Borda.png");
                    GenTextureMipmaps(&borda_escolhido);
                    SetTextureFilter(borda_escolhido, TEXTURE_FILTER_TRILINEAR);
                    borda = LoadTexture("assets/images/Borda2.png");
                    GenTextureMipmaps(&borda);
                    SetTextureFilter(borda, TEXTURE_FILTER_TRILINEAR);
                    caixa = LoadTexture("assets/images/Caixa.png");
                    GenTextureMipmaps(&caixa);
                    SetTextureFilter(caixa, TEXTURE_FILTER_TRILINEAR);

                    quadro_roxo = LoadTexture("assets/images/roxo/Roxo1.png");
                    GenTextureMipmaps(&quadro_roxo);
                    SetTextureFilter(quadro_roxo, TEXTURE_FILTER_TRILINEAR);
                    quadro_roxo_noite = LoadTexture("assets/images/roxo/Roxo1_noite.png");
                    GenTextureMipmaps(&quadro_roxo_noite);
                    SetTextureFilter(quadro_roxo_noite, TEXTURE_FILTER_TRILINEAR);
                    quadro_roxo2 = LoadTexture("assets/images/roxo/Roxo2.png");
                    GenTextureMipmaps(&quadro_roxo2);
                    SetTextureFilter(quadro_roxo2, TEXTURE_FILTER_TRILINEAR);
                    quadro_roxo2_noite = LoadTexture("assets/images/roxo/Roxo2_noite.png");
                    GenTextureMipmaps(&quadro_roxo2_noite);
                    SetTextureFilter(quadro_roxo2_noite, TEXTURE_FILTER_TRILINEAR);
                    quadro_roxo3 = LoadTexture("assets/images/roxo/Roxo3.png");
                    GenTextureMipmaps(&quadro_roxo3);
                    SetTextureFilter(quadro_roxo3, TEXTURE_FILTER_TRILINEAR);
                    quadro_roxo3_noite = LoadTexture("assets/images/roxo/Roxo3_noite.png");
                    GenTextureMipmaps(&quadro_roxo3_noite);
                    SetTextureFilter(quadro_roxo3_noite, TEXTURE_FILTER_TRILINEAR);

                    quadro_vermelho = LoadTexture("assets/images/vermelho/Vermelho1.png");
                    GenTextureMipmaps(&quadro_vermelho);
                    SetTextureFilter(quadro_vermelho, TEXTURE_FILTER_TRILINEAR);
                    quadro_vermelho_noite = LoadTexture("assets/images/vermelho/Vermelho1_noite.png");
                    GenTextureMipmaps(&quadro_vermelho_noite);
                    SetTextureFilter(quadro_vermelho_noite, TEXTURE_FILTER_TRILINEAR);
                    quadro_vermelho2 = LoadTexture("assets/images/vermelho/Vermelho2.png");
                    GenTextureMipmaps(&quadro_vermelho2);
                    SetTextureFilter(quadro_vermelho2, TEXTURE_FILTER_TRILINEAR);
                    quadro_vermelho2_noite = LoadTexture("assets/images/vermelho/Vermelho2_noite.png");
                    GenTextureMipmaps(&quadro_vermelho2_noite);
                    SetTextureFilter(quadro_vermelho2_noite, TEXTURE_FILTER_TRILINEAR);
                    quadro_vermelho3 = LoadTexture("assets/images/vermelho/Vermelho3.png");
                    GenTextureMipmaps(&quadro_vermelho3);
                    SetTextureFilter(quadro_vermelho3, TEXTURE_FILTER_TRILINEAR);
                    quadro_vermelho3_noite = LoadTexture("assets/images/vermelho/Vermelho3_noite.png");
                    GenTextureMipmaps(&quadro_vermelho3_noite);
                    SetTextureFilter(quadro_vermelho3_noite, TEXTURE_FILTER_TRILINEAR);

                    quadro_laranja = LoadTexture("assets/images/laranja/Laranja1.png");
                    GenTextureMipmaps(&quadro_laranja);
                    SetTextureFilter(quadro_laranja, TEXTURE_FILTER_TRILINEAR);
                    quadro_laranja_noite = LoadTexture("assets/images/laranja/Laranja1_noite.png");
                    GenTextureMipmaps(&quadro_laranja_noite);
                    SetTextureFilter(quadro_laranja_noite, TEXTURE_FILTER_TRILINEAR);
                    quadro_laranja2 = LoadTexture("assets/images/laranja/Laranja2.png");
                    GenTextureMipmaps(&quadro_laranja2);
                    SetTextureFilter(quadro_laranja2, TEXTURE_FILTER_TRILINEAR);
                    quadro_laranja2_noite = LoadTexture("assets/images/laranja/Laranja2_noite.png");
                    GenTextureMipmaps(&quadro_laranja2_noite);
                    SetTextureFilter(quadro_laranja2_noite, TEXTURE_FILTER_TRILINEAR);
                    quadro_laranja3 = LoadTexture("assets/images/laranja/Laranja3.png");
                    GenTextureMipmaps(&quadro_laranja3);
                    SetTextureFilter(quadro_laranja3, TEXTURE_FILTER_TRILINEAR);
                    quadro_laranja3_noite = LoadTexture("assets/images/laranja/Laranja3_noite.png");
                    GenTextureMipmaps(&quadro_laranja3_noite);
                    SetTextureFilter(quadro_laranja3_noite, TEXTURE_FILTER_TRILINEAR);

                    quadro_vinho = LoadTexture("assets/images/vinho/Vinho1.png");
                    GenTextureMipmaps(&quadro_vinho);
                    SetTextureFilter(quadro_vinho, TEXTURE_FILTER_TRILINEAR);
                    quadro_vinho_noite = LoadTexture("assets/images/vinho/Vinho1_noite.png");
                    GenTextureMipmaps(&quadro_vinho_noite);
                    SetTextureFilter(quadro_vinho_noite, TEXTURE_FILTER_TRILINEAR);
                    quadro_vinho2 = LoadTexture("assets/images/vinho/Vinho2.png");
                    GenTextureMipmaps(&quadro_vinho2);
                    SetTextureFilter(quadro_vinho2, TEXTURE_FILTER_TRILINEAR);
                    quadro_vinho2_noite = LoadTexture("assets/images/vinho/Vinho2_noite.png");
                    GenTextureMipmaps(&quadro_vinho2_noite);
                    SetTextureFilter(quadro_vinho2_noite, TEXTURE_FILTER_TRILINEAR);
                    quadro_vinho3 = LoadTexture("assets/images/vinho/Vinho3.png");
                    GenTextureMipmaps(&quadro_vinho3);
                    SetTextureFilter(quadro_vinho3, TEXTURE_FILTER_TRILINEAR);
                    quadro_vinho3_noite = LoadTexture("assets/images/vinho/Vinho3_noite.png");
                    GenTextureMipmaps(&quadro_vinho3_noite);
                    SetTextureFilter(quadro_vinho3_noite, TEXTURE_FILTER_TRILINEAR);

                    boss_dia_f1 = LoadTexture("assets/images/boss/Boss_dia_f1.png");
                    GenTextureMipmaps(&boss_dia_f1);
                    SetTextureFilter(boss_dia_f1, TEXTURE_FILTER_TRILINEAR);
                    boss_noite_f1 = LoadTexture("assets/images/boss/Boss_noite_f1.png");
                    GenTextureMipmaps(&boss_noite_f1);
                    SetTextureFilter(boss_noite_f1, TEXTURE_FILTER_TRILINEAR);
                    boss_dia_f2 = LoadTexture("assets/images/boss/Boss_dia_f2.png");
                    GenTextureMipmaps(&boss_dia_f2);
                    SetTextureFilter(boss_dia_f2, TEXTURE_FILTER_TRILINEAR);
                    boss_noite_f2 = LoadTexture("assets/images/boss/Boss_noite_f2.png");
                    GenTextureMipmaps(&boss_noite_f2);
                    SetTextureFilter(boss_noite_f2, TEXTURE_FILTER_TRILINEAR);
                    boss_dia_f3 = LoadTexture("assets/images/boss/Boss_dia_f3.png");
                    GenTextureMipmaps(&boss_dia_f3);
                    SetTextureFilter(boss_dia_f3, TEXTURE_FILTER_TRILINEAR);
                    boss_noite_f3 = LoadTexture("assets/images/boss/Boss_noite_f3.png");
                    GenTextureMipmaps(&boss_noite_f3);
                    SetTextureFilter(boss_noite_f3, TEXTURE_FILTER_TRILINEAR);

                    boss_acertar = LoadTexture("assets/images/boss/Boss_acertar.png");
                    GenTextureMipmaps(&boss_acertar);
                    SetTextureFilter(boss_acertar, TEXTURE_FILTER_TRILINEAR);
                    boss_coracao = LoadTexture("assets/images/boss/Boss_coracao.png");
                    GenTextureMipmaps(&boss_coracao);
                    SetTextureFilter(boss_coracao, TEXTURE_FILTER_TRILINEAR);

                    boss_ataque_dia = LoadTexture("assets/images/boss/Boss_ataque_dia.png");
                    GenTextureMipmaps(&boss_ataque_dia);
                    SetTextureFilter(boss_ataque_dia, TEXTURE_FILTER_TRILINEAR);
                    boss_ataque_noite = LoadTexture("assets/images/boss/Boss_ataque_noite.png");
                    GenTextureMipmaps(&boss_ataque_noite);
                    SetTextureFilter(boss_ataque_noite, TEXTURE_FILTER_TRILINEAR);

                    proj_agua = LoadTexture("assets/images/projeteis/Agua.png");
                    GenTextureMipmaps(&proj_agua);
                    SetTextureFilter(proj_agua, TEXTURE_FILTER_TRILINEAR);
                    proj_ar = LoadTexture("assets/images/projeteis/Ar.png");
                    GenTextureMipmaps(&proj_ar);
                    SetTextureFilter(proj_ar, TEXTURE_FILTER_TRILINEAR);
                    proj_corte = LoadTexture("assets/images/projeteis/Corte.png");
                    GenTextureMipmaps(&proj_corte);
                    SetTextureFilter(proj_corte, TEXTURE_FILTER_TRILINEAR);
                    proj_eletricidade = LoadTexture("assets/images/projeteis/Eletricidade.png");
                    GenTextureMipmaps(&proj_eletricidade);
                    SetTextureFilter(proj_eletricidade, TEXTURE_FILTER_TRILINEAR);
                    proj_fogo = LoadTexture("assets/images/projeteis/Fogo.png");
                    GenTextureMipmaps(&proj_fogo);
                    SetTextureFilter(proj_fogo, TEXTURE_FILTER_TRILINEAR);
                    proj_gelo = LoadTexture("assets/images/projeteis/Gelo.png");
                    GenTextureMipmaps(&proj_gelo);
                    SetTextureFilter(proj_gelo, TEXTURE_FILTER_TRILINEAR);
                    proj_impacto = LoadTexture("assets/images/projeteis/Impacto.png");
                    GenTextureMipmaps(&proj_impacto);
                    SetTextureFilter(proj_impacto, TEXTURE_FILTER_TRILINEAR);
                    proj_lunar = LoadTexture("assets/images/projeteis/Lunar.png");
                    GenTextureMipmaps(&proj_lunar);
                    SetTextureFilter(proj_lunar, TEXTURE_FILTER_TRILINEAR);
                    proj_perfuracao = LoadTexture("assets/images/projeteis/Perfuracao.png");
                    GenTextureMipmaps(&proj_perfuracao);
                    SetTextureFilter(proj_perfuracao, TEXTURE_FILTER_TRILINEAR);
                    proj_solar = LoadTexture("assets/images/projeteis/Solar.png");
                    GenTextureMipmaps(&proj_solar);
                    SetTextureFilter(proj_solar, TEXTURE_FILTER_TRILINEAR);
                    proj_veneno = LoadTexture("assets/images/projeteis/Veneno.png");
                    GenTextureMipmaps(&proj_veneno);
                    SetTextureFilter(proj_veneno, TEXTURE_FILTER_TRILINEAR);

                    escolhas = 1; escolha_flores_diurnas = 0; escolha_flores_noturnas = 0; escolha_ataques = 0; defender = 0;
                    escolhido = 0; inicio_escolhas_secundarios = 0; personagem_num = 0; vez_inimigo = 0; horario = 0;
                    personagem_atual = NULL;
                    p0_morto = 0, p1_morto = 0; p2_morto = 0; p3_morto = 0;
                    momento_atacar = 0, verificar_ataque = 0, ataque_apertado = 0, acertou_ataque = 0;
                    projetil_ataque = 0, projetil_flor_diurna = 0, projetil_flor_noturna = 0;
                    ir_coracao = 0, voltar_coracao = 0;
                    largura_coracao = 0, altura_proj = 0;
                    elemento_atual = (char *)malloc(20);
                    velocidade_atual = 0;
                    energia_sobra = 0;
                    pode_apertar = 0.0; delay = 0.1;
                    ataque_boss_tempo = 0.0; delay_ataque_boss = 2;
                    boss_animado = 0.0; delay_boss_animado = 0.4;
                    vida_cor = (Color){120, 18, 18, 255};
                    energia_cor = (Color){18, 120, 80, 255};
                    
                    ataque_head2 = NULL;
                    adicionar_ataque(&ataque_head2, "Soco", 20, "Impacto", 5, 1.5, "");
                    adicionar_ataque(&ataque_head2, "Chute", 15, "Impacto", 5, 1.0, "");
                    adicionar_ataque(&ataque_head2, "Pa de jardinagem", 30, "Impacto", 10, 1.5, "");
                    adicionar_ataque(&ataque_head2, "Tesoura de poda", 25, "Corte", 10, 1.5, "");

                    ataque_head3 = NULL;
                    adicionar_ataque(&ataque_head3, "Soco", 15, "Impacto", 5, 2.0, "");
                    adicionar_ataque(&ataque_head3, "Unhada", 10, "Corte", 3, 2.5, "");
                    adicionar_ataque(&ataque_head3, "Chute espiral", 25, "Perfuracao", 15, 2.0, "");
                    adicionar_ataque(&ataque_head3, "Chifrada", 30, "Perfuracao", 20, 1.5, "");

                    ataque_head4 = NULL;
                    adicionar_ataque(&ataque_head4, "Soco solar", 35, "Impacto", 0, 2.0, "");
                    adicionar_ataque(&ataque_head4, "Chute solar", 35, "Impacto", 0, 1.5, "");
                    adicionar_ataque(&ataque_head4, "Lanca solar", 30, "Perfuracao", 0, 2.5, "");
                    adicionar_ataque(&ataque_head4, "Espada solar", 30, "Corte", 0, 1.0, "");
                    adicionar_ataque(&ataque_head4, "Fumaca venenosa", 10, "Veneno", 0, 1.0, "");

                    ataque_head_boss = NULL;
                    adicionar_ataque(&ataque_head_boss, "Bafo lunar", 200, "Fogo", 0, 0, "");
                    adicionar_ataque(&ataque_head_boss, "Chute dilacerante", 200, "Corte", 0, 0, "");
                    adicionar_ataque(&ataque_head_boss, "Espectro lunatico", 200, "Lunar", 0, 0, "");
                    adicionar_ataque(&ataque_head_boss, "Olhar sombrio", 200, "Lunar", 0, 0, "");
                    
                    flor_dia_head1 = NULL;
                    adicionar_flor_dia(&flor_dia_head1, "Flamigera-do-dia", 25, "Fogo", 15, 1.5, "");
                    adicionar_flor_dia(&flor_dia_head1, "Tulipa afiada", 10, "Corte", 15, 1.5, "");
                    adicionar_flor_dia(&flor_dia_head1, "Orquidea voltaica", 20, "Eletricidade", 15, 2.5, "");
                    adicionar_flor_dia(&flor_dia_head1, "Nenufar real", 15, "Agua", 15, 1.5, "");
                    adicionar_flor_dia(&flor_dia_head1, "Girassol", 20, "Solar", 15, 2.0, "");
                    adicionar_flor_dia(&flor_dia_head1, "Ventanilia", 15, "Ar", 15, 2.5, "");

                    flor_dia_head2 = NULL;
                    adicionar_flor_dia(&flor_dia_head2, "Rosa gelida", 15, "Gelo", 15, 1.0, "");
                    adicionar_flor_dia(&flor_dia_head2, "Helicopdea", 10, "Ar", 15, 2.5, "");
                    adicionar_flor_dia(&flor_dia_head2, "Girassol", 20, "Solar", 15, 2.0, "");
                    adicionar_flor_dia(&flor_dia_head2, "Gravitiana", 20, "Impacto", 15, 1.0, "");
                    adicionar_flor_dia(&flor_dia_head2, "Lotus", 15, "Agua", 15, 2.0, "");

                    flor_noite_head1 = NULL;
                    adicionar_flor_noite(&flor_noite_head1, "Rosa cromada", 20, "Impacto", 10, 1.0, "");
                    adicionar_flor_noite(&flor_noite_head1, "Rainha-da-noite", 20, "Fogo", 10, 2.0, "");
                    adicionar_flor_noite(&flor_noite_head1, "Realeza espinhenta", 15, "Perfuracao", 10, 2.5, "");
                    adicionar_flor_noite(&flor_noite_head1, "Flor de Mandacaru", 20, "Agua", 10, 1.5, "");
                    adicionar_flor_noite(&flor_noite_head1, "Trombeta-de-anjo", 15, "Veneno", 10, 1.5, "");
                    adicionar_flor_noite(&flor_noite_head1, "Gloria-da-friagem", 20, "Gelo", 10, 1.5, "");

                    flor_noite_head3 = NULL;
                    adicionar_flor_noite(&flor_noite_head3, "Dama-da-noite", 20, "Lunar", 10, 2.0, "");
                    adicionar_flor_noite(&flor_noite_head3, "Flamigera-da-noite", 25, "Fogo", 10, 1.5, "");
                    adicionar_flor_noite(&flor_noite_head3, "Realeza espinhenta", 15, "Perfuracao", 10, 2.5, "");
                    adicionar_flor_noite(&flor_noite_head3, "Gloria-da-friagem", 20, "Gelo", 10, 1.5, "");
                    adicionar_flor_noite(&flor_noite_head3, "Energialida", 15, "Eletricidade", 10, 2.5, "");

                    personagem_head = NULL;
                    adicionar_personagem(&personagem_head, "Roxo", 100, 80, NULL, flor_dia_head1, flor_noite_head1);
                    adicionar_personagem(&personagem_head, "Vermelho", 150, 40, ataque_head2, flor_dia_head2, NULL);
                    adicionar_personagem(&personagem_head, "Laranja", 80, 80, ataque_head3, NULL, flor_noite_head3);
                    adicionar_personagem(&personagem_head, "Verde", 100, 0, ataque_head4, NULL, NULL);
                    
                    adicionar_vantagens_desvantagens_personagem(&personagem_head, 0);
                    adicionar_vantagens_desvantagens_personagem(&personagem_head, 1);
                    adicionar_vantagens_desvantagens_personagem(&personagem_head, 2);
                    adicionar_vantagens_desvantagens_personagem(&personagem_head, 3);
                    
                    boss = (Boss *)malloc(sizeof(Boss));
                    adicionar_boss(&boss, ataque_head_boss);
                }
                break; 
            case SCREEN_GAME:
                UpdateMusicStream(pink);
                
                pode_apertar += GetFrameTime();
                ataque_boss_tempo += GetFrameTime();
                boss_animado += GetFrameTime();
                
                if (IsKeyPressed(KEY_F11) && pode_apertar >= delay) {
                    ToggleFullscreen();
                    pode_apertar = 0.0;
                }

                BeginTextureMode(janela);
                
                ClearBackground(BLACK);
                if (horario == 1) {
                    DrawTextureEx(BG_noite, (Vector2){0, 0}, 0.0, 1, WHITE);
                    DrawTextureEx(noite, (Vector2){0, 0}, 0.0, 1, WHITE);
                    DrawTextureEx(relogio_noite, (Vector2){0, 0}, 0.0, 0.5, WHITE);
                    if (vez_inimigo == 1) {
                        DrawTextureEx(boss_ataque_noite, (Vector2){0, 0}, 0.0, 1, WHITE);
                    } else {
                        if (momento_atacar == 1 || ataque_apertado == 1) {
                            DrawTextureEx(boss_acertar, (Vector2){0, 0}, 0.0, 1, WHITE);
                        } else {
                            if (boss_animado > delay_boss_animado * 4) {
                                DrawTextureEx(boss_noite_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                                boss_animado = 0.0;
                            } else if (boss_animado > delay_boss_animado * 3) {
                                DrawTextureEx(boss_noite_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else if (boss_animado > delay_boss_animado * 2) {
                                DrawTextureEx(boss_noite_f3, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else if (boss_animado > delay_boss_animado) {
                                DrawTextureEx(boss_noite_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else {
                                DrawTextureEx(boss_noite_f1, (Vector2){0, 0}, 0.0, 1, WHITE);
                            }
                        }
                    }
                    desenhar_personagem(personagem_head, 0, 100, quadro_roxo_noite, quadro_roxo2_noite, quadro_roxo3_noite);
                    desenhar_personagem(personagem_head, 1, 150, quadro_vermelho_noite, quadro_vermelho2_noite, quadro_vermelho3_noite);
                    desenhar_personagem(personagem_head, 2, 80, quadro_laranja_noite, quadro_laranja2_noite, quadro_laranja3_noite);
                    desenhar_personagem(personagem_head, 3, 100, quadro_vinho_noite, quadro_vinho2_noite, quadro_vinho3_noite);   
                } else if (horario == 0) {
                    DrawTextureEx(BG, (Vector2){0, 0}, 0.0, 1, GRAY);
                    DrawTextureEx(relogio_dia, (Vector2){0, 0}, 0.0, 0.5, WHITE);
                    if (vez_inimigo == 1) {
                        DrawTextureEx(boss_ataque_dia, (Vector2){0, 0}, 0.0, 1, WHITE);
                    } else {
                        if (momento_atacar == 1 || ataque_apertado == 1) {
                            DrawTextureEx(boss_acertar, (Vector2){0, 0}, 0.0, 1, WHITE);
                        } else {
                            if (boss_animado > delay_boss_animado * 4) {
                                DrawTextureEx(boss_dia_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                                boss_animado = 0.0;
                            } else if (boss_animado > delay_boss_animado * 3) {
                                DrawTextureEx(boss_dia_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else if (boss_animado > delay_boss_animado * 2) {
                                DrawTextureEx(boss_dia_f3, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else if (boss_animado > delay_boss_animado) {
                                DrawTextureEx(boss_dia_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else {
                                DrawTextureEx(boss_dia_f1, (Vector2){0, 0}, 0.0, 1, WHITE);
                            }
                        }
                    }
                    desenhar_personagem(personagem_head, 0, 100, quadro_roxo, quadro_roxo2, quadro_roxo3);
                    desenhar_personagem(personagem_head, 1, 150, quadro_vermelho, quadro_vermelho2, quadro_vermelho3);
                    desenhar_personagem(personagem_head, 2, 80, quadro_laranja, quadro_laranja2, quadro_laranja3);
                    desenhar_personagem(personagem_head, 3, 100, quadro_vinho, quadro_vinho2, quadro_vinho3); 
                }           
                desenhar_vida_personagens(personagem_head, 0, vida_cor);
                desenhar_energia_personagens(personagem_head, 0, energia_cor);
                desenhar_vida_personagens(personagem_head, 1, vida_cor);
                desenhar_energia_personagens(personagem_head, 1, energia_cor);
                desenhar_vida_personagens(personagem_head, 2, vida_cor);
                desenhar_energia_personagens(personagem_head, 2, energia_cor);
                desenhar_vida_personagens(personagem_head, 3, vida_cor);
                desenhar_energia_personagens(personagem_head, 3, energia_cor);
                desenhar_vida_boss(boss, largura, vida_cor);
                DrawTextureEx(borda, (Vector2){0, 600}, 0.0, 0.5, GRAY);
                DrawTextureEx(borda, (Vector2){400, 600}, 0.0, 0.5, GRAY);
                DrawTextureEx(borda, (Vector2){800, 600}, 0.0, 0.5, GRAY);
                DrawTextureEx(borda, (Vector2){1200, 600}, 0.0, 0.5, GRAY);
                if (vez_inimigo == 1) {
                    // Nada pra nao ter borda de escolhido
                } else if (personagem_num == 0) {
                    DrawTextureEx(borda_escolhido, (Vector2){0, 600}, 0.0, 0.5, WHITE);
                } else if (personagem_num == 1) {
                    DrawTextureEx(borda_escolhido, (Vector2){400, 600}, 0.0, 0.5, WHITE);
                } else if (personagem_num == 2) {
                    DrawTextureEx(borda_escolhido, (Vector2){800, 600}, 0.0, 0.5, WHITE);
                } else if (personagem_num == 3) {
                    DrawTextureEx(borda_escolhido, (Vector2){1200, 600}, 0.0, 0.5, WHITE);
                }
                
                //Vez do inimigo ou vez do jogador
                if (vez_inimigo == 1) {
                    if (ataque_boss_tempo >= delay_ataque_boss) {
                        ataque_boss(boss, &personagem_head, &p0_morto, &p1_morto, &p2_morto, &p3_morto);
                        vez_inimigo = 0;
                        personagem_num = 0;
                        escolhas = 1;
                        pode_apertar = 0.0;
                        boss_animado = 0.0;
                        // 0 - dia, 1 - noite
                        if (horario == 0) {
                            horario  = 1;
                        } else if (horario == 1) {
                            horario = 0;
                        }
                        if(currentScreen == SCREEN_GAME && p0_morto == 1 && p1_morto == 1 && p2_morto == 1 && p3_morto == 1){
                            currentScreen = SCREEN_GAMEOVER;
                        }
                    }
                } else {
                    // Vez do player
                    
                    //Escolhas primarias de cada personagem
                    if (escolhas == 1 && personagem_num == 0) {
                        //Personagem 0
                        pegar_personagem(personagem_num, &personagem_atual, personagem_head);
                
                        personagem_atual->defesa = 0;

                        if (personagem_atual->vida == 0) {
                            personagem_num++;
                            pode_apertar = 0.0;
                            continue;
                        }
                
                        mudar_escolha_primaria(&escolhido, personagem_num, &pode_apertar, &delay);
                        
                        desenhar_escolhas_primarias(escolhido, personagem_num, largura, altura, horario);
                        
                        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                            if (escolhido == 0) {
                                if (horario == 0) {
                                    escolha_flores_diurnas = 1;    
                                    escolhas = 0;
                                    escolhido = 0;
                                }
                            } else if (escolhido == 1) {
                                if (horario == 1) {
                                    escolha_flores_noturnas = 1;    
                                    escolhas = 0;
                                    escolhido = 0;
                                }
                            } else if (escolhido == 2) {
                                defender = 1;
                                escolhas = 0;
                                escolhido = 0;
                            }
                            pode_apertar = 0.0;
                        }
                
                    } else if (escolhas == 1 && personagem_num == 1) {
                        //Personagem 1
                        pegar_personagem(personagem_num, &personagem_atual, personagem_head);
                
                        personagem_atual->defesa = 0;

                        if (personagem_atual->vida == 0) {
                            personagem_num++;
                            pode_apertar = 0.0;
                            continue;
                        }
                
                        mudar_escolha_primaria(&escolhido, personagem_num, &pode_apertar, &delay);
                        
                        desenhar_escolhas_primarias(escolhido, personagem_num, largura, altura, horario);
                        
                        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                            if (escolhido == 0) {
                                escolha_ataques = 1;
                                escolhas = 0;
                                escolhido = 0;    
                            } else if (escolhido == 1) {
                                if (horario == 0) {
                                    escolha_flores_diurnas = 1;
                                    escolhas = 0;
                                    escolhido = 0;
                                }
                            } else if (escolhido == 2) {
                                defender = 1;
                                escolhas = 0;
                                escolhido = 0;
                            }
                            pode_apertar = 0.0;
                        }
                    } else if (escolhas == 1 && personagem_num == 2) {
                        //Personagem 2
                        pegar_personagem(personagem_num, &personagem_atual, personagem_head);
                
                        personagem_atual->defesa = 0;

                        if (personagem_atual->vida == 0) {
                            personagem_num++;
                            pode_apertar = 0.0;
                            continue;
                        }
                
                        mudar_escolha_primaria(&escolhido, personagem_num, &pode_apertar, &delay);
                
                        desenhar_escolhas_primarias(escolhido, personagem_num, largura, altura, horario);
                
                        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                            if (escolhido == 0) {
                                escolha_ataques = 1;
                                escolhas = 0;
                                escolhido = 0;   
                            } else if (escolhido == 1) {
                                if (horario == 1) {
                                    escolha_flores_noturnas = 1;
                                    escolhas = 0;
                                    escolhido = 0;
                                }
                            } else if (escolhido == 2) {
                                defender = 1;
                                escolhas = 0;
                                escolhido = 0;
                            }
                            pode_apertar = 0.0;
                        }
                    } else if (escolhas == 1 && personagem_num == 3) {
                        //Personagem 3
                        pegar_personagem(personagem_num, &personagem_atual, personagem_head);
                
                        personagem_atual->defesa = 0;

                        if (personagem_atual->vida == 0) {
                            personagem_num++;
                            pode_apertar = 0.0;
                            continue;
                        }
                
                        mudar_escolha_primaria(&escolhido, personagem_num, &pode_apertar, &delay);
                
                        desenhar_escolhas_primarias(escolhido, personagem_num, largura, altura, horario);
                
                        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                            if (escolhido == 0) {
                                escolha_ataques = 1;    
                            } else if (escolhido == 1) {
                                defender = 1;
                            }
                            escolhas = 0;
                            escolhido = 0;
                            pode_apertar = 0.0;
                        }
                    }
                    
                    //Escolhas secundarias
                    if (escolha_ataques == 1) {
                        //Escolha de ataques
                        inicio_escolhas_secundarios = 0;
                        mudar_escolha_secundaria(&escolhido, personagem_atual, escolha_flores_diurnas, escolha_flores_noturnas, escolha_ataques, &pode_apertar, &delay);
                        desenhar_escolhas_ataques(&escolhido, &inicio_escolhas_secundarios, personagem_atual, personagem_num, largura, altura, &energia_sobra, elemento_atual, &velocidade_atual);
                
                        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                            if (energia_sobra == 1) {
                                escolha_ataques = 0;
                                projetil_ataque = 1;
                                momento_atacar = 1;
                                largura_coracao = 200;
                                altura_proj = 515;
                                pode_apertar = 0.0;
                            }
                        }
                        if (IsKeyPressed(KEY_X) && pode_apertar >= delay) {
                            escolha_ataques = 0;
                            escolhas = 1;
                            escolhido = 0;
                            pode_apertar = 0.0;
                        }
                    }
                    if (escolha_flores_diurnas == 1) {
                        //Escolha de flores diurnas
                        inicio_escolhas_secundarios = 0;
                        mudar_escolha_secundaria(&escolhido, personagem_atual, escolha_flores_diurnas, escolha_flores_noturnas, escolha_ataques, &pode_apertar, &delay);
                        desenhar_escolhas_flores_dia(&escolhido, &inicio_escolhas_secundarios, personagem_atual, personagem_num, largura, altura, &energia_sobra, elemento_atual, &velocidade_atual);
                
                        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                            if (energia_sobra == 1) {
                                escolha_flores_diurnas = 0;
                                projetil_flor_diurna = 1;
                                momento_atacar = 1;
                                largura_coracao = 200;
                                altura_proj = 515;
                                pode_apertar = 0.0;
                            }
                        }
                        if (IsKeyPressed(KEY_X) && pode_apertar >= delay) {
                            escolha_flores_diurnas = 0;
                            escolhas = 1;
                            escolhido = 0;
                            pode_apertar = 0.0;
                        }
                    }
                    if (escolha_flores_noturnas == 1) {
                        //Escolha de flores noturnas
                        inicio_escolhas_secundarios = 0;
                        mudar_escolha_secundaria(&escolhido, personagem_atual, escolha_flores_diurnas, escolha_flores_noturnas, escolha_ataques, &pode_apertar, &delay);
                        desenhar_escolhas_flores_noite(&escolhido, &inicio_escolhas_secundarios, personagem_atual, personagem_num, largura, altura, &energia_sobra, elemento_atual, &velocidade_atual);
                
                        if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                            if (energia_sobra == 1) {
                                escolha_flores_noturnas= 0;
                                projetil_flor_noturna = 1;
                                momento_atacar = 1;
                                largura_coracao = 200;
                                altura_proj = 515;
                                pode_apertar = 0.0;
                            }
                        }
                        if (IsKeyPressed(KEY_X) && pode_apertar >= delay) {
                            escolha_flores_noturnas = 0;
                            escolhas = 1;
                            escolhido = 0;
                            pode_apertar = 0.0;
                        }
                    }
                    if (defender == 1) {
                        personagem_atual->defesa = 1;
                        defender = 0;
                        pode_apertar = 0.0;
                        if (personagem_num == 3) {
                            ataque_boss_tempo = 0.0;
                            vez_inimigo = 1;
                        } else {
                            personagem_atual->energia += GetRandomValue(10, 20);
                            if (personagem_num == 0 && personagem_atual->energia > 60) {
                                personagem_atual->energia = 80;
                            } else if (personagem_num == 1 && personagem_atual->energia > 80) {
                                personagem_atual->energia = 40;
                            } else if (personagem_num == 2 && personagem_atual->energia > 40) {
                                personagem_atual->energia = 80;
                            }
                            if (personagem_num == 2 && p3_morto == 1) {
                                ataque_boss_tempo = 0.0;
                                vez_inimigo = 1;
                            } else if (personagem_num == 1 && p2_morto == 1 && p3_morto == 1) {
                                ataque_boss_tempo = 0.0;
                                vez_inimigo = 1;
                            } else if (personagem_num == 0 && p1_morto == 1 && p2_morto == 1 && p3_morto == 1) {
                                ataque_boss_tempo = 0.0;
                                vez_inimigo = 1;
                            } else {
                                escolhas = 1;
                                personagem_num++;
                            }
                        }
                    }

                    if (momento_atacar == 1) {
                        desenhar_coracao(boss_coracao, largura_coracao);
                        desenhar_projetil(elemento_atual, altura_proj, proj_agua, proj_ar, proj_corte,
                            proj_eletricidade, proj_fogo, proj_gelo, proj_impacto, proj_lunar,
                            proj_perfuracao, proj_solar, proj_veneno);
                        if (largura_coracao == 1000) {
                            voltar_coracao = 1;
                            ir_coracao = 0;
                        } else if (largura_coracao == 200) {
                            voltar_coracao = 0;
                            ir_coracao = 1;
                        }
                        if (ir_coracao == 1) {
                            largura_coracao += 20;
                        } else if (voltar_coracao == 1) {
                            largura_coracao -= 20;
                        }
                        if (ataque_apertado == 1) {
                            altura_proj -= 20 * velocidade_atual;
                            // Verificar com colisao
                            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                                acertou_ataque = 1;
                                ataque_apertado = 0;
                                verificar_ataque = 1;
                                momento_atacar = 0;
                            }
                        } else if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                            ataque_apertado = 1;
                            pode_apertar = 0.0;
                        }
                    }
                    if (verificar_ataque == 1) {
                        acao(&escolhido, &personagem_atual, &boss, projetil_ataque, projetil_flor_diurna, projetil_flor_noturna, acertou_ataque);
                        projetil_ataque = 0;
                        projetil_flor_diurna = 0;
                        projetil_flor_noturna = 0;
                        escolhido = 0;
                        acertou_ataque = 0;
                        verificar_ataque = 0;
                        if (personagem_num == 3) {
                            ataque_boss_tempo = 0.0;
                            vez_inimigo = 1;
                        } else {
                            if (personagem_num == 2 && p3_morto == 1) {
                                ataque_boss_tempo = 0.0;
                                vez_inimigo = 1;
                            } else if (personagem_num == 1 && p2_morto == 1 && p3_morto == 1) {
                                ataque_boss_tempo = 0.0;
                                vez_inimigo = 1;
                            } else if (personagem_num == 0 && p1_morto == 1 && p2_morto == 1 && p3_morto == 1) {
                                ataque_boss_tempo = 0.0;
                                vez_inimigo = 1;
                            } else {
                                escolhas = 1;
                                personagem_num++;
                            }
                        }
                    }
                }

                EndTextureMode();
                
                BeginDrawing();

                int largura_nova = GetScreenWidth();
                int altura_nova = GetScreenHeight();

                float escala = fminf((float)largura_nova/largura, (float)altura_nova/altura);
                float largura_escala = largura * escala;
                float altura_escala = altura * escala;
                float offsetX = (largura_nova - largura_escala) / 2.0f;
                float offsetY = (altura_nova - altura_escala) / 2.0f;

                DrawTexturePro(janela.texture,
                        (Rectangle){ 0, 0, largura, -altura },
                        (Rectangle){ offsetX, offsetY, largura_escala, altura_escala },
                        (Vector2){ 0, 0 },
                        0.0,
                        WHITE);

                EndDrawing();
                break;
            
            case SCREEN_GAMEOVER:
                currentScreen = RunGameOver();
                break;
        }
    }

    if (currentScreen == SCREEN_GAME) {
        liberar_ataque(ataque_head2);
        liberar_ataque(ataque_head3);
        liberar_ataque(ataque_head4);
        liberar_ataque(ataque_head_boss);
        liberar_flor_dia(flor_dia_head1);
        liberar_flor_dia(flor_dia_head2);
        liberar_flor_noite(flor_noite_head1);
        liberar_flor_noite(flor_noite_head3);
        liberar_personagem(personagem_head);
        free(elemento_atual);
        free(boss);

        UnloadRenderTexture(janela);
        UnloadTexture(quadro_roxo);
        UnloadTexture(quadro_roxo2);
        UnloadTexture(quadro_roxo3);
        UnloadTexture(quadro_vermelho);
        UnloadTexture(quadro_vermelho2);
        UnloadTexture(quadro_vermelho3);
        UnloadTexture(quadro_laranja);
        UnloadTexture(quadro_laranja2);
        UnloadTexture(quadro_laranja3);
        UnloadTexture(quadro_vinho);
        UnloadTexture(quadro_vinho2);
        UnloadTexture(quadro_vinho3);
        UnloadTexture(boss_dia_f1);
        UnloadTexture(boss_dia_f2);
        UnloadTexture(boss_dia_f3);
        UnloadTexture(boss_ataque_dia); 
        UnloadTexture(quadro_roxo_noite);
        UnloadTexture(quadro_roxo2_noite);
        UnloadTexture(quadro_roxo3_noite);
        UnloadTexture(quadro_vermelho_noite);
        UnloadTexture(quadro_vermelho2_noite);
        UnloadTexture(quadro_vermelho3_noite);
        UnloadTexture(quadro_laranja_noite);
        UnloadTexture(quadro_laranja2_noite);
        UnloadTexture(quadro_laranja3_noite);
        UnloadTexture(quadro_vinho_noite);
        UnloadTexture(quadro_vinho2_noite);
        UnloadTexture(quadro_vinho3_noite);
        UnloadTexture(boss_noite_f1);
        UnloadTexture(boss_noite_f2);
        UnloadTexture(boss_noite_f3);
        UnloadTexture(boss_ataque_noite);
        UnloadTexture(boss_acertar);
        UnloadTexture(boss_coracao);
        UnloadTexture(proj_agua);
        UnloadTexture(proj_ar);
        UnloadTexture(proj_corte);
        UnloadTexture(proj_eletricidade);
        UnloadTexture(proj_fogo);
        UnloadTexture(proj_gelo);
        UnloadTexture(proj_impacto);
        UnloadTexture(proj_lunar);
        UnloadTexture(proj_perfuracao);
        UnloadTexture(proj_solar);
        UnloadTexture(proj_veneno);
        UnloadTexture(relogio_dia);
        UnloadTexture(relogio_noite);
        UnloadTexture(borda);
        UnloadTexture(borda_escolhido);
        UnloadTexture(caixa);
        UnloadTexture(noite);
        UnloadTexture(BG);
        UnloadTexture(BG_noite);
        UnloadMusicStream(pink);
        CloseAudioDevice();
    }

    CloseWindow();

    return 0;
}