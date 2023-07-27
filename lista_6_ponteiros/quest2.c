#include <stdio.h>

/*
João Pedro Barbosa Marins
jpbm 
Lista Ponteiros
Questão 2
*/

int main(){
    int vet[5] = {1,2,3,4,5};
    int *p = vet;

    printf("a)\n");
    printf("\tEndereço guardado em vet: %p\n\tO endereço guardado em p: %p\n", vet, p);
    printf("b)\n");
    
    for(int i=0;i<5;i++){
        printf("\tValor de vet[%d] utilizando p com []: %d\n",i,p[i]);
    }
    printf("c)\n");
    
    for(int i=0;i<5;i++){
        printf("\tValor de vet[%d] utilizando p com *: %d\n",i,*(p+i));
    }

    printf("d)\n");

        for(int i=0;i<5;i++){
        printf("\tValor de vet[%d] utilizando vet com []: %d\n",i,vet[i]);
    }

    printf("\n");

    for(int i=0;i<5;i++){
        printf("\tValor de vet[%d] utilizando vet com *: %d\n",i,*(vet+i));
    }
    return 0;
}
