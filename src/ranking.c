#include "raylib.h"
#include "ranking.h"

void nova_pontuacao_ranking(Ranks **head, int nova_pontuacao){
    int total_podio = 5;
    Ranks podio[total_podio];
    Ranks *novo_rank = malloc(sizeof(Ranks));
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

            if(i == 4){
                podio[i].next = NULL;
            }else{
                podio[i].next = &podio[i+1];
            }
            
            fwrite(&podio[i].posicao, sizeof(int), 1, arquivo);
            fwrite(&podio[i].total_pontos, sizeof(int), 1, arquivo);
        }

        *head = &podio[0];
        fclose(arquivo);
        free(novo_rank);
        return;

    }else{
        for (int i = 0; i < total_podio; i++)
        {
            fread(&podio[i].posicao, sizeof(int), 1, arquivo);
            fread(&podio[i].total_pontos, sizeof(int), 1, arquivo);

            if(i == 4){
                podio[i].next = NULL;
            }else{
                podio[i].next = &podio[i+1];
            }
        }

        *head = &podio[0];
        fclose(arquivo);
    }
}