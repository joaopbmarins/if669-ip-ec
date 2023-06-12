#include <stdio.h>
#include <math.h>

int main(){
    float x;
    printf("Digite um numero real: ");
    scanf("%f", &x);
    printf("Raiz quadrada de %.2f = %.2f", x, sqrt(x));
    return 0;
}