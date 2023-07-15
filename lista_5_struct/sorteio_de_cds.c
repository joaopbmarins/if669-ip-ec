#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int estado; //0 ou 1 sendo 1 emprestado e 0 não emprestado
    char estrelinhas[6];
    int artista;
} Album;

typedef struct {
    char nome[20];
    int qtd_album;
    Album album[100];
} Artista;

int main(){
    int n, cd1, cd2, cd3;
    scanf("%d", &n);
    int posi_album[(n*100)];
    Artista artistas[n];

    for(int i=0;i<n;i++){
        scanf(" %19[^\n]",artistas[i].nome);
        scanf("%d", &artistas[i].qtd_album);

        for(int j=0;j<artistas[i].qtd_album;j++){
            scanf(" %s", artistas[i].album[j].nome);
            scanf("%d", &artistas[i].album[j].estado);
            scanf(" %s", artistas[i].album[j].estrelinhas);
            posi_album[j] = i;
        }
        Album aux;
        for(int j=0;j<artistas[i].qtd_album;j++){
            for(int k=0;k<artistas[i].qtd_album-j-1;k++){
                if(strlen(artistas[i].album[k].estrelinhas) < strlen(artistas[i].album[k+1].estrelinhas)){
                    aux = artistas[i].album[k];
                    artistas[i].album[k] = artistas[i].album[k+1];
                    artistas[i].album[k+1] = aux;
                }
            }
        }
    }
    int cd[3];
    scanf("%d %d %d", &cd[0], &cd[1], &cd[2]);// 2 4 7 

    //esperar ver se os indices na questão está correto
    
    

    return 0;
}

//printf("%s - %s\n",,);
//printf("Infelizmente %s tá emprestado:(\n",);