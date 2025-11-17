#ifndef SCREENS_H
#define SCREENS_H

#include "raylib.h"

typedef struct Images {
    Texture2D imagem;
    struct Images* next;
} Images;

typedef enum GameScreen {
    SCREEN_MENU,
    SCREEN_GAME,
    SCREEN_EXIT,
    SCREEN_GAMEOVER,
    SCREEN_CUTSCENE,
} GameScreen;

GameScreen RunMenu(void);
GameScreen RunCutscene(void);
GameScreen RunGameOver(void);

#endif