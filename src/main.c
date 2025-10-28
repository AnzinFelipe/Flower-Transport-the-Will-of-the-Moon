#include "raylib.h"
#include "escolhas_primarias.h"
#include "escolhas_secundarias.h"
#include "boss.h"
#include "acao.h"

#include <stdlib.h>
#include <math.h>

int main(void) {
    int largura = 1600, altura = 900;

    SetConfigFlags(FLAG_MSAA_4X_HINT | FLAG_VSYNC_HINT | FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_MAXIMIZED);
    InitWindow(largura, altura, "Flower Transport - the Will of the Moon");
    RenderTexture2D janela = LoadRenderTexture(largura, altura);
    SetTextureFilter(janela.texture, TEXTURE_FILTER_TRILINEAR);
    
    InitAudioDevice();
    Music pink = LoadMusicStream("assets/music/Pink.mp3");
    PlayMusicStream(pink);

    Texture2D fundo = LoadTexture("assets/images/Teste.png");

    Texture2D noite = LoadTexture("assets/images/Noite.png");
    GenTextureMipmaps(&noite);
    SetTextureFilter(noite, TEXTURE_FILTER_TRILINEAR);

    Texture2D borda_escolhido = LoadTexture("assets/images/Borda.png");
    GenTextureMipmaps(&borda_escolhido);
    SetTextureFilter(borda_escolhido, TEXTURE_FILTER_TRILINEAR);
    Texture2D borda = LoadTexture("assets/images/Borda2.png");
    GenTextureMipmaps(&borda);
    SetTextureFilter(borda, TEXTURE_FILTER_TRILINEAR);

    Texture2D quadro_roxo = LoadTexture("assets/images/Roxo1.png");
    GenTextureMipmaps(&quadro_roxo);
    SetTextureFilter(quadro_roxo, TEXTURE_FILTER_TRILINEAR);
    Texture2D quadro_roxo_noite = LoadTexture("assets/images/Roxo1_noite.png");
    GenTextureMipmaps(&quadro_roxo_noite);
    SetTextureFilter(quadro_roxo_noite, TEXTURE_FILTER_TRILINEAR);

    Texture2D quadro_vermelho = LoadTexture("assets/images/Vermelho1.png");
    GenTextureMipmaps(&quadro_vermelho);
    SetTextureFilter(quadro_vermelho, TEXTURE_FILTER_TRILINEAR);
    Texture2D quadro_vermelho_noite = LoadTexture("assets/images/Vermelho1_noite.png");
    GenTextureMipmaps(&quadro_vermelho_noite);
    SetTextureFilter(quadro_vermelho_noite, TEXTURE_FILTER_TRILINEAR);

    Texture2D quadro_laranja = LoadTexture("assets/images/Laranja1.png");
    GenTextureMipmaps(&quadro_laranja);
    SetTextureFilter(quadro_laranja, TEXTURE_FILTER_TRILINEAR);
    Texture2D quadro_laranja_noite = LoadTexture("assets/images/Laranja1_noite.png");
    GenTextureMipmaps(&quadro_laranja_noite);
    SetTextureFilter(quadro_laranja_noite, TEXTURE_FILTER_TRILINEAR);

    Texture2D quadro_vinho = LoadTexture("assets/images/Vinho1.png");
    GenTextureMipmaps(&quadro_vinho);
    SetTextureFilter(quadro_vinho, TEXTURE_FILTER_TRILINEAR);
    Texture2D quadro_vinho_noite = LoadTexture("assets/images/Vinho1_noite.png");
    GenTextureMipmaps(&quadro_vinho_noite);
    SetTextureFilter(quadro_vinho_noite, TEXTURE_FILTER_TRILINEAR);

    int escolhas = 1, escolha_flores_diurnas = 0, escolha_flores_noturnas = 0, escolha_ataques = 0, defender = 0;
    int escolhido = 0, inicio_escolhas_secundarios = 0, personagem_num = 0, vez_inimigo = 0, horario = 0;
    Personagem *personagem_atual = NULL;
    float pode_apertar = 0.0, delay = 0.1;
    Color vida_cor = {180, 18, 18, 255};
    Color energia_cor = {18, 180, 80, 255};
    
    Ataque *ataque_head2 = NULL;
    // Head, nome, dano, elemento, energia gasta, velocidade
    adicionar_ataque(&ataque_head2, "Soco", 20, "Impacto", 5, 1.5);
    adicionar_ataque(&ataque_head2, "Chute", 15, "Impacto", 5, 1);
    adicionar_ataque(&ataque_head2, "Pa de jardinagem", 30, "Impacto", 10, 1.5);
    adicionar_ataque(&ataque_head2, "Tesoura de poda", 25, "Corte", 10, 1.5);

    Ataque *ataque_head3 = NULL;
    adicionar_ataque(&ataque_head3, "Soco", 15, "Impacto", 5, 1.5);
    adicionar_ataque(&ataque_head3, "Unhada", 10, "Corte", 3, 2);
    adicionar_ataque(&ataque_head3, "Chute espiral", 25, "Perfuracao", 15, 2);
    adicionar_ataque(&ataque_head3, "Chifrada", 30, "Perfuracao", 20, 1);

    Ataque *ataque_head4 = NULL;
    adicionar_ataque(&ataque_head4, "Soco solar", 35, "Impacto", 0, 1.5);
    adicionar_ataque(&ataque_head4, "Chute solar", 35, "Impacto", 0, 1.5);
    adicionar_ataque(&ataque_head4, "Lanca solar", 30, "Perfuracao", 0, 2);
    adicionar_ataque(&ataque_head4, "Espada solar", 30, "Corte", 0, 1.5);
    adicionar_ataque(&ataque_head4, "Fumaca venenosa", 10, "Veneno", 0, 1);

    Ataque *ataque_head_boss = NULL;
    adicionar_ataque(&ataque_head_boss, "Bafo lunar", 25, "Fogo", 0, 0);
    adicionar_ataque(&ataque_head_boss, "Chute dilacerante", 25, "Corte", 0, 0);
    adicionar_ataque(&ataque_head_boss, "Espectro lunatico", 30, "Lunar", 0, 0);
    adicionar_ataque(&ataque_head_boss, "Olhar sombrio", 20, "Lunar", 0, 0);
    
    Flor_dia *flor_dia_head1 = NULL;
    // Head, nome, dano, elemento, energia gasta, velocidade
    adicionar_flor_dia(&flor_dia_head1, "Flamigera-do-dia", 25, "Fogo", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head1, "Tulipa afiada", 10, "Corte", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head1, "Orquidea voltaica", 20, "Eletricidade", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head1, "Nenufar real", 15, "Agua", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head1, "Girassol", 20, "Solar", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head1, "Ventanilia", 15, "Ar", 15, 2.0);

    Flor_dia *flor_dia_head2 = NULL;
    adicionar_flor_dia(&flor_dia_head2, "Rosa gelida", 15, "Gelo", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head2, "Helicopdea", 10, "Ar", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head2, "Girassol", 20, "Solar", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head2, "Gravitiana", 20, "Impacto", 15, 2.0);
    adicionar_flor_dia(&flor_dia_head2, "Lotus", 15, "Agua", 15, 2.0);

    Flor_noite *flor_noite_head1 = NULL;
    // Head, nome, dano, elemento, energia gasta, velocidade
    adicionar_flor_noite(&flor_noite_head1, "Rosa cromada", 20, "Impacto", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head1, "Rainha-da-noite", 20, "Fogo", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head1, "Realeza espinhenta", 15, "Perfuracao", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head1, "Flor de Mandacaru", 20, "Agua", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head1, "Trombeta-de-anjo", 15, "Veneno", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head1, "Gloria-da-friagem", 20, "Gelo", 10, 2.5);

    Flor_noite *flor_noite_head3 = NULL;
    adicionar_flor_noite(&flor_noite_head3, "Dama-da-noite", 20, "Lunar", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head3, "Flamigera-da-noite", 25, "Fogo", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head3, "Realeza espinhenta", 15, "Perfuracao", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head3, "Gloria-da-friagem", 20, "Gelo", 10, 2.5);
    adicionar_flor_noite(&flor_noite_head3, "Energialida", 15, "Eletricidade", 10, 2.5);

    Personagem *personagem_head = NULL;
    // Head, nome, vida, energia, ataque, flor_dia, flor_noite
    adicionar_personagem(&personagem_head, "Roxo", 100, 60, NULL, flor_dia_head1, flor_noite_head1);
    adicionar_personagem(&personagem_head, "Vermelho", 150, 40, ataque_head2, flor_dia_head2, NULL);
    adicionar_personagem(&personagem_head, "Laranja", 80, 80, ataque_head3, NULL, flor_noite_head3);
    adicionar_personagem(&personagem_head, "Verde", 100, 0, ataque_head4, NULL, NULL);
    
    adicionar_vantagens_desvantagens_personagem(&personagem_head, 0);
    adicionar_vantagens_desvantagens_personagem(&personagem_head, 1);
    adicionar_vantagens_desvantagens_personagem(&personagem_head, 2);
    adicionar_vantagens_desvantagens_personagem(&personagem_head, 3);
    
    Boss *boss = (Boss *)malloc(sizeof(Boss));
    adicionar_boss(&boss, ataque_head_boss);
    
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        UpdateMusicStream(pink);
        
        pode_apertar += GetFrameTime();
        
        if (IsKeyPressed(KEY_F11) && pode_apertar >= delay) {
            ToggleFullscreen();
            pode_apertar = 0.0;
        }

        BeginTextureMode(janela);
        
        ClearBackground(BLACK);
        DrawTextureEx(fundo, (Vector2){0, 0}, 0.0, 0.85, BLACK);
        DrawRectangle(15, 615, 370, 35, vida_cor);
        DrawRectangle(350, 650, 35, 250, energia_cor);
        DrawRectangle(415, 615, 370, 35, vida_cor);
        DrawRectangle(750, 650, 35, 250, energia_cor);
        DrawRectangle(815, 615, 370, 35, vida_cor);
        DrawRectangle(1150, 650, 35, 250, energia_cor);
        DrawRectangle(1215, 615, 370, 35, vida_cor);
        DrawRectangle(1550, 650, 35, 250, BLACK);
        if (horario == 1) {
            DrawTextureEx(noite, (Vector2){0, 0}, 0.0, 1, WHITE);
            DrawTextureEx(quadro_roxo_noite, (Vector2){15, 650}, 0.0, 0.35, WHITE);
            DrawTextureEx(quadro_vermelho_noite, (Vector2){415, 650}, 0.0, 0.35, WHITE);
            DrawTextureEx(quadro_laranja_noite, (Vector2){815, 650}, 0.0, 0.35, WHITE);
            DrawTextureEx(quadro_vinho_noite, (Vector2){1215, 650}, 0.0, 0.35, WHITE);
        } else if (horario == 0) {
            DrawTextureEx(quadro_roxo, (Vector2){15, 650}, 0.0, 0.35, WHITE);
            DrawTextureEx(quadro_vermelho, (Vector2){415, 650}, 0.0, 0.35, WHITE);
            DrawTextureEx(quadro_laranja, (Vector2){815, 650}, 0.0, 0.35, WHITE);
            DrawTextureEx(quadro_vinho, (Vector2){1215, 650}, 0.0, 0.35, WHITE);
        }           
        DrawTextureEx(borda, (Vector2){0, 600}, 0.0, 0.5, GRAY);
        DrawTextureEx(borda, (Vector2){400, 600}, 0.0, 0.5, GRAY);
        DrawTextureEx(borda, (Vector2){800, 600}, 0.0, 0.5, GRAY);
        DrawTextureEx(borda, (Vector2){1200, 600}, 0.0, 0.5, GRAY);
        if (personagem_num == 0) {
            DrawTextureEx(borda_escolhido, (Vector2){0, 600}, 0.0, 0.5, WHITE);
        } else if (personagem_num == 1) {
            DrawTextureEx(borda_escolhido, (Vector2){400, 600}, 0.0, 0.5, WHITE);
        } else if (personagem_num == 2) {
            DrawTextureEx(borda_escolhido, (Vector2){800, 600}, 0.0, 0.5, WHITE);
        } else if (personagem_num == 3) {
            DrawTextureEx(borda_escolhido, (Vector2){1200, 600}, 0.0, 0.5, WHITE);
        }
        desenhar_vida_boss(boss, largura, altura, vida_cor);
        
        //Vez do inimigo ou vez do jogador
        if (vez_inimigo == 1) {
            DrawText("Vez do Inimigo", largura / 2 - 100, 100, 40, WHITE);
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                vez_inimigo = 0;
                personagem_num = 0;
                escolhas = 1;
                pode_apertar = 0.0;
                // 0 - dia, 1 - noite
                if (horario == 0) {
                    horario  = 1;
                } else if (horario == 1) {
                    horario = 0;
                }
            }
        } else {
            DrawText("Sua Vez", largura / 2 - 100, 100, 40, WHITE);
        }
    
        //Escolhas primarias de cada personagem
        if (escolhas == 1 && personagem_num == 0) {
            //Personagem 0
            pegar_personagem(personagem_num, &personagem_atual, personagem_head);
    
            personagem_atual->defesa = 0;
    
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
            desenhar_escolhas_ataques(&escolhido, &inicio_escolhas_secundarios, personagem_atual, personagem_num, largura, altura);
    
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                acao(&escolhido, &personagem_atual, &boss, escolha_ataques, escolha_flores_diurnas, escolha_flores_noturnas);
                escolha_ataques = 0;
                escolhido = 0;
                pode_apertar = 0.0;
                if (personagem_num == 3) {
                    vez_inimigo = 1;
                } else {
                    escolhas = 1;
                    personagem_num++;
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
            desenhar_escolhas_flores_dia(&escolhido, &inicio_escolhas_secundarios, personagem_atual, personagem_num, largura, altura);
    
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                acao(&escolhido, &personagem_atual, &boss, escolha_ataques, escolha_flores_diurnas, escolha_flores_noturnas);
                escolha_flores_diurnas = 0;
                escolhido = 0;
                pode_apertar = 0.0;
                if (personagem_num == 3) {
                    vez_inimigo = 1;
                } else {
                    escolhas = 1;
                    personagem_num++;
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
            desenhar_escolhas_flores_noite(&escolhido, &inicio_escolhas_secundarios, personagem_atual, personagem_num, largura, altura);
    
            if (IsKeyPressed(KEY_Z) && pode_apertar >= delay) {
                acao(&escolhido, &personagem_atual, &boss, escolha_ataques, escolha_flores_diurnas, escolha_flores_noturnas);
                escolha_flores_noturnas = 0;
                pode_apertar = 0.0;
                escolhido = 0;
                if (personagem_num == 3) {
                    vez_inimigo = 1;
                } else {
                    escolhas = 1;
                    personagem_num++;
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
                vez_inimigo = 1;
            } else {
                escolhas = 1;
                personagem_num++;
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
    }

    liberar_ataque(ataque_head2);
    liberar_ataque(ataque_head3);
    liberar_ataque(ataque_head4);
    liberar_ataque(ataque_head_boss);
    liberar_flor_dia(flor_dia_head1);
    liberar_flor_dia(flor_dia_head2);
    liberar_flor_noite(flor_noite_head1);
    liberar_flor_noite(flor_noite_head3);
    liberar_personagem(personagem_head);
    free(boss);

    UnloadRenderTexture(janela);
    UnloadTexture(quadro_roxo);
    UnloadTexture(quadro_vermelho);
    UnloadTexture(quadro_laranja);
    UnloadTexture(quadro_vinho);
    UnloadTexture(quadro_roxo_noite);
    UnloadTexture(quadro_vermelho_noite);
    UnloadTexture(quadro_laranja_noite);
    UnloadTexture(quadro_vinho_noite);
    UnloadTexture(borda);
    UnloadTexture(borda_escolhido);
    UnloadTexture(noite);
    UnloadTexture(fundo);
    UnloadMusicStream(pink);
    CloseAudioDevice();
    CloseWindow();

    return 0;
}