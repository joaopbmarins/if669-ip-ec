#include <stdio.h>
#define TAM 4

int main(){
    float v[TAM];
    int i;
    for(i=0; i<TAM; i++){
        printf("Digite um valor: ");
        scanf("%f", &v[i]);
    }
    for(i=0;i<TAM;i++)
        printf("v[%d]=%.2f\n", i+1, v[i]);


    return 0;
}