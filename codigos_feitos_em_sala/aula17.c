#include <stdio.h>

int main(){
    int soma =0, num;
    do{
        printf("Digite um numero: ");
        scanf("%d", &num);
        if(num>=0)
            soma += num;
    }
    while(num>=0);
    printf("Soma = %d\n", soma);
    return 0;
}