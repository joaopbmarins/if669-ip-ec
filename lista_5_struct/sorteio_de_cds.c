#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[20];
    int estado; //0 ou 1 sendo 1 emprestado e 0 não emprestado
    char estrelinhas[6];
    char artista[20];
} Album;

typedef struct {
    char nome[20];
    int qtd_album;
} Artista;

int main(){
    int n, j=0, indices_album=0;
    scanf("%d", &n);
    Artista artistas[n];
    Album album[1000];

    for(int i=0;i<n;i++){
        scanf(" %19[^\n]",artistas[i].nome);
        scanf("%d", &artistas[i].qtd_album);

        indices_album += artistas[i].qtd_album;

        for(;j<indices_album;j++){
            scanf(" %s", album[j].nome);
            scanf("%d", &album[j].estado);
            scanf(" %s", album[j].estrelinhas);
            strcpy(album[j].artista,artistas[i].nome);
        }
    }
    Artista aux;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            //printf("%d\n",strcmp(artistas[j].nome,artistas[j+1].nome));
            if(strcmp(artistas[j].nome,artistas[j+1].nome) > 0){
                aux = artistas[j];
                artistas[j] = artistas[j+1];
                artistas[j+1] = aux;
            }
        }
    }
    Album aux1;
    for(int i=0;i<indices_album;i++){
        for(int j=0;j<indices_album-i-1;j++){
            //printf("%d\n",strcmp(artistas[j].nome,artistas[j+1].nome));
            if(strcmp(album[j].artista,album[j+1].artista) > 0){
                aux1 = album[j];
                album[j] = album[j+1];
                album[j+1] = aux1;
            }
        }
    }
    int cd;
    Album cds[3];
    for(int i=0;i<3;i++){
        scanf("%d", &cd);
        cds[i] = album[cd-1];
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3-i-1;j++){
            //printf("%d\n",strcmp(artistas[j].nome,artistas[j+1].nome));
            if(strlen(cds[j].estrelinhas) < strlen(cds[j+1].estrelinhas) ){
                aux1 = cds[j];
                cds[j] = cds[j+1];
                cds[j+1] = aux1;
            }
        }
    }

    for(int i=0;i<3;i++){
        if(cds[i].estado == 0)
            printf("%s - %s\n",cds[i].artista,cds[i].nome);
        else
            printf("Infelizmente %s ta emprestado:(\n",cds[i].nome);
    }

    return 0;
}
