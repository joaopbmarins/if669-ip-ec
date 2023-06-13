#include <stdio.h>

int main(){
    int i;
    for(i=1; i<=10; i++){
        if(i==6) break;
        else printf("Numero %d\n", i);
        
    }
    printf("Ultimo valor %d\n", i);

    return 0;
}