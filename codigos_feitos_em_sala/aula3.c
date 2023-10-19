#include <stdio.h>

int main(){

    float area, base, altura; //1. Declara as variaveis (altura = saida) (base e altura = entrada)
    printf("Digite a base e a altura do triangulo (cm): "); 
    scanf("%f %f", &base, &altura); //preenche as variaveis 
    area = (base*altura)/2.0; //calculo
    printf("Área do triangulo = %.2f cm² \n", area); // pq não precisa do & (assunto é ponteiro.)
    return 0;
}