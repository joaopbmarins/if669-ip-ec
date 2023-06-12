#include <stdio.h>

int main(){
    int num1, num2;
    float media;
    printf("Digite 2 inteiros: ");
    scanf("%d %d", &num1, &num2);
    media = (num1 + num2)/(float)2;
    printf("Média = %.2f\n", media);
    return 0;
} 