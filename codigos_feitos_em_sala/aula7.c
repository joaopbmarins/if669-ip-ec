#include <stdio.h>

int main(){
    float x;
    printf("Digite um numero pseudo real: ");
    scanf("%f", &x);
    if(x != 0){
        printf("Inverso = %.2f\n", 1/x);
    }
    else{
        printf("A função inversa não funciona no caso 0!\n");
    }
}