#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[100];
    float valor_mercado;
    int qtd_famoso;
    int qtd_titulos;
    char tem_neymar[4];
    int ney;
    char flamengo_2019[4];
    int f2019;
    float pontuacao;
}Clubes;

int main(){
    int n;
    scanf("%d",&n);
    Clubes clubes[n];
    for(int i=0;i<n;i++){
        scanf(" %16[^\n]", clubes[i].nome);
        scanf("%f %d %d", &clubes[i].valor_mercado, &clubes[i].qtd_famoso, &clubes[i].qtd_titulos);
        scanf(" %s", clubes[i].tem_neymar);
        scanf(" %s", clubes[i].flamengo_2019);
        if(strcmp(clubes[i].tem_neymar, "sim")==0){
            clubes[i].ney = 1;
        }
        else{
            clubes[i].ney = 0;
        }
        if(strcmp(clubes[i].flamengo_2019, "sim")==0){
            clubes[i].f2019 = 1;
        }
        else{
            clubes[i].f2019 = 0;
        }
        clubes[i].pontuacao = clubes[i].valor_mercado + (clubes[i].qtd_famoso*100) + (clubes[i].qtd_titulos*2000) + (clubes[i].ney*10000) + (clubes[i].f2019*20000);
    }
    Clubes aux;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(clubes[j].pontuacao < clubes[j+1].pontuacao){
                aux = clubes[j];
                clubes[j] = clubes[j+1];
                clubes[j+1] = aux;
            }
        }
    }

    for(int i=0;i<n;i++){
        printf("%s %.2f\n", clubes[i].nome, clubes[i].pontuacao);
    }

    return 0;
}