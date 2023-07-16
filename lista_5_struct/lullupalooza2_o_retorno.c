#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[200];
    int agregados;
    char comida[100];
    char bebida[100];
    char artista[500];
}Voto;

typedef struct{
    char nome[500];
    int num;
    int qtd_votos;
}Totalizacao;

typedef struct{
    char nome[200];
}Vip;

int main(){
    int n, adc_agregados=1;
    scanf("%d", &n);
    Voto voto[n];
    Totalizacao comida[5];
    Totalizacao bebida[5];
    Totalizacao artista[5];
    Totalizacao agregados[n];

    //inserindo ou zerando nomes e numeros no struct para totalizacao dos votos
    strcpy(artista[0].nome, "Gustavo Mioto");strcpy(artista[1].nome, "Billie Eilish");strcpy(artista[2].nome, "Pericles");strcpy(artista[3].nome, "Shevchenko e Elloco");strcpy(artista[4].nome, "Joao Gomes");
    strcpy(bebida[0].nome, "agua");strcpy(bebida[1].nome, "cafe");strcpy(bebida[2].nome, "suco");strcpy(bebida[3].nome, "monster");strcpy(bebida[4].nome, "pitu");
    strcpy(comida[0].nome, "coxinha");strcpy(comida[1].nome, "brigadeiro");strcpy(comida[2].nome, "risoto");strcpy(comida[3].nome, "picanha");strcpy(comida[4].nome, "pizza");
    for(int i=0;i<5;i++){comida[i].qtd_votos = 0;bebida[i].qtd_votos = 0;artista[i].qtd_votos = 0;}
    for(int i=0;i<n;i++){agregados[i].qtd_votos=0;}//agregados[i].num=0;

    for(int i=0;i<n;i++){
        scanf(" %s %d %s %s %[^\n]",voto[i].nome ,&voto[i].agregados, voto[i].comida, voto[i].bebida, voto[i].artista);
        adc_agregados = 1;
        for(int j=0;j<n && adc_agregados==1;j++){
            if(agregados[j].num == voto[i].agregados){
                adc_agregados = 0;
                agregados[j].qtd_votos++;
            }
        }
        if(adc_agregados == 1){
            agregados[i].num = voto[i].agregados;
            agregados[i].qtd_votos++;
        }
        else{
            agregados[i].nome[0] = '\0';
            agregados[i].qtd_votos = 0;
            agregados[i].num = 0;
        }
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
//Ordena totalizacao de comida pela ordem alfabetica dps pelos votos
    Totalizacao aux;
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(strcmp(comida[j].nome,comida[j+1].nome) > 0){
                aux = comida[j];
                comida[j] = comida[j+1];
                comida[j+1] = aux;
            }
        }
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(comida[j].qtd_votos < comida[j+1].qtd_votos){
                aux = comida[j];
                comida[j] =  comida[j+1];
                comida[j+1] = aux;
            }
        }
    }

//Ordena totalizacao de bebida pela ordem alfabetica dps pelos votos
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(strcmp(bebida[j].nome,bebida[j+1].nome) > 0){
                aux = bebida[j];
                bebida[j] = bebida[j+1];
                bebida[j+1] = aux;
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

//Ordena totalizacao de artista pela ordem alfabetica dps pelos votos
    for(int i=0;i<5;i++){
        for(int j=0;j<5-i-1;j++){
            if(strcmp(artista[j].nome,artista[j+1].nome) > 0){
                aux = artista[j];
                artista[j] = artista[j+1];
                artista[j+1] = aux;
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

//Ordena totalizacao de agregados do menor numero pro maior e dps pelos votos
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(agregados[j].num > agregados[j+1].num){
                aux = agregados[j];
                agregados[j] =  agregados[j+1];
                agregados[j+1] = aux;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(agregados[j].qtd_votos < agregados[j+1].qtd_votos){
                aux = agregados[j];
                agregados[j] =  agregados[j+1];
                agregados[j+1] = aux;
            }
        }
    }

    int votos_acertados=0;
    Vip vips[n];
    //printf("\n");
    printf("%d\n",agregados[0].num);
    printf("%s\n",comida[0].nome);
    printf("%s\n",bebida[0].nome);
    printf("%s\n",artista[0].nome);
    printf("convidados vip:\n");//checa cada voto contando quantas categorias a pessoa acertou
    for(int i=0;i<n;i++){
        votos_acertados=0;
        if(voto[i].agregados == agregados[0].num){
            votos_acertados++;
        }
        if(strcmp(voto[i].comida,comida[0].nome)==0){
            votos_acertados++;
        }
        if(strcmp(voto[i].bebida,bebida[0].nome)==0){
            votos_acertados++;
        }
        if(strcmp(voto[i].artista,artista[0].nome)==0){
            votos_acertados++;
        }
        if(votos_acertados>=2){
            strcpy(vips[i].nome, voto[i].nome);
        }
        else{
            vips[i].nome[0] = '\0';
        }
    }
//ordena os vips pelo nome e imprime eles no final
    Vip aux1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(strcmp(vips[j].nome,vips[j+1].nome) > 0){
                aux1 = vips[j];
                vips[j] = vips[j+1];
                vips[j+1] = aux1;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(vips[i].nome[0] != '\0')
            printf("%s\n",vips[i].nome);
    }

    //printf("oi\n");

    return 0;
}