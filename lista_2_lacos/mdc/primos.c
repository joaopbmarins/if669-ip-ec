#include <stdio.h>

int main(){
    int num, nao_primo = 0, i;
    scanf("%d", &num);

    for(i = 2; i<num; i++){
        if(num % i == 0){
            nao_primo = 1;
            printf("%d é divisivel por %d.\n", num, i);
        }
    }
    if(nao_primo == 0)
        printf("%d é primo.\n", num);

    return 0;
}