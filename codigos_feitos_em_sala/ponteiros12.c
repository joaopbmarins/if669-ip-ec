#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *nomeAl;
    int posAta;
} Aluno;

int main(){
    Aluno *sala=NULL;
    char nome[50];
    int iAluno =0;
    do{
        printf("Qual o nome do aluno? ");
        scanf(" %49[^\n]", nome);
        if(nome[0] != '.'){
            sala = (Aluno *) realloc(sala, (iAluno+1)*sizeof(Aluno));
            if(sala==NULL){ printf("Problema de alocacao\n"); exit(1);}
            sala[iAluno].nomeAl = (char *) malloc(strlen(nome)+1);
            strcpy(sala[iAluno].nomeAl,nome);
            printf("Qual a posicao na ata? "); scanf("%d", &(sala[iAluno].posAta));
            iAluno++;
        }
    }while(nome[0]!='.');
    for(;iAluno>=0;iAluno--) free(sala[iAluno].nomeAl);
    free(sala);
    return 0;
}