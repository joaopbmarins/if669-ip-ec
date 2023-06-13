#include <stdio.h>

int main(){
    float x, C, prec;

    printf("Digite o valor que quer a raiz: ");
    scanf("%f", &C);
    printf("Digite a margem: ");
    scanf("%f", &prec);
    x = C/2;


    do{
        x = x - (x * x - C)/ (2 * x);
        printf("Aproximacao da raiz = %.2f\n", x);
    }
    while((x * x < C - prec) || (x * x > C + prec));
    printf("Raiz = %.2f\n", x);
    return 0;
}