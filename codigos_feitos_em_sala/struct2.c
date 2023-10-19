#include <stdio.h>
#include <string.h>
#define tam 2

int main(){
    char nome[tam][100];// tam alunos com nomes de tamanho 100
    float nota[tam], media, soma=0;
    int i;
    for(i=0;i<tam;i++){
        printf("Digite nome: "); scanf(" %99[^\n]", nome[i]);
        printf("Nota: "); scanf("%f", &nota[i]);
        soma += nota[i];
    }
    media = soma/tam;
    for(i=0;i<tam;i++)
        if(nota[i]>=media)
            printf("Nome: %s\n", nome[i]);


    return 0;
}
