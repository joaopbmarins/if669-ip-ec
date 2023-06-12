#include <stdio.h>

float a,b,x;

int main(){
    printf("Digite dois números A e B de uma equação de primeiro grau: ");
    scanf("%f %f", &a, &b);
    if(a == 0){
        printf("Erro sua equação não existe.\n");
        printf("%.2fx + %.2f = 0\n", a ,b);
    }
    else{
        x = -b/a;
        printf("o valor de X na equação %.2fx + %.2f = 0 \né x= %.2f\n",a ,b , x);
    }
    return 0;
}
