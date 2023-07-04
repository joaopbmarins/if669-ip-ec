#include <stdio.h>
#define TAM 7

int main(){
    char vetor[TAM] = {'a','d','c','g','b','e','f'};

    for(int j = 0;j<TAM;j++){
        for(int i = 0; i<TAM-j-1;i++){
            if(vetor[i]>vetor[i+1]){
                int tmp;
                tmp = vetor[i+1];
                vetor[i+1] = vetor[i];
                vetor[i] = tmp;
            }
        }
    }

    for(int i = 0; i<TAM;i++)
        printf("%c", vetor[i]);

    return 0;
}