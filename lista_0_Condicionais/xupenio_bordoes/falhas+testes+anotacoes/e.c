#include <stdio.h>

int main() {
    int var1, var2, var3;
    
    printf("Digite o valor da primeira variável: ");
    scanf("%d", &var1);
    
    printf("Digite o valor da segunda variável: ");
    scanf("%d", &var2);
    
    printf("Digite o valor da terceira variável: ");
    scanf("%d", &var3);
    
    int sum_var2 = (var1 / var2) * (var2 + (var2 * (var1 / var2))) / 2;
    int sum_var3 = (var1 / var3) * (var3 + (var3 * (var1 / var3))) / 2;
    int sum_common = (var1 / (var2 * var3)) * ((var2 * var3) + ((var2 * var3) * (var1 / (var2 * var3)))) / 2;
    
    int sum = sum_var2 + sum_var3 - sum_common;
    
    printf("A soma dos números entre 1 e %d, excluindo os múltiplos de %d e %d, é: %d\n", var1, var2, var3, sum);
    
    return 0;
}
