#include <stdio.h>

int main(){
    float xFut, xAt, C;
    int n;
    printf("Digite o valor que quer a raiz: ");
    scanf("%f", &C);
    printf("Quantas aproximacoes: ");
    scanf("%d", &n);

    xAt = C/2;
    for(; n>=1;n--){
        xFut = xAt - (xAt * xAt - C)/ (2 * xAt);
        printf("Aproximacao da raiz = %f\n", xFut);
        xAt = xFut;
        }
    printf("Raiz = %.2f\n", xFut);
    return 0;
}