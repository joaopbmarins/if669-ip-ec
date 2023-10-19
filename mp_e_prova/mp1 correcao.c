#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define QTD_MAX_PALAVRA 1000
#define MAX_CHAR_PALAVRA 100

/*
João Pedro Barbosa Marins
jpbm
MP 1 IP 2023.1
*/


int main(){
    srand(time(NULL));
    int n;
    scanf("%d",&n);
    int direc[8] = {};
    int posi_i, posi_j, sentindo_escolhido, qtd_palavra=0;
    char lista_palavra[QTD_MAX_PALAVRA][MAX_CHAR_PALAVRA];
    if(n>=15){
        char matriz[n][n];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                matriz[i][j] = '\0';
        for(int i=0;i<QTD_MAX_PALAVRA;i++){
            scanf(" %s", lista_palavra[i]);
            if(strcmp(lista_palavra[i], ".") == 0){
                strcpy(lista_palavra[i],"\0");
                break;
            }
            else{
                qtd_palavra++;
            }
        }
            

        for(int k=0;k<qtd_palavra;k++){
            posi_i = rand() % (n - strlen(lista_palavra[k]));
            posi_j = rand() % (n - strlen(lista_palavra[k]));
            sentindo_escolhido = rand() % 8;
                
                if(matriz[posi_i][posi_j] == '\0'){
                    int final_palavra;
                    final_palavra = strlen(lista_palavra[k]);
                    if(sentindo_escolhido == 0){
                        if(posi_j + final_palavra -1<n) //era pra ser posi_j + final_palavra - 1
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                        }
                    }
                    else if(sentindo_escolhido == 1){
                        if(posi_i + final_palavra -1 <n && posi_j + final_palavra -1<n) //faltou o -1 aqui tb
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                        }
                    }
                    else if(sentindo_escolhido == 2){
                        if(posi_i + final_palavra -1 <n) //faltou o -1 aqui tb
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                        }
                    }
                    else if(sentindo_escolhido == 3){
                        if(posi_i + final_palavra-1<n && posi_j+1-final_palavra>=0) //faltou o -1 aqui tb
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            
                        }
                    }
                    else if(sentindo_escolhido == 4){
                        if(posi_j+1-final_palavra>=0)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            
                        }
                    }
                    else if(sentindo_escolhido == 5){
                        if(posi_i+1-final_palavra>=0 && posi_j+1-final_palavra>=0)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            
                        }
                    }
                    else if(sentindo_escolhido == 6){
                        if(posi_i+1-final_palavra>=0)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            
                        }
                            
                    }
                    else if(sentindo_escolhido == 7){
                        if(posi_i+1-final_palavra>=0 && posi_j+final_palavra-1<n) //faltou o -1 aqui tb
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            
                        }
                    }

                }
                else{ //se em matriz[posi_i][posi_j] já há outra letra, então vc deveria ou sortear nova posição/sentido pra palavra ou excluí-la da lista
                
                }
            
            for(int a=1;a<strlen(lista_palavra[k]);a++){
                if(sentindo_escolhido == 0){
                    matriz[posi_i][posi_j+a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 1){
                    matriz[posi_i+a][posi_j+a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 2){
                    matriz[posi_i+a][posi_j] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 3){
                    matriz[posi_i+a][posi_j-a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 4){
                    matriz[posi_i][posi_j-a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 5){
                    matriz[posi_i-a][posi_j-a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 6){
                    matriz[posi_i-a][posi_j] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 7){
                    matriz[posi_i-a][posi_j+a] = lista_palavra[k][a];
                }

            }
        }
        char letra_aleatoria;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    letra_aleatoria = (char)(rand() % 26 + 65);
                    if(matriz[i][j] == '\0')
                        //matriz[i][j] = letra_aleatoria;
                        matriz[i][j] = '0';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }
    }

    


    return 0;
}