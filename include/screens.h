#ifndef SCREENS_H
#define SCREENS_H

#include "raylib.h"

typedef enum GameScreen {
    SCREEN_MENU,
    SCREEN_GAME,
    SCREEN_EXIT,
    SCREEN_GAMEOVER,
} GameScreen;

GameScreen RunMenu(void);

#endif