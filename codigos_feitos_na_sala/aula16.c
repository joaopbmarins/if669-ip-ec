#include <stdio.h>

int main(){
    int soma =0, num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    while(num>=0){
        soma += num;
        printf("Digite um numero: ");
        scanf("%d", &num);
    }
    printf("Soma = %d\n", soma);
    return 0;
}