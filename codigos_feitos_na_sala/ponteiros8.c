#include <stdio.h>
#include <stdlib.h>

int main(){
    int *p=NULL,*pAux,num,tam=0;
    do{
        printf("Digite um numero (se 0 ou negativo,para): ");
        scanf("%d", &num);
        if(num>0){
            pAux = p;
            p = (int *)realloc(pAux,(tam+1)*sizeof(int));// se nn tiver espaço para alocar o realloc vai mudar o endereço pra null, mas nn vai limpar o endereço anterior
            if(p == NULL) { free(pAux); printf("Problema de alocacao de memoria.\n"); exit(1);} 
            p[tam++] = num;
        }

    }while(num>0);
    free(p);
    return 0;
}