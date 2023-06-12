#include <stdio.h>
#include <math.h>

int main(){
    float peso, altura, imc;
    printf("Qual é o seu peso(Kg)? ");
    scanf("%f", &peso);
    printf("Qual é o seu altura(m)? ");
    scanf("%f", &altura);

    if(peso && altura !=0){
        imc = peso/(altura * altura);
        printf("Seu imc é: %.2f\n", imc);
        if(imc <= 16.9){
            printf("Você está classificado como muito abaixo do peso.\n");
        }
        else if(17 <= imc && imc <= 18.4){
            printf("Você está classificado como abaixo do peso.\n");
        }
        else if(18.5 <= imc && imc < 30.0){
            printf("Você está classificado como peso normal.\n");
        }
        else if(25.0 <= imc && imc < 30.0){
            printf("Você está classificado como acima do peso.\n");
        }
        else if(30.0 <= imc && imc < 35.0){
            printf("Você está classificado como obesidade grau 1.\n");
        }
        else if(35.0 <= imc && imc < 40.0){
            printf("Você está classificado como obesidade grau 2.\n");
        }
        else if(imc >= 40.0){
            printf("Você está classificado como obesidade grau 3.\n");
        }
    }
    else{
        printf("Peso nem Altura podem ter o valor igual a zero.\n");
    }
    return 0;
}