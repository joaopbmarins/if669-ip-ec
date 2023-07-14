#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
    char  nome[200];
    int   idade;
    float altura;
    float num_magico;
    float delta;
} Pessoa;

int main(){
    int n,m,magico;
    scanf("%d",&n);
    scanf("%d",&m);
    scanf("%d", &magico);
    Pessoa filhos[n];
    
    for(int i=0;i<n;i++){
        scanf(" %s", filhos[i].nome);
        scanf("%d", &filhos[i].idade);
        scanf("%f", &filhos[i].altura);
        filhos[i].num_magico = strlen(filhos[i].nome) * filhos[i].idade * filhos[i].altura;
        filhos[i].delta = fabs(filhos[i].num_magico-magico);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            Pessoa aux;
            if(filhos[j].delta > filhos[j+1].delta){
                aux = filhos[j];
                filhos[j] = filhos[j+1];
                filhos[j+1] = aux;
            }
        }
    }

    for(int i=0;i<m;i++) printf("%s\n",filhos[i].nome);

    return 0;
}