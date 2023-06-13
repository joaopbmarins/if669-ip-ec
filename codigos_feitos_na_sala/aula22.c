#include <stdio.h>
#include <math.h>


int main(){
    float x, n, cima, baixo, lado, final;

    n = 1; // isso é a quantidade de repetições
    cima = -1;
    baixo = n + 1;
    lado = x;


    printf("Valor de x: ");
    scanf("%f", &x);
    if(x == fabs(x) && x<1.0){

        for(int i = n; i>1.0; i--){
            cima = (-1)*cima;
        }
        for(int i = n + 1.0; i>1.0; i--){
            lado = x * lado;
        }
        baixo = n + 1.0;
        final = (cima/baixo)*lado;
        printf("%f %f %f\n",cima, baixo, lado);
        printf("ln(x+1) = %f\n", final);
    }
    else{
        printf("Entrada invalida\n");
    }
    return 0;
}