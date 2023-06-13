#include <stdio.h>
#define modulo(x) (x<0)?-x:x


int main(){
    float x, n, cima, baixo, final;


    printf("Valor de x: ");
    scanf("%f", &x);
    if(x == modulo(x) && x<1){

        for(int i = n; i>1; i--){
            cima = (-1)*cima;
        }
        for(int i = n + 1; i>1; i--){
            baixo = n + 1 * baixo;
        }

        final = cima/baixo;

    }
    else{
        printf("Entrada invalida\n");
    }
    return 0;
}