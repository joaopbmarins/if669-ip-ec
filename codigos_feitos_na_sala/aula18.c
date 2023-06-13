#include <stdio.h>
#include <stdlib.h>


int main(){
    int a = 1;
    batata:
    printf("%d\n", a);
    a = a + 1;
    if(a == 5)
        exit;
    else 
        goto batata;
    
    return 0;
}