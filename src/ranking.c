#include "raylib.h"
#include "ranking.h"
#include <stdio.h>

void nova_pontuacao_ranking(int nova_pontuacao){
    int total_podio = 5;
    Ranks podio[total_podio];
    FILE *arquivo = fopen("ranking.txt", "rb+");
    
    if(arquivo == NULL){
        arquivo = fopen("ranking.txt", "ab+");

        for(int i = 0; i < total_podio; i++){
            podio[i].posicao = i+1;

            if(i == 0){
                podio[i].total_pontos = nova_pontuacao;
            }else{
                podio[i].total_pontos = -1;
            }
            
            fwrite(&podio[i].posicao, sizeof(int), 1, arquivo);
            fwrite(&podio[i].total_pontos, sizeof(int), 1, arquivo);
        }

        fclose(arquivo);
        return;

    }else{
        for (int i = 0; i < total_podio; i++)
        {
            fread(&podio[i].posicao, sizeof(int), 1, arquivo);
            fread(&podio[i].total_pontos, sizeof(int), 1, arquivo);
        }

        fclose(arquivo);
    }
}