#include <math.h>
#include <stdio.h>

int main(){
    float a,b,c;
    float delta;
    float x1 , x2;

    printf("Escreva os três coeficiente de uma equação de 2º grau: ");
    scanf("%f %f %f", &a, &b, &c);
    printf("Sua equação: %.2fx² + %.2fx + %.2f = 0\n", a, b, c);
    delta = pow(b, 2) -4 * a * c;
    if(a!=0){
        if(delta < 0){
        printf("o delta da sua equação é negativo logo não tem raiz a equação\n");
        }
        else if(delta == 0){
            printf("Raiz Unica x1 e x2 = %.2f\n", &x1);
        }
        else{
            x1 = (-b + sqrt(delta))/2*a;
            x2 = (-b - sqrt(delta))/2*a;
            printf("x1 = %f \nx2 = %f\n", x1 ,x2);
        }    
    }
    else{
        printf("O coeficiente A da sua equação não pode ser negativo.\n");
    }
    return 0;
}