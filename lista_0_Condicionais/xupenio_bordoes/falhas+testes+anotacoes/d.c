#include <stdio.h>

int sumRecursively(int n, int var1, int var2, int var3) {
    if (n <= 0) {
        return 0;
    }
    
    int currentNum = n;
    if (currentNum % var2 != 0 && currentNum % var3 != 0) {
        return currentNum + sumRecursively(n - 1, var1, var2, var3);
    } else {
        return sumRecursively(n - 1, var1, var2, var3);
    }
}

int main() {
    int var1, var2, var3;
    
    printf("Digite o valor da primeira variável: ");
    scanf("%d", &var1);
    
    printf("Digite o valor da segunda variável: ");
    scanf("%d", &var2);
    
    printf("Digite o valor da terceira variável: ");
    scanf("%d", &var3);
    
    int sum = sumRecursively(var1, var1, var2, var3);
    
    printf("A soma dos números entre 1 e %d, excluindo os múltiplos de %d e %d, é: %d\n", var1, var2, var3, sum);
    
    return 0;
}
