#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
    float altura;
} Pessoa;

int main(){
/*
    int *vet;
    Pessoa *familia;
    printf("Tam estrutura: %ld bytes\n", sizeof(Pessoa));
    printf("Tam ponteiro p inteiro: %ld bytes\n", sizeof(vet));
    printf("Tam ponteiro p Pessoa: %ld bytes\n", sizeof(familia));
*/
    Pessoa pEst;
    strcpy(pEst.nome,"Pedro Alvares");
    pEst.idade = 556;

    Pessoa *pDin;
    pDin = (Pessoa *) malloc(sizeof(Pessoa));
    strcpy(pDin->nome, "Pedro I");//equivalente/ strcpy((*pDin).nome,"Pedro I");
    pDin->idade=596;//equivalente/ (*pDin).idade = 596;
    


    return 0;
}