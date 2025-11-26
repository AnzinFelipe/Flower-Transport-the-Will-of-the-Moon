#include "raylib.h"
#include "ranking.h"
#include <stdio.h>

int nova_pontuacao_ranking(int *nova_pontuacao){
    int total_podio = 5;
    Ranks podio[total_podio];
    FILE *arquivo = fopen("ranking.txt", "rb+");
    
    if(arquivo == NULL){
        arquivo = fopen("ranking.txt", "ab+");

        for(int i = 0; i < total_podio; i++){
            podio[i].posicao = i+1;

            if(i == 0){
                podio[i].total_pontos = *nova_pontuacao;
            }else{
                podio[i].total_pontos = -1;
            }
            
        }
        fwrite(&podio, sizeof(Ranks), total_podio, arquivo);
        
        fclose(arquivo);
        return *nova_pontuacao;

    }else{
        fread(&podio, sizeof(Ranks), total_podio, arquivo);

        for(int i = 0; i < total_podio; i++){
            if(*nova_pontuacao > podio[i].total_pontos){
                for(int j = total_podio - 1; j > i; j--){
                    podio[j].total_pontos = podio[j-1].total_pontos;
                }
                podio[i].total_pontos = *nova_pontuacao;
                break;
            }
        }

        fclose(arquivo);

        arquivo = fopen("ranking.txt", "wb+");
        fwrite(&podio, sizeof(Ranks), total_podio, arquivo);
        fclose(arquivo);
        return *nova_pontuacao;
    }
}