#include <stdio.h>
#define PI 3.14159      // o compilador substitui a palavra PI no codigo pelo valor dado
#define aoquadrado(v) (v * v) // o compilador substititui a expressão aoquadrado(v) pela expressão matematica

int main(){

    float area, raio; 
    printf("Digite o raio da circuferencia (cm): "); 
    scanf("%f", &raio); //preenche as variaveis 
    area = PI * raio * raio; //calculo
    printf("Área da circuferencia = %.2f cm²\n", area); // pq não precisa do &? (assunto é ponteiro.)
    //printf("%d\n", aoquadrado(8));
    return 0;
}