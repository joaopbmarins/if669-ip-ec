#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vet=NULL,tam=0,num;
    do{
        printf("Digite um numero: "); scanf("%d", &num);
        if(num>0){
            vet = (int *) realloc(vet,(tam+1) * sizeof(int));
            if(vet!=NULL) vet[tam++] = num;
            else num=-1;
        }
    }
    while(num>0);
    
    free(vet);
    return 0;
}