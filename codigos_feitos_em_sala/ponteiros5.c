#include <stdio.h>
#include <stdlib.h>

int main(){
    int i;
    int *pont;

    pont = (int *) malloc(10 * sizeof(int)); // "equivalente" a int pont[10]; malloc é uma alocação mais dinamica 
    if(pont != NULL){
        // use o vetor
        for(i=0;i<10;i++){
            pont[i] = i;
            printf("%d\n", pont[i]);
        }

        free(pont);// sempre precisa liberar a memoria no final do uso
    }

    return 0;
}

/*
    //*(pont + 0) = 10; // mesma coisa pont[0] = 10;     

    for(int i=0;i<10;i++){
        pont[i] = 10;
    }
*/