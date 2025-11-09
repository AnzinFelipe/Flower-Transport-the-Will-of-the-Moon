#include "raylib.h"
#include <string.h>

void desenhar_projetil(char *elemento, Texture2D agua, Texture2D ar, Texture2D corte, 
    Texture2D eletricidade, Texture2D fogo, Texture2D gelo, Texture2D impacto, 
    Texture2D lunar, Texture2D perfuracao, Texture2D solar, Texture2D veneno) {
    if (strcmp(elemento,"Agua") == 0) {
        DrawTextureEx(agua, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Ar") == 0) {
        DrawTextureEx(ar, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Corte") == 0) {
        DrawTextureEx(corte, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Eletricidade") == 0) {
        DrawTextureEx(eletricidade, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Fogo") == 0) {
        DrawTextureEx(fogo, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Gelo") == 0) {
        DrawTextureEx(gelo, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Impacto") == 0) {
        DrawTextureEx(impacto, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Lunar") == 0) {
        DrawTextureEx(lunar, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Perfuracao") == 0) {
        DrawTextureEx(perfuracao, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Solar") == 0) {
        DrawTextureEx(solar, (Vector2){750, 515}, 0.0, 1, WHITE);
    } else if (strcmp(elemento,"Veneno") == 0) {
        DrawTextureEx(veneno, (Vector2){750, 515}, 0.0, 1, WHITE);
    }   
}