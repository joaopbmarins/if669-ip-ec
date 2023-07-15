#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[2000];
    int agregados;
    char comida[2000];
    char bebida[2000];
    char artista[2000];
}Voto;

typedef struct{
    char nome[2000];
    int qtd_votos;
}Totalizacao;



int main(){
    int n, adc_agregados=1;
    char aux1[2000];
    scanf("%d", &n);
    Voto voto[n];
    Totalizacao comida[5];
    Totalizacao bebida[5];
    Totalizacao artista[5];
    Totalizacao agregados[n];

    strcpy(artista[0].nome, "Gustavo Mioto");strcpy(artista[1].nome, "Billie Eilish");strcpy(artista[2].nome, "Pericles");strcpy(artista[3].nome, "Shevchenko e Elloco");strcpy(artista[4].nome, "Joao Gomes");
    strcpy(bebida[0].nome, "agua");strcpy(bebida[1].nome, "cafe");strcpy(bebida[2].nome, "suco");strcpy(bebida[3].nome, "monster");strcpy(bebida[4].nome, "pitu");
    strcpy(comida[0].nome, "coxinha");strcpy(comida[1].nome, "brigadeiro");strcpy(comida[2].nome, "risoto");strcpy(comida[3].nome, "picanha");strcpy(comida[4].nome, "pizza");
    for(int i=0;i<5;i++){comida[i].qtd_votos = 0;bebida[i].qtd_votos = 0;artista[i].qtd_votos = 0;}

    for(int i=0;i<n;i++){
        scanf(" %s %d %s %s %[^\n]",voto[i].nome ,&voto[i].agregados, voto[i].comida, voto[i].bebida, voto[i].artista);
        sprintf(aux1,"%d",voto[i].agregados);
        adc_agregados = 1;
        for(int j=0;j<n;j++){
            if(strcmp(agregados[j].nome,voto[i].agregados) == 0){
                adc_agregados = 0;
            }
        }
        if(adc_agregados == 1)
            strcpy(agregados[i].nome,aux1);
        for(int j=0;j<5;j++){
            if(strcmp(comida[j].nome,voto[i].comida)==0){
                comida[j].qtd_votos++;
            }
            if(strcmp(bebida[j].nome,voto[i].bebida)==0){
                bebida[j].qtd_votos++;
            }
            if(strcmp(artista[j].nome,voto[i].artista)==0){
                artista[j].qtd_votos++;
            }
        }
    }
    Totalizacao aux;
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(comida[j].qtd_votos < comida[j+1].qtd_votos){
                aux = comida[j];
                comida[j] =  comida[j+1];
                comida[j+1] = aux;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(bebida[j].qtd_votos < bebida[j+1].qtd_votos){
                aux = bebida[j];
                bebida[j] =  bebida[j+1];
                bebida[j+1] = aux;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(artista[j].qtd_votos < artista[j+1].qtd_votos){
                aux = artista[j];
                artista[j] =  artista[j+1];
                artista[j+1] = aux;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(agregados[j].qtd_votos < agregados[j+1].qtd_votos){
                aux = agregados[j];
                agregados[j] =  agregados[j+1];
                agregados[j+1] = aux;
            }
        }
    }

    printf("oi\n");

    return 0;
}