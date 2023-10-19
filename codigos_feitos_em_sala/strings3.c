#include <stdio.h>
#define nAlunos 3

int main(){
    char nome[nAlunos][100];
    float notas[nAlunos];
    float media = 0;
    int i;
    for(i=0;i<nAlunos;i++){
        printf("Digite o nome %da pessoa: ", i+1);
        scanf(" %99[^\n]", nome[i]);
        printf("Nota da %da: ", i+1);
        scanf("%f", &notas[i]);
        media += notas[i];
    }
    media = media/nAlunos;

    for(i=0;i<nAlunos;i++)
        if(notas[i]>= media)
            printf("Nome %da pessoa: %s\n Nota: %.2f\n", i+1, nome[i],notas[i]);

    return 0;
}
