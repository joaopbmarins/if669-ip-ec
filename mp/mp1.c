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
    int n; //numero de linhas e colunas na matriz
    scanf("%d",&n);
    int direc[8] = {};
    int posi_i, posi_j, sentindo_escolhido, qtd_palavra=0;
    char lista_palavra[QTD_MAX_PALAVRA][MAX_CHAR_PALAVRA];
    if(n>=15){
        char matriz[n][n];// verificar se a matriz vai estar vazia e isso é pra vc joao 
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                matriz[i][j] = '\0';
        for(int i=0;i<QTD_MAX_PALAVRA;i++){// laco para scanear todas as palavras possiveis
            scanf("%s", lista_palavra[i]);
            if(strcmp(lista_palavra[i], ".") == 0){// condicional para parar caso a ultima leitura for string com "."
                strcpy(lista_palavra[i],"\0");//atualiza o valor do ponto para \0
                break;
            }
            else{
                qtd_palavra++;
            }
        }
            

        for(int k=0;k<qtd_palavra;k++){
            posi_i = rand() % (n - strlen(lista_palavra[0])); //escolhe uma posição i na matriz para colocar a letra
            posi_j = rand() % (n - strlen(lista_palavra[0])); //escolhe uma posição j na matriz para colocar a letra
            sentindo_escolhido = rand() % 8; //escolhe um sentido

            while(matriz[posi_i][posi_j] != lista_palavra[k][0]){// testa se a posição escolhida na matriz for diferente a letra 1 da palavra escolhida ou seja ainda nn colocou a letra na posição
                if(matriz[posi_i][posi_j] == '\0'){// testa se a posição na matriz vai estar vazia ou se ja tem uma letra igual letra escolhida na posição
                    int final_palavra;
                    final_palavra = strlen(lista_palavra[k]);
                    if(sentindo_escolhido == 0){//condicionais para testar se cabe a palavra no sentido
                        if(posi_j + final_palavra<n)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            break;
                        }
                    }
                    else if(sentindo_escolhido == 1){
                        if(posi_i + final_palavra<n && posi_j + final_palavra<n)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            break;
                        }
                    }
                    else if(sentindo_escolhido == 2){
                        if(posi_i + final_palavra<n)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            break;
                        }
                    }
                    else if(sentindo_escolhido == 3){
                        if(posi_i + final_palavra<n && posi_j+1-final_palavra>=0)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            break;
                        }
                    }
                    else if(sentindo_escolhido == 4){
                        if(posi_j+1-final_palavra>=0)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            break;
                        }
                    }
                    else if(sentindo_escolhido == 5){
                        if(posi_i+1-final_palavra>=0 && posi_j+1-final_palavra>=0)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            break;
                        }
                    }
                    else if(sentindo_escolhido == 6){
                        if(posi_i+1-final_palavra>=0)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            break;
                        }
                            
                    }
                    else if(sentindo_escolhido == 7){
                        if(posi_i+1-final_palavra>=0 && posi_j+final_palavra<n)
                            matriz[posi_i][posi_j] = lista_palavra[k][0];
                        else{
                            strcpy(lista_palavra[k],"\0");
                            break;
                        }
                    }//fim das condicionais para verificar se cabe na matriz

                }
                else{
                    break;
                    /*
                    posi_i = rand() % (n - strlen(lista_palavra[0])); 
                    posi_j = rand() % (n - strlen(lista_palavra[0]));
                    sentindo_escolhido = rand() % 8;*/
                }
            }
            for(int a=1;a<strlen(lista_palavra[k]);a++){//laço para colocar a palavra no sentido definido
                if(sentindo_escolhido == 0){// palavra segue para o leste
                    matriz[posi_i][posi_j+a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 1){//palavra segue para o se
                    matriz[posi_i+a][posi_j+a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 2){//palavra segue para o s
                    matriz[posi_i+a][posi_j] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 3){//palavra segue para o so
                    matriz[posi_i+a][posi_j-a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 4){//palavra segue para o o
                    matriz[posi_i][posi_j-a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 5){//palavra segue para o no
                    matriz[posi_i-a][posi_j-a] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 6){//palavra segue para o n
                    matriz[posi_i-a][posi_j] = lista_palavra[k][a];
                }
                else if(sentindo_escolhido == 7){//palavra segue para o ne
                    matriz[posi_i-a][posi_j+a] = lista_palavra[k][a];
                }

            }
        }
        char letra_aleatoria;
        for(int i=0;i<n;i++){//preenche a matriz com letras aleatórias
            for(int j=0;j<n;j++){
                    letra_aleatoria = (char)(rand() % 26 + 65);
                    if(matriz[i][j] == '\0')
                        matriz[i][j] = letra_aleatoria;
            }
        }
        for(int i=0;i<n;i++){//imprime a matriz
            for(int j=0;j<n;j++){
                printf("%c ", matriz[i][j]);
            }
            printf("\n");
        }
    }

    


    return 0;
}
