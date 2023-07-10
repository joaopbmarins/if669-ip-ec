#include <stdio.h>

int main(){
    int x = 10; //x sinonimo de endereço de memoria
    int *pontInt = NULL; // NULL equivalente a '\0' que é equivalente a 0; na partica esse endereço é invalido, pois null nn é um endereço, mas serve como referencia pra iniciar a variavel ponteiro.

    pontInt = &x;// & junto da variavel especificava que é o endereço da variavel 

    printf("Endereço de memoria de x = %p\n", pontInt);
    printf("Endereço de memoria de x = %p\n", &x);

    return 0;
}