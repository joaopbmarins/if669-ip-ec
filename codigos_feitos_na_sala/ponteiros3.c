#include <stdio.h>

int main(){
    int vet[10], x; 
    int *pVet;

    pVet = vet;

    pVet[0] /*  *(pVet + 0) */= 10;

    pVet = &x;
    *pVet = 5;

    return 0;
}