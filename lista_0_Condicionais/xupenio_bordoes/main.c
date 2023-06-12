#include <stdio.h>


int main(){
    int n, a, b, a_n, b_n, ab_n, ab;
    int soma, mult_a, mult_b, mult_ab, resultado;

    scanf("%d", &n);
    scanf("%d %d", &a, &b);

    soma = (n*(n+1))/2;
    
    a_n = (a + ((n/a)-1)*a);
    b_n = (b + ((n/b)-1)*b);
    ab = a*b;
    ab_n = (ab + ((n/ab)-1)*ab);

    mult_a = ((a + a_n) * (n/a))/2;
    mult_b = ((b + b_n) * (n/b))/2;
    mult_ab = ((ab + ab_n) * (n/ab))/2;

    resultado = (soma+mult_ab-(mult_a+mult_b));

    printf("%d\n", resultado);

    if(resultado % 2 != 0){
        printf("Opa xupenio AULAS...\n");
    }
    else{
        printf("La ele!!!\n");
    }
    return 0;
}