#include <stdio.h>

int main() {
    int var1, var2, var3;
    int sum = 0;
    
    printf("Digite o valor da primeira variável: ");
    scanf("%d", &var1);
    
    printf("Digite o valor da segunda variável: ");
    scanf("%d", &var2);
    
    printf("Digite o valor da terceira variável: ");
    scanf("%d", &var3);
    
    for (int i = 1; i <= var1; i++) {
        if (i % var2 != 0 && i % var3 != 0) {
            sum += i;
        }
    }
    
    printf("A soma dos números entre 1 e %d, excluindo os múltiplos de %d e %d, é: %d\n", var1, var2, var3, sum);
    
    return 0;
}
