#include <stdio.h>

int main(){
    int x = 10, y = 15;   
    int *pX = &x;

    *pX = -10; //alterando o valor de x para -10; * está pedindo o valor que está no endereço; o ponteiro serve como um acesso indireto a variavel

    printf("Endereço de memoria de x = %p\n", pX);
    printf("valor de x = %d\n", x);

    pX = &y;
    *pX = 10;

    printf("Endereço de memoria de y = %p\n", pX);
    printf("valor de y = %d\n", y);

    return 0;
}