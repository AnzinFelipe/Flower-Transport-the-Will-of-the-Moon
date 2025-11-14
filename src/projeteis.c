#include "raylib.h"
#include <string.h>

void desenhar_projetil(char *elemento, float altura, Texture2D agua, Texture2D ar, Texture2D corte, 
    Texture2D eletricidade, Texture2D fogo, Texture2D gelo, Texture2D impacto, 
    Texture2D lunar, Texture2D perfuracao, Texture2D solar, Texture2D veneno, Rectangle horizontal, Rectangle vertical) {
    if (strcmp(elemento,"Água") == 0) {
        //DrawRectangleRec(horizontal, GREEN);
        DrawTextureEx(agua, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Ar") == 0) {
        //DrawRectangleRec(vertical, GREEN);
        DrawTextureEx(ar, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Corte") == 0) {
        //DrawRectangleRec(vertical, GREEN);
        DrawTextureEx(corte, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Eletricidade") == 0) {
        //DrawRectangleRec(vertical, GREEN);
        DrawTextureEx(eletricidade, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Fogo") == 0) {
        //DrawRectangleRec(vertical, GREEN);
        DrawTextureEx(fogo, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Gelo") == 0) {
        //DrawRectangleRec(vertical, GREEN);
        DrawTextureEx(gelo, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Impacto") == 0) {
        //DrawRectangleRec(horizontal, GREEN);
        DrawTextureEx(impacto, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Lunar") == 0) {
        //DrawRectangleRec(horizontal, GREEN);
        DrawTextureEx(lunar, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Perfuração") == 0) {
        //DrawRectangleRec(vertical, GREEN);
        DrawTextureEx(perfuracao, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Solar") == 0) {
        //DrawRectangleRec(vertical, GREEN);
        DrawTextureEx(solar, (Vector2){750, altura}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Veneno") == 0) {
        //DrawRectangleRec(vertical, GREEN);
        DrawTextureEx(veneno, (Vector2){750, altura}, 0.0, 1, WHITE);
    }   
}