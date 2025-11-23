#include "raylib.h"
#include "escolhas_primarias.h"
#include "escolhas_secundarias.h"
#include "projeteis.h"
#include "boss.h"
#include "acao.h"
#include "screens.h" 
#include "inicia_libera_jogo.h"
#include <stdlib.h>
#include <math.h>


int main(void) {
    int largura = 1600, altura = 900;

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);
    InitWindow(largura, altura, "Flower Transport - the Will of the Moon");

    GameScreen currentScreen = SCREEN_MENU;

    VariaveisInicioJogo *jogo_iniciado = (VariaveisInicioJogo *)malloc(sizeof *jogo_iniciado);

    int derrotado;
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        switch (currentScreen) {
            case SCREEN_EXIT:
                    if (IsAudioDeviceReady()) {
                        CloseAudioDevice();
                    }
                CloseWindow();
                return 0;
            case SCREEN_MENU:
                currentScreen = RunMenu();
                break; 
            case SCREEN_CUTSCENE:
                currentScreen = RunCutscene();
                if (currentScreen == SCREEN_GAME) {
                    novo_jogo(jogo_iniciado, largura, altura);
                    derrotado = 0;
                    
                }
                break;
            case SCREEN_GAME:
                
                if(derrotado == 1){
                    novo_jogo(jogo_iniciado, largura, altura);
                    derrotado = 0;
                }

                UpdateMusicStream(jogo_iniciado->batalha);
                UpdateMusicStream(jogo_iniciado->batalha2);
                if (jogo_iniciado->horario == 0) {
                    SetMusicVolume(jogo_iniciado->batalha, 1);
                    SetMusicVolume(jogo_iniciado->batalha2, 0);
                } else if (jogo_iniciado->horario == 1) {
                    SetMusicVolume(jogo_iniciado->batalha, 0);
                    SetMusicVolume(jogo_iniciado->batalha2, 1);
                }
                
                jogo_iniciado->pode_apertar += GetFrameTime();
                jogo_iniciado->ataque_boss_tempo += GetFrameTime();
                jogo_iniciado->boss_animado += GetFrameTime();
                
                BeginTextureMode(jogo_iniciado->janela);
                
                ClearBackground(BLACK);
                if (jogo_iniciado->horario == 1) {
                    DrawTextureEx(jogo_iniciado->BG_noite, (Vector2){0, 0}, 0.0, 1, WHITE);
                    DrawTextureEx(jogo_iniciado->noite, (Vector2){0, 0}, 0.0, 1, WHITE);
                    if (jogo_iniciado->vez_inimigo == 1) {
                        DrawTextureEx(jogo_iniciado->boss_ataque_noite, (Vector2){0, 0}, 0.0, 1, WHITE);
                    } else {
                        if (jogo_iniciado->momento_atacar == 1 || jogo_iniciado->ataque_apertado == 1) {
                            DrawTextureEx(jogo_iniciado->boss_acertar, (Vector2){0, 0}, 0.0, 1, WHITE);
                        } else {
                            DrawTextureEx(jogo_iniciado->relogio_noite, (Vector2){0, 20}, 0.0, 0.5, WHITE);
                            DrawRectangle(1250, 50, 300, 375, (Color){0, 0, 0, 160});
                            DrawTextureEx(jogo_iniciado->caixa, (Vector2){1240, 40}, 0.0, 0.4, WHITE);
                            if (jogo_iniciado->boss_animado > jogo_iniciado->delay_boss_animado * 4) {
                                DrawTextureEx(jogo_iniciado->boss_noite_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                                jogo_iniciado->boss_animado = 0.0;
                            } else if (jogo_iniciado->boss_animado > jogo_iniciado->delay_boss_animado * 3) {
                                DrawTextureEx(jogo_iniciado->boss_noite_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else if (jogo_iniciado->boss_animado > jogo_iniciado->delay_boss_animado * 2) {
                                DrawTextureEx(jogo_iniciado->boss_noite_f3, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else if (jogo_iniciado->boss_animado > jogo_iniciado->delay_boss_animado) {
                                DrawTextureEx(jogo_iniciado->boss_noite_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else {
                                DrawTextureEx(jogo_iniciado->boss_noite_f1, (Vector2){0, 0}, 0.0, 1, WHITE);
                            }
                        }
                    }
                    desenhar_personagem(jogo_iniciado->personagem_head, 0, 100, jogo_iniciado->quadro_roxo_noite, jogo_iniciado->quadro_roxo2_noite, jogo_iniciado->quadro_roxo3_noite);
                    desenhar_personagem(jogo_iniciado->personagem_head, 1, 150, jogo_iniciado->quadro_vermelho_noite, jogo_iniciado->quadro_vermelho2_noite, jogo_iniciado->quadro_vermelho3_noite);
                    desenhar_personagem(jogo_iniciado->personagem_head, 2, 80, jogo_iniciado->quadro_laranja_noite, jogo_iniciado->quadro_laranja2_noite, jogo_iniciado->quadro_laranja3_noite);
                    desenhar_personagem(jogo_iniciado->personagem_head, 3, 100, jogo_iniciado->quadro_vinho_noite, jogo_iniciado->quadro_vinho2_noite, jogo_iniciado->quadro_vinho3_noite);   
                } else if (jogo_iniciado->horario == 0) {
                    DrawTextureEx(jogo_iniciado->BG, (Vector2){0, 0}, 0.0, 1, GRAY);
                    if (jogo_iniciado->vez_inimigo == 1) {
                        DrawTextureEx(jogo_iniciado->boss_ataque_dia, (Vector2){0, 0}, 0.0, 1, WHITE);
                    } else {
                        if (jogo_iniciado->momento_atacar == 1 || jogo_iniciado->ataque_apertado == 1) {
                            DrawTextureEx(jogo_iniciado->boss_acertar, (Vector2){0, 0}, 0.0, 1, WHITE);
                        } else {
                            DrawTextureEx(jogo_iniciado->relogio_dia, (Vector2){0, 20}, 0.0, 0.5, WHITE);
                            DrawRectangle(1250, 50, 300, 375, (Color){0, 0, 0, 160});
                            DrawTextureEx(jogo_iniciado->caixa, (Vector2){1240, 40}, 0.0, 0.4, WHITE);
                            if (jogo_iniciado->boss_animado > jogo_iniciado->delay_boss_animado * 4) {
                                DrawTextureEx(jogo_iniciado->boss_dia_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                                jogo_iniciado->boss_animado = 0.0;
                            } else if (jogo_iniciado->boss_animado > jogo_iniciado->delay_boss_animado * 3) {
                                DrawTextureEx(jogo_iniciado->boss_dia_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else if (jogo_iniciado->boss_animado > jogo_iniciado->delay_boss_animado * 2) {
                                DrawTextureEx(jogo_iniciado->boss_dia_f3, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else if (jogo_iniciado->boss_animado > jogo_iniciado->delay_boss_animado) {
                                DrawTextureEx(jogo_iniciado->boss_dia_f2, (Vector2){0, 0}, 0.0, 1, WHITE);
                            } else {
                                DrawTextureEx(jogo_iniciado->boss_dia_f1, (Vector2){0, 0}, 0.0, 1, WHITE);
                            }
                        }
                    }
                    desenhar_personagem(jogo_iniciado->personagem_head, 0, 100, jogo_iniciado->quadro_roxo, jogo_iniciado->quadro_roxo2, jogo_iniciado->quadro_roxo3);
                    desenhar_personagem(jogo_iniciado->personagem_head, 1, 150, jogo_iniciado->quadro_vermelho, jogo_iniciado->quadro_vermelho2, jogo_iniciado->quadro_vermelho3);
                    desenhar_personagem(jogo_iniciado->personagem_head, 2, 80, jogo_iniciado->quadro_laranja, jogo_iniciado->quadro_laranja2, jogo_iniciado->quadro_laranja3);
                    desenhar_personagem(jogo_iniciado->personagem_head, 3, 100, jogo_iniciado->quadro_vinho, jogo_iniciado->quadro_vinho2, jogo_iniciado->quadro_vinho3); 
                }           
                desenhar_vida_personagens(jogo_iniciado->personagem_head, 0, jogo_iniciado->vida_cor);
                desenhar_energia_personagens(jogo_iniciado->personagem_head, 0, jogo_iniciado->energia_cor);
                desenhar_vida_personagens(jogo_iniciado->personagem_head, 1, jogo_iniciado->vida_cor);
                desenhar_energia_personagens(jogo_iniciado->personagem_head, 1, jogo_iniciado->energia_cor);
                desenhar_vida_personagens(jogo_iniciado->personagem_head, 2, jogo_iniciado->vida_cor);
                desenhar_energia_personagens(jogo_iniciado->personagem_head, 2, jogo_iniciado->energia_cor);
                desenhar_vida_personagens(jogo_iniciado->personagem_head, 3, jogo_iniciado->vida_cor);
                desenhar_energia_personagens(jogo_iniciado->personagem_head, 3, jogo_iniciado->energia_cor);
                if (!(jogo_iniciado->vez_inimigo)) {
                    desenhar_vida_boss(jogo_iniciado->boss, largura, jogo_iniciado->vida_cor, jogo_iniciado->fonte);
                }
                DrawTextureEx(jogo_iniciado->borda, (Vector2){0, 600}, 0.0, 0.5, GRAY);
                DrawTextureEx(jogo_iniciado->borda, (Vector2){400, 600}, 0.0, 0.5, GRAY);
                DrawTextureEx(jogo_iniciado->borda, (Vector2){800, 600}, 0.0, 0.5, GRAY);
                DrawTextureEx(jogo_iniciado->borda, (Vector2){1200, 600}, 0.0, 0.5, GRAY);
                if (jogo_iniciado->vez_inimigo == 1) {
                    // Nada pra nao ter borda de escolhido
                } else if (jogo_iniciado->personagem_num == 0) {
                    DrawTextureEx(jogo_iniciado->borda_escolhido, (Vector2){0, 600}, 0.0, 0.5, WHITE);
                } else if (jogo_iniciado->personagem_num == 1) {
                    DrawTextureEx(jogo_iniciado->borda_escolhido, (Vector2){400, 600}, 0.0, 0.5, WHITE);
                } else if (jogo_iniciado->personagem_num == 2) {
                    DrawTextureEx(jogo_iniciado->borda_escolhido, (Vector2){800, 600}, 0.0, 0.5, WHITE);
                } else if (jogo_iniciado->personagem_num == 3) {
                    DrawTextureEx(jogo_iniciado->borda_escolhido, (Vector2){1200, 600}, 0.0, 0.5, WHITE);
                }
                
                //Vez do inimigo ou vez do jogador
                if (jogo_iniciado->vez_inimigo == 1) {
                    if (jogo_iniciado->ataque_boss_tempo >= jogo_iniciado->delay_ataque_boss) {
                        ataque_boss(jogo_iniciado->boss, &jogo_iniciado->personagem_head, jogo_iniciado->random_p, &jogo_iniciado->p0_morto, &jogo_iniciado->p1_morto, &jogo_iniciado->p2_morto, &jogo_iniciado->p3_morto);
                        jogo_iniciado->vez_inimigo = 0;
                        jogo_iniciado->personagem_num = 0;
                        jogo_iniciado->escolhas = 1;
                        jogo_iniciado->pode_apertar = 0.0;
                        jogo_iniciado->boss_animado = 0.0;
                        jogo_iniciado->comeco = 1;
                        // 0 - dia, 1 - noite
                        if (jogo_iniciado->horario == 0) {
                            jogo_iniciado->horario  = 1;
                        } else if (jogo_iniciado->horario == 1) {
                            jogo_iniciado->horario = 0;
                        }
                        if(currentScreen == SCREEN_GAME && jogo_iniciado->p0_morto == 1 && jogo_iniciado->p1_morto == 1 && jogo_iniciado->p2_morto == 1 && jogo_iniciado->p3_morto == 1){
                            liberar_jogo(jogo_iniciado);
                            derrotado = 1;
                            currentScreen = SCREEN_GAMEOVER;
                        }
                        if (currentScreen == SCREEN_GAME && jogo_iniciado->boss->vida <= 0) {
                            liberar_jogo(jogo_iniciado);
                            currentScreen = SCREEN_WIN;
                        }
                    }
                } else {
                    // Vez do player
                    if (jogo_iniciado->comeco == 1) {
                        pegar_personagem_aleatorio(jogo_iniciado->personagem_head, &jogo_iniciado->random_p);
                        jogo_iniciado->comeco = 0;
                    }
                    
                    //Escolhas primarias de cada personagem
                    if (jogo_iniciado->escolhas == 1 && jogo_iniciado->personagem_num == 0) {
                        //Personagem 0
                        
                        pegar_personagem(jogo_iniciado->personagem_num, &jogo_iniciado->personagem_atual, jogo_iniciado->personagem_head);
                        
                        if(jogo_iniciado->random_p == 0) {
                            desenhar_olho(jogo_iniciado->olho1, jogo_iniciado->olho2, jogo_iniciado->olho3, &jogo_iniciado->olho_animado, jogo_iniciado->olho_delay);
                        }

                        jogo_iniciado->personagem_atual->defesa = 0;

                        if (jogo_iniciado->personagem_atual->vida == 0) {
                            jogo_iniciado->personagem_num++;
                            jogo_iniciado->pode_apertar = 0.0;
                            continue;
                        }
                
                        mudar_escolha_primaria(&jogo_iniciado->escolhido, jogo_iniciado->personagem_num, &jogo_iniciado->pode_apertar, &jogo_iniciado->delay);
                        
                        desenhar_escolhas_primarias(jogo_iniciado->escolhido, jogo_iniciado->personagem_num, largura, altura, jogo_iniciado->horario, jogo_iniciado->fonte, jogo_iniciado->personagem_atual);
                        
                        if (IsKeyPressed(KEY_Z) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            if (jogo_iniciado->escolhido == 0) {
                                if (jogo_iniciado->horario == 0) {
                                    jogo_iniciado->escolha_flores_diurnas = 1;    
                                    jogo_iniciado->escolhas = 0;
                                    jogo_iniciado->escolhido = 0;
                                }
                            } else if (jogo_iniciado->escolhido == 1) {
                                if (jogo_iniciado->horario == 1) {
                                    jogo_iniciado->escolha_flores_noturnas = 1;    
                                    jogo_iniciado->escolhas = 0;
                                    jogo_iniciado->escolhido = 0;
                                }
                            } else if (jogo_iniciado->escolhido == 2) {
                                jogo_iniciado->defender = 1;
                                jogo_iniciado->escolhas = 0;
                                jogo_iniciado->escolhido = 0;
                            }
                            jogo_iniciado->pode_apertar = 0.0;
                        }
                
                    } else if (jogo_iniciado->escolhas == 1 && jogo_iniciado->personagem_num == 1) {
                        //Personagem 1
                        pegar_personagem(jogo_iniciado->personagem_num, &jogo_iniciado->personagem_atual, jogo_iniciado->personagem_head);
                
                        if(jogo_iniciado->random_p == 1) {
                            desenhar_olho(jogo_iniciado->olho1, jogo_iniciado->olho2, jogo_iniciado->olho3, &jogo_iniciado->olho_animado, jogo_iniciado->olho_delay);
                        }

                        jogo_iniciado->personagem_atual->defesa = 0;

                        if (jogo_iniciado->personagem_atual->vida == 0) {
                            jogo_iniciado->personagem_num++;
                            jogo_iniciado->pode_apertar = 0.0;
                            continue;
                        }
                
                        mudar_escolha_primaria(&jogo_iniciado->escolhido, jogo_iniciado->personagem_num, &jogo_iniciado->pode_apertar, &jogo_iniciado->delay);
                        
                        desenhar_escolhas_primarias(jogo_iniciado->escolhido, jogo_iniciado->personagem_num, largura, altura, jogo_iniciado->horario, jogo_iniciado->fonte, jogo_iniciado->personagem_atual);
                        
                        if (IsKeyPressed(KEY_Z) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            if (jogo_iniciado->escolhido == 0) {
                                jogo_iniciado->escolha_ataques = 1;
                                jogo_iniciado->escolhas = 0;
                                jogo_iniciado->escolhido = 0;    
                            } else if (jogo_iniciado->escolhido == 1) {
                                if (jogo_iniciado->horario == 0) {
                                    jogo_iniciado->escolha_flores_diurnas = 1;
                                    jogo_iniciado->escolhas = 0;
                                    jogo_iniciado->escolhido = 0;
                                }
                            } else if (jogo_iniciado->escolhido == 2) {
                                jogo_iniciado->defender = 1;
                                jogo_iniciado->escolhas = 0;
                                jogo_iniciado->escolhido = 0;
                            }
                            jogo_iniciado->pode_apertar = 0.0;
                        }
                    } else if (jogo_iniciado->escolhas == 1 && jogo_iniciado->personagem_num == 2) {
                        //Personagem 2
                        pegar_personagem(jogo_iniciado->personagem_num, &jogo_iniciado->personagem_atual, jogo_iniciado->personagem_head);
                
                        if(jogo_iniciado->random_p == 2) {
                            desenhar_olho(jogo_iniciado->olho1, jogo_iniciado->olho2, jogo_iniciado->olho3, &jogo_iniciado->olho_animado, jogo_iniciado->olho_delay);
                        }

                        jogo_iniciado->personagem_atual->defesa = 0;

                        if (jogo_iniciado->personagem_atual->vida == 0) {
                            jogo_iniciado->personagem_num++;
                            jogo_iniciado->pode_apertar = 0.0;
                            continue;
                        }
                
                        mudar_escolha_primaria(&jogo_iniciado->escolhido, jogo_iniciado->personagem_num, &jogo_iniciado->pode_apertar, &jogo_iniciado->delay);
                
                        desenhar_escolhas_primarias(jogo_iniciado->escolhido, jogo_iniciado->personagem_num, largura, altura, jogo_iniciado->horario, jogo_iniciado->fonte, jogo_iniciado->personagem_atual);
                
                        if (IsKeyPressed(KEY_Z) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            if (jogo_iniciado->escolhido == 0) {
                                jogo_iniciado->escolha_ataques = 1;
                                jogo_iniciado->escolhas = 0;
                                jogo_iniciado->escolhido = 0;   
                            } else if (jogo_iniciado->escolhido == 1) {
                                if (jogo_iniciado->horario == 1) {
                                    jogo_iniciado->escolha_flores_noturnas = 1;
                                    jogo_iniciado->escolhas = 0;
                                    jogo_iniciado->escolhido = 0;
                                }
                            } else if (jogo_iniciado->escolhido == 2) {
                                jogo_iniciado->defender = 1;
                                jogo_iniciado->escolhas = 0;
                                jogo_iniciado->escolhido = 0;
                            }
                            jogo_iniciado->pode_apertar = 0.0;
                        }
                    } else if (jogo_iniciado->escolhas == 1 && jogo_iniciado->personagem_num == 3) {
                        //Personagem 3
                        pegar_personagem(jogo_iniciado->personagem_num, &jogo_iniciado->personagem_atual, jogo_iniciado->personagem_head);
                
                        if(jogo_iniciado->random_p == 3) {
                            desenhar_olho(jogo_iniciado->olho1, jogo_iniciado->olho2, jogo_iniciado->olho3, &jogo_iniciado->olho_animado, jogo_iniciado->olho_delay);
                        }

                        jogo_iniciado->personagem_atual->defesa = 0;

                        if (jogo_iniciado->personagem_atual->vida == 0) {
                            jogo_iniciado->personagem_num++;
                            jogo_iniciado->pode_apertar = 0.0;
                            continue;
                        }
                
                        mudar_escolha_primaria(&jogo_iniciado->escolhido, jogo_iniciado->personagem_num, &jogo_iniciado->pode_apertar, &jogo_iniciado->delay);
                
                        desenhar_escolhas_primarias(jogo_iniciado->escolhido, jogo_iniciado->personagem_num, largura, altura, jogo_iniciado->horario, jogo_iniciado->fonte, jogo_iniciado->personagem_atual);
                
                        if (IsKeyPressed(KEY_Z) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            if (jogo_iniciado->escolhido == 0) {
                                jogo_iniciado->escolha_ataques = 1;    
                            } else if (jogo_iniciado->escolhido == 1) {
                                jogo_iniciado->defender = 1;
                            }
                            jogo_iniciado->escolhas = 0;
                            jogo_iniciado->escolhido = 0;
                            jogo_iniciado->pode_apertar = 0.0;
                        }
                    }
                    
                    //Escolhas secundarias
                    if (jogo_iniciado->escolha_ataques == 1) {
                        //Escolha de ataques
                        jogo_iniciado->inicio_escolhas_secundarios = 0;
                        mudar_escolha_secundaria(&jogo_iniciado->escolhido, jogo_iniciado->personagem_atual, jogo_iniciado->escolha_flores_diurnas, jogo_iniciado->escolha_flores_noturnas, 
                            jogo_iniciado->escolha_ataques, &jogo_iniciado->pode_apertar, &jogo_iniciado->delay);
                        desenhar_escolhas_ataques(&jogo_iniciado->escolhido, &jogo_iniciado->inicio_escolhas_secundarios, jogo_iniciado->personagem_atual, jogo_iniciado->personagem_num, 
                            largura, altura, &jogo_iniciado->energia_sobra, jogo_iniciado->elemento_atual, &jogo_iniciado->velocidade_atual, jogo_iniciado->fonte);
                
                        if (IsKeyPressed(KEY_Z) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            if (jogo_iniciado->energia_sobra == 1) {
                                jogo_iniciado->escolha_ataques = 0;
                                jogo_iniciado->projetil_ataque = 1;
                                jogo_iniciado->momento_atacar = 1;
                                jogo_iniciado->largura_coracao = 200;
                                jogo_iniciado->altura_proj = 515;
                                jogo_iniciado->pode_apertar = 0.0;
                            }
                        }
                        if (IsKeyPressed(KEY_X) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            jogo_iniciado->escolha_ataques = 0;
                            jogo_iniciado->escolhas = 1;
                            jogo_iniciado->escolhido = 0;
                            jogo_iniciado->pode_apertar = 0.0;
                        }
                    }
                    if (jogo_iniciado->escolha_flores_diurnas == 1) {
                        //Escolha de flores diurnas
                        jogo_iniciado->inicio_escolhas_secundarios = 0;
                        mudar_escolha_secundaria(&jogo_iniciado->escolhido, jogo_iniciado->personagem_atual, jogo_iniciado->escolha_flores_diurnas, jogo_iniciado->escolha_flores_noturnas, 
                            jogo_iniciado->escolha_ataques, &jogo_iniciado->pode_apertar, &jogo_iniciado->delay);
                        desenhar_escolhas_flores_dia(&jogo_iniciado->escolhido, &jogo_iniciado->inicio_escolhas_secundarios, jogo_iniciado->personagem_atual, jogo_iniciado->personagem_num, 
                            largura, altura, &jogo_iniciado->energia_sobra, jogo_iniciado->elemento_atual, &jogo_iniciado->velocidade_atual, jogo_iniciado->fonte);
                
                        if (IsKeyPressed(KEY_Z) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            if (jogo_iniciado->energia_sobra == 1) {
                                jogo_iniciado->escolha_flores_diurnas = 0;
                                jogo_iniciado->projetil_flor_diurna = 1;
                                jogo_iniciado->momento_atacar = 1;
                                jogo_iniciado->largura_coracao = 200;
                                jogo_iniciado->altura_proj = 515;
                                jogo_iniciado->pode_apertar = 0.0;
                            }
                        }
                        if (IsKeyPressed(KEY_X) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            jogo_iniciado->escolha_flores_diurnas = 0;
                            jogo_iniciado->escolhas = 1;
                            jogo_iniciado->escolhido = 0;
                            jogo_iniciado->pode_apertar = 0.0;
                        }
                    }
                    if (jogo_iniciado->escolha_flores_noturnas == 1) {
                        //Escolha de flores noturnas
                        jogo_iniciado->inicio_escolhas_secundarios = 0;
                        mudar_escolha_secundaria(&jogo_iniciado->escolhido, jogo_iniciado->personagem_atual, jogo_iniciado->escolha_flores_diurnas, jogo_iniciado->escolha_flores_noturnas, 
                            jogo_iniciado->escolha_ataques, &jogo_iniciado->pode_apertar, &jogo_iniciado->delay);
                        desenhar_escolhas_flores_noite(&jogo_iniciado->escolhido, &jogo_iniciado->inicio_escolhas_secundarios, jogo_iniciado->personagem_atual, jogo_iniciado->personagem_num, 
                            largura, altura, &jogo_iniciado->energia_sobra, jogo_iniciado->elemento_atual, &jogo_iniciado->velocidade_atual, jogo_iniciado->fonte);
                
                        if (IsKeyPressed(KEY_Z) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            if (jogo_iniciado->energia_sobra == 1) {
                                jogo_iniciado->escolha_flores_noturnas= 0;
                                jogo_iniciado->projetil_flor_noturna = 1;
                                jogo_iniciado->momento_atacar = 1;
                                jogo_iniciado->largura_coracao = 200;
                                jogo_iniciado->altura_proj = 515;
                                jogo_iniciado->pode_apertar = 0.0;
                            }
                        }
                        if (IsKeyPressed(KEY_X) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            jogo_iniciado->escolha_flores_noturnas = 0;
                            jogo_iniciado->escolhas = 1;
                            jogo_iniciado->escolhido = 0;
                            jogo_iniciado->pode_apertar = 0.0;
                        }
                    }
                    if (jogo_iniciado->defender == 1) {
                        jogo_iniciado->personagem_atual->defesa = 1;
                        jogo_iniciado->defender = 0;
                        jogo_iniciado->pode_apertar = 0.0;
                        if (jogo_iniciado->personagem_num == 3) {
                            jogo_iniciado->ataque_boss_tempo = 0.0;
                            jogo_iniciado->vez_inimigo = 1;
                        } else {
                            jogo_iniciado->personagem_atual->energia += GetRandomValue(10, 20);
                            if (jogo_iniciado->personagem_num == 0 && jogo_iniciado->personagem_atual->energia > 80) {
                                jogo_iniciado->personagem_atual->energia = 80;
                            } else if (jogo_iniciado->personagem_num == 1 && jogo_iniciado->personagem_atual->energia > 50) {
                                jogo_iniciado->personagem_atual->energia = 50;
                            } else if (jogo_iniciado->personagem_num == 2 && jogo_iniciado->personagem_atual->energia > 80) {
                                jogo_iniciado->personagem_atual->energia = 80;
                            }
                            if (jogo_iniciado->personagem_num == 2 && jogo_iniciado->p3_morto == 1) {
                                jogo_iniciado->ataque_boss_tempo = 0.0;
                                jogo_iniciado->vez_inimigo = 1;
                            } else if (jogo_iniciado->personagem_num == 1 && jogo_iniciado->p2_morto == 1 && jogo_iniciado->p3_morto == 1) {
                                jogo_iniciado->ataque_boss_tempo = 0.0;
                                jogo_iniciado->vez_inimigo = 1;
                            } else if (jogo_iniciado->personagem_num == 0 && jogo_iniciado->p1_morto == 1 && jogo_iniciado->p2_morto == 1 && jogo_iniciado->p3_morto == 1) {
                                jogo_iniciado->ataque_boss_tempo = 0.0;
                                jogo_iniciado->vez_inimigo = 1;
                            } else {
                                jogo_iniciado->escolhas = 1;
                                jogo_iniciado->personagem_num++;
                            }
                        }
                    }

                    if (jogo_iniciado->momento_atacar == 1) {
                        jogo_iniciado->colisao_coracao = (Vector2){200 + jogo_iniciado->largura_coracao, 175};
                        //DrawCircleV(jogo_iniciado->colisao_coracao, 80, GREEN);
                        desenhar_coracao(jogo_iniciado->boss_coracao, jogo_iniciado->largura_coracao);
                        jogo_iniciado->colisao_proj_horizontal = (Rectangle){750, jogo_iniciado->altura_proj + 50, 100, 20};
                        jogo_iniciado->colisao_proj_vertical = (Rectangle){780, jogo_iniciado->altura_proj + 10, 40, 90};
                        desenhar_projetil(jogo_iniciado->elemento_atual, jogo_iniciado->altura_proj, jogo_iniciado->proj_agua, jogo_iniciado->proj_ar, jogo_iniciado->proj_corte,
                            jogo_iniciado->proj_eletricidade, jogo_iniciado->proj_fogo, jogo_iniciado->proj_gelo, jogo_iniciado->proj_impacto, jogo_iniciado->proj_lunar,
                            jogo_iniciado->proj_perfuracao, jogo_iniciado->proj_solar, jogo_iniciado->proj_veneno, jogo_iniciado->colisao_proj_horizontal, jogo_iniciado->colisao_proj_vertical);
                        if (jogo_iniciado->largura_coracao == 1000) {
                            jogo_iniciado->voltar_coracao = 1;
                            jogo_iniciado->ir_coracao = 0;
                        } else if (jogo_iniciado->largura_coracao == 200) {
                            jogo_iniciado->voltar_coracao = 0;
                            jogo_iniciado->ir_coracao = 1;
                        }
                        if (jogo_iniciado->ir_coracao == 1) {
                            jogo_iniciado->largura_coracao += 20;
                        } else if (jogo_iniciado->voltar_coracao == 1) {
                            jogo_iniciado->largura_coracao -= 20;
                        }
                        if (jogo_iniciado->ataque_apertado == 1) {
                            jogo_iniciado->altura_proj -= 20 * jogo_iniciado->velocidade_atual;
                            // Verificar com colisao
                            if (CheckCollisionCircleRec(jogo_iniciado->colisao_coracao, 80, jogo_iniciado->colisao_proj_horizontal) || CheckCollisionCircleRec(jogo_iniciado->colisao_coracao, 80, jogo_iniciado->colisao_proj_vertical)) {
                                jogo_iniciado->acertou_ataque = 1;
                                jogo_iniciado->ataque_apertado = 0;
                                jogo_iniciado->verificar_ataque = 1;
                                jogo_iniciado->momento_atacar = 0;
                            } else if (CheckCollisionRecs(jogo_iniciado->colisao_proj_horizontal, jogo_iniciado->colisao_teto) || CheckCollisionRecs(jogo_iniciado->colisao_proj_vertical, jogo_iniciado->colisao_teto)) {
                                jogo_iniciado->acertou_ataque = 0;
                                jogo_iniciado->ataque_apertado = 0;
                                jogo_iniciado->verificar_ataque = 1;
                                jogo_iniciado->momento_atacar = 0;
                            }
                        } else if (IsKeyPressed(KEY_Z) && jogo_iniciado->pode_apertar >= jogo_iniciado->delay) {
                            jogo_iniciado->ataque_apertado = 1;
                            jogo_iniciado->pode_apertar = 0.0;
                        }
                    }
                    if (jogo_iniciado->verificar_ataque == 1) {
                        acao(&jogo_iniciado->escolhido, &jogo_iniciado->personagem_atual, &jogo_iniciado->boss, jogo_iniciado->projetil_ataque, jogo_iniciado->projetil_flor_diurna, jogo_iniciado->projetil_flor_noturna, jogo_iniciado->acertou_ataque);
                        jogo_iniciado->projetil_ataque = 0;
                        jogo_iniciado->projetil_flor_diurna = 0;
                        jogo_iniciado->projetil_flor_noturna = 0;
                        jogo_iniciado->escolhido = 0;
                        jogo_iniciado->verificar_ataque = 0;
                        jogo_iniciado->animacao_efeito = 1;
                        
                        if (currentScreen == SCREEN_GAME && jogo_iniciado->boss->vida <= 0) {
                            liberar_jogo(jogo_iniciado);
                            currentScreen = SCREEN_WIN;
                        }
                    }
                    if (jogo_iniciado->animacao_efeito == 1) {
                        if (jogo_iniciado->acertou_ataque == 1) {
                            jogo_iniciado->efeito_animado += GetFrameTime();
                            animacao_efeito(jogo_iniciado->efeitos, jogo_iniciado->elemento_atual, &jogo_iniciado->efeito_terminou, &jogo_iniciado->efeito_animado, jogo_iniciado->efeito_delay, &jogo_iniciado->largura_frame, &jogo_iniciado->cont_frames);
                        }
                        if (jogo_iniciado->efeito_terminou == 1 || jogo_iniciado->acertou_ataque == 0) {
                            jogo_iniciado->acertou_ataque = 0;
                            jogo_iniciado->efeito_terminou = 0;
                            jogo_iniciado->animacao_efeito = 0;
                            if (jogo_iniciado->personagem_num == 3) {
                                jogo_iniciado->ataque_boss_tempo = 0.0;
                                jogo_iniciado->vez_inimigo = 1;
                            } else {
                                if (jogo_iniciado->personagem_num == 2 && jogo_iniciado->p3_morto == 1) {
                                    jogo_iniciado->ataque_boss_tempo = 0.0;
                                    jogo_iniciado->vez_inimigo = 1;
                                } else if (jogo_iniciado->personagem_num == 1 && jogo_iniciado->p2_morto == 1 && jogo_iniciado->p3_morto == 1) {
                                    jogo_iniciado->ataque_boss_tempo = 0.0;
                                    jogo_iniciado->vez_inimigo = 1;
                                } else if (jogo_iniciado->personagem_num == 0 && jogo_iniciado->p1_morto == 1 && jogo_iniciado->p2_morto == 1 && jogo_iniciado->p3_morto == 1) {
                                    jogo_iniciado->ataque_boss_tempo = 0.0;
                                    jogo_iniciado->vez_inimigo = 1;
                                } else {
                                    jogo_iniciado->escolhas = 1;
                                    jogo_iniciado->personagem_num++;
                                }
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

                DrawTexturePro(jogo_iniciado->janela.texture,
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

            case SCREEN_WIN:
                currentScreen = RunGameWin();
    
                if (currentScreen == SCREEN_GAME) {
                    novo_jogo(jogo_iniciado, largura, altura);
                    derrotado = 0;
                }
    break;
        }
    }

    if (currentScreen == SCREEN_GAME) {
        liberar_jogo(jogo_iniciado);
        free(jogo_iniciado);
    }
    
    CloseWindow();

    return 0;
}