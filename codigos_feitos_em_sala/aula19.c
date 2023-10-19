#include <stdio.h>

int main(){
    long long int fat =1, n, n0, fat1 =1;
    printf("Digite o n: ");
    scanf("%lld", &n0);

    n = n0;

    for (; n>=1; n--){
        fat = fat * n;
    }

    while(n0>1){
        fat1 = fat1 * n0;
        n0--;
    }
    printf("Fatorial = %lld\n", fat);
    printf("Fatorial = %lld\n", fat1);

//    fat = n!
//    fat = 1 x 2 x 3 .... x (n-1) x n



    return 0;
}