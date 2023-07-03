#include <stdio.h>
#include <string.h>
#define tam 2
typedef struct {
    char nome[100];
    float nota;
} Alunos;

int main(){
    Alunos aluno[tam];
    float media, soma = 0;
    int i;
    for(i=0;i<tam;i++){
        printf("Digite nome: "); scanf(" %99[^\n]", aluno[i].nome);
        printf("Nota: "); scanf("%f", &aluno[i].nota);
        soma += aluno[i].nota;
    }
    media = soma/tam;
    for(i=0;i<tam;i++)
        if(aluno[i].nota>=media)
            printf("Nome: %s\n", aluno[i].nome);


    return 0;
}
