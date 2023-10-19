#include <stdio.h>
#include <stdlib.h>

int main(){
    int tam;
    printf("Qual tamanho? "); scanf("%d", &tam);
    int *p = (int *) calloc(tam, sizeof(int));// a diferença entre calloc e malloc é q o calloc vai limpar a memoria garantido q ela está vazia
    if(p == NULL){
        printf("Problema de alocacao de memoria naa variavel p\n");
        exit(1);
    }
    for(int i=0;i<tam;i++){
        p[i] = 15;
    }
    free(p);


    return 0;
}