#include <stdio.h>

int main(){
    int i;
    //for(i=1;i<=5;printf("Numero %d\n",i), i=i+4);
    for(i=1; i<=5 ;i++)
        printf("Numero %d\n", i);
    for(; i<=10 ;i++)
        printf("E agora o numero %d\n", i);


    return 0;
}